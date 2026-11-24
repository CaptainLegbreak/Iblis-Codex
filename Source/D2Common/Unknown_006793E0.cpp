#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2PathFind.h"
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2PathInfoStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2CollisionTestStrc;
union D2SeedStrc;
struct D2PathIDAStarNodeStrc;
struct D2DrlgCoordsStrc;
struct D2PathFoWallNodeStrc;
struct D2PathFoWallContextStrc;
struct D2PathMovStrc;






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
int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798
void __fastcall PATH_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067A390

static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo); // 0x006793E0


extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);


#pragma pack(push, 1)
struct D2PathFoWallContextStrc
{
    D2PathFoWallNodeStrc* aPendingCache[128];
    D2PathFoWallNodeStrc* aVisitedCache[128];
    D2PathFoWallNodeStrc* pSortedListByFScore;
};

#pragma pack(pop)

extern const int gaIdaStar_PointCacheHashMaskX[128]; // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[128]; // 0x006F1B98

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
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 52);

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
    PATH_GetScaledDirectionVector(pDynamicPath->dwVelocity, &tDirectionVector, tStartCoord, tTargetCoord);
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

int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord); // 0x00679A60

static inline int PATH_ScaleDelta(int nScale, int nDelta, int nMax)
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
    if ((pDynamicPath ? pDynamicPath->hTarget : 0))
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
        const int nTargetUnitY = UNITS_GetYPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
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

    int nMaxPathPoints = pDynamicPath->bDistMax >> 1;
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


