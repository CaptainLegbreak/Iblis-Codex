typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2ActiveRoomStrc;
struct D2UnitStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x58];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x9C - 0x5C];
    D2PathPointStrc PathPoints[78];
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    char unk0x10[0x28 - 0x10];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern const int gaIdaStar_PointCacheHashMaskX[];                                                           // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[];                                                           // 0x006F1B98
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask);// 0x0064D910
int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2);                     // 0x0067ADC0
D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE00
D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE50
D2PathFoWallNodeStrc* __fastcall sub_0067B1C0_AllocTableEntry(D2PathFoWallContextStrc* pContext);         // 0x0067B1C0

static __forceinline int PATH_AStar_HeuristicInline(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
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
    if (!pPathInfo->pDynamicPath->pTargetUnit)
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
