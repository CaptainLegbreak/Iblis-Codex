// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayAStrc::SetCount
// build: context D2StormArrayBStrc::Reserve

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

#include "D2StormBigBuffer.h"

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

// build: context New
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


struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
    D2StormArrayBStrc tOutput;
};

unsigned int __stdcall sub_004213B0_FindLastSetBit(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0

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

// 0x00422570
static int __stdcall sub_00422570_CompareUInt(BigBuffer& a, unsigned int b)
{
    a.sub_00422140_Trim();
    if (a.Count() > 1)
        return 1;
    const BigBuffer& tRead = a;
    unsigned int nDigit = tRead[0];
    if (nDigit)
        return nDigit > b ? 1 : -1;
    return 0;
}

void __stdcall sub_004225C0_DivUInt(BigBuffer& a, unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c); // 0x004225C0

// 0x00422750
static int IsOne(BigBuffer& a)
{
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
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

// 0x00422B00
static void __stdcall Set2Exp(BigBuffer& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
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

// build: context Shl
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

// build: context sub_00422FC0_SubUInt
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

// build: context sub_00423100_Sub
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

// 0x004234B0
static void FromStr(BigBuffer& a, const char* szString)
{
    SetZero(a);
    while (*szString)
    {
        sub_004227A0_MulUInt(a, a, 10);
        sub_004221F0_AddUInt(a, a, *szString - '0');
        szString++;
    }
}

// 0x00423540
static void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

static void __stdcall ToStr(const BigBuffer& tNumber, D2StormArrayBStrc& tOutput, BigStack& tStack) // 0x00423600
{
    BigBuffer& tBuffer = tStack.f_0[tStack.nUsed++];
    tBuffer.CopyFrom(tNumber);
    tOutput.f_4 = 0;
    do
    {
        unsigned int nDigit;
        sub_004225C0_DivUInt(tBuffer, &nDigit, tBuffer, 10);
        unsigned char nChar = (unsigned char)(nDigit + '0');
        tOutput.Add(1, &nChar);
    } while (sub_00422570_CompareUInt(tBuffer, 0));
    unsigned int nCount = tOutput.f_4;
    for (unsigned int i = 0; i < nCount / 2; i++)
    {
        unsigned char nSwap = tOutput.f_8[i];
        tOutput.f_8[i] = tOutput.f_8[nCount - 1 - i];
        tOutput.f_8[nCount - 1 - i] = nSwap;
    }
    *tOutput.New() = 0;
    tStack.nUsed--;
}

// 0x00423800
void __stdcall SBigDec(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    sub_00422FC0_SubUInt(pResult->tPrimary, pA->tPrimary, 1);
}

// 0x00423870
void __stdcall SBigFromStr(D2StormBigStrc* pBig, const char* szString)
{
    FromStr(pBig->tPrimary, szString);
}

// 0x004238B0
void __stdcall SBigFromUnsigned(D2StormBigStrc* pBig, unsigned int nValue)
{
    FromUnsigned(pBig->tPrimary, nValue);
}

// 0x004238D0
void __stdcall SBigInc(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    sub_004221F0_AddUInt(pResult->tPrimary, pA->tPrimary, 1);
}

// 0x00423910
int __stdcall SBigIsOne(D2StormBigStrc* pBig)
{
    return IsOne(pBig->tPrimary);
}

// 0x00423930
int __stdcall SBigIsZero(D2StormBigStrc* pBig)
{
    return IsZero(pBig->tPrimary);
}

// 0x00423A20
void __stdcall SBigSet2Exp(D2StormBigStrc* pBig, unsigned int nExponent)
{
    Set2Exp(pBig->tPrimary, nExponent);
}

// 0x00423A40
void __stdcall SBigSetOne(D2StormBigStrc* pBig)
{
    SetOne(pBig->tPrimary);
}

// 0x00423A60
void __stdcall SBigSetZero(D2StormBigStrc* pBig)
{
    SetZero(pBig->tPrimary);
}

// 0x00423A80
void __stdcall SBigShl(D2StormBigStrc* pResult, D2StormBigStrc* pA, unsigned int nShift)
{
    Shl(pResult->tPrimary, pA->tPrimary, nShift);
}

// 0x00423AA0
void __stdcall SBigShr(D2StormBigStrc* pResult, D2StormBigStrc* pA, unsigned int nShift)
{
    Shr(pResult->tPrimary, pA->tPrimary, nShift);
}

// 0x00423AC0
void __stdcall SBigSub(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423100_Sub(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00423BC0
void __stdcall SBigToStrArray(D2StormBigStrc* pBig, D2StormArrayCStrc* pArray, int bAppend)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    if (bAppend)
        pArray->sub_00421F60_Add(pBig->tOutput.f_4, (const char*)pBig->tOutput.f_8);
    else
        pArray->sub_00421A50_Set(pBig->tOutput.f_4, (const char*)pBig->tOutput.f_8);
}

// 0x00423C20
void __stdcall SBigToStrBuffer(D2StormBigStrc* pBig, char* szBuffer, unsigned int nSize)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    SStrCopy(szBuffer, (const char*)pBig->tOutput.f_8, nSize);
}

// 0x00423C60
void __stdcall SBigToStrPtr(D2StormBigStrc* pBig, const char** pszString)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    *pszString = (const char*)pBig->tOutput.f_8;
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

// build: context Gcd
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

// 0x004245F0
static void __stdcall sub_004245F0_MulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    BigBuffer& tProduct = tStack.f_0[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tRem = tStack.f_0[tStack.nUsed++];
    Div(pResult->tPrimary, tRem, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424EB0
void __stdcall SBigGcd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    Gcd(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}

// 0x00424ED0
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tQuotient = tStack.f_0[tStack.nUsed++];
    Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424F30
void __stdcall SBigMulMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormBigStrc* pC)
{
    sub_004245F0_MulMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pC->tPrimary, pResult->tStack);
}
