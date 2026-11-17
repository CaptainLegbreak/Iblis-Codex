extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

// 0x00654410
static int sub_00654410_NextIntToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return atoi(szToken);
}

int __stdcall sub_A10_Emit_00654410(char* szText, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
    {
        nSum += sub_00654410_NextIntToken(&szText, ',');
    }
    return nSum;
}
