struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc;
struct D2TileLibraryEntryStrc;

struct D2DrlgRoomTilesStrc
{
    void* pWallTiles;
    int nWalls;
    void* pFloorTiles;
    int nFloors;
    void* pRoofTiles;
    int nRoofs;
};

struct D2DrlgTileGridStrc
{
    void* pMapLinks;
    void* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    D2DrlgRoomTilesStrc pTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x28];
    unsigned int dwFlags;
    char unk0x2C[0x8];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x10];
    D2DrlgTileGridStrc* pTileGrid;
    char unk0x58[0x10];
    void* pTiles;
};

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570
int __stdcall D2CMP_GetTiles(void** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries);   // 0x00604AE0
unsigned int __stdcall sub_00604BC0(D2TileLibraryEntryStrc* pTileEntry);                              // 0x00604BC0

// 0x0066D290
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int nTileX, int nTileY)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const int nWidth = (nTileX == 0) + pDrlgRoom->pDrlgCoord.nWidth;
    const int nHeight = (nTileY == 0) + pDrlgRoom->pDrlgCoord.nHeight;
    D2DrlgRoomTilesStrc* pRoomTiles = &pDrlgRoom->pTileGrid->pTiles;

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            const unsigned int nTileInfo = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
            if (nTileInfo & 0x8000003)
            {
                const int nType = pTileTypeGrid ? DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY) : nTileType;

                unsigned char nStyle;
                unsigned char nSequence;
                if (nTileInfo)
                {
                    nStyle = (unsigned char)(nTileInfo >> 20) & 0x3F;
                    nSequence = (unsigned char)(nTileInfo >> 8);
                }
                else
                {
                    nStyle = 0;
                    nSequence = 0;
                }

                const int nTiles = D2CMP_GetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
                if (nTiles && sub_00604BC0(ppTileEntries[0]) & 0x100)
                {
                    if (nTileInfo & 2)
                    {
                        pRoomTiles->nFloors += nTiles - 1;
                    }
                    else if (nTileInfo & 1)
                    {
                        pRoomTiles->nWalls += nTiles - 1;
                    }
                    else
                    {
                        pRoomTiles->nRoofs += nTiles - 1;
                    }

                    pDrlgRoom->dwFlags |= 0x8000000;
                }
            }
        }
    }
}
