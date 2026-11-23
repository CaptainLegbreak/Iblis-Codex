#include "Fog.h"
#include "D2GameTypes.h"


extern "C" __int64 __cdecl _time64(__int64* pTime);                                                        // 0x0068568B
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern void* gpfnSymCleanup;                                                                       // 0x0098A6B8
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
extern char gszLogDirectory[0x400];                                                                // 0x00992708

static inline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
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
static inline bool sub_00401020_SetLogDirectory(const char* szPath)
{
    return StrLCopy(gszLogDirectory, szPath, 0x400) < 0x400 ? true : false;
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
    LeaveCriticalSection(&gtSymbolLock);
}

// 0x00401C80
void __cdecl sub_00401C80_FreeDbgHelp()
{
// build: symbol ?gbSymInitialized@* 0x0098A6B0
    if (gbSymInitialized)
    {
// build: symbol ?ghDbgHelp@* 0x0098A680
        if (ghDbgHelp)
        {
            FreeLibrary(ghDbgHelp);
            ghDbgHelp = 0;
        }
    }
}

// 0x00401DD0
void __cdecl sub_00401DD0_CleanupSymbols()
{
    if (gbSymInitialized)
    {
// build: symbol ?ghProcess@* 0x0074C6F0
        ((SymCleanupFn)gpfnSymCleanup)(ghProcess);
        gbSymInitialized = false;
    }
}
