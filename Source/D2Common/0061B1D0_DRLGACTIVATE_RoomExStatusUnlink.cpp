struct D2ActiveRoomStrc;
struct D2DrlgStrc;
struct D2DrlgLevelStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x0C];
    unsigned short wRoomsInList[4];
    char unk0x14[0x08];
    D2DrlgRoomStrc* pStatusNext;
    char unk0x20[0x08];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0x03];
    int nType;
    char unk0x4C[0x0C];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x8C];
    D2DrlgRoomStrc* pStatusPrev;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgStrc
{
    char unk0x000[0x08];
    int nAllocatedRooms;
    char unk0x00C[0x8C];
    unsigned char nRoomsInitSinceLastUpdate;
    char unk0x099[0x07];
    D2DrlgRoomStrc tStatusRoomsLists[4];
    char unk0x450[0x0C];
    unsigned char nRoomsInitTimeout;
    char unk0x45D[0x03];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x464[0x04];
    int nFreedRooms;
    char unk0x46C[0x0C];
    void* pMempool;
};

void __fastcall sub_0066C370_OnChildlessNode(void* pContext, D2DrlgRoomStrc* pNode);                        // 0x0066C370
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EE40
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom);                                    // 0x0066EE70
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom);                     // 0x006422A0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg);                                                          // 0x00642A00
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom);                                // 0x0066F240
void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom);                            // 0x00667890
void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom);                            // 0x0066F1A0
static int gnStatsClientAllocatedRooms_0096C8B8;                                                            // 0x0096C8B8
static int gnStatsClientFreedRooms_0096C8BC;                                                                // 0x0096C8BC
static int gnStatsAllocatedRooms_0096C8C4;                                                                  // 0x0096C8C4
static int gnStatsFreedRooms_0096C8C0;                                                                      // 0x0096C8C0

// build: symbol ?DRLGACTIVATE_RoomEx_EnsureHasRoom@@YAHPAXPAUD2DrlgRoomStrc@@@Z 0x0061B190
static int DRLGACTIVATE_RoomEx_EnsureHasRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->pLevel->pDrlg;
    if (!pDrlgRoom->nRoomsNear)
        sub_0066C370_OnChildlessNode(pMemPool, pDrlgRoom);
    DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
    DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
    DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
    ++pDrlg->nRoomsInitSinceLastUpdate;
    ++pDrlg->nAllocatedRooms;
    return 1;
}

// 0x0061B1D0
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

static void DRLGACTIVATE_ForceRoomExStatusImpl(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B210

// build: context DRLGACTIVATE_ForceRoomExStatusImpl
static void DRLGACTIVATE_ForceRoomExStatusImpl(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->fRoomStatus == nStatus)
        return;

    DRLGACTIVATE_RoomExStatusUnlink(pDrlgRoom);
    if (nStatus < 4)
    {
        D2DrlgRoomStrc* pHead = &pDrlgRoom->pLevel->pDrlg->tStatusRoomsLists[nStatus];
        pDrlgRoom->pStatusNext = pHead;
        pDrlgRoom->pStatusPrev = pHead->pStatusPrev;
        pHead->pStatusPrev->pStatusNext = pDrlgRoom;
        pHead->pStatusPrev = pDrlgRoom;
    }
    pDrlgRoom->fRoomStatus = nStatus;
}

// 0x0061B290
static void sub_0061B290_ForceStatusClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 0);
}

// 0x0061B2A0
static void sub_0061B2A0_ForceStatusClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 1);
}

// 0x0061B2B0
static void sub_0061B2B0_ForceStatusUntile(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 3);
}

// 0x0061B2C0
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    sub_0061B290_ForceStatusClientInRoom(pDrlgRoom);
}

// 0x0061B2D0
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pRoom && !(pDrlgRoom->dwFlags & 0x100000))
    {
        D2DrlgStrc* pDrlg = pDrlgRoom->pLevel->pDrlg;
        DRLGACTIVATE_RoomEx_EnsureHasRoom(pDrlg->pMempool, pDrlgRoom);
        pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) == 0 ? 7 : 5;
    }
    if (pDrlgRoom->fRoomStatus > 1)
        sub_0061B2A0_ForceStatusClientInSight(pDrlgRoom);
}

// 0x0061B320
void __fastcall DRLGACTIVATE_RoomExSetStatus_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & 0x1000000))
        DRLGROOMTILE_LoadDT1FilesForRoom(pDrlgRoom);
    if (pDrlgRoom->nType == 2 && !(pDrlgRoom->dwFlags & 0x2000000))
        DRLGPRESET_SpawnHardcodedPresetUnits(pDrlgRoom);
    if (pDrlgRoom->fRoomStatus > 3)
        sub_0061B2B0_ForceStatusUntile(pDrlgRoom);
}

// 0x0061B4F0
static void sub_0061B4F0(D2DrlgRoomStrc* pDrlgRoom)
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

// 0x0061B530
void __fastcall sub_0061B530_UnsetStatusClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    sub_0061B4F0(pDrlgRoom);
}

// 0x0061B540
void __fastcall sub_0061B540_UnsetStatusClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    sub_0061B4F0(pDrlgRoom);
}

// 0x0061B550
void __fastcall sub_0061B550_UnsetStatusClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    sub_0061B4F0(pDrlgRoom);
}

// 0x0061B560
void __fastcall DRLGACTIVATE_RoomExStatusUnset_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->fRoomStatus != 4)
    {
        sub_0061B4F0(pDrlgRoom);
        if (pDrlgRoom->fRoomStatus == 4 && DRLG_IsOnClient(pDrlgRoom->pLevel->pDrlg))
            DRLGROOMTILE_FreeRoom(pDrlgRoom, 0);
    }
}

void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnStatsClientAllocatedRooms_0096C8B8 = pDrlg->nAllocatedRooms;
        gnStatsClientFreedRooms_0096C8BC = pDrlg->nFreedRooms;
    }
    else
    {
        gnStatsAllocatedRooms_0096C8C4 = pDrlg->nAllocatedRooms;
        gnStatsFreedRooms_0096C8C0 = pDrlg->nFreedRooms;
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

// 0x0061BAF0
static void sub_0061BAF0_ForceStatusClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 2);
    if (pDrlgRoom->wRoomsInList[1])
        DRLGACTIVATE_RoomExSetStatus_ClientInSight(pDrlgRoom);
}

// 0x0061BB10
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if ((pDrlgRoom->dwFlags & 0x1000000) && (pDrlgRoom->nType != 2 || (pDrlgRoom->dwFlags & 0x2000000)))
    {
        if (pDrlgRoom->fRoomStatus > 2)
            sub_0061BAF0_ForceStatusClientOutOfSight(pDrlgRoom);
    }
}
