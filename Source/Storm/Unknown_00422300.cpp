struct D2StormArrayAStrc;
struct BigBuffer;
struct D2StormBigStrc;

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
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
        nCount += f_4;
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
        if (nCount > f_4)
            Reserve(nCount - f_4, 1);
        f_4 = nCount;
    }
    void GrowToFit(unsigned int nIndex, int bZero)
    {
        if (nIndex < f_4)
            return;
        Reserve(nIndex - f_4 + 1, 1);
        if (bZero)
            SMemZero(&f_8[f_4], (nIndex - f_4 + 1) * sizeof(unsigned int));
        f_4 = nIndex + 1;
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
        return nIndex + m_start < m_array.f_4;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
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


inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

// 0x00422300
static void __stdcall sub_00422300_Add(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned __int64 nCarry = 0;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i) || c.IsUsed(i); i++)
    {
        nCarry += (unsigned __int64)b[i] + c[i];
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

// 0x00423790
void __stdcall SBigAdd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00422300_Add(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00422440
static void __stdcall sub_00422440_And(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] & c[i];
    }
    a.SetCount(i);
}

// 0x004237B0
void __stdcall SBigAnd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00422440_And(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x004229D0
static void __stdcall sub_004229D0_Or(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] | c[i];
    }
    a.SetCount(i);
}

// 0x00423A00
void __stdcall SBigOr(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_004229D0_Or(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00423250
static void __stdcall sub_00423250_Xor(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] ^ c[i];
    }
    a.SetCount(i);
}

// 0x00423D60
void __stdcall SBigXor(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423250_Xor(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}
