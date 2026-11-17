#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgVertexStrc;
struct D2CoordStrc;
struct D2DrlgCoordStrc;
struct D2LvlPrestTxt;
struct D2DrlgMapStrc;
struct D2DrlgPresetRoomStrc;
struct D2DrlgStrc;
struct D2RoomTileGridStrc;
struct D2SeedStrc;
struct D2PresetUnitStrc;
struct D2ObjectsTxt;
struct D2DrlgTileInfoStrc;

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
    int dwDef;
    char unk0x04[0x04];
    int dwPopulate;
    int dwLogicals;
    int dwOutdoors;
    int dwAnimate;
    int dwKillEdge;
    int dwFillBlanks;
    int unk0x20;
    int nAnimSpeed;
    unsigned char unk_28[0xC];
    int dwScan;
    int dwPops;
    char unk0x3C[0x08];
    char szFile[6][60];
    unsigned int dwDt1Mask;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x0C];
    int nWidth;
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    char unk0x3C[0x18];
    D2PresetUnitStrc* pPresetUnit;
};

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    D2DrlgCoordStrc pDrlgCoord;
    D2DrlgVertexStrc* pVertices;
    D2DrlgGridStrc pMapGrid;
    D2PresetUnitStrc* pPresetUnit;
    unsigned char unk_3C[0x4];
    int nPops;
    int* pPopsIndex;
    int* pPopsSubIndex;
    int* pPopsOrientation;
    D2DrlgCoordStrc* pPopsLocation;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int unk0x04;
    D2DrlgMapStrc* pMap;
    unsigned int dwFlags;
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pFloorGrid[2];
    D2DrlgGridStrc pCellGrid;
    D2DrlgGridStrc* pMazeGrid;
    D2CoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgStrc
{
    char unk0x00[0x464];
    void* hArchive;
    char unk0x468[0x10];
    void* pMempool;
};

struct D2DrlgTileInfoStrc
{
    int nPosX;
    int nPosY;
    int nTileIndex;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x2C];
    D2DrlgTileInfoStrc pTileInfo[32];
    char unk0x1AC[0x08];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
    char unk0x1D4[0x04];
    int nTileInfo;
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
    char unk0x24[0x04];
    unsigned int dwFlags;
    char unk0x2C[0x08];
    union
    {
        struct
        {
            D2DrlgCoordStrc pDrlgCoord;
        };
        struct
        {
            int nTileXPos;
            int nTileYPos;
            int nTileWidth;
            int nTileHeight;
        };
    };
    char unk0x44[0x0C];
    unsigned int dwDT1Mask;
    D2RoomTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
};
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEA0
void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags); // 0x0067CBF0
void __fastcall sub_0066ECE0_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066ECE0
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int bKillEdgeX, int bKillEdgeY); // 0x0066D290
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY); // 0x0066EDB0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EEE0
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066EC10
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pDrlgRoom, int nAnimSpeed, D2DrlgGridStrc* pWallGrids, int nWallLayers, D2DrlgGridStrc* pFloorGrids, int nFloorLayers, D2DrlgGridStrc* pCellGrid); // 0x0066D700
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid); // 0x0066D110
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom); // 0x0066CCB0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid); // 0x0067CDC0
static void __declspec(noinline) sub_00666990(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    void* pMapAI;
    int nUnitType;
    int nYpos;
    int bSpawned;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710
D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY); // 0x00667510

