extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet);                          // 0x00688990

// 0x00668590
static char* sub_00668590_NextSetToken(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return szToken;
}

char* __stdcall sub_M133_Emit_00668590(char* szText, const char* szSet, char** ppOut)
{
    ppOut[0] = sub_00668590_NextSetToken(&szText, szSet);
    ppOut[1] = sub_00668590_NextSetToken(&szText, szSet);
    return szText;
}
