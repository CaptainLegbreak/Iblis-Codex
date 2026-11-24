#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2DrlgRooms.h"

struct D2DrlgActStrc;
struct D2Entry0061B7E0Strc;
struct D2Owner0061B7E0Strc;

struct D2Entry0061B7E0Strc
{
    unsigned char unk_00[0x1C];
    D2Entry0061B7E0Strc* pNext1C;
    unsigned char unk_20[0x10];
    int nValue30;
    unsigned char unk_34[0x10];
    unsigned char nIndex44;
    unsigned char unk_45[0xA3];
    D2Entry0061B7E0Strc* pSelfE8;
};

struct D2Owner0061B7E0Strc
{
    unsigned char unk_00[0xA0];
    D2Entry0061B7E0Strc pEntries[4];
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct); // 0x0061AA60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern D2EnvironmentCycleStrc gNormalEnvironmentCycle[]; // 0x007443F0
extern D2EnvironmentCycleStrc gAct4EnvironmentCycle[]; // 0x00744438
extern D2EnvironmentCycleStrc gEclipseEnvironmentCycle[]; // 0x00744480
static void ENVIRONMENT_UpdateLightIntensity(D2DrlgEnvironmentStrc* pEnvironment, int nLevelId, int nAct);

static inline D2Entry0061B7E0Strc* sub_0061B870_GetFirst(D2Owner0061B7E0Strc* pOwner, unsigned char nIndex)
{
    if (pOwner->pEntries[nIndex].pNext1C != &pOwner->pEntries[nIndex])
    {
        return pOwner->pEntries[nIndex].pNext1C;
    }
    return 0;
}

static inline int sub_0061B870_IsListHead(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pNext, unsigned char nIndex)
{
    return pNext == &pOwner->pEntries[nIndex];
}

static inline int sub_0061B870_IsStatus(D2Entry0061B7E0Strc* pEntry, int nStatus)
{
    if (pEntry->nIndex44 == nStatus)
    {
        return 1;
    }
    return 0;
}

// 0x0061B870
int __fastcall sub_0061B870_GetNextValue(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pEntry)
{
    unsigned char nIndex = pEntry->nIndex44;
    D2Entry0061B7E0Strc* pNext = pEntry->pNext1C;
    if (sub_0061B870_IsStatus(pEntry, 0) && sub_0061B870_IsListHead(pOwner, pNext, nIndex))
        pNext = sub_0061B870_GetFirst(pOwner, 1);
    return pNext ? pNext->nValue30 : 0;
}

static void __stdcall DRLGACTIVATE_ApplyArreatSummitLightColor(D2DrlgEnvironmentStrc* pRecord, int nId)
{
    if (nId == 0x78)
    {
        pRecord->nRed = 0xF5;
        pRecord->nGreen = 0xF0;
        pRecord->nBlue = 0xFF;
    }
}

