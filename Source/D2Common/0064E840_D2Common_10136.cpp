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

struct D2RoomCollisionGridStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
    unsigned short* pCollisionMask;
};

struct D2BoundingBoxStrc
{
    int nLeft;
    int nBottom;
    int nRight;
    int nTop;
};

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY);// 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom);              // 0x0061A010
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);             // 0x00619730
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CEB0

static __forceinline void COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

static __forceinline unsigned short COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid && pCollisionGrid->pCollisionMask)
        {
            return pCollisionGrid->pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] & nMask;
        }
    }

    return 0x27;
}

static __forceinline unsigned short COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX <= 1 && (int)nSizeY <= 1)
    {
        return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
    }

    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064E840
void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nSize, unsigned short nMask, D2ActiveRoomStrc** ppRoom)
{
    D2CoordStrc tCenter;
    tCenter.nX = pCoord->nX;
    tCenter.nY = pCoord->nY;
    D2DrlgCoordsStrc tDrlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tDrlgCoords);

    for (int j = 1; j < 50; ++j)
    {
        const int i = -j;
        for (int y = i; y < j; y += 2)
        {
            D2ActiveRoomStrc* pRowRoom = pRoom;
            pCoord->nY = y + tCenter.nY;

            if (pCoord->nY < tDrlgCoords.nSubtileY || pCoord->nY >= tDrlgCoords.nSubtileY + tDrlgCoords.nSubtileHeight)
            {
                pRowRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pCoord->nX, pCoord->nY);
            }

            if (pRowRoom)
            {
                for (int x = i; x < j; x += 2)
                {
                    D2ActiveRoomStrc* pTestRoom = pRowRoom;
                    DUNGEON_GetRoomCoordinates(pRowRoom, &tDrlgCoords);

                    pCoord->nX = x + tCenter.nX;

                    if (pCoord->nX < tDrlgCoords.nSubtileX || pCoord->nX >= tDrlgCoords.nSubtileX + tDrlgCoords.nSubtileWidth)
                    {
                        pTestRoom = COLLISION_GetRoomBySubTileCoordinates(pRowRoom, pCoord->nX, pCoord->nY);
                    }

                    if (pTestRoom && !COLLISION_CheckMaskWithSizeXY(pTestRoom, pCoord->nX, pCoord->nY, nSize + 2, nSize + 2, nMask))
                    {
                        *ppRoom = pTestRoom;
                        return;
                    }
                }
            }
        }
    }

    *ppRoom = 0;
}
