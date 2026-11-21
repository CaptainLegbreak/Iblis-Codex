#include "D2Common.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2DrlgMapStrc;
struct D2DrlgOrthStrc;
union D2SeedStrc;
struct D2DrlgCoordStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgVertexStrc;
struct D2DrlgStrc;






int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0
int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile); // 0x00666EC0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0
D2DrlgRoomStrc* __fastcall sub_0067D540(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50); // 0x0067D540
static __declspec(noinline) void sub_006750F0_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel);


unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight); // 0x0067CB80
void __fastcall DRLGVER_CreateVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pDrlgOrth); // 0x0067D050
void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel); // 0x0067E600
void __fastcall sub_0067E890(D2DrlgLevelStrc* pLevel); // 0x0067E890
void __fastcall sub_0067F450(D2DrlgLevelStrc* pLevel); // 0x0067F450
void __fastcall DRLGOUTWILD_InitAct1OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x006807F0

// 0x006750F0
static void sub_006750F0_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nLevelFlags = 0;
    switch (pLevel->nLevelType)
    {
    case 2:
        nLevelFlags = 0x44103;
        break;
    case 16:
        nLevelFlags = 1;
        break;
    case 21:
        nLevelFlags = 4;
        break;
    case 22:
        nLevelFlags = 1;
        break;
    case 27:
        nLevelFlags = 1;
        break;
    case 28:
        nLevelFlags = 1;
        break;
    case 30:
        nLevelFlags = 0x11;
        break;
    case 31:
        nLevelFlags = 0x11;
        break;
    }

    int nPosY = pLevel->pLevelCoords.nPosY;
    for (int nY = 0; nY < pOutdoors->nGridHeight; ++nY)
    {
        int nPosX = pLevel->pLevelCoords.nPosX;
        for (int nX = 0; nX < pOutdoors->nGridWidth; ++nX)
        {
            const int nRoomFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[1], nX, nY);
            const unsigned int dwCellFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
            if (dwCellFlags & 0x200)
            {
                const int nLvlPrestId = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
                if (nLvlPrestId)
                {
                    D2DrlgCoordStrc tDrlgCoord;
                    tDrlgCoord.nPosX = nPosX;
                    tDrlgCoord.nPosY = nPosY;
                    tDrlgCoord.nWidth = 0;
                    tDrlgCoord.nHeight = 0;
                    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, nLvlPrestId, &tDrlgCoord, &pLevel->pSeed);
                    DRLGPRESET_SetPickedFileInDrlgMap(pDrlgMap, (dwCellFlags >> 16) & 0xF);
                    DRLGPRESET_BuildArea(pLevel, pDrlgMap, nRoomFlags, 0);
                }
            }
            else if (!(dwCellFlags & 0x100))
            {
                const int nOutdoorEntry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[3], nX, nY);
                sub_0067D540(pLevel, nPosX, nPosY, 8, 8, nRoomFlags, dwCellFlags, nOutdoorEntry, nLevelFlags);
            }

            nPosX += 8;
        }

        nPosY += 8;
    }
}

void __fastcall sub_006750F0_EmitSpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel)
{
    sub_006750F0_SpawnPresetsAndRooms(pLevel);
}

static __forceinline int sub_006750F0_GetLevelRoomFlags(int nLevelType)
{
    int nFlags = 0;
    switch (nLevelType)
    {
    case 2:
        nFlags = 0x44103;
        break;
    case 16:
    case 22:
    case 27:
    case 28:
        nFlags = 1;
        break;
    case 21:
        nFlags = 4;
        break;
    case 30:
    case 31:
        nFlags = 0x11;
        break;
    }
    return nFlags;
}

// 0x00675080
static __declspec(noinline) void sub_00675080_ScaleAndMergeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pVertex = *ppVertex;
    do
    {
        pVertex->nPosX /= 8;
        pVertex->nPosY /= 8;
        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);

    do
    {
        D2DrlgVertexStrc* pNextVertex = pVertex->pNext;

        if (pVertex->nPosX == pNextVertex->nPosX && pVertex->nPosY == pNextVertex->nPosY)
        {
            if (pNextVertex == *ppVertex)
            {
                *ppVertex = pVertex;
            }

            pVertex->pNext = pNextVertex->pNext;
            pVertex->dwFlags |= pNextVertex->dwFlags;
            pVertex->nDirection = pNextVertex->nDirection;
            FOG_FreeServerMemory(pMemPool, pNextVertex, ".\\DRLG\\Outdoors.cpp", 715, 0);
        }

        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);
}

// 0x00675360
void __fastcall DRLGOUTDOORS_GenerateLevel(D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;

    pOutdoors->unk0x54 = 0;
    pOutdoors->nRoomData = 0;
    pOutdoors->nGridWidth = pLevel->pLevelCoords.nWidth / 8;
    pOutdoors->nGridHeight = pLevel->pLevelCoords.nHeight / 8;

    const int nGridWidth = pOutdoors->nGridWidth;
    const int nGridHeight = pOutdoors->nGridHeight;
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[0], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[1], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[2], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[3], nGridWidth, nGridHeight);

    unsigned char nAct = DRLG_GetActNoFromLevelId(pLevel->eLevelId);

    DRLGVER_CreateVertices(pMemPool, &pOutdoors->pVertex, &pLevel->pLevelCoords, 0, pOutdoors->pRoomData);
    sub_00675080_ScaleAndMergeVertices(pMemPool, (D2DrlgVertexStrc**)&pOutdoors->pVertex);

    if (pLevel->eLevelId == 134)
    {
        nAct = 1;
    }

    switch (nAct)
    {
    case 0:
        DRLGOUTWILD_InitAct1OutdoorLevel(pLevel);
        break;
    case 1:
        DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
        break;
    case 2:
        sub_0067F450(pLevel);
        break;
    case 3:
        sub_0067E890(pLevel);
        break;
    case 4:
        sub_0067E600(pLevel);
        break;
    }

    sub_006750F0_SpawnPresetsAndRooms(pLevel);
}
