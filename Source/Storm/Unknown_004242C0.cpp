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
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nCount);
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
    unsigned int Count() const
    {
        return f_4.n;
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
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormArrayViewStrc
{
    const unsigned int* pData;
    unsigned int nCount;
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_00420DB0_InRange(unsigned int nIndex) const;
    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.f_4;
        return nIndex + m_start < tCount.n;
    }                                                    // 0x00420DB0
    unsigned int operator[](unsigned int nIndex) const
    {
        return sub_00420DB0_InRange(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
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
            m_array.sub_004215C0_Set(tSource.m_array.f_4.n, tSource.m_array.f_8);
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
    }
    unsigned int sub_004212D0_Get(unsigned int nIndex) const;                                               // 0x004212D0
};

struct D2StormBigStackStrc
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;

    D2StormQueueStrc& Alloc()
    {
        return f_0[nUsed++];
    }
    void Free()
    {
        nUsed--;
    }
    D2StormQueueStrc& MakeDistinct(D2StormQueueStrc& tOrig, int bRequired)
    {
        return bRequired ? Alloc() : tOrig;
    }
    void UnmakeDistinct(D2StormQueueStrc& tOrig, D2StormQueueStrc& tDistinct)
    {
        if (&tOrig != &tDistinct)
        {
            tOrig.CopyFrom(tDistinct);
            Free();
        }
    }
};

// 0x004210A0
unsigned int D2StormArrayAStrc::sub_004210A0_CalcChunkSize(unsigned int nCount)
{
    unsigned int nResult = nCount;
    if (nCount < 0x40)
    {
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x40;
    return 0x40;
}

// 0x00420DB0
int D2StormQueueStrc::sub_00420DB0_InRange(unsigned int nIndex) const
{
    return m_start + nIndex < m_array.f_4.n;
}

// 0x004212D0
__declspec(noinline) unsigned int D2StormQueueStrc::sub_004212D0_Get(unsigned int nIndex) const
{
    return sub_00420DB0_InRange(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
}

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

// 0x004242C0
void __stdcall sub_004242C0_BigOp(D2StormQueueStrc* pResult, const D2StormQueueStrc* pB, const D2StormQueueStrc* pC, D2StormBigStackStrc* pStack)
{
    D2StormQueueStrc& a = *pResult;
    const D2StormQueueStrc& b = *pB;
    const D2StormQueueStrc& c = *pC;
    D2StormQueueStrc& aa = pStack->MakeDistinct(a, &a == &b || &a == &c);

    aa.SetCount(0);

    int i = 0;
    for (; b.IsUsed(i); i++)
    {
        unsigned __int64 nData = 0;
        int j = 0;
        for (; c.IsUsed(j); j++)
        {
            nData += (unsigned __int64)b.sub_004212D0_Get(i) * c[j] + aa[i + j];
            aa[i + j] = ExtractLowPart(nData);
        }
        aa[i + j] = ExtractLowPart(nData);
    }

    if (&a != &aa)
    {
        D2StormArrayViewStrc tView;
        tView.pData = aa.m_array.f_8;
        tView.nCount = aa.m_array.f_4.n;
        a.m_array.sub_004215C0_Set(tView.nCount, tView.pData);
        a.m_array.f_C = aa.m_array.f_C;
        a.m_start = aa.m_start;
        pStack->nUsed--;
    }
}

// build: context ?RoundUp@D2StormArrayAStrc@@SGIII@Z
// build: context ?Alloc@D2StormBigStackStrc@@QAEAAUD2StormQueueStrc@@XZ
// build: context ?MakeDistinct@D2StormBigStackStrc@@QAEAAUD2StormQueueStrc@@AAU2@H@Z
// build: context ?ExtractLowPart@@YAIAA_K@Z
// build: context ?Reserve@D2StormArrayAStrc@@QAEXIH@Z
// build: context ?SetCount@D2StormArrayAStrc@@QAEXI@Z
// build: context ?GrowToFit@D2StormArrayAStrc@@QAEXIH@Z
// build: context ??AD2StormQueueStrc@@QBEII@Z
// build: context ??AD2StormQueueStrc@@QAEAAII@Z
// build: context ?SetCount@D2StormQueueStrc@@QAEXI@Z
