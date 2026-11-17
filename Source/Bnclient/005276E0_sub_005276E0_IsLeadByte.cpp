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
unsigned char gnLeadByteRangeCount_00882B22;                                                                // 0x00882B22
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

static __forceinline int FindCharIndex(unsigned short wChar)
{
    int nLow = 0;
    int nHigh = gnCharMapCount_00882B20 - 1;
    if (wChar < gpCharMap_00882B24[gpCharMapIndex_00882B2C[0]].wValue || wChar > gpCharMap_00882B24[gpCharMapIndex_00882B2C[nHigh]].wValue)
    {
        return -1;
    }
    int nMid = nHigh;
    if (wChar != gpCharMap_00882B24[gpCharMapIndex_00882B2C[nHigh]].wValue)
    {
        nMid = (nLow + nHigh) >> 1;
        do
        {
            if (wChar >= gpCharMap_00882B24[gpCharMapIndex_00882B2C[nMid]].wValue)
            {
                nLow = nMid;
            }
            else
            {
                nHigh = nMid;
            }
            nMid = (nLow + nHigh) >> 1;
        }
        while (nHigh - nLow > 1);
        if (gpCharMap_00882B24[gpCharMapIndex_00882B2C[nMid]].wValue != wChar)
        {
            return -1;
        }
    }
    return nMid;
}

// build: context sub_00527A50_MapCodePageChar
static __declspec(noinline) int sub_00527A50_MapCodePageChar(unsigned short wChar)
{
    if (wChar < 0x20)
    {
        return wChar;
    }
    const int nIndex = FindCharIndex(wChar);
    if (nIndex < 0)
    {
        return -1;
    }
    return gpCharMap_00882B24[gpCharMapIndex_00882B2C[nIndex]].f_2;
}

// 0x00527B00
static int sub_00527B00_MapUnicodeChar(unsigned short wChar)
{
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

// 0x00527B50
Unicode* __fastcall sub_00527B50_CodePageToUnicode(Unicode* pDest, const char* szSrc, int nCount)
{
    if (!gpCharMapIndex_00882B2C)
    {
        return sub_00526F20_ToUnicode(pDest, szSrc, nCount);
    }
    int i = 0;
    for (; i < nCount; ++i)
    {
        const unsigned char nByte = *szSrc;
        if (!nByte)
        {
            goto terminate;
        }
        unsigned short wChar;
        if (sub_005276E0_IsLeadByte(nByte))
        {
            wChar = (unsigned short)((nByte << 8) | (unsigned char)szSrc[1]);
            szSrc += 2;
        }
        else
        {
            wChar = nByte;
            ++szSrc;
        }
        const int nUnicode = sub_00527A50_MapCodePageChar(wChar);
        if (nUnicode < 0)
        {
            --i;
        }
        else
        {
            pDest[i].wChar = nUnicode;
        }
    }
    if (*szSrc)
    {
        return pDest;
    }
terminate:
    if (i < nCount)
    {
        pDest[i].wChar = 0;
    }
    return pDest;
}

char* __fastcall sub_00527BE0_UnicodeToCodePage(char* szDest, const Unicode* pSrc, int nCount)
{
    if (!gpCharMap_00882B24)
    {
        return sub_00526F70(szDest, pSrc, nCount);
    }
    int i = 0;
    for (; i < nCount; ++pSrc)
    {
        const Unicode tChar = *pSrc;
        if (!tChar)
        {
            break;
        }
        const int nCodePage = sub_00527B00_MapUnicodeChar(tChar);
        if (nCodePage < 0)
        {
            continue;
        }
        if ((nCodePage & 0xFF00) || sub_005276E0_IsLeadByte((unsigned char)nCodePage))
        {
            szDest[i++] = (char)((unsigned int)nCodePage >> 8);
        }
        szDest[i++] = (char)nCodePage;
    }
    if (!pSrc->wChar && i < nCount)
    {
        szDest[i] = 0;
    }
    return szDest;
}

int __fastcall sub_00527CA0_GetCodePageLength(const Unicode* pSrc, int nCount)
{
    if (!gpCharMap_00882B24)
    {
        return sub_00526800(pSrc);
    }
    int nLength = 0;
    for (int i = 0; i < nCount; ++i)
    {
        const Unicode tChar = pSrc[i];
        if (!tChar)
        {
            break;
        }
        const int nCodePage = sub_00527B00_MapUnicodeChar(tChar);
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
    return nLength;
}

// 0x00527D50
int __fastcall sub_00527D50_GetCodePageCharCount(const char* szSrc, int nCount)
{
    if (!gpCharMapIndex_00882B2C)
    {
        return strlen(szSrc);
    }
    int nLength = 0;
    for (int i = 0; i < nCount; ++nLength)
    {
        const unsigned char nByte = szSrc[i];
        if (!nByte)
        {
            break;
        }
        if (sub_005276E0_IsLeadByte(nByte))
        {
            i += 2;
        }
        else
        {
            i += 1;
        }
    }
    return nLength;
}
