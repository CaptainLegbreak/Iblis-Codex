#include "D2Common.h"
#include "D2Structs.h"
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2PathInfoStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2CollisionTestStrc;
struct D2SeedStrc;
struct D2PathIDAStarNodeStrc;
struct D2DrlgCoordsStrc;
struct D2PathFoWallNodeStrc;
struct D2PathFoWallContextStrc;
struct D2PathMovStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};


struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    char unk0x08[0x08];
    D2PathPointStrc tTargetCoord;
    unsigned char unk_14[0x8];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x4];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x4];
    D2UnitStrc* pUnit;
    char unk0x34[0x8];
    unsigned int dwPathType;
    char unk0x40[0x8];
    unsigned int dwCollisionPattern;
    char unk0x4C[0x4];
    unsigned int nMoveTestCollisionMask;
    char unk0x54[0x4];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x20];
    int dwVelocity;
    char unk0x80[0x10];
    unsigned char nDist;
    unsigned char nDistMax;
    unsigned char unk_92[0x6];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
};

struct D2CollisionTestStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned int nCollisionPattern;
    unsigned int nCollisionMask;
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned short field_16;
    int nDistMax;
    char unk0x1C[0xC];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall sub_00679380_PathTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798
void __fastcall sub_0067A390_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067A390

enum D2C_PathConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo); // 0x006793E0


struct D2PathIDAStarNodeStrc
{
    unsigned short nFScore;
    unsigned short nHeuristicDistanceToTarget;
    unsigned short nBestDistanceFromStart;
    short nEvaluationsCount;
    D2PathPointStrc tCoord;
    const int* pNeighborsSequence;
    int nNextNeighborIndex;
    D2PathIDAStarNodeStrc* pParent;
    D2PathIDAStarNodeStrc* pBestChild;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
static __declspec(noinline) int PATH_IDAStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathIDAStarNodeStrc* pNode);

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

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

#pragma pack(push, 1)
struct D2PathFoWallNodeStrc
{
    D2PathPointStrc tPoint;
    short nFScore;
    short nHeuristicDistanceToTarget;
    short nBestDistanceFromStart;
    unsigned short wPad;
    D2PathFoWallNodeStrc* pBestParent;
    D2PathFoWallNodeStrc* pChildren[8];
    D2PathFoWallNodeStrc* pNextCachePoint;
    D2PathFoWallNodeStrc* pNextSortedByFScore;
};

struct D2PathFoWallContextStrc
{
    D2PathFoWallNodeStrc* aPendingCache[128];
    D2PathFoWallNodeStrc* aVisitedCache[128];
    D2PathFoWallNodeStrc* pSortedListByFScore;
};

#pragma pack(pop)

extern const int gaIdaStar_PointCacheHashMaskX[128]; // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[128]; // 0x006F1B98
static __declspec(noinline) D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext);
static __declspec(noinline) int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode);
static __declspec(noinline) int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints);

struct D2PathMovStrc
{
    int nDirectionIndex;
    int nPoints;
    D2PathPointStrc tCurrentCoord;
    D2PathPointStrc tTargetCoord;
    int bReachedDeadEnd;
    const int* pPrevDirection;
    const int* pNextDirection;
    int nLastSyncPointWithOtherPathIndex;
    int bPathFinished;
    D2PathPointStrc pPoints[201];
};

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern const D2CoordStrc gnDirectionsToAdjacentCellOffsets[16]; // 0x006F1D98

// 0x006793E0
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 52);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;

    const int nX0 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[0]].nX);
    const int nY0 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX0, nY0, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    const int nX1 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[1]].nX);
    const int nY1 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX1, nY1, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    const int nX2 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[2]].nX);
    const int nY2 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX2, nY2, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

