#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"
#include "D2DrlgRooms.h"

struct D2LvlPrestTxt;
struct D2CoordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2DrlgStrc;
struct D2LevelDefRecordStrc;
struct D2DrlgOutdoorTileCtxStrc;
struct D2RoomTileTotalStrc;
struct D2RoomTileInfoStrc;
union D2SeedStrc;
struct D2DrlgLinkStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgOutSiegeInitStrc;








struct D2LevelDefRecordStrc
{
    char unk0x00[0x38];
    int n38;
    int n3C;
    int n40;
    int n44;
};

struct D2DrlgOutdoorTileCtxStrc
{
    struct D2DrlgRoomStrc* pRoom;
    D2DrlgGridStrc* pGrid00;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgGridStrc* pGrid14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    D2DrlgGridStrc* pGrid28;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
};

struct D2RoomTileTotalStrc
{
    int nTotal;
    int unk0x04;
};

struct D2RoomTileInfoStrc
{
    int unk0x00;
    int unk0x04;
    int nCount[3];
    int unk0x14;
    D2RoomTileTotalStrc tTotals[3];
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex);
void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pRoom); // 0x0066EEA0
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5); // 0x0066EDB0
void __fastcall sub_0066ECE0(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, int a3, int a4, int a5); // 0x0066ECE0
void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pRoom); // 0x0066EEE0
void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5, int a6); // 0x0066EC10
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pRoom); // 0x0066CCB0
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight); // 0x0067CB80
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation); // 0x0067C600
unsigned char __stdcall sub_006427F0(int nLevelId);
D2LevelDefRecordStrc* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);
void __fastcall sub_006707A0(D2DrlgOutdoorTileCtxStrc* pCtx);
D2DrlgRoomStrc* __fastcall sub_0066B3E0(D2DrlgLevelStrc* pLevel, int nType);
void __fastcall sub_0066B970(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);
int __fastcall sub_006706A0(D2DrlgRoomStrc* pRoom, int a2, int a3);
void __fastcall DRLGOUTROOM_InitOutdoorRoomGrids(D2DrlgRoomStrc* pRoom);
D2DrlgRoomStrc* __fastcall sub_0067D540(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50);
void sub_0067D5D0(void* pMemPool, D2DrlgOutdoorRoomStrc* pOutdoor);
void __fastcall sub_0067D610(D2DrlgRoomStrc* pRoom);
void __fastcall sub_0067D680(D2DrlgRoomStrc* pRoom);
void __fastcall sub_0067D6D0(D2DrlgRoomStrc* pRoom);
unsigned int __fastcall sub_0067D7A0(D2DrlgRoomStrc* pRoom);
void sub_0067D7B0(D2DrlgCoordsStrc* pCoords, int nType);
void __stdcall DRLGOUTROOM_GetOrthCoords(D2DrlgCoordsStrc* pCoords, int nType, int nDirection, D2DrlgCoordsStrc* pBase);

// build: context DRLGOUTROOM_LinkLevelsByOffsetCoords



extern const D2CoordStrc gOutdoorOrthOffsets_006F1F7C[4]; // 0x006F1F7C


struct D2DrlgOutSiegeInitStrc
{
    int nLevelId;
    int field_4;
    int field_8;
    int nLevelPrestId1;
    int nLevelPrestId2;
};

extern const D2DrlgOutSiegeInitStrc gaOutSiegeCaves[3]; // 0x006F1F9C
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLevelPrestId); // 0x0061F0B0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nDirection, int a6); // 0x006743C0
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770
void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel); // 0x0067E160

// 0x0067D710
void __fastcall sub_0067D710(D2DrlgRoomStrc* pRoom)
{
    DRLGROOMTILE_AllocTileGrid(pRoom);

    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    DRLGROOMTILE_CountWallWarpTiles(pRoom, &pOutdoor->tGrid14, &pOutdoor->pTileTypeGrid, 0, 0);
    sub_0066ECE0(pRoom, &pOutdoor->tGrid14, 0, 0, 0);
    sub_0066ECE0(pRoom, &pOutdoor->tGrid28, 0, 0, 0);
    DRLGROOMTILE_AllocTileData(pRoom);
    DRLGROOMTILE_LoadInitRoomTiles(pRoom, &pOutdoor->tGrid14, &pOutdoor->pTileTypeGrid, 0, 0, 0);
    DRLGROOMTILE_LoadInitRoomTiles(pRoom, &pOutdoor->tGrid28, 0, 0, 0, 0);

    D2DrlgTileGridStrc* pTileGrid = pRoom->ptDrlgTiles;
    D2DrlgRoomTilesStrc* pTiles = &pTileGrid->pTiles;
    pTiles->nWalls = pTileGrid->nWalls;
    pTiles->nFloors = pTileGrid->nFloors;
    pTiles->nRoofs = pTileGrid->nShadows;

    DRLGLOGIC_AllocCoordLists(pRoom);
}

static const D2CoordStrc gOutdoorOrthOffsets[2][2] =
{
    { { 0, -160 }, { -96, -64 } },
    { { -64, -96 }, { -160, 0 } },
};

// 0x0067D7E0
static inline void __fastcall sub_0067D7E0_SetOffsetCoords(D2DrlgCoordStrc* pCoords, D2DrlgCoordStrc* pLinkCoords, int nRand, int nLinkRand)
{
    switch (nRand)
    {
    case 0:
        pCoords->nWidth = 64;
        pCoords->nHeight = 160;
        break;
    case 1:
        pCoords->nWidth = 160;
        pCoords->nHeight = 64;
        break;
    }

    const int nIndex = nRand + 2 * nLinkRand;
    pCoords->nPosX = gOutdoorOrthOffsets_006F1F7C[nIndex].nX + pLinkCoords->nPosX;
    pCoords->nPosY = gOutdoorOrthOffsets_006F1F7C[nIndex].nY + pLinkCoords->nPosY;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// build: context SEED_RollRandomNumber
int __fastcall DRLGOUTROOM_LinkLevelsByOffsetCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int bRand0IsNull = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] == 0;
        if (bRand0IsNull == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = bRand0IsNull;
    }

    const int nLevelLink = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    sub_0067D7E0_SetOffsetCoords(&pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], &pLevelLinkData->pLevelCoord[nLevelLink], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], pLevelLinkData->nRand[0][nLevelLink]);
    return 1;
}

// 0x0067DA70
static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int i = 0; i < 3; ++i)
    {
        if (pLevel->eLevelId == gaOutSiegeCaves[i].nLevelId)
        {
            int nLevelPrestId;
            int nX;
            int nY;
            if (pLevel->nWidth > pLevel->nHeight)
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId2;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId1;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = 2;
                nY = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridHeight - 2 : 0;
            }
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, gaOutSiegeCaves[i].field_4, 0);
        }
    }
}

void __fastcall sub_M170_Emit_0067DA70(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
        return;
    }
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    sub_0067E160(pLevel);
    DRLGOUTSIEGE_PlaceCaves(pLevel);
    if (pLevel->eLevelId == LEVEL_ID_ACT5_BARRICADE_1)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    }
    sub_0067E160(pLevel);
}

#include "gen/data/Source/D2Common/Unknown_0067D710.inc"
