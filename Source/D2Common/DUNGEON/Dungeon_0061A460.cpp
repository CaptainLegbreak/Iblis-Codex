#include "D2Common.h"

struct D2DrlgActStrc;

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    char unk0x04[8];
    int nTileCount;
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[16];
    int nNumRooms;
    char unk0x28[12];
    unsigned int dwFlags;
    char unk0x38[64];
    int nNumClients;
};

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

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ROOMFLAG_1 0x00000001

// 0x0061A460
int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1007);

    if (pRoom->nNumRooms == sub_0066BCF0(pRoom->pDrlgRoom))
    {
        for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
        {
            if (!(pRoom->ppRoomList[i]->dwFlags & ROOMFLAG_1))
            {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

// 0x0061A790
int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1198);

    if (pRoom->nNumClients)
    {
        pRoom->nTileCount = 0;
    }
    else
    {
        ++pRoom->nTileCount;
    }

    return pRoom->nTileCount;
}

// 0x0061AE30
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nPortalLevelId)
{
    int nPortalLevels;
    int* pPortalLevels = DATATBLS_GetPortalLevels(&nPortalLevels);

    for (int i = 0; i < nPortalLevels; ++i)
    {
        if (nPortalLevelId == *pPortalLevels)
        {
            return 1 << i;
        }
        ++pPortalLevels;
    }

    return 0;
}

// build: context DRLGACTIVATE_GetRoomsAllocationStats
void __fastcall DRLGACTIVATE_GetRoomsAllocationStats(int* pOutStatsClientAllocatedRooms, int* pOutStatsClientFreedRooms, int* pOutStatsAllocatedRooms, int* pOutStatsFreedRooms)
{
    *pOutStatsClientAllocatedRooms = gStatsClientAllocatedRooms;
    *pOutStatsClientFreedRooms = gStatsClientFreedRooms;
    *pOutStatsAllocatedRooms = gStatsAllocatedRooms;
    *pOutStatsFreedRooms = gStatsFreedRooms;
}

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