// 0x00679B30
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nPrevDirection = 0xFF;
    int nbPathPoints = pDynamicPath->dwPathPoints;
    const int nDistMax = pPathInfo->nDistMax;
    D2PathPointStrc tLastSegmentEndCoord = pPathInfo->tStartCoord;
    const int nDirectionOffset = pDynamicPath->nDirOffset;
    {
        int bSegmentEndAlreadyAdded = 0;
        const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;

        D2PathPointStrc tCurCoords = tLastSegmentEndCoord;
        int nCurDistance;
        for (nCurDistance = 0; nCurDistance < nDistMax; nCurDistance += 1)
        {
            if (tCurCoords.X == tTargetCoord.X && tCurCoords.Y == tTargetCoord.Y)
            {
                break;
            }

            bSegmentEndAlreadyAdded = 0;
            int nDirections[3];
            PATH_GetDirections_6FDAB790(nDirections, tLastSegmentEndCoord, tTargetCoord);
            nDirections[0] = (nDirections[0] + nDirectionOffset) & 7;
            nDirections[1] = (nDirections[1] + nDirectionOffset) & 7;
            nDirections[2] = (nDirections[2] + nDirectionOffset) & 7;
            int nDirection;
            if (!sub_6FDAA880(tLastSegmentEndCoord, nDirections, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDirection)
            {
                break;
            }

            tCurCoords.X += gatDirectionToOffset[nDirection].nX;
            tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
            if (nDirection != nPrevDirection)
            {
                pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
                nbPathPoints += 1;
                bSegmentEndAlreadyAdded = 1;
            }
            tLastSegmentEndCoord = tCurCoords;
            nPrevDirection = nDirection;
        }

        if (!bSegmentEndAlreadyAdded && nCurDistance != 0)
        {
            pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
            nbPathPoints += 1;
        }
    }

    pDynamicPath->dwPathPoints = nbPathPoints;
    return nbPathPoints;
}

// build: context PATH_ToFP16Center
inline unsigned int PATH_ToFP16Center(unsigned short value)
{
    return (value << 16) + (1 << 15);
}

