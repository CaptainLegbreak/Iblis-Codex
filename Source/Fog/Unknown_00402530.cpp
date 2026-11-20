#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* SymUnloadModule64Fn)(void* hProcess, unsigned __int64 qwBaseOfDll);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern SymUnloadModule64Fn gpfnSymUnloadModule64_0098A694;                                                  // 0x0098A694
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402530
int __stdcall sub_00402530_UnloadModule(unsigned __int64 qwBaseOfDll)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp_0098A680 || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized_0098A6B0 || sub_00401CB0_InitSymbols())
        && gpfnSymUnloadModule64_0098A694)
        return gpfnSymUnloadModule64_0098A694(ghProcess_0074C6F0, qwBaseOfDll) != 0;
    return 0;
}
