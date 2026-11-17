const char* __stdcall SStrChr(const char* szString, char c); // 0x00413490

static __declspec(noinline) const char* sub_006C5EE0_FindExtension(const char* szPath);
// 0x006C5EE0
static const char* sub_006C5EE0_FindExtension(const char* szPath)
{
    const char* szName = szPath;
    while (SStrChr(szName, '\\'))
        szName = SStrChr(szName, '\\') + 1;
    while (SStrChr(szName + 1, '.'))
        szName = SStrChr(szName + 1, '.');
    return szName;
}

// calling-convention shim (not game code)
const char* __fastcall sub_006C5EE0_Shim(const char* szPath)
{
    return sub_006C5EE0_FindExtension(szPath);
}
