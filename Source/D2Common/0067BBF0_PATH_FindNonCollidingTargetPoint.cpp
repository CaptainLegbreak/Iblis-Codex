struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
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

struct D2DynamicPathStrc
{
    char unk0x00[0x30];
    D2UnitStrc* pUnit;
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    char unk0x0C[0x1C];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

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
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
extern const D2CoordStrc gnDirectionsToAdjacentCellOffsets[16];                                             // 0x006F1D98
extern const int gnCellOffsetsToDirections[9];                                                              // 0x006F1E18
extern const int gnNextDirection2[16];                                                                      // 0x006F1E40
extern const int gnPreviousDirection2[16];                                                                  // 0x006F1E80
extern const int gnNextDirection1[16];                                                                      // 0x006F1EC0
extern const int gnPreviousDirection1[16];                                                                  // 0x006F1F00

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
