unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern "C" char* __cdecl strpbrk(const char* szString, const char* szCharSet);                              // 0x00686990
extern "C" const char gszCloseParen_006CF324[];                                                            // 0x006CF324

// 0x0041C1F0
static int __stdcall sub_0041C1F0_FormatTypeName(const char* szName, char* szOut, unsigned int nSize)
{
    if (SStrLen(szName) < 6)
        return 0;
    if (szName[0] != '.' || szName[3] != 'U')
        return 0;
    const char* pName = szName + 4;
    if (!strpbrk(pName, "?@"))
        return 0;
    SStrCopy(szOut, pName, nSize);
    char* p = strpbrk(szOut, "?@");
    if (!p)
        return 0;
    *p = 0;
    for (p--; p >= szOut && *p == '_'; p--)
        *p = 0;
    sub_00413800(szOut, " (", nSize);
    sub_00413800(szOut, szName, nSize);
    sub_00413800(szOut, gszCloseParen_006CF324, nSize);
    return 1;
}

int __stdcall sub_M01_Emit_0041C1F0(const char* szName, char* szOut)
{
    return sub_0041C1F0_FormatTypeName(szName, szOut, 0x100);
}
