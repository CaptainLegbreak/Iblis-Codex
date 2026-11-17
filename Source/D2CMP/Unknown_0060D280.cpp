#include "D2CMP.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2CmpSubTileHeaderStrc
{
    int unk0x00;
    int unk0x04;
    short nFlags;
    unsigned short nLength;
    int unk0x0C;
};

struct D2CmpSubTileRecordStrc
{
    D2CmpSubTileHeaderStrc tHeader;
    unsigned char* pData;
};

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

// 0x0060D280
int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x19);
    unsigned char nValue = *pData;
    int nCount = 0;
    while (pData < pEnd && nValue == *pData && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && nValue == *pData)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

// 0x0060D3A0
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x6F);
    int nCount = 0;
    while (pData < pEnd && *pData != nValue && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && *pData == nValue)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

// build: context sub_0060D5B0_MapSubTileColors
void __fastcall sub_0060D5B0_MapSubTileColors(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpColorStrc tTransparent, D2CmpMapColorFn pfnMapColor)
{
    D2_ASSERT(pDst, 0x82);
    D2_ASSERT(pSrc, 0x83);
    D2_ASSERT(pSrc->pData, 0x84);
    pDst->tHeader = pSrc->tHeader;
    pDst->tHeader.nFlags &= ~1;
    pDst->pData = 0;
    pDst->tHeader.nLength = 0;
    int nCount = pSrc->tHeader.nLength / 3;
    D2_ASSERT(nCount, 0x8E);
    D2_ASSERT(nCount < 0x10000, 0x8F);
    pDst->pData = (unsigned char*)FOG_Alloc(nCount, szSubTileFile, 0x90, 0);
    D2_ASSERT(pDst->pData, 0x91);
    memset(pDst->pData, 0, nCount);
    pDst->tHeader.nFlags |= 1;
    pDst->tHeader.nLength = (unsigned short)nCount;
    const unsigned char* pIn = pSrc->pData;
    unsigned char* pOut = pDst->pData;
    for (int i = 0; i < nCount; i++)
    {
        unsigned char nIndex = 0;
        if (pIn[0] != tTransparent.nRed || pIn[1] != tTransparent.nGreen || pIn[2] != tTransparent.nBlue)
        {
            nIndex = pfnMapColor(pIn[0], pIn[1], pIn[2]);
            D2_ASSERT(nIndex, 0xA1);
        }
        *pOut++ = nIndex;
        pIn += 3;
    }
}
