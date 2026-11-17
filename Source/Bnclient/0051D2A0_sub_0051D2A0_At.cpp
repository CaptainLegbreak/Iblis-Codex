struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    D2Storm408ElemStrc* sub_0051D2A0_At(unsigned int nIndex);
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);                                           // 0x0051D2F0
    void sub_0051D5D0_ReallocData(unsigned int nCount);                                                     // 0x0051D5D0
    void sub_0051D6D0_Reserve(unsigned int nCount, int bRound);
    void sub_0051D7F0_Grow(unsigned int nCount);
};

inline unsigned int RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0051D2A0
D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D2A0_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0051D330
unsigned int __stdcall sub_0051D330_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0051D6D0
void D2StormArray408Strc::sub_0051D6D0_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

// 0x0051D7F0
void D2StormArray408Strc::sub_0051D7F0_Grow(unsigned int nCount)
{
    const unsigned int nNewCount = f_4 + nCount;
    if (nNewCount > f_0)
        sub_0051D5D0_ReallocData(nNewCount);
}
