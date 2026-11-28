#include "D2Common.h"
#include "D2ProfileCounter.h"
#include "FogApi.h"

struct D2GameStrc;
struct D2ProfileCounterStrc;

typedef int (__cdecl* PROFHOOK0096BC24FN)();

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800
void __cdecl LOGGING_CloseLog(); // 0x00624B20

extern PROFHOOK0096BC24FN gpfnProfSecondaryHook; // 0x0096BC24

typedef void(__stdcall* PROFHOOKFN)(int nA, char* pBuffer, int nC);
extern PROFHOOKFN gpfnProfHook; // 0x0096BC28
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pnCount); // 0x006CC25C
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254
PROFHOOK0096BC24FN gpfnProfSecondaryHook; // 0x0096BC24

// 0x006115F0
void __cdecl sub_006115F0_Empty()
{
}

// 0x00611600
void __cdecl PROFCORE_CloseLog()
{
    LOGGING_CloseLog();
}

// 0x00611620
void __fastcall PROFCORE_CallProfHook(int nA, char* pBuffer, int nC)
{
    PROFHOOKFN pfnHook = gpfnProfHook;
    *pBuffer = 0;
    if (pfnHook)
        pfnHook(nA, pBuffer, nC);
}

// 0x00611650
int __cdecl PROFCORE_CallSecondaryHook()
{
    if (gpfnProfSecondaryHook)
    {
        return gpfnProfSecondaryHook();
    }
    return 0;
}

// 0x00611660
void __fastcall PROFCORE_AddSample(int nIndex, __int64 nStart)
{
    __int64 nNow;
    QueryPerformanceCounter(&nNow);
    gaProfEntries[nIndex].nTotal += nNow - nStart;
    gaProfEntries[nIndex].nCount++;
}

// 0x006116B0
void __cdecl PROFCORE_WriteProfileCounters()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x4E, "PROFILING DUMP FREQUENCY %d:\n", nFrequency);
    for (int i = 0; i < 23; i++)
        LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x54, "FUNCTION: %30s, TIME %12d, COUNT %5d", gaProfEntries[i].szName,
            (int)gaProfEntries[i].nTotal, gaProfEntries[i].nCount);
}

// 0x00611730
void __cdecl PROFCORE_DumpAndResetProfile()
{
    PROFCORE_WriteProfileCounters();
    for (int i = 0; i < 23; i++)
    {
        gaProfEntries[i].nTotal = 0;
        gaProfEntries[i].nCount = 0;
    }
}

#include "gen/data/Source/D2Common/Logging/ProfCore.inc"
#include "D2CommonApi.h"
