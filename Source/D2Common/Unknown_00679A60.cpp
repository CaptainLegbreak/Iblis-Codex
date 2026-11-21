#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DrlgPresets.h"
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2CollisionTestStrc;
struct D2PathInfoStrc;
union D2FP32_16;
struct D2PathFoWallNodeStrc;
struct D2PathFoWallContextStrc;
struct D2PathMovStrc;







struct D2CollisionTestStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned int nCollisionPattern;
    unsigned int nCollisionMask;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall sub_00679380_PathTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo); // 0x00679B30
int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo); // 0x00679C80
int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo); // 0x0067B850

void __fastcall sub_6FDAB810(int* a1, int* a2); // 0x00678F00
void __fastcall sub_0067A390_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067A390

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
    int nUnk0x32EC;
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

static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 52);

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

static inline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
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

    D2_ASSERT(((pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 324);
    D2_ASSERT(pDynamicPath->eType != 4, 325);
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

int __fastcall PATH_Knockback_Server(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    const int nHalfDist = (pDynamicPath->nDist >> 1) + 1;
    D2PathPointStrc tFinalCoords;
    if (pDynamicPath->hTarget)
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline(pDynamicPath->hTarget);
        const int nTargetUnitY = UNITS_GetYPositionInline(pDynamicPath->hTarget);
        int nDeltaX = pPathInfo->tStartCoord.X - nTargetUnitX;
        int nDeltaY = pPathInfo->tStartCoord.Y - nTargetUnitY;
        if (const int nMax = PATH_MaxRef(nDeltaX < 0 ? -nDeltaX : nDeltaX, nDeltaY < 0 ? -nDeltaY : nDeltaY))
        {
            nDeltaX = (nDeltaX * nHalfDist) / nMax;
            nDeltaY = (nDeltaY * nHalfDist) / nMax;
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

// 0x00679E50
int __fastcall sub_6FDAB0B0(D2PathInfoStrc* pPathInfo)
{
    pPathInfo->pDynamicPath->dwCurrentPointIdx = 0;
    return PATH_Toward_6FDAA9F0(pPathInfo);
}

// 0x00679E60
int __fastcall PATH_BackupTurn_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->nDirOffset = -4;

    const int nResult = sub_6FDAA720(pPathInfo);
    if (!nResult)
    {
        return 0;
    }

    pDynamicPath->dwPathPoints = nResult;
    pDynamicPath->nDirOffset = -2;

    int nExtra = sub_6FDAA720(pPathInfo) - nResult;
    if (!nExtra)
    {
        pDynamicPath->nDirOffset = 2;
        nExtra = sub_6FDAA720(pPathInfo) - nResult;
    }

    pDynamicPath->nDirOffset = -4;
    return nResult + nExtra;
}

// 0x00679ED0
int __fastcall PATH_Straight_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->dwPathPoints = 0;

    int nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
    if (nPathPoints)
    {
        D2PathPointStrc tPathLastPoint = pDynamicPath->PathPoints[nPathPoints - 1];
        if (sub_00679380_PathTableHeuristic(tPathLastPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14
            && (tPathLastPoint.X != pPathInfo->tStartCoord.X || tPathLastPoint.Y != pPathInfo->tStartCoord.Y))
        {
            return nPathPoints;
        }
    }

    const int nMaxDist = 18;
    const int nMaxDistSquared = nMaxDist * nMaxDist;

    int nDX = pPathInfo->tStartCoord.X - pPathInfo->tTargetCoord.X;
    const int nDiffX = nDX < 0 ? -nDX : nDX;
    int nDY = pPathInfo->tStartCoord.Y - pPathInfo->tTargetCoord.Y;
    const int nDiffY = nDY < 0 ? -nDY : nDY;
    const int nSquaredDistance = nDiffX * nDiffX + nDiffY * nDiffY;

    if (nSquaredDistance <= nMaxDistSquared)
    {
        if (int nAStarPathPoints = PATH_AStar_ComputePath(pPathInfo))
        {
            return nAStarPathPoints;
        }
        else if (nPathPoints)
        {
            nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
        }
    }
    return nPathPoints;
}

// 0x0067A140
int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed)
{
    D2FP32_16 tCenter = pPath->tGameCoords;
    D2FP32_16 tPrevious = tCenter;
    int nAngle = 0;
    int nRadius = 0;
    int nPoints = 0;

    do
    {
        nRadius += 0x2580;
        nAngle += 16;
        float fRadius = (float)nRadius;
        unsigned int nX = (unsigned int)(sub_0040B330_Cos(nAngle) * fRadius) + tCenter.dwPrecisionX;
        unsigned int nY = (unsigned int)(sub_0040B350_Sin(nAngle) * fRadius) + tCenter.dwPrecisionY;
        if ((unsigned short)(nX >> 16) != (unsigned short)(tPrevious.dwPrecisionX >> 16) || (nY >> 16) != (unsigned short)(tPrevious.dwPrecisionY >> 16))
        {
            tPrevious.dwPrecisionX = nX;
            tPrevious.dwPrecisionY = nY;
            pPath->PathPoints[nPoints].X = (unsigned short)(nX >> 16);
            pPath->PathPoints[nPoints].Y = (unsigned short)(nY >> 16);
            ++nPoints;
        }
    }
    while (nPoints < 77);

    pPath->dwPathPoints = nPoints;
    return nPoints;
}

static int __stdcall sub_00679530_TraceLineFP16(D2DynamicPathStrc* pDynamicPath, D2CoordStrc* pDirectionVector, D2PathPointStrc tStartCoord, D2PathPointStrc* pDestination)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    const int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    const int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    D2PathPointStrc tPrevPoint = tStartCoord;
    int nX = (tStartCoord.X << 16) + 0x8000;
    int nY = (tStartCoord.Y << 16) + 0x8000;
    D2PathPointStrc tTargetPoint = *pDestination;
    const int nDeltaX = tTargetPoint.X - (unsigned short)(nX >> 16);
    const int nDeltaY = tTargetPoint.Y - (unsigned short)(nY >> 16);
    int nVelocityX = pDirectionVector->nX;
    int nVelocityY = pDirectionVector->nY;
    D2_ASSERT(D2_ABS(nVelocityX) > 0 || D2_ABS(nVelocityY) > 0, 110);
    sub_6FDAB810(&nVelocityX, &nVelocityY);
    if (D2_ABS(nDeltaX) > D2_ABS(nDeltaY))
    {
        while (tStartCoord.X != tTargetPoint.X)
        {
            nX += nVelocityX;
            nY += nVelocityY;
            tStartCoord.X = (unsigned short)(nX >> 16);
            tStartCoord.Y = (unsigned short)(nY >> 16);
            if (tPrevPoint.X != tStartCoord.X || tPrevPoint.Y != tStartCoord.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tStartCoord.X, tStartCoord.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            tPrevPoint = tStartCoord;
        }
    }
    else
    {
        while (tStartCoord.Y != tTargetPoint.Y)
        {
            nX += nVelocityX;
            nY += nVelocityY;
            tStartCoord.X = (unsigned short)(nX >> 16);
            tStartCoord.Y = (unsigned short)(nY >> 16);
            if (tPrevPoint.X != tStartCoord.X || tPrevPoint.Y != tStartCoord.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tStartCoord.X, tStartCoord.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            tPrevPoint = tStartCoord;
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

// 0x0067A5D0
static const int* __stdcall sub_0067A5D0_GetNeighborsSequence(int nBase, int nDirection)
{
    return dword_6FDD1BE0[(nDirection - nBase) & 7];
}

const int* __stdcall sub_M125_Emit_0067A5D0(int nUnused1, int nUnused2, int nBase, int nDirection)
{
    return sub_0067A5D0_GetNeighborsSequence(nBase, nDirection);
}

#include "gen/data/Source/D2Common/Unknown_00679A60.inc"
struct D2DynamicPathStrc;

static inline int PATH_AStar_HeuristicInline(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
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

// build: context PATH_AStar_RemoveFromPendingCache
static inline D2PathFoWallNodeStrc* PATH_AStar_RemoveFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pToRemove)
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

static D2PathFoWallNodeStrc* PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pPopped = pContext->pSortedListByFScore;
    if (!pPopped)
    {
        return 0;
    }

    pContext->pSortedListByFScore = pPopped->pNextSortedByFScore;
    PATH_AStar_RemoveFromPendingCache(pContext, pPopped);
    PATH_AStar_PushToVisitedCache(pContext, pPopped);
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
static BOOL __stdcall PATH_AStar_ExploreChildren(D2PathFoWallContextStrc* pContext, D2PathPointStrc tTargetCoord, D2PathFoWallNodeStrc* pNode, D2PathInfoStrc* pPathInfo)
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

static int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    D2PathPointStrc* pDest = pPathInfo->pDynamicPath->PathPoints;
    int nbPoints = 0;
    int nPrevDeltaX = -2;
    int nPrevDeltaY = -2;
    D2PathPointStrc tempPathPoints[78];
    while (pNode && nbPoints < 78)
    {
        D2PathFoWallNodeStrc* pNext = pNode->pBestParent;
        if (pNext)
        {
            const int nDeltaX = pNode->tPoint.X - pNext->tPoint.X;
            const int nDeltaY = pNode->tPoint.Y - pNext->tPoint.Y;
            if (nDeltaX != nPrevDeltaX || nDeltaY != nPrevDeltaY)
            {
                tempPathPoints[77 - nbPoints] = pNode->tPoint;
                ++nbPoints;
                nPrevDeltaX = nDeltaX;
                nPrevDeltaY = nDeltaY;
            }
        }
        pNode = pNext;
    }

    if (nbPoints < 1 || nbPoints >= 78)
    {
        return 0;
    }

    memcpy(pDest, &tempPathPoints[78 - nbPoints], sizeof(D2PathPointStrc) * nbPoints);
    return nbPoints;
}

static BOOL PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo)
{
    if (!pPathInfo->pDynamicPath->hTarget)
    {
        return TRUE;
    }

    const int nTargetX = pPathInfo->tTargetCoord.X;
    D2ActiveRoomStrc* pStartRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nTargetY = pPathInfo->tTargetCoord.Y;
    return !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY - 2, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 2, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY - 2, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 2, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX, nTargetY - 2, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY, nCollisionPattern, nCollisionMask)
        || !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX, nTargetY + 2, nCollisionPattern, nCollisionMask);
}

int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo)
{
    if (!PATH_AStar_TargetLocationHasEnoughRoom(pPathInfo))
    {
        return 0;
    }

    D2PathFoWallContextStrc tContext;
    D2PathFoWallNodeStrc* pStartNode = 0;
    tContext.nUnk0x32EC = 0;
    tContext.nNodesCount = 0;
    tContext.pSortedListByFScore = 0;
    tContext.nStackCount = 0;
    memset(tContext.aPendingCache, 0, sizeof(tContext.aPendingCache));
    memset(tContext.aVisitedCache, 0, sizeof(tContext.aVisitedCache));

    const D2PathPointStrc tStartCoord = pPathInfo->tStartCoord;
    const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
    if (tContext.nNodesCount != 200)
    {
        pStartNode = &tContext.aNodesStorage[tContext.nNodesCount++];
        memset(pStartNode, 0, sizeof(D2PathFoWallNodeStrc));
    }
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

        if (pCur->nHeuristicDistanceToTarget == 0 || !PATH_AStar_ExploreChildren(&tContext, tTargetCoord, pCur, pPathInfo))
        {
            break;
        }
    }

    if (pBestNode)
    {
        return PATH_AStar_FlushNodeToDynamicPath(pPathInfo, pBestNode);
    }
    return tContext.nUnk0x32EC;
}