struct D2ObjectsTxt
{
    char unk0x00[0x167];
    unsigned char nSubClass;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed); // 0x00667620
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B970
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation); // 0x0067C590
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer); // 0x0067CD30
D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid); // 0x00666680
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap); // 0x00667970

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

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int DRLGPRESET_GetMonsterId(int nMonsterId, int nMonStatsCount)
{
    if (nMonsterId >= 0 && nMonsterId < nMonStatsCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x00667620
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed)
{
    D2PresetUnitStrc* pPresetUnit = pDrlgMap->pFile->pPresetUnit;
    int nX = pDrlgMap->pDrlgCoord.nPosX;
    int nY = pDrlgMap->pDrlgCoord.nPosY;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    for (; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        switch (pPresetUnit->nUnitType)
        {
        case 1:
        {
            const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
            if (pPresetUnit->nIndex < nMonStatsCount)
            {
                switch (DRLGPRESET_GetMonsterId(pPresetUnit->nIndex, nMonStatsCount))
                {
                case 204:
                case 205:
                case 371:
                case 372:
                    if (SEED_RollRandomNumber(pSeed) % 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            else if (pPresetUnit->nIndex - nMonStatsCount >= DATATBLS_GetSuperUniquesTxtRecordCount())
            {
                const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
                switch (pPresetUnit->nIndex - nCount - DATATBLS_GetSuperUniquesTxtRecordCount())
                {
                case 33:
                    if (!(SEED_RollRandomNumber(pSeed) & 3))
                    {
                        continue;
                    }
                    break;

                case 34:
                    if (!(SEED_RollRandomNumber(pSeed) & 1))
                    {
                        continue;
                    }
                    break;

                case 35:
                    if (SEED_RollRandomNumber(pSeed) & 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        case 2:
            switch (pPresetUnit->nIndex)
            {
            case 196:
            case 261:
                if (SEED_RollRandomNumber(pSeed) & 1)
                {
                    continue;
                }
                break;

            case 581:
                if (!(SEED_RollRandomNumber(pSeed) & 3))
                {
                    continue;
                }
                break;
            }
            break;
        }

        D2PresetUnitStrc* pNew = DRLGPRESET_CopyPresetUnit(pMemPool, pPresetUnit, nX, nY);
        pNew->pNext = pDrlgMap->pPresetUnit;
        pDrlgMap->pPresetUnit = pNew;
    }
}

// 0x00666E00
static void __stdcall sub_00666E00(D2DrlgMapStrc* pDrlgMap, int nPops)
{
    pDrlgMap->nPops = nPops;

    for (int i = 0; i < nPops; ++i)
    {
        D2DrlgCoordStrc* pPopsLocation = &pDrlgMap->pPopsLocation[i];
        const int nX1 = pPopsLocation->nPosX < pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY1 = pPopsLocation->nPosY < pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;
        const int nX2 = pPopsLocation->nPosX > pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY2 = pPopsLocation->nPosY > pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;

        pPopsLocation->nPosX = nX1 + pDrlgMap->pDrlgCoord.nPosX;
        pPopsLocation->nPosY = nY1 + pDrlgMap->pDrlgCoord.nPosY;
        pPopsLocation->nWidth = nX2 - nX1 + 1;
        pPopsLocation->nHeight = nY2 - nY1 + 1;
        pDrlgMap->pPopsIndex[i] = pDrlgMap->pPopsIndex[i] / 4 - 1;
    }
}

// 0x00666680
D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
    pDrlgRoom->dwDT1Mask = dwDT1Mask;
    pDrlgRoom->dwFlags |= dwRoomFlags;
    pDrlgRoom->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgRoom->pDrlgCoord.nPosY = pDrlgCoord->nPosY;
    pDrlgRoom->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
    pDrlgRoom->pDrlgCoord.nHeight = pDrlgCoord->nHeight;

    D2DrlgPresetRoomStrc* pDrlgPresetRoom = pDrlgRoom->pMaze;
    pDrlgPresetRoom->pMap = pDrlgMap;
    pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    pDrlgPresetRoom->dwFlags = dwPresetFlags;
    pDrlgPresetRoom->pMazeGrid = pMazeGrid;

    if (pMazeGrid)
    {
        pMazeGrid->nHeight |= 1;
    }

    if (!pDrlgPresetRoom->pMap->pLvlPrestTxtRecord->dwPopulate)
    {
        pDrlgRoom->dwFlags |= 0x800000;
    }

    DRLGROOM_AddRoomExToLevel(pLevel, pDrlgRoom);
    return pDrlgRoom;
}

// 0x00667970
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, pLevel->nLevelId);
    int nWarpFlag = 0x10;
    for (int i = 0; i < 8; ++i)
    {
        if (pVisArray[i] && DRLGWARP_GetWarpDestinationFromArray(pLevel, i) == -1)
        {
            nFlags |= nWarpFlag;
        }

        nWarpFlag <<= 1;
    }

    DRLGGRID_AlterAllGridFlags(pDrlgGrid, nFlags, 0);

    const int bScan = pDrlgMap->pLvlPrestTxtRecord->dwScan;
    const int nPops = pDrlgMap->pLvlPrestTxtRecord->dwPops;
    int nProcessedPops = 0;

    if (!bScan && !nPops)
    {
        return;
    }

    DRLGPRESET_LoadDrlgFile(&pDrlgMap->pFile, pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
    DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pLevel->pSeed);

    D2_ASSERT(pDrlgMap->pFile->nWidth == pDrlgMap->pDrlgCoord.nWidth, 0x8B9);
    D2_ASSERT(pDrlgMap->pFile->nHeight == pDrlgMap->pDrlgCoord.nHeight, 0x8BA);

    if (nPops)
    {
        pDrlgMap->pPopsIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8BF, 0);
        pDrlgMap->pPopsSubIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C0, 0);
        pDrlgMap->pPopsOrientation = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C1, 0);
        pDrlgMap->pPopsLocation = (D2DrlgCoordStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgCoordStrc) * nPops, &gszDrlgPresetSourceFile, 0x8C2, 0);
    }

    memset(pDrlgMap->pPopsIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsSubIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsOrientation, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsLocation, 0, sizeof(D2DrlgCoordStrc) * nPops);

    D2DrlgFileStrc* pFile = pDrlgMap->pFile;
    D2DrlgCoordStrc tDrlgCoord = { 0 };
    D2DrlgGridStrc tTileTypeGrid = { 0 };
    D2DrlgGridStrc tWallGrid = { 0 };
    int nTileTypeCellFlags[0x100];
    int nWallCellFlags[0x100];

    tDrlgCoord.nWidth = pFile->nWidth + 1;
    tDrlgCoord.nHeight = pFile->nHeight + 1;

    for (int i = 0; i < pFile->nWallLayers; ++i)
    {
        DRLGGRID_AssignCellsOffsetsAndFlags(&tTileTypeGrid, (int*)pFile->pTileTypeLayer[i], &tDrlgCoord, pFile->nWidth + 1, nTileTypeCellFlags);
        DRLGGRID_AssignCellsOffsetsAndFlags(&tWallGrid, (int*)pFile->pWallLayer[i], &tDrlgCoord, pFile->nWidth + 1, nWallCellFlags);

        for (int nY = 0; nY < pFile->nHeight; ++nY)
        {
            for (int nX = 0; nX < pFile->nWidth; ++nX)
            {
                const int nTileType = DRLGGRID_GetGridEntry(&tTileTypeGrid, nX, nY);
                const int nWallFlags = DRLGGRID_GetGridEntry(&tWallGrid, nX, nY);
                const unsigned int nIndex = ((unsigned int)nWallFlags >> 0x14) & 0x3F;
                const int nSubIndex = (nWallFlags >> 8) & 0xFF;
                const int nUpperBit = nWallFlags & 0x80000000;

                if (nTileType == 0xB || nTileType == 0xA)
                {
                    if (bScan && nIndex <= 7 && (nSubIndex == 0 || nSubIndex == 4 || nUpperBit))
                    {
                        int nGridX;
                        int nGridY;
                        if (bSingleRoom)
                        {
                            nGridX = 0;
                            nGridY = 0;
                        }
                        else
                        {
                            nGridX = nX / 8;
                            nGridY = nY / 8;
                        }

                        DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 1 << (nIndex + 4), 0);
                    }

                    if (nPops && nIndex >= 8 && nIndex <= 0x1D)
                    {
                        int nCounter = 0;
                        while (nCounter < nProcessedPops)
                        {
                            if (pDrlgMap->pPopsIndex[nCounter] == nIndex)
                            {
                                pDrlgMap->pPopsLocation[nCounter].nWidth = nX;
                                pDrlgMap->pPopsLocation[nCounter].nHeight = nY;
                                break;
                            }

                            ++nCounter;
                        }

                        if (nCounter == nProcessedPops)
                        {
                            pDrlgMap->pPopsIndex[nProcessedPops] = nIndex;
                            pDrlgMap->pPopsSubIndex[nProcessedPops] = nSubIndex;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosX = nX;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosY = nY;
                            ++nProcessedPops;
                        }
                    }

                    if (bScan && nIndex >= 0x1E && nIndex <= 0x21)
                    {
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosX = nX + pDrlgMap->pDrlgCoord.nPosX;
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosY = nY + pDrlgMap->pDrlgCoord.nPosY;

                        switch (nIndex)
                        {
                        case 0x1E:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex;
                            break;

                        case 0x1F:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex + 5;
                            break;

                        case 0x20:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xA;
                            break;

                        case 0x21:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xB;
                            break;

                        case 0x22:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xC;
                            break;
                        }

                        ++pLevel->nTileInfo;
                    }
                }
            }
        }

        DRLGGRID_ResetGrid(&tWallGrid);
        DRLGGRID_ResetGrid(&tTileTypeGrid);
    }

    if (nPops)
    {
        sub_00666E00(pDrlgMap, nProcessedPops);
    }

    if (bScan)
    {
        for (D2PresetUnitStrc* pPresetUnit = pFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
        {
            if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 0x23D && DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40)
            {
                int nGridX;
                int nGridY;
                if (bSingleRoom)
                {
                    nGridX = 0;
                    nGridY = 0;
                }
                else
                {
                    nGridX = pPresetUnit->nXpos / 5 / 8;
                    nGridY = pPresetUnit->nYpos / 5 / 8;
                }

                DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 0x30000, 0);
            }
        }
    }
}

