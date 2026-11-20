#include "D2CrashTypes.h"
struct D2CriticalSectionStrc { int a[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* SymCleanupFn)(void* hProcess);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
extern SymCleanupFn gpfnSymCleanup_0098A6B8;                                                                // 0x0098A6B8
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402AE0
void __cdecl sub_00402AE0_ShutdownSymbols()
{
    D2SymbolLockGuardStrc tGuard;
    if (gbSymInitialized_0098A6B0)
    {
        gpfnSymCleanup_0098A6B8(ghProcess_0074C6F0);
        gbSymInitialized_0098A6B0 = false;
    }
}
