void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

extern char gszTypeNameUInt_00708874[];                                                                     // 0x00708874
extern char gszTypeNameUChar_00708880[];                                                                    // 0x00708880
extern char gszTypeNameChar_0070888C[];                                                                     // 0x0070888C

struct D2StormFixedArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_00421110_ReallocData(unsigned int nAlloc);
    D2StormFixedArrayAStrc& sub_00421870_Assign(const D2StormFixedArrayAStrc& tSource);
};

struct D2StormArrayAStrc : D2StormFixedArrayAStrc
{
    unsigned int f_C;

    D2StormArrayAStrc& sub_00421BA0_Assign(const D2StormArrayAStrc& tSource);
};

struct D2StormFixedArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    void sub_00421680_ReallocData(unsigned int nAlloc);
};

struct D2StormFixedArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;

    void sub_004216B0_ReallocData(unsigned int nAlloc);
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
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    void sub_00421980_SetCount(unsigned int nCount);
};

// 0x00421110
void D2StormFixedArrayAStrc::sub_00421110_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (unsigned int*)SMemReAlloc(f_8, nAlloc * sizeof(unsigned int), gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421680
void D2StormFixedArrayBStrc::sub_00421680_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (unsigned char*)SMemReAlloc(f_8, nAlloc, gszTypeNameUChar_00708880, -2, 0);
}

// 0x004216B0
void D2StormFixedArrayCStrc::sub_004216B0_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (char*)SMemReAlloc(f_8, nAlloc, gszTypeNameChar_0070888C, -2, 0);
}

// 0x00421870
D2StormFixedArrayAStrc& D2StormFixedArrayAStrc::sub_00421870_Assign(const D2StormFixedArrayAStrc& tSource)
{
    if (this != &tSource)
        sub_004215C0_Set(tSource.f_4, tSource.f_8);
    return *this;
}

// 0x00421980
void D2StormArrayBStrc::sub_00421980_SetCount(unsigned int nCount)
{
    if (nCount > f_4 && nCount > f_0)
    {
        unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
        sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
    }
    f_4 = nCount;
}

// 0x00421BA0
D2StormArrayAStrc& D2StormArrayAStrc::sub_00421BA0_Assign(const D2StormArrayAStrc& tSource)
{
    if (this != &tSource)
        sub_004215C0_Set(tSource.f_4, tSource.f_8);
    f_C = tSource.f_C;
    return *this;
}
