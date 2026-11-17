struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
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

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

// 0x00545340
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius)
{
    D2CoordStrc tCenter;
    tCenter.nX = pCoord->nX - (nSize >> 1);
    tCenter.nY = pCoord->nY - (nSize >> 1);

    D2CoordStrc tPos;
    tPos.nX = tCenter.nX;

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    for (int j = 1; j < nRadius; ++j)
    {
        const int i = -j;
        for (int y = j; y > i; y -= 2)
        {
            tPos.nY = y + tCenter.nY;

            D2ActiveRoomStrc* pRoom1 = pRoom;
            if (tPos.nY < drlgCoords.nSubtileY || tPos.nY >= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight)
            {
                pRoom1 = COLLISION_GetRoomBySubTileCoordinates(pRoom, tPos.nX, tPos.nY);
            }

            if (pRoom1)
            {
                for (int x = i; x < j; x += 2)
                {
                    D2ActiveRoomStrc* pRoom2 = pRoom1;
                    DUNGEON_GetRoomCoordinates(pRoom2, &drlgCoords);

                    tPos.nX = x + tCenter.nX;

                    if (tPos.nX < drlgCoords.nSubtileX || tPos.nY >= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                    {
                        pRoom2 = COLLISION_GetRoomBySubTileCoordinates(pRoom1, tPos.nX, tPos.nY);
                    }

                    if (pRoom2 && !COLLISION_CheckMaskWithSizeXY(pRoom2, tPos.nX, tPos.nY, 2 * nSize + 1, 2 * nSize + 1, fCollision)
                        && (unsigned int)tPos.nX >= (unsigned int)drlgCoords.nSubtileX && (unsigned int)tPos.nX < (unsigned int)(drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                        && (unsigned int)tPos.nY >= (unsigned int)drlgCoords.nSubtileY && (unsigned int)tPos.nY < (unsigned int)(drlgCoords.nSubtileY + drlgCoords.nSubtileHeight))
                    {
                        pCoord->nX = (nSize >> 1) + tPos.nX;
                        pCoord->nY = (nSize >> 1) + tPos.nY;
                        *ppRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pCoord->nX, pCoord->nY);
                        return;
                    }
                }
            }
        }
    }

    *ppRoom = 0;
}
