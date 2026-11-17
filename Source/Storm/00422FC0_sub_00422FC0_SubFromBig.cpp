struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;
    unsigned int m_offset;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount); // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc); // 0x004216E0
};

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

// 0x00422FC0
static __declspec(noinline) void __stdcall sub_00422FC0_SubFromBig(D2StormArrayAStrc* pSrc, D2StormArrayAStrc* pDst, unsigned int nValue)
{
    unsigned __int64 nAcc = ~(unsigned __int64)nValue + 1;
    unsigned int nIndex = 0;
    unsigned int nCount;
    while (nCount = pSrc->m_count, pSrc->m_offset + nIndex < nCount)
    {
        unsigned int nSrcIdx = pSrc->m_offset + nIndex;
        unsigned int nElem = nSrcIdx < nCount ? pSrc->m_data[nSrcIdx] : 0;
        nAcc += nElem;
        unsigned int nLow = (unsigned int)nAcc;
        unsigned int nHigh = (unsigned int)(nAcc >> 32);
        nAcc = nHigh;
        if (nAcc >= 0x80000000ull)
            nAcc |= 0xFFFFFFFF00000000ull;

        unsigned int nDstIdx = pDst->m_offset + nIndex;
        if (nDstIdx >= pDst->m_count)
        {
            unsigned int nNewCount = nDstIdx + 1;
            if (nNewCount > pDst->m_alloc)
            {
                unsigned int nChunk = pDst->m_chunk;
                if (!nChunk)
                    nChunk = pDst->sub_004210A0_CalcChunkSize(nNewCount);
                unsigned int nAlloc = nNewCount;
                unsigned int nRem = nNewCount % nChunk;
                if (nRem)
                    nAlloc = nNewCount + (nChunk - nRem);
                pDst->sub_004216E0_ReallocData(nAlloc);
            }
            SMemZero(&pDst->m_data[pDst->m_count], (nDstIdx - pDst->m_count) * 4 + 4);
            pDst->m_count = nNewCount;
        }
        pDst->m_data[pDst->m_offset + nIndex] = nLow;
        nIndex++;
    }
    unsigned int nEnd = pDst->m_offset + nIndex;
    if (nEnd > pDst->m_count && nEnd > pDst->m_alloc)
    {
        unsigned int nChunk = pDst->m_chunk;
        if (!nChunk)
            nChunk = pDst->sub_004210A0_CalcChunkSize(nEnd);
        unsigned int nAlloc = nEnd;
        unsigned int nRem = nEnd % nChunk;
        if (nRem)
            nAlloc = nEnd + (nChunk - nRem);
        pDst->sub_004216E0_ReallocData(nAlloc);
    }
    pDst->m_count = nEnd;
}

// 0x00423800
void __stdcall sub_00423800_Caller(D2StormArrayAStrc* pDst, D2StormArrayAStrc* pSrc)
{
    sub_00422FC0_SubFromBig(pSrc, pDst, 1);
}
