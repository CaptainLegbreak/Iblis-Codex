#include "D2GameTypes.h"
#include "D2CrashTypes.h"

typedef int (__stdcall* SymGetLineFromAddr64Fn)(void* hProcess, unsigned __int64 qwAddr, unsigned long* pdwDisplacement, D2ImagehlpLine64Strc* pLine);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern bool gbSymInitialized;                                                                      // 0x0098A6B0
extern SymGetLineFromAddr64Fn gpfnSymGetLineFromAddr64;                                            // 0x0098A6E8
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0

static inline bool sub_EnsureSymbolEngine()
{
    if (!ghDbgHelp && !sub_00401B00_LoadDbgHelp())
        return false;
    if (!gbSymInitialized && !sub_00401CB0_InitSymbols())
        return false;
    return true;
}

static bool __stdcall sub_004020D0_GetLineFromAddr(unsigned long dwAddress, char* szFile, unsigned long* pLineNumber);

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004020D0
static bool __stdcall sub_004020D0_GetLineFromAddr(unsigned long dwAddress, char* szFile, unsigned long* pLineNumber)
{
    unsigned long dwDisplacement;
    szFile[0] = 0;
    *pLineNumber = 0;
    D2SymbolLockGuardStrc tLock;

    if (sub_EnsureSymbolEngine())
    {
        SymGetLineFromAddr64Fn pfnGetLine = gpfnSymGetLineFromAddr64;
        if (pfnGetLine)
        {
            D2ImagehlpLine64Strc tLine;
            memset(&tLine, 0, sizeof(tLine));
            tLine.SizeOfStruct = sizeof(D2ImagehlpLine64Strc);
            if (pfnGetLine(ghProcess, dwAddress, &dwDisplacement, &tLine))
            {
                strncpy_s(szFile, 0x100, tLine.FileName, (unsigned int)-1);
                *pLineNumber = tLine.LineNumber;
                return true;
            }
        }
    }
    return false;
}

// build: context sub_004020D0_Shim
// calling-convention shim (not game code)
void __stdcall sub_004020D0_Shim(unsigned long dwAddress, char* szOut, unsigned long* pLineNumber)
{
    __declspec(align(8)) char szName[0x104];
    sub_004020D0_GetLineFromAddr(dwAddress, szName, pLineNumber);
    strncpy_s(szOut, 0x100, szName, (unsigned int)-1);
}
