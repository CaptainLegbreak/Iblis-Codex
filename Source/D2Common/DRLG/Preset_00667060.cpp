#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2GameAux.h"
#include "D2GameObjs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
struct D2ActiveRoomStrc;



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




struct D2RoomStrc;


struct D2DrlgRoomStrc;






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
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY);                                          // 0x0066B980
void __fastcall DRLGGRID_FillNewCellFlags(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth);   // 0x0067CCC0
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);                              // 0x0067C590
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);                             // 0x0067C600
D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId);                                                  // 0x0061F0E0
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed);   // 0x00666ED0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                                                  // 0x0066C040
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                     // 0x00642BB0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                                        // 0x006424A0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation);             // 0x0067C4F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                                         // 0x00640E90
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom);                                                // 0x0066EEA0
void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY);   // 0x0066ECE0
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int bKillEdgeX, int bKillEdgeY);   // 0x0066D290
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY);   // 0x0066EDB0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom);                                                 // 0x0066EEE0
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY);   // 0x0066EC10
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pDrlgRoom, int nAnimSpeed, D2DrlgGridStrc* pWallGrid, int nWallLayers, D2DrlgGridStrc* pFloorGrid, int nFloorLayers, D2DrlgGridStrc* pCellGrid);   // 0x0066D700
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid);   // 0x0066D110
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom);                                               // 0x0066CCB0
int __stdcall sub_00604B90(void* pTile);                                                                  // 0x00604B90
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
void __fastcall sub_0067CBF0(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags);   // 0x0067CBF0
extern "C" const char gszEmptyAssertText;                                                                          // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                               // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                 // 0x00681E09
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

static void __stdcall sub_00666170(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 2, nIndex, 0, nX, nY);
    pPresetUnit->bSpawned |= 1;
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

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

// 0x00666220
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

static void sub_00666710(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgMapStrc* pDrlgMap = pDrlgRoom->pMaze->pMap;
    D2DrlgCoordStrc tDrlgCoord;
    tDrlgCoord.nPosX = pDrlgRoom->pDrlgCoord.nPosX;
    tDrlgCoord.nPosY = pDrlgRoom->pDrlgCoord.nPosY;
    tDrlgCoord.nWidth = pDrlgRoom->pDrlgCoord.nWidth;
    tDrlgCoord.nHeight = pDrlgRoom->pDrlgCoord.nHeight;
    sub_00643560_GameTileToSubtileCoords(&tDrlgCoord.nPosX, &tDrlgCoord.nPosY);
    sub_00643560_GameTileToSubtileCoords(&tDrlgCoord.nWidth, &tDrlgCoord.nHeight);

    D2PresetUnitStrc* pPresetUnit = pDrlgMap->pPresetUnit;
    const int nOffsetX = 5 * pDrlgRoom->pDrlgCoord.nPosX;
    D2PresetUnitStrc* pPrevious = 0;
    const int nOffsetY = 5 * pDrlgRoom->pDrlgCoord.nPosY;
    while (pPresetUnit)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&tDrlgCoord, pPresetUnit->nXpos, pPresetUnit->nYpos))
        {
            pPresetUnit->nXpos -= nOffsetX;
            pPresetUnit->nYpos -= nOffsetY;

            if (pPrevious)
            {
                pPrevious->pNext = pPresetUnit->pNext;
            }
            else
            {
                pDrlgMap->pPresetUnit = pPresetUnit->pNext;
            }

            pPresetUnit->pNext = pDrlgRoom->pPresetUnits;
            pDrlgRoom->pPresetUnits = pPresetUnit;

            if (pPrevious)
            {
                pPresetUnit = pPrevious->pNext;
            }
            else
            {
                pPresetUnit = pDrlgMap->pPresetUnit;
            }
        }
        else
        {
            pPrevious = pPresetUnit;
            pPresetUnit = pPresetUnit->pNext;
        }
    }
}

