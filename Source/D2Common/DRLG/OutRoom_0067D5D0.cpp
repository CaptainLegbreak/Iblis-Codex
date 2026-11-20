#include "D2Structs.h"
#include "D2Path.h"
struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};


struct D2DrlgCoordsStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
};

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc tGrid00;
    D2DrlgGridStrc tGrid14;
    D2DrlgGridStrc tGrid28;
    D2DrlgGridStrc tGrid3C;
    D2DrlgVertexStrc* pVertex;
    unsigned int dwFlags;
    int unk0x58;
    int unk0x5C;
    int unk0x60;
    int nTileInfo64;
    int nTileInfo68;
    int nTileInfo6C;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMemPool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    int unk0x1B8;
    int unk0x1BC;
    int nLevelType;
    int unk0x1C4;
    int unk0x1C8;
    int unk0x1CC;
    int nLevelId;
};

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

struct D2RoomTileInfoStrc
{
    int unk0x00;
    int unk0x04;
    int nCount08;
    int nCount0C;
    int nCount10;
    int unk0x14;
    int nTotal18;
    int unk0x1C;
    int nTotal20;
    int unk0x24;
    int nTotal28;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgOutdoorRoomStrc* pOutdoor;
    D2DrlgRoomStrc* pNext;
    unsigned int dwFlags;
    int unk0x2C;
    int unk0x30;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    D2RoomTileInfoStrc* pTileInfo;
    D2DrlgLevelStrc* pLevel;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);                                    // 0x0067CD90
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex);                          // 0x0067D1E0

void __fastcall sub_0066EEA0(D2DrlgRoomStrc* pRoom);
void __fastcall sub_0066EDB0(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5);
void __fastcall sub_0066ECE0(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, int a3, int a4, int a5);
void __fastcall sub_0066EEE0(D2DrlgRoomStrc* pRoom);
void __fastcall sub_0066EC10(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5, int a6);
void __fastcall sub_0066CCB0(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);         // 0x0067CB80
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);            // 0x0067C4F0
int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);                       // 0x0067C600
unsigned char __stdcall sub_006427F0(int nLevelId);
D2LevelDefRecordStrc* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                          // 0x0061E470
void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);
void __fastcall sub_006707A0(D2DrlgOutdoorTileCtxStrc* pCtx);
D2DrlgRoomStrc* __fastcall sub_0066B3E0(D2DrlgLevelStrc* pLevel, int nType);
void __fastcall sub_0066B970(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);
int __fastcall sub_006706A0(D2DrlgRoomStrc* pRoom, int a2, int a3);

void __fastcall DRLGOUTROOM_InitOutdoorRoomGrids(D2DrlgRoomStrc* pRoom);

D2DrlgRoomStrc* __fastcall sub_0067D540(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50);

// 0x0067D5D0
static void sub_0067D5D0(void* pMemPool, D2DrlgOutdoorRoomStrc* pOutdoor)
{
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid00);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid14);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid28);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid3C);
    DRLGVER_FreeVertices(pMemPool, &pOutdoor->pVertex);
}

// 0x0067D610
void __fastcall sub_0067D610(D2DrlgRoomStrc* pRoom)
{
    void* pMemPool = pRoom->pLevel->pDrlg->pMemPool;
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    if (pOutdoor)
    {
        sub_0067D5D0(pMemPool, pOutdoor);
        sub_0040B480(pMemPool, pOutdoor, ".\\DRLG\\OutRoom.cpp", 173, 0);
        pRoom->pOutdoor = 0;
    }
}

void __fastcall sub_0067D680(D2DrlgRoomStrc* pRoom);

void __fastcall sub_0067D6D0(D2DrlgRoomStrc* pRoom);

void __fastcall sub_0067D710(D2DrlgRoomStrc* pRoom);

unsigned int __fastcall sub_0067D7A0(D2DrlgRoomStrc* pRoom);

void sub_0067D7B0(D2DrlgCoordsStrc* pCoords, int nType);

static const D2CoordStrc gOutdoorOrthOffsets[2][2] =
{
    { { 0, -160 }, { -96, -64 } },
    { { -64, -96 }, { -160, 0 } },
};

void __stdcall DRLGOUTROOM_GetOrthCoords(D2DrlgCoordsStrc* pCoords, int nType, int nDirection, D2DrlgCoordsStrc* pBase);
