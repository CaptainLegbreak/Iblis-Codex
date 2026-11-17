void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                    // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                            // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                   // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                      // 0x004216E0
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0

    unsigned int GetInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        return nPosition < m_array.f_4 ? m_array.f_8[nPosition] : 0;
    }
    // build: context D2StormQueueStrc::SetCountInline
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_array.f_4 && nCount > m_array.f_0)
        {
            unsigned int nChunk = m_array.f_C;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.sub_004216E0_ReallocData(nAlloc);
        }
        m_array.f_4 = nCount;
    }
    unsigned int ChunkSizeInline(unsigned int nCount)
    {
        if (nCount < 0x40)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_array.f_C = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        if (nPosition >= m_array.f_4)
        {
            const unsigned int nNewCount = nPosition + 1;
            if (nNewCount > m_array.f_0)
            {
                const unsigned int nChunk = m_array.f_C ? m_array.f_C : ChunkSizeInline(nNewCount);
                unsigned int nAlloc = nNewCount;
                const unsigned int nRemainder = nNewCount % nChunk;
                if (nRemainder)
                    nAlloc = nNewCount + nChunk - nRemainder;
                m_array.sub_004216E0_ReallocData(nAlloc);
            }
            SMemZero(&m_array.f_8[m_array.f_4], (nPosition - m_array.f_4 + 1) * sizeof(unsigned int));
            m_array.f_4 = nNewCount;
        }
    }
    unsigned int& AtInline(unsigned int nIndex)
    {
        GrowToFitInline(nIndex);
        return m_array.f_8[m_start + nIndex];
    }
};

struct D2StormBigStackStrc
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

// 0x00420EB0
static __declspec(noinline) unsigned int __stdcall sub_00420EB0_Accumulate64(unsigned __int64 nValue, unsigned __int64* pAccumulator)
{
    *pAccumulator += nValue;
    const unsigned __int64 nCarry = *pAccumulator < nValue ? 1ui64 : 0ui64;
    const unsigned int nLow = (unsigned int)*pAccumulator;
    *pAccumulator >>= 32;
    *pAccumulator += nCarry * 0x100000000ui64;
    return nLow;
}

void __stdcall sub_00424B00_BigSquare(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, D2StormBigStackStrc* pStack)
{
    D2StormQueueStrc* pWork;
    if (pResult == pA)
        pWork = &pStack->f_0[pStack->nUsed++];
    else
        pWork = pResult;

    pWork->SetCountInline(pWork->m_start);

    for (unsigned int i = 0; pA->m_start + i < pA->m_array.f_4; i++)
    {
        unsigned __int64 nCarry = 0;
        unsigned int j;
        for (j = 0; j <= i; j++)
        {
            const unsigned int nDigit = pA->GetInline(j);
            const unsigned __int64 nProduct = (unsigned __int64)pA->sub_004212D0_Get(i) * nDigit;
            const unsigned int k = j + i;
            const unsigned __int64 nSum = pWork->AtInline(k) + nProduct;
            if (j < i)
                nCarry += nProduct;
            unsigned int& rDigit = pWork->AtInline(k);
            rDigit = sub_00420EB0_Accumulate64(nSum, &nCarry);
        }
        pWork->AtInline(j + i) = (unsigned int)nCarry;
    }

    if (pResult != pWork)
    {
        pResult->m_array.sub_004215C0_Set(pWork->m_array.f_4, pWork->m_array.f_8);
        pResult->m_array.f_C = pWork->m_array.f_C;
        pResult->m_start = pWork->m_start;
        pStack->nUsed--;
    }
}