void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom)
{
    int i = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pDrlgMap = pMaze->pMap;
    D2DrlgFileStrc* pDrlgFile = pDrlgMap->ptFile;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    D2DrlgCoordStrc tDrlgCoord;
    tDrlgCoord.nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgMap->tCoords.nPosX;
    tDrlgCoord.nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgMap->tCoords.nPosY;
    tDrlgCoord.nWidth = pDrlgRoom->pDrlgCoord.nWidth + 1;
    tDrlgCoord.nHeight = pDrlgRoom->pDrlgCoord.nHeight + 1;

    const int nWidth = pDrlgMap->tCoords.nWidth + 1;

    for (i = 0; i < pDrlgFile->nWallLayers; ++i)
    {
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pWallGrid[i], (int*)pDrlgFile->pWallLayer[i], &tDrlgCoord, nWidth);
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pTileTypeGrid[i], (int*)pDrlgFile->pTileTypeLayer[i], &tDrlgCoord, nWidth);
    }

    if (pDrlgFile->nWallLayers)
    {
        DRLGGRID_AlterEdgeGridFlags(pMaze->pWallGrid, 0x84, 0);
    }

    for (i = 1; i < pDrlgFile->nWallLayers; ++i)
    {
        DRLGGRID_AlterAllGridFlags(&pMaze->pWallGrid[i], i << 18, 0);
    }

    for (i = 0; i < pDrlgFile->nFloorLayers; ++i)
    {
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pFloorGrid[i], (int*)pDrlgFile->pFloorLayer[i], &tDrlgCoord, nWidth);
        DRLGGRID_AlterAllGridFlags(&pMaze->pFloorGrid[i], i << 18, 0);
    }

    DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pCellGrid, (int*)pDrlgFile->pShadowLayer, &tDrlgCoord, nWidth);

    for (i = 0; i < pDrlgFile->nFloorLayers; ++i)
    {
        DRLGGRID_AlterEdgeGridFlags(&pMaze->pFloorGrid[i], 0x84, 0);
    }

    DRLGGRID_AlterEdgeGridFlags(&pMaze->pCellGrid, 0x84, 0);
    sub_00666710(pDrlgRoom);
}

void __fastcall DRLGPRESET_GetTombStoneTileCoords(D2DrlgRoomStrc* pDrlgRoom, D2CoordStrc** ppTombStoneTiles, int* pnTombStoneTiles)
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

static void __fastcall DRLGPRESET_AddTombStoneTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    int nTombStoneTiles = 0;

    if (pMaze->pTombStoneTiles)
    {
        return;
    }

    pMaze->pTombStoneTiles = (D2CoordStrc*)sub_0040B430(pMemPool, 6 * sizeof(D2CoordStrc), &gszDrlgPresetSourceFile, 1964, 0);

    for (int nY = 0; nY < pDrlgRoom->pDrlgCoord.nHeight; ++nY)
    {
        for (int nX = 0; nX < pDrlgRoom->pDrlgCoord.nWidth; ++nX)
        {
            const unsigned int nTileInfo = DRLGGRID_GetGridEntry(pMaze->pWallGrid, nX, nY);
            if (((unsigned char)(nTileInfo >> 20) & 0x3F) == 10 && (unsigned char)(nTileInfo >> 8) >= 23 && (unsigned char)(nTileInfo >> 8) <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nTileX = nX + pDrlgRoom->pDrlgCoord.nPosX;
                    int nTileY = nY + pDrlgRoom->pDrlgCoord.nPosY;
                    sub_00643560_GameTileToSubtileCoords(&nTileX, &nTileY);
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nTileX + 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nTileY + 2;
                    ++nTombStoneTiles;
                }
            }
        }
    }

    pMaze->nTombStoneTiles = nTombStoneTiles;
}

