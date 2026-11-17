struct D2CmpTileStrc;

struct D2DrlgTileDataStrc
{
    char unk0x00[0x20];
    D2DrlgTileDataStrc* unk0x20;
    char unk0x24[0x0C];
};

struct D2DrlgTileGridStrc
{
    char unk0x00[0x0C];
    int nFloors;
    char unk0x10[0x0C];
    D2DrlgTileDataStrc* pFloorTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x54];
    D2DrlgTileGridStrc* pTileGrid;
};

void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry); // 0x0066DDE0

// 0x0066DEF0
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pFloorTiles[pTileGrid->nFloors];
    if (ppTileData)
    {
        pTileData->unk0x20 = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->unk0x20 = 0;
    }

    ++pTileGrid->nFloors;

    DRLGROOMTILE_InitTileData(pDrlgRoom, pTileData, nX, nY, nPackedTileInformation, pTileLibraryEntry);
    return pTileData;
}
