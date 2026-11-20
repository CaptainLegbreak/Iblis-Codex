struct D2ActiveRoomStrc;
struct D2CoordStrc;

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

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);// 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom);              // 0x0061A010

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, void* pCollisionGrid); // 0x0061A040

static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall COLLISION_ResetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall COLLISION_SetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static void __fastcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static void __fastcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static int __fastcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes);
static unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask);
static void __fastcall COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY);
static unsigned short __fastcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static unsigned short __fastcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static unsigned short __fastcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D4A0
static int __fastcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static int __fastcall sub_0064D7C0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064D7C0
static void __fastcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall sub_0064DBC0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DBC0
static void __fastcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static void __fastcall sub_0064DDF0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DDF0

#define MASK_INVALID 0x27
#define MASK_ALL 0xFFFF
#define MASK_NO_PATH 0x1000
#define MASK_PET 0x2000
#define BOX_LO 1
#define BOX_HI 1

// 0x0064CA10
void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            FOG_FreeServerMemory(pMemPool, pCollisionGrid, ".\\COLLISN\\Collisn.cpp", 449, 0);
            DUNGEON_SetCollisionGridInRoom(pRoom, 0);
        }
    }
}

// 0x0064CA50
static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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

// 0x0064CAA0
static void __fastcall COLLISION_ResetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// 0x0064CAF0
static void __fastcall COLLISION_SetCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] |= nMask;
            }
        }
    }
}

// 0x0064CB30
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
}

void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] |= nMask;
            }
        }
    }
}

void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// @ref 0x0064CC30
static unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    unsigned short nResult = 0;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            nResult |= *pLine & nMask;
            ++pLine;
        }

        pLine += nWidth - (nEndX - nBeginX + 1);
    }
    return nResult;
}

// @ref 0x0064CCE0
static void __fastcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const unsigned short nInvMask = ~nMask;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine &= nInvMask;
            ++pLine;
        }

        pLine += nWidth - (nEndX - nBeginX + 1);
    }

}

// @ref 0x0064CD70
static void __fastcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{

    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine |= nMask;
            ++pLine;
        }

        pLine += nWidth - (nEndX - nBeginX + 1);
    }

}

// @ref 0x0064CDF0
static int __fastcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes)
{
    if (pBoundingBox->nBottom > pBoundingBox->nTop || pBoundingBox->nLeft > pBoundingBox->nRight)
    {
        return 0;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return 0;
    }

    pBoundingBoxes[0].nBottom = pBoundingBox->nBottom;
    pBoundingBoxes[0].nTop = pBoundingBox->nTop;
    pBoundingBoxes[0].nLeft = pBoundingBox->nLeft;
    pBoundingBoxes[0].nRight = pBoundingBox->nRight;
    int nBoundingBoxes = 1;

    const int nCollisionGridRight = pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth;
    if (pBoundingBox->nRight >= nCollisionGridRight)
    {
        pBoundingBoxes[0].nRight = nCollisionGridRight - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nRight + 1;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBox->nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nBottom;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBoxes[0].nTop;

        ++nBoundingBoxes;
    }

    const int nCollisionGridTop = pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight;
    if (pBoundingBox->nTop >= nCollisionGridTop)
    {
        pBoundingBoxes[0].nTop = nCollisionGridTop - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nLeft;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBoxes[0].nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nTop + 1;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBox->nTop;

        ++nBoundingBoxes;
    }

    return nBoundingBoxes;
}

// @ref 0x0064CEB0
static unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0)
            {
                unsigned short nResult = COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);

                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    nResult |= COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
                }

                return nResult;
            }
        }
    }

    return MASK_INVALID;
}

// @ref 0x0064CF50
static int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0 && !COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask))
            {
                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    if (COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask) != 0)
                    {
                        return 1;
                    }
                }

                return 0;
            }
        }
    }

    return 1;
}

// @ref 0x0064CFF0
static void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0)
            {
                COLLISION_ResetCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);

                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
                }
            }
        }
    }
}

// @ref 0x0064D060
static void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (pRoom)
    {
        if (D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom))
        {
            D2BoundingBoxStrc pBoundingBoxes[3];
            int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
            if (nBoundingBoxes > 0)
            {
                COLLISION_SetCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);

                for (int i = 1; i < nBoundingBoxes; ++i)
                {
                    COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
                }
            }
        }
    }
}

