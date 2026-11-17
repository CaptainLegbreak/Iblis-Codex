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

struct D2DrlgOutdoorInfoStrc
{
    char unk0x000[0x68];
    D2DrlgVertexStrc* pRoads[6];
    char unk0x080[0x1E0];
    int nRoads;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMemPool;
};

struct D2DrlgLevelStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgOutdoorInfoStrc* pOutdoorInfo;
    char unk0x018[0x19C];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc tGrid00;
    D2DrlgGridStrc tGrid14;
    D2DrlgGridStrc tGrid28;
    D2DrlgGridStrc tGrid3C;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgOutdoorRoomStrc* pOutdoor;
    int unk0x24;
    unsigned int dwFlags;
    int unk0x2C;
    int unk0x30;
    D2DrlgCoordsStrc tTileCoords;
};

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);              // 0x0067C4F0
int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);                                           // 0x0067C570
void __fastcall sub_0067C8E0(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pCoords, int nFlag, int eOperation, int nSize);  // 0x0067C8E0
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);          // 0x0067CB80

extern const unsigned char gRoadPatternCodes[256]; // 0x006F2700

// 0x006808F0
static int sub_006808F0(int pFlags[3][3])
{
    if (!pFlags[1][1])
    {
        return 0;
    }

    int nCode = 0;
    if (pFlags[2][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[2][1]) ++nCode;
    nCode <<= 1;
    if (pFlags[2][0]) ++nCode;
    nCode <<= 1;
    if (pFlags[1][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[1][0]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][1]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][0]) ++nCode;
    return nCode;
}

// 0x00680950
static void __stdcall sub_00680950(D2DrlgGridStrc* pGrid, int pFlags[3][3], int nX, int nY)
{
    pFlags[0][0] = pFlags[0][1];
    pFlags[0][1] = pFlags[0][2];
    pFlags[0][2] = pFlags[1][0];
    pFlags[1][0] = pFlags[1][1];
    pFlags[1][1] = pFlags[1][2];
    pFlags[1][2] = pFlags[2][0];
    pFlags[2][0] = pFlags[2][1];
    pFlags[2][1] = pFlags[2][2];
    pFlags[0][2] = sub_0067C570(pGrid, nX - 1, nY - 1);
    pFlags[1][2] = sub_0067C570(pGrid, nX, nY - 1);
    pFlags[2][2] = sub_0067C570(pGrid, nX + 1, nY - 1);
}

// 0x006809C0
static void __stdcall sub_006809C0(D2DrlgGridStrc* pGrid, int pFlags[3][3], int nX, int nY)
{
    pFlags[0][2] = sub_0067C570(pGrid, nX - 1, nY - 1);
    pFlags[0][1] = sub_0067C570(pGrid, nX - 1, nY);
    pFlags[0][0] = sub_0067C570(pGrid, nX - 1, nY + 1);
    pFlags[1][2] = sub_0067C570(pGrid, nX, nY - 1);
    pFlags[2][2] = sub_0067C570(pGrid, nX + 1, nY - 1);
    pFlags[1][1] = sub_0067C570(pGrid, nX, nY);
    pFlags[2][1] = sub_0067C570(pGrid, nX + 1, nY);
    pFlags[1][0] = sub_0067C570(pGrid, nX, nY + 1);
    pFlags[2][0] = sub_0067C570(pGrid, nX + 1, nY + 1);
}

// 0x00680A70
static void sub_00680A70(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoorInfo;
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    D2DrlgCoordsStrc tCoords = pRoom->tTileCoords;
    tCoords.nX -= 1;
    tCoords.nY -= 1;
    tCoords.nWidth += 3;
    tCoords.nHeight += 3;

    for (int i = 0; i < pInfo->nRoads; ++i)
    {
        for (D2DrlgVertexStrc* pVertex = pInfo->pRoads[i]; pVertex; pVertex = pVertex->pNext)
        {
            if (pVertex->pNext)
            {
                sub_0067C8E0(&pOutdoor->tGrid3C, pVertex, &tCoords, 1, 0, 2);
            }
        }
    }
}

// 0x00680B10
static void __stdcall sub_00680B10(D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    for (int nX = 1; nX <= pRoom->tTileCoords.nWidth + 1; ++nX)
    {
        int aFlags[3][3];
        int nY = pRoom->tTileCoords.nHeight + 1;
        sub_006809C0(&pOutdoor->tGrid3C, aFlags, nX, nY);

        for (; nY >= 1; --nY)
        {
            int nCode = sub_006808F0(aFlags);
            if (nCode)
            {
                unsigned char nRoadCode = gRoadPatternCodes[nCode];
                if (nRoadCode)
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX - 1, nY - 1, (nRoadCode << 8) | 0x82, 3);
                }
            }

            if (nY > 1)
            {
                sub_00680950(&pOutdoor->tGrid3C, aFlags, nX, nY - 1);
            }
        }
    }
}

// 0x00680C80
void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom)
{
    DRLGGRID_InitializeGridCells(pLevel->pDrlg->pMemPool, &pRoom->pOutdoor->tGrid3C, pRoom->tTileCoords.nWidth + 3, pRoom->tTileCoords.nHeight + 3);
    sub_00680A70(pLevel, pRoom);
    sub_00680B10(pRoom);
}

#include "gen/data/Source/D2Common/006808F0_sub_006808F0.inc"
