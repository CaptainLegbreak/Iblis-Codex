struct D2CriticalSectionStrc { int a[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* StackWalk64Fn)(unsigned long dwMachineType, void* hProcess, void* hThread, void* pStackFrame,
    void* pContextRecord, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase,
    void* pfnTranslateAddress);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern void* gpfnSymFunctionTableAccess64_0098A698;                                                         // 0x0098A698
extern void* gpfnSymGetModuleBase64_0098A69C;                                                               // 0x0098A69C
extern StackWalk64Fn gpfnStackWalk64_0098A6A0;                                                              // 0x0098A6A0
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
struct D2SymbolLockGuardStrc
{
    D2SymbolLockGuardStrc() { EnterCriticalSection(&gtSymbolLock_0098A6F0); }
    ~D2SymbolLockGuardStrc() { LeaveCriticalSection(&gtSymbolLock_0098A6F0); }
};

// 0x004025F0
bool __stdcall sub_004025F0_StackWalk(void* hThread, void* pStackFrame, void* pContextRecord)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp_0098A680 || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized_0098A6B0 || sub_00401CB0_InitSymbols())
        && gpfnStackWalk64_0098A6A0 && gpfnSymFunctionTableAccess64_0098A698 && gpfnSymGetModuleBase64_0098A69C)
        return gpfnStackWalk64_0098A6A0(0x14C, ghProcess_0074C6F0, hThread, pStackFrame, pContextRecord, 0,
            gpfnSymFunctionTableAccess64_0098A698, gpfnSymGetModuleBase64_0098A69C, 0) != 0;
    return false;
}
