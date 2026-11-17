struct D2ActiveRoomStrc;

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
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CEB0
int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CF50

#define MASK_INVALID 0x27

static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

// 0x0064CA50
static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

    return MASK_INVALID;
}

static __declspec(noinline) int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

// 0x0064D4E0
static int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pRoom)
    {
        return 1;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pGrid || !pGrid->pCollisionMask)
    {
        return 1;
    }

    int nResult;
    int nCase = 0;
    if (pGrid->nSubtileX >= nX)
    {
        nCase = 1;
    }

    if (pGrid->nSubtileY >= nY)
    {
        nCase += 2;
    }

    if (pGrid->nSubtileX + pGrid->nSubtileWidth <= nX + 1)
    {
        nCase += 4;
    }

    if (pGrid->nSubtileY + pGrid->nSubtileHeight <= nY + 1)
    {
        nCase += 8;
    }

    const int nWidth = pGrid->nSubtileWidth;
    unsigned short* p = &pGrid->pCollisionMask[(nY - pGrid->nSubtileY) * nWidth - pGrid->nSubtileX + nX];

    switch (nCase)
    {
    case 0:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth]))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 1:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 2:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 3:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 4:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[-nWidth])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 6:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 8:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 9:
        if ((nMask & *p)
            || (nMask & p[1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        nResult = 0;
        break;

    case 12:
        if ((nMask & *p)
            || (nMask & p[-1])
            || (nMask & p[-nWidth])
            || COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask)
            || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            goto Collide;
        }
        return 0;

    default:
    Collide:
        nResult = 1;
        break;
    }

    return nResult;
}

// 0x0064D450
static unsigned short __fastcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
}

// 0x0064D0D0
static void __fastcall COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

// 0x0064D7C0
static int __fastcall sub_0064D7C0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D910
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
        return COLLISION_CheckAnyCollisionWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D7C0(pRoom, nX, nY, nMask);

    case 5:
        return COLLISION_CheckAnyCollisionWithAdjacentCells(pRoom, nX, nY, nMask);

    default:
        return 1;
    }
}
