#include "D2Hell.h"

const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character); // 0x006C9AFF

// 0x006C9A46
int __fastcall sub_006C9A46_StringEquals(const char* szA, const char* szB)
{
    while (*szA)
    {
        if (!*szB || *szA != *szB)
        {
            break;
        }
        ++szA;
        ++szB;
    }
    return *szA == *szB;
}

// 0x006C9A76
int __fastcall sub_006C9A76_ParseNumber(const char* szText, const char** pszEnd, int* pnValue)
{
    if (!(gCharacterClass_0074C5C8[*szText] & 2))
    {
        *pszEnd = szText;
        return 0;
    }
    int nValue = 0;
    while (*szText && (gCharacterClass_0074C5C8[*szText] & 2))
    {
        nValue = nValue * 10 + *szText - '0';
        ++szText;
    }
    *pnValue = nValue;
    *pszEnd = szText;
    return 1;
}

// 0x006C9AC7
const char* __fastcall sub_006C9AC7_SkipSpaces(const char* szText)
{
    while (*szText && (gCharacterClass_0074C5C8[*szText] & 1))
    {
        ++szText;
    }
    return szText;
}

// 0x006C9ADF
const char* __fastcall sub_006C9ADF_CopyWord(char* szDest, const char* szSource)
{
    while (*szSource && !(gCharacterClass_0074C5C8[*szSource] & 1))
    {
        *szDest = *szSource;
        ++szDest;
        ++szSource;
    }
    *szDest = 0;
    return szSource;
}

// 0x006C9B17
char* __fastcall sub_006C9B17_StripFileName(char* szPath)
{
    char* pSlash = (char*)sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        *szPath = 0;
    }
    else
    {
        *pSlash = 0;
    }
    return szPath;
}

// 0x006C9B30
const char* __fastcall sub_006C9B30_GetFileName(const char* szPath)
{
    const char* pSlash = sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        return szPath;
    }
    return pSlash + 1;
}