// 0x0064D0D0
static void __fastcall COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

// @ref 0x0064D100
static unsigned short __fastcall COLLISION_CheckCollisionMaskWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2ActiveRoomStrc* pAdjRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pAdjRoom)
    {
        return nMask;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pAdjRoom);
    if (!pGrid || !pGrid->pCollisionMask)
    {
        return nMask;
    }

    int nCase = 0;
    if (pGrid->nSubtileX >= nX)
    {
        nCase += 1;
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

    unsigned short* p = &pGrid->pCollisionMask[nX + pGrid->nSubtileWidth * (nY - pGrid->nSubtileY) - pGrid->nSubtileX];

    switch (nCase)
    {
    case 0:
        return (nMask & (*p | p[1] | *(p - 1) | p[pGrid->nSubtileWidth] | p[-pGrid->nSubtileWidth]));
    case 1:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX - 1, nY, nMask) | (nMask & (*p | p[1] | p[pGrid->nSubtileWidth] | p[-pGrid->nSubtileWidth]));
    case 2:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[pGrid->nSubtileWidth]));
    case 3:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pAdjRoom, nX, nY - 1, nMask) | (nMask & (*p | p[1] | p[pGrid->nSubtileWidth]));
    case 4:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX + 1, nY, nMask) | (nMask & (*p | *(p - 1) | p[pGrid->nSubtileWidth] | p[-pGrid->nSubtileWidth]));
    case 6:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pAdjRoom, nX, nY - 1, nMask) | (nMask & (*p | *(p - 1) | p[pGrid->nSubtileWidth]));
    case 8:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | *(p - 1) | p[-pGrid->nSubtileWidth]));
    case 9:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX - 1, nY, nMask) | COLLISION_CheckCollisionMask(pAdjRoom, nX, nY + 1, nMask) | (nMask & (*p | p[1] | p[-pGrid->nSubtileWidth]));
    case 12:
        return COLLISION_CheckCollisionMask(pAdjRoom, nX + 1, nY, nMask) | COLLISION_CheckCollisionMask(pAdjRoom, nX, nY + 1, nMask) | (nMask & (*p | *(p - 1) | p[-pGrid->nSubtileWidth]));
    default:
        return nMask;
    }
}

// 0x0064D450
static unsigned short __fastcall sub_0064D450(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
}
#if 0
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
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
#endif

// build: context sub_0064D4A0
static unsigned short __fastcall sub_0064D4A0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// @ref 0x0064D4E0
static int __fastcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 1;
    }

    D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pGrid || !pGrid->pCollisionMask)
    {
        return 1;
    }

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

    unsigned short* p = &pGrid->pCollisionMask[nX + pGrid->nSubtileWidth * (nY - pGrid->nSubtileY) - pGrid->nSubtileX];

    switch (nCase)
    {
    case 0:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[1] || nMask & p[-pGrid->nSubtileWidth] || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        return 0;

    case 1:
        if (nMask & *p || nMask & p[1] || nMask & p[-pGrid->nSubtileWidth] || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            return 1;
        }

        return 0;

    case 2:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[1] || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            return 1;
        }

        return 0;

    case 3:
        if (nMask & *p || nMask & p[1] || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask) || COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask))
        {
            return 1;
        }

        return 0;

    case 4:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[-pGrid->nSubtileWidth] || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask))
        {
            return 1;
        }

        return 0;

    case 6:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) || COLLISION_CheckCollisionMask(pRoom, nX, nY - 1, nMask))
        {
            return 1;
        }

        return 0;

    case 8:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[1] || nMask & p[-pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            return 1;
        }

        return 0;

    case 9:
        if (nMask & *p || nMask & p[1] || nMask & p[-pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX - 1, nY, nMask) || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            return 1;
        }

        return 0;

    case 12:
        if (nMask & *p || nMask & *(p - 1) || nMask & p[-pGrid->nSubtileWidth])
        {
            return 1;
        }

        if (COLLISION_CheckCollisionMask(pRoom, nX + 1, nY, nMask) || COLLISION_CheckCollisionMask(pRoom, nX, nY + 1, nMask))
        {
            return 1;
        }

        return 0;

    default:
        return 1;
    }
}