// 0x00678F00
void __fastcall sub_6FDAB810(int* a1, int* a2)
{
    if (*a1 >= 0)
    {
        while (*a1 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a1 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }

    if (*a2 >= 0)
    {
        while (*a2 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a2 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
}

// 0x00679530
static int __stdcall sub_00679530_TraceLineFP16(D2DynamicPathStrc* pDynamicPath, D2CoordStrc* pDirectionVector, D2PathPointStrc tStartCoord, D2PathPointStrc* pDestination)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    const int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    const int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    D2PathPointStrc tPrevPoint = tStartCoord;
    int nX = PATH_ToFP16Center(tPrevPoint.X);
    int nY = PATH_ToFP16Center(tPrevPoint.Y);
    D2PathPointStrc tTargetPoint = *pDestination;
    const int nDeltaX = tTargetPoint.X - (unsigned short)(nX >> 16);
    const int nDeltaY = tTargetPoint.Y - (unsigned short)(nY >> 16);
    int nVelocityX = pDirectionVector->nX;
    int nVelocityY = pDirectionVector->nY;
    D2_ASSERT(D2_ABS(nVelocityX) > 0 || D2_ABS(nVelocityY) > 0, 110);
    sub_6FDAB810(&nVelocityX, &nVelocityY);
    const int nStepX = nVelocityX;
    const int nStepY = nVelocityY;
    if (D2_ABS(nDeltaX) > D2_ABS(nDeltaY))
    {
        while (tPrevPoint.X != tTargetPoint.X)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    else
    {
        while (tPrevPoint.Y != tTargetPoint.Y)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    D2_ASSERT(tTargetPoint.X, 171);
    D2_ASSERT(tTargetPoint.Y, 172);
    return 1;
}

// 0x0067A420
static int __stdcall sub_0067A420_TraceSegment(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc tStartCoord, D2PathPointStrc tTargetCoord)
{
    if (!pDynamicPath->dwVelocity)
        return 0;

    D2CoordStrc tDirectionVector;
    sub_0067A390_GetScaledDirectionVector(pDynamicPath->dwVelocity, &tDirectionVector, tStartCoord, tTargetCoord);
    D2_ASSERT(D2_ABS(tDirectionVector.nX) > 0 || D2_ABS(tDirectionVector.nY) > 0, 834);
    sub_6FDAB810(&tDirectionVector.nX, &tDirectionVector.nY);
    return sub_00679530_TraceLineFP16(pDynamicPath, &tDirectionVector, tStartCoord, &tTargetCoord);
}

// 0x0067A4A0
int __fastcall sub_0067A4A0_TestPathPoints(D2PathInfoStrc* pPathInfo)
{
    D2PathPointStrc tPrevPoint = pPathInfo->tStartCoord;
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    struct LoopState { int count; D2ActiveRoomStrc* room; int pattern; int mask; int index; } loop;
    loop.room=pDynamicPath->pRoom;
    loop.count=pDynamicPath->dwPathPoints;
    loop.pattern=pDynamicPath->dwCollisionPattern;
    loop.mask=pDynamicPath->nMoveTestCollisionMask;
    loop.index=0;
    for (; loop.index < loop.count; ++loop.index)
    {
        const D2PathPointStrc tPoint = pDynamicPath->PathPoints[loop.index];
        int deltaX=tPoint.X-tPrevPoint.X;
        if (deltaX<0) deltaX=-deltaX;
        int deltaY;
        if (deltaX <= 1 && ((deltaY=tPoint.Y-tPrevPoint.Y), (deltaY<0 ? -deltaY : deltaY)) <= 1)
        {
            if (COLLISION_CheckAnyCollisionWithPattern(loop.room, tPoint.X, tPoint.Y, loop.pattern, loop.mask))
                return 0;
        }
        else if (!sub_0067A420_TraceSegment(pDynamicPath, tPrevPoint, tPoint))
        {
            return 0;
        }
        tPrevPoint = tPoint;
    }
    return 1;
}

// build: context PATH_MaxRef
inline const int& PATH_MaxRef(const int& a, const int& b)
{
    return a > b ? a : b;
}

// build: context UNITS_GetXPositionInline
inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// build: context UNITS_GetYPositionInline
inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context PATH_TestCollision
static __forceinline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
{
    return COLLISION_CheckAnyCollisionWithPattern(pTest->pRoom, nX, nY, pTest->nCollisionPattern, pTest->nCollisionMask);
}

// 0x00679720
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    const D2PathPointStrc tTargetPoint = *pPathDestination;

    D2PathPointStrc tLastPointWithoutCollision = tStartCoord;
    D2PathPointStrc tCurPoint = tStartCoord;
    const int nDeltaX = tTargetPoint.X - tStartCoord.X;
    const int nDeltaY = tTargetPoint.Y - tStartCoord.Y;
    const int nPointsX = (nDeltaX < 0 ? -nDeltaX : nDeltaX) + 1;
    const int nPointsY = (nDeltaY < 0 ? -nDeltaY : nDeltaY) + 1;
    int nXIncrement;
    int nYIncrement;

    if (nPointsX > nPointsY)
    {
        if (nDeltaX == 0)
        {
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            while (tLastPointWithoutCollision.Y != tTargetPoint.Y)
            {
                tCurPoint.Y += nYIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tStartCoord.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
        else
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            int nYOffset = nPointsY;
            while (tLastPointWithoutCollision.X != tTargetPoint.X)
            {
                tCurPoint.X += nXIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                nYOffset += nPointsY;
                if (nYOffset >= nPointsX)
                {
                    nYOffset -= nPointsX;
                    tCurPoint.Y += nYIncrement;
                    if (nYOffset > 0)
                    {
                        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                        {
                            *pPathDestination = tLastPointWithoutCollision;
                            return 0;
                        }
                    }
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
    }

    if (nPointsX < nPointsY)
    {
        if (nDeltaY == 0)
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            while (tLastPointWithoutCollision.X != tTargetPoint.X)
            {
                tCurPoint.X += nXIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tStartCoord.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
        else
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            int nEndOffsetX = nPointsX;
            while (tLastPointWithoutCollision.Y != tTargetPoint.Y)
            {
                tCurPoint.Y += nYIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                nEndOffsetX += nPointsX;
                if (nEndOffsetX >= nPointsY)
                {
                    nEndOffsetX -= nPointsY;
                    tCurPoint.X += nXIncrement;
                    if (nEndOffsetX > 0)
                    {
                        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                        {
                            *pPathDestination = tLastPointWithoutCollision;
                            return 0;
                        }
                    }
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
    }

    nXIncrement = nDeltaX >= 0 ? 1 : -1;
    nYIncrement = nDeltaY >= 0 ? 1 : -1;
    while (tLastPointWithoutCollision.X != tTargetPoint.X)
    {
        tCurPoint.X += nXIncrement;
        tCurPoint.Y += nYIncrement;
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
        {
            *pPathDestination = tLastPointWithoutCollision;
            return 0;
        }
        tLastPointWithoutCollision = tCurPoint;
    }
    return 1;
}

// 0x00679A60
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord)
{
    D2PathPointStrc tPoint;

    D2_ASSERT(((pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 0) || (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 1)) != 0, 324);
    D2_ASSERT(pDynamicPath->dwPathType != 4, 325);
    D2_ASSERT(pGameCoord->X != 0, 326);
    D2_ASSERT(pGameCoord->Y != 0, 327);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pDynamicPath, 1, 1);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    tPoint.X = pDynamicPath->wPosX;
    tPoint.Y = pDynamicPath->wPosY;
    return PATH_RayTrace(tPoint, pGameCoord, pDynamicPath);
}

// 0x00679F70
int __fastcall PATH_Leap_6FDAB1E0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    D2PathPointStrc pGameCoord = pPathInfo->tTargetCoord;
    pDynamicPath->PathPoints[0] = pGameCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pGameCoord);
    if (pPathInfo->tStartCoord.X == pGameCoord.X && pPathInfo->tStartCoord.Y == pGameCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = pGameCoord;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

// 0x00679FD0
int __fastcall PATH_Knockback_Client(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->PathPoints[0] = pPathInfo->tTargetCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pDynamicPath->PathPoints[0]);
    return 1;
}

// build: context PATH_ScaleDelta
static __forceinline int PATH_ScaleDelta(int nScale, int nDelta, int nMax)
{
    int nResult = nScale;
    nResult *= nDelta;
    return nResult / nMax;
}

// 0x0067A000
int __fastcall PATH_Knockback_Server(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nDeltaX = 0;
    int nDeltaY = 0;
    const int nHalfDist = (pDynamicPath->nDist >> 1) + 1;
    D2PathPointStrc tFinalCoords;
    if ((pDynamicPath ? pDynamicPath->pTargetUnit : 0))
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline((pDynamicPath ? pDynamicPath->pTargetUnit : 0));
        const int nTargetUnitY = UNITS_GetYPositionInline((pDynamicPath ? pDynamicPath->pTargetUnit : 0));
        nDeltaX = pPathInfo->tStartCoord.X - nTargetUnitX;
        nDeltaY = pPathInfo->tStartCoord.Y - nTargetUnitY;
        if (const int nMax = D2_MAX(D2_ABS(nDeltaX), D2_ABS(nDeltaY)))
        {
            nDeltaX = PATH_ScaleDelta(nHalfDist, nDeltaX, nMax);
            nDeltaY = PATH_ScaleDelta(nHalfDist, nDeltaY, nMax);
        }
        tFinalCoords.X += nDeltaX;
        tFinalCoords.Y += nDeltaY;
    }
    else
    {
        tFinalCoords = pPathInfo->tTargetCoord;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    PATH_RayTrace(pPathInfo->tStartCoord, &tFinalCoords, pDynamicPath);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, tFinalCoords.X, tFinalCoords.Y);
    if (tFinalCoords.X == pPathInfo->tStartCoord.X && tFinalCoords.Y == pPathInfo->tStartCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

#include "gen/data/Source/D2Common/Unknown_006793E0.inc"

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0067A240
int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pDynamicPath, D2SeedStrc* pSeed)
{

    int dirOffsetSequence[32] = {
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1,   1,
    };

    int nMaxPathPoints = pDynamicPath->nDistMax >> 1;
    int nCurPointIdx = 0;
    D2PathPointStrc nPrevPoint;
    nPrevPoint.X = pDynamicPath->wPosX;
    nPrevPoint.Y = pDynamicPath->wPosY;

    int v16[3];
    PATH_GetDirections_6FDAB790(v16, nPrevPoint, pDynamicPath->tTargetCoord);

    for (; nCurPointIdx < nMaxPathPoints; nCurPointIdx++)
    {
        unsigned int nDir = dirOffsetSequence[SEED_RollRandomNumber(pSeed) & 31];
        nDir = (v16[0] + nDir) % 8;
        pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
        nPrevPoint.X += 2 * gatDirectionToOffset[nDir].nX;
        nPrevPoint.Y += 2 * gatDirectionToOffset[nDir].nY;
    }

    pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
    nCurPointIdx += 1;
    pDynamicPath->dwPathPoints = nCurPointIdx;
    return nCurPointIdx;
}

// 0x0067A9F0
static int PATH_IDAStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathIDAStarNodeStrc* pNode)
{
    D2PathPointStrc* pPathPoints = pPathInfo->pDynamicPath->PathPoints;
    D2PathPointStrc aTempPathPoints[78];
    int nbPoints = 0;
    int nPrevDeltaX = -2;
    int nPrevDeltaY = -2;

    while (pNode && nbPoints < 78)
    {
        if (pNode->pParent)
        {
            const int nDeltaX = pNode->tCoord.X - pNode->pParent->tCoord.X;
            const int nDeltaY = pNode->tCoord.Y - pNode->pParent->tCoord.Y;
            if (nDeltaX != nPrevDeltaX || nDeltaY != nPrevDeltaY)
            {
                aTempPathPoints[77 - nbPoints] = pNode->tCoord;
                ++nbPoints;
                nPrevDeltaX = nDeltaX;
                nPrevDeltaY = nDeltaY;
            }
        }
        pNode = pNode->pParent;
    }

    if (nbPoints <= 1 || nbPoints >= 78)
    {
        return 0;
    }

    memcpy(pPathPoints, &aTempPathPoints[78 - nbPoints], sizeof(D2PathPointStrc) * nbPoints);
    return nbPoints;
}

int __fastcall sub_0067A9F0_EmitFlush(D2PathInfoStrc* pPathInfo, D2PathIDAStarNodeStrc* pNode)
{
    return PATH_IDAStar_FlushNodeToDynamicPath(pPathInfo, pNode);
}

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

// 0x0067AF40
static D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pPopped = pContext->pSortedListByFScore;
    if (!pPopped)
    {
        return 0;
    }

    pContext->pSortedListByFScore = pPopped->pNextSortedByFScore;

    const int nCacheIndex = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F] + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
    D2PathFoWallNodeStrc* pPreviousPoint = 0;
    for (D2PathFoWallNodeStrc* pCacheEntry = pContext->aPendingCache[nCacheIndex]; pCacheEntry != pPopped; pCacheEntry = pCacheEntry->pNextCachePoint)
    {
        pPreviousPoint = pCacheEntry;
    }

    if (!pPreviousPoint)
    {
        pContext->aPendingCache[nCacheIndex] = pPopped->pNextCachePoint;
    }
    else
    {
        pPreviousPoint->pNextCachePoint = pPopped->pNextCachePoint;
    }
    pPopped->pNextCachePoint = 0;

    const int nHash = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F] + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
    pPopped->pNextCachePoint = pContext->aVisitedCache[nHash];
    pContext->aVisitedCache[nHash] = pPopped;
    return pPopped;
}

// build: context sub_0067AF40_Shim
// calling-convention shim (not game code)
int __fastcall sub_0067AF40_Shim(D2PathFoWallContextStrc* pContext)
{
    int nCount = 0;
    while (PATH_AStar_PopBestScoreForVisit(pContext))
    {
        ++nCount;
    }
    return nCount;
}

// 0x0067B690
static int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    D2PathPointStrc* pPathPoints = pPathInfo->pDynamicPath->PathPoints;
    D2PathPointStrc aTempPathPoints[78];
    int nbPoints = 0;
    int nPrevDeltaX = -2;
    int nPrevDeltaY = -2;

    while (pNode && nbPoints < 78)
    {
        if (pNode->pBestParent)
        {
            const int nDeltaX = pNode->tPoint.X - pNode->pBestParent->tPoint.X;
            const int nDeltaY = pNode->tPoint.Y - pNode->pBestParent->tPoint.Y;
            if (nDeltaX != nPrevDeltaX || nDeltaY != nPrevDeltaY)
            {
                aTempPathPoints[77 - nbPoints] = pNode->tPoint;
                ++nbPoints;
                nPrevDeltaX = nDeltaX;
                nPrevDeltaY = nDeltaY;
            }
        }
        pNode = pNode->pBestParent;
    }

    if (nbPoints <= 0 || nbPoints >= 78)
    {
        return 0;
    }

    memcpy(pPathPoints, &aTempPathPoints[78 - nbPoints], sizeof(D2PathPointStrc) * nbPoints);
    return nbPoints;
}

int __fastcall sub_0067B690_EmitFlush(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    return PATH_AStar_FlushNodeToDynamicPath(pPathInfo, pNode);
}

// 0x0067B9F0
static int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints)
{
    nDistMax--;
    *nMajorDirection = 0;

    int nAbsDiffX = tTargetPoint.X - tStartPoint.X;
    int nAbsDiffY = tTargetPoint.Y - (int)tStartPoint.Y;
    int nStepY = 0;
    int nStepX = 0;
    int nbPoints = 0;
    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
        nStepX = -1;
    }
    else
    {
        nStepX = 1;
    }
    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
        nStepY = -1;
    }
    else
    {
        nStepY = 1;
    }

    if (nAbsDiffX == 0)
    {
        if (nAbsDiffY > 0)
        {
            unsigned short nY = tStartPoint.Y;
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                pOutPoints[nbPoints].X = tStartPoint.X;
                nY += nStepY;
                pOutPoints[nbPoints].Y = (int)nY;
                ++nbPoints;
                --nAbsDiffY;
            }
            while (nAbsDiffY);
        }
    }
    else
    {
        unsigned short nX = tStartPoint.X;
        unsigned short nY = tStartPoint.Y;
        if (nAbsDiffY == 0)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                nX += nStepX;
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = tStartPoint.Y;
                ++nbPoints;
                --nAbsDiffX;
            }
            while (nAbsDiffX);
        }
        else if (nAbsDiffX >= nAbsDiffY)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            int nDeviation = 0;
            nDistMax = nAbsDiffX;
            do
            {
                nX += nStepX;
                nDeviation += nAbsDiffY;
                if (nDeviation >= nAbsDiffX)
                {
                    nDeviation -= nAbsDiffX;
                    nY += nStepY;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nDistMax;
            }
            while (nDistMax);
        }
        else
        {
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }
            int nRemainingStepsY = nAbsDiffY;
            int nDeviation = 0;
            do
            {
                nY += nStepY;
                nDeviation += nAbsDiffX;
                if (nDeviation >= nAbsDiffY)
                {
                    nDeviation -= nAbsDiffY;
                    nX += nStepX;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nRemainingStepsY;
            }
            while (nRemainingStepsY);
        }
    }

    pOutPoints[nbPoints].X = 0;
    return nbPoints;
}

