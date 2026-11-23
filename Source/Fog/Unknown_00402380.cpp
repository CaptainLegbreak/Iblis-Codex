#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* FindFileInPathCallbackFn)(int nUnused1, int nUnused2);
typedef int (__stdcall* SymFindFileInPathFn)(void* hProcess, const char* szSearchPath, const char* szFileName,
    void* pId, unsigned int nTwo, unsigned int nThree, unsigned int nFlags, char* szFoundFile,
    FindFileInPathCallbackFn pfnCallback, void* pContext);
extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern bool gbSymInitialized;                                                                      // 0x0098A6B0
extern SymFindFileInPathFn gpfnSymFindFileInPath;                                                  // 0x0098A6EC
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0
int __stdcall sub_00402370(int nUnused1, int nUnused2);                                                     // 0x00402370

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402380
int __fastcall sub_00402380_FindFileInPath(FindFileInPathCallbackFn pfnCallback, int nUnused, const char* szSearchPath,
    const char* szFileName, void* pId, unsigned int nTwo, unsigned int nThree, unsigned int nFlags, char* szFoundFile,
    void* pContext)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized || sub_00401CB0_InitSymbols())
        && gpfnSymFindFileInPath)
        return gpfnSymFindFileInPath(ghProcess, szSearchPath, szFileName, pId, nTwo, nThree, nFlags,
            szFoundFile, pfnCallback ? pfnCallback : sub_00402370, pContext);
    return 0;
}
