extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8

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
