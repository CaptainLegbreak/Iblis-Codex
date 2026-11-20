#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
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

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};


struct D2DrlgFileStrc
{
    char unk0x00[0x10];
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    void* pFloorLayer[2];
};


union D2C_PackedTileInformation
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int bIsWall : 1;
        unsigned int bIsFloor : 1;
        unsigned int bLOS : 1;
        unsigned int bEnclosed : 1;
        unsigned int bExit : 1;
        unsigned int bUnk0x20 : 1;
        unsigned int bLayerBelow : 1;
        unsigned int bLayerAbove : 1;
        unsigned int nTileSequence : 8;
        unsigned int bFillLOS : 1;
        unsigned int bUnwalkable : 1;
        unsigned int nWallLayer : 2;
        unsigned int nTileStyle : 6;
        unsigned int bRevealHidden : 1;
        unsigned int bShadow : 1;
        unsigned int bLinkage : 1;
        unsigned int bObjectWall : 1;
        unsigned int bUnk0x40000000 : 1;
        unsigned int bHidden : 1;
    };
};

struct D2DrlgVertexStrc;

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* ptFile;
    D2DrlgCoordStrc tCoords;
    D2DrlgVertexStrc* pVertices;
    D2DrlgGridStrc pMapGrid;
    D2PresetUnitStrc* pPresetUnit;
    int bInited;
    int unk0x40;
    int* pPopsIndex;
    int* pPopsSubIndex;
    int* pPopsOrientation;
    int* pPopsLocation;
    D2DrlgMapStrc* pNext;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2DrlgMapStrc* pMap;
    unsigned int dwFlags;
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pFloorGrid[2];
    D2DrlgGridStrc pCellGrid;
    D2DrlgGridStrc* pMazeGrid;
    D2DrlgCoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgPresetLevelStrc
{
    D2DrlgMapStrc* pDrlgMap;
};

struct D2DrlgStrc
{
    char unk0x000[0x464];
    void* hArchive;
    char unk0x468[0x10];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgPresetLevelStrc* pPreset;
    char unk0x018[0x19C];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int eLevelId;
};


struct D2DrlgRoomStrc
{
    char unk0x00[0x14];
    D2SeedStrc pSeed;
    char unk0x1C[0x4];
    D2DrlgPresetRoomStrc* pMaze;
    char unk0x24[0x4];
    unsigned int dwFlags;
    char unk0x2C[0x8];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x4];
    int nType;
    char unk0x4C[0x4];
    unsigned int dwDT1Mask;
    char unk0x54[0x4];
    D2DrlgLevelStrc* ptDrlgLevel;
};

extern "C" const char gszDrlgPresetSourceFile;                                                                    // 0x006EE7C4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                                  // 0x0061F0B0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                            // 0x0066B3E0
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);                          // 0x0066B970
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);                                     // 0x0067CD90
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices);                              // 0x0067D1E0
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);                                                // 0x00668300
void __stdcall sub_00643560_GameTileToSubtileCoords(int* pX, int* pY);                                                            // 0x00643560
struct D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY);   // 0x0066BF30
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer);   // 0x0067CD30
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);                                                       // 0x0067CDC0
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile);              // 0x00665F40
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed);                    // 0x00667620
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                            // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x006829C0
#pragma intrinsic(memset, memcpy)

D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    D2MapAIStrc* pNewMapAI = (D2MapAIStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIStrc), &gszDrlgPresetSourceFile, 1396, 0);
    memset(pNewMapAI, 0, sizeof(D2MapAIStrc));
    pNewMapAI->nPathNodes = pMapAI->nPathNodes;
    pNewMapAI->pPosition = (D2MapAIPathPositionStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes, &gszDrlgPresetSourceFile, 1401, 0);
    memcpy(pNewMapAI->pPosition, pMapAI->pPosition, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes);
    return pNewMapAI;
}

