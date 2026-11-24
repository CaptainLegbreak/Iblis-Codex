#include "D2CMP.h"
#include "D2CmpTypes.h"

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

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

void __fastcall SubTileConvert24To8(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpColorStrc tTransparent, D2CmpMapColorFn pfnMapColor); // 0x0060D5B0
