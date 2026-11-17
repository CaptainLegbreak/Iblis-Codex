struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount); // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc); // 0x004216E0
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
    void sub_00421FE0_GrowToFit(int nIndex); // 0x00421FE0
};

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

static __forceinline void ReserveCount(D2StormArrayAStrc* pArray, unsigned int nCount)
{
    if (nCount > pArray->m_alloc)
    {
        unsigned int nChunk = pArray->m_chunk;
        if (!nChunk)
        {
            nChunk = pArray->sub_004210A0_CalcChunkSize(nCount);
        }
        unsigned int nNew = nCount;
        unsigned int nRem = nCount % nChunk;
        if (nRem)
        {
            nNew = nCount + (nChunk - nRem);
        }
        pArray->sub_004216E0_ReallocData(nNew);
    }
}

// 0x00423380
static void __stdcall sub_00423380_FromBytes(D2StormQueueStrc* pThis, const unsigned char* pData, unsigned int nSize)
{
    unsigned int nStart = pThis->m_start;
    if (nStart > pThis->m_array.m_count)
    {
        ReserveCount(&pThis->m_array, nStart);
    }
    pThis->m_array.m_count = nStart;

    for (unsigned int i = 0; i < nSize; ++i)
    {
        unsigned int nIdx = i >> 2;
        unsigned int nShift = i & 3;
        unsigned int nByte = pData[i];
        unsigned int nCur;
        if (nShift)
        {
            pThis->sub_00421FE0_GrowToFit(nIdx);
            nCur = pThis->m_array.m_data[pThis->m_start + nIdx];
        }
        else
        {
            nCur = 0;
        }
        unsigned int nPos = pThis->m_start + nIdx;
        if (nPos >= pThis->m_array.m_count)
        {
            unsigned int nNewCount = nPos + 1;
            ReserveCount(&pThis->m_array, nNewCount);
            SMemZero(&pThis->m_array.m_data[pThis->m_array.m_count], (nPos - pThis->m_array.m_count) * 4 + 4);
            pThis->m_array.m_count = nNewCount;
        }
        pThis->m_array.m_data[pThis->m_start + nIdx] = (nByte << (nShift * 8)) + nCur;
    }
}

// 0x00423850
void __stdcall sub_00423850(D2StormQueueStrc* pThis, const unsigned char* pData, unsigned int nSize)
{
    sub_00423380_FromBytes(pThis, pData, nSize);
}