D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc** ppMapAI2)
{
    *ppMapAI2 = *ppMapAI1;
    *ppMapAI1 = 0;

    return *ppMapAI2;
}

void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    sub_0040B480(pMemPool, pMapAI->pPosition, &gszDrlgPresetSourceFile, 1431, 0);
    sub_0040B480(pMemPool, pMapAI, &gszDrlgPresetSourceFile, 1432, 0);
}

// 0x00666170
static void __stdcall sub_00666170(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 2, nIndex, 0, nX, nY);
    pPresetUnit->bSpawned |= 1;
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

// 0x006661A0
static void DRLGPRESET_SpawnRiver(D2DrlgMapStrc* pDrlgMap, int nX, int nY, void* pMemPool)
{
    int nSubtileX = nX;
    int nSubtileY = nY;
    int nEndSubtileX = 0;
    int nEndSubtileY = nY + pDrlgMap->ptFile->nHeight;

    sub_00643560_GameTileToSubtileCoords(&nSubtileX, &nSubtileY);
    sub_00643560_GameTileToSubtileCoords(&nEndSubtileX, &nEndSubtileY);

    while (nSubtileY < nEndSubtileY)
    {
        sub_00666170(pDrlgMap, pMemPool, 65, nSubtileX, nSubtileY);
        nSubtileY += 40;
    }
}

static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid)
{
    for (int nY = 0; nY < pDrlgMap->tCoords.nHeight; ++nY)
    {
        const int nX = nOffsetX > 0 ? nOffsetX : 0;
        int nObjectX = pDrlgMap->tCoords.nPosX + nOffsetX;
        int nObjectY = pDrlgMap->tCoords.nPosY + nY;
        sub_00643560_GameTileToSubtileCoords(&nObjectX, &nObjectY);
        nObjectX -= 5;

        sub_00666170(pDrlgMap, pMemPool, 40, nObjectX, nObjectY);
        sub_00666170(pDrlgMap, pMemPool, 41, nObjectX + 5, nObjectY);
        sub_00666170(pDrlgMap, pMemPool, 41, nObjectX + 10, nObjectY);
        sub_00666170(pDrlgMap, pMemPool, 41, nObjectX + 15, nObjectY);
        sub_00666170(pDrlgMap, pMemPool, 42, nObjectX + 20, nObjectY);
        const unsigned int nGridEntry = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
        if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 4)
        {
            switch ((unsigned char)(nGridEntry >> 8))
            {
            case 0:
            case 4:
            case 8:
            case 16:
            case 29:
            case 39:
                nY += 3;
                break;

            default:
                break;
            }
        }
    }
}

static void sub_006663C0(D2DrlgMapStrc* pDrlgMap, void* pMemPool); // 0x006663C0

// build: context sub_006663C0
static void sub_006663C0(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    D2DrlgCoordStrc tDrlgCoord;
    D2DrlgGridStrc tDrlgGrid;
    int nCellFlags[256];

    tDrlgCoord.nPosX = 0;
    tDrlgCoord.nPosY = 0;
    tDrlgCoord.nWidth = pDrlgMap->tCoords.nWidth;
    tDrlgCoord.nHeight = pDrlgMap->tCoords.nHeight;
    DRLGGRID_AssignCellsOffsetsAndFlags(&tDrlgGrid, (int*)pDrlgMap->ptFile->pFloorLayer[0], &tDrlgCoord, pDrlgMap->tCoords.nWidth + 1, nCellFlags);

    tDrlgCoord.nPosX = pDrlgMap->tCoords.nPosX;
    tDrlgCoord.nPosY = pDrlgMap->tCoords.nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->dwDef == 27)
    {
        DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX - 1 + 1, tDrlgCoord.nPosY, pMemPool);
        DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, -1, &tDrlgGrid);
    }
    else
    {
        for (int nOffsetX = 0; nOffsetX < tDrlgCoord.nWidth; ++nOffsetX)
        {
            const unsigned int nGridEntry = DRLGGRID_GetGridEntry(&tDrlgGrid, nOffsetX, 0);
            if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 2 && (unsigned char)(nGridEntry >> 8) == 24)
            {
                DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX + nOffsetX + 1, tDrlgCoord.nPosY, pMemPool);
                DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, nOffsetX, &tDrlgGrid);
                nOffsetX += 4;
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
}

