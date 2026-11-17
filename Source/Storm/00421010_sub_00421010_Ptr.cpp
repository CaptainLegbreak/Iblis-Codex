int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern char gszTypeNameUInt_00708874[];                                                                     // 0x00708874
extern char gszTypeNameUChar_00708880[];                                                                    // 0x00708880

struct D2StormByteArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    char* sub_00421010_Ptr();
};

struct D2StormFixedArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    unsigned int* sub_00421150_Ptr();
};

struct D2StormFixedArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    unsigned char* sub_004215B0_Ptr();
};

struct D2StormFixedUIntArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    ~D2StormFixedUIntArrayStrc();
};

struct D2StormFixedUCharArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    ~D2StormFixedUCharArrayStrc();
};

struct D2StormGrowUIntArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    ~D2StormGrowUIntArrayStrc();
};

struct D2StormGrowUCharArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    ~D2StormGrowUCharArrayStrc();
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
    unsigned char* sub_00421930_New();
};

struct D2StormQueueArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
};

struct D2StormQueueStrc
{
    D2StormQueueArrayStrc m_array;
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
};

struct D2StormBigStrc
{
    D2StormQueueStrc tPrimary;
};

// 0x00421010
char* D2StormByteArrayStrc::sub_00421010_Ptr()
{
    return f_8;
}

// 0x00421040
void __cdecl sub_00421040_Empty()
{
}

// 0x00421050
void __fastcall sub_00421050_Construct(unsigned char* pDest, const unsigned char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421060
void __cdecl sub_00421060_Empty()
{
}

// 0x00421070
void __cdecl sub_00421070_Empty()
{
}

// 0x00421080
void __cdecl sub_00421080_Empty()
{
}

// 0x00421090
void __fastcall sub_00421090_Construct(char* pDest, const char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421150
unsigned int* D2StormFixedArrayAStrc::sub_00421150_Ptr()
{
    return f_8;
}

// 0x004212A0
void __fastcall sub_004212A0_Construct(unsigned int* pDest, const unsigned int* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x004212B0
void __cdecl sub_004212B0_Empty()
{
}

static __declspec(noinline) int sub_00421440_IsEven(const D2StormQueueStrc& a)
{
    return !a.Count() || !(a[0] & 1);
}

// 0x00421540
int __stdcall SBigIsEven(D2StormBigStrc* pBig)
{
    return sub_00421440_IsEven(pBig->tPrimary);
}

// 0x00421570
D2StormFixedUIntArrayStrc::~D2StormFixedUIntArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421590
D2StormFixedUCharArrayStrc::~D2StormFixedUCharArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUChar_00708880, -2, 0);
}

// 0x004215B0
unsigned char* D2StormFixedArrayBStrc::sub_004215B0_Ptr()
{
    return f_8;
}

// 0x004217F0
D2StormGrowUIntArrayStrc::~D2StormGrowUIntArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421840
D2StormGrowUCharArrayStrc::~D2StormGrowUCharArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUChar_00708880, -2, 0);
}

// 0x00421930
unsigned char* D2StormArrayBStrc::sub_00421930_New()
{
    unsigned int nCount = f_4 + 1;
    if (nCount > f_0)
    {
        unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
        sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
    }
    return &f_8[f_4++];
}
