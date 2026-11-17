void __stdcall SMemZero(void* pLocation, unsigned int nLength);                                             // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero);
    void sub_00421F10_SetCount(unsigned int nCount);
};

struct D2StormArray2Strc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00450810_CalcChunkSize(unsigned int nCount);                                           // 0x00450810
    void sub_00450D90_ReallocData(unsigned int nAlloc);                                                     // 0x00450D90
    void sub_00450E70_Reserve(unsigned int nCount, int bRound);
    void sub_00450F50_ReserveExact(unsigned int nCount);
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    unsigned int* sub_00422050_At(unsigned int nIndex);
    void sub_00422120_SetStart(unsigned int nStart);
    D2StormQueueStrc& operator=(const D2StormQueueStrc& tSource);
};

// build: symbol ??4D2StormQueueStrc@@QAEAAU0@ABU0@@Z 0x004221B0
// 0x00421EA0
void D2StormArrayAStrc::sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero)
{
    if (nIndex >= f_4)
    {
        unsigned int nCount = nIndex + 1;
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        if (bZero)
            SMemZero(&f_8[f_4], (nIndex - f_4 + 1) * sizeof(unsigned int));
        f_4 = nCount;
    }
}

// 0x00421F10
void D2StormArrayAStrc::sub_00421F10_SetCount(unsigned int nCount)
{
    if (nCount > f_4 && nCount > f_0)
    {
        unsigned int nChunk = f_C;
        if (!nChunk)
            nChunk = sub_004210A0_CalcChunkSize(nCount);
        unsigned int nAlloc = nCount;
        const unsigned int nRemainder = nCount % nChunk;
        if (nRemainder)
            nAlloc = nCount + nChunk - nRemainder;
        sub_004216E0_ReallocData(nAlloc);
    }
    f_4 = nCount;
}

// 0x00422050
unsigned int* D2StormQueueStrc::sub_00422050_At(unsigned int nIndex)
{
    sub_00421FE0_GrowToFit(nIndex);
    return &m_array.f_8[m_start + nIndex];
}

// 0x00422120
void D2StormQueueStrc::sub_00422120_SetStart(unsigned int nStart)
{
    m_start = nStart;
    if (nStart)
        sub_00421FE0_GrowToFit(-1);
}

// 0x004221B0
D2StormQueueStrc& D2StormQueueStrc::operator=(const D2StormQueueStrc& tSource)
{
    if (this != &tSource)
        m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
    m_array.f_C = tSource.m_array.f_C;
    m_start = tSource.m_start;
    return *this;
}

// 0x00450E70
void D2StormArray2Strc::sub_00450E70_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00450810_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_00450D90_ReallocData(nCount);
    }
}

// 0x00450F50
void D2StormArray2Strc::sub_00450F50_ReserveExact(unsigned int nCount)
{
    const unsigned int nNewCount = f_4 + nCount;
    if (nNewCount > f_0)
        sub_00450D90_ReallocData(nNewCount);
}
