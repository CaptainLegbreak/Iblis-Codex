#include "Storm.h"
#include "stpl.h"

#define TO_UNSIGNED sub_00421510_ToUnsigned

struct BigBuffer;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct BigBuffer
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int At(unsigned int nIndex) const
    {
        return m_offset + nIndex < f_4 ? f_8[m_offset + nIndex] : 0;
    }
};

int __stdcall sub_004212F0_Compare(void* hLeft, void* hRight); // 0x004212F0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNewsTableItem_0072FF8C[];

static void __cdecl sub_00421510_ToUnsigned(unsigned int* pnResult, BigBuffer* pBuf);

// build: symbol ?ReallocData@?$TSFixedArray@IU?$TSCD@I@@@@QAEXI@Z 0x00421110
// build: symbol ?ReallocData@?$TSFixedArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421680
// build: symbol ?ReallocData@?$TSFixedArray@DU?$TSCD@D@@@@QAEXI@Z 0x004216B0
// build: symbol ??4?$TSFixedArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421870
// build: symbol ?SetCount@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421980
// build: symbol ??4?$TSGrowableArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421BA0
// build: symbol ?Set@?$TSFixedArray@IU?$TSCD@I@@@@QAEXIPBI@Z 0x004215C0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@EU?$TSCD@E@@@@QAEII@Z 0x00421160
// build: symbol ?ReallocData@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x004211C0
// build: symbol ??_R0I@8 0x0070886C
// build: symbol ??_R0E@8 0x00708878
// build: symbol ??_R0D@8 0x00708884
template void TSFixedArray<unsigned int>::ReallocData(unsigned int);
template void TSFixedArray<unsigned char>::ReallocData(unsigned int);
template void TSFixedArray<char>::ReallocData(unsigned int);
template TSFixedArray<unsigned int>& TSFixedArray<unsigned int>::operator=(const TSFixedArray<unsigned int>&);
template void TSGrowableArray<unsigned char>::SetCount(unsigned int);
template TSGrowableArray<unsigned int>& TSGrowableArray<unsigned int>::operator=(const TSGrowableArray<unsigned int>&);

// 0x00421510
static void __cdecl sub_00421510_ToUnsigned(unsigned int* pnResult, BigBuffer* pBuf)
{
    *pnResult = 0;
    *pnResult = pBuf->At(0);
}

// 0x00421530
int __stdcall sub_00421530(void* hLeft, void* hRight)
{
    return sub_004212F0_Compare(hLeft, hRight);
}

// 0x00421550
void __stdcall SBigToUnsigned(void* hBig, unsigned int* pnResult)
{
    TO_UNSIGNED(pnResult, (BigBuffer*)hBig);
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    return this;
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00421860
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}
