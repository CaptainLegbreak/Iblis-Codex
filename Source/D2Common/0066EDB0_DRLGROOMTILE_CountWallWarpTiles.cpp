struct D2DrlgGridStrc;
struct D2DrlgTileDataStrc;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    int nWalls;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloors;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofs;
};

struct D2DrlgTileGridStrc
{
    char unk0x00[0x14];
    D2DrlgRoomTilesStrc pTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x10];
    D2DrlgTileGridStrc* pTileGrid;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                           // 0x0067C570

// 0x0066EDB0
void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileInfoGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY)
{
    const int nTileCountX = pDrlgRoom->pDrlgCoord.nWidth + (bKillEdgeX == 0);
    const int nTileCountY = pDrlgRoom->pDrlgCoord.nHeight + (bKillEdgeY == 0);
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->pTileGrid->pTiles;

    for (int nY = 0; nY < nTileCountY; ++nY)
    {
        for (int nX = 0; nX < nTileCountX; ++nX)
        {
            switch (DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY))
            {
            case 3:
                ++pTiles->nWalls;
                break;

            case 10:
            case 11:
                if (DRLGGRID_GetGridEntry(pTileInfoGrid, nX, nY) & 0x80000000)
                {
                    pTiles->nFloors += 6;
                }
                else
                {
                    ++pTiles->nWalls;
                }
                break;

            default:
                break;
            }
        }
    }
}
