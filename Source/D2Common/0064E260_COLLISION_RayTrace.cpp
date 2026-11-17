struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
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

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2RoomCollisionGridStrc* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A010

#define RAYTRACE_LOAD_ROOM() \
    nRoomX = pRoom->nSubtileX; \
    nRoomY = pRoom->nSubtileY; \
    nRoomEndX = nRoomX + pRoom->nSubtileWidth; \
    nRoomEndY = nRoomY + pRoom->nSubtileHeight;

#define RAYTRACE_IN_ROOM() (nX >= nRoomX && nX < nRoomEndX && nY >= nRoomY && nY < nRoomEndY)

#define RAYTRACE_NEXT_ROOM() \
    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY); \
    if (!pRoom) \
    { \
        goto Blocked; \
    } \
    RAYTRACE_LOAD_ROOM() \
    if (!RAYTRACE_IN_ROOM()) \
    { \
        goto Blocked; \
    }

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
            const int nStride = pRoom->nSubtileWidth * nYDir;
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
            const int nStride = pRoom->nSubtileWidth * nYDir;
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
            const int nStride = pRoom->nSubtileWidth * nYDir;
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
