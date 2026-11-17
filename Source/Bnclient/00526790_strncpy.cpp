struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);
};

struct D2LangCharRangeStrc
{
    unsigned short wLow;
    unsigned short wHigh;

    void sub_005276A0_SetFromBytes(const unsigned char* pBytes);
};

struct D2LangByteRangeStrc
{
    unsigned char f_0;
    unsigned char f_1;

    int sub_005276C0_Contains(unsigned char nValue) const;
};

struct D2LangCharMapEntryStrc
{
    unsigned short wValue;
    unsigned short f_2;
};

// 0x00526790
Unicode* __fastcall Unicode::strncpy(Unicode* dest, const Unicode* src, int count)
{
    Unicode* current_dest = dest;
    for (; (count--) != 0 && src->wChar != 0; ++current_dest, ++src)
    {
        current_dest->wChar = src->wChar;
    }

    for (; count != -1; ++current_dest, --count)
    {
        current_dest->wChar = 0;
    }

    return dest;
}

// 0x005276A0
void D2LangCharRangeStrc::sub_005276A0_SetFromBytes(const unsigned char* pBytes)
{
    wLow = pBytes[0];
    wHigh = pBytes[2];
}

// 0x005276C0
int D2LangByteRangeStrc::sub_005276C0_Contains(unsigned char nValue) const
{
    if (f_0 <= nValue && nValue <= f_1)
        return 1;
    return 0;
}

// 0x00527AE0
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight)
{
    return ((const D2LangCharMapEntryStrc*)pLeft)->f_2 - ((const D2LangCharMapEntryStrc*)pRight)->f_2;
}
