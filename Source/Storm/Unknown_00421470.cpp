struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0
};

// 0x00421470
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue)
{
    const unsigned int nStart = pQueue->m_start;
    unsigned int i = 0;
    const unsigned int nCount = pQueue->m_array.f_4 - nStart;
    const unsigned int nUsed = pQueue->m_array.f_4;
    if (nCount)
    {
        unsigned int nPos = nStart;
        do
        {
            if (nPos < nUsed && pQueue->m_array.f_8[nStart + i])
            {
                unsigned int nMask = 1;
                for (unsigned int nBit = 0; nBit < 32; ++nBit, nMask <<= 1)
                {
                    if (pQueue->sub_004212D0_Get(i) & nMask)
                        return i * 32 + nBit;
                }
            }
            ++i;
            ++nPos;
        } while (i < nCount);
    }
    return 0;
}
