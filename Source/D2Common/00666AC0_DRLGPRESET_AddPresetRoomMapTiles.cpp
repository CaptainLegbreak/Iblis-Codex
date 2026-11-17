struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int nFlags;
};

struct D2LvlPrestTxt
{
    char unk0x00[0x0C];
    int dwLogicals;
    int unk0x10;
    int dwAnimate;
    int dwKillEdge;
    int dwFillBlanks;
    int unk0x20;
    int nAnimSpeed;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x14];
    int nWallLayers;
    int nFloorLayers;
};

struct D2DrlgMapStrc
{
    char unk0x00[0x08];
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    D2DrlgCoordStrc pDrlgCoord;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int unk0x04;
    D2DrlgMapStrc* pMap;
    int unk0x0C;
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pFloorGrid[2];
    D2DrlgGridStrc pCellGrid;
    int unk0xEC;
    D2CoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgStrc
{
    char unk0x00[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
};

struct D2RoomTileGridStrc
{
    char unk0x00[0x08];
    volatile int nWalls;
    volatile int nFloors;
    volatile int nShadows;
    int unk0x14;
    volatile int nTileWalls;
    int unk0x1C;
    volatile int nTileFloors;
    int unk0x24;
    volatile int nTileRoofs;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgPresetRoomStrc* pMaze;
    char unk0x24[0x10];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x10];
    D2RoomTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
};

extern "C" const char gszDrlgPresetSourceFile_006EE7C4[];                                                   // 0x006EE7C4
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY);                                      // 0x00643560

void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EEA0
void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags); // 0x0067CBF0
void __fastcall sub_0066ECE0_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066ECE0
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int bKillEdgeX, int bKillEdgeY); // 0x0066D290
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY); // 0x0066EDB0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom);                                      // 0x0066EEE0
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066EC10
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pDrlgRoom, int nAnimSpeed, D2DrlgGridStrc* pWallGrids, int nWallLayers, D2DrlgGridStrc* pFloorGrids, int nFloorLayers, D2DrlgGridStrc* pCellGrid); // 0x0066D700
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid); // 0x0066D110
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom);                                       // 0x0066CCB0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);                                                  // 0x0067CDC0

static void __declspec(noinline) sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

// 0x00666990
static void sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    int nTombStoneTiles = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze->pTombStoneTiles)
        return;

    pMaze->pTombStoneTiles = (D2CoordStrc*)FOG_AllocPool(pMemPool, 6 * sizeof(D2CoordStrc), gszDrlgPresetSourceFile_006EE7C4, 1964, 0);
    for (int i = 0; i < pDrlgRoom->nTileHeight; ++i)
    {
        for (int j = 0; j < pDrlgRoom->nTileWidth; ++j)
        {
            const unsigned int nPacked = DRLGGRID_GetGridEntry(pMaze->pWallGrid, j, i);
            const unsigned char nTileStyle = (nPacked >> 20) & 0x3F;
            const unsigned char nTileSequence = (unsigned char)(nPacked >> 8);
            if (nTileStyle == 10 && nTileSequence >= 23 && nTileSequence <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nY;
                    int nX;
                    nX = j + pDrlgRoom->nTileXPos;
                    nY = i + pDrlgRoom->nTileYPos;
                    sub_00643560_GameTileToSubtileCoords(&nX, &nY);
                    nX += 2;
                    nY += 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nX;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nY;
                    ++nTombStoneTiles;
                }
            }
        }
    }
    pMaze->nTombStoneTiles = nTombStoneTiles;
}

// 0x00666AC0
void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGROOMTILE_AllocTileGrid(pDrlgRoom);

    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pMazeMap = pMaze->pMap;
    const int bAnimate = pMazeMap->pLvlPrestTxtRecord->dwAnimate;
    const int bFillBlanks = pMazeMap->pLvlPrestTxtRecord->dwFillBlanks;

    int bKillEdgeX = 0;
    int bKillEdgeY = 0;
    if (pMazeMap->pLvlPrestTxtRecord->dwKillEdge)
    {
        bKillEdgeX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth == pMazeMap->pDrlgCoord.nPosX + pMazeMap->pDrlgCoord.nWidth;
        bKillEdgeY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight == pMazeMap->pDrlgCoord.nPosY + pMazeMap->pDrlgCoord.nHeight;
    }

    D2DrlgGridStrc tTileTypeGrid;
    D2DrlgGridStrc tTileInfoGrid;
    int aTileTypeCellPos[1024];
    int aTileTypeCellFlags[256];
    int aTileInfoCellPos[1024];
    int aTileInfoCellFlags[256];
    int bTownOrGraveyard = 0;
    switch (pDrlgRoom->pMaze->nLevelPrest)
    {
    case 1:
    case 108:
        bTownOrGraveyard = 1;
        sub_0067CBF0(&tTileTypeGrid, pDrlgRoom->nTileWidth + 1, pDrlgRoom->nTileHeight + 1, aTileTypeCellPos, aTileTypeCellFlags);
        sub_0067CBF0(&tTileInfoGrid, pDrlgRoom->nTileWidth + 1, pDrlgRoom->nTileHeight + 1, aTileInfoCellPos, aTileInfoCellFlags);
        break;
    }

    const int nWallLayers = pMaze->pMap->pFile->nWallLayers;
    const int nFloorLayers = pMaze->pMap->pFile->nFloorLayers;

    for (int i = 0; i < nFloorLayers; ++i)
    {
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pFloorGrid[i], i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, 0, bKillEdgeX, bKillEdgeY);
        }
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_CountWallWarpTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], bKillEdgeX, bKillEdgeY);
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pWallGrid[i], 0, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
        }
    }

    sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &pMaze->pCellGrid, 0, bKillEdgeX, bKillEdgeY);
    if (bAnimate)
    {
        DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 13, bKillEdgeX, bKillEdgeY);
    }

    if (bTownOrGraveyard)
    {
        sub_0066ECE0_CountAllTileTypes(pDrlgRoom, &tTileInfoGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_AllocTileData(pDrlgRoom);

    for (int i = 0; i < nFloorLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 0, bKillEdgeX, bKillEdgeY);

    if (bTownOrGraveyard)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &tTileInfoGrid, &tTileTypeGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    if (bAnimate)
    {
        DRLGANIM_AllocAnimationTileGrids(pDrlgRoom, pMaze->pMap->pLvlPrestTxtRecord->nAnimSpeed, pMaze->pWallGrid, nWallLayers, pMaze->pFloorGrid, nFloorLayers, &pMaze->pCellGrid);
    }

    D2RoomTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    pTileGrid->nTileWalls = pTileGrid->nWalls;
    pTileGrid->nTileFloors = pTileGrid->nFloors;
    pTileGrid->nTileRoofs = pTileGrid->nShadows;

    if (pMaze->pMap->pLvlPrestTxtRecord->dwLogicals)
    {
        DRLGLOGIC_InitializeDrlgCoordList(pDrlgRoom, pMaze->pTileTypeGrid, pMaze->pFloorGrid, pMaze->pWallGrid);
    }
    else
    {
        DRLGLOGIC_AllocCoordLists(pDrlgRoom);
    }

    if (bTownOrGraveyard)
    {
        DRLGGRID_ResetGrid(&tTileTypeGrid);
        DRLGGRID_ResetGrid(&tTileInfoGrid);
    }

    if (pDrlgRoom->pLevel->nLevelId == 17)
    {
        sub_00666990(pMemPool, pDrlgRoom);
    }
}