// build: context sub_0067B9F0_Shim
// calling-convention shim (not game code)
int __fastcall sub_0067B9F0_Shim(const D2PathPointStrc* pStart, const D2PathPointStrc* pTarget, int nDist)
{
    int nMajorDirection = 0;
    D2PathPointStrc aPathPoints[78];
    nDist = PATH_BresenhamLine(*pStart, *pTarget, nDist, &nMajorDirection, aPathPoints);
    return nDist + nMajorDirection + aPathPoints[1].Y;
}

static __forceinline int PATH_TestNewTargetPoint(D2PathMovStrc* pMov, D2ActiveRoomStrc* pRoom, int nCollisionPattern, int nCollisionMask)
{
    pMov->tTargetCoord.X = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nX + pMov->tCurrentCoord.X);
    pMov->tTargetCoord.Y = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nY + pMov->tCurrentCoord.Y);
    return COLLISION_CheckAnyCollisionWithPattern(pRoom, pMov->tTargetCoord.X, pMov->tTargetCoord.Y, nCollisionPattern, nCollisionMask);
}

// 0x0067BBF0
static int PATH_FindNonCollidingTargetPoint(D2PathInfoStrc* pInfo, D2PathMovStrc* pMov)
{
    D2ActiveRoomStrc* pRoom = pInfo->pStartRoom;
    const int nCollisionPattern = pInfo->nCollisionPattern;
    const int nCollisionMask = pInfo->nCollisionMask;
    D2_ASSERT(((pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 290);

    pMov->bReachedDeadEnd = 0;
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->bReachedDeadEnd = 1;
    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    return !PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask);
}

// 0x0067BD80
static void __stdcall PATH_ReplaceSubpathPoints(D2PathPointStrc* pPoints, int* pSubPathStartIdx, int nSubPathLastIdx, int* nMaxIndex, D2PathMovStrc* pMov)
{
    const int nPointsDiff = (*pSubPathStartIdx - nSubPathLastIdx) + (pMov->nPoints - 1);
    const int nLastReplacedPointIdx = nSubPathLastIdx + nPointsDiff;
    memmove(&pPoints[nLastReplacedPointIdx + 1], &pPoints[nSubPathLastIdx + 1], (*nMaxIndex - nSubPathLastIdx - 1) * sizeof(D2PathPointStrc));
    memcpy(&pPoints[*pSubPathStartIdx], &pMov->pPoints[0], pMov->nPoints * sizeof(D2PathPointStrc));
    *nMaxIndex += nPointsDiff;
    *pSubPathStartIdx = nLastReplacedPointIdx + 1;
}

int __fastcall PATH_FindSubpathWithoutObstacles(D2PathInfoStrc* pInfo, D2PathPointStrc tSubPathStart, D2PathPointStrc* pPathPoints, int* pSubPathStartIdx, int* nMaxIndex, int nMaxLength, int nMajorDirection)
{
    D2PathMovStrc tCache1 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection1, gnNextDirection1, 0, 0, 0 };
    D2PathMovStrc tCache2 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection2, gnNextDirection2, 0, 0, 0 };

    const int nDirX = pPathPoints[*pSubPathStartIdx].X - tSubPathStart.X;
    const int nDirY = pPathPoints[*pSubPathStartIdx].Y - tSubPathStart.Y;
    const int nAdjacentCellIndex = gnCellOffsetsToDirections[4 + (nDirY * 3) + nDirX];
    tCache1.nDirectionIndex = nAdjacentCellIndex + 1;
    tCache2.nDirectionIndex = nAdjacentCellIndex + 7;

    tCache2.tCurrentCoord = tSubPathStart;
    tCache1.tCurrentCoord = tSubPathStart;

    D2PathMovStrc* pCurPath = &tCache1;
    D2PathMovStrc* pOtherPath = &tCache2;

    while (!(tCache1.bPathFinished || tCache2.bPathFinished))
    {
        if (!pCurPath->bPathFinished)
        {
            if (!PATH_FindNonCollidingTargetPoint(pInfo, pCurPath))
            {
                pCurPath->bPathFinished = 1;
            }
            else
            {
                if (pCurPath->nPoints > 0)
                {
                    int nMajorDirectionDistance = 0;
                    switch (nMajorDirection)
                    {
                    case 0:
                        nMajorDirectionDistance = tSubPathStart.Y - pCurPath->tTargetCoord.Y;
                        break;
                    case 1:
                        nMajorDirectionDistance = pCurPath->tTargetCoord.X - tSubPathStart.X;
                        break;
                    case 2:
                        nMajorDirectionDistance = pCurPath->tTargetCoord.Y - tSubPathStart.Y;
                        break;
                    case 3:
                        nMajorDirectionDistance = tSubPathStart.X - pCurPath->tTargetCoord.X;
                        break;
                    }

                    if (nMajorDirectionDistance > 0)
                    {
                        const int nPointIndex = nMajorDirectionDistance - 1 + *pSubPathStartIdx;
                        if (nPointIndex < *nMaxIndex && pCurPath->tTargetCoord.X == pPathPoints[nPointIndex].X && pCurPath->tTargetCoord.Y == pPathPoints[nPointIndex].Y)
                        {
                            D2_ASSERT(pCurPath->nPoints < nMaxLength, 443);
                            pCurPath->pPoints[pCurPath->nPoints] = pCurPath->tTargetCoord;
                            pCurPath->nPoints++;
                            pCurPath->pPoints[pCurPath->nPoints].X = 0;
                            PATH_ReplaceSubpathPoints(pPathPoints, pSubPathStartIdx, nPointIndex, nMaxIndex, pCurPath);
                            return pCurPath->nPoints;
                        }
                    }
                }

                if (pOtherPath->nPoints > 1)
                {
                    if (pCurPath->nLastSyncPointWithOtherPathIndex)
                    {
                        if (pCurPath->tTargetCoord.X == pOtherPath->pPoints[pCurPath->nLastSyncPointWithOtherPathIndex - 2].X && pCurPath->tTargetCoord.Y == pOtherPath->pPoints[pCurPath->nLastSyncPointWithOtherPathIndex - 2].Y)
                        {
                            pPathPoints[*pSubPathStartIdx].X = 0;
                            *nMaxIndex = *pSubPathStartIdx;
                            return 0;
                        }
                        pCurPath->nLastSyncPointWithOtherPathIndex = 0;
                    }

                    if (pCurPath->tTargetCoord.X == pOtherPath->tCurrentCoord.X && pCurPath->tTargetCoord.Y == pOtherPath->tCurrentCoord.Y)
                        pCurPath->nLastSyncPointWithOtherPathIndex = pOtherPath->nPoints;
                }

                pCurPath->pPoints[pCurPath->nPoints] = pCurPath->tTargetCoord;
                pCurPath->nPoints++;
                pCurPath->tCurrentCoord = pCurPath->tTargetCoord;
                pCurPath->nDirectionIndex = pCurPath->pPrevDirection[pCurPath->nDirectionIndex];

                if ((nMaxLength - *nMaxIndex - 1) <= pCurPath->nPoints)
                    pCurPath->bPathFinished = 1;
            }
        }

        if (!pCurPath->nLastSyncPointWithOtherPathIndex)
        {
            D2PathMovStrc* pSwap = pOtherPath;
            pOtherPath = pCurPath;
            pCurPath = pSwap;
        }
    }

    if (nMaxLength > 80)
    {
        pPathPoints[*pSubPathStartIdx].X = 0;
        *nMaxIndex = *pSubPathStartIdx;
        return 0;
    }

    const D2PathPointStrc tLast1 = tCache1.pPoints[tCache1.nPoints - 1];
    const int nDX1 = tLast1.X - pInfo->tTargetCoord.X;
    const int nDY1 = tLast1.Y - pInfo->tTargetCoord.Y;
    const int nSquaredDist1 = nDX1 * nDX1 + nDY1 * nDY1;
    const D2PathPointStrc tLast2 = tCache2.pPoints[tCache2.nPoints - 1];
    const int nDX2 = tLast2.X - pInfo->tTargetCoord.X;
    const int nDY2 = tLast2.Y - pInfo->tTargetCoord.Y;
    const int nSquaredDist2 = nDX2 * nDX2 + nDY2 * nDY2;
    const int nDX0 = pInfo->tStartCoord.X - pInfo->tTargetCoord.X;
    const int nDY0 = pInfo->tStartCoord.Y - pInfo->tTargetCoord.Y;
    const int nSquaredDistStartToTarget = nDX0 * nDX0 + nDY0 * nDY0;

    D2PathMovStrc* pBestPath;
    if (nSquaredDist2 <= nSquaredDist1)
    {
        if (nSquaredDistStartToTarget < nSquaredDist2)
            return 0;
        pBestPath = &tCache2;
    }
    else
    {
        if (nSquaredDistStartToTarget < nSquaredDist1)
            return 0;
        pBestPath = &tCache1;
    }

    for (int i = 0; i < pBestPath->nPoints; ++i)
        pPathPoints[*pSubPathStartIdx + i] = pBestPath->pPoints[i];

    *pSubPathStartIdx += pBestPath->nPoints;
    *nMaxIndex = *pSubPathStartIdx;
    pPathPoints[*pSubPathStartIdx].X = 0;
    return pCurPath->nPoints;
}

