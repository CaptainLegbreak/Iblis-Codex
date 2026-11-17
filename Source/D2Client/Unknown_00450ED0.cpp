inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2SGameDataStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    char unk0x14[0x1DF4 - 0x14];

    D2SGameDataStrc()
    {
        unk0x04 = 0;
        unk0x08 = 0;
        unk0x0C = 0;
        unk0x10 = 0;
    }
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
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
    void Reserve(unsigned int nCount, int bRound)
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
    D2SGameDataStrc* sub_00450ED0_New();
};

// 0x00450ED0
D2SGameDataStrc* D2StormGameDataArrayStrc::sub_00450ED0_New()
{
    Reserve(1, 1);
    new (&f_8[f_4]) D2SGameDataStrc;
    return &f_8[f_4++];
}
