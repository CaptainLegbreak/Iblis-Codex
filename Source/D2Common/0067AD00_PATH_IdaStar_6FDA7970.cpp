struct D2PathInfoStrc;

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

    int PATH_IdaStar_ComputePathWithRooms(D2PathInfoStrc* pPathInfo); // 0x0067AAA0
};

struct D2ActiveRoomStrc;

struct D2PathInfoStrc
{
    int tStartCoord;
    int tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int unk0x10;
    unsigned char field_14;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730

// 0x0067AD00
int __fastcall PATH_IdaStar_6FDA7970(D2PathInfoStrc* pPathInfo)
{
    pPathInfo->field_14 *= 2;
    D2DrlgCoordsStrc tPathRoomsAABB;
    DUNGEON_GetRoomCoordinates(pPathInfo->pStartRoom, &tPathRoomsAABB);
    D2DrlgCoordsStrc tStartRoomCoords = tPathRoomsAABB;

    int nAABBHeight = 0;
    int nAABBWidth = 0;

    if (pPathInfo->pTargetRoom && pPathInfo->pStartRoom != pPathInfo->pTargetRoom)
    {
        D2DrlgCoordsStrc tTargetRoomCoords;
        DUNGEON_GetRoomCoordinates(pPathInfo->pTargetRoom, &tTargetRoomCoords);
        if (tTargetRoomCoords.nSubtileX < tStartRoomCoords.nSubtileX)
        {
            tPathRoomsAABB.nSubtileX = tTargetRoomCoords.nSubtileX;
            nAABBWidth = tStartRoomCoords.nSubtileX + tStartRoomCoords.nSubtileWidth - tTargetRoomCoords.nSubtileX;
        }
        else
        {
            tPathRoomsAABB.nSubtileX = tStartRoomCoords.nSubtileX;
            nAABBWidth = tTargetRoomCoords.nSubtileX + tTargetRoomCoords.nSubtileWidth - tStartRoomCoords.nSubtileX;
        }
        tPathRoomsAABB.nSubtileWidth = nAABBWidth;
        if (tTargetRoomCoords.nSubtileY < tStartRoomCoords.nSubtileY)
        {
            tPathRoomsAABB.nSubtileY = tTargetRoomCoords.nSubtileY;
            nAABBHeight = tStartRoomCoords.nSubtileY + tStartRoomCoords.nSubtileHeight - tTargetRoomCoords.nSubtileY;
        }
        else
        {
            tPathRoomsAABB.nSubtileY = tStartRoomCoords.nSubtileY;
            nAABBHeight = tTargetRoomCoords.nSubtileY + tTargetRoomCoords.nSubtileHeight - tStartRoomCoords.nSubtileY;
        }
        tPathRoomsAABB.nSubtileHeight = nAABBHeight;
        if (nAABBWidth != tStartRoomCoords.nSubtileWidth)
        {
            goto height;
        }
        goto widen;
    }
    else
    {
        nAABBHeight = tPathRoomsAABB.nSubtileHeight;
        nAABBWidth = tPathRoomsAABB.nSubtileWidth;
widen:
        tPathRoomsAABB.nSubtileX -= 10;
        tPathRoomsAABB.nSubtileWidth = nAABBWidth + 20;
    }
height:
    if (nAABBHeight == tStartRoomCoords.nSubtileHeight)
    {
        nAABBHeight += 20;
        tPathRoomsAABB.nSubtileY -= 10;
        tPathRoomsAABB.nSubtileHeight = nAABBHeight;
    }
    return tPathRoomsAABB.PATH_IdaStar_ComputePathWithRooms(pPathInfo);
}
