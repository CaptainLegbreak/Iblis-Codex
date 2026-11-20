#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"



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

struct D2LvlPrestTxt
{
    int dwDef;
    int unk0x04;
    int dwPopulate;
    char unk0x0C[0x1C];
    int nSizeX;
    int nSizeY;
    char unk0x30[0x14];
    char szFile[6][60];
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




struct D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer); // 0x0067CD30
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);                                                  // 0x0067CDC0
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed); // 0x00667620
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304

static void DRLGPRESET_SpawnRiver(D2DrlgMapStrc* pDrlgMap, int nX, int nY, void* pMemPool);
static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid);

static __forceinline void __stdcall DRLGPRESET_AddRiverObject_Inline(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
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

    DUNGEON_GameTileToSubtileCoords(&nSubtileX, &nSubtileY);
    DUNGEON_GameTileToSubtileCoords(&nEndSubtileX, &nEndSubtileY);

    while (nSubtileY < nEndSubtileY)
    {
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 65, nSubtileX, nSubtileY);
        nSubtileY += 40;
    }
}

// 0x00666220
static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid)
{
    for (int nY = 0; nY < pDrlgMap->tCoords.nHeight; ++nY)
    {
        const int nX = nOffsetX > 0 ? nOffsetX : 0;
        int nObjectX = pDrlgMap->tCoords.nPosX + nOffsetX;
        int nObjectY = pDrlgMap->tCoords.nPosY + nY;
        DUNGEON_GameTileToSubtileCoords(&nObjectX, &nObjectY);
        nObjectX -= 5;

        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 40, nObjectX, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 5, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 10, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 15, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 42, nObjectX + 20, nObjectY);
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

// 0x006663C0
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

static void __stdcall sub_006664A0(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    int nX = pDrlgMap->tCoords.nPosX + pDrlgMap->tCoords.nWidth / 2;
    int nY = pDrlgMap->tCoords.nPosY + pDrlgMap->tCoords.nHeight / 2;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    const int nClassId = sgptDataTables->nMonStatsTxtRecordCount <= 266 ? -1 : 266;
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 1, nClassId, 1, nX, nY);
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

// build: context DRLGPRESET_SpawnHardcodedPresetUnits
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
