#include "D2Common.h"
struct D2RoomCollisionGridStrc;
struct D2BoundingBoxStrc;

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

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CEB0
int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CF50
static unsigned short __fastcall COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);
static __declspec(noinline) int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);

// build: context COLLISION_CheckCollisionMaskForBoundingBox
static unsigned short __stdcall COLLISION_CheckCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    unsigned short nResult = 0;
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            nResult |= *pLine & nMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
    return nResult;
}

// build: context COLLISION_ResetCollisionMaskForBoundingBox
static void __stdcall COLLISION_ResetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;
    const unsigned short nInvMask = ~nMask;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine &= nInvMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
}

// build: context COLLISION_SetCollisionMaskForBoundingBox
static void __stdcall COLLISION_SetCollisionMaskForBoundingBox(D2RoomCollisionGridStrc* pCollisionGrid, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    const int nBeginY = pBoundingBox->nBottom - pCollisionGrid->nSubtileY;
    const int nEndY = pBoundingBox->nTop - pCollisionGrid->nSubtileY;
    const int nEndX = pBoundingBox->nRight - pCollisionGrid->nSubtileX;
    const int nBeginX = pBoundingBox->nLeft - pCollisionGrid->nSubtileX;
    const int nWidth = pCollisionGrid->nSubtileWidth;
    unsigned short* pLine = &pCollisionGrid->pCollisionMask[nBeginX + nBeginY * nWidth];
    const int nLineSkip = nWidth + (nBeginX - nEndX) - 1;

    for (int y = nBeginY; y <= nEndY; ++y)
    {
        for (int x = nBeginX; x <= nEndX; ++x)
        {
            *pLine |= nMask;
            ++pLine;
        }

        pLine += nLineSkip;
    }
}

// 0x0064CDF0
static int __stdcall COLLISION_AdaptBoundingBoxToGrid(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, D2BoundingBoxStrc* pBoundingBoxes)
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

    int nBoundingBoxes = 1;
    pBoundingBoxes[0].nBottom = pBoundingBox->nBottom;
    pBoundingBoxes[0].nTop = pBoundingBox->nTop;
    pBoundingBoxes[0].nLeft = pBoundingBox->nLeft;
    pBoundingBoxes[0].nRight = pBoundingBox->nRight;

    if (pBoundingBox->nRight >= pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth)
    {
        pBoundingBoxes[0].nRight = pCollisionGrid->nSubtileX + pCollisionGrid->nSubtileWidth - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nRight + 1;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBox->nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nBottom;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBoxes[0].nTop;

        ++nBoundingBoxes;
    }

    if (pBoundingBox->nTop >= pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight)
    {
        pBoundingBoxes[0].nTop = pCollisionGrid->nSubtileY + pCollisionGrid->nSubtileHeight - 1;

        pBoundingBoxes[nBoundingBoxes].nLeft = pBoundingBoxes[0].nLeft;
        pBoundingBoxes[nBoundingBoxes].nRight = pBoundingBoxes[0].nRight;
        pBoundingBoxes[nBoundingBoxes].nBottom = pBoundingBoxes[0].nTop + 1;
        pBoundingBoxes[nBoundingBoxes].nTop = pBoundingBox->nTop;

        ++nBoundingBoxes;
    }

    return nBoundingBoxes;
}

// 0x0064CEB0
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (!pRoom)
    {
        return MASK_INVALID;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return MASK_INVALID;
    }

    D2BoundingBoxStrc pBoundingBoxes[3];
    const int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
    if (nBoundingBoxes <= 0)
    {
        return MASK_INVALID;
    }

    unsigned short nResult = COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask);
    for (int i = 1; i < nBoundingBoxes; ++i)
    {
        nResult |= COLLISION_CheckCollisionMaskForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask);
    }

    return nResult;
}

// 0x0064CF50
int __fastcall COLLISION_CheckAnyCollisionForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, pBoundingBox->nLeft, pBoundingBox->nBottom);
    if (!pRoom)
    {
        return 1;
    }

    D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
    if (!pCollisionGrid)
    {
        return 1;
    }

    D2BoundingBoxStrc pBoundingBoxes[3];
    const int nBoundingBoxes = COLLISION_AdaptBoundingBoxToGrid(pRoom, pBoundingBox, pBoundingBoxes);
    if (nBoundingBoxes <= 0 || COLLISION_CheckCollisionMaskForBoundingBox(pCollisionGrid, &pBoundingBoxes[0], nMask))
    {
        return 1;
    }

    for (int i = 1; i < nBoundingBoxes; ++i)
    {
        if (COLLISION_CheckAnyCollisionForBoundingBoxRecursively(pRoom, &pBoundingBoxes[i], nMask))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0064CFF0
void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
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

// 0x0064D060
void __fastcall COLLISION_SetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask)
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

// 0x0064D4E0
static int __stdcall COLLISION_CheckAnyCollisionWithAdjacentCells(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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