// 0x006664A0
static void __stdcall sub_006664A0(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    int nX = pDrlgMap->tCoords.nPosX + pDrlgMap->tCoords.nWidth / 2;
    int nY = pDrlgMap->tCoords.nPosY + pDrlgMap->tCoords.nHeight / 2;
    sub_00643560_GameTileToSubtileCoords(&nX, &nY);

    const int nClassId = sgptDataTables->nMonStatsTxtRecordCount <= 266 ? -1 : 266;
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 1, nClassId, 1, nX, nY);
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

static void __stdcall DRLGPRESET_FreeDrlgGrids(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze && pMaze->pMap)
    {
        D2DrlgFileStrc* pDrlgFile = pMaze->pMap->ptFile;
        if (pDrlgFile)
        {
            const int nWallLayers = pDrlgFile->nWallLayers;
            for (int i = 0; i < nWallLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pTileTypeGrid[i]);
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pWallGrid[i]);
            }

            const int nFloorLayers = pDrlgFile->nFloorLayers;
            for (int i = 0; i < nFloorLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pFloorGrid[i]);
            }

            DRLGGRID_FreeGrid(pMemPool, &pMaze->pCellGrid);
        }
    }
}

void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pMemPool, pDrlgRoom);

        if (pMaze->pTombStoneTiles)
        {
            sub_0040B480(pMemPool, pMaze->pTombStoneTiles, &gszDrlgPresetSourceFile, 1783, 0);
        }

        sub_0040B480(pMemPool, pMaze, &gszDrlgPresetSourceFile, 1786, 0);
        pDrlgRoom->pMaze = 0;
    }
}

void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, pDrlgRoom);
    }
}

void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = (D2DrlgPresetRoomStrc*)sub_0040B430(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgPresetRoomStrc), &gszDrlgPresetSourceFile, 1807, 0);
    memset(pMaze, 0, sizeof(D2DrlgPresetRoomStrc));
    pDrlgRoom->pMaze = pMaze;
}

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

void __fastcall DRLGPRESET_GetTombStoneTileCoords(D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordStrc** ppTombStoneTiles, int* pnTombStoneTiles)
{
    if (pDrlgRoom->nType != 2)
    {
        *ppTombStoneTiles = 0;
        *pnTombStoneTiles = 0;
    }
    else
    {
        D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
        *ppTombStoneTiles = pMaze->pTombStoneTiles;
        *pnTombStoneTiles = pMaze->nTombStoneTiles;
    }
}

int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile)
{
    return pDrlgMap->nPickedFile = nPickedFile;
}

int __fastcall DRLGPRESET_GetSizeX(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeX;
}

int __fastcall DRLGPRESET_GetSizeY(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeY;
}

char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    return pMaze->pMap->pLvlPrestTxtRecord->szFile[pMaze->pMap->nPickedFile];
}

void __fastcall DRLGPRESET_ResetDrlgMap(D2DrlgLevelStrc* pLevel, int bKeepPreset)
{
    pLevel->pPreset->pDrlgMap = 0;

    if (!bKeepPreset)
    {
        sub_0040B480(pLevel->pDrlg->pMempool, pLevel->pPreset, &gszDrlgPresetSourceFile, 2906, 0);
        pLevel->pPreset = 0;
    }
}

