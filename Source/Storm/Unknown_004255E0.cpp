// build: context MakeLarge
// build: context ExtractLowPart
// build: context ExtractLowPartSx
// build: context D2StormArrayAStrc::RoundUp
// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayAStrc::SetCount
// build: context D2StormArrayAStrc::GrowToFit
// build: context D2StormArrayAStrc::CalcChunkSizeInline
// build: context D2StormArrayAStrc::GrowToFitInline
// build: context BigBuffer::Count
// build: context BigBuffer::IsUsed
// build: context BigBuffer::operator[]
// build: context BigBuffer::SetCount
// build: context BigBuffer::CopyFrom
// build: context BigBuffer::operator=
// build: context BigBuffer::Ref
// build: context BigBuffer::At
// build: context BigBuffer::SetStart

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

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
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormQueueRangeStrc
{
    unsigned int nCount;
    unsigned int nStart;
};

struct BigBuffer
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
    BigBuffer& operator=(const BigBuffer& tSource)
    {
        if (this != &tSource)
        {
            const unsigned int* const pData = *(const unsigned int* const volatile*)&tSource.m_array.f_8;
            const unsigned int nCount = *(const volatile unsigned int*)&tSource.m_array.f_4;
            m_array.sub_004215C0_Set(nCount, pData);
        }
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
        return *this;
    }
    void CopyFrom(const BigBuffer& tSource)
    {
        if (this != &tSource)
            m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
    }
    unsigned int& Ref(int nIndex)
    {
        GrowToFit(nIndex);
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
            GrowToFit(-1);
    }
    void GrowToFit(int nIndex);                                                                // 0x00421FE0
    void sub_004220D0_SetCount(unsigned int nCount);                                                        // 0x004220D0
    void sub_00422140_Trim();                                                                               // 0x00422140
};

struct BigStack
{
    BigBuffer f_0[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
};

unsigned int __stdcall sub_004213B0_FindLastSetBit(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0
void __stdcall sub_00424B00_BigSquare(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack); // 0x00424B00
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue);                            // 0x00421470
extern const unsigned int gaSBigFermatBases[1];                                                         // 0x006CFF70
extern const unsigned int gaSBigSmallPrimes[171];                                                        // 0x006CFF78

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

// 0x004225C0
static void __stdcall sub_004225C0_DivUInt(unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c, BigBuffer& a)
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

// 0x00422780
static int IsZero(BigBuffer& a)
{
    a.sub_00422140_Trim();
    return a.Count() == 0;
}

// 0x004227A0
static void __stdcall sub_004227A0_MulUInt(BigBuffer& a, const BigBuffer& b, unsigned __int64 c)
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

// 0x00422C60
static void SetOne(BigBuffer& a)
{
    a.SetCount(1);
    a.GrowToFit(0);
    a.m_array.f_8[a.m_start] = 1;
}

// 0x00422CC0
static void SetZero(BigBuffer& a)
{
    a.SetCount(0);
}

// 0x00422D00
static void __stdcall Shl(BigBuffer& a, const BigBuffer& b, unsigned int nShift)
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
static void __stdcall Shr(BigBuffer& a, const BigBuffer& b, unsigned int nShift)
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

// 0x00423DC0
static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
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
        const BigBuffer& tD = d;
        sub_004225C0_DivUInt(&b.Ref(0), c, tD[0], a);
        b.sub_004220D0_SetCount(1);
        return;
    }
    BigBuffer& tRem = tStack.f_0[tStack.nUsed++];
    BigBuffer& tDiv = tStack.f_0[tStack.nUsed++];
    BigBuffer& tProduct = tStack.f_0[tStack.nUsed++];
    unsigned int nShift = 31 - (sub_004213B0_FindLastSetBit(&d) & 31);
    Shl(tRem, c, nShift);
    Shl(tDiv, d, nShift);
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

// 0x004221F0
static void __stdcall sub_004221F0_AddUInt(BigBuffer& a, const BigBuffer& b, unsigned int c)
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

// 0x00422750
static __declspec(noinline) int IsOne(BigBuffer& a)
{
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
}

// 0x00422B00
static void __stdcall Set2Exp(BigBuffer& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
}

