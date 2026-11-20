#include "D2Common.h"
#include "D2Structs.h"
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2CollisionTestStrc;
struct D2PathInfoStrc;
struct D2PathFoWallNodeStrc;
struct D2PathFoWallContextStrc;
struct D2PathMovStrc;

enum D2C_PathConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

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
    char unk0x08[0x14];
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
    char unk0x91[0x7];
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
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo); // 0x006793E0
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo); // 0x00679B30

typedef int BOOL;

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
    D2PathFoWallNodeStrc aNodesStorage[200];
    int nNodesCount;
    D2PathFoWallNodeStrc* aPointsStack[200];
    int nStackCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern const int gaIdaStar_PointCacheHashMaskX[]; // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[]; // 0x006F1B98
int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067ADC0
D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE00
D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE50
D2PathFoWallNodeStrc* __fastcall sub_0067B1C0_AllocTableEntry(D2PathFoWallContextStrc* pContext); // 0x0067B1C0

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

inline const int& PATH_MaxRef(const int& a, const int& b)
{
    return a > b ? a : b;
}

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

// build: context sub_6FDAA880
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 52);

    const int nCollisionMask = pPathInfo->nCollisionMask;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;

    D2PathPointStrc tTest0;
    tTest0.X = tPoint.X + gatDirectionToOffset[pTestDir[0]].nX;
    tTest0.Y = tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest0.X, tTest0.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    D2PathPointStrc tTest1;
    tTest1.X = tPoint.X + gatDirectionToOffset[pTestDir[1]].nX;
    tTest1.Y = tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest1.X, tTest1.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    D2PathPointStrc tTest2;
    tTest2.X = tPoint.X + gatDirectionToOffset[pTestDir[2]].nX;
    tTest2.Y = tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tTest2.X, tTest2.Y, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

static __forceinline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
{
    return COLLISION_CheckAnyCollisionWithPattern(pTest->pRoom, nX, nY, pTest->nCollisionPattern, pTest->nCollisionMask);
}

// build: context PATH_RayTrace
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath)
{
    D2CollisionTestStrc tTest;
    tTest.pRoom = pDynamicPath->pRoom;
    tTest.nCollisionPattern = pDynamicPath->dwCollisionPattern;
    tTest.nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    const D2PathPointStrc tTargetPoint = *pPathDestination;

    D2PathPointStrc tLastPointWithoutCollision = tStartCoord;
    D2PathPointStrc tCurPoint = tStartCoord;
    const int nDeltaX = tTargetPoint.X - tStartCoord.X;
    const int nDeltaY = tTargetPoint.Y - tStartCoord.Y;
    const int nPointsX = (nDeltaX < 0 ? -nDeltaX : nDeltaX) + 1;
    const int nPointsY = (nDeltaY < 0 ? -nDeltaY : nDeltaY) + 1;

    if (nPointsX > nPointsY)
    {
        if (nDeltaX == 0)
        {
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.Y != tTargetPoint.Y)
            {
                do
                {
                    tCurPoint.Y += nYIncrement;
                    if (PATH_TestCollision(&tTest, tStartCoord.X, tCurPoint.Y))
                    {
                        *pPathDestination = tLastPointWithoutCollision;
                        return 0;
                    }
                    tLastPointWithoutCollision = tCurPoint;
                }
                while (tCurPoint.Y != tTargetPoint.Y);
            }
        }
        else
        {
            const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.X != tTargetPoint.X)
            {
                int nYOffset = nPointsY;
                while (1)
                {
                    tCurPoint.X += nXIncrement;
                    if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
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
                            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                            {
                                *pPathDestination = tLastPointWithoutCollision;
                                return 0;
                            }
                        }
                    }
                    tLastPointWithoutCollision = tCurPoint;
                    if (tCurPoint.X == tTargetPoint.X)
                    {
                        return 1;
                    }
                }
            }
        }
        return 1;
    }

    if (nPointsX >= nPointsY)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.Y += nYIncrement;
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    if (nDeltaY == 0)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tStartCoord.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
    const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
    if (tStartCoord.Y == tTargetPoint.Y)
    {
        return 1;
    }

    int nEndOffsetX = nPointsX;
    do
    {
        tCurPoint.Y += nYIncrement;
        if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
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
                if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
            }
        }
        tLastPointWithoutCollision = tCurPoint;
    }
    while (tCurPoint.Y != tTargetPoint.Y);
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

