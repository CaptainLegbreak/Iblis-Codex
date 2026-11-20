#include "D2DDraw.h"

struct D2DDrawSmackStrc
{
    D2SmackStrc* hSmack;
    unsigned char nType;
    unsigned char unk0x05[3];
    int nX;
    int nY;
};

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
void __fastcall sub_00513330_DDrawCloseSmacker(D2DDrawSmackStrc* pRecord);                                      // 0x00513330
unsigned char gabRemapTable_008815B0[256];                                                                  // 0x008815B0
extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0
int gbRemapValid_008816B4;                                                                                  // 0x008816B4
extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8

static __forceinline void sub_00513380_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        --nCount;
        *pDst++ = gabRemapTable_008815B0[*pSrc++];
    }
}

static __declspec(noinline) void __stdcall sub_00513380_RemapRows(int nWidth, D2DDrawSmackStrc* pRect, unsigned int nRows);

// 0x00513380
static void __stdcall sub_00513380_RemapRows(int nWidth, D2DDrawSmackStrc* pRect, unsigned int nRows)
{
    if (!gpRemapSource_008816B0)
        return;
    unsigned char* pSrc = gpRemapSource_008816B0;
    unsigned char* pDst = (pRect->nY - nRows) * gnScreenWidth_007C9138 + pRect->nX + gpScreenBuffer_007C9154;
    unsigned int nLeft = nRows;
    while (nLeft)
    {
        --nLeft;
        sub_00513380_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnScreenWidth_007C9138;
        pSrc += nWidth;
    }
}

// 0x005135F0
void __fastcall sub_005135F0_DDrawPlaySmacker(D2DDrawSmackStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = pRecord->hSmack;
        if (!hSmack)
            return;
        if (!SmackWait(hSmack))
        {
            if (!gbSurfaceActive_007C9140)
                return;
            if (hSmack->bNewPalette)
            {
                for (int i = 0; i < 256; ++i)
                {
                    gabRemapTable_008815B0[i] = sub_00605210_FindNearestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbRemapValid_008816B4 = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                sub_00513330_DDrawCloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
        if (gbRenderPaused_007C9144)
            return;
        if (!gbRemapValid_008816B4)
            return;
        sub_00513380_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused_007C9144)
            sub_00513380_RemapRows(468, pRecord, 60);
        break;
    }
}
