struct D2DrlgCoord0066ECE0Strc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2TileCounts0066ECE0Strc
{
    int unk0x00;
    int nFlag1Tiles;
    int unk0x08;
    int nFlag2Tiles;
    int unk0x10;
    int nFlag8000000Tiles;
};

struct D2RoomRecord0066ECE0Strc
{
    char unk0x00[0x14];
    D2TileCounts0066ECE0Strc tCounts;
};

struct D2DrlgRoom0066ECE0Strc
{
    char unk0x00[0x34];
    D2DrlgCoord0066ECE0Strc tCoords;
    char unk0x44[0x10];
    D2RoomRecord0066ECE0Strc* pRecord;
};

struct D2TileGrid0066ECE0Strc;

unsigned int* __fastcall sub_0067C550_GetTileFlags(D2TileGrid0066ECE0Strc* pGrid, int nX, int nY); // 0x0067C550
int __fastcall sub_0066B980_IsOnBorder(D2DrlgCoord0066ECE0Strc* pCoords, int nX, int nY); // 0x0066B980

// 0x0066ECE0
void __fastcall sub_0066ECE0_CountTiles(D2DrlgRoom0066ECE0Strc* pDrlgRoom, D2TileGrid0066ECE0Strc* pGrid, int bCheckBorder, int bNoExtraColumn, int bNoExtraRow)
{
    const int nWidth = pDrlgRoom->tCoords.nWidth + (bNoExtraColumn == 0);
    D2DrlgCoord0066ECE0Strc* pCoords = &pDrlgRoom->tCoords;
    const int nHeight = pDrlgRoom->tCoords.nHeight + (bNoExtraRow == 0);
    const int nPosX = pCoords->nPosX;
    const int nPosY = pDrlgRoom->tCoords.nPosY;

    D2TileCounts0066ECE0Strc* pCounts = &pDrlgRoom->pRecord->tCounts;
    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            unsigned int* pFlags = sub_0067C550_GetTileFlags(pGrid, nX, nY);
            if (*pFlags & 1)
            {
                ++pCounts->nFlag1Tiles;
            }
            if (*pFlags & 2)
            {
                ++pCounts->nFlag2Tiles;
            }
            else if (bCheckBorder && sub_0066B980_IsOnBorder(pCoords, nX + nPosX, nY + nPosY))
            {
                ++pCounts->nFlag2Tiles;
            }
            if (*pFlags & 0x8000000)
            {
                ++pCounts->nFlag8000000Tiles;
            }
        }
    }
}
