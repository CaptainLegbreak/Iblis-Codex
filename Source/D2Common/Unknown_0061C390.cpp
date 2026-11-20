#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2Unicode.h"

struct Act;
struct D2DrlgActStrc;
struct Environment;
struct D2DrlgEnvironmentStrc;
struct D2EnvironmentCycleStrc;
struct Unicode;
struct D2BinFieldStrc;
struct D2LevelsTxt;

struct Environment { char pad[0x28]; int timeFields[2]; };

Environment* __fastcall sub_0061AA60(Act*); // 0x0061AA60

enum { TIME_RATE_FIELD = 0 };

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
    unsigned char unk0x1B;
    float fCos;
    float fLast;
    float fSin;
    int nTimeRate;
    int nTimeRateIndex;
    int bEclipse;
    int nPrev;
};

struct D2EnvironmentCycleStrc
{
    int nTicksBegin;
    int nPeriodOfDay;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char unk0x0B;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
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
static void ENVIRONMENT_UpdateLightIntensity(D2DrlgEnvironmentStrc* pEnvironment, int nLevelId, int nAct); // 0x0061BB80


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2LevelsTxt
{
    unsigned short wLevelNo;
    unsigned char nPal;
    unsigned char nAct;
    unsigned char nTeleport;
    unsigned char nRain;
    unsigned char nMud;
    unsigned char nNoPer;
    unsigned char nIsInside;
    unsigned char nDrawEdges;
    unsigned short unk0x0A;
    unsigned int dwWarpDist;
    unsigned short wMonLvl[3];
    unsigned short wMonLvlEx[3];
    unsigned int dwMonDen[3];
    unsigned char nMonUMin[3];
    unsigned char nMonUMax[3];
    unsigned char nMonWndr;
    unsigned char nMonSpcWalk;
    unsigned char nQuest;
    unsigned char nRangedSpawn;
    unsigned char nNumMon;
    unsigned char nNumNormalMonsters;
    unsigned char nNumNightmareHellMonsters;
    unsigned char nNumUniqueMonsters;
    short wNormalMonsters[25];
    short wNightmareHellMonsters[25];
    short wUniqueMonsters[25];
    unsigned short wCMon[4];
    unsigned short wCPct[4];
    unsigned short wCAmt[4];
    unsigned char nWaypoint;
    unsigned char nObjGroup[8];
    unsigned char nObjPrb[8];
    char szLevelName[40];
    char szLevelWarp[40];
    char szEntryFile[40];
    unsigned char pad0x16D;
    Unicode wszLevelName[40];
    Unicode wszLevelWarp[40];
    unsigned short pad0x20E;
    unsigned int dwThemes;
    unsigned int dwFloorFilter;
    unsigned int dwBlankScreen;
    unsigned int dwSoundEnv;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_NAMETOWORD = 20,
};
extern D2DataTablesStrc sgtDataTables; // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey); // 0x00524E20

// 0x0061C390
int __stdcall sub_0061C390(Act* act)
{
    return sub_0061AA60(act)->timeFields[TIME_RATE_FIELD];
}

static void __stdcall sub_0061BB60_SetColorForId(D2DrlgEnvironmentStrc* pRecord, int nId)
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
            if (pEnvironment->nTicks < ENV_HALF_CIRCLE_DEGREES * pEnvironment->nTimeRate)
            {
                pEnvironment->fCos = (float)-cos(dAngle);
                pEnvironment->fSin = (float)sin(dAngle);
            }
            else
            {
                pEnvironment->fCos = (float)-cos(dAngle);
                pEnvironment->fSin = (float)(sin(dAngle) * 0.5);
            }

            pEnvironment->fLast = 0.0f;
            pEnvironment->nIntensity = (int)(pEnvironment->fSin * 128.0 + 128.0 + 0.5);
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

// 0x0061BCE0
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

static void sub_0061BDF0_SetCycleState(D2DrlgEnvironmentStrc* pEnvironment)
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
    sub_0061BB60_SetColorForId(pEnvironment, nLevelId);
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

// 0x0061C180
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
    sub_0061BB60_SetColorForId(pEnvironment, nLevelId);
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
        sub_0061BDF0_SetCycleState(pEnvironment);
        ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nAct);
        ENVIRONMENT_UpdateLightColor(nAct, pEnvironment);
    }

    sub_0061BB60_SetColorForId(pEnvironment, nLevelId);
}

