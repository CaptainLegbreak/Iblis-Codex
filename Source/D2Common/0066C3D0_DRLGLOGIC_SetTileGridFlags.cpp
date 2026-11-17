struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
    char unk0x1D4[0x8];
    int nCoordLists;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int dwFlags;
};

struct D2RoomCoordListStrc
{
    D2DrlgCoordStrc pBox[2];
    int bNode;
    int bRoomActive;
    int nIndex;
    D2RoomCoordListStrc* pNext;
};

struct D2DrlgLogicalRoomInfoStrc
{
    int dwFlags;
    int nLists;
    D2DrlgGridStrc pIndexX;
    D2DrlgGridStrc pIndexY;
    D2RoomCoordListStrc* pCoordList;
};

struct D2DrlgTileDataStrc
{
    char unk0x00[0x8];
    int nPosX;
    int nPosY;
    D2RoomCoordListStrc* pCoordList;
    union
    {
        unsigned int dwFlags;
        struct
        {
            unsigned int nFlagsLow : 11;
            unsigned int bObjectWall : 1;
        };
    };
    int unk0x18;
    int nTileType;
    D2DrlgTileDataStrc* pNext;
    char unk0x24[0xC];
};

struct D2DrlgTileLinkStrc
{
    int bFloor;
    D2DrlgTileDataStrc* pMapTile;
    D2DrlgTileLinkStrc* pNext;
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    unsigned int nWalls;
};

struct D2DrlgTileGridStrc
{
    D2DrlgTileLinkStrc* pMapLinks;
    char unk0x04[0x10];
    D2DrlgRoomTilesStrc pTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x8];
    D2DrlgRoomStrc** ppRoomsNear;
    char unk0x0C[0x20];
    int nRoomsNear;
    char unk0x30[0x4];
    D2DrlgCoordStrc tCoords;
    char unk0x44[0x10];
    D2DrlgTileGridStrc* pTileGrid;
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x8];
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo;
};

union D2PackedFloorStrc
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int nLow : 31;
        unsigned int bHidden : 1;
    };
};

inline int HasMapTileLayer(unsigned int dwFlags)
{
    return (dwFlags & 0x1C000) != 0;
}

struct D2UnkDrlgLogicStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgGridStrc* field_4;
    D2DrlgGridStrc* pTileTypeGrid;
    D2DrlgGridStrc* pWallGrid;
    D2DrlgGridStrc* pFloorGrid;
    D2DrlgGridStrc* field_14;
    int field_18;
    int nFlags;
};

extern "C" const D2CoordStrc gLogicDirections[];                                                        // 0x006EEE14
extern "C" const int gnLogicTileFlags[];                                                              // 0x006EEE38
extern "C" const int gnLogicTileIndex[];                                                              // 0x006EEEA0
extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                  // 0x00681EF0
#pragma function(memset)
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance);  // 0x0066B860
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY);                        // 0x0066B9D0
int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid);                                           // 0x0067C480
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation);   // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                           // 0x0067C570
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);  // 0x0067CB80
void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags);  // 0x0067CBF0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);                                          // 0x0067CDC0

// 0x0066C3D0
void __fastcall DRLGLOGIC_SetTileGridFlags(D2UnkDrlgLogicStrc* a1, int nX, int nY, int a4)
{
    while (DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&a1->pDrlgRoom->tCoords, nX + a1->pDrlgRoom->tCoords.nPosX, nY + a1->pDrlgRoom->tCoords.nPosY))
    {
        if (DRLGGRID_GetGridEntry(a1->field_4, nX, nY) & 0x10000000)
        {
            return;
        }

        if (!DRLGGRID_GetGridEntry(a1->field_14, nX, nY))
        {
            DRLGGRID_AlterGridFlag(a1->field_4, nX, nY, a1->nFlags, 0);

            for (int i = 0; i < 4; ++i)
            {
                DRLGLOGIC_SetTileGridFlags(a1, nX + gLogicDirections[i].nX, nY + gLogicDirections[i].nY, i);
            }
            return;
        }

        int nIndex = 0;
        if (DRLGGRID_IsGridValid(a1->pTileTypeGrid))
        {
            nIndex = DRLGGRID_GetGridEntry(a1->pTileTypeGrid, nX, nY);
        }

        const int nFlags = gnLogicTileFlags[a4 + 5 * gnLogicTileIndex[nIndex] + 1];
        if (nFlags & 1)
        {
            DRLGGRID_AlterGridFlag(a1->field_4, nX, nY, a1->nFlags, 0);
        }

        if (nFlags & 2 && a4 != 2)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX + 1, nY, 0);
        }

        if (nFlags & 4 && a4 != 3)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX, nY + 1, 1);
        }

        if (nFlags & 8 && a4 != 0)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX - 1, nY, 2);
        }

        if (nFlags & 16 && a4 != 1)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX, nY - 1, 3);
        }

        if (!(nFlags & 32))
        {
            return;
        }

        ++nY;
        ++nX;

        a4 = -1;
    }
}