// build: context sub_6FDAA720
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    const int nDistMax = pPathInfo->nDistMax;
    int nbPathPoints = pDynamicPath->dwPathPoints;
    D2PathPointStrc tLastSegmentEndCoord = pPathInfo->tStartCoord;
    const int nDirectionOffset = pDynamicPath->nDirOffset;
    {
        const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
        int nPrevDirection = 0xFF;
        int bSegmentEndAlreadyAdded = 0;

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

int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    if (pPath->nDirOffset)
    {
        return sub_6FDAA720(pPathInfo);
    }

    D2PathPointStrc nNextPoint = pPathInfo->tTargetCoord;
    pPath->PathPoints[0] = nNextPoint;

    if (PATH_CheckCollisionsToNextPosition(pPath, &nNextPoint))
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    if (sub_00679380_PathTableHeuristic(nNextPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    {
        D2PathPointStrc tPoint = pPathInfo->tStartCoord;
        D2PathPointStrc tCurCoords = pPathInfo->tStartCoord;
        if (tPoint.X != nNextPoint.X || tPoint.Y != nNextPoint.Y)
        {
            pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
            pPath->dwPathPoints += 1;
            tPoint = nNextPoint;
            tCurCoords = nNextPoint;
        }

        const int nDistMax = pPathInfo->nDistMax;
        nNextPoint = pPathInfo->tTargetCoord;
        int nPrevDir = 0xFF;
        int nNewPointsCount = pPath->dwPathPoints;
        int bNotStraightLine = 0;
        int nCurDist = 0;
        if (nDistMax > 0)
        {
            D2PathPointStrc* pPathPointsEnd = &pPath->PathPoints[pPath->dwPathPoints];
            do
            {
                if (tCurCoords.X == nNextPoint.X && tCurCoords.Y == nNextPoint.Y)
                {
                    break;
                }

                bNotStraightLine = 0;
                int aTestDir[3];
                PATH_GetDirections_6FDAB790(aTestDir, tPoint, nNextPoint);
                int nDirection;
                if (!sub_6FDAA880(tPoint, aTestDir, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDir)
                {
                    goto LABEL_20;
                }

                tCurCoords.X += gatDirectionToOffset[nDirection].nX;
                tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
                if (nDirection != nPrevDir)
                {
                    if (tPoint.X != pPathInfo->tStartCoord.X || tPoint.Y != pPathInfo->tStartCoord.Y)
                    {
                        *pPathPointsEnd = tPoint;
                        nNewPointsCount += 1;
                        ++pPathPointsEnd;
                    }
                    bNotStraightLine = 1;
                }
                tPoint = tCurCoords;
                nPrevDir = nDirection;
                nCurDist += 1;
            }
            while (nCurDist < nDistMax);

            if (bNotStraightLine)
            {
                goto LABEL_22;
            }
        LABEL_20:
            if (nCurDist)
            {
                pPath->PathPoints[nNewPointsCount] = tPoint;
                nNewPointsCount += 1;
            }
        }
    LABEL_22:
        pPath->dwPathPoints = nNewPointsCount;
    }

    return pPath->dwPathPoints;
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

static __forceinline unsigned short PATH_AStar_HeuristicInline(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint1.X - tPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint1.Y - tPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX >= nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

// 0x0067AEA0
static void PATH_AStar_PushToVisitedCache(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNode)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pNode->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pNode->tPoint.X & 0x7F]) & 0x7F;
    pNode->pNextCachePoint = pContext->aVisitedCache[nHash];
    pContext->aVisitedCache[nHash] = pNode;
}

// 0x0067AED0
static void PATH_AStar_MakeCandidate(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNode)
{
    D2PathFoWallNodeStrc* pCur = pContext->pSortedListByFScore;
    D2PathFoWallNodeStrc* pPrev = 0;
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pNode->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pNode->tPoint.X & 0x7F]) & 0x7F;
    pNode->pNextCachePoint = pContext->aPendingCache[nHash];
    pContext->aPendingCache[nHash] = pNode;

    const int nFScore = pNode->nFScore;
    for (; pCur; pCur = pCur->pNextSortedByFScore)
    {
        if (pCur->nFScore >= nFScore)
        {
            break;
        }
        pPrev = pCur;
    }

    if (pPrev)
    {
        pPrev->pNextSortedByFScore = pNode;
        pNode->pNextSortedByFScore = pCur;
    }
    else
    {
        pNode->pNextSortedByFScore = pContext->pSortedListByFScore;
        pContext->pSortedListByFScore = pNode;
    }
}

