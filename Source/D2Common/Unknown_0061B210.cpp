#include "D2Common.h"
#include "D2Drlg.h"

struct D2DrlgStrc;




void __fastcall DRLGROOM_InitNearRooms(void* pContext, D2DrlgRoomStrc* pNode);                        // 0x0066C370
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EE40
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom);                     // 0x006422A0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg);                                                          // 0x00642A00
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom);                                // 0x0066F240
static int gnStatsClientAllocatedRooms;                                                            // 0x0096C8B8
static int gnStatsClientFreedRooms;                                                                // 0x0096C8BC
static int gnStatsAllocatedRooms;                                                                  // 0x0096C8C4
static int gnStatsFreedRooms;                                                                      // 0x0096C8C0

static int DRLGACTIVATE_RoomEx_EnsureHasRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
    if (!pDrlgRoom->nRoomsNear)
        DRLGROOM_InitNearRooms(pMemPool, pDrlgRoom);
    DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
    DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
    DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
    ++pDrlg->nRoomsInitSinceLastUpdate;
    ++pDrlg->nAllocatedRooms;
    return 1;
}

static void DRLGACTIVATE_RoomExStatusUnlink(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->pStatusPrev && pDrlgRoom->pStatusNext)
    {
        pDrlgRoom->pStatusPrev->pStatusNext = pDrlgRoom->pStatusNext;
        pDrlgRoom->pStatusNext->pStatusPrev = pDrlgRoom->pStatusPrev;
        pDrlgRoom->pStatusPrev = 0;
        pDrlgRoom->pStatusNext = 0;
    }
}

// 0x0061B210
static void DRLGACTIVATE_ForceRoomExStatusImpl(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->fRoomStatus == nStatus)
        return;

    DRLGACTIVATE_RoomExStatusUnlink(pDrlgRoom);
    if (nStatus < 4)
    {
        D2DrlgRoomStrc* pHead = &pDrlgRoom->ptDrlgLevel->pDrlg->tStatusRoomsLists[nStatus];
        pDrlgRoom->pStatusNext = pHead;
        pDrlgRoom->pStatusPrev = pHead->pStatusPrev;
        pHead->pStatusPrev->pStatusNext = pDrlgRoom;
        pHead->pStatusPrev = pDrlgRoom;
        pDrlgRoom->fRoomStatus = nStatus;
    }
}

static void DRLGACTIVATE_ForceRoomExStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 0);
}

static void DRLGACTIVATE_ForceRoomExStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 1);
}

static void DRLGACTIVATE_ForceRoomExStatus_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 3);
}

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatus_ClientInRoom(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pRoom && !(pDrlgRoom->dwFlags & 0x100000))
    {
        D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
        DRLGACTIVATE_RoomEx_EnsureHasRoom(pDrlg->pMempool, pDrlgRoom);
        pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) == 0 ? 7 : 5;
    }
    if (pDrlgRoom->fRoomStatus > 1)
        DRLGACTIVATE_ForceRoomExStatus_ClientInSight(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExSetStatus_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & 0x1000000))
        DRLGROOMTILE_LoadDT1FilesForRoom(pDrlgRoom);
    if (pDrlgRoom->nType == 2 && !(pDrlgRoom->dwFlags & 0x2000000))
        DRLGPRESET_SpawnHardcodedPresetUnits(pDrlgRoom);
    if (pDrlgRoom->fRoomStatus > 3)
        DRLGACTIVATE_ForceRoomExStatus_Untile(pDrlgRoom);
}

static void DRLGACTIVATE_RoomExIdentifyRealStatus(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->fRoomStatus < 4 && pDrlgRoom->wRoomsInList[pDrlgRoom->fRoomStatus])
        return;

    unsigned char nStatus;
    for (nStatus = 0; nStatus < 4; ++nStatus)
    {
        if (pDrlgRoom->wRoomsInList[nStatus])
            break;
    }
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, nStatus);
    pDrlgRoom->fRoomStatus = nStatus;
}

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExStatusUnset_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->fRoomStatus != 4)
    {
        DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
        if (pDrlgRoom->fRoomStatus == 4 && DRLG_IsOnClient(pDrlgRoom->ptDrlgLevel->pDrlg))
            DRLGROOMTILE_FreeRoom(pDrlgRoom, 0);
    }
}

void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnStatsClientAllocatedRooms = pDrlg->nAllocatedRooms;
        gnStatsClientFreedRooms = pDrlg->nFreedRooms;
    }
    else
    {
        gnStatsAllocatedRooms = pDrlg->nAllocatedRooms;
        gnStatsFreedRooms = pDrlg->nFreedRooms;
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
            while (pCurRoomEx != pDrlgRoomExListHead && pDrlg->nRoomsInitSinceLastUpdate == 0);

            pDrlg->pDrlgRoom = pCurRoomEx;
            pDrlg->nRoomsInitSinceLastUpdate = 0;
        }
    }
}

static void DRLGACTIVATE_ForceRoomExStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 2);
    if (pDrlgRoom->wRoomsInList[1])
        DRLGACTIVATE_RoomExSetStatus_ClientInSight(pDrlgRoom);
}

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if ((pDrlgRoom->dwFlags & 0x1000000) && (pDrlgRoom->nType != 2 || (pDrlgRoom->dwFlags & 0x2000000)))
    {
        if (pDrlgRoom->fRoomStatus > 2)
            DRLGACTIVATE_ForceRoomExStatus_ClientOutOfSight(pDrlgRoom);
    }
}