// build: context ENVIRONMENT_UpdateLightIntensity
static void ENVIRONMENT_UpdateLightIntensity(D2DrlgEnvironmentStrc* pEnvironment, int nLevelId, int nAct)
{
    if (nAct == ACT_IV)
    {
        int nTargetIntensity = 16;
        switch (nLevelId)
        {
        case LEVEL_THEPANDEMONIUMFORTRESS:
            nTargetIntensity = 128;
            break;
        case LEVEL_OUTERSTEPPES:
            nTargetIntensity = 64;
            break;
        case LEVEL_PLAINSOFDESPAIR:
            nTargetIntensity = 56;
            break;
        case LEVEL_CITYOFTHEDAMNED:
            nTargetIntensity = 48;
            break;
        }

        if (pEnvironment->nIntensity < nTargetIntensity)
        {
            ++pEnvironment->nIntensity;
        }

        if (pEnvironment->nIntensity > nTargetIntensity)
        {
            --pEnvironment->nIntensity;
        }

        if (!pEnvironment->nIntensity)
        {
            pEnvironment->nIntensity = nTargetIntensity;
        }
    }
    else if (!pEnvironment->bEclipse)
    {
        if (nLevelId == LEVEL_ROCKYSUMMIT)
        {
            pEnvironment->nIntensity = 200;
        }
        else
        {
            const double dAngle = (double)pEnvironment->nTicks / (double)pEnvironment->nTimeRate / 180.0 * 3.14159265f;
            pEnvironment->fSin = (float)(pEnvironment->nTicks < ENV_HALF_CIRCLE_DEGREES * pEnvironment->nTimeRate
                ? (pEnvironment->fCos = (float)-cos(dAngle), sin(dAngle))
                : (pEnvironment->fCos = (float)-cos(dAngle), sin(dAngle) * 0.5));

            pEnvironment->fLast = 0.0f;
            const float& fSin = pEnvironment->fSin;
            pEnvironment->nIntensity = (int)(fSin * 128.0 + 128.0 + 0.5);
            int nTargetIntensity = 255;
            if (nAct == ACT_V)
            {
                nTargetIntensity = 170;
            }

            pEnvironment->nIntensity = (pEnvironment->nIntensity <= 0 ? 0 : pEnvironment->nIntensity) < nTargetIntensity ? (pEnvironment->nIntensity <= 0 ? 0 : pEnvironment->nIntensity) : nTargetIntensity;
        }
    }
    else
    {
        const int nEclipseLightIntensity = 32;
        if (pEnvironment->nIntensity > nEclipseLightIntensity)
        {
            pEnvironment->nIntensity -= 8;
        }

        if (pEnvironment->nIntensity < nEclipseLightIntensity)
        {
            pEnvironment->nIntensity = nEclipseLightIntensity;
        }
    }
}

static void __stdcall ENVIRONMENT_UpdateLightColor(int nAct, D2DrlgEnvironmentStrc* pEnvironment)
{
    const int nCycleIndex = pEnvironment->nCycleIndex;
    int nNextCycleIndex = nCycleIndex + 1;
    if (nNextCycleIndex == NUM_ENVIRONMENT_CYCLES)
    {
        nNextCycleIndex = 0;
    }

    const D2EnvironmentCycleStrc* pCurrEnvironmentCycle;
    const D2EnvironmentCycleStrc* pNextEnvironmentCycle;
    if (nAct == ACT_IV)
    {
        pCurrEnvironmentCycle = &gAct4EnvironmentCycle[nCycleIndex];
        pNextEnvironmentCycle = &gAct4EnvironmentCycle[nNextCycleIndex];
    }
    else if (!pEnvironment->bEclipse)
    {
        pCurrEnvironmentCycle = &gNormalEnvironmentCycle[nCycleIndex];
        pNextEnvironmentCycle = &gNormalEnvironmentCycle[nNextCycleIndex];
    }
    else
    {
        pCurrEnvironmentCycle = &gEclipseEnvironmentCycle[nCycleIndex];
        pNextEnvironmentCycle = &gEclipseEnvironmentCycle[nNextCycleIndex];
    }

    const int nCurrTicks = pEnvironment->nTimeRate * pCurrEnvironmentCycle->nTicksBegin;
    const double dLerpRatio = (double)(pEnvironment->nTicks - nCurrTicks) / (double)(pEnvironment->nTimeRate * pNextEnvironmentCycle->nTicksBegin - nCurrTicks);
    const int nGreen = (int)((pNextEnvironmentCycle->nGreen - pCurrEnvironmentCycle->nGreen) * dLerpRatio + 0.5);
    const int nBlue = (int)((pNextEnvironmentCycle->nBlue - pCurrEnvironmentCycle->nBlue) * dLerpRatio + 0.5);
    pEnvironment->nRed = pCurrEnvironmentCycle->nRed + (unsigned char)((pNextEnvironmentCycle->nRed - pCurrEnvironmentCycle->nRed) * dLerpRatio + 0.5);
    pEnvironment->nGreen = pCurrEnvironmentCycle->nGreen + nGreen;
    pEnvironment->nBlue = pCurrEnvironmentCycle->nBlue + nBlue;
}

static void ENVIRONMENT_SetCycleState(D2DrlgEnvironmentStrc* pEnvironment)
{
    const D2EnvironmentCycleStrc* pEnvironmentCycle = !pEnvironment->bEclipse ? &gNormalEnvironmentCycle[pEnvironment->nCycleIndex] : &gEclipseEnvironmentCycle[pEnvironment->nCycleIndex];
    pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
    pEnvironment->nTicks = pEnvironment->nTimeRate * pEnvironmentCycle->nTicksBegin;
}