static __forceinline D2PathFoWallNodeStrc* PATH_AStar_RemoveFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pToRemove)
{
    D2PathFoWallNodeStrc* pPrev = 0;
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pToRemove->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pToRemove->tPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pCur = pContext->aPendingCache[nHash]; pCur != pToRemove; pCur = pCur->pNextCachePoint)
    {
        pPrev = pCur;
    }

    if (pPrev)
    {
        pPrev->pNextCachePoint = pToRemove->pNextCachePoint;
    }
    else
    {
        pContext->aPendingCache[nHash] = pToRemove->pNextCachePoint;
    }
    pToRemove->pNextCachePoint = 0;
    return pPrev;
}

// 0x0067AF40
static D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pPopped = pContext->pSortedListByFScore;
    if (!pPopped) return pPopped;
    {
        pContext->pSortedListByFScore = pPopped->pNextSortedByFScore;
        const int nCacheIndex = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F]
            + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
        D2PathFoWallNodeStrc* pPreviousPoint = 0;
        D2PathFoWallNodeStrc* pCacheEntry = pContext->aPendingCache[nCacheIndex];
        while (pCacheEntry != pPopped)
        {
            pPreviousPoint = pCacheEntry;
            pCacheEntry = pCacheEntry->pNextCachePoint;
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
        const int nHash = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F]
            + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
        pPopped->pNextCachePoint = pContext->aVisitedCache[nHash];
        pContext->aVisitedCache[nHash] = pPopped;
    }
    return pPopped;
}

// 0x0067AFE0
static void PATH_AStar_PropagateNewFScoreToChildren(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNewNode)
{
    pContext->aPointsStack[pContext->nStackCount++] = pNewNode;
    while (pContext->nStackCount != 0)
    {
        D2PathFoWallNodeStrc* pCurrent = pContext->aPointsStack[--pContext->nStackCount];
        for (int i = 0; i < 8; ++i)
        {
            D2PathFoWallNodeStrc* pChild = pCurrent->pChildren[i];
            if (!pChild)
            {
                break;
            }

            const short nCost = (pCurrent->tPoint.X == pChild->tPoint.X || pCurrent->tPoint.Y == pChild->tPoint.Y) ? 2 : 3;
            const short nDistance = pCurrent->nBestDistanceFromStart + nCost;
            if (nDistance < pChild->nBestDistanceFromStart)
            {
                pChild->pBestParent = pCurrent;
                pChild->nBestDistanceFromStart = nDistance;
                pChild->nFScore = nDistance + pChild->nHeuristicDistanceToTarget;
                pContext->aPointsStack[pContext->nStackCount++] = pChild;
            }
        }
    }
}

