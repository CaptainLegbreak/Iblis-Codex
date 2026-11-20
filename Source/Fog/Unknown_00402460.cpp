#include "D2CrashTypes.h"
struct D2CriticalSectionStrc { int a[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef unsigned __int64 (__stdcall* SymLoadModule64Fn)(void* hProcess, void* hFile, const char* szImageName,
    const char* szModuleName, unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
extern SymLoadModule64Fn gpfnSymLoadModule64_0098A6DC;                                                      // 0x0098A6DC
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2
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

static __declspec(noinline) unsigned __int64 __stdcall sub_00402460_LoadModule(void* hFile, const char* szImageName,
    const char* szModuleName, unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll);

// 0x00402460
static unsigned __int64 __stdcall sub_00402460_LoadModule(void* hFile, const char* szImageName, const char* szModuleName,
    unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp_0098A680 || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized_0098A6B0 || sub_00401CB0_InitSymbols())
        && gpfnSymLoadModule64_0098A6DC)
        return gpfnSymLoadModule64_0098A6DC(ghProcess_0074C6F0, hFile, szImageName, szModuleName, qwBaseOfDll, dwSizeOfDll);
    return 0;
}

// build: context sub_00402460_Shim
// calling-convention shim (not game code)
unsigned long __stdcall sub_00402460_Shim(void* hFile, const char* szImageName, const char* szModuleName,
    unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll)
{
    __declspec(align(8)) char szName[0x104];
    strncpy_s(szName, 0x104, szModuleName, (unsigned int)-1);
    return (unsigned long)sub_00402460_LoadModule(hFile, szImageName, szName, qwBaseOfDll, dwSizeOfDll);
}
