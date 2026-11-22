inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);

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
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
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
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
    void sub_004216E0_ReallocData(unsigned int nAlloc);
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
    inline unsigned int& operator[](unsigned int nIndex)
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
    inline unsigned int& At(unsigned int nIndex)
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
    void sub_00421FE0_GrowToFit(int nIndex);
    void sub_004220D0_SetCount(unsigned int nCount);
    void sub_00422140_Trim();
};

struct BigStack
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    D2StormQueueStrc tPrimary;
    BigStack tStack;
};

unsigned int __stdcall sub_004213B0_FindLastSetBit(D2StormQueueStrc* pQueue);
int __stdcall sub_004212F0_Compare(D2StormQueueStrc* pLeft, D2StormQueueStrc* pRight);
int __stdcall sub_004242C0_BigOp(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, D2StormQueueStrc* pB, BigStack* pStack);
int __stdcall sub_00424B00_Square(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, BigStack* pStack);
unsigned int __stdcall sub_00421470_FindLowestSetBit(D2StormQueueStrc* pQueue);
extern const unsigned int gaSBigFermatBases[1];
extern const unsigned int gaSBigSmallPrimes[171];

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

static void __stdcall sub_00422300_Add(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
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

static void __stdcall sub_004225C0_DivUInt(D2StormQueueStrc& a, unsigned int* pRemainder, const D2StormQueueStrc& b, unsigned __int64 c)
{
    a.SetCount(b.Count());
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

static int IsZero(D2StormQueueStrc& a)
{
    a.sub_00422140_Trim();
    return a.Count() == 0;
}

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

static void SetOne(D2StormQueueStrc& a)
{
    a.SetCount(1);
    a.sub_00421FE0_GrowToFit(0);
    a.m_array.f_8[a.m_start] = 1;
}

static void SetZero(D2StormQueueStrc& a)
{
    a.SetCount(0);
}

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

static void __stdcall Shr(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int nShift)
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

static void __stdcall sub_00423DC0_Div(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    d.sub_00422140_Trim();
    unsigned int nCCount = c.Count();
    unsigned int nDCount = d.Count();
    if (nDCount > nCCount)
    {
        b.CopyFrom(c);
        SetZero(a);
        return;
    }
    if (nDCount <= 1)
    {
        const D2StormQueueStrc& tD = d;
        sub_004225C0_DivUInt(a, &b.Ref(0), c, tD[0]);
        b.sub_004220D0_SetCount(1);
        return;
    }
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tDiv = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tProduct = tStack.f_0[tStack.nUsed++];
    unsigned int nShift = 31 - (sub_004213B0_FindLastSetBit(&d) & 31);
    sub_00422D00_Shl(tRem, c, nShift);
    sub_00422D00_Shl(tDiv, d, nShift);
    unsigned int nTop = tDiv.Ref(nDCount - 1) + 1;
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
            a.Ref(0) = (unsigned int)(MakeLarge(tRem.Ref(nDCount - 1), tRem.Ref(nDCount)) / nTop);
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
    Shr(b, tRem, nShift);
    b.sub_00422140_Trim();
    tStack.nUsed -= 3;
}

static void __stdcall sub_004221F0_AddUInt(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int c)
{
    unsigned __int64 nCarry = c;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i); i++)
    {
        nCarry += b[i];
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

static int IsOne(D2StormQueueStrc& a)
{
    a.sub_00422140_Trim();
    const D2StormQueueStrc& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
}

static void __stdcall Set2Exp(D2StormQueueStrc& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
}

static void __stdcall sub_00422FC0_SubUInt(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int c)
{
    unsigned __int64 nBorrow = ~(unsigned __int64)c + 1;
    unsigned int i = 0;
    for (; b.IsUsed(i); i++)
    {
        nBorrow += b[i];
        a[i] = ExtractLowPartSx(nBorrow);
    }
    a.SetCount(i);
}

static void __stdcall FromUnsigned(D2StormQueueStrc& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

static void __stdcall sub_00424180_Gcd(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, BigStack& tStack)
{
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tNext = tStack.f_0[tStack.nUsed++];
    if (sub_004212F0_Compare(&b, &c) > 0)
    {
        a.CopyFrom(b);
        tNext.CopyFrom(c);
    }
    else
    {
        a.CopyFrom(c);
        tNext.CopyFrom(b);
    }
    while (!IsZero(tNext))
    {
        sub_00423DC0_Div(a, tRem, a, tNext, tStack);
        a.CopyFrom(tNext);
        tNext.CopyFrom(tRem);
    }
    tStack.nUsed -= 2;
}

static void __stdcall sub_004245F0_MulMod(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, BigStack& tStack)
{
    D2StormQueueStrc& tProduct = tStack.f_0[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    sub_00423DC0_Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

static void __stdcall sub_00425150_PowMod(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    if (!c.Count())
    {
        SetOne(a);
        return;
    }
    D2StormQueueStrc& tQuot = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tSquare = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tCube = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tWork = (&a == &b || &a == &c || &a == &d) ? tStack.f_0[tStack.nUsed++] : a;
    sub_004245F0_MulMod(tSquare, b, b, d, tStack);
    sub_004245F0_MulMod(tCube, tSquare, b, d, tStack);
    D2StormQueueStrc* aPowers[3] = { &b, &tSquare, &tCube };
    SetOne(tWork);
    const D2StormQueueStrc& tExp = c;
    for (unsigned int i = c.Count(); i; i--)
    {
        unsigned int nDigit = tExp[i - 1];
        unsigned int nBits = 32;
        if (i == c.Count())
        {
            while (!(nDigit & 0xC0000000))
            {
                nDigit <<= 2;
                nBits -= 2;
            }
        }
        for (; nBits; nBits -= 2)
        {
            sub_00424B00_Square(&tWork, &tWork, &tStack);
            sub_00423DC0_Div(tQuot, tWork, tWork, d, tStack);
            sub_00424B00_Square(&tWork, &tWork, &tStack);
            sub_00423DC0_Div(tQuot, tWork, tWork, d, tStack);
            if (nDigit >> 30)
                sub_004245F0_MulMod(tWork, tWork, *aPowers[(nDigit >> 30) - 1], d, tStack);
            nDigit <<= 2;
        }
    }
    if (&tWork != &a)
    {
        a.CopyFrom(tWork);
        tStack.nUsed--;
    }
    tStack.nUsed -= 3;
}

static int __stdcall sub_00425350_IsPrime(BigStack& tStack, D2StormQueueStrc& a)
{
    D2StormQueueStrc& tMinusOne = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tOdd = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tWork = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tBase = tStack.f_0[tStack.nUsed++];
    int bPrime = 1;
    a.sub_00422140_Trim();
    const D2StormQueueStrc& tRead = a;
    if (IsZero(a) || !(tRead[0] & 1))
        bPrime = 0;
    for (unsigned int i = 0; bPrime && i < 171; i++)
    {
        unsigned __int64 nPrime = gaSBigSmallPrimes[i];
        int bZero;
        if (nPrime < 0x100000000ui64)
        {
            unsigned int nRemainder;
            sub_004225C0_DivUInt(tWork, &nRemainder, a, nPrime);
            bZero = !nRemainder;
        }
        else
        {
            FromUnsigned(tBase, (unsigned int)nPrime);
            sub_00423DC0_Div(tWork, tOdd, a, tBase, tStack);
            bZero = IsZero(tOdd);
        }
        if (bZero && !IsOne(tWork))
            bPrime = 0;
    }
    sub_00422FC0_SubUInt(tMinusOne, a, 1);
    tOdd.CopyFrom(tMinusOne);
    unsigned int nShift = sub_00421470_FindLowestSetBit(&tOdd);
    if (nShift)
        Shr(tOdd, tOdd, nShift);
    for (unsigned int i = 0; bPrime && i < 6; i++)
    {
        FromUnsigned(tBase, gaSBigSmallPrimes[i]);
        if (sub_004212F0_Compare(&tBase, &a) >= 0)
            break;
        sub_00425150_PowMod(tWork, tBase, tOdd, a, tStack);
        if (!IsOne(tWork) && sub_004212F0_Compare(&tWork, &tMinusOne))
        {
            unsigned int j = 0;
            do
            {
                if (++j == nShift)
                {
                    bPrime = 0;
                    break;
                }
                sub_004245F0_MulMod(tWork, tWork, tWork, a, tStack);
                if (IsOne(tWork))
                {
                    bPrime = 0;
                    break;
                }
            } while (sub_004212F0_Compare(&tWork, &tMinusOne));
        }
    }
    for (unsigned int i = 0; bPrime && i < 1; i++)
    {
        FromUnsigned(tBase, gaSBigFermatBases[i]);
        sub_00425150_PowMod(tWork, tBase, a, a, tStack);
        if (sub_004212F0_Compare(&tWork, &tBase))
            bPrime = 0;
    }
    tStack.nUsed -= 4;
    return bPrime;
}

// 0x00421440
static int sub_00421440_IsEven(const D2StormQueueStrc& a)
{
    return !a.Count() || !(a[0] & 1);
}

static void __stdcall sub_004255E0_FindPrime(unsigned int nBits, D2StormQueueStrc& b, D2StormQueueStrc& c, BigStack& tStack, D2StormQueueStrc& a)
{
    D2StormQueueStrc& tLow = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tHigh = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tWork = tStack.f_0[tStack.nUsed++];
    Set2Exp(tLow, nBits - 2);
    Set2Exp(tHigh, nBits - 1);
    sub_00422300_Add(tHigh, tHigh, tLow);
    sub_00423DC0_Div(tWork, a, b, tLow, tStack);
    sub_00422300_Add(a, a, tHigh);
    if (sub_00421440_IsEven(a))
        sub_004221F0_AddUInt(a, a, 1);
    sub_00422300_Add(tHigh, tHigh, tLow);
    sub_00422FC0_SubUInt(tHigh, tHigh, 2);
    for (;;)
    {
        if (sub_00425350_IsPrime(tStack, a))
        {
            if (IsOne(c))
                break;
            sub_00422FC0_SubUInt(tWork, a, 1);
            sub_00424180_Gcd(tWork, tWork, c, tStack);
            if (IsOne(tWork))
                break;
        }
        sub_004221F0_AddUInt(a, a, 2);
        if (sub_004212F0_Compare(&a, &tHigh) > 0)
            sub_00423100_Sub(a, a, tLow);
    }
    tStack.nUsed -= 3;
}

void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus)
{
    sub_00425150_PowMod(pResult->tPrimary, pBase->tPrimary, pExponent->tPrimary, pModulus->tPrimary, pResult->tStack);
}

int __stdcall SBigIsPrime(D2StormBigStrc* pBig)
{
    return sub_00425350_IsPrime(pBig->tStack, pBig->tPrimary);
}

void __stdcall SBigFindPrime(D2StormBigStrc* pResult, unsigned int nBits, D2StormBigStrc* pRandom, D2StormBigStrc* pExponent)
{
    sub_004255E0_FindPrime(nBits, pRandom->tPrimary, pExponent->tPrimary, pResult->tStack, pResult->tPrimary);
}

static void __stdcall sub_00424FB0_InvMod(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, BigStack& tStack)
{
    D2StormQueueStrc& tPrev = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tNum = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tDen = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tQuot = tStack.f_0[tStack.nUsed++];
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    tNum.CopyFrom(b);
    tDen.CopyFrom(c);
    SetOne(a);
    SetZero(tPrev);
    int nSign = 1;
    while (!IsZero(tDen))
    {
        sub_00423DC0_Div(tQuot, tRem, tNum, tDen, tStack);
        sub_004242C0_BigOp(&tQuot, &tQuot, &tPrev, &tStack);
        sub_00422300_Add(tQuot, a, tQuot);
        a.CopyFrom(tPrev);
        tPrev.CopyFrom(tQuot);
        tNum.CopyFrom(tDen);
        tDen.CopyFrom(tRem);
        nSign = -nSign;
    }
    if (nSign < 0)
        sub_00423100_Sub(a, c, a);
    tStack.nUsed -= 5;
}

void __stdcall SBigInvMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00424FB0_InvMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}
