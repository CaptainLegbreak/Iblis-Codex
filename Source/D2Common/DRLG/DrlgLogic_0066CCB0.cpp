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

D2DrlgLogicalRoomInfoStrc* __fastcall sub_0066C660(void* pMemPool, int nUnused, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = (D2DrlgLogicalRoomInfoStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgLogicalRoomInfoStrc), ".\\DRLG\\DrlgLogic.cpp", 223, 0);
    memset(pLogicalRoomInfo, 0, sizeof(D2DrlgLogicalRoomInfoStrc));
    pDrlgRoom->pLogicalRoomInfo = pLogicalRoomInfo;
    return pLogicalRoomInfo;
}

static void sub_0066C6A0(void* pMemPool, D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo, int nLists)
{
    pLogicalRoomInfo->nLists = nLists;
    pLogicalRoomInfo->pCoordList = (D2RoomCoordListStrc*)sub_0040B430(pMemPool, sizeof(D2RoomCoordListStrc) * nLists, ".\\DRLG\\DrlgLogic.cpp", 233, 0);
    memset(pLogicalRoomInfo->pCoordList, 0, sizeof(D2RoomCoordListStrc) * pLogicalRoomInfo->nLists);
}

void __stdcall sub_0066C870(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid);

void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom);

void __stdcall DRLGLOGIC_AssignCoordListsForGrids(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLogicalRoomInfoStrc* pDrlgCoordList);

// 0x0066CCB0
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLevelStrc* pLevel = pDrlgRoom->pLevel;
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = sub_0066C660(pMemPool, 0, pDrlgRoom);

    pLogicalRoomInfo->dwFlags |= 1;
    pLevel->nCoordLists = 1;
    sub_0066C6A0(pMemPool, pLogicalRoomInfo, 1);

    pLogicalRoomInfo->pCoordList->nIndex = pLevel->nCoordLists;
    pLogicalRoomInfo->pCoordList->pBox[0].nPosY = pDrlgRoom->tCoords.nPosY;
    pLogicalRoomInfo->pCoordList->pBox[0].nHeight = pDrlgRoom->tCoords.nPosY + pDrlgRoom->tCoords.nHeight;
    pLogicalRoomInfo->pCoordList->pBox[0].nPosX = pDrlgRoom->tCoords.nPosX;
    pLogicalRoomInfo->pCoordList->pBox[0].nWidth = pDrlgRoom->tCoords.nPosX + pDrlgRoom->tCoords.nWidth;
    pLogicalRoomInfo->pCoordList->pBox[1].nPosY = pDrlgRoom->tCoords.nPosY;
    pLogicalRoomInfo->pCoordList->pBox[1].nHeight = pDrlgRoom->tCoords.nPosY + pDrlgRoom->tCoords.nHeight;
    pLogicalRoomInfo->pCoordList->pBox[1].nPosX = pDrlgRoom->tCoords.nPosX;
    pLogicalRoomInfo->pCoordList->pBox[1].nWidth = pDrlgRoom->tCoords.nPosX + pDrlgRoom->tCoords.nWidth;
}
