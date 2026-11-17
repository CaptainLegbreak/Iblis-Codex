struct D2CriticalSectionStrc { int a[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2
typedef int (__stdcall* SymSetSearchPathFn)(void* hProcess, const char* szSearchPath);
extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern SymSetSearchPathFn gpfnSymSetSearchPath_0098A690;                                                    // 0x0098A690
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
extern char gszSymSearchPath_0098A708[];                                                                    // 0x0098A708
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

// 0x00402280
int __fastcall sub_00402280_SetSearchPath(const char* szSearchPath)
{
    D2SymbolLockGuardStrc tGuard;
    strncpy_s(gszSymSearchPath_0098A708, 0x8000, szSearchPath, (unsigned int)-1);
    if (!gbSymInitialized_0098A6B0)
        return 1;
    if ((ghDbgHelp_0098A680 || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized_0098A6B0 || sub_00401CB0_InitSymbols())
        && gpfnSymSetSearchPath_0098A690)
        return gpfnSymSetSearchPath_0098A690(ghProcess_0074C6F0, szSearchPath);
    return 0;
}