static __forceinline void PATH_AStar_AddChildToNode(D2PathFoWallNodeStrc* pNode, D2PathFoWallNodeStrc* pChild)
{
    if (!pNode->pChildren[0])
        pNode->pChildren[0] = pChild;
    else if (!pNode->pChildren[1])
        pNode->pChildren[1] = pChild;
    else if (!pNode->pChildren[2])
        pNode->pChildren[2] = pChild;
    else if (!pNode->pChildren[3])
        pNode->pChildren[3] = pChild;
    else if (!pNode->pChildren[4])
        pNode->pChildren[4] = pChild;
    else if (!pNode->pChildren[5])
        pNode->pChildren[5] = pChild;
    else if (!pNode->pChildren[6])
        pNode->pChildren[6] = pChild;
    else if (!pNode->pChildren[7])
        pNode->pChildren[7] = pChild;
}

// 0x0067B200
static BOOL __stdcall PATH_AStar_EvaluateNeighbor(D2PathFoWallContextStrc* pContext, D2PathPointStrc tNewPointCoord, D2PathPointStrc tTargetCoord, D2PathFoWallNodeStrc* pCurrentNode)
{
    const short nCost = (pCurrentNode->tPoint.X == tNewPointCoord.X || pCurrentNode->tPoint.Y == tNewPointCoord.Y) ? 2 : 3;
    const short nNewPointDistance = pCurrentNode->nBestDistanceFromStart + nCost;

    D2PathFoWallNodeStrc* pNewNode = PATH_AStar_GetNodeFromPendingCache(pContext, tNewPointCoord);
    if (pNewNode)
    {
        PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
        if (nNewPointDistance < pNewNode->nBestDistanceFromStart)
        {
            pNewNode->pBestParent = pCurrentNode;
            pNewNode->nBestDistanceFromStart = nNewPointDistance;
            pNewNode->nFScore = nNewPointDistance + pNewNode->nHeuristicDistanceToTarget;
        }
        return TRUE;
    }

    pNewNode = PATH_AStar_FindPointInVisitedCache(pContext, tNewPointCoord);
    if (pNewNode)
    {
        PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
        if (nNewPointDistance < pNewNode->nBestDistanceFromStart)
        {
            pNewNode->pBestParent = pCurrentNode;
            pNewNode->nBestDistanceFromStart = nNewPointDistance;
            pNewNode->nFScore = nNewPointDistance + pNewNode->nHeuristicDistanceToTarget;
            PATH_AStar_PropagateNewFScoreToChildren(pContext, pNewNode);
        }
        return TRUE;
    }

    pNewNode = sub_0067B1C0_AllocTableEntry(pContext);
    if (!pNewNode)
    {
        return FALSE;
    }

    pNewNode->pBestParent = pCurrentNode;
    pNewNode->nBestDistanceFromStart = nNewPointDistance;
    pNewNode->nHeuristicDistanceToTarget = PATH_AStar_Heuristic(tNewPointCoord, tTargetCoord);
    pNewNode->tPoint = tNewPointCoord;
    pNewNode->nFScore = pNewNode->nHeuristicDistanceToTarget + nNewPointDistance;
    PATH_AStar_MakeCandidate(pContext, pNewNode);
    PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
    return TRUE;
}

// 0x0067B440
static BOOL __stdcall PATH_AStar_ExploreChildren(D2PathFoWallContextStrc* pContext, D2PathPointStrc tTargetCoord, D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    D2PathPointStrc tNew;

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    return TRUE;
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

// 0x0067B740
static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo)
{
    if (!pPathInfo->pDynamicPath->pTargetUnit)
    {
        return 1;
    }
    D2ActiveRoomStrc* pStartRoom = pPathInfo->pStartRoom;
    const int nTargetX = pPathInfo->tTargetCoord.X;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nTargetY = pPathInfo->tTargetCoord.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
    ReturnOne:
        return 1;
    }

    return !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY + 2, nCollisionPattern, nCollisionMask);
}

