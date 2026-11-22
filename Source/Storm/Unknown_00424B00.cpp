#include "D2StormTypes.h"
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                    // 0x0041D300

struct D2StormCountStrc
{
    unsigned int n;
};

struct D2StormArrayAStrc
{
    unsigned int f_0;
    D2StormCountStrc f_4;
    unsigned int* f_8;
    unsigned int f_C;

    unsigned int Count() const
    {
        return f_4.n;
    }
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                            // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                   // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                      // 0x004216E0
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0

    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.f_4;
        return nIndex + m_start < tCount.n;
    }
    unsigned int GetInline(unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
    }
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_array.f_4.n && nCount > m_array.f_0)
        {
            unsigned int nChunk = m_array.f_C;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            m_array.sub_004216E0_ReallocData(D2StormArrayAStrc::RoundUp(nCount, nChunk));
        }
        m_array.f_4.n = nCount;
    }
    unsigned int ChunkSizeInline(unsigned int nCount)
    {
        unsigned int nResult = nCount;
        if (nCount < 0x40)
        {
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_array.f_C = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nPosition)
    {
        if (nPosition < m_array.f_4.n)
            return;
        const unsigned int nNewCount = nPosition + 1;
        if (nNewCount > m_array.f_0)
        {
            const unsigned int nChunk = m_array.f_C ? m_array.f_C : ChunkSizeInline(nNewCount);
            m_array.sub_004216E0_ReallocData(D2StormArrayAStrc::RoundUp(nNewCount, nChunk));
        }
        SMemZero(&m_array.f_8[m_array.f_4.n], (nPosition - m_array.f_4.n + 1) * sizeof(unsigned int));
        m_array.f_4.n = nPosition + 1;
    }
    inline unsigned int& AtInline(unsigned int nIndex)
    {
        GrowToFitInline(m_start + nIndex);
        return m_array.f_8[m_start + nIndex];
    }
};

struct BigStack
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

// 0x00420EB0
static __declspec(noinline) unsigned int __stdcall sub_00420EB0_AddWithCarry(unsigned __int64 nValue, unsigned __int64* pAccumulator)
{
    *pAccumulator += nValue;
    const unsigned __int64 nCarry = *pAccumulator < nValue ? 1ui64 : 0ui64;
    const unsigned int nLow = (unsigned int)*pAccumulator;
    *pAccumulator >>= 32;
    *pAccumulator += nCarry * 0x100000000ui64;
    return nLow;
}

// 0x00424B00
void __stdcall sub_00424B00_BigSquare(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, BigStack* pStack)
{
    D2StormQueueStrc* pWork;
    if (pResult == pA)
    {
        // the original relies on the work-stack index staying below 16 here (its push/pop check); without it the frame and loads differ
        __assume(pStack->nUsed < 16);
        pWork = &pStack->f_0[pStack->nUsed++];
    }
    else
        pWork = pResult;

    pWork->SetCountInline(pWork->m_start);

    for (unsigned int i = 0; pA->IsUsed(i); i++)
    {
        unsigned __int64 nCarry = 0;
        unsigned int j;
        for (j = 0; j <= i; j++)
        {
            const unsigned int nDigit = pA->GetInline(j);
            const unsigned __int64 nProduct = (unsigned __int64)pA->sub_004212D0_Get(i) * nDigit;
            const unsigned int k = i + j;
            const unsigned __int64 nSum = pWork->AtInline(i + j) + nProduct;
            if (j < i)
                nCarry += nProduct;
            pWork->AtInline(k) = sub_00420EB0_AddWithCarry(nSum, &nCarry);
        }
        pWork->AtInline(j + i) = (unsigned int)nCarry;
    }

    if (pResult != pWork)
    {
        pResult->m_array.sub_004215C0_Set(pWork->m_array.f_4.n, pWork->m_array.f_8);
        pResult->m_array.f_C = pWork->m_array.f_C;
        pResult->m_start = pWork->m_start;
        __assume(1 <= pStack->nUsed);
        pStack->nUsed--;
    }
}

// build: context ?RoundUp@D2StormArrayAStrc@@SGIII@Z
// build: context ?IsUsed@D2StormQueueStrc@@QBEHI@Z
// build: context ?GetInline@D2StormQueueStrc@@QBEII@Z
// build: context ?SetCountInline@D2StormQueueStrc@@QAEXI@Z
// build: context ?ChunkSizeInline@D2StormQueueStrc@@QAEII@Z
// build: context ?GrowToFitInline@D2StormQueueStrc@@QAEXI@Z
// build: context ?AtInline@D2StormQueueStrc@@QAEAAII@Z
