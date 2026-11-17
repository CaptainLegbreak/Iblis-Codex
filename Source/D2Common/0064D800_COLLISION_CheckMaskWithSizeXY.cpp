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

#define MASK_INVALID 0x27
#define MASK_ALL 0xFFFF

inline void COLLISION_CreateBoundingBoxInline(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

// 0x0064CA50
static unsigned short __stdcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

static unsigned short __stdcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D450

// build: context sub_0064D450
static unsigned short __stdcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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

static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D100

// build: context COLLISION_CheckCollisionMaskWithAdjacentCells
static unsigned short __stdcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pRoom)
    {
        return nMask;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pGrid)
    {
        return nMask;
    }

    unsigned short* pCollisionMask = pGrid->pCollisionMask;
    if (!pCollisionMask)
    {
        return nMask;
    }

    const int nWidth = pGrid->nSubtileWidth;
    int nCase = 0;
    if (pGrid->nSubtileX >= nX)
    {
        nCase += 1;
    }

    if (pGrid->nSubtileY >= nY)
    {
        nCase += 2;
    }

    if (pGrid->nSubtileX + nWidth <= nX + 1)
    {
        nCase += 4;
    }

    if (pGrid->nSubtileY + pGrid->nSubtileHeight <= nY + 1)
    {
        nCase += 8;
    }

    unsigned short* p = &pCollisionMask[nX + nWidth * (nY - pGrid->nSubtileY) - pGrid->nSubtileX];

    switch (nCase)
    {
    case 0:
        return (nMask & (*p | p[1] | *(p - 1) | p[nWidth] | p[-nWidth]));
    case 1:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | (nMask & (*p | p[1] | p[nWidth] | p[-nWidth]));
    case 2:
        return COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[nWidth]));
    case 3:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | p[nWidth]));
    case 4:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | (nMask & (*p | *(p - 1) | p[nWidth] | p[-nWidth]));
    case 6:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) | (nMask & (*p | *(p - 1) | p[nWidth]));
    case 8:
        return COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[-nWidth]));
    case 9:
        return COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | p[-nWidth]));
    case 12:
        return COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask) | (nMask & (*p | *(p - 1) | p[-nWidth]));
    default:
        return nMask;
    }
}

// 0x0064D4A0
static unsigned short __stdcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBoxInline(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D800
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX <= 1 && (int)nSizeY <= 1)
    {
        return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
    }

    COLLISION_CreateBoundingBoxInline(&pBoundingBox, nX, nY, nSizeX, nSizeY);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// 0x0064D870
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D4A0(pRoom, nX, nY, nMask);

    case 5:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    default:
        return MASK_ALL;
    }
}

// 0x0064D9B0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    switch (nUnitSize)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 2:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    case 3:
        return sub_0064D4A0(pRoom, nX, nY, nMask);

    default:
        return MASK_ALL;
    }
}
