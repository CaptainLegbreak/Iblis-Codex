#include "Fog.h"

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName); // 0x006CC294
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern void* gpfnSymGetOptions_0098A6AC; // 0x0098A6AC
extern void* gpfnSymInitialize_0098A6A8; // 0x0098A6A8
extern void* gpfnSymCleanup_0098A6B8; // 0x0098A6B8
extern void* gpfnSymSetOptions_0098A6B4; // 0x0098A6B4
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) unsigned long __stdcall GetProcessId(void* hProcess); // 0x006CC2A0
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2
extern void* ghProcess_0074C6F0; // 0x0074C6F0
extern void* ghDbgHelp_0098A680; // 0x0098A680

typedef unsigned long (__stdcall* SymGetOptionsFn)();

typedef unsigned long (__stdcall* SymSetOptionsFn)(unsigned long dwOptions);

typedef int (__stdcall* SymInitializeFn)(void* hProcess, const char* szUserSearchPath, int bInvadeProcess);

void* ghDbgHelp_0098A680; // 0x0098A680

void* gpfnEnumerateLoadedModules64_0098A6A4; // 0x0098A6A4

void* gpfnStackWalk64_0098A6A0; // 0x0098A6A0

void* gpfnSymFunctionTableAccess64_0098A698; // 0x0098A698

void* gpfnSymGetLineFromAddr64_0098A6E8; // 0x0098A6E8

void* gpfnSymGetModuleBase64_0098A69C; // 0x0098A69C

void* gpfnSymGetModuleInfo64_0098A684; // 0x0098A684

void* gpfnSymGetSymFromAddr64_0098A68C; // 0x0098A68C

void* gpfnSymEnumerateModules64_0098A688; // 0x0098A688

void* gpfnSymSetSearchPath_0098A690; // 0x0098A690

void* gpfnSymFindFileInPath_0098A6EC; // 0x0098A6EC

void* gpfnSymLoadModule64_0098A6DC; // 0x0098A6DC

void* gpfnSymUnloadModule64_0098A694; // 0x0098A694

void* gpfnMiniDumpWriteDump_0098A6E0; // 0x0098A6E0

// 0x00401B00
bool __cdecl sub_00401B00_LoadDbgHelp()
{
    if (ghDbgHelp_0098A680)
    {
        return true;
    }
    void* hModule = LoadLibraryW(L"DbgHelp.dll");
    if (!hModule)
    {
        return false;
    }
    if (!(gpfnEnumerateLoadedModules64_0098A6A4 = GetProcAddress(hModule, "EnumerateLoadedModules64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnStackWalk64_0098A6A0 = GetProcAddress(hModule, "StackWalk64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymFunctionTableAccess64_0098A698 = GetProcAddress(hModule, "SymFunctionTableAccess64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetLineFromAddr64_0098A6E8 = GetProcAddress(hModule, "SymGetLineFromAddr64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetModuleBase64_0098A69C = GetProcAddress(hModule, "SymGetModuleBase64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetModuleInfo64_0098A684 = GetProcAddress(hModule, "SymGetModuleInfo64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetOptions_0098A6AC = GetProcAddress(hModule, "SymGetOptions")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetSymFromAddr64_0098A68C = GetProcAddress(hModule, "SymGetSymFromAddr64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymInitialize_0098A6A8 = GetProcAddress(hModule, "SymInitialize")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymCleanup_0098A6B8 = GetProcAddress(hModule, "SymCleanup")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymSetOptions_0098A6B4 = GetProcAddress(hModule, "SymSetOptions")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymEnumerateModules64_0098A688 = GetProcAddress(hModule, "SymEnumerateModules64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymSetSearchPath_0098A690 = GetProcAddress(hModule, "SymSetSearchPath")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymFindFileInPath_0098A6EC = GetProcAddress(hModule, "SymFindFileInPath")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymLoadModule64_0098A6DC = GetProcAddress(hModule, "SymLoadModule64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymUnloadModule64_0098A694 = GetProcAddress(hModule, "SymUnloadModule64")))
    {
        CloseHandle(hModule);
        return false;
    }
    gpfnMiniDumpWriteDump_0098A6E0 = GetProcAddress(hModule, gszMiniDumpWriteDump_006FFB94);
    ghDbgHelp_0098A680 = hModule;
    return true;
}

#include "gen/data/Source/Fog/Unknown_00401B00.inc"

void* gpfnSymInitialize_0098A6A8; // 0x0098A6A8

void* gpfnSymGetOptions_0098A6AC; // 0x0098A6AC

bool gbSymInitialized_0098A6B0; // 0x0098A6B0

void* gpfnSymSetOptions_0098A6B4; // 0x0098A6B4

char gszSymSearchPath_0098A708[32768]; // 0x0098A708

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