// 0x0067C1E0
int __fastcall PATH_SimplifyToLines(D2PathPointStrc* pOutPathPoints, D2PathPointStrc* pInputPoints, D2PathPointStrc tStartCoord, int nbTempPoints)
{
    if (nbTempPoints < 2)
    {
        if (nbTempPoints == 1)
        {
            *pOutPathPoints = *pInputPoints;
            return 1;
        }
        return 0;
    }

    int nCurrentPointIdx = 0;
    int prevDeltaX = pInputPoints->X - tStartCoord.X;
    int nbOutPoints = 0;
    int nbPointsInLine = 0;
    int prevDeltaY = pInputPoints->Y - tStartCoord.Y;
    for (; nCurrentPointIdx < nbTempPoints - 1; )
    {
        int deltaX = pInputPoints[nCurrentPointIdx + 1].X - pInputPoints[nCurrentPointIdx].X;
        int deltaY = pInputPoints[nCurrentPointIdx + 1].Y - pInputPoints[nCurrentPointIdx].Y;
        if (deltaX == prevDeltaX && deltaY == prevDeltaY)
        {
            ++nbPointsInLine;
            ++nCurrentPointIdx;
        }
        else if (nbPointsInLine > 0)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else if (prevDeltaX == deltaX || prevDeltaY == deltaY)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else
        {
            nbPointsInLine = 1;
            deltaX = -2;
            ++nCurrentPointIdx;
        }
        prevDeltaY = deltaY;
        prevDeltaX = deltaX;
    }
    if (nCurrentPointIdx < nbTempPoints)
    {
        pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
    }

    return nbOutPoints;
}
