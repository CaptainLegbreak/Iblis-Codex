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
