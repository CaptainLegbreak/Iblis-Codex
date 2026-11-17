#include "Storm.h"

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormFixedArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    D2StormFixedArrayAStrc& operator=(const D2StormFixedArrayAStrc& tSource)
    {
        if (this != &tSource)
        {
            sub_004215C0_Set(tSource.f_4, tSource.f_8);
        }
        return *this;
    }
    void InlineReallocData(unsigned int nAlloc)
    {
        f_0 = nAlloc;
        if (f_8 || nAlloc)
            f_8 = (unsigned int*)SMemReAlloc(f_8, nAlloc * sizeof(unsigned int), gszTypeNameUInt_00708874, -2, 0);
    }
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
};

// 0x004215C0
void D2StormFixedArrayAStrc::sub_004215C0_Set(unsigned int nCount, const unsigned int* pData)
{
    InlineReallocData(nCount);
    for (unsigned int i = 0; i < nCount; i++, pData++)
        new (&f_8[i]) unsigned int(*pData);
    f_4 = nCount;
}

struct D2StormArrayAStrc : D2StormFixedArrayAStrc
{
    unsigned int f_C;
};

struct D2StormQueueStrc : D2StormArrayAStrc
{
    unsigned int m_start;
};

struct D2StormArrayViewStrc
{
    const unsigned int* pData;
    unsigned int nCount;
};

struct D2StormRecordStackStrc
{
    D2StormQueueStrc pRecords[16];
    unsigned int nUsed;

    void sub_00423D80_Release(D2StormQueueStrc* pResult, D2StormQueueStrc* pWork);
};

// 0x00423D80
void D2StormRecordStackStrc::sub_00423D80_Release(D2StormQueueStrc* pResult, D2StormQueueStrc* pWork)
{
    if (pResult != pWork)
    {
        D2StormArrayViewStrc tView;
        tView.pData = pWork->f_8;
        tView.nCount = pWork->f_4;
        pResult->sub_004215C0_Set(tView.nCount, tView.pData);
        pResult->f_C = pWork->f_C;
        pResult->m_start = pWork->m_start;
        nUsed--;
    }
}
