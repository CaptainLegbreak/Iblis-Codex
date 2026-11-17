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

    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);                                           // 0x0051D2F0
    void sub_0051D5D0_ReallocData(unsigned int nCount);                                                     // 0x0051D5D0
    void sub_0051D810_SetCount(unsigned int nCount);
};

// 0x0051D810
void D2StormArray408Strc::sub_0051D810_SetCount(unsigned int nCount)
{
    if (nCount > f_4 && nCount > f_0)
    {
        unsigned int nChunk = f_C;
        if (!nChunk)
            nChunk = sub_0051D2F0_CalcChunkSize(nCount);
        unsigned int nAlloc = nCount;
        const unsigned int nRemainder = nCount % nChunk;
        if (nRemainder)
            nAlloc = nCount + nChunk - nRemainder;
        sub_0051D5D0_ReallocData(nAlloc);
    }
    f_4 = nCount;
}
