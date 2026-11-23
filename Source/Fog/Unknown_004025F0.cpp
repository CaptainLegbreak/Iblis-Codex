#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* StackWalk64Fn)(unsigned long dwMachineType, void* hProcess, void* hThread, void* pStackFrame,
    void* pContextRecord, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase,
    void* pfnTranslateAddress);
extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern void* gpfnSymFunctionTableAccess64;                                                         // 0x0098A698
extern void* gpfnSymGetModuleBase64;                                                               // 0x0098A69C
extern StackWalk64Fn gpfnStackWalk64;                                                              // 0x0098A6A0
extern bool gbSymInitialized;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004025F0
bool __stdcall sub_004025F0_StackWalk(void* hThread, void* pStackFrame, void* pContextRecord)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized || sub_00401CB0_InitSymbols())
        && gpfnStackWalk64 && gpfnSymFunctionTableAccess64 && gpfnSymGetModuleBase64)
        return gpfnStackWalk64(0x14C, ghProcess, hThread, pStackFrame, pContextRecord, 0,
            gpfnSymFunctionTableAccess64, gpfnSymGetModuleBase64, 0) != 0;
    return false;
}
