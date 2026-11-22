void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

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

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4.n;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C;
                if (!nChunk)
                    nChunk = sub_004210A0_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004216E0_ReallocData(nCount);
        }
    }
    void SetCount(unsigned int nCount)
    {
        if (nCount > f_4.n)
            Reserve(nCount - f_4.n, 1);
        f_4.n = nCount;
    }
    void GrowToFit(unsigned int nIndex, int bZero)
    {
        if (nIndex < f_4.n)
            return;
        Reserve(nIndex - f_4.n + 1, 1);
        if (bZero)
            SMemZero(&f_8[f_4.n], (nIndex - f_4.n + 1) * sizeof(unsigned int));
        f_4.n = nIndex + 1;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.f_4;
        return nIndex + m_start < tCount.n;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.f_4.n ? m_array.f_8[m_start + nIndex] : 0;
    }
    __forceinline unsigned int& operator[](unsigned int nIndex)
    {
        m_array.GrowToFit(m_start + nIndex, 1);
        return m_array.f_8[m_start + nIndex];
    }
    void SetCount(unsigned int nCount)
    {
        m_array.SetCount(m_start + nCount);
    }
};

struct D2StormBigStrc
{
    BigBuffer tPrimary;
    char unk0x14[0x154];
};

// build: context ExtractLowPartSx
inline unsigned int ExtractLowPartSx(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    if (nValue >= 0x80000000)
        nValue |= 0xFFFFFFFF00000000ui64;
    return nLow;
}

// 0x00423100
static void __stdcall sub_00423100_Sub(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned __int64 nBorrow = 0;
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        nBorrow += (unsigned __int64)b[i] - c[i];
        a[i] = ExtractLowPartSx(nBorrow);
    }
    a.SetCount(i);
}

// 0x00423AC0
void __stdcall SBigSub(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423100_Sub(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}
