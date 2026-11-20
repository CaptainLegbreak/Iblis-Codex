#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"

#define RAYTRACE_LOAD_ROOM() \
    nRoomX = pRoom->tCoords.nSubtileX; \
    nRoomY = pRoom->tCoords.nSubtileY; \
    nRoomEndX = nRoomX + pRoom->tCoords.nSubtileWidth; \
    nRoomEndY = nRoomY + pRoom->tCoords.nSubtileHeight;
#define RAYTRACE_IN_ROOM() (nX >= nRoomX && nX < nRoomEndX && nY >= nRoomY && nY < nRoomEndY)
#define RAYTRACE_NEXT_ROOM() \
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY); \
    if (!pRoom) \
    { \
        goto Blocked; \
    } \
    RAYTRACE_LOAD_ROOM() \
    if (!RAYTRACE_IN_ROOM()) \
    { \
        goto Blocked; \
    }
struct D2CoordStrc;
struct D2RoomCollisionGridStrc;
struct D2DrlgCoordsStrc;
struct D2BoundingBoxStrc;



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

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010


struct D2BoundingBoxStrc
{
    int nLeft;
    int nBottom;
    int nRight;
    int nTop;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
unsigned short __fastcall COLLISION_CheckCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CEB0
void __fastcall COLLISION_ResetCollisionMaskForBoundingBoxRecursively(D2ActiveRoomStrc* pRoom, D2BoundingBoxStrc* pBoundingBox, unsigned short nMask); // 0x0064CFF0
static void __stdcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DB70
static void __stdcall sub_0064DA40(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064DA40

// 0x0064E260
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask)
{
    int nX = pBegin->nX;
    int nY = pBegin->nY;
    int nEndX = pEnd->nX;
    int nEndY = pEnd->nY;
    int nDeltaX = nEndX - nX;
    int nDeltaY = nEndY - nY;
    int nXDir = 1;
    int nYDir = 1;
    int nRoomX;
    int nRoomY;
    int nRoomEndX;
    int nRoomEndY;

    if (!pRoom)
    {
        goto Blocked;
    }

    if (nDeltaX < 0)
    {
        nDeltaX = -nDeltaX;
        nXDir = -1;
    }

    if (nDeltaY < 0)
    {
        nDeltaY = -nDeltaY;
        nYDir = -1;
    }

    RAYTRACE_LOAD_ROOM()
    if (!RAYTRACE_IN_ROOM())
    {
        RAYTRACE_NEXT_ROOM()
    }

    if (nDeltaX == 0)
    {
        if (nDeltaY == 0)
        {
            D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
            if (nCollisionMask & pGrid->pCollisionMask[(nX - nRoomX) + (nY - nRoomY) * pGrid->nSubtileWidth])
            {
                goto Blocked;
            }

            return 0;
        }

        ++nDeltaY;
        while (1)
        {
            int nNext = 0;
            if (nYDir > 0)
            {
                if (nEndY >= nRoomEndY)
                {
                    const int nInRoom = nRoomEndY - nY;
                    nNext = nDeltaY - nInRoom;
                    nDeltaY = nInRoom;
                }
            }
            else if (nEndY < nRoomY)
            {
                const int nInRoom = nY - nRoomY + 1;
                nNext = nDeltaY - nInRoom;
                nDeltaY = nInRoom;
            }

            D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
            unsigned short* pMask = &pGrid->pCollisionMask[(nX - nRoomX) + (nY - nRoomY) * pGrid->nSubtileWidth];
            const int nStride = pRoom->tCoords.nSubtileWidth * nYDir;
            unsigned short* pMaskEnd = pMask + nStride * nDeltaY;
            while (pMask != pMaskEnd)
            {
                if (*pMask & nCollisionMask)
                {
                    goto Blocked;
                }

                nY += nYDir;
                pMask += nStride;
            }

            if (!nNext)
            {
                return 0;
            }

            RAYTRACE_NEXT_ROOM()
            nDeltaY = nNext;
        }
    }

    if (nDeltaY == 0)
    {
        ++nDeltaX;
        while (1)
        {
            int nNext = 0;
            if (nXDir > 0)
            {
                if (nEndX >= nRoomEndX)
                {
                    const int nInRoom = nRoomEndX - nX;
                    nNext = nDeltaX - nInRoom;
                    nDeltaX = nInRoom;
                }
            }
            else if (nEndX < nRoomX)
            {
                const int nInRoom = nX - nRoomX + 1;
                nNext = nDeltaX - nInRoom;
                nDeltaX = nInRoom;
            }

            D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
            unsigned short* pMask = &pGrid->pCollisionMask[(nX - nRoomX) + (nY - nRoomY) * pGrid->nSubtileWidth];
            unsigned short* pMaskEnd = pMask + nXDir * nDeltaX;
            while (pMask != pMaskEnd)
            {
                if (*pMask & nCollisionMask)
                {
                    goto Blocked;
                }

                pMask += nXDir;
                nX += nXDir;
            }

            if (!nNext)
            {
                return 0;
            }

            RAYTRACE_NEXT_ROOM()
            nDeltaX = nNext;
        }
    }

    if (nDeltaX >= nDeltaY)
    {
        nEndX += nXDir;
        int nDeviation = 0;
        while (1)
        {
            const int nLastX = nXDir < 0 ? nRoomX - 1 : nRoomEndX;
            const int nLastY = nYDir < 0 ? nRoomY - 1 : nRoomEndY;
            if (nY >= nRoomEndY)
            {
                goto Blocked;
            }

            D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
            unsigned short* pMask = &pGrid->pCollisionMask[(nX - nRoomX) + (nY - nRoomY) * pGrid->nSubtileWidth];
            const int nStride = pRoom->tCoords.nSubtileWidth * nYDir;
            while (1)
            {
                if (*pMask & nCollisionMask)
                {
                    goto Blocked;
                }

                nX += nXDir;
                nDeviation += nDeltaY;
                if (nDeviation >= nDeltaX)
                {
                    nDeviation -= nDeltaX;
                    nY += nYDir;
                    pMask += nStride;
                }
                pMask += nXDir;

                if (nX == nLastX || nY == nLastY)
                {
                    break;
                }

                if (nX == nEndX)
                {
                    return 0;
                }
            }

            if (nX == nEndX)
            {
                return 0;
            }

            RAYTRACE_NEXT_ROOM()
        }
    }
    else
    {
        nEndY += nYDir;
        int nDeviation = 0;
        while (1)
        {
            const int nLastX = nXDir < 0 ? nRoomX - 1 : nRoomEndX;
            const int nLastY = nYDir < 0 ? nRoomY - 1 : nRoomEndY;
            if (nY >= nRoomEndY)
            {
                goto Blocked;
            }

            D2RoomCollisionGridStrc* pGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
            unsigned short* pMask = &pGrid->pCollisionMask[(nX - nRoomX) + (nY - nRoomY) * pGrid->nSubtileWidth];
            const int nStride = pRoom->tCoords.nSubtileWidth * nYDir;
            while (1)
            {
                if (*pMask & nCollisionMask)
                {
                    goto Blocked;
                }

                nY += nYDir;
                nDeviation += nDeltaX;
                if (nDeviation >= nDeltaY)
                {
                    nDeviation -= nDeltaY;
                    nX += nXDir;
                    pMask += nXDir;
                }
                pMask += nStride;

                if (nX == nLastX || nY == nLastY)
                {
                    break;
                }

                if (nY == nEndY)
                {
                    return 0;
                }
            }

            if (nY == nEndY)
            {
                return 0;
            }

            RAYTRACE_NEXT_ROOM()
        }
    }

Blocked:
    pEnd->nX = nX;
    pEnd->nY = nY;
    return 1;
}

static __forceinline void COLLISION_CreateBoundingBox(D2BoundingBoxStrc* pBoundingBox, int nCenterX, int nCenterY, unsigned int nSizeX, unsigned int nSizeY)
{
    pBoundingBox->nLeft = nCenterX - (nSizeX / 2);
    pBoundingBox->nRight = pBoundingBox->nLeft + nSizeX - 1;
    pBoundingBox->nBottom = nCenterY - (nSizeY / 2);
    pBoundingBox->nTop = pBoundingBox->nBottom + nSizeY - 1;
}

static __forceinline unsigned short COLLISION_CheckCollisionMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
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
                pRowRoom = sub_00463740_FindRoomAtPoint(pRoom, pCoord->nX, pCoord->nY);
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
                        pTestRoom = sub_00463740_FindRoomAtPoint(pRowRoom, pCoord->nX, pCoord->nY);
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

// build: context sub_0064DB70
static void __stdcall sub_0064DB70(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask)
{
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (pRoom)
    {
        D2RoomCollisionGridStrc* pCollisionGrid = DUNGEON_GetCollisionGridFromRoom(pRoom);
        if (pCollisionGrid && pCollisionGrid->pCollisionMask)
        {
            pCollisionGrid->pCollisionMask[nX + pCollisionGrid->nSubtileWidth * (nY - pCollisionGrid->nSubtileY) - pCollisionGrid->nSubtileX] &= ~nMask;
        }
    }
}

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
