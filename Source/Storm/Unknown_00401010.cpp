#include "Storm.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __int64 __cdecl _time64(__int64* pTime);                                                        // 0x0068568B
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern void* gpfnSymCleanup_0098A6B8;                                                                       // 0x0098A6B8
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
extern char gszLogDirectory_00992708[0x400];                                                                // 0x00992708

static __forceinline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

// 0x00401010
__int64 __cdecl sub_00401010_GetTime64()
{
    return _time64(0);
}

// 0x00401020
static __forceinline bool sub_00401020_SetLogDirectory(const char* szPath)
{
    return StrLCopy(gszLogDirectory_00992708, szPath, 0x400) < 0x400 ? true : false;
}

// build: context sub_M123_Emit_00401020
bool sub_M123_Emit_00401020(const char* szPath)
{
    return sub_00401020_SetLogDirectory(szPath);
}

// 0x004016B0
void __cdecl sub_004016B0_Nothing()
{
}

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// 0x00401C80
void __cdecl sub_00401C80_FreeDbgHelp()
{
    if (gbSymInitialized_0098A6B0)
    {
        if (ghDbgHelp_0098A680)
        {
            FreeLibrary(ghDbgHelp_0098A680);
            ghDbgHelp_0098A680 = 0;
        }
    }
}

// 0x00401DD0
void __cdecl sub_00401DD0_CleanupSymbols()
{
    if (gbSymInitialized_0098A6B0)
    {
        ((SymCleanupFn)gpfnSymCleanup_0098A6B8)(ghProcess_0074C6F0);
        gbSymInitialized_0098A6B0 = false;
    }
}
