struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2DrlgTileDataListStrc
{
    void* pWallTiles;
    int nWalls;
    void* pFloorTiles;
    int nFloors;
};

struct D2RoomTileGridStrc
{
    char unk0x00[0x14];
    D2DrlgTileDataListStrc pTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    char unk0x1C[0x0C];
    unsigned int dwFlags;
    int unk0x2C;
    D2ActiveRoomStrc* pRoom;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x10];
    D2RoomTileGridStrc* pTileGrid;
    int unk0x58[2];
    unsigned int dwOtherFlags;
};

struct D2DrlgStrc
{
    char unk0x000[0x46C];
    D2DrlgActStrc* pAct;
};

#define DRLGROOMFLAG_0x40000 0x40000

D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* pAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgTileDataListStrc* pRoomTiles, int nLowSeed, int nFlags); // 0x00619890
void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x006422A0
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgCoordsStrc tDrlgCoords = { 0 };

    tDrlgCoords.nTileXPos = pDrlgRoom->nTileXPos;
    tDrlgCoords.nTileYPos = pDrlgRoom->nTileYPos;
    tDrlgCoords.nTileWidth = pDrlgRoom->nTileWidth;
    tDrlgCoords.nTileHeight = pDrlgRoom->nTileHeight;

    tDrlgCoords.nSubtileX = pDrlgRoom->nTileXPos;
    tDrlgCoords.nSubtileY = pDrlgRoom->nTileYPos;
    tDrlgCoords.nSubtileWidth = pDrlgRoom->nTileWidth;
    tDrlgCoords.nSubtileHeight = pDrlgRoom->nTileHeight;

    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileX, &tDrlgCoords.nSubtileY);
    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileWidth, &tDrlgCoords.nSubtileHeight);

    D2DrlgTileDataListStrc* pTiles = &pDrlgRoom->pTileGrid->pTiles;
    if (pTiles->nWalls || pTiles->nFloors)
    {
        int nFlags = 0;
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_0x40000)
        {
            nFlags = 4;
        }
        else if (pDrlgRoom->dwOtherFlags & 1)
        {
            nFlags = 1;
        }

        pDrlgRoom->pRoom = DUNGEON_AllocRoom(pDrlg->pAct, pDrlgRoom, &tDrlgCoords, pTiles, (int)SEED_RollRandomNumber(&pDrlgRoom->pSeed), nFlags);
    }
}
