struct D2TileLibraryEntryStrc;

union D2C_PackedTileInformation
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int bIsWall : 1;
        unsigned int bIsFloor : 1;
        unsigned int bLOS : 1;
        unsigned int bEnclosed : 1;
        unsigned int bExit : 1;
        unsigned int bUnk0x20 : 1;
        unsigned int bLayerBelow : 1;
        unsigned int bLayerAbove : 1;
        unsigned int nTileSequence : 8;
        unsigned int bFillLOS : 1;
        unsigned int bUnwalkable : 1;
        unsigned int nWallLayer : 2;
        unsigned int nTileStyle : 6;
        unsigned int bRevealHidden : 1;
        unsigned int bShadow : 1;
        unsigned int bLinkage : 1;
        unsigned int bObjectWall : 1;
        unsigned int bUnk0x40000000 : 1;
        unsigned int bHidden : 1;
    };
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    D2DrlgTileDataStrc* pNext;
    int unk0x24;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nIntensity;
    int unk0x2C;
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
    void* pMapLinks;
    void* pAnimTiles;
    int nWalls;
    int nFloors;
    int nShadows;
    D2DrlgRoomTilesStrc pTiles;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x34];
    int nTileXPos;
    int nTileYPos;
    char unk0x3C[0x18];
    D2DrlgTileGridStrc* pTileGrid;
};

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                                  // 0x00643310
unsigned int __stdcall D2CMP_10079_GetTileFlags(D2TileLibraryEntryStrc* pTile);                            // 0x00604BC0
D2TileLibraryEntryStrc* __fastcall DRLGROOMTILE_GetTileCache(D2DrlgRoomStrc* pDrlgRoom, int nType, unsigned int nPackedTileInformation);   // 0x0066D820
void __fastcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nX, int nY, int nTileType);   // 0x0066D9E0

// build: symbol ?DRLGROOMTILE_InitializeTileDataFlags@@YAXPAUD2DrlgRoomStrc@@PAUD2DrlgTileDataStrc@@IHHH@Z 0x0066DB20
static void DRLGROOMTILE_InitializeTileDataFlags(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, unsigned int nTileFlags, int nType, int nX, int nY)
{
    D2C_PackedTileInformation nTileInfo;
    nTileInfo.nPackedValue = nTileFlags;

    if (pDrlgRoom && (nType == 9 || nType == 8))
    {
        DRLGROOMTILE_AddTilePresetUnits(pDrlgRoom, pTileData, nTileFlags, nX, nY, 0);
    }

    if (nType != 13)
    {
        pTileData->dwFlags |= ((int)((nTileFlags >> 18) & 3) + 1) << 14;
    }

    if (nType == 14)
    {
        pTileData->dwFlags |= 4;
    }
    else if (nType == 11 || nType == 10 || nType == 9 || nType == 8)
    {
        pTileData->dwFlags |= 2;
    }

    if (nTileInfo.bLayerAbove)
    {
        pTileData->dwFlags |= 1;
    }

    if (nTileInfo.bLinkage)
    {
        pTileData->dwFlags |= 0x102;
    }

    if (nTileInfo.bUnwalkable)
    {
        pTileData->dwFlags |= 0x40;
    }

    if (nTileInfo.bFillLOS)
    {
        pTileData->dwFlags |= 0x80;
    }

    if (nTileInfo.bEnclosed)
    {
        pTileData->dwFlags |= 4;
    }

    if (nTileInfo.bHidden)
    {
        pTileData->dwFlags |= 8;
    }
    else
    {
        pTileData->dwFlags &= ~8;
    }

    if (nTileInfo.bRevealHidden)
    {
        pTileData->dwFlags |= 0x20C;
    }

    if (nTileInfo.bObjectWall)
    {
        pTileData->dwFlags |= 0x800;
    }

    if (nTileInfo.bLOS)
    {
        pTileData->dwFlags |= 0x2000;
    }

    const unsigned int nFlags = D2CMP_10079_GetTileFlags(pTileData->pTile);
    if (nFlags & 1)
    {
        pTileData->dwFlags |= 4;
    }

    if (nFlags & 4)
    {
        pTileData->dwFlags |= 0x800;
    }
}

// 0x0066DC10
static void __stdcall sub_0066DC10(D2DrlgTileDataStrc* pTileData, D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    pTileData->nPosX = nX - pDrlgRoom->nTileXPos;
    pTileData->nPosY = nY - pDrlgRoom->nTileYPos;

    nY += 1;
    DUNGEON_GameTileToClientCoords(&nX, &nY);

    nY += 40;
    pTileData->nWidth = nX;
    pTileData->nHeight = nY;
}

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pWallTiles[pTileGrid->nWalls];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nWalls;

    sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = nTileType;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, nTileType, nX, nY);

    if (nTileType == 3)
    {
        DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, DRLGROOMTILE_InitWallTileData(pDrlgRoom, ppTileData, nX, nY, nPackedTileInformation, DRLGROOMTILE_GetTileCache(pDrlgRoom, 4, nPackedTileInformation), 4), nPackedTileInformation, 4, nX, nY);
    }

    return pTileData;
}

// 0x0066DDE0
void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 0;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    if (pDrlgRoom)
    {
        sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    }

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, 0, nX, nY);
}

// 0x0066DF40
D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry)
{
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->pTileGrid;
    D2DrlgTileDataStrc* pTileData = &pTileGrid->pTiles.pRoofTiles[pTileGrid->nShadows];
    if (ppTileData)
    {
        pTileData->pNext = *ppTileData;
        *ppTileData = pTileData;
    }
    else
    {
        pTileData->pNext = 0;
    }

    ++pTileGrid->nShadows;

    sub_0066DC10(pTileData, pDrlgRoom, nX, nY);
    pTileData->pTile = pTileLibraryEntry;
    pTileData->nTileType = 13;
    pTileData->dwFlags = 0;
    pTileData->unk0x24 = 0;
    pTileData->nGreen = 0xFF;
    pTileData->nBlue = 0xFF;
    pTileData->nRed = 0xFF;

    DRLGROOMTILE_InitializeTileDataFlags(pDrlgRoom, pTileData, nPackedTileInformation, 13, nX, nY);

    return pTileData;
}
