#include "D2Common.h"

struct D2DrlgStrc;
struct D2DrlgTableRefStrc;
struct D2Entry0061B7E0Strc;
struct D2Owner0061B7E0Strc;
struct D2ColorRecordStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x08];
    D2DrlgRoomStrc** ppRoomsNear;
    unsigned short wRoomsInList[4];
    char unk0x14[0x08];
    D2DrlgRoomStrc* pStatusNext;
    char unk0x20[0x08];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0x13];
    D2DrlgLevelStrc* ptDrlgLevel;
    char unk0x5C[0x90];
};

struct D2DrlgStrc
{
    char unk0x000[0x08];
    int nRoomCount08;
    char unk0x00C[0x8C];
    unsigned char nRoomsInitSinceLastUpdate;
    char unk0x099[0x07];
    D2DrlgRoomStrc tStatusRoomsLists[4];
    char unk0x450[0x0C];
    unsigned char nRoomsInitTimeout;
    char unk0x45D[0x03];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x464[0x04];
    int nRoomCount468;
    char unk0x46C[0x0C];
    void* pMempool;
};

struct D2DrlgTableRefStrc
{
    char unk0x00[0x28];
    int nValue;
    int nIndex;
};
extern int gaTable_007443E4[]; // 0x007443E4
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg); // 0x00642A00
int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0
void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B5B0

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

void __fastcall DRLGROOM_InitNearRooms(void* pContext, D2DrlgRoomStrc* pNode); // 0x0066C370
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE40
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x006422A0

struct D2Entry0061B7E0Strc
{
    unsigned char unk_00[0x1C];
    D2Entry0061B7E0Strc* pSelf1C;
    unsigned char unk_20[0x24];
    unsigned char nIndex44;
    unsigned char unk_45[0xA3];
    D2Entry0061B7E0Strc* pSelfE8;
};

struct D2Owner0061B7E0Strc
{
    unsigned char unk_00[0xA0];
    D2Entry0061B7E0Strc pEntries[4];
};

struct D2ColorRecordStrc
{
    char unk0x00[0x18];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

static int gnRoomStats_0096C8B8; // 0x0096C8B8

static int gnRoomStats_0096C8BC; // 0x0096C8BC

static int gnRoomStats_0096C8C0; // 0x0096C8C0

static int gnRoomStats_0096C8C4; // 0x0096C8C4

// 0x0061B170
static __forceinline void DRLGACTIVATE_InitRoomsInitTimeout(D2DrlgStrc* pDrlg)
{
    pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) ? 5 : 7;
}

void __stdcall sub_M121_Emit_0061B170(D2DrlgStrc* pDrlg) { DRLGACTIVATE_InitRoomsInitTimeout(pDrlg); }

// 0x0061B360
static __forceinline void sub_0061B360_SetStatusIfUnreferenced(D2DrlgRoomStrc* pDrlgRoom, int nStatus)
{
    if (pDrlgRoom->fRoomStatus >= nStatus)
    {
        for (int i = 0; i <= nStatus; ++i)
        {
            if (pDrlgRoom->wRoomsInList[i])
            {
                return;
            }
        }
        gRoomExSetStatus[nStatus](pDrlgRoom);
    }
}

void __stdcall sub_M121_Emit_0061B360(D2DrlgRoomStrc* pDrlgRoom, int nStatus) { sub_0061B360_SetStatusIfUnreferenced(pDrlgRoom, nStatus); }

// 0x0061B5A0
static __forceinline void sub_0061B5A0_CallUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    gRoomExUnsetStatus[nStatus](pDrlgRoom);
}

void __stdcall sub_M121_Emit_0061B5A0(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { sub_0061B5A0_CallUnsetStatus(pDrlgRoom, nStatus); }

// 0x0061B610
static __forceinline void sub_0061B610_RoomUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->wRoomsInList[nStatus])
    {
        --pDrlgRoom->wRoomsInList[nStatus];
        gRoomExUnsetStatus[nStatus](pDrlgRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pDrlgRoom, nStatus + 1);
    }
}

void __stdcall sub_M121_Emit_0061B610(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { sub_0061B610_RoomUnsetStatus(pDrlgRoom, nStatus); }

// 0x0061B810
static __forceinline D2DrlgRoomStrc* DRLGACTIVATE_RoomExStatusList_GetFirst(D2DrlgStrc* pDrlg, unsigned char nStatus)
{
    if (pDrlg->tStatusRoomsLists[nStatus].pStatusNext != &pDrlg->tStatusRoomsLists[nStatus])
    {
        return pDrlg->tStatusRoomsLists[nStatus].pStatusNext;
    }
    return 0;
}

D2DrlgRoomStrc* __stdcall sub_M121_Emit_0061B810(D2DrlgStrc* pDrlg, unsigned char nStatus) { return DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, nStatus); }

// 0x0061B8B0
static __forceinline void sub_0061B8B0_UpdateRoomStats(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnRoomStats_0096C8B8 = pDrlg->nRoomCount08;
        gnRoomStats_0096C8BC = pDrlg->nRoomCount468;
    }
    else
    {
        gnRoomStats_0096C8C4 = pDrlg->nRoomCount08;
        gnRoomStats_0096C8C0 = pDrlg->nRoomCount468;
    }
}

void __stdcall sub_M121_Emit_0061B8B0(D2DrlgStrc* pDrlg) { sub_0061B8B0_UpdateRoomStats(pDrlg); }

