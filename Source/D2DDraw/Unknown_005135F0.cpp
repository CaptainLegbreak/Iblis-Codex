#include "D2DDraw.h"
#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __fastcall DDRAW_CloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
unsigned char gabRemapTable_008815B0[256];                                                                  // 0x008815B0
extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0
int gbRemapValid_008816B4;                                                                                  // 0x008816B4
extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140

static inline void sub_00513380_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        *pDst++ = gabRemapTable_008815B0[*pSrc++];
        --nCount;
    }
}

static void __stdcall sub_00513380_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows);

// build: context sub_00513380_RemapRows
static void __stdcall sub_00513380_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
{
    unsigned char* pSrc = gpRemapSource_008816B0;
    unsigned char* pDst = (pRect->nY - nRows) * gnScreenWidth_007C9138 + pRect->nX + gpScreenBuffer_007C9154;
    for (unsigned int y = 0; y < nRows; ++y)
    {
        sub_00513380_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnScreenWidth_007C9138;
        pSrc += nWidth;
    }
}

// 0x005135F0
void __fastcall sub_005135F0_DDrawPlaySmacker(D2SmackRecordStrc* pRecord)
{
    switch (pRecord->nType)
    {
    case 's':
    {
        D2SmackStrc* hSmack = pRecord->pSmack;
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
                    gabRemapTable_008815B0[i] = GetClosestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbRemapValid_008816B4 = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                DDRAW_CloseSmacker(pRecord);
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