D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY)
{
    D2PresetUnitStrc* pNewPresetUnit = (D2PresetUnitStrc*)sub_0040B430(pMemPool, sizeof(D2PresetUnitStrc), &gszDrlgPresetSourceFile, 1354, 0);
    memset(pNewPresetUnit, 0, sizeof(D2PresetUnitStrc));
    pNewPresetUnit->nUnitType = pPresetUnit->nUnitType;
    pNewPresetUnit->nIndex = pPresetUnit->nIndex;
    pNewPresetUnit->nMode = pPresetUnit->nMode;
    pNewPresetUnit->nXpos = nX + pPresetUnit->nXpos;
    pNewPresetUnit->nYpos = nY + pPresetUnit->nYpos;
    pNewPresetUnit->bSpawned = pPresetUnit->bSpawned;

    if (pPresetUnit->pMapAI)
    {
        pNewPresetUnit->pMapAI = DRLGPRESET_CreateCopyOfMapAI(pMemPool, pPresetUnit->pMapAI);

        for (unsigned int i = 0; i < (unsigned int)pNewPresetUnit->pMapAI->nPathNodes; ++i)
        {
            pNewPresetUnit->pMapAI->pPosition[i].nX += nX;
            pNewPresetUnit->pMapAI->pPosition[i].nY += nY;
        }
    }

    return pNewPresetUnit;
}

void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit)
{
    if (pPresetUnit->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pMemPool, pPresetUnit->pMapAI);
    }

    sub_0040B480(pMemPool, pPresetUnit, &gszDrlgPresetSourceFile, 1387, 0);
}

// 0x00667890
void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgMapStrc* pDrlgMap = pDrlgRoom->pMaze->pMap;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    if (!pDrlgMap->ptFile)
    {
        DRLGPRESET_LoadDrlgFile(&pDrlgMap->ptFile, pDrlgRoom->ptDrlgLevel->pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
        DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pDrlgRoom->pSeed);
    }

    if (pDrlgMap->bInited == 1)
    {
        pDrlgMap->bInited = 0;

        switch (pDrlgMap->nLevelPrest)
        {
        case 4:
        case 5:
        case 6:
        case 7:
            if (pDrlgRoom->ptDrlgLevel->eLevelId == 2 && pDrlgMap->nPickedFile == 3)
            {
                sub_006664A0(pDrlgMap, pMemPool);
            }
            break;

        case 1:
        case 3:
        case 26:
        case 27:
        case 28:
        case 300:
            if (pDrlgRoom->dwFlags & 0x40000)
            {
                sub_006663C0(pDrlgMap, pMemPool);
            }
            break;

        default:
            break;
        }
    }

    pDrlgRoom->dwFlags |= 0x2000000;
}

void __fastcall DRLGPRESET_FreeDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgMapStrc* pMap = pDrlgMap;
    while (pMap)
    {
        D2DrlgMapStrc* pNextMap = pMap->pNext;

        DRLGGRID_FreeGrid(pMemPool, &pMap->pMapGrid);
        DRLGVER_FreeVertices(pMemPool, &pMap->pVertices);
        DRLGPRESET_FreeDrlgFile(&pMap->ptFile);

        D2PresetUnitStrc* pPresetUnit = pMap->pPresetUnit;
        while (pPresetUnit)
        {
            D2PresetUnitStrc* pFreePresetUnit = pPresetUnit;
            pPresetUnit = pPresetUnit->pNext;
            DRLGPRESET_FreePresetUnit(pMemPool, pFreePresetUnit);
        }

        if (pMap->pPopsIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsIndex, &gszDrlgPresetSourceFile, 2554, 0);
        }

        if (pMap->pPopsSubIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsSubIndex, &gszDrlgPresetSourceFile, 2555, 0);
        }

        if (pMap->pPopsOrientation)
        {
            sub_0040B480(pMemPool, pMap->pPopsOrientation, &gszDrlgPresetSourceFile, 2556, 0);
        }

        if (pMap->pPopsLocation)
        {
            sub_0040B480(pMemPool, pMap->pPopsLocation, &gszDrlgPresetSourceFile, 2557, 0);
        }

        sub_0040B480(pMemPool, pMap, &gszDrlgPresetSourceFile, 2559, 0);
        pMap = pNextMap;
    }
}
