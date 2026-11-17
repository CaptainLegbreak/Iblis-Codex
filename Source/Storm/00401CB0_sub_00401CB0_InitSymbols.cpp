extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                      // 0x006CC13C
extern "C" __declspec(dllimport) unsigned long __stdcall GetProcessId(void* hProcess);                     // 0x006CC2A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2

extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
void* gpfnSymInitialize_0098A6A8;                                                                           // 0x0098A6A8
void* gpfnSymGetOptions_0098A6AC;                                                                           // 0x0098A6AC
bool gbSymInitialized_0098A6B0;                                                                             // 0x0098A6B0
void* gpfnSymSetOptions_0098A6B4;                                                                           // 0x0098A6B4
char gszSymSearchPath_0098A708[32768];                                                                      // 0x0098A708

typedef unsigned long (__stdcall* SymGetOptionsFn)();
typedef unsigned long (__stdcall* SymSetOptionsFn)(unsigned long dwOptions);
typedef int (__stdcall* SymInitializeFn)(void* hProcess, const char* szUserSearchPath, int bInvadeProcess);

// 0x00401CB0
bool __cdecl sub_00401CB0_InitSymbols()
{
    char szPath[0x8000];

    if (gbSymInitialized_0098A6B0)
    {
        return true;
    }

    if (!ghDbgHelp_0098A680)
    {
        return false;
    }

    if (!gpfnSymSetOptions_0098A6B4)
    {
        return false;
    }

    if (!gpfnSymInitialize_0098A6A8)
    {
        return false;
    }

    ((SymSetOptionsFn)gpfnSymSetOptions_0098A6B4)(((SymGetOptionsFn)gpfnSymGetOptions_0098A6AC)() | 0x214);

    if (!gszSymSearchPath_0098A708[0])
    {
        GetModuleFileNameA(0, szPath, sizeof(szPath));
        szPath[sizeof(szPath) - 1] = 0;
        char* pSlash = strrchr(szPath, 0x5C);
        if (pSlash)
        {
            *pSlash = 0;
        }
    }
    else
    {
        strncpy_s(szPath, sizeof(szPath), gszSymSearchPath_0098A708, (unsigned int)-1);
    }

    if (ghProcess_0074C6F0 == (void*)-1)
    {
        ghProcess_0074C6F0 = GetCurrentProcess();
    }

    if (!((SymInitializeFn)gpfnSymInitialize_0098A6A8)(ghProcess_0074C6F0, szPath, GetProcessId(ghProcess_0074C6F0) != 0))
    {
        return false;
    }

    gbSymInitialized_0098A6B0 = true;
    return true;
}

#include "gen/data/Source/Storm/00401CB0_sub_00401CB0_InitSymbols.inc"
