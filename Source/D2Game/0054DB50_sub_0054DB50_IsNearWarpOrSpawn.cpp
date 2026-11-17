struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

struct D2GameActsViewStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2RoomWarpCoordsStrc
{
    int nX[9];
    int nY[9];
    int nCount;
};

struct D2LevelsTxt
{
    char unk0x00[0x0C];
    int nWarpDistSq;
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2RoomWarpCoordsStrc* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* pRoom);                // 0x0061AC10
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x00619E50
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY);                                      // 0x00643560

static __declspec(noinline) int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom);

// 0x0054DB50
static int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return 0;
    }

    D2RoomWarpCoordsStrc* pWarps = DUNGEON_GetWarpCoordinatesFromRoom(pRoom);
    if (!pWarps)
    {
        return 0;
    }

    const int nDistSq = DATATBLS_GetLevelsTxtRecord(nLevelId)->nWarpDistSq;
    for (int i = 0; i < pWarps->nCount; ++i)
    {
        const int nDX = nX - pWarps->nX[i];
        const int nDY = nY - pWarps->nY[i];
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    int nSpawnX;
    int nSpawnY;
    DUNGEON_FindActSpawnLocation(((D2GameActsViewStrc*)pGame)->pAct[DRLG_GetActNoFromLevelId(nLevelId)], nLevelId, 11, &nSpawnX, &nSpawnY);
    if (nSpawnX > 0 && nSpawnY > 0)
    {
        sub_00643560_GameTileToSubtileCoords(&nSpawnX, &nSpawnY);
        const int nDX = nX - nSpawnX;
        const int nDY = nY - nSpawnY;
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    return 0;
}

int __fastcall sub_0054DB50_Emit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return sub_0054DB50_IsNearWarpOrSpawn(pGame, nX, nY, pRoom);
}
