typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl _ultoa(unsigned long nValue, char* szOut, int nRadix);                             // 0x00687652
extern "C" char* __cdecl _i64toa(__int64 nValue, char* szOut, int nRadix);                                  // 0x006876D7

struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncat(Unicode* dest, const Unicode* src, int count); // 0x00526740
};

struct D2LanguageInfoStrc
{
    const char* szName;
    const char* szCode;
    const char* szAltCode;
    const char* szRegion;
    int nFourCC;
    int f_14;
};

struct D2LangCharSetStrc
{
    char szChars[1];

    bool sub_00527090_ContainsChar(const Unicode* pChar) const;
};

struct D2StringTableStrc;

extern D2LanguageInfoStrc gaLanguageInfo_007303D8[13];                                                      // 0x007303D8
extern Unicode gawszUnitSuffix_00730510[4][2];                                                              // 0x00730510
D2StringTableStrc* gpStringTable_008829B4;                                                                  // 0x008829B4
void* gpStringIndex_008829B8;                                                                               // 0x008829B8
extern D2StringTableStrc* gpPatchStringTable_008829D0;                                                      // 0x008829D0
extern void* gpPatchStringIndex_008829BC;                                                                   // 0x008829BC
extern D2StringTableStrc* gpExpansionStringTable_008829D4;                                                  // 0x008829D4
extern void* gpExpansionStringIndex_008829C0;                                                               // 0x008829C0
extern "C" const char szStar_006D5830[];                                                                    // 0x006D5830

int __cdecl sub_00525150();                                                                         // 0x00525150
const Unicode* __fastcall sub_00524930(D2StringTableStrc* pTable, void* pIndex, unsigned short nIndex); // 0x00524930
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

static inline const Unicode* D2LANG_GetStringFromTblIndex_Inline(unsigned short nIndex)
{
    if (nIndex >= 0x4E20)
    {
        if (!gpExpansionStringTable_008829D4)
        {
            nIndex = 0x2B46;
        }
        else
        {
            const Unicode* pText = sub_00524930(gpExpansionStringTable_008829D4, gpExpansionStringIndex_008829C0, nIndex - 0x4E20);
            if (pText)
            {
                return pText;
            }
        }
    }
    if (gpPatchStringTable_008829D0 && nIndex >= 0x2710)
    {
        const Unicode* pText = sub_00524930(gpPatchStringTable_008829D0, gpPatchStringIndex_008829BC, nIndex - 0x2710);
        if (pText)
        {
            return pText;
        }
    }
    D2_ASSERT(gpStringTable_008829B4, 0x246);
    return sub_00524930(gpStringTable_008829B4, gpStringIndex_008829B8, nIndex);
}

// 0x00525260
void __stdcall sub_00525260(void* pOut, int nField)
{
    const int nLanguageId = sub_00525150();
    D2_ASSERT(gaLanguageInfo_007303D8[0].f_14 == 0, 0x490);

    int nIndex = 0;
    if (nLanguageId < 14)
    {
        for (nIndex = 0; nIndex < 13; ++nIndex)
        {
            if (gaLanguageInfo_007303D8[nIndex].f_14 == nLanguageId)
            {
                break;
            }
        }
        if (nIndex >= 14)
        {
            nIndex = 0;
        }
    }

    switch (nField)
    {
    case 1:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szAltCode);
        break;
    case 2:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szRegion);
        break;
    case 3:
        *(int*)pOut = gaLanguageInfo_007303D8[nIndex].nFourCC;
        break;
    default:
        strcpy((char*)pOut, gaLanguageInfo_007303D8[nIndex].szCode);
        break;
    }
}

// 0x00525350
void __stdcall sub_00525350_FormatUInt(Unicode* pOut, unsigned int nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x4ED);
    _ultoa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x500);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3 && strlen(szBuffer) > 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
    sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
    sub_005267E0(pOut, wszStar);
}

// 0x00525490
void __stdcall sub_00525490_FormatInt64(Unicode* pOut, __int64 nValue, int nSize)
{
    char szBuffer[64];
    int nGroup = 0;
    D2_ASSERT(nSize > 2, 0x519);
    if (nValue < 0)
    {
        pOut->wChar = '-';
        ++pOut;
        --nSize;
        nValue = -nValue;
    }
    _i64toa(nValue, szBuffer, 10);
    int nLength = strlen(szBuffer);
    if (nLength)
    {
        int nPos = nLength + (nLength - 1) / 3;
        if (nPos >= 1 && nPos < nSize - 1)
        {
            pOut[nPos].wChar = 0;
            while (nLength)
            {
                D2_ASSERT(nPos != 0, 0x533);
                --nLength;
                --nPos;
                pOut[nPos].wChar = szBuffer[nLength];
                ++nGroup;
                if (nGroup >= 3)
                {
                    nGroup = 0;
                    if (nPos > 0)
                    {
                        --nPos;
                        pOut[nPos].wChar = ',';
                    }
                }
            }
            return;
        }
    }
    Unicode wszStar[2];
    wszStar[0].wChar = 0;
    wszStar[1].wChar = 0;
    sub_00526320_ToUnicode(wszStar, szStar_006D5830, 2);
    sub_005267E0(pOut, wszStar);
}

// 0x00525770
void __cdecl sub_00525770_InitUnitSuffixes()
{
    char szBuffer[8];

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D0), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[0][0].wChar = 'K';
    }
    else
    {
        gawszUnitSuffix_00730510[0][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D1), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[1][0].wChar = 'M';
    }
    else
    {
        gawszUnitSuffix_00730510[1][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D2), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[2][0].wChar = 'B';
    }
    else
    {
        gawszUnitSuffix_00730510[2][0].wChar = szBuffer[0];
    }

    sub_00526F70(szBuffer, D2LANG_GetStringFromTblIndex_Inline(0x14D3), 5);
    if (strlen(szBuffer) > 1)
    {
        gawszUnitSuffix_00730510[3][0].wChar = 'T';
    }
    else
    {
        gawszUnitSuffix_00730510[3][0].wChar = szBuffer[0];
    }
}

// build: context Unicode::strncat
Unicode* __fastcall Unicode::strncat(Unicode* dest, const Unicode* src, int count)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
    {
        ++pEnd;
    }

    while (count--)
    {
        if (!src->wChar)
        {
            break;
        }
        *pEnd++ = *src++;
    }

    pEnd->wChar = 0;
    return dest;
}

// 0x00527090
bool D2LangCharSetStrc::sub_00527090_ContainsChar(const Unicode* pChar) const
{
    Unicode wszChars[20] = {};
    int i;
    for (i = 0; i < 20 && szChars[i] != '\0'; ++i)
    {
        wszChars[i].wChar = (unsigned char)szChars[i];
    }
    if (szChars[i] != '\0')
    {
        wszChars[i - 1].wChar = 0;
    }
    else
    {
        wszChars[i].wChar = 0;
    }
    const int nLength = sub_00526800(wszChars);
    for (int j = 0; j < nLength; ++j)
    {
        if (pChar->wChar == wszChars[j].wChar)
        {
            return true;
        }
    }
    return false;
}

#include "gen/data/Source/Bnclient/00525260_sub_00525260.inc"
