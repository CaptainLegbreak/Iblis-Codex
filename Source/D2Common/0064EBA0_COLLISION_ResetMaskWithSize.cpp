struct D2ActiveRoomStrc;

struct D2BoundingBoxStrc
{
    int nLeft;
    int nBottom;
    int nRight;
    int nTop;
};

struct D2RoomCollisionGridStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    unsigned short* pCollisionMask;
};

D2ActiveRoomStrc* __fastcall sub_00463740_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010
void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CFF0

static void __stdcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DB70

// build: context sub_0064DB70
static void __stdcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid && pCollisionGrid->pCollisionMask)
        {
            pCollisionGrid->pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
        }
    }
}

static void __stdcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DA40

// build: context sub_0064DA40
static void __stdcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DB70(pRoom, nX - 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY, nMask);
    sub_0064DB70(pRoom, nX + 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY - 1, nMask);
    sub_0064DB70(pRoom, nX, nY + 1, nMask);
}

// 0x0064DBC0
static void __stdcall sub_0064DBC0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc tBoundingBox;
    tBoundingBox.nLeft = nX - 1;
    tBoundingBox.nRight = tBoundingBox.nLeft + 2;
    tBoundingBox.nBottom = nY - 1;
    tBoundingBox.nTop = tBoundingBox.nBottom + 2;
    COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &tBoundingBox, nMask);
}

// 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    if (pRoom)
    {
        switch (nUnitSize)
        {
        case 1:
            sub_0064DB70(pRoom, nX, nY, nMask);
            break;

        case 2:
            sub_0064DA40(pRoom, nX, nY, nMask);
            break;

        case 3:
            sub_0064DBC0(pRoom, nX, nY, nMask);
            break;

        case 0:
            return;

        default:
            break;
        }
    }
}
