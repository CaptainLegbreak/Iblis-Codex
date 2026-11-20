#include "D2GameTypes.h"
#include "D2CrashTypes.h"

typedef int (__stdcall* SymGetModuleInfo64Fn)(void* hProcess, unsigned __int64 qwAddr, D2ImagehlpModule64Strc* pModuleInfo);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

extern void* ghProcess_0074C6F0;                                                                            // 0x0074C6F0
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern SymGetModuleInfo64Fn gpfnSymGetModuleInfo64_0098A684;                                                // 0x0098A684
extern bool gbSymInitialized_0098A6B0;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0

static __declspec(noinline) bool __stdcall sub_00401DF0_GetModuleFromAddr(unsigned long dwAddress, unsigned long* pdwBase, char* szModule);

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00401DF0
static bool __stdcall sub_00401DF0_GetModuleFromAddr(unsigned long dwAddress, unsigned long* pdwBase, char* szModule)
{
    szModule[0] = 0;
    *pdwBase = 0;
    D2SymbolLockGuardStrc tLock;

    if ((ghDbgHelp_0098A680 || sub_00401B00_LoadDbgHelp()) && (gbSymInitialized_0098A6B0 || sub_00401CB0_InitSymbols()))
    {
        SymGetModuleInfo64Fn pfnGetModuleInfo = gpfnSymGetModuleInfo64_0098A684;
        if (pfnGetModuleInfo)
        {
            D2ImagehlpModule64Strc tInfo;
            memset(&tInfo, 0, sizeof(tInfo));
            tInfo.SizeOfStruct = sizeof(D2ImagehlpModule64Strc);
            if (pfnGetModuleInfo(ghProcess_0074C6F0, dwAddress, &tInfo))
            {
                if (GetModuleHandleA(tInfo.LoadedImageName))
                    *pdwBase = (unsigned long)tInfo.BaseOfImage;
                strncpy_s(szModule, 0x100, tInfo.ImageName, (unsigned int)-1);
                return true;
            }
        }
    }
    return false;
}

// build: context sub_00401DF0_Shim
// calling-convention shim (not game code)
unsigned long __stdcall sub_00401DF0_Shim(unsigned long dwAddress, char* szOut)
{
    __declspec(align(8)) char szName[0x104];
    unsigned long dwBase = 0;
    if (sub_00401DF0_GetModuleFromAddr(dwAddress, &dwBase, szName))
        strncpy_s(szOut, 0x40, szName, (unsigned int)-1);
    return dwBase;
}
