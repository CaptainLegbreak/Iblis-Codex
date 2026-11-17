struct D2ActiveRoomStrc;

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

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

// 0x0065A710
static int __stdcall sub_0065A710_IsInRoomRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRange)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    if (nX + nRange >= tCoords.nSubtileX)
    {
        if (nY + nRange >= tCoords.nSubtileY || nY - nRange <= tCoords.nSubtileY + tCoords.nSubtileHeight)
            return 1;
    }
    else if (nX - nRange <= tCoords.nSubtileX + tCoords.nSubtileWidth)
    {
        if (nY + nRange >= tCoords.nSubtileY || nY - nRange <= tCoords.nSubtileY + tCoords.nSubtileHeight)
            return 1;
    }
    return 0;
}

struct UnitFindArgStrc
{
    unsigned char unk0x00[0x20];
    int nX;
    int nY;
    int nRange;
};

// build: context sub_0065A710_Shim
// calling-convention shim (not game code)
int __stdcall sub_0065A710_Shim(UnitFindArgStrc* pArg, D2ActiveRoomStrc** ppRooms, int nRooms)
{
    int nCount = 0;
    for (int i = 0; i < nRooms; ++i)
    {
        if (sub_0065A710_IsInRoomRange(ppRooms[i], pArg->nX, pArg->nY, pArg->nRange))
            ++nCount;
    }
    return nCount;
}
