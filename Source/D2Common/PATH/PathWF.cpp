#include "D2Common.h"
#include "D2Structs.h"
#include "D2DrlgPresets.h"
#include "D2Path.h"






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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
extern const D2CoordStrc gnDirectionsToAdjacentCellOffsets[16];                                             // 0x006F1D98

static inline int PATH_TestNewTargetPoint(D2PathMovStrc* pMov, D2ActiveRoomStrc* pRoom, int nCollisionPattern, int nCollisionMask)
{
    pMov->tTargetCoord.X = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nX + pMov->tCurrentCoord.X);
    pMov->tTargetCoord.Y = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nY + pMov->tCurrentCoord.Y);
    return COLLISION_CheckAnyCollisionWithPattern(pRoom, pMov->tTargetCoord.X, pMov->tTargetCoord.Y, nCollisionPattern, nCollisionMask);
}

int PATH_FindNonCollidingTargetPoint(D2PathInfoStrc* pInfo, D2PathMovStrc* pMov); // 0x0067BBF0
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

static inline int PATH_GetSquaredDistance(D2PathPointStrc tPoint, D2PathPointStrc tTarget)
{
    const int nDX = tPoint.X - tTarget.X;
    const int nDY = tPoint.Y - tTarget.Y;
    return nDX * nDX + nDY * nDY;
}

// 0x0067BBC0
int __stdcall PATH_GetAdjacentPointDirection(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
// build: symbol ?gaPathDeltaTable@* 0x006F1E28
    return gaPathDeltaTable[3 * (tPoint2.Y - tPoint1.Y) + (tPoint2.X - tPoint1.X)];
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

    const int nAdjacentCellIndex = PATH_GetAdjacentPointDirection(tSubPathStart, pPathPoints[*pSubPathStartIdx]);
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

int __fastcall PATH_SimplifyToLines(D2PathPointStrc tStartCoord, D2PathPointStrc* pOutPathPoints, D2PathPointStrc* pInputPoints, int nbTempPoints); // 0x0067C1E0

static int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints);

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

// 0x0067C2D0
int __fastcall PATH_ComputePathOrSlideAlongObstacles(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* ptPathInfo = pPathInfo->pDynamicPath;
    D2_ASSERT(((ptPathInfo->pUnit && ptPathInfo->pUnit->dwUnitType == UNIT_PLAYER) || (ptPathInfo->pUnit && ptPathInfo->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 0x2AD);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const unsigned char nDist = ptPathInfo->bDistMax;
    int i = 0;
    const D2PathPointStrc tStart = pPathInfo->tStartCoord;
    const D2PathPointStrc tTarget = pPathInfo->tTargetCoord;
    D2PathPointStrc tPrevious = tStart;
    int nDistMax = nDist;
    if (ptPathInfo->hTarget && nDist < 40)
    {
        nDistMax = 40;
    }

    D2PathPointStrc aPathPoints[78];
    int nMajorDirection;
    int nPoints = PATH_BresenhamLine(tStart, tTarget, nDistMax, &nMajorDirection, aPathPoints);
    if (nPoints <= 2)
    {
        return 0;
    }

    for (; i < nPoints; ++i)
    {
        const D2PathPointStrc* pPoint = &aPathPoints[i];
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, pPoint->X, pPoint->Y, nCollisionPattern, nCollisionMask))
        {
            if (!PATH_FindSubpathWithoutObstacles(pPathInfo, tPrevious, aPathPoints, &i, &nPoints, nDistMax - i, nMajorDirection))
            {
                return PATH_SimplifyToLines(tStart, ptPathInfo->PathPoints, aPathPoints, i);
            }
        }

        tPrevious = aPathPoints[i];
    }

    if (!nPoints)
    {
        return 0;
    }

    return PATH_SimplifyToLines(tStart, ptPathInfo->PathPoints, aPathPoints, nPoints);
}
