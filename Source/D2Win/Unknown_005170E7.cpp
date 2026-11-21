extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490

static void sub_005170E7_GetModuleDirectory(char* szPath);

// 0x005170E7
static void sub_005170E7_GetModuleDirectory(char* szPath)
{
    GetModuleFileNameA(0, szPath, 260);
    szPath[259] = 0;
    char* pEnd = szPath;
    while (*pEnd && SStrChr(pEnd + 1, '\\'))
    {
        pEnd = (char*)SStrChr(pEnd + 1, '\\');
    }
    *pEnd = 0;
}

// build: context sub_005170E7_Shim

// calling-convention shim (not game code)
void __fastcall sub_005170E7_Shim(char* szPath)
{
    sub_005170E7_GetModuleDirectory(szPath);
}
