#include "D2Common.h"

struct D2GameStrc;
struct D2ProfileCounterStrc;

struct D2ProfileCounterStrc
{
    char szName[0x68];
    __int64 nTotal;
    int nCount;
    int f_74;
};

typedef int (__cdecl* PROFHOOK0096BC24FN)();

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800
void __cdecl sub_006116B0_WriteProfileCounters(); // 0x006116B0
void __cdecl sub_00624B20_CloseLog(); // 0x00624B20
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC
extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C
extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

extern PROFHOOK0096BC24FN gpfnHook_0096BC24; // 0x0096BC24

typedef void(__stdcall* PROFHOOKFN)(int nA, char* pBuffer, int nC);
extern PROFHOOKFN gpfnProfHook; // 0x0096BC28
void __cdecl LOG_11100(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pnCount); // 0x006CC25C
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254
// 0x00611600
void __cdecl sub_00611600_CloseLogTail()
{
    sub_00624B20_CloseLog();
}

// 0x00611620
void __fastcall sub_00611620_ClearAndCallHook(int nA, char* pBuffer, int nC)
{
    PROFHOOKFN pfnHook = gpfnProfHook;
    *pBuffer = 0;
    if (pfnHook)
        pfnHook(nA, pBuffer, nC);
}

// 0x00611650
int __cdecl sub_00611650_CallHook0096BC24()
{
    if (gpfnHook_0096BC24)
    {
        return gpfnHook_0096BC24();
    }
    return 0;
}

// 0x00611660
void __fastcall sub_00611660_AddSample(int nIndex, __int64 nStart)
{
    __int64 nNow;
    QueryPerformanceCounter(&nNow);
    gaProfEntries[nIndex].nTotal += nNow - nStart;
    gaProfEntries[nIndex].nCount++;
}

// 0x006116B0
void __cdecl sub_006116B0_WriteProfileCounters()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x4E, "PROFILING DUMP FREQUENCY %d:\n", nFrequency);
    for (int i = 0; i < 23; i++)
        LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x54, "FUNCTION: %30s, TIME %12d, COUNT %5d", gaProfEntries[i].szName,
            (int)gaProfEntries[i].nTotal, gaProfEntries[i].nCount);
}

// 0x00611730
void __cdecl sub_00611730_DumpAndResetProfile()
{
    sub_006116B0_WriteProfileCounters();
    for (int i = 0; i < 23; i++)
    {
        gaProfEntries[i].nTotal = 0;
        gaProfEntries[i].nCount = 0;
    }
}