void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGROOMTILE_AllocTileGrid(pDrlgRoom);

    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pMazeMap = pMaze->pMap;
    const int bAnimate = pMazeMap->pLvlPrestTxtRecord->dwAnimate;
    const int bFillBlanks = pMazeMap->pLvlPrestTxtRecord->dwFillBlanks;

    int bKillEdgeX = 0;
    int bKillEdgeY = 0;
    if (pMazeMap->pLvlPrestTxtRecord->dwKillEdge)
    {
        bKillEdgeX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth == pMazeMap->tCoords.nPosX + pMazeMap->tCoords.nWidth;
        bKillEdgeY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight == pMazeMap->tCoords.nPosY + pMazeMap->tCoords.nHeight;
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
        sub_0067CBF0(&tTileTypeGrid, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1, aTileTypeCellPos, aTileTypeCellFlags);
        sub_0067CBF0(&tTileInfoGrid, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1, aTileInfoCellPos, aTileInfoCellFlags);
        break;
    }

    const int nWallLayers = pMaze->pMap->ptFile->nWallLayers;
    const int nFloorLayers = pMaze->pMap->ptFile->nFloorLayers;

    for (int i = 0; i < nFloorLayers; ++i)
    {
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pFloorGrid[i], i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, 0, bKillEdgeX, bKillEdgeY);
        }
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_CountWallWarpTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], bKillEdgeX, bKillEdgeY);
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pWallGrid[i], 0, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
        }
    }

    DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pCellGrid, 0, bKillEdgeX, bKillEdgeY);
    if (bAnimate)
    {
        DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 13, bKillEdgeX, bKillEdgeY);
    }

    if (bTownOrGraveyard)
    {
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &tTileInfoGrid, 0, bKillEdgeX, bKillEdgeY);
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

    pDrlgRoom->ptDrlgTiles->nTileWalls = pDrlgRoom->ptDrlgTiles->nWalls;
    pDrlgRoom->ptDrlgTiles->nTileFloors = pDrlgRoom->ptDrlgTiles->nFloors;
    pDrlgRoom->ptDrlgTiles->nTileRoofs = pDrlgRoom->ptDrlgTiles->nShadows;

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

    if (pDrlgRoom->ptDrlgLevel->eLevelId == 17)
    {
        DRLGPRESET_AddTombStoneTiles(pMemPool, pDrlgRoom);
    }
}

static int DRLGPRESET_IsTileInsideCoord(D2DrlgCoordStrc* pDrlgCoord, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData)
{
    const int nX = pDrlgRoom->pDrlgCoord.nPosX + pTileData->nPosX;
    const int nY = pDrlgRoom->pDrlgCoord.nPosY + pTileData->nPosY;
    return DRLGROOM_AreXYInsideCoordinates(pDrlgCoord, nX, nY);
}

// 0x00667060
static void __stdcall DRLGPRESET_TogglePopsVisibility(D2DrlgRoomStrc* ptRoom, int nPopSubIndex, D2DrlgCoordStrc* pDrlgCoord, int nTick, int bClose)
{
    if (!ptRoom->ptDrlgTiles)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 2619);
        exit(-1);
    }

    D2DrlgCoordStrc tDrlgCoord = { 0 };
    tDrlgCoord.nPosX = pDrlgCoord->nPosX - 1;
    tDrlgCoord.nPosY = pDrlgCoord->nPosY - 1;
    tDrlgCoord.nWidth = pDrlgCoord->nWidth + 2;
    tDrlgCoord.nHeight = pDrlgCoord->nHeight + 2;

    const int nWalls = ptRoom->ptDrlgTiles->nTileWalls;
    D2DrlgTileDataStrc* pWallTiles = ptRoom->ptDrlgTiles->pTiles.pWallTiles;
    for (int i = 0; i < nWalls; ++i)
    {
        D2DrlgTileDataStrc* pTileData = &pWallTiles[i];
        if (pTileData->dwFlags & 0x200 && DRLGPRESET_IsTileInsideCoord(&tDrlgCoord, ptRoom, pTileData))
        {
            if (bClose)
            {
                pTileData->dwPopFlags |= 4;
                pTileData->nPopTick = nTick;
            }
            else
            {
                pTileData->dwPopFlags &= ~4;
                pTileData->dwFlags &= ~8;
            }
        }
        else if (!(pTileData->dwFlags & 0x100) && sub_00604B90(pTileData->pTile) == nPopSubIndex && DRLGPRESET_IsTileInsideCoord(&tDrlgCoord, ptRoom, pTileData))
        {
            pTileData->dwPopFlags |= 2;
            if (bClose)
            {
                pTileData->nGreen = 0;
                pTileData->nBlue = 255;
                if (!pTileData->nRed)
                {
                    pTileData->nPopTick = nTick;
                }
                else
                {
                    pTileData->nPopTick = nTick - 500 * pTileData->nRed / 255;
                }
            }
            else
            {
                pTileData->nGreen = 255;
                pTileData->nBlue = 0;
                if (pTileData->nRed == 255)
                {
                    pTileData->nPopTick = nTick;
                }
                else
                {
                    pTileData->nPopTick = nTick + 500 * (pTileData->nRed - 255) / 255;
                }
            }
        }
    }
}

