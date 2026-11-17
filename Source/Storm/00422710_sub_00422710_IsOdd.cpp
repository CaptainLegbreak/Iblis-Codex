struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int Count() const
    {
        return m_array.f_4 - m_start;
    }
    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.f_4;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
    }
    void sub_00422140_Trim();                                                                               // 0x00422140
};

struct D2StormBigStrc
{
    D2StormQueueStrc tQueue;
};

// 0x00422710
static __declspec(noinline) int sub_00422710_IsOdd(D2StormQueueStrc* pQueue)
{
    pQueue->sub_00422140_Trim();
    if (pQueue->Count() >= 1 && ((*pQueue)[0] & 1))
    {
        return 1;
    }
    return 0;
}

// 0x004238F0
int __stdcall SBigIsOdd(D2StormBigStrc* pBig)
{
    return sub_00422710_IsOdd(&pBig->tQueue);
}