D2DrlgEnvironmentStrc* __fastcall ENVIRONMENT_AllocDrlgEnvironment(void* pMemPool)
{
    D2DrlgEnvironmentStrc* pEnvironment = (D2DrlgEnvironmentStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgEnvironmentStrc), ".\\ENVIRONMENT\\Env.cpp", 298, 0);
    memset(pEnvironment, 0, sizeof(D2DrlgEnvironmentStrc));
    pEnvironment->nCycleIndex = ENVCYCLE_NOON;
    pEnvironment->nTimeRate = gnTimeRates[pEnvironment->nTimeRateIndex];
    const D2EnvironmentCycleStrc* pEnvironmentCycle = !pEnvironment->bEclipse ? &gNormalEnvironmentCycle[pEnvironment->nCycleIndex] : &gEclipseEnvironmentCycle[pEnvironment->nCycleIndex];
    pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
    pEnvironment->nTicks = pEnvironment->nTimeRate * pEnvironmentCycle->nTicksBegin;
    ENVIRONMENT_UpdateLightIntensity(pEnvironment, 0, 0);
    ENVIRONMENT_UpdateLightColor(0, pEnvironment);
    pEnvironment->unk0x14 = 0;
    pEnvironment->dwInitTick = GetTickCount();
    pEnvironment->bEclipse = 0;
    return pEnvironment;
}

static void ENVIRONMENT_UpdateTicks(D2DrlgEnvironmentStrc* pEnvironment, int nActNo)
{
    ++pEnvironment->nTicks;
    if (!pEnvironment->bEclipse)
    {
        if (nActNo == ACT_IV)
        {
            pEnvironment->nTicks += 15;
        }
        else if (gNormalEnvironmentCycle[pEnvironment->nCycleIndex].nPeriodOfDay == ENVPERIOD_NIGHT)
        {
            ++pEnvironment->nTicks;
            if (nActNo == ACT_III)
            {
                pEnvironment->nTicks += 8;
            }
        }
    }

    if (pEnvironment->nTicks >= ENV_FULL_CIRCLE_DEGREES * pEnvironment->nTimeRate)
    {
        pEnvironment->nTicks = 0;
    }

    int nNextEnvCycle = pEnvironment->nCycleIndex + 1;
    if (nNextEnvCycle >= NUM_ENVIRONMENT_CYCLES)
    {
        nNextEnvCycle = 0;
    }

    const D2EnvironmentCycleStrc* pNextEnvCycle;
    if (!pEnvironment->bEclipse)
    {
        pNextEnvCycle = &gNormalEnvironmentCycle[nNextEnvCycle];
    }
    else if (nActNo == ACT_IV)
    {
        pNextEnvCycle = &gAct4EnvironmentCycle[nNextEnvCycle];
    }
    else
    {
        pNextEnvCycle = &gEclipseEnvironmentCycle[nNextEnvCycle];
    }

    if (pEnvironment->nTicks > pEnvironment->nTimeRate * pNextEnvCycle->nTicksBegin)
    {
        if (++pEnvironment->nCycleIndex >= NUM_ENVIRONMENT_CYCLES)
        {
            pEnvironment->nCycleIndex = 0;
        }

        const D2EnvironmentCycleStrc* pEnvironmentCycle = !pEnvironment->bEclipse ? &gNormalEnvironmentCycle[pEnvironment->nCycleIndex] : &gEclipseEnvironmentCycle[pEnvironment->nCycleIndex];
        pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
        pEnvironment->nTicks = pEnvironment->nTimeRate * pEnvironmentCycle->nTicksBegin;
    }
}

int __stdcall ENVIRONMENT_UpdatePeriodOfDay(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    const int nPreviousPeriodOfDay = pEnvironment->nPeriodOfDay;
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    const int nActNo = DRLG_GetActNoFromLevelId(nLevelId);
    ENVIRONMENT_UpdateTicks(pEnvironment, nActNo);
    ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nActNo);
    ENVIRONMENT_UpdateLightColor(nActNo, pEnvironment);
    DRLGACTIVATE_ApplyArreatSummitLightColor(pEnvironment, nLevelId);
    return nPreviousPeriodOfDay != pEnvironment->nPeriodOfDay;
}