void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom)
{
    D2DrlgMapStrc* pDrlgMap;
    int bUpdate;
    int nTick;
    int nPopIndex;

    pDrlgMap = 0;
    bUpdate = 0;
    nTick = GetTickCount() + 500;
    nPopIndex = 0;
    int i;
    int j;
    D2DrlgRoomStrc* pAdjacentRoom;
    D2DrlgMapStrc* pAdjacentMap;
    int nOrientation;

    if (pDrlgRoom->nType == 2)
    {
        pDrlgMap = pDrlgRoom->pMaze->pMap;
        for (i = 0; i < pDrlgMap->nPops; ++i)
        {
            D2DrlgCoordStrc tDrlgCoord = { 0 };
            tDrlgCoord.nPosX = 5 * pDrlgMap->pPopsLocation[i].nPosX;
            tDrlgCoord.nPosY = 5 * pDrlgMap->pPopsLocation[i].nPosY;
            tDrlgCoord.nWidth = pDrlgMap->pLvlPrestTxtRecord->dwPopPad + 5 * pDrlgMap->pPopsLocation[i].nWidth;
            tDrlgCoord.nHeight = pDrlgMap->pLvlPrestTxtRecord->dwPopPad + 5 * pDrlgMap->pPopsLocation[i].nHeight;

            if (DRLGROOM_AreXYInsideCoordinates(&tDrlgCoord, nX, nY))
            {
                nPopIndex = pDrlgMap->pPopsIndex[i];
                break;
            }
        }
    }

    for (i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        pAdjacentRoom = pDrlgRoom->ppRoomsNear[i];
        if (pAdjacentRoom->nType == 2 && pAdjacentRoom->pRoom)
        {
            pAdjacentMap = pAdjacentRoom->pMaze->pMap;
            for (j = 0; j < pAdjacentMap->nPops; ++j)
            {
                nOrientation = pAdjacentMap->pPopsOrientation[j];
                if ((pAdjacentMap != pDrlgMap || pAdjacentMap->pPopsIndex[j] != nPopIndex) && nOrientation)
                {
                    DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nTick, 1);
                    bUpdate = 1;
                }

                if (pAdjacentMap == pDrlgMap && pAdjacentMap->pPopsIndex[j] == nPopIndex)
                {
                    if (!nOrientation)
                    {
                        DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nTick, 0);
                        bUpdate = 1;
                    }
                    else if (bOtherRoom)
                    {
                        DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nOrientation, 0);
                        bUpdate = 1;
                    }
                }
            }
        }
    }

    if (bUpdate)
    {
        for (i = 0; i < pDrlgRoom->nRoomsNear; ++i)
        {
            pAdjacentRoom = pDrlgRoom->ppRoomsNear[i];
            if (pAdjacentRoom->nType == 2)
            {
                pAdjacentMap = pAdjacentRoom->pMaze->pMap;
                for (j = 0; j < pAdjacentMap->nPops; ++j)
                {
                    if (pAdjacentMap != pDrlgMap || pAdjacentMap->pPopsIndex[j] != nPopIndex)
                    {
                        pAdjacentMap->pPopsOrientation[j] = 0;
                    }

                    if (pAdjacentMap == pDrlgMap && pAdjacentMap->pPopsIndex[j] == nPopIndex)
                    {
                        pAdjacentMap->pPopsOrientation[j] = nTick;
                    }
                }
            }
        }
    }
}

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

        pPopsLocation->nPosX = nX1 + pDrlgMap->tCoords.nPosX;
        pPopsLocation->nPosY = nY1 + pDrlgMap->tCoords.nPosY;
        pPopsLocation->nWidth = nX2 - nX1 + 1;
        pPopsLocation->nHeight = nY2 - nY1 + 1;
        pDrlgMap->pPopsIndex[i] = pDrlgMap->pPopsIndex[i] / 4 - 1;
    }
}

