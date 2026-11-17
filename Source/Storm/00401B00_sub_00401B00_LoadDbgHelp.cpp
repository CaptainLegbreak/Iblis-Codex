extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName);                  // 0x006CC294
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" const char gszMiniDumpWriteDump_006FFB94[];                                                      // 0x006FFB94
void* ghDbgHelp_0098A680;                                                                                   // 0x0098A680
void* gpfnEnumerateLoadedModules64_0098A6A4;                                                                // 0x0098A6A4
void* gpfnStackWalk64_0098A6A0;                                                                             // 0x0098A6A0
void* gpfnSymFunctionTableAccess64_0098A698;                                                                // 0x0098A698
void* gpfnSymGetLineFromAddr64_0098A6E8;                                                                    // 0x0098A6E8
void* gpfnSymGetModuleBase64_0098A69C;                                                                      // 0x0098A69C
void* gpfnSymGetModuleInfo64_0098A684;                                                                      // 0x0098A684
extern void* gpfnSymGetOptions_0098A6AC;                                                                    // 0x0098A6AC
void* gpfnSymGetSymFromAddr64_0098A68C;                                                                     // 0x0098A68C
extern void* gpfnSymInitialize_0098A6A8;                                                                    // 0x0098A6A8
extern void* gpfnSymCleanup_0098A6B8;                                                                       // 0x0098A6B8
extern void* gpfnSymSetOptions_0098A6B4;                                                                    // 0x0098A6B4
void* gpfnSymEnumerateModules64_0098A688;                                                                   // 0x0098A688
void* gpfnSymSetSearchPath_0098A690;                                                                        // 0x0098A690
void* gpfnSymFindFileInPath_0098A6EC;                                                                       // 0x0098A6EC
void* gpfnSymLoadModule64_0098A6DC;                                                                         // 0x0098A6DC
void* gpfnSymUnloadModule64_0098A694;                                                                       // 0x0098A694
void* gpfnMiniDumpWriteDump_0098A6E0;                                                                       // 0x0098A6E0

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

#include "gen/data/Source/Storm/00401B00_sub_00401B00_LoadDbgHelp.inc"