static __forceinline D2PathFoWallNodeStrc* PATH_AStar_GetNewNode(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pNewNode = 0;
    if (pContext->nNodesCount != 200)
    {
        pNewNode = &pContext->aNodesStorage[pContext->nNodesCount++];
        memset(pNewNode, 0, sizeof(*pNewNode));
    }
    return pNewNode;
}

// 0x0067B850
int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo)
{
    if (!PATH_AStar_TargetLocationHasEnoughRoom(pPathInfo))
    {
        return 0;
    }

    int nResult = 0;
    D2PathFoWallContextStrc tContext;
    tContext.nNodesCount = 0;
    tContext.pSortedListByFScore = 0;
    tContext.nStackCount = 0;
    memset(tContext.aPendingCache, 0, sizeof(tContext.aPendingCache));
    memset(tContext.aVisitedCache, 0, sizeof(tContext.aVisitedCache));

    const D2PathPointStrc tStartCoord = pPathInfo->tStartCoord;
    const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
    D2PathFoWallNodeStrc* pStartNode = PATH_AStar_GetNewNode(&tContext);
    pStartNode->nBestDistanceFromStart = 0;
    const unsigned short nDistToTarget = PATH_AStar_HeuristicInline(tStartCoord, tTargetCoord);
    pStartNode->nHeuristicDistanceToTarget = nDistToTarget;
    pStartNode->nFScore = nDistToTarget;
    pStartNode->tPoint = tStartCoord;
    PATH_AStar_MakeCandidate(&tContext, pStartNode);

    D2PathFoWallNodeStrc* pBestNode = 0;
    for (D2PathFoWallNodeStrc* pCur = PATH_AStar_PopBestScoreForVisit(&tContext); pCur; pCur = PATH_AStar_PopBestScoreForVisit(&tContext))
    {
        if (!pBestNode
            || pCur->nHeuristicDistanceToTarget < pBestNode->nHeuristicDistanceToTarget
            || (pCur->nHeuristicDistanceToTarget == pBestNode->nHeuristicDistanceToTarget
                && pCur->nBestDistanceFromStart > pBestNode->nBestDistanceFromStart + 5))
        {
            pBestNode = pCur;
        }

        if (pCur->nHeuristicDistanceToTarget == 0 || !PATH_AStar_ExploreChildren(&tContext, tTargetCoord, pPathInfo, pCur))
        {
            break;
        }
    }

    if (pBestNode)
    {
        nResult = PATH_AStar_FlushNodeToDynamicPath(pPathInfo, pBestNode);
    }
    return nResult;
}

// 0x0067BBC0
int __stdcall sub_0067BBC0_DeltaTableLookup(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    return gaPathDeltaTable_006F1E28[3 * (tPoint2.Y - tPoint1.Y) + (tPoint2.X - tPoint1.X)];
}

// build: context PATH_TestNewTargetPoint
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

// build: context PATH_GetSquaredDistance
static __forceinline int PATH_GetSquaredDistance(D2PathPointStrc tPoint, D2PathPointStrc tTarget)
{
    const int nDX = tPoint.X - tTarget.X;
    const int nDY = tPoint.Y - tTarget.Y;
    return nDX * nDX + nDY * nDY;
}

