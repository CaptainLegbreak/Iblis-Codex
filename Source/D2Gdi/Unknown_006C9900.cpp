#include "D2Gdi.h"
#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __fastcall sub_006C9640_GdiCloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x006C9640
extern unsigned char gabRemapTable_0098A178[256];                                                           // 0x0098A178
extern unsigned char* gpRemapSource_0098A278;                                                               // 0x0098A278
int gbRemapValid;                                                                                  // 0x0098A27C
extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8

static inline void sub_006C9690_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        *pDst++ = gabRemapTable_0098A178[*pSrc++];
        --nCount;
    }
}

static void __stdcall sub_006C9690_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows);

// build: context sub_006C9690_RemapRows
static void __stdcall sub_006C9690_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
{
    unsigned char* pSrc = gpRemapSource_0098A278;
// build: symbol ?gnRenderWidth@* 0x007C9138
    unsigned char* pDst = (pRect->nY - nRows) * gnRenderWidth + pRect->nX + gpScreenBuffer_007C9154;
    for (unsigned int y = 0; y < nRows; ++y)
    {
        sub_006C9690_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnRenderWidth;
        pSrc += nWidth;
    }
}

// 0x006C9900
void __fastcall sub_006C9900_GdiPlaySmacker(D2SmackRecordStrc* pRecord)
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
                    gabRemapTable_0098A178[i] = GetClosestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbRemapValid = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                sub_006C9640_GdiCloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
// build: symbol ?gbRenderPaused@* 0x007C9144
        if (gbRenderPaused)
            return;
        if (!gbRemapValid)
            return;
        sub_006C9690_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused)
            sub_006C9690_RemapRows(468, pRecord, 60);
        break;
    }
}
