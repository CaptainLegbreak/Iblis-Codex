#include "D2Common.h"
#include "D2Drlg.h"

struct D2DrlgActStrc;

struct D2DrlgEnvironmentStrc
{
    int nCycleIndex;
    int nPeriodOfDay;
    int nTicks;
    int nIntensity;
    unsigned int dwInitTick;
    int unk0x14;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char pad0x1B;
    float fCos;
    float fLast;
    float fSin;
    int nTimeRate;
    int nTimeRateIndex;
    int bEclipse;
    int nPrev;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0066BCF0
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct);                       // 0x0061AA60
int gStatsClientAllocatedRooms;                                                                             // 0x0096C8B8
int gStatsClientFreedRooms;                                                                                 // 0x0096C8BC
int gStatsFreedRooms;                                                                                       // 0x0096C8C0
int gStatsAllocatedRooms;                                                                                   // 0x0096C8C4
#define ROOMFLAG_1 0x00000001

// 0x0061C0B0
void __stdcall ENVIRONMENT_GetLightColorFromAct(D2DrlgActStrc* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct))
    {
        *pRed = pEnvironment->nRed;
        *pGreen = pEnvironment->nGreen;
        *pBlue = pEnvironment->nBlue;
    }
}

// 0x0061C0E0
int __stdcall ENVIRONMENT_GetIntensityFromAct(D2DrlgActStrc* pAct)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (!pEnvironment)
    {
        return 0;
    }

    return pEnvironment->nIntensity;
}

// 0x0061C160
int __stdcall ENVIRONMENT_GetUnusedMember(D2DrlgActStrc* pAct)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (!pEnvironment)
    {
        return 0;
    }

    return pEnvironment->unk0x14;
}

// 0x0061C220
int __stdcall ENVIRONMENT_GetCycleIndexFromAct(D2DrlgActStrc* pAct)
{
    return DUNGEON_GetEnvironmentFromAct(pAct)->nCycleIndex;
}

// 0x0061C330
void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);

    *pCycleIndex = pEnvironment->nCycleIndex;
    *pTicks = pEnvironment->nTicks;
    *pEclipse = pEnvironment->bEclipse;
}

// 0x0061C360
void __stdcall ENVIRONMENT_GetStatistics(D2DrlgActStrc* pAct, float* pCos, float* pLast, float* pSin, int* a5)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);

    *pCos = pEnvironment->fCos;
    *pLast = pEnvironment->fLast;
    *pSin = pEnvironment->fSin;

    *a5 = 0;
}