// 0x0067BDF0
int __fastcall PATH_FindSubpathWithoutObstacles(D2PathInfoStrc* pInfo, D2PathPointStrc tSubPathStart, D2PathPointStrc* pPathPoints, int* pSubPathStartIdx, int* nMaxIndex, int nMaxLength, int nMajorDirection)
{
    D2PathMovStrc* pOtherPath;
    D2PathMovStrc* pCurPath;
    D2PathMovStrc tCache1 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection1, gnNextDirection1, 0, 0, 0 };
    D2PathMovStrc tCache2 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection2, gnNextDirection2, 0, 0, 0 };
    pOtherPath = &tCache2;
    pCurPath = &tCache1;

    const int nAdjacentCellIndex = sub_0067BBC0_DeltaTableLookup(tSubPathStart, pPathPoints[*pSubPathStartIdx]);
    tCache1.nDirectionIndex = nAdjacentCellIndex + 1;
    tCache2.nDirectionIndex = nAdjacentCellIndex + 7;

    tCache2.tCurrentCoord = tSubPathStart;
    tCache1.tCurrentCoord = tSubPathStart;

    do
    {
        if (!pCurPath->bPathFinished)
        {
            if (PATH_FindNonCollidingTargetPoint(pInfo, pCurPath))
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
                        nMajorDirectionDistance += *pSubPathStartIdx - 1;
                        if (nMajorDirectionDistance < *nMaxIndex && pCurPath->tTargetCoord.X == pPathPoints[nMajorDirectionDistance].X && pCurPath->tTargetCoord.Y == pPathPoints[nMajorDirectionDistance].Y)
                        {
                            D2_ASSERT(pCurPath->nPoints < nMaxLength, 443);
                            pCurPath->pPoints[pCurPath->nPoints] = pCurPath->tTargetCoord;
                            pCurPath->nPoints++;
                            pCurPath->pPoints[pCurPath->nPoints].X = 0;
                            PATH_ReplaceSubpathPoints(pPathPoints, pSubPathStartIdx, nMajorDirectionDistance, nMaxIndex, pCurPath);
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

                if (pCurPath->nPoints >= nMaxLength - *nMaxIndex - 1)
                    pCurPath->bPathFinished = 1;
            }
            else
            {
                pCurPath->bPathFinished = 1;
            }
        }

        D2PathMovStrc* pSwap = pOtherPath;
        if (!pCurPath->nLastSyncPointWithOtherPathIndex)
        {
            pOtherPath = pCurPath;
            pCurPath = pSwap;
        }
    }
    while (!(tCache1.bPathFinished || tCache2.bPathFinished));

    if (nMaxLength > 80)
    {
        pPathPoints[*pSubPathStartIdx].X = 0;
        *nMaxIndex = *pSubPathStartIdx;
        return 0;
    }

    const int nSquaredDist1 = PATH_GetSquaredDistance(tCache1.pPoints[tCache1.nPoints - 1], pInfo->tTargetCoord);
    const int nSquaredDist2 = PATH_GetSquaredDistance(tCache2.pPoints[tCache2.nPoints - 1], pInfo->tTargetCoord);
    const int nSquaredDistStartToTarget = PATH_GetSquaredDistance(pInfo->tStartCoord, pInfo->tTargetCoord);

    if (nSquaredDist2 <= nSquaredDist1)
    {
        if (nSquaredDistStartToTarget < nSquaredDist2)
            return 0;
        const int nStartIdx = *pSubPathStartIdx;
        if (tCache2.nPoints > 0)
        {
            for (int i = 0; i < tCache2.nPoints; ++i)
                pPathPoints[nStartIdx + i] = tCache2.pPoints[i];
        }
        *pSubPathStartIdx += tCache2.nPoints;
        *nMaxIndex = *pSubPathStartIdx;
        pPathPoints[*pSubPathStartIdx].X = 0;
        return pCurPath->nPoints;
    }
    else
    {
        if (nSquaredDistStartToTarget < nSquaredDist1)
            return 0;
        const int nStartIdx = *pSubPathStartIdx;
        if (tCache1.nPoints > 0)
        {
            for (int i = 0; i < tCache1.nPoints; ++i)
                pPathPoints[nStartIdx + i] = tCache1.pPoints[i];
        }
        *pSubPathStartIdx += tCache1.nPoints;
        *nMaxIndex = *pSubPathStartIdx;
        pPathPoints[*pSubPathStartIdx].X = 0;
        return pCurPath->nPoints;
    }
}
