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

// 0x004221F0
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

// 0x00422570
static int __stdcall sub_00422570_CompareUInt(D2StormQueueStrc& a, unsigned int b)
{
    a.sub_00422140_Trim();
    if (a.Count() > 1)
        return 1;
    const D2StormQueueStrc& tRead = a;
    unsigned int nDigit = tRead[0];
    if (nDigit)
        return nDigit > b ? 1 : -1;
    return 0;
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

// 0x00422750
static int IsOne(D2StormQueueStrc& a)
{
    a.sub_00422140_Trim();
    const D2StormQueueStrc& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
}

// 0x00422780
static int IsZero(D2StormQueueStrc& a)
{
    a.sub_00422140_Trim();
    return a.Count() == 0;
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

// 0x00422B00
static void __stdcall Set2Exp(D2StormQueueStrc& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
}

// 0x00422C60
static void SetOne(D2StormQueueStrc& a)
{
    a.SetCount(1);
    a.sub_00421FE0_GrowToFit(0);
    a.m_array.f_8[a.m_start] = 1;
}

// 0x00422CC0
static void SetZero(D2StormQueueStrc& a)
{
    a.SetCount(0);
}

void __stdcall sub_00422D00_Shl(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int nShift); // 0x00422D00

// 0x00422E70
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

void __stdcall sub_00422FC0_SubUInt(D2StormQueueStrc& a, const D2StormQueueStrc& b, unsigned int c); // 0x00422FC0

void __stdcall sub_00423100_Sub(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c); // 0x00423100

// 0x004234B0
static void FromStr(D2StormQueueStrc& a, const char* szString)
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
static void __stdcall FromUnsigned(D2StormQueueStrc& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

// build: context sub_00423600_ToStr
static void __stdcall sub_00423600_ToStr(const D2StormQueueStrc& tNumber, D2StormArrayBStrc& tOutput, D2StormBigStackStrc& tStack)
{
    D2StormQueueStrc& tBuffer = tStack.f_0[tStack.nUsed++];
    tBuffer.CopyFrom(tNumber);
    tOutput.f_4 = 0;
    do
    {
        unsigned int nDigit;
        sub_004225C0_DivUInt(&nDigit, tBuffer, 10, tBuffer);
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
    sub_00422D00_Shl(pResult->tPrimary, pA->tPrimary, nShift);
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
    sub_00423600_ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    if (bAppend)
        pArray->sub_00421F60_Add(pBig->tOutput.f_4, (const char*)pBig->tOutput.f_8);
    else
        pArray->sub_00421A50_Set(pBig->tOutput.f_4, (const char*)pBig->tOutput.f_8);
}

// 0x00423C20
void __stdcall SBigToStrBuffer(D2StormBigStrc* pBig, char* szBuffer, unsigned int nSize)
{
    sub_00423600_ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    SStrCopy(szBuffer, (const char*)pBig->tOutput.f_8, nSize);
}

// 0x00423C60
void __stdcall SBigToStrPtr(D2StormBigStrc* pBig, const char** pszString)
{
    sub_00423600_ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    *pszString = (const char*)pBig->tOutput.f_8;
}

void __stdcall sub_00423DC0_Div(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, D2StormBigStackStrc& tStack); // 0x00423DC0

void __stdcall sub_00424180_Gcd(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormBigStackStrc& tStack); // 0x00424180

// 0x004245F0
static void __stdcall sub_004245F0_MulMod(D2StormQueueStrc& a, D2StormQueueStrc& b, D2StormQueueStrc& c, D2StormQueueStrc& d, D2StormBigStackStrc& tStack)
{
    D2StormQueueStrc& tProduct = tStack.f_0[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    sub_00423DC0_Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    D2StormBigStackStrc& tStack = pResult->tStack;
    D2StormQueueStrc& tRem = tStack.f_0[tStack.nUsed++];
    sub_00423DC0_Div(pResult->tPrimary, tRem, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424EB0
void __stdcall SBigGcd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00424180_Gcd(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}

// 0x00424ED0
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    D2StormBigStackStrc& tStack = pResult->tStack;
    D2StormQueueStrc& tQuotient = tStack.f_0[tStack.nUsed++];
    sub_00423DC0_Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424F30
void __stdcall SBigMulMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormBigStrc* pC)
{
    sub_004245F0_MulMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pC->tPrimary, pResult->tStack);
}
