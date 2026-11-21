#include "D2DDraw.h"
#include "D2GfxTypes.h"

extern "C" __declspec(dllimport) int __stdcall SmackWait(D2SmackStrc* hSmack);                             // 0x006CC5F8

extern "C" __declspec(dllimport) void __stdcall SmackDoFrame(D2SmackStrc* hSmack);                         // 0x006CC5FC

extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* hSmack);                       // 0x006CC600

void __fastcall sub_00513330_DDrawCloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330

unsigned char gabRemapTable_008815B0[256];                                                                  // 0x008815B0

extern unsigned char* gpRemapSource_008816B0;                                                               // 0x008816B0

int gbRemapValid_008816B4;                                                                                  // 0x008816B4

extern unsigned char gabGamePalette_007C8CC8[];                                                             // 0x007C8CC8

static void __stdcall sub_00513380_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" __declspec(dllimport) D2SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680

int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth);

extern tagPALETTEENTRY gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8

extern unsigned char gaDDrawSmackRemap_008815B0[256];                                                       // 0x008815B0

extern int gbDDrawSmackRemapReady_008816B4;                                                                 // 0x008816B4

static void* gpDDrawSmackBuffer_008816B0; // 0x008816B0

static inline void sub_00513380_RemapSpan(unsigned char* pDst, const unsigned char* pSrc, int nCount)
{
    while (nCount)
    {
        --nCount;
        *pDst++ = gabRemapTable_008815B0[*pSrc++];
    }
}

// 0x00513380
static void __stdcall sub_00513380_RemapRows(int nWidth, D2SmackRecordStrc* pRect, unsigned int nRows)
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

// 0x00513330
void __fastcall sub_00513330_DDrawCloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (gpDDrawSmackBuffer_008816B0)
    {
        FOG_Free(gpDDrawSmackBuffer_008816B0, szDDSmackFile_006DE20C, 0xF0, 0);
        gpDDrawSmackBuffer_008816B0 = 0;
    }
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
}

// 0x00513400
void __fastcall sub_00513400_DDrawDecodeSmacker(const char* szFile, D2SmackRecordStrc* pRecord, unsigned char nType)
{
    pRecord->nType = nType;
    switch (nType)
    {
    case 's':
    {
        if (pRecord->hSmack)
        {
            return;
        }
        D2SmackStrc* pSmack = SmackOpen(szFile, 0xFE000, -1);
        pRecord->hSmack = pSmack;
        if (!pSmack)
        {
            break;
        }
        unsigned char* pBuffer = (unsigned char*)FOG_Alloc(pSmack->nWidth * pSmack->nHeight, szDDSmackFile_006DE20C, 0x42, 0);
        gpDDrawSmackBuffer_008816B0 = pBuffer;
        memset(pBuffer, 0, pSmack->nWidth * pSmack->nHeight);
        SmackToBuffer(pRecord->hSmack, 0, 0, pSmack->nWidth, pSmack->nHeight, pBuffer, 0);
        gbDDrawSmackRemapReady_008816B4 = 0;
        return;
    }

    case 'p':
    {
        gpDDrawSmackBuffer_008816B0 = (unsigned char*)FOG_Alloc(0x6DB0, szDDSmackFile_006DE20C, 0x53, 0);
        memset(gpDDrawSmackBuffer_008816B0, 0, 0x6DB0);
        void* pData = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pData, &nSize, 0, 3, 0) || !pData)
        {
            break;
        }

        tagPALETTEENTRY aPalette[256];
        int nHeight;
        int nDepth;
        int nWidth;
        const int bDecoded = sub_006C6A80_DecodeImage(2, pData, nSize, aPalette, (unsigned char*)gpDDrawSmackBuffer_008816B0, 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pData, szDDSmackFile_006DE20C, 0x78, 0);
        if (!bDecoded || nWidth != 0x1D4 || nHeight != 0x3C || nDepth != 8)
        {
            break;
        }

        for (int i = 0; i < 256; ++i)
        {
            gaDDrawSmackRemap_008815B0[i] = sub_00605210_FindNearestColor((const unsigned char*)gaDDrawPalette_007C8CC8, 256, aPalette[i].peRed, aPalette[i].peGreen, aPalette[i].peBlue);
        }
        return;
    }

    default:
        return;
    }

    sub_00513330_DDrawCloseSmacker(pRecord);
}

#include "gen/data/Source/D2DDraw/Src/ddSmack.inc"