// 0x0061C3B0
void __stdcall ENVIRONMENT_SetNextTimeRate(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2DrlgEnvironmentStrc* pEnvironment = DUNGEON_GetEnvironmentFromAct(pAct);
    if (++pEnvironment->nTimeRateIndex >= NUM_TIME_RATES)
    {
        pEnvironment->nTimeRateIndex = 0;
    }

    const int nTimeRate = gnTimeRates[pEnvironment->nTimeRateIndex];
    pEnvironment->nTimeRate = nTimeRate;
    const D2EnvironmentCycleStrc* pEnvironmentCycle = !pEnvironment->bEclipse ? &gNormalEnvironmentCycle[pEnvironment->nCycleIndex] : &gEclipseEnvironmentCycle[pEnvironment->nCycleIndex];
    pEnvironment->nPeriodOfDay = pEnvironmentCycle->nPeriodOfDay;
    pEnvironment->nTicks = pEnvironmentCycle->nTicksBegin * nTimeRate;
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    const int nActNo = DRLG_GetActNoFromLevelId(nLevelId);
    ENVIRONMENT_UpdateLightIntensity(pEnvironment, nLevelId, nActNo);
    ENVIRONMENT_UpdateLightColor(nActNo, pEnvironment);
    sub_0061BB60_SetColorForId(pEnvironment, nLevelId);
}

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

// 0x0061C530
int __cdecl sub_0061C530_GetLvlPrestTxtRecordCount()
{
    return sgptDataTables->nLvlPrestTxtRecordCount;
}

