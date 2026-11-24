#include "Storm.h"
#include "stpl.h"

struct D2Storm408ElemStrc;
struct D2StormArray408Strc;

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNewsTableItem_0072FF8C[];

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

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
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
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00421860
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}