// 0x00667ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom)
{
    int nCellPos[0x400];
    int nCellFlags[0x100];
    D2DrlgGridStrc tDrlgGrid;

    const int nGridWidth = pDrlgMap->pDrlgCoord.nWidth / 8 + 1;
    const int nGridHeight = pDrlgMap->pDrlgCoord.nHeight / 8 + 1;
    if (pDrlgMap->pLvlPrestTxtRecord->dwOutdoors)
    {
        nFlags |= 0x80000;
    }

    DRLGGRID_FillGrid(&tDrlgGrid, nGridWidth, nGridHeight, nCellPos, nCellFlags);
    DRLGPRESET_BuildPresetArea(pLevel, &tDrlgGrid, nFlags, bSingleRoom, pDrlgMap);

    const unsigned int dwDT1Mask = pDrlgMap->pLvlPrestTxtRecord->dwDt1Mask;
    D2DrlgRoomStrc* pDrlgRoom = 0;
    if (bSingleRoom)
    {
        const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, 0, 0);
        D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
        pRoom->dwDT1Mask = dwDT1Mask;
        pRoom->dwFlags |= nGridFlags;
        pRoom->pDrlgCoord.nPosX = pDrlgMap->pDrlgCoord.nPosX;
        pRoom->pDrlgCoord.nPosY = pDrlgMap->pDrlgCoord.nPosY;
        pRoom->pDrlgCoord.nWidth = pDrlgMap->pDrlgCoord.nWidth;
        pRoom->pDrlgCoord.nHeight = pDrlgMap->pDrlgCoord.nHeight;

        D2DrlgPresetRoomStrc* pDrlgPresetRoom = pRoom->pMaze;
        pDrlgPresetRoom->pMap = pDrlgMap;
        pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
        pDrlgPresetRoom->dwFlags = 1;
        pDrlgPresetRoom->pMazeGrid = 0;

        if (!pDrlgMap->pLvlPrestTxtRecord->dwPopulate)
        {
            pRoom->dwFlags |= 0x800000;
        }

        DRLGROOM_AddRoomExToLevel(pLevel, pRoom);
        pDrlgRoom = pRoom;
    }
    else
    {
        const int nXEnd = pDrlgMap->pDrlgCoord.nWidth + pDrlgMap->pDrlgCoord.nPosX;
        const int nYEnd = pDrlgMap->pDrlgCoord.nPosY + pDrlgMap->pDrlgCoord.nHeight;
        D2DrlgCoordStrc tDrlgCoord = { 0, 0, 0, 0 };

        for (int nY = pDrlgMap->pDrlgCoord.nPosY, nGridY = 0; nY < nYEnd; nY += 8, ++nGridY)
        {
            for (int nX = pDrlgMap->pDrlgCoord.nPosX, nGridX = 0; nX < nXEnd; nX += 8, ++nGridX)
            {
                const int nDeltaToEndX = nXEnd - nX;
                const int nDeltaToEndY = nYEnd - nY;
                tDrlgCoord.nPosX = nX;
                tDrlgCoord.nPosY = nY;

                if (nDeltaToEndX < 8)
                    tDrlgCoord.nWidth = nDeltaToEndX;
                else
                    tDrlgCoord.nWidth = 8;

                tDrlgCoord.nHeight = nDeltaToEndY;
                if (nDeltaToEndY >= 8)
                {
                    tDrlgCoord.nHeight = 8;
                }

                int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, nGridX, nGridY);
                int nMapFlags = pDrlgMap->pVertices ? DRLGGRID_GetGridEntry(&pDrlgMap->pMapGrid, nGridX, nGridY) : 0;
                if (tDrlgCoord.nWidth && tDrlgCoord.nHeight)
                {
                    pDrlgRoom = DRLGPRESET_InitPresetRoomData(pLevel, pDrlgMap, &tDrlgCoord, dwDT1Mask, nGridFlags, 0, (D2DrlgGridStrc*)nMapFlags);
                }
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
    return pDrlgRoom;
}
