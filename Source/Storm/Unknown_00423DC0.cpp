inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

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
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nCount);
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
    unsigned int CalcChunkSizeInline(unsigned int nCount)
    {
        if (nCount < 0x40)
        {
            while (nCount & (nCount - 1))
                nCount &= nCount - 1;
            return nCount < 1 ? 1 : nCount;
        }
        f_C = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        if (nIndex < f_4)
            return;
        unsigned int nCount = nIndex + 1;
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : CalcChunkSizeInline(nCount);
            sub_004216E0_ReallocData(RoundUp(nCount, nChunk));
        }
        SMemZero(&f_8[f_4], (nIndex - f_4 + 1) * sizeof(unsigned int));
        f_4 = nIndex + 1;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int CalcChunkSize(unsigned int nCount)
    {
        if (nCount < 0x100)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        f_C = 0x100;
        return 0x100;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004211C0_ReallocData(nCount);
        }
    }
    void Add(unsigned int nCount, const unsigned char* pData)
    {
        Reserve(nCount, 1);
        for (unsigned int i = 0; i < nCount; i++, pData++)
            new (&f_8[f_4 + i]) unsigned char(*pData);
        f_4 += nCount;
    }
    unsigned char* New()
    {
        Reserve(1, 1);
        return &f_8[f_4++];
    }
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    void sub_00421A50_Set(unsigned int nCount, const char* pData);                                          // 0x00421A50
    unsigned int sub_00421F60_Add(unsigned int nCount, const char* pData);                                  // 0x00421F60
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
    __forceinline unsigned int& operator[](unsigned int nIndex)
    {
        m_array.GrowToFit(m_start + nIndex, 1);
        return m_array.f_8[m_start + nIndex];
    }
    void SetCount(unsigned int nCount)
    {
        m_array.SetCount(m_start + nCount);
    }
    void CopyFrom(const D2StormQueueStrc& tSource)
    {
        if (this != &tSource)
            m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
    }
    unsigned int& Ref(int nIndex)
    {
        sub_00421FE0_GrowToFit(nIndex);
        return m_array.f_8[m_start + nIndex];
    }
    __forceinline unsigned int& At(unsigned int nIndex)
    {
        m_array.GrowToFitInline(m_start + nIndex);
        return m_array.f_8[m_start + nIndex];
    }
    void SetStart(unsigned int nStart)
    {
        m_start = nStart;
        if (nStart)
            sub_00421FE0_GrowToFit(-1);
    }
    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    void sub_004220D0_SetCount(unsigned int nCount);                                                        // 0x004220D0
    void sub_00422140_Trim();                                                                               // 0x00422140
};

struct D2StormBigStackStrc
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    D2StormQueueStrc tPrimary;
    D2StormBigStackStrc tStack;
    D2StormArrayBStrc tOutput;
};