static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, D2DrlgMapStrc* pDrlgMap, int bSingleRoom)
{
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, pLevel->eLevelId);
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

    DRLGPRESET_LoadDrlgFile(&pDrlgMap->ptFile, pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
    DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pLevel->pSeed);

    if (pDrlgMap->ptFile->nWidth != pDrlgMap->tCoords.nWidth)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 2233);
        exit(-1);
    }

    if (pDrlgMap->ptFile->nHeight != pDrlgMap->tCoords.nHeight)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 2234);
        exit(-1);
    }

    if (nPops)
    {
        pDrlgMap->pPopsIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 2239, 0);
        pDrlgMap->pPopsSubIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 2240, 0);
        pDrlgMap->pPopsOrientation = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 2241, 0);
        pDrlgMap->pPopsLocation = (D2DrlgCoordStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgCoordStrc) * nPops, &gszDrlgPresetSourceFile, 2242, 0);
    }

    memset(pDrlgMap->pPopsIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsSubIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsOrientation, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsLocation, 0, sizeof(D2DrlgCoordStrc) * nPops);

    D2DrlgFileStrc* pFile = pDrlgMap->ptFile;
    D2DrlgCoordStrc tDrlgCoord = { 0 };
    D2DrlgGridStrc tTileTypeGrid = { 0 };
    D2DrlgGridStrc tWallGrid = { 0 };
    int nTileTypeCellFlags[256];
    int nWallCellFlags[256];

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
                const unsigned int nIndex = ((unsigned int)nWallFlags >> 20) & 0x3F;
                const int nSubIndex = (nWallFlags >> 8) & 0xFF;
                const int nUpperBit = nWallFlags & 0x80000000;

                if (nTileType == 11 || nTileType == 10)
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

                    if (nPops && nIndex >= 8 && nIndex <= 29)
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

                    if (bScan && nIndex >= 30 && nIndex <= 33)
                    {
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosX = nX + pDrlgMap->tCoords.nPosX;
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosY = nY + pDrlgMap->tCoords.nPosY;

                        switch (nIndex)
                        {
                        case 30:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex;
                            break;

                        case 31:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex + 5;
                            break;

                        case 32:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 10;
                            break;

                        case 33:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 11;
                            break;

                        case 34:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 12;
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
            if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 573 && DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40)
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

D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom)
{
    int nCellPos[1024];
    int nCellFlags[256];
    D2DrlgGridStrc tDrlgGrid;

    const int nGridWidth = pDrlgMap->tCoords.nWidth / 8 + 1;
    const int nGridHeight = pDrlgMap->tCoords.nHeight / 8 + 1;
    if (pDrlgMap->pLvlPrestTxtRecord->dwOutdoors)
    {
        nFlags |= 0x80000;
    }

    sub_0067CBF0(&tDrlgGrid, nGridWidth, nGridHeight, nCellPos, nCellFlags);
    DRLGPRESET_BuildPresetArea(pLevel, &tDrlgGrid, nFlags, pDrlgMap, bSingleRoom);

    const unsigned int dwDT1Mask = pDrlgMap->pLvlPrestTxtRecord->dwDt1Mask;
    D2DrlgRoomStrc* pDrlgRoom = 0;
    if (bSingleRoom)
    {
        const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, 0, 0);
        D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
        pRoom->dwDT1Mask = dwDT1Mask;
        pRoom->dwFlags |= nGridFlags;
        pRoom->pDrlgCoord.nPosX = pDrlgMap->tCoords.nPosX;
        pRoom->pDrlgCoord.nPosY = pDrlgMap->tCoords.nPosY;
        pRoom->pDrlgCoord.nWidth = pDrlgMap->tCoords.nWidth;
        pRoom->pDrlgCoord.nHeight = pDrlgMap->tCoords.nHeight;

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
        int nY = pDrlgMap->tCoords.nPosY;
        const int nXEnd = pDrlgMap->tCoords.nPosX + pDrlgMap->tCoords.nWidth;
        const int nYEnd = pDrlgMap->tCoords.nPosY + pDrlgMap->tCoords.nHeight;
        D2DrlgCoordStrc tDrlgCoord = { 0 };
        int nGridY = 0;

        for (; nY < nYEnd; nY += 8, ++nGridY)
        {
            const int nDeltaToEndY = nYEnd - nY;
            tDrlgCoord.nPosY = nY;
            int nGridX = 0;
            for (int nX = pDrlgMap->tCoords.nPosX; nX < nXEnd; nX += 8, ++nGridX)
            {
                const int nDeltaToEndX = nXEnd - nX;
                tDrlgCoord.nPosX = nX;

                tDrlgCoord.nWidth = nDeltaToEndX;
                if (nDeltaToEndX >= 8)
                {
                    tDrlgCoord.nWidth = 8;
                }

                tDrlgCoord.nHeight = nDeltaToEndY;
                if (nDeltaToEndY >= 8)
                {
                    tDrlgCoord.nHeight = 8;
                }

                const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, nGridX, nGridY);
                const int nMapFlags = pDrlgMap->pVertices ? DRLGGRID_GetGridEntry(&pDrlgMap->pMapGrid, nGridX, nGridY) : 0;

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

void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel)
{
    D2DrlgPresetInfoStrc* pPreset = pLevel->pPreset;
    D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecordFromLevelId(pLevel->eLevelId);
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pLvlPrestTxtRecord->dwDef, &pLevel->pLevelCoords, &pLevel->pSeed);
    pPreset->pDrlgMap = pDrlgMap;

    if (pPreset->nDirection == -1)
    {
        pPreset->nDirection = pDrlgMap->nPickedFile;
    }
    else
    {
        pDrlgMap->nPickedFile = pPreset->nDirection;
    }

    DRLGPRESET_BuildArea(pLevel, pPreset->pDrlgMap, 0, 0);

    if (pLevel->eLevelId == 40 || pLevel->eLevelId == 103 || pLevel->eLevelId == 109)
    {
        if (pLevel->pDrlg->pfTownAutomap && pDrlgMap->pLvlPrestTxtRecord->dwAutoMap)
        {
            pLevel->pDrlg->pfTownAutomap(pLevel->eLevelId, pDrlgMap->nPickedFile, pLevel->pLevelCoords.nPosX + pLevel->pLevelCoords.nWidth / 2, pLevel->pLevelCoords.nPosY + pLevel->pLevelCoords.nHeight / 2);
        }
    }
    else
    {
        if (pLevel->pDrlg->pfAutomap && pDrlgMap->pLvlPrestTxtRecord->dwAutoMap)
        {
            int* pVisLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
            for (int i = 0; i < 8; ++i)
            {
                if (pVisLevelIds[i])
                {
                    D2DrlgLevelStrc* pCurrentLevel = DRLG_GetLevel(pLevel->pDrlg, pVisLevelIds[i]);
                    if (!pCurrentLevel->ptRoomFirst)
                    {
                        DRLG_InitLevel(pCurrentLevel);
                    }
                }
            }

            for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
            {
                DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
                pLevel->pDrlg->pfAutomap((D2RoomStrc*)pDrlgRoom->pRoom);
            }
        }
    }
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
