#include "D2CrashTypes.h"
struct D2CriticalSectionStrc { int a[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* EnumerateLoadedModules64Fn)(void* hProcess, void* pfnCallback, void* pContext);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern EnumerateLoadedModules64Fn gpfnEnumerateLoadedModules64_0098A6A4;                                    // 0x0098A6A4
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004021D0
bool __stdcall sub_004021D0_EnumerateModules(void* pfnCallback, void* pContext)
{
    D2SymbolLockGuardStrc tGuard;
    if (!ghDbgHelp_0098A680 && !sub_00401B00_LoadDbgHelp())
        return false;
    if (!gpfnEnumerateLoadedModules64_0098A6A4)
        return false;
    return gpfnEnumerateLoadedModules64_0098A6A4(ghProcess_0074C6F0, pfnCallback, pContext) != 0;
}