unsigned int __stdcall sub_004213B0_FindLastSetBit(D2StormQueueStrc* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(D2StormQueueStrc* pLeft, D2StormQueueStrc* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, D2StormQueueStrc* pB, D2StormBigStackStrc* pStack); // 0x004242C0

inline unsigned __int64 MakeLarge(const unsigned int& nLow, const unsigned int& nHigh)
{
    return (unsigned __int64)nHigh * 0x100000000ui64 + nLow;
}

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

inline unsigned int ExtractLowPartSx(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    if (nValue >= 0x80000000)
        nValue |= 0xFFFFFFFF00000000ui64;
    return nLow;
}

// 0x004225C0
static void __stdcall sub_004225C0_DivUInt(unsigned int* pRemainder, const D2StormQueueStrc& b, unsigned __int64 c, D2StormQueueStrc& a)
{
    a.m_array.SetCount((int)a.m_start - (int)b.m_start + b.m_array.f_4);
    unsigned __int64 nData = 0;
    unsigned int i = b.Count();
    while (i)
    {
        --i;
        nData = nData * 0x100000000ui64 + b[i];
        a[i] = (unsigned int)(nData / c);
        nData %= c;
    }
    a.sub_00422140_Trim();
    *pRemainder = (unsigned int)nData;
}

// 0x004227A0
static void __stdcall sub_004227A0_MulUInt(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned __int64 c)
{
    unsigned __int64 nCarry = 0;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i); i++)
    {
        nCarry += b[i] * c;
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

static __declspec(noinline) void sub_00422CC0_SetZero(D2StormQueueStrc& a);
// 0x00422CC0
static void sub_00422CC0_SetZero(D2StormQueueStrc& a)
{
    a.SetCount(0);
}

// build: context sub_00422D00_Shl
static void __stdcall sub_00422D00_Shl(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int nShift)
{
    unsigned int nWords = nShift / 32;
    unsigned int nBits = nShift % 32;
    unsigned int nCount = b.Count() + nWords + 1;
    unsigned int i = nCount;
    while (i)
    {
        --i;
        unsigned int nValue = 0;
        if (i >= nWords)
        {
            nValue = b[i - nWords] << nBits;
            if (i > nWords && nBits)
                nValue += b[i - nWords - 1] >> (32 - nBits);
        }
        a[i] = nValue;
    }
    a.SetCount(nCount);
    a.sub_00422140_Trim();
}

// 0x00422E70
static void __stdcall sub_00422E70_Shr(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int nShift)
{
    unsigned int nWords = nShift / 32;
    unsigned int nBits = nShift % 32;
    unsigned int i = 0;
    for (; b.IsUsed(i + nWords); i++)
    {
        unsigned int nValue = b[i + nWords] >> nBits;
        if (nBits)
            nValue += b[i + nWords + 1] << (32 - nBits);
        a[i] = nValue;
    }
    a.SetCount(i);
}

// build: context sub_00423100_Sub
static void __stdcall sub_00423100_Sub(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
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

static void __stdcall sub_00423DC0_Div(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, D2StormBigStackStrc& tStack);
// 0x00423DC0
static void __stdcall sub_00423DC0_Div(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, D2StormBigStackStrc& tStack)
{
    c.sub_00422140_Trim();
    d.sub_00422140_Trim();
    unsigned int nCCount = c.Count();
    unsigned int nDCount = d.Count();
    if (nDCount > nCCount)
    {
        b.CopyFrom(c);
        sub_00422CC0_SetZero(a);
        return;
    }
    if (nDCount <= 1)
    {
        const D2StormQueueStrc& tD = d;
        sub_004225C0_DivUInt(&b.Ref(0), c, tD[0], a);
        b.sub_004220D0_SetCount(1);
        return;
    }
    __assume(tStack.nUsed < 16);
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    __assume(tStack.nUsed < 16);
    D2StormQueueStrc& tDiv = tStack.f_0[tStack.nUsed++];
    __assume(tStack.nUsed < 16);
    D2StormQueueStrc& tProduct = tStack.f_0[tStack.nUsed++];
    unsigned int nShift = 31 - (sub_004213B0_FindLastSetBit(&d) & 31);
    sub_00422D00_Shl(tRem, c, nShift);
    sub_00422D00_Shl(tDiv, d, nShift);
    unsigned int nLastDigit = nDCount - 1;
    unsigned int nTop = tDiv.Ref(nLastDigit) + 1;
    unsigned int i = nCCount - nDCount + 1;
    a.sub_004220D0_SetCount(i);
    while (i)
    {
        --i;
        a.SetStart(i);
        tRem.SetStart(i);
        if (!nTop)
            a.Ref(0) = tRem.Ref(nDCount);
        else
            {
            const unsigned int& nHigh = tRem.Ref(nDCount);
            const unsigned int& nLow = tRem.Ref(nLastDigit);
            unsigned __int64 nWide = (unsigned __int64)nHigh * 0x100000000ui64;
            nWide += nLow;
            a.Ref(0) = (unsigned int)(nWide / nTop);
        }
        if (a.Ref(0))
        {
            sub_004227A0_MulUInt(tProduct, tDiv, a.Ref(0));
            sub_00423100_Sub(tRem, tRem, tProduct);
        }
        while (tRem.At(nDCount) || sub_004212F0_Compare(&tRem, &tDiv) >= 0)
        {
            a.At(0)++;
            sub_00423100_Sub(tRem, tRem, tDiv);
        }
    }
    sub_00422E70_Shr(b, tRem, nShift);
    b.sub_00422140_Trim();
    __assume(3 <= tStack.nUsed);
    tStack.nUsed -= 3;
}

// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    D2StormBigStackStrc& tStack = pResult->tStack;
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    sub_00423DC0_Div(pResult->tPrimary, tRem, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424ED0
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    D2StormBigStackStrc& tStack = pResult->tStack;
    D2StormQueueStrc& tQuotient = tStack.f_0[tStack.nUsed++];
    sub_00423DC0_Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}