int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (!pEnvironment)
    {
        return 0;
    }

    const int nOldCycleIndex = pEnvironment->nCycleIndex;
    const int nOldPeriodOfDay = pEnvironment->nPeriodOfDay;
    ENVIRONMENT_UpdateTicks(pEnvironment, nActNo);
    if (pEnvironment->nTimeRate)
    {
        const int nNext = pEnvironment->nTicks / pEnvironment->nTimeRate;
        int nDiff = nNext - pEnvironment->nPrev;
        if (nDiff < 0)
        {
            nDiff = -nDiff;
        }

        if (nDiff > 16)
        {
            pEnvironment->nPrev = nNext;
            return 1;
        }
    }

    if (nOldPeriodOfDay != pEnvironment->nPeriodOfDay || nOldCycleIndex != pEnvironment->nCycleIndex)
    {
        return 1;
    }

    return 0;
}

void __stdcall ENVIRONMENT_NextEnvCycle(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (++pEnvironment->nCycleIndex >= NUM_ENVIRONMENT_CYCLES)
    {
        pEnvironment->nCycleIndex = 0;
    }

    const D2EnvironmentCycleStrc* pEnvironmentCycle = !pEnvironment->bEclipse ? &gNormalEnvironmentCycle[pEnvironment->nCycleIndex] : &gEclipseEnvironmentCycle[pEnvironment->nCycleIndex];
    pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
    pEnvironment->nTicks = pEnvironmentCycle->nTicksBegin * pEnvironment->nTimeRate;
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    const int nActNo = DRLG_GetActNoFromLevelId(nLevelId);
    ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nActNo);
    ENVIRONMENT_UpdateLightColor(nActNo, pEnvironment);
    DRLGACTIVATE_ApplyArreatSummitLightColor(pEnvironment, nLevelId);
}

void __stdcall ENVIRONMENT_InitializeEnvironment(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom, int nIndex, int nTicks, int bEclipse)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    D2_ASSERT(nIndex >= 0, 528);
    D2_ASSERT(nIndex < NUM_ENVIRONMENT_CYCLES, 529);
    D2_ASSERT(nTicks >= 0, 530);
    if (nTicks > ENV_FULL_CIRCLE_DEGREES * pEnvironment->nTimeRate)
    {
        nTicks = 0;
    }

    pEnvironment->nCycleIndex = nIndex;
    pEnvironment->nTicks = nTicks;
    const D2EnvironmentCycleStrc* pEnvironmentCycle = !bEclipse ? &gNormalEnvironmentCycle[nIndex] : &gEclipseEnvironmentCycle[nIndex];
    pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    const int nAct = DRLG_GetActNoFromLevelId(nLevelId);
    ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nAct);
    pEnvironment->bEclipse = bEclipse;
    if (bEclipse)
    {
        ENVIRONMENT_SetCycleState(pEnvironment);
        ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nAct);
        ENVIRONMENT_UpdateLightColor(nAct, pEnvironment);
    }

    DRLGACTIVATE_ApplyArreatSummitLightColor(pEnvironment, nLevelId);
}

void __stdcall ENVIRONMENT_SetNextTimeRate(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061C3B0

void __stdcall ENVIRONMENT_TaintedSunBegin(D2DrlgActStrc* pAct)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    pEnvironment->nTimeRateIndex = 1;
    pEnvironment->nTimeRate = gnTimeRates[1];
    ENVIRONMENT_InitializeEnvironment(pAct, 0, ENVCYCLE_SUNRISE, 0, 1);
}

void __stdcall ENVIRONMENT_TaintedSunEnd(D2DrlgActStrc* pAct)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    pEnvironment->nTimeRateIndex = 0;
    pEnvironment->nTimeRate = gnTimeRates[0];
    ENVIRONMENT_InitializeEnvironment(pAct, 0, ENVCYCLE_NOON, 0, 0);
}