// build: context sub_0064D7C0
static int __fastcall sub_0064D7C0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    return COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// @ref 0x0064D800
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX <= 1 && (int)nSizeY <= 1)
    {
        return COLLISION_CheckCollisionMask(pRoom, nX, nY, nMask);
    }

    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
    return COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// @ref 0x0064D870
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
    case 5:
        return COLLISION_CheckCollisionMaskWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D4A0(pRoom, nX, nY, nMask);

    default:
        return MASK_ALL;
    }
}

// @ref 0x0064D910
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask)
{
    switch (nCollisionPattern)
    {
    case 0:
        return sub_0064D450(pRoom, nX, nY, nMask);

    case 1:
    case 3:
    case 5:
        return COLLISION_CheckAnyCollisionWithAdjacentCells(pRoom, nX, nY, nMask);

    case 2:
    case 4:
        return sub_0064D7C0(pRoom, nX, nY, nMask);

    default:
        return 1;
    }
}

// @ref 0x0064D9B0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    switch (nUnitSize)
    {
    case 0:
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

// 0x0064DA40
static void __fastcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DB70(pRoom, nX - 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY, nMask);
    sub_0064DB70(pRoom, nX + 1, nY, nMask);
    sub_0064DB70(pRoom, nX, nY - 1, nMask);
    sub_0064DB70(pRoom, nX, nY + 1, nMask);
}

// 0x0064DB70
static void __fastcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
            }
        }
    }
}

// build: context sub_0064DBC0
static void __fastcall sub_0064DBC0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// build: context COLLISION_ResetMaskWithSizeXY
void __stdcall COLLISION_ResetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if ((int)nSizeX > 0 && (int)nSizeY > 0)
    {
        if (nSizeX != 1 || nSizeY != 1)
        {
            COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
            COLLISION_ResetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
        }
        else
        {
            COLLISION_ResetCollisionMask(pRoom, nX, nY, nMask);
        }
    }
}

// 0x0064DC80
static void __fastcall sub_0064DC80(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    sub_0064DDB0(pRoom, nX - 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY, nMask);
    sub_0064DDB0(pRoom, nX + 1, nY, nMask);
    sub_0064DDB0(pRoom, nX, nY - 1, nMask);
    sub_0064DDB0(pRoom, nX, nY + 1, nMask);
}

// 0x0064DDB0
static void __fastcall sub_0064DDB0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid)
        {
            unsigned short* pCollisionMask = pCollisionGrid->pCollisionMask;
            if (pCollisionMask)
            {
                pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] |= nMask;
            }
        }
    }
}

// build: context sub_0064DDF0
static void __fastcall sub_0064DDF0(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;
    COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, 3, 3);
    COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
}

// @ref 0x0064DE30
void __stdcall COLLISION_SetMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask)
{
    D2BoundingBoxStrc pBoundingBox;

    if (nSizeX != 1 || nSizeY != 1)
    {
        COLLISION_CreateBoundingBox(&pBoundingBox, nX, nY, nSizeX, nSizeY);
        COLLISION_SetCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBox, nMask);
    }
    else
    {
        COLLISION_SetCollisionMask(pRoom, nX, nY, nMask);
    }
}

// @ref 0x0064EA00
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask)
{
    switch (nUnitSize)
    {
    case 1:
        sub_0064DDB0(pRoom, nX, nY, nMask);
        break;

    case 2:
        sub_0064DC80(pRoom, nX, nY, nMask);
        break;

    case 3:
        sub_0064DDF0(pRoom, nX, nY, nMask);
        break;
    }
}

// 0x0064EC10
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask)
{
    if (pRoom)
    {
    switch (nCollisionPattern)
    {
    case 0:
        return;

    case 1:
        sub_0064DA40(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DB70(pRoom, nX, nY, MASK_NO_PATH);
        }
        break;

    case 2:
        sub_0064DBC0(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DA40(pRoom, nX, nY, MASK_NO_PATH);
        }
        break;

    case 3:
        sub_0064DA40(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DB70(pRoom, nX, nY, MASK_PET);
        }
        break;

    case 4:
        sub_0064DBC0(pRoom, nX, nY, nMask);
        if (nMask)
        {
            sub_0064DA40(pRoom, nX, nY, MASK_PET);
        }
        break;

    case 5:
        sub_0064DA40(pRoom, nX, nY, nMask);
        break;
    }
    }
}
