struct D2ActiveRoomStrc;
struct D2DrlgStrc;

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x1C];
    D2DrlgRoomStrc* pStatusNext;
    char unk0x20[0x08];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x10];
    unsigned char fRoomStatus;
    char unk0x45[0x13];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x90];
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
void __fastcall DRLGROOMTILE_AddRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EE70
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom);                     // 0x006422A0
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg);                                                          // 0x00642A00

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

// 0x0061B920
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
            while (pCurRoomEx != pDrlgRoomExListHead && pDrlg->nRoomsInitSinceLastUpdate < 1);

            pDrlg->pDrlgRoom = pCurRoomEx;
            pDrlg->nRoomsInitSinceLastUpdate = 0;
        }
    }
}
