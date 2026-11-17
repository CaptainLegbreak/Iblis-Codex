struct Unicode
{
    unsigned short wChar;

    operator unsigned short() const
    {
        return wChar;
    }
};

struct D2LangByteRangeStrc
{
    unsigned char f_0;
    unsigned char f_1;
};

struct D2LangCharMapEntryStrc
{
    unsigned short wValue;
    unsigned short f_2;
};

extern unsigned short gnCharMapCount_00882B20;                                                              // 0x00882B20
extern unsigned char gnLeadByteRangeCount_00882B22;                                                         // 0x00882B22
extern D2LangCharMapEntryStrc* gpCharMap_00882B24;                                                          // 0x00882B24
extern D2LangByteRangeStrc* gpLeadByteRanges_00882B28;                                                      // 0x00882B28
extern unsigned short* gpCharMapIndex_00882B2C;                                                             // 0x00882B2C
extern "C" void* __cdecl bsearch(const void* pKey, const void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x006881B1
extern "C" unsigned int __cdecl strlen(const char* szString);
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight);                                 // 0x00527AE0
Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

// 0x005276E0
static int sub_005276E0_IsLeadByte(unsigned char nByte)
{
    if (nByte < 0x20)
    {
        return 0;
    }
    for (int i = 0; i < gnLeadByteRangeCount_00882B22; ++i)
    {
        if (gpLeadByteRanges_00882B28[i].f_0 <= nByte && nByte <= gpLeadByteRanges_00882B28[i].f_1)
        {
            return 0;
        }
    }
    return 1;
}

static int sub_00527B00_MapUnicodeChar(int nChar)
{
    const unsigned short wChar = (unsigned short)nChar;
    if (wChar < 0x20)
    {
        return wChar;
    }
    D2LangCharMapEntryStrc tKey;
    tKey.f_2 = wChar;
    const D2LangCharMapEntryStrc* pEntry = (const D2LangCharMapEntryStrc*)bsearch(&tKey, gpCharMap_00882B24, gnCharMapCount_00882B20, sizeof(D2LangCharMapEntryStrc), sub_00527AE0_CompareKey);
    if (!pEntry)
    {
        return -1;
    }
    return pEntry->wValue;
}

// 0x00527CA0
int __fastcall sub_00527CA0_GetCodePageLength(const Unicode* pSrc, int nCount)
{
    if (!gpCharMap_00882B24)
    {
        return sub_00526800(pSrc);
    }
    int nLength = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (!pSrc[i].wChar)
        {
            goto terminate;
        }
        const int nCodePage = sub_00527B00_MapUnicodeChar(pSrc[i].wChar);
        if (nCodePage < 0)
        {
            continue;
        }
        if ((nCodePage & 0xFF00) || sub_005276E0_IsLeadByte((unsigned char)nCodePage))
        {
            nLength += 2;
        }
        else
        {
            nLength += 1;
        }
    }
terminate:
    return nLength;
}
