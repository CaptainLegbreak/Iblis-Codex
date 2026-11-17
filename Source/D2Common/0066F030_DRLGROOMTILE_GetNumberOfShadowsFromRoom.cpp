struct D2ActiveRoomStrc;
struct D2DrlgLevelStrc;

struct D2DrlgTileGridStrc
{
    void* pMapLinks;
    void* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
};

struct D2RoomTileStrc
{
    void* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    void* unk0x0C;
    void* pLvlWarpTxtRecord;
    void* unk0x14;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x28];
    unsigned int dwFlags;
    char unk0x2C[0x4];
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x14];
    int nType;
    D2RoomTileStrc* pRoomTiles;
    char unk0x50[0x4];
    D2DrlgTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
};

D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom);                             // 0x0061AAE0

// 0x0066F030
int __fastcall DRLGROOMTILE_GetNumberOfShadowsFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    return DUNGEON_GetRoomExFromRoom(pRoom)->pTileGrid->nShadows;
}

// 0x0066F180
static void sub_0066F180_ResetRoomTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        pRoomTile->unk0x14 = 0;
        pRoomTile->unk0x0C = 0;
    }
}

void __fastcall sub_M107_Emit_0066F180(D2DrlgRoomStrc* pDrlgRoom, int bReset)
{
    if (bReset)
        sub_0066F180_ResetRoomTiles(pDrlgRoom);
}
