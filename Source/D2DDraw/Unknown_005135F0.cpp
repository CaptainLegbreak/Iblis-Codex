#include "D2DDraw.h"
#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __fastcall DDRAW_CloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
unsigned char gabDDrawSmackRemap[256];                                                                  // 0x008815B0
extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0
int gbDDrawSmackRemapReady;                                                                                  // 0x008816B4
extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140

static inline void sub_00513380_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        *pDst++ = gabDDrawSmackRemap[*pSrc++];
        --nCount;
    }
}

static void __stdcall DDRAW_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows); // 0x00513380

// build: context DDRAW_RemapRows
static void __stdcall DDRAW_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
{
    unsigned char* pSrc = gpRemapSource_008816B0;
// build: symbol ?gnRenderWidth@* 0x007C9138
    unsigned char* pDst = (pRect->nY - nRows) * gnRenderWidth + pRect->nX + gpScreenBuffer_007C9154;
    for (unsigned int y = 0; y < nRows; ++y)
    {
        sub_00513380_RemapSpan(pDst, pSrc, nWidth);
        pDst += gnRenderWidth;
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
                    gabDDrawSmackRemap[i] = GetClosestColor(gabGamePalette_007C8CC8, 256, hSmack->aPalette[i].nRed, hSmack->aPalette[i].nGreen, hSmack->aPalette[i].nBlue);
                }
                gbDDrawSmackRemapReady = 1;
            }
            SmackDoFrame(hSmack);
            if (hSmack->nFrameNum == hSmack->nFrames)
                DDRAW_CloseSmacker(pRecord);
            else
                SmackNextFrame(hSmack);
        }
// build: symbol ?gbRenderPaused@* 0x007C9144
        if (gbRenderPaused)
            return;
        if (!gbDDrawSmackRemapReady)
            return;
        DDRAW_RemapRows(hSmack->nWidth, pRecord, hSmack->nHeight);
        return;
    }
    case 'p':
        if (!gbRenderPaused)
            DDRAW_RemapRows(468, pRecord, 60);
        break;
    }
}