// 0x00422FC0
static void __stdcall sub_00422FC0_SubUInt(const BigBuffer* pSrc, BigBuffer* pDst, unsigned int nValue)
{
    unsigned __int64 nAcc = ~(unsigned __int64)nValue + 1;
    unsigned int nIndex = 0;
    unsigned int nCount;
    while (nCount = pSrc->m_array.f_4, pSrc->m_start + nIndex < nCount)
    {
        unsigned int nSrcIdx = pSrc->m_start + nIndex;
        unsigned int nElem = nSrcIdx < nCount ? pSrc->m_array.f_8[nSrcIdx] : 0;
        nAcc += nElem;
        unsigned int nLow = (unsigned int)nAcc;
        unsigned int nHigh = (unsigned int)(nAcc >> 32);
        nAcc = nHigh;
        if (nAcc >= 0x80000000ull)
            nAcc |= 0xFFFFFFFF00000000ull;

        unsigned int nDstIdx = pDst->m_start + nIndex;
        if (nDstIdx >= pDst->m_array.f_4)
        {
            unsigned int nNewCount = nDstIdx + 1;
            if (nNewCount > pDst->m_array.f_0)
            {
                unsigned int nChunk = pDst->m_array.f_C;
                if (!nChunk)
                    nChunk = pDst->m_array.sub_004210A0_CalcChunkSize(nNewCount);
                unsigned int nAlloc = nNewCount;
                unsigned int nRem = nNewCount % nChunk;
                if (nRem)
                    nAlloc = nNewCount + (nChunk - nRem);
                pDst->m_array.sub_004216E0_ReallocData(nAlloc);
            }
            SMemZero(&pDst->m_array.f_8[pDst->m_array.f_4], (nDstIdx - pDst->m_array.f_4) * 4 + 4);
            pDst->m_array.f_4 = nNewCount;
        }
        pDst->m_array.f_8[pDst->m_start + nIndex] = nLow;
        nIndex++;
    }
    unsigned int nEnd = pDst->m_start + nIndex;
    if (nEnd > pDst->m_array.f_4 && nEnd > pDst->m_array.f_0)
    {
        unsigned int nChunk = pDst->m_array.f_C;
        if (!nChunk)
            nChunk = pDst->m_array.sub_004210A0_CalcChunkSize(nEnd);
        unsigned int nAlloc = nEnd;
        unsigned int nRem = nEnd % nChunk;
        if (nRem)
            nAlloc = nEnd + (nChunk - nRem);
        pDst->m_array.sub_004216E0_ReallocData(nAlloc);
    }
    pDst->m_array.f_4 = nEnd;
}

// 0x00423540
static void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

// 0x00424180
static void __stdcall Gcd(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack)
{
    BigBuffer& tRem = tStack.f_0[tStack.nUsed++];
    BigBuffer& tNext = tStack.f_0[tStack.nUsed++];
    if (sub_004212F0_Compare(&b, &c) > 0)
    {
        a = b;
        tNext = c;
    }
    else
    {
        a = c;
        tNext = b;
    }
    while (!IsZero(tNext))
    {
        Div(a, tRem, a, tNext, tStack);
        a = tNext;
        tNext = tRem;
    }
    tStack.nUsed -= 2;
}

