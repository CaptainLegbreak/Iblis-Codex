#include "D2DDraw.h"
#include "D2GfxTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) D2SmackStrc* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, T004F51E0* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth);
extern T004F51E0 gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8
extern unsigned char gaDDrawSmackRemap_008815B0[256];                                                       // 0x008815B0
extern int gbDDrawSmackRemapReady_008816B4;                                                                 // 0x008816B4
static void* gpDDrawSmackBuffer_008816B0; // 0x008816B0

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

        T004F51E0 aPalette[256];
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

#include "gen/data/Source/D2DDraw/Src/ddSmack_00513400.inc"
