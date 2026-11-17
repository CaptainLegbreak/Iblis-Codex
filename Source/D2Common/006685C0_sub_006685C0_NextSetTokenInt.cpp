extern "C" unsigned int __cdecl strcspn(const char* szString, const char* szSet);                          // 0x00688990
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

// 0x006685C0
static int sub_006685C0_NextSetTokenInt(char** ppString, const char* szSet)
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
    return atoi(szToken);
}

char* __stdcall sub_M133_Emit_006685C0(char* szText, const char* szSet, int* pOut)
{
    pOut[0] = sub_006685C0_NextSetTokenInt(&szText, szSet);
    pOut[1] = sub_006685C0_NextSetTokenInt(&szText, szSet);
    return szText;
}