// 0x0066C580
static void sub_0066C580(D2UnkDrlgLogicStrc* a1)
{
    const int nWidth = a1->pDrlgRoom->tCoords.nWidth;
    const int nHeight = a1->pDrlgRoom->tCoords.nHeight;

    for (int j = 0; j <= nHeight; ++j)
    {
        for (int i = 0; i <= nWidth; ++i)
        {
            if (!(DRLGGRID_GetGridEntry(a1->field_4, i, j) & 0x10000000))
            {
                ++a1->field_18;
                a1->nFlags = (a1->field_18 & 0xFFFFFFF) | 0x10000000;

                D2PackedFloorStrc tFloor;
                tFloor.nPackedValue = DRLGGRID_GetGridEntry(a1->pFloorGrid, i, j);
                if ((tFloor.nPackedValue & 0x1E0FF00) == 0x1E00000 || tFloor.bHidden)
                {
                    a1->nFlags |= 0x20000000;
                }

                DRLGLOGIC_SetTileGridFlags(a1, i, j, -1);
            }
        }
    }
}

// 0x0066C660
D2DrlgLogicalRoomInfoStrc* __fastcall sub_0066C660(void* pMemPool, int nUnused, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = (D2DrlgLogicalRoomInfoStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgLogicalRoomInfoStrc), ".\\DRLG\\DrlgLogic.cpp", 223, 0);
    memset(pLogicalRoomInfo, 0, sizeof(D2DrlgLogicalRoomInfoStrc));
    pDrlgRoom->pLogicalRoomInfo = pLogicalRoomInfo;
    return pLogicalRoomInfo;
}

// 0x0066C6A0
static void sub_0066C6A0(void* pMemPool, D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo, int nLists)
{
    pLogicalRoomInfo->nLists = nLists;
    pLogicalRoomInfo->pCoordList = (D2RoomCoordListStrc*)sub_0040B430(pMemPool, sizeof(D2RoomCoordListStrc) * nLists, ".\\DRLG\\DrlgLogic.cpp", 233, 0);
    memset(pLogicalRoomInfo->pCoordList, 0, sizeof(D2RoomCoordListStrc) * pLogicalRoomInfo->nLists);
}

// 0x0066C770
void __fastcall sub_0066C770(D2DrlgRoomStrc* pDrlgRoom, int nIndex1, int nIndex2, int bNode)
{
    if (!pDrlgRoom->pLogicalRoomInfo || (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1))
    {
        return;
    }

    int bContinue = 0;
    D2RoomCoordListStrc* pRoomCoordList = pDrlgRoom->pLogicalRoomInfo->pCoordList;
    if (pRoomCoordList)
    {
        do
        {
            if (pRoomCoordList->nIndex == nIndex1)
            {
                bContinue = 1;
                pRoomCoordList->nIndex = nIndex2;
            }
            pRoomCoordList = pRoomCoordList->pNext;
        }
        while (pRoomCoordList);

        if (bContinue)
        {
            for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
            {
                D2DrlgRoomStrc* pDrlgRoomNear = pDrlgRoom->ppRoomsNear[i];
                if (pDrlgRoomNear != pDrlgRoom && pDrlgRoomNear->pLevel->nLevelId == pDrlgRoom->pLevel->nLevelId)
                {
                    sub_0066C770(pDrlgRoomNear, nIndex1, nIndex2, bNode);
                }
            }
        }
    }
}

// 0x0066C7F0
static void __stdcall sub_0066C7F0(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid)
{
    D2DrlgRoomTilesStrc* pDrlgRoomTiles = &pDrlgRoom->pTileGrid->pTiles;
    for (unsigned int i = 0; i < pDrlgRoomTiles->nWalls; ++i)
    {
        if (pDrlgRoomTiles->pWallTiles[i].dwFlags & 4 && !(pDrlgRoomTiles->pWallTiles[i].dwFlags & 0x1C000))
        {
            DRLGGRID_AlterGridFlag(pWallGrid, pDrlgRoomTiles->pWallTiles[i].nPosX, pDrlgRoomTiles->pWallTiles[i].nPosY, 8, 0);
        }
    }
}

void __stdcall sub_0066C870(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid);   // 0x0066C870

void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom);   // 0x0066C9C0

void __stdcall DRLGLOGIC_AssignCoordListsForGrids(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLogicalRoomInfoStrc* pDrlgCoordList);   // 0x0066CA50

static D2RoomCoordListStrc* sub_0066CDA0(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 668);
        exit(-1);
    }

    if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
    {
        return pDrlgRoom->pLogicalRoomInfo->pCoordList;
    }

    int nTileX = nX - pDrlgRoom->tCoords.nPosX;
    int nTileY = nY - pDrlgRoom->tCoords.nPosY;
    return (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nTileX, nTileY);
}