// 0x0061C540
void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", TXTFIELD_BYTE, 0, 0, 0 },
        { "Pal", TXTFIELD_BYTE, 0, 2, 0 },
        { "Act", TXTFIELD_BYTE, 0, 3, 0 },
        { "Teleport", TXTFIELD_BYTE, 0, 4, 0 },
        { "Rain", TXTFIELD_BYTE, 0, 5, 0 },
        { "Mud", TXTFIELD_BYTE, 0, 6, 0 },
        { "NoPer", TXTFIELD_BYTE, 0, 7, 0 },
        { "IsInside", TXTFIELD_BYTE, 0, 8, 0 },
        { "DrawEdges", TXTFIELD_BYTE, 0, 9, 0 },
        { "WarpDist", TXTFIELD_DWORD, 0, 12, 0 },
        { "MonLvl1", TXTFIELD_WORD, 0, 16, 0 },
        { "MonLvl2", TXTFIELD_WORD, 0, 18, 0 },
        { "MonLvl3", TXTFIELD_WORD, 0, 20, 0 },
        { "MonLvl1Ex", TXTFIELD_WORD, 0, 22, 0 },
        { "MonLvl2Ex", TXTFIELD_WORD, 0, 24, 0 },
        { "MonLvl3Ex", TXTFIELD_WORD, 0, 26, 0 },
        { "MonDen", TXTFIELD_DWORD, 0, 28, 0 },
        { "MonDen(N)", TXTFIELD_DWORD, 0, 32, 0 },
        { "MonDen(H)", TXTFIELD_DWORD, 0, 36, 0 },
        { "MonUMin", TXTFIELD_BYTE, 0, 40, 0 },
        { "MonUMax", TXTFIELD_BYTE, 0, 43, 0 },
        { "MonUMin(N)", TXTFIELD_BYTE, 0, 41, 0 },
        { "MonUMax(N)", TXTFIELD_BYTE, 0, 44, 0 },
        { "MonUMin(H)", TXTFIELD_BYTE, 0, 42, 0 },
        { "MonUMax(H)", TXTFIELD_BYTE, 0, 45, 0 },
        { "MonWndr", TXTFIELD_BYTE, 0, 46, 0 },
        { "MonSpcWalk", TXTFIELD_BYTE, 0, 47, 0 },
        { "ObjGrp0", TXTFIELD_BYTE, 0, 229, 0 },
        { "ObjGrp1", TXTFIELD_BYTE, 0, 230, 0 },
        { "ObjGrp2", TXTFIELD_BYTE, 0, 231, 0 },
        { "ObjGrp3", TXTFIELD_BYTE, 0, 232, 0 },
        { "ObjGrp4", TXTFIELD_BYTE, 0, 233, 0 },
        { "ObjGrp5", TXTFIELD_BYTE, 0, 234, 0 },
        { "ObjGrp6", TXTFIELD_BYTE, 0, 235, 0 },
        { "ObjGrp7", TXTFIELD_BYTE, 0, 236, 0 },
        { "ObjPrb0", TXTFIELD_BYTE, 0, 237, 0 },
        { "ObjPrb1", TXTFIELD_BYTE, 0, 238, 0 },
        { "ObjPrb2", TXTFIELD_BYTE, 0, 239, 0 },
        { "ObjPrb3", TXTFIELD_BYTE, 0, 240, 0 },
        { "ObjPrb4", TXTFIELD_BYTE, 0, 241, 0 },
        { "ObjPrb5", TXTFIELD_BYTE, 0, 242, 0 },
        { "ObjPrb6", TXTFIELD_BYTE, 0, 243, 0 },
        { "ObjPrb7", TXTFIELD_BYTE, 0, 244, 0 },
        { "Quest", TXTFIELD_BYTE, 0, 48, 0 },
        { "NumMon", TXTFIELD_BYTE, 0, 50, 0 },
        { "mon1", TXTFIELD_NAMETOWORD, 0, 54, &sgtDataTables.pMonStatsLinker },
        { "mon2", TXTFIELD_NAMETOWORD, 0, 56, &sgtDataTables.pMonStatsLinker },
        { "mon3", TXTFIELD_NAMETOWORD, 0, 58, &sgtDataTables.pMonStatsLinker },
        { "mon4", TXTFIELD_NAMETOWORD, 0, 60, &sgtDataTables.pMonStatsLinker },
        { "mon5", TXTFIELD_NAMETOWORD, 0, 62, &sgtDataTables.pMonStatsLinker },
        { "mon6", TXTFIELD_NAMETOWORD, 0, 64, &sgtDataTables.pMonStatsLinker },
        { "mon7", TXTFIELD_NAMETOWORD, 0, 66, &sgtDataTables.pMonStatsLinker },
        { "mon8", TXTFIELD_NAMETOWORD, 0, 68, &sgtDataTables.pMonStatsLinker },
        { "mon9", TXTFIELD_NAMETOWORD, 0, 70, &sgtDataTables.pMonStatsLinker },
        { "mon10", TXTFIELD_NAMETOWORD, 0, 72, &sgtDataTables.pMonStatsLinker },
        { "mon11", TXTFIELD_NAMETOWORD, 0, 74, &sgtDataTables.pMonStatsLinker },
        { "mon12", TXTFIELD_NAMETOWORD, 0, 76, &sgtDataTables.pMonStatsLinker },
        { "mon13", TXTFIELD_NAMETOWORD, 0, 78, &sgtDataTables.pMonStatsLinker },
        { "mon14", TXTFIELD_NAMETOWORD, 0, 80, &sgtDataTables.pMonStatsLinker },
        { "mon15", TXTFIELD_NAMETOWORD, 0, 82, &sgtDataTables.pMonStatsLinker },
        { "mon16", TXTFIELD_NAMETOWORD, 0, 84, &sgtDataTables.pMonStatsLinker },
        { "mon17", TXTFIELD_NAMETOWORD, 0, 86, &sgtDataTables.pMonStatsLinker },
        { "mon18", TXTFIELD_NAMETOWORD, 0, 88, &sgtDataTables.pMonStatsLinker },
        { "mon19", TXTFIELD_NAMETOWORD, 0, 90, &sgtDataTables.pMonStatsLinker },
        { "mon20", TXTFIELD_NAMETOWORD, 0, 92, &sgtDataTables.pMonStatsLinker },
        { "mon21", TXTFIELD_NAMETOWORD, 0, 94, &sgtDataTables.pMonStatsLinker },
        { "mon22", TXTFIELD_NAMETOWORD, 0, 96, &sgtDataTables.pMonStatsLinker },
        { "mon23", TXTFIELD_NAMETOWORD, 0, 98, &sgtDataTables.pMonStatsLinker },
        { "mon24", TXTFIELD_NAMETOWORD, 0, 100, &sgtDataTables.pMonStatsLinker },
        { "mon25", TXTFIELD_NAMETOWORD, 0, 102, &sgtDataTables.pMonStatsLinker },
        { "rangedspawn", TXTFIELD_BYTE, 0, 49, 0 },
        { "nmon1", TXTFIELD_NAMETOWORD, 0, 104, &sgtDataTables.pMonStatsLinker },
        { "nmon2", TXTFIELD_NAMETOWORD, 0, 106, &sgtDataTables.pMonStatsLinker },
        { "nmon3", TXTFIELD_NAMETOWORD, 0, 108, &sgtDataTables.pMonStatsLinker },
        { "nmon4", TXTFIELD_NAMETOWORD, 0, 110, &sgtDataTables.pMonStatsLinker },
        { "nmon5", TXTFIELD_NAMETOWORD, 0, 112, &sgtDataTables.pMonStatsLinker },
        { "nmon6", TXTFIELD_NAMETOWORD, 0, 114, &sgtDataTables.pMonStatsLinker },
        { "nmon7", TXTFIELD_NAMETOWORD, 0, 116, &sgtDataTables.pMonStatsLinker },
        { "nmon8", TXTFIELD_NAMETOWORD, 0, 118, &sgtDataTables.pMonStatsLinker },
        { "nmon9", TXTFIELD_NAMETOWORD, 0, 120, &sgtDataTables.pMonStatsLinker },
        { "nmon10", TXTFIELD_NAMETOWORD, 0, 122, &sgtDataTables.pMonStatsLinker },
        { "nmon11", TXTFIELD_NAMETOWORD, 0, 124, &sgtDataTables.pMonStatsLinker },
        { "nmon12", TXTFIELD_NAMETOWORD, 0, 126, &sgtDataTables.pMonStatsLinker },
        { "nmon13", TXTFIELD_NAMETOWORD, 0, 128, &sgtDataTables.pMonStatsLinker },
        { "nmon14", TXTFIELD_NAMETOWORD, 0, 130, &sgtDataTables.pMonStatsLinker },
        { "nmon15", TXTFIELD_NAMETOWORD, 0, 132, &sgtDataTables.pMonStatsLinker },
        { "nmon16", TXTFIELD_NAMETOWORD, 0, 134, &sgtDataTables.pMonStatsLinker },
        { "nmon17", TXTFIELD_NAMETOWORD, 0, 136, &sgtDataTables.pMonStatsLinker },
        { "nmon18", TXTFIELD_NAMETOWORD, 0, 138, &sgtDataTables.pMonStatsLinker },
        { "nmon19", TXTFIELD_NAMETOWORD, 0, 140, &sgtDataTables.pMonStatsLinker },
        { "nmon20", TXTFIELD_NAMETOWORD, 0, 142, &sgtDataTables.pMonStatsLinker },
        { "nmon21", TXTFIELD_NAMETOWORD, 0, 144, &sgtDataTables.pMonStatsLinker },
        { "nmon22", TXTFIELD_NAMETOWORD, 0, 146, &sgtDataTables.pMonStatsLinker },
        { "nmon23", TXTFIELD_NAMETOWORD, 0, 148, &sgtDataTables.pMonStatsLinker },
        { "nmon24", TXTFIELD_NAMETOWORD, 0, 150, &sgtDataTables.pMonStatsLinker },
        { "nmon25", TXTFIELD_NAMETOWORD, 0, 152, &sgtDataTables.pMonStatsLinker },
        { "umon1", TXTFIELD_NAMETOWORD, 0, 154, &sgtDataTables.pMonStatsLinker },
        { "umon2", TXTFIELD_NAMETOWORD, 0, 156, &sgtDataTables.pMonStatsLinker },
        { "umon3", TXTFIELD_NAMETOWORD, 0, 158, &sgtDataTables.pMonStatsLinker },
        { "umon4", TXTFIELD_NAMETOWORD, 0, 160, &sgtDataTables.pMonStatsLinker },
        { "umon5", TXTFIELD_NAMETOWORD, 0, 162, &sgtDataTables.pMonStatsLinker },
        { "umon6", TXTFIELD_NAMETOWORD, 0, 164, &sgtDataTables.pMonStatsLinker },
        { "umon7", TXTFIELD_NAMETOWORD, 0, 166, &sgtDataTables.pMonStatsLinker },
        { "umon8", TXTFIELD_NAMETOWORD, 0, 168, &sgtDataTables.pMonStatsLinker },
        { "umon9", TXTFIELD_NAMETOWORD, 0, 170, &sgtDataTables.pMonStatsLinker },
        { "umon10", TXTFIELD_NAMETOWORD, 0, 172, &sgtDataTables.pMonStatsLinker },
        { "umon11", TXTFIELD_NAMETOWORD, 0, 174, &sgtDataTables.pMonStatsLinker },
        { "umon12", TXTFIELD_NAMETOWORD, 0, 176, &sgtDataTables.pMonStatsLinker },
        { "umon13", TXTFIELD_NAMETOWORD, 0, 178, &sgtDataTables.pMonStatsLinker },
        { "umon14", TXTFIELD_NAMETOWORD, 0, 180, &sgtDataTables.pMonStatsLinker },
        { "umon15", TXTFIELD_NAMETOWORD, 0, 182, &sgtDataTables.pMonStatsLinker },
        { "umon16", TXTFIELD_NAMETOWORD, 0, 184, &sgtDataTables.pMonStatsLinker },
        { "umon17", TXTFIELD_NAMETOWORD, 0, 186, &sgtDataTables.pMonStatsLinker },
        { "umon18", TXTFIELD_NAMETOWORD, 0, 188, &sgtDataTables.pMonStatsLinker },
        { "umon19", TXTFIELD_NAMETOWORD, 0, 190, &sgtDataTables.pMonStatsLinker },
        { "umon20", TXTFIELD_NAMETOWORD, 0, 192, &sgtDataTables.pMonStatsLinker },
        { "umon21", TXTFIELD_NAMETOWORD, 0, 194, &sgtDataTables.pMonStatsLinker },
        { "umon22", TXTFIELD_NAMETOWORD, 0, 196, &sgtDataTables.pMonStatsLinker },
        { "umon23", TXTFIELD_NAMETOWORD, 0, 198, &sgtDataTables.pMonStatsLinker },
        { "umon24", TXTFIELD_NAMETOWORD, 0, 200, &sgtDataTables.pMonStatsLinker },
        { "umon25", TXTFIELD_NAMETOWORD, 0, 202, &sgtDataTables.pMonStatsLinker },
        { "cmon1", TXTFIELD_NAMETOWORD, 0, 204, &sgtDataTables.pMonStatsLinker },
        { "cmon2", TXTFIELD_NAMETOWORD, 0, 206, &sgtDataTables.pMonStatsLinker },
        { "cmon3", TXTFIELD_NAMETOWORD, 0, 208, &sgtDataTables.pMonStatsLinker },
        { "cmon4", TXTFIELD_NAMETOWORD, 0, 210, &sgtDataTables.pMonStatsLinker },
        { "cpct1", TXTFIELD_WORD, 0, 212, 0 },
        { "cpct2", TXTFIELD_WORD, 0, 214, 0 },
        { "cpct3", TXTFIELD_WORD, 0, 216, 0 },
        { "cpct4", TXTFIELD_WORD, 0, 218, 0 },
        { "camt1", TXTFIELD_WORD, 0, 220, 0 },
        { "camt2", TXTFIELD_WORD, 0, 220, 0 },
        { "camt3", TXTFIELD_WORD, 0, 220, 0 },
        { "camt4", TXTFIELD_WORD, 0, 220, 0 },
        { "Themes", TXTFIELD_DWORD, 0, 528, 0 },
        { "FloorFilter", TXTFIELD_DWORD, 0, 532, 0 },
        { "BlankScreen", TXTFIELD_DWORD, 0, 536, 0 },
        { "SoundEnv", TXTFIELD_BYTE, 0, 540, 0 },
        { "Waypoint", TXTFIELD_BYTE, 0, 228, 0 },
        { "LevelName", TXTFIELD_ASCII, 39, 245, 0 },
        { "LevelWarp", TXTFIELD_ASCII, 39, 285, 0 },
        { "EntryFile", TXTFIELD_ASCII, 39, 325, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    sgtDataTables.pLevelsTxt = (D2LevelsTxt*)DATATBLS_CompileTxt(hArchive, "levels", pTbl, &sgtDataTables.nLevelsTxtRecordCount, sizeof(D2LevelsTxt));

    D2_ASSERT(sgtDataTables.nLevelsTxtRecordCount < 1024, 199);

    for (int i = 0; i < sgtDataTables.nLevelsTxtRecordCount; ++i)
    {
        D2LevelsTxt* pLevelsTxtRecord = &sgtDataTables.pLevelsTxt[i];

        memset(pLevelsTxtRecord->wszLevelName, 0, 80);
        memset(pLevelsTxtRecord->wszLevelWarp, 0, 80);

        Unicode::strncpy(pLevelsTxtRecord->wszLevelName, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelName), 40);
        pLevelsTxtRecord->wszLevelName[39].wChar = 0;

        Unicode::strncpy(pLevelsTxtRecord->wszLevelWarp, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelWarp), 40);
        pLevelsTxtRecord->wszLevelWarp[39].wChar = 0;

        for (int j = 0; j < sgtDataTables.nLevelsTxtRecordCount; ++j)
        {
            int nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNormalMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNormalMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNightmareHellMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNightmareHellMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wUniqueMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumUniqueMonsters = nMonsterCounter;
        }
    }
}
