struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[10];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2TileLibraryEntryStrc
{
    int nLightDirection;
    unsigned short nRoofHeight;
    unsigned short nFlags;
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
    int unk0x1C[5];
};

struct T00481920
{
    int unk0x00[7];
    int nMaterial1;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc* pRoom, unsigned int* pCount);    // 0x00619660
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __cdecl sub_004817A0_GetPlayerSoundEnviron();                                                           // 0x004817A0
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CACE0
static __declspec(noinline) D2DrlgTileDataStrc* sub_004CACE0_FindFloorTileAt(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nTileX = (nX - tCoords.nSubtileX) / 5;
    const int nTileY = (nY - tCoords.nSubtileY) / 5;
    unsigned int nCount;
    D2DrlgTileDataStrc* pTiles = sub_00619660_GetFloorTiles(pRoom, &nCount);
    for (unsigned int i = 0; i < nCount; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (pTile->nPosX == nTileX && pTile->nPosY == nTileY)
            return pTile;
    }
    return 0;
}

// 0x004CAD60
static __declspec(noinline) int sub_004CAD60_GetTileMaterial(D2DrlgTileDataStrc* pTileData)
{
    D2TileLibraryEntryStrc* pTile = pTileData->pTile;
    if (pTile)
    {
        const unsigned short nFlags = pTile->nFlags;
        if (nFlags & 0x20)
            return 1;
        if (nFlags & 8)
            return 2;
        if (nFlags & 0x10)
            return 3;
        if (nFlags & 0x40)
            return 4;
        if (nFlags & 0x80)
            return 6;
        if (nFlags & 0x400)
            return 5;
    }
    return 0;
}

// 0x004CADB0
int __fastcall sub_004CADB0_GetUnitFloorMaterial(D2UnitStrc* pUnit)
{
    int nRooms;
    T00481920* pSoundEnvironTxtRecord = sub_00481920_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
    int nDefault = 1;
    if (pSoundEnvironTxtRecord && pSoundEnvironTxtRecord->nMaterial1 > 0 && pSoundEnvironTxtRecord->nMaterial1 < 7)
        nDefault = pSoundEnvironTxtRecord->nMaterial1;

    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    D2DrlgTileDataStrc* pTileData = sub_004CACE0_FindFloorTileAt(pRoom, nX, nY);
    if (!pTileData)
    {
        D2ActiveRoomStrc** ppRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
        for (int i = 0; i < nRooms; ++i)
        {
            pTileData = sub_004CACE0_FindFloorTileAt(ppRooms[i], nX, nY);
            if (pTileData)
                break;
        }

    }

    if (pTileData)
    {
        const int nMaterial = sub_004CAD60_GetTileMaterial(pTileData);
        if (nMaterial)
            return nMaterial;
    }
    return nDefault;
}
