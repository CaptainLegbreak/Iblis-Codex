inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

#include "D2StormBigBuffer.h"
#include "D2StormArrayC.h"

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

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
        m_chunk = 0x100;
        return 0x100;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            if (bRound)
            {
                unsigned int nChunk = m_chunk ? m_chunk : CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004211C0_ReallocData(nCount);
        }
    }
    void Add(unsigned int nCount, const unsigned char* pData)
    {
        Reserve(nCount, 1);
        for (unsigned int i = 0; i < nCount; i++, pData++)
            new (&m_data[m_count + i]) unsigned char(*pData);
        m_count += nCount;
    }
    unsigned char* New()
    {
        Reserve(1, 1);
        return &m_data[m_count++];
    }
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
};



struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
    D2StormArrayBStrc tOutput;
};

unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0

void __stdcall BigAddUInt(BigBuffer& a, const BigBuffer& b, unsigned int c); // 0x004221F0

int IsOne(BigBuffer& a); // 0x00422750
int IsZero(BigBuffer& a); // 0x00422780

void __stdcall BigMulUInt(BigBuffer& a, const BigBuffer& b, unsigned __int64 c); // 0x004227A0
void __stdcall Set2Exp(BigBuffer& a, unsigned int nExponent); // 0x00422B00

void SetOne(BigBuffer& a); // 0x00422C60
void SetZero(BigBuffer& a); // 0x00422CC0

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
            nValue = b[i - nWords] << nBits;
        if (i > nWords && nBits)
            nValue += b[i - nWords - 1] >> (32 - nBits);
        a[i] = nValue;
    }
    a.SetCount(nCount);
    a.sub_00422140_Trim();
}

void __stdcall Shr(BigBuffer& a, const BigBuffer& b, unsigned int nShift); // 0x00422E70
void __stdcall sub_00422FC0_SubUInt(BigBuffer& a, const BigBuffer& b, unsigned int c); // 0x00422FC0

void __stdcall sub_00423100_Sub(BigBuffer& a, const BigBuffer& b, const BigBuffer& c); // 0x00423100

void FromStr(BigBuffer& a, const char* szString); // 0x004234B0
void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue); // 0x00423540

void __stdcall ToStr(const BigBuffer& tNumber, D2StormArrayBStrc& tOutput, BigStack& tStack); // 0x00423600

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
    BigAddUInt(pResult->tPrimary, pA->tPrimary, 1);
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
        pArray->sub_00421F60_Add(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
    else
        pArray->sub_00421A50_Set(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
}

// 0x00423C20
void __stdcall SBigToStrBuffer(D2StormBigStrc* pBig, char* szBuffer, unsigned int nSize)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    SStrCopy(szBuffer, (const char*)pBig->tOutput.m_data, nSize);
}

// 0x00423C60
void __stdcall SBigToStrPtr(D2StormBigStrc* pBig, const char** pszString)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    *pszString = (const char*)pBig->tOutput.m_data;
}

void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack); // 0x00423DC0

void __stdcall Gcd(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack); // 0x00424180

void __stdcall BigMulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack); // 0x004245F0
// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
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
    BigBuffer& tQuotient = tStack.pRecords[tStack.nUsed++];
    Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424F30
void __stdcall SBigMulMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormBigStrc* pC)
{
    BigMulMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pC->tPrimary, pResult->tStack);
}