// 0x0067BD70
static inline void sub_0067BD70_SwapPoints(D2PathPointStrc* pA, D2PathPointStrc* pB)
{
    const D2PathPointStrc tPoint = *pA;
    *pA = *pB;
    *pB = tPoint;
}

void __fastcall sub_M110_Emit_0067BD70(D2PathPointStrc* pPoints, int nCount)
{
    sub_0067BD70_SwapPoints(pPoints, pPoints + nCount);
}

static inline int PATH_TestNewTargetPoint(D2PathMovStrc* pMov, D2ActiveRoomStrc* pRoom, int nCollisionPattern, int nCollisionMask)
{
    pMov->tTargetCoord.X = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nX + pMov->tCurrentCoord.X);
    pMov->tTargetCoord.Y = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nY + pMov->tCurrentCoord.Y);
    return COLLISION_CheckAnyCollisionWithPattern(pRoom, pMov->tTargetCoord.X, pMov->tTargetCoord.Y, nCollisionPattern, nCollisionMask);
}

static int PATH_FindNonCollidingTargetPoint(D2PathInfoStrc* pInfo, D2PathMovStrc* pMov)
{
    const int nCollisionMask = pInfo->nCollisionMask;
    const int nCollisionPattern = pInfo->nCollisionPattern;
    D2ActiveRoomStrc* pRoom = pInfo->pStartRoom;
    D2_ASSERT((pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER), 290);

    pMov->bReachedDeadEnd = 0;
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    pMov->bReachedDeadEnd = 1;
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