// 0x0061BA10
static __forceinline int sub_0061BA10_CanUntileLevel(int nLevelId)
{
    if (DRLG_IsTownLevel(nLevelId))
    {
        return 0;
    }
    return nLevelId != 120;
}

int __stdcall sub_M121_Emit_0061BA10(int nLevelId) { return sub_0061BA10_CanUntileLevel(nLevelId); }

// 0x0061BB50
static __forceinline void sub_0061BB50_SetFieldFromTable(D2DrlgTableRefStrc* pRecord)
{
    pRecord->nValue = gaTable_007443E4[pRecord->nIndex];
}

void __stdcall sub_M121_Emit_0061BB50(D2DrlgTableRefStrc* pRecord) { sub_0061BB50_SetFieldFromTable(pRecord); }

#include "gen/data/Source/D2Common/Unknown_0061B170.inc"

static int gnStatsClientAllocatedRooms_0096C8B8; // 0x0096C8B8

static int gnStatsClientFreedRooms_0096C8BC; // 0x0096C8BC

static int gnStatsAllocatedRooms_0096C8C4; // 0x0096C8C4

static int gnStatsFreedRooms_0096C8C0; // 0x0096C8C0

// 0x0061B190
static int DRLGACTIVATE_RoomEx_EnsureHasRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
    if (!pDrlgRoom->nRoomsNear)
        DRLGROOM_InitNearRooms(pMemPool, pDrlgRoom);
    DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
    DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
    DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
    ++pDrlg->nRoomsInitSinceLastUpdate;
    ++pDrlg->nRoomCount08;
    return 1;
}

// 0x0061B7E0
void __fastcall sub_0061B7E0_InitEntries(D2Owner0061B7E0Strc* pOwner)
{
    unsigned int i;
    D2Entry0061B7E0Strc* pEntry;
    for (i = 0, pEntry = pOwner->pEntries; i < 4; ++i, ++pEntry)
    {
        pEntry->nIndex44 = (unsigned char)i;
        pEntry->pSelf1C = pEntry;
        pEntry->pSelfE8 = pEntry;
    }
}

static int gStatsClientFreedRooms; // 0x0096C8BC

static int gStatsClientAllocatedRooms; // 0x0096C8B8

static int gStatsFreedRooms; // 0x0096C8C0

static int gStatsAllocatedRooms; // 0x0096C8C4

// 0x0061B8F0
void __fastcall DRLGACTIVATE_GetRoomsAllocationStats(int* pOutStatsClientAllocatedRooms, int* pOutStatsClientFreedRooms, int* pOutStatsAllocatedRooms, int* pOutStatsFreedRooms)
{
    *pOutStatsClientAllocatedRooms = gStatsClientAllocatedRooms;
    *pOutStatsClientFreedRooms = gStatsClientFreedRooms;
    *pOutStatsAllocatedRooms = gStatsAllocatedRooms;
    *pOutStatsFreedRooms = gStatsFreedRooms;
}

// 0x0061B920
void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnStatsClientAllocatedRooms_0096C8B8 = pDrlg->nRoomCount08;
        gnStatsClientFreedRooms_0096C8BC = pDrlg->nRoomCount468;
    }
    else
    {
        gnStatsAllocatedRooms_0096C8C4 = pDrlg->nRoomCount08;
        gnStatsFreedRooms_0096C8C0 = pDrlg->nRoomCount468;
    }

    if (pDrlg->nRoomsInitSinceLastUpdate > 1)
    {
        pDrlg->nRoomsInitSinceLastUpdate = 0;
        return;
    }

    --pDrlg->nRoomsInitTimeout;
    if (pDrlg->nRoomsInitTimeout == 0)
    {
        pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) == 0 ? 7 : 5;
        if (!pDrlg->pDrlgRoom || pDrlg->pDrlgRoom->fRoomStatus != 2)
            pDrlg->pDrlgRoom = pDrlg->tStatusRoomsLists[2].pStatusNext;

        if (D2DrlgRoomStrc* pDrlgRoomExListHead = pDrlg->pDrlgRoom)
        {
            D2DrlgRoomStrc* pCurRoomEx = pDrlgRoomExListHead;
            do
            {
                if (!(pCurRoomEx->dwFlags & 0x100000) && pCurRoomEx != &pDrlg->tStatusRoomsLists[2] && !pCurRoomEx->pRoom)
                    DRLGACTIVATE_RoomEx_EnsureHasRoom(pDrlg->pMempool, pCurRoomEx);
                pCurRoomEx = pCurRoomEx->pStatusNext;
            }
            while (pCurRoomEx != pDrlgRoomExListHead && pDrlg->nRoomsInitSinceLastUpdate < 1);

            pDrlg->pDrlgRoom = pCurRoomEx;
            pDrlg->nRoomsInitSinceLastUpdate = 0;
        }
    }
}

// 0x0061BB60
static void __stdcall sub_0061BB60_SetColorForId(D2ColorRecordStrc* pRecord, int nId)
{
    if (nId == 0x78)
    {
        pRecord->nRed = 0xF5;
        pRecord->nGreen = 0xF0;
        pRecord->nBlue = 0xFF;
    }
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitSetColorForId(D2ColorRecordStrc* pRecord, int nId)
{
    sub_0061BB60_SetColorForId(pRecord, nId);
}
