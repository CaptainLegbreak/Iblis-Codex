#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* EnumerateLoadedModules64Fn)(void* hProcess, void* pfnCallback, void* pContext);
extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern EnumerateLoadedModules64Fn gpfnEnumerateLoadedModules64;                                    // 0x0098A6A4
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004021D0
bool __stdcall sub_004021D0_EnumerateModules(void* pfnCallback, void* pContext)
{
    D2SymbolLockGuardStrc tGuard;
    if (!ghDbgHelp && !sub_00401B00_LoadDbgHelp())
        return false;
    if (!gpfnEnumerateLoadedModules64)
        return false;
    return gpfnEnumerateLoadedModules64(ghProcess, pfnCallback, pContext) != 0;
}
