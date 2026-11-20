#include "D2Common.h"
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
    int eLevelId;
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
    D2DrlgLevelStrc* ptDrlgLevel;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex);

void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pRoom);                                                // 0x0066EEA0
void __fastcall sub_0066EDB0(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5);
void __fastcall sub_0066ECE0(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, int a3, int a4, int a5);
void __fastcall sub_0066EEE0(D2DrlgRoomStrc* pRoom);
void __fastcall sub_0066EC10(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5, int a6);
void __fastcall sub_0066CCB0(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);         // 0x0067CB80
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);            // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);                       // 0x0067C600
unsigned char __stdcall sub_006427F0(int nLevelId);                                                            // 0x006427F0
D2LevelDefRecordStrc* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                          // 0x0061E470
void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);                                // 0x00680C80
void __fastcall sub_006707A0(D2DrlgOutdoorTileCtxStrc* pCtx);                                                // 0x006707A0
D2DrlgRoomStrc* __fastcall sub_0066B3E0(D2DrlgLevelStrc* pLevel, int nType);
void __fastcall sub_0066B970(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);
int __fastcall sub_006706A0(D2DrlgRoomStrc* pRoom, int a2, int a3);

// build: symbol ?DRLGOUTROOM_InitOutdoorRoomGrids@@YIXPAUD2DrlgRoomStrc@@@Z 0x0067D2D0
void __fastcall DRLGOUTROOM_InitOutdoorRoomGrids(D2DrlgRoomStrc* pRoom)
{
    D2DrlgLevelStrc* pLevel = pRoom->ptDrlgLevel;
    void* pMemPool = pLevel->pDrlg->pMemPool;
    int nLevelId = pLevel->eLevelId;
    unsigned char bSkip = sub_006427F0(nLevelId);
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    D2LevelDefRecordStrc* pLevelDef = DATATBLS_GetLevelDefRecord(nLevelId);
    int nWidth = pRoom->nTileWidth + 1;
    int nHeight = pRoom->nTileHeight + 1;
    int nSubType1 = (pRoom->dwFlags >> 16) & 3;
    int nSubType2 = (pRoom->dwFlags >> 12) & 0xF;
    int nMask = 0;

    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->tGrid00, nWidth, nHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->tGrid14, nWidth, nHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->tGrid28, nWidth, nHeight);

    for (int nY = 0; nY < 8; ++nY)
    {
        for (int nX = 0; nX < 8; ++nX)
        {
            DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX, nY, 0x40002, 3);
        }
    }

    if (!bSkip)
    {
        sub_00680C80(pLevel, pRoom);
    }

    DRLGROOMTILE_AllocTileGrid(pRoom);

    D2DrlgOutdoorTileCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pRoom = pRoom;
    tCtx.pGrid00 = &pOutdoor->tGrid00;
    tCtx.pGrid14 = &pOutdoor->tGrid14;
    tCtx.pGrid28 = &pOutdoor->tGrid28;
    tCtx.n28 = 0;
    tCtx.n2C = 1;

    if (nSubType1)
    {
        tCtx.n30 = pLevelDef->n40;
        tCtx.n34 = 0;
        tCtx.n38 = nSubType1;
        sub_006707A0(&tCtx);
    }

    if (nSubType2)
    {
        tCtx.n30 = pLevelDef->n44;
        tCtx.n34 = 0;
        tCtx.n38 = nSubType2;
        sub_006707A0(&tCtx);
    }

    tCtx.n30 = pOutdoor->nTileInfo64;
    tCtx.n34 = pOutdoor->nTileInfo68;
    tCtx.n38 = pOutdoor->nTileInfo6C;
    sub_006707A0(&tCtx);

    switch (pLevel->nLevelType)
    {
    case 0x10:
        nMask = 0x100;
        break;
    case 0x15:
        nMask = 0x120000;
        break;
    case 0x16:
        nMask = 0x100000;
        break;
    case 0x1B:
        nMask = 0xA00000;
        break;
    case 0x1C:
        nMask = 0x1600000;
        break;
    case 0x1F:
        nMask = (pLevel->eLevelId == 117) ? 0x600000 : 0;
        break;
    }

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            if (!(DRLGGRID_GetGridEntry(&pOutdoor->tGrid28, nX, nY) & 0x3F0FF80))
            {
                DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX, nY, nMask, 0);
            }
        }
    }

    DRLGGRID_AlterEdgeGridFlags(&pOutdoor->tGrid14, 4, 0);
    DRLGGRID_AlterEdgeGridFlags(&pOutdoor->tGrid28, 4, 0);
}

D2DrlgRoomStrc* __fastcall sub_0067D540(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50);

void sub_0067D5D0(void* pMemPool, D2DrlgOutdoorRoomStrc* pOutdoor);

void __fastcall sub_0067D610(D2DrlgRoomStrc* pRoom);

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
