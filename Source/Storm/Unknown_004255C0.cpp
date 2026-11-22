inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);

#include "D2StormBigBuffer.h"


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

unsigned int __stdcall sub_004213B0_FindLastSetBit(BigBuffer* pQueue);
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack);
int __stdcall sub_00424B00_Square(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack);
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue);
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

static void __stdcall sub_004225C0_DivUInt(BigBuffer& a, unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c)
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

static int IsZero(BigBuffer& a)
{
    a.sub_00422140_Trim();
    return a.Count() == 0;
}

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

static void SetOne(BigBuffer& a)
{
    a.SetCount(1);
    a.GrowToFit(0);
    a.m_array.f_8[a.m_start] = 1;
}

static void SetZero(BigBuffer& a)
{
    a.SetCount(0);
}

static void __stdcall Shl(BigBuffer& a, const BigBuffer& b, unsigned int nShift) // 0x00422D00
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

static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack) // 0x00423DC0
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
        sub_004225C0_DivUInt(a, &b.Ref(0), c, tD[0]);
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

static int IsOne(BigBuffer& a)
{
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
}

static void __stdcall Set2Exp(BigBuffer& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
}

static void __stdcall sub_00422FC0_SubUInt(BigBuffer& a, const BigBuffer& b, unsigned int c)
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

static void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

static void __stdcall Gcd(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack) // 0x00424180
{
    BigBuffer& tRem = tStack.f_0[tStack.nUsed++];
    BigBuffer& tNext = tStack.f_0[tStack.nUsed++];
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
        Div(a, tRem, a, tNext, tStack);
        a.CopyFrom(tNext);
        tNext.CopyFrom(tRem);
    }
    tStack.nUsed -= 2;
}

static __declspec(noinline) void __stdcall sub_004245F0_MulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    BigBuffer& tProduct = tStack.f_0[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

static void __stdcall PowMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack) // 0x00425150
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
            sub_00424B00_Square(&tWork, &tWork, &tStack);
            Div(tQuot, tWork, tWork, d, tStack);
            sub_00424B00_Square(&tWork, &tWork, &tStack);
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

static int __stdcall IsPrime(BigStack* pStack, BigBuffer& a) // 0x00425350
{
    const unsigned int nUsed = pStack->nUsed;
    BigBuffer& tMinusOne = pStack->f_0[nUsed];
    BigBuffer& tOdd = pStack->f_0[nUsed + 1];
    BigBuffer& tWork = pStack->f_0[nUsed + 2];
    BigBuffer& tBase = pStack->f_0[nUsed + 3];
    pStack->nUsed = nUsed + 4;
    int bPrime = 1;
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
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
            Div(tWork, tOdd, a, tBase, *pStack);
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
        PowMod(tWork, tBase, tOdd, a, *pStack);
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
                sub_004245F0_MulMod(tWork, tWork, tWork, a, *pStack);
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
        PowMod(tWork, tBase, a, a, *pStack);
        if (sub_004212F0_Compare(&tWork, &tBase))
            bPrime = 0;
    }
    pStack->nUsed -= 4;
    return bPrime;
}

static int sub_00421440_IsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

static void __stdcall FindPrime(unsigned int nBits, BigBuffer& b, BigBuffer& c, BigStack* pStack, BigBuffer& a) // 0x004255E0
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
    sub_00422FC0_SubUInt(tHigh, tHigh, 2);
    for (;;)
    {
        if (IsPrime(pStack, a))
        {
            if (IsOne(c))
                break;
            sub_00422FC0_SubUInt(tWork, a, 1);
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

void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus)
{
    PowMod(pResult->tPrimary, pBase->tPrimary, pExponent->tPrimary, pModulus->tPrimary, pResult->tStack);
}

// 0x004255C0
int __stdcall SBigIsPrime(D2StormBigStrc* pBig)
{
    return IsPrime(&pBig->tStack, pBig->tPrimary);
}

void __stdcall SBigFindPrime(D2StormBigStrc* pResult, unsigned int nBits, D2StormBigStrc* pRandom, D2StormBigStrc* pExponent)
{
    FindPrime(nBits, pRandom->tPrimary, pExponent->tPrimary, &pResult->tStack, pResult->tPrimary);
}

static void __stdcall InvMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack) // 0x00424FB0
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

void __stdcall SBigInvMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    InvMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}
