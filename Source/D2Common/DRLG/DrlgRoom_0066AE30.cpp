#include "D2Common.h"

struct D2DrlgVertexStrc;
struct D2RoomDataStrc;

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
    int unk0x10;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    char unk0x054[0x10];
    D2DrlgVertexStrc* pVertex;
    D2DrlgVertexStrc* pPathStarts[6];
    char pVertices[4][0x78];
    int nVertices;
    D2RoomDataStrc* pRoomData;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x04];
    D2DrlgCoordStrc pLevelCoords;
    char unk0x02C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x08];
    int nLevelType;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x28];
    unsigned int dwFlags;
    char unk0x2C[0x24];
    unsigned int dwDT1Mask;
    char unk0x54[0x04];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x0C];
    D2TileLibraryHeaderStrc* pTiles;
};

struct D2LvlTypesTxt
{
    char szFile[32][60];
};

struct D2DrlgFileStrc
{
    char unk0x00[0x14];
    int nWallLayers;
};

struct D2LvlSubTxt
{
    char unk0x00[0x50];
    D2DrlgFileStrc* pDrlgFile;
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pFloorGrid;
    D2DrlgGridStrc pShadowGrid;
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY);  // 0x00642630
void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2RoomDataStrc* pRoomData);                           // 0x0066B530
int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);                                       // 0x00668300
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pDrlgGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pDrlgGrid);                               // 0x0067CD90
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices);                        // 0x0067D1E0

// 0x0066AE30
D2DrlgRoomStrc* __fastcall sub_0066AE30(D2DrlgLevelStrc* pLevel, int nUnused, int nOffsetX, int nOffsetY)
{
    const int nX = pLevel->pLevelCoords.nWidth / 2 + pLevel->pLevelCoords.nPosX + nOffsetX - 2;
    const int nY = pLevel->pLevelCoords.nHeight / 2 + pLevel->pLevelCoords.nPosY + nOffsetY - 2;
    return DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
}

// 0x0066B860
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistanceToAssumeCollision)
{
    int nSignedDistanceX;
    return DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(pDrlgCoord1, pDrlgCoord2, nMaxDistanceToAssumeCollision, &nSignedDistanceX, &nMaxDistanceToAssumeCollision);
}

// 0x0066F240
void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlTypesTxt* pLvlTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(pDrlgRoom->pLevel->nLevelType);

    unsigned int dwDT1Mask = pDrlgRoom->dwDT1Mask;
    for (unsigned int nFileIndex = 0; dwDT1Mask && nFileIndex < 32; dwDT1Mask >>= 1, ++nFileIndex)
    {
        if (dwDT1Mask & 1)
        {
            TileLibraryAddProject(&pDrlgRoom->pTiles, pLvlTypesTxtRecord->szFile[nFileIndex]);
        }
    }

    char szPath[260] = { 0 };

    wsprintfA(szPath, "%s\\Tiles\\Act1\\Outdoors\\Blank.dt1", szDataGlobal_006D4118);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    wsprintfA(szPath, "%s\\Tiles\\Act1\\Barracks\\InvisWal.dt1", szDataGlobal_006D4118);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    wsprintfA(szPath, "%s\\Tiles\\Act1\\Barracks\\Warp.dt1", szDataGlobal_006D4118);
    TileLibraryAddProject(&pDrlgRoom->pTiles, szPath);

    pDrlgRoom->dwFlags |= 0x1000000;
}

// 0x00670630
void __fastcall DRLGTILESUB_FreeDrlgFile(D2LvlSubTxt* pLvlSubTxtRecord)
{
    if (pLvlSubTxtRecord->pDrlgFile)
    {
        for (int i = 0; i < pLvlSubTxtRecord->pDrlgFile->nWallLayers; ++i)
        {
            DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pWallGrid[i]);
            DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pTileTypeGrid[i]);
        }

        DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pFloorGrid);
        DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pShadowGrid);

        DRLGPRESET_FreeDrlgFile(&pLvlSubTxtRecord->pDrlgFile);
    }
}

// 0x00674160
void __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[0], nX, nY, 0, 3);
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0, 3);
}

// 0x006741A0
void __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[0], nX, nY, 0, 3);
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x100, 3);
}

// 0x006741E0
unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    const unsigned int nPackedValue = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
    return ((nPackedValue >> 10) & 1) == 0;
}

// 0x006754C0
void __fastcall DRLGOUTDOORS_FreeOutdoorInfo(D2DrlgLevelStrc* pLevel, int bKeepRoomData)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;

    if (pOutdoors->dwFlags & 0x20)
    {
        pOutdoors->dwFlags ^= 0x20;
    }

    if (pOutdoors->dwFlags & 0x40)
    {
        pOutdoors->dwFlags ^= 0x40;
    }

    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[0]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[1]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[2]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[3]);

    DRLGVER_FreeVertices(pMemPool, &pOutdoors->pVertex);

    for (int i = 0; i < 6; ++i)
    {
        DRLGVER_FreeVertices(pMemPool, &pOutdoors->pPathStarts[i]);
    }

    memset(pOutdoors->pVertices[0], 0, 0x78);
    memset(pOutdoors->pVertices[1], 0, 0x78);
    memset(pOutdoors->pVertices[2], 0, 0x78);
    memset(pOutdoors->pVertices[3], 0, 0x78);

    pOutdoors->nVertices = 0;

    if (!bKeepRoomData)
    {
        DRLGROOM_FreeRoomData(pMemPool, pOutdoors->pRoomData);
        FOG_FreeServerMemory(pMemPool, pLevel->pOutdoors, ".\\DRLG\\Outdoors.cpp", 940, 0);
        pLevel->pOutdoors = 0;
    }
}