// 0x004245F0
static __declspec(noinline) void __stdcall sub_004245F0_MulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    BigBuffer& tProduct = tStack.f_0[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

// 0x00425150
static void __stdcall PowMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    if (!c.Count())
    {
        SetOne(a);
        return;
    }
    BigBuffer& tQuot = tStack.f_0[tStack.nUsed++];
    BigBuffer& tSquare = tStack.f_0[tStack.nUsed++];
    BigBuffer& tCube = tStack.f_0[tStack.nUsed++];
    BigBuffer& tWork = (&a == &b || &a == &c || &a == &d) ? tStack.f_0[tStack.nUsed++] : a;
    sub_004245F0_MulMod(tSquare, b, b, d, tStack);
    sub_004245F0_MulMod(tCube, tSquare, b, d, tStack);
    BigBuffer* aPowers[3] = { &b, &tSquare, &tCube };
    SetOne(tWork);
    const BigBuffer& tExp = c;
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
            sub_00424B00_BigSquare(&tWork, &tWork, &tStack);
            Div(tQuot, tWork, tWork, d, tStack);
            sub_00424B00_BigSquare(&tWork, &tWork, &tStack);
            Div(tQuot, tWork, tWork, d, tStack);
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

// 0x00425350
static int __stdcall IsPrime(BigStack* pStack, BigBuffer& a)
{
    BigBuffer& tMinusOne = pStack->f_0[pStack->nUsed++];
    BigBuffer& tOdd = pStack->f_0[pStack->nUsed++];
    BigBuffer& tWork = pStack->f_0[pStack->nUsed++];
    BigBuffer& tBase = pStack->f_0[pStack->nUsed++];
    int bPrime = 1;
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    if (IsZero(a))
        bPrime = 0;
    else
    {
        D2StormQueueRangeStrc tRange;
        tRange.nCount = tRead.m_array.f_4;
        tRange.nStart = tRead.m_start;
        if (!((tRange.nStart < tRange.nCount ? tRead.m_array.f_8[tRange.nStart] : 0) & 1))
            bPrime = 0;
    }
    for (unsigned int i = 0; bPrime && i < 171; i++)
    {
        unsigned __int64 nPrime = gaSBigSmallPrimes[i];
        if (nPrime < 0x100000000ui64)
        {
            unsigned int nRemainder;
            sub_004225C0_DivUInt(&nRemainder, a, nPrime, tWork);
            if (!nRemainder && !IsOne(tWork))
                bPrime = 0;
        }
        else
        {
            FromUnsigned(tBase, (unsigned int)nPrime);
            Div(tWork, tOdd, a, tBase, *pStack);
            if (IsZero(tOdd) && !IsOne(tWork))
                bPrime = 0;
        }
    }
    sub_00422FC0_SubUInt(&a, &tMinusOne, 1);
    tOdd.CopyFrom(tMinusOne);
    unsigned int nShift = sub_00421470_FindLowestSetBit(&tOdd);
    if (nShift)
        Shr(tOdd, tOdd, nShift);
    for (unsigned int i = 0; bPrime && i < 6; i++)
    {
        FromUnsigned(tBase, gaSBigSmallPrimes[i]);
        if (sub_004212F0_Compare(&tBase, &a) >= 0)
            break;
        PowMod(tWork, tBase, tOdd, a, *pStack);
        if (!IsOne(tWork))
        {
            unsigned int j = 0;
            while (sub_004212F0_Compare(&tWork, &tMinusOne))
            {
                if (++j == nShift)
                {
                    bPrime = 0;
                    break;
                }
                sub_004245F0_MulMod(tWork, tWork, tWork, a, *pStack);
                if (IsOne(tWork))
                {
                    bPrime = 0;
                    break;
                }
            }
        }
    }
    for (unsigned int i = 0; bPrime && i < 1; i++)
    {
        FromUnsigned(tBase, gaSBigFermatBases[i]);
        PowMod(tWork, tBase, a, a, *pStack);
        if (sub_004212F0_Compare(&tWork, &tBase))
            bPrime = 0;
    }
    pStack->nUsed -= 4;
    return bPrime;
}

// 0x00421440
static __declspec(noinline) int sub_00421440_IsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

static void __stdcall FindPrime(unsigned int nBits, BigBuffer& b, BigBuffer& c, BigStack* pStack, BigBuffer& a); // 0x004255E0
// 0x004255E0
static void __stdcall FindPrime(unsigned int nBits, BigBuffer& b, BigBuffer& c, BigStack* pStack, BigBuffer& a)
{
    BigBuffer& tLow = pStack->f_0[pStack->nUsed++];
    BigBuffer& tHigh = pStack->f_0[pStack->nUsed++];
    BigBuffer& tWork = pStack->f_0[pStack->nUsed++];
    Set2Exp(tLow, nBits - 2);
    Set2Exp(tHigh, nBits - 1);
    sub_00422300_Add(tHigh, tHigh, tLow);
    Div(tWork, a, b, tLow, *pStack);
    sub_00422300_Add(a, a, tHigh);
    if (sub_00421440_IsEven(a))
        sub_004221F0_AddUInt(a, a, 1);
    sub_00422300_Add(tHigh, tHigh, tLow);
    sub_00422FC0_SubUInt(&tHigh, &tHigh, 2);
    for (;;)
    {
        if (IsPrime(pStack, a))
        {
            if (IsOne(c))
                break;
            sub_00422FC0_SubUInt(&a, &tWork, 1);
            Gcd(tWork, tWork, c, *pStack);
            if (IsOne(tWork))
                break;
        }
        sub_004221F0_AddUInt(a, a, 2);
        if (sub_004212F0_Compare(&a, &tHigh) > 0)
            sub_00423100_Sub(a, a, tLow);
    }
    pStack->nUsed -= 3;
}

// 0x00425330
void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus)
{
    PowMod(pResult->tPrimary, pBase->tPrimary, pExponent->tPrimary, pModulus->tPrimary, pResult->tStack);
}

// 0x004255C0
int __stdcall SBigIsPrime(D2StormBigStrc* pBig)
{
    return IsPrime(&pBig->tStack, pBig->tPrimary);
}

// 0x00425700
void __stdcall SBigFindPrime(D2StormBigStrc* pResult, unsigned int nBits, D2StormBigStrc* pRandom, D2StormBigStrc* pExponent)
{
    FindPrime(nBits, pRandom->tPrimary, pExponent->tPrimary, &pResult->tStack, pResult->tPrimary);
}

// 0x00424FB0
static void __stdcall InvMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack)
{
    BigBuffer& tPrev = tStack.f_0[tStack.nUsed++];
    BigBuffer& tNum = tStack.f_0[tStack.nUsed++];
    BigBuffer& tDen = tStack.f_0[tStack.nUsed++];
    BigBuffer& tQuot = tStack.f_0[tStack.nUsed++];
    BigBuffer& tRem = tStack.f_0[tStack.nUsed++];
    tNum.CopyFrom(b);
    tDen.CopyFrom(c);
    SetOne(a);
    SetZero(tPrev);
    int nSign = 1;
    while (!IsZero(tDen))
    {
        Div(tQuot, tRem, tNum, tDen, tStack);
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

// 0x00425310
void __stdcall SBigInvMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    InvMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}
