#include "Fog.h"
#include "D2GameTypes.h"


struct D2ExceptionPointersStrc
{
    void* pExceptionRecord;
    D2ThreadContextStrc* pContextRecord;
};

typedef void (__cdecl* D2SETranslatorFn)(unsigned int, D2ExceptionPointersStrc*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" D2SETranslatorFn __cdecl _set_se_translator(D2SETranslatorFn pfnTranslator);                    // 0x00684AF3
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __cdecl LOGMANAGER_SETranslator(unsigned int nCode, D2ExceptionPointersStrc* pExceptionInfo);         // 0x0040D540

extern D2CriticalSectionStrc gtImageHlpLock;                                                       // 0x0075CFBC
void* ghImageHlp;                                                                                  // 0x0075CFD8
void* gpfnImageHlpSymCleanup;                                                                              // 0x0075CFDC
void* gpfnSymFunctionTableAccess;                                                                  // 0x0075CFE0
extern void* gpfnSymGetLineFromAddr;                                                               // 0x0075CFE4
void* gpfnSymGetModuleBase;                                                                        // 0x0075CFE8
void* gpfnSymGetModuleInfo;                                                                        // 0x0075CFEC
void* gpfnImageHlpSymGetOptions;                                                                           // 0x0075CFF0
void* gpfnSymGetSymFromAddr;                                                                       // 0x0075CFF4
void* gpfnImageHlpSymInitialize;                                                                           // 0x0075CFF8
void* gpfnSymLoadModule;                                                                           // 0x0075CFFC
void* gpfnSymUnloadModule;                                                                         // 0x0075D000
void* gpfnImageHlpSymSetOptions;                                                                           // 0x0075D004
void* gpfnStackWalk;                                                                               // 0x0075D008
void* gpfnUnDecorateSymbolName;                                                                    // 0x0075D00C
void* gpfnImageHlpMiniDumpWriteDump;                                                                       // 0x0075D010
int gbImageHlpLoaded;                                                                              // 0x0075D014

// 0x0040B500
int __cdecl sub_0040B500_UnloadImageHlp()
{
    gbImageHlpLoaded = 0;
    if (ghImageHlp)
    {
        FreeLibrary(ghImageHlp);
        ghImageHlp = 0;
    }
    DeleteCriticalSection(&gtImageHlpLock);
    return 1;
}

// 0x0040D5B0
int __cdecl sub_0040D5B0_LoadImageHlp()
{
    if (gbImageHlpLoaded)
    {
        return 1;
    }
    InitializeCriticalSection(&gtImageHlpLock);
    _set_se_translator(LOGMANAGER_SETranslator);
    ghImageHlp = LoadLibraryA(".\\dbghelp.dll");
    if (!ghImageHlp)
    {
        ghImageHlp = LoadLibraryA("dbghelp.dll");
        if (!ghImageHlp)
        {
            ghImageHlp = LoadLibraryA("imagehlp.dll");
            if (!ghImageHlp)
            {
                sub_00410610_WriteLogLine("Missing imagehlp.dll.  Can't generate better stack crawls!");
                return 0;
            }
        }
    }
    gpfnImageHlpSymCleanup = GetProcAddress(ghImageHlp, "SymCleanup");
    gpfnSymFunctionTableAccess = GetProcAddress(ghImageHlp, "SymFunctionTableAccess");
    gpfnSymGetLineFromAddr = GetProcAddress(ghImageHlp, "SymGetLineFromAddr");
    gpfnSymGetModuleBase = GetProcAddress(ghImageHlp, "SymGetModuleBase");
    gpfnSymGetModuleInfo = GetProcAddress(ghImageHlp, "SymGetModuleInfo");
    gpfnImageHlpSymGetOptions = GetProcAddress(ghImageHlp, "SymGetOptions");
    gpfnSymGetSymFromAddr = GetProcAddress(ghImageHlp, "SymGetSymFromAddr");
    gpfnImageHlpSymInitialize = GetProcAddress(ghImageHlp, "SymInitialize");
    gpfnImageHlpSymSetOptions = GetProcAddress(ghImageHlp, "SymSetOptions");
    gpfnSymLoadModule = GetProcAddress(ghImageHlp, "SymLoadModule");
    gpfnSymUnloadModule = GetProcAddress(ghImageHlp, "SymUnloadModule");
    gpfnStackWalk = GetProcAddress(ghImageHlp, "StackWalk");
    gpfnUnDecorateSymbolName = GetProcAddress(ghImageHlp, "UnDecorateSymbolName");
// build: symbol ?gszMiniDumpWriteDump@* 0x006FFB94
    gpfnImageHlpMiniDumpWriteDump = GetProcAddress(ghImageHlp, gszMiniDumpWriteDump);
    if (gpfnImageHlpSymCleanup && gpfnSymFunctionTableAccess && gpfnSymGetModuleBase
        && gpfnSymGetModuleInfo && gpfnImageHlpSymGetOptions && gpfnSymGetSymFromAddr
        && gpfnImageHlpSymInitialize && gpfnImageHlpSymSetOptions && gpfnStackWalk
        && gpfnUnDecorateSymbolName && gpfnSymLoadModule && gpfnSymUnloadModule)
    {
        gbImageHlpLoaded = 1;
        sub_00410610_WriteLogLine("imagehlp.dll loaded for better stack crawls.");
        return 1;
    }
    sub_00410610_WriteLogLine("Missing functions in imagehlp.dll.  Can't generate better stack crawls!");
    return 0;
}
