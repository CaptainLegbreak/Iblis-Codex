#include "Fog.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

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
void __cdecl sub_0040D540_SETranslator(unsigned int nCode, D2ExceptionPointersStrc* pExceptionInfo);         // 0x0040D540

extern D2CriticalSectionStrc gtImageHlpLock_0075CFBC;                                                       // 0x0075CFBC
void* ghImageHlp_0075CFD8;                                                                                  // 0x0075CFD8
void* gpfnSymCleanup_0075CFDC;                                                                              // 0x0075CFDC
void* gpfnSymFunctionTableAccess_0075CFE0;                                                                  // 0x0075CFE0
extern void* gpfnSymGetLineFromAddr_0075CFE4;                                                               // 0x0075CFE4
void* gpfnSymGetModuleBase_0075CFE8;                                                                        // 0x0075CFE8
void* gpfnSymGetModuleInfo_0075CFEC;                                                                        // 0x0075CFEC
void* gpfnSymGetOptions_0075CFF0;                                                                           // 0x0075CFF0
void* gpfnSymGetSymFromAddr_0075CFF4;                                                                       // 0x0075CFF4
void* gpfnSymInitialize_0075CFF8;                                                                           // 0x0075CFF8
void* gpfnSymLoadModule_0075CFFC;                                                                           // 0x0075CFFC
void* gpfnSymUnloadModule_0075D000;                                                                         // 0x0075D000
void* gpfnSymSetOptions_0075D004;                                                                           // 0x0075D004
void* gpfnStackWalk_0075D008;                                                                               // 0x0075D008
void* gpfnUnDecorateSymbolName_0075D00C;                                                                    // 0x0075D00C
void* gpfnMiniDumpWriteDump_0075D010;                                                                       // 0x0075D010
int gbImageHlpLoaded_0075D014;                                                                              // 0x0075D014

// 0x0040B500
int __cdecl sub_0040B500_UnloadImageHlp()
{
    gbImageHlpLoaded_0075D014 = 0;
    if (ghImageHlp_0075CFD8)
    {
        FreeLibrary(ghImageHlp_0075CFD8);
        ghImageHlp_0075CFD8 = 0;
    }
    DeleteCriticalSection(&gtImageHlpLock_0075CFBC);
    return 1;
}

// 0x0040D5B0
int __cdecl sub_0040D5B0_LoadImageHlp()
{
    if (gbImageHlpLoaded_0075D014)
    {
        return 1;
    }
    InitializeCriticalSection(&gtImageHlpLock_0075CFBC);
    _set_se_translator(sub_0040D540_SETranslator);
    ghImageHlp_0075CFD8 = LoadLibraryA(".\\dbghelp.dll");
    if (!ghImageHlp_0075CFD8)
    {
        ghImageHlp_0075CFD8 = LoadLibraryA("dbghelp.dll");
        if (!ghImageHlp_0075CFD8)
        {
            ghImageHlp_0075CFD8 = LoadLibraryA("imagehlp.dll");
            if (!ghImageHlp_0075CFD8)
            {
                sub_00410610_WriteLogLine("Missing imagehlp.dll.  Can't generate better stack crawls!");
                return 0;
            }
        }
    }
    gpfnSymCleanup_0075CFDC = GetProcAddress(ghImageHlp_0075CFD8, "SymCleanup");
    gpfnSymFunctionTableAccess_0075CFE0 = GetProcAddress(ghImageHlp_0075CFD8, "SymFunctionTableAccess");
    gpfnSymGetLineFromAddr_0075CFE4 = GetProcAddress(ghImageHlp_0075CFD8, "SymGetLineFromAddr");
    gpfnSymGetModuleBase_0075CFE8 = GetProcAddress(ghImageHlp_0075CFD8, "SymGetModuleBase");
    gpfnSymGetModuleInfo_0075CFEC = GetProcAddress(ghImageHlp_0075CFD8, "SymGetModuleInfo");
    gpfnSymGetOptions_0075CFF0 = GetProcAddress(ghImageHlp_0075CFD8, "SymGetOptions");
    gpfnSymGetSymFromAddr_0075CFF4 = GetProcAddress(ghImageHlp_0075CFD8, "SymGetSymFromAddr");
    gpfnSymInitialize_0075CFF8 = GetProcAddress(ghImageHlp_0075CFD8, "SymInitialize");
    gpfnSymSetOptions_0075D004 = GetProcAddress(ghImageHlp_0075CFD8, "SymSetOptions");
    gpfnSymLoadModule_0075CFFC = GetProcAddress(ghImageHlp_0075CFD8, "SymLoadModule");
    gpfnSymUnloadModule_0075D000 = GetProcAddress(ghImageHlp_0075CFD8, "SymUnloadModule");
    gpfnStackWalk_0075D008 = GetProcAddress(ghImageHlp_0075CFD8, "StackWalk");
    gpfnUnDecorateSymbolName_0075D00C = GetProcAddress(ghImageHlp_0075CFD8, "UnDecorateSymbolName");
    gpfnMiniDumpWriteDump_0075D010 = GetProcAddress(ghImageHlp_0075CFD8, gszMiniDumpWriteDump_006FFB94);
    if (gpfnSymCleanup_0075CFDC && gpfnSymFunctionTableAccess_0075CFE0 && gpfnSymGetModuleBase_0075CFE8
        && gpfnSymGetModuleInfo_0075CFEC && gpfnSymGetOptions_0075CFF0 && gpfnSymGetSymFromAddr_0075CFF4
        && gpfnSymInitialize_0075CFF8 && gpfnSymSetOptions_0075D004 && gpfnStackWalk_0075D008
        && gpfnUnDecorateSymbolName_0075D00C && gpfnSymLoadModule_0075CFFC && gpfnSymUnloadModule_0075D000)
    {
        gbImageHlpLoaded_0075D014 = 1;
        sub_00410610_WriteLogLine("imagehlp.dll loaded for better stack crawls.");
        return 1;
    }
    sub_00410610_WriteLogLine("Missing functions in imagehlp.dll.  Can't generate better stack crawls!");
    return 0;
}