// 0x0066CF60
static void __stdcall sub_0066CF60(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nX, int nY)
{
    if (DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&pDrlgRoom2->tCoords, nX, nY))
    {
        D2RoomCoordListStrc* pRoomCoordList2 = sub_0066CDA0(pDrlgRoom2, nX, nY);
        D2RoomCoordListStrc* pRoomCoordList1 = sub_0066CDA0(pDrlgRoom1, nX, nY);

        if (pRoomCoordList2->nIndex && pRoomCoordList1->nIndex)
        {
            if (pDrlgRoom2->pLevel->nLevelId == pDrlgRoom1->pLevel->nLevelId && pRoomCoordList2->nIndex != pRoomCoordList1->nIndex && pRoomCoordList2->bNode == pRoomCoordList1->bNode)
            {
                sub_0066C770(pDrlgRoom1, pRoomCoordList1->nIndex, pRoomCoordList2->nIndex, pRoomCoordList2->bNode);
            }
        }
    }
}

// 0x0066D040
static void sub_0066D040(D2DrlgRoomStrc* pDrlgRoom)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom->ppRoomsNear[i];
        if (pCurrentRoomEx != pDrlgRoom && pCurrentRoomEx->pLogicalRoomInfo)
        {
            if (!DRLG_CheckNotOverlappingUsingManhattanDistance(&pDrlgRoom->tCoords, &pCurrentRoomEx->tCoords, 1))
            {
                for (int j = pDrlgRoom->tCoords.nPosX; j <= pDrlgRoom->tCoords.nPosX + pDrlgRoom->tCoords.nWidth; ++j)
                {
                    sub_0066CF60(pDrlgRoom, pCurrentRoomEx, j, pDrlgRoom->tCoords.nPosY);
                    sub_0066CF60(pDrlgRoom, pCurrentRoomEx, j, pDrlgRoom->tCoords.nHeight + pDrlgRoom->tCoords.nPosY);
                }

                for (int j = pDrlgRoom->tCoords.nPosY; j <= pDrlgRoom->tCoords.nPosY + pDrlgRoom->tCoords.nHeight; ++j)
                {
                    sub_0066CF60(pDrlgRoom, pCurrentRoomEx, pDrlgRoom->tCoords.nPosX, j);
                    sub_0066CF60(pDrlgRoom, pCurrentRoomEx, pDrlgRoom->tCoords.nPosX + pDrlgRoom->tCoords.nWidth, j);
                }
            }
        }
    }
}

// 0x0066D110
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid)
{
    int nCellPositions[1024];
    int nCellFlags[256];

    D2DrlgLevelStrc* pLevel = pDrlgRoom->pLevel;
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pDrlgCoordList = sub_0066C660(pMemPool, 0, pDrlgRoom);

    sub_0066C7F0(pDrlgRoom, pWallGrid);

    pDrlgCoordList->dwFlags |= 2;

    DRLGGRID_InitializeGridCells(pMemPool, &pDrlgCoordList->pIndexX, pDrlgRoom->tCoords.nWidth + 1, pDrlgRoom->tCoords.nHeight + 1);

    if (!pLevel->nCoordLists)
    {
        pLevel->nCoordLists = 1;
    }

    const int nLists = pLevel->nCoordLists;

    D2DrlgGridStrc pDrlgGrid;
    DRLGGRID_FillGrid(&pDrlgGrid, pDrlgRoom->tCoords.nWidth + 1, pDrlgRoom->tCoords.nHeight + 1, nCellPositions, nCellFlags);

    sub_0066C870(pDrlgRoom, &pDrlgGrid);

    D2UnkDrlgLogicStrc tDRLGLogicUnkStrc = {};
    tDRLGLogicUnkStrc.field_4 = &pDrlgCoordList->pIndexX;
    tDRLGLogicUnkStrc.pTileTypeGrid = pTileTypeGrid;
    tDRLGLogicUnkStrc.pDrlgRoom = pDrlgRoom;
    tDRLGLogicUnkStrc.pWallGrid = pWallGrid;
    tDRLGLogicUnkStrc.pFloorGrid = pFloorGrid;
    tDRLGLogicUnkStrc.field_14 = &pDrlgGrid;
    tDRLGLogicUnkStrc.field_18 = nLists;

    sub_0066C580(&tDRLGLogicUnkStrc);

    DRLGGRID_ResetGrid(&pDrlgGrid);

    sub_0066C6A0(pMemPool, pDrlgCoordList, tDRLGLogicUnkStrc.field_18 - nLists + 1);
    pLevel->nCoordLists += pDrlgCoordList->nLists;

    DRLGLOGIC_AssignCoordListsForGrids(pDrlgRoom, pDrlgCoordList);
    DRLGLOGIC_SetCoordListForTiles(pDrlgRoom);
    sub_0066D040(pDrlgRoom);
}

#include "gen/data/Source/D2Common/0066C3D0_DRLGLOGIC_SetTileGridFlags.inc"
