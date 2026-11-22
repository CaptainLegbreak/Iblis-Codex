#include "D2Common.h"
#include "D2Path.h"




struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;

    int PATH_IdaStar_ComputePathWithRooms(struct D2PathInfoStrc* pPathInfo);
};



struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    void* pStartRoom;
    char unk0x0C[0x08];
    unsigned char field_14;
    char unk0x15[0x07];
    unsigned char nMinimumFScoreToEvaluate;
    char unk0x1D[0x03];
    int nPathType;
    char unk0x24[0x04];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

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

struct D2PathIDAStarContextStrc
{
    D2PathIDAStarNodeStrc* pCurrentNode;
    D2PathIDAStarNodeStrc aNodesStorage[900];
    int nNodesCount;
    D2PathPointStrc nCoord[3];
    int nStride;
    int nXOffset;
    int nYOffset;
    int aCoordData[50000];
    int bRandomDirection;
    D2SeedStrc* pSeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
int __stdcall COLLISION_CheckAnyCollisionWithPattern(void* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064D910
int __stdcall sub_6FDAB770(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2);                              // 0x00678D10
extern const D2CoordStrc aCoordOffsets[8];                                                                  // 0x006F1958

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline int PATH_AStar_Heuristic_Inline(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
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
    if (nDiffX < nDiffY)
    {
        return nDiffX + 2 * nDiffY;
    }
    return nDiffY + 2 * nDiffX;
}

static void PATH_IDAStar_GetNextNeighborIndex(D2PathIDAStarNodeStrc* pNode, D2PathIDAStarContextStrc* pContext)
{
    if (pContext->bRandomDirection)
    {
        const unsigned int nRand = SEED_RollRandomNumber_Inline(pContext->pSeed);
// build: symbol ?gnIdaStarNeighborRandOffsets@* 0x006F18D8
        pNode->nNextNeighborIndex = (gnIdaStarNeighborRandOffsets[nRand & 0x1F] + *pNode->pNeighborsSequence + pNode->nNextNeighborIndex) & 7;
    }
    else
    {
        pNode->nNextNeighborIndex = (*pNode->pNeighborsSequence + pNode->nNextNeighborIndex) & 7;
    }
}

static D2PathIDAStarNodeStrc* __stdcall sub_6FDC0840(D2PathIDAStarContextStrc* pContext, D2PathIDAStarNodeStrc* pNode)
{
    if (pNode->nEvaluationsCount < 4)
    {
        pNode->pNeighborsSequence++;
        PATH_IDAStar_GetNextNeighborIndex(pNode, pContext);
    }

    pNode->nEvaluationsCount++;
    while (pNode->nEvaluationsCount == 5)
    {
        if (pNode == pContext->pCurrentNode)
        {
            return 0;
        }
        pNode = pNode->pParent;
        pNode->pNeighborsSequence++;
        PATH_IDAStar_GetNextNeighborIndex(pNode, pContext);
        pNode->nEvaluationsCount++;
    }

    return pNode;
}

static inline D2PathIDAStarNodeStrc* PATH_IDAStar_GetNewNode_Inline(D2PathIDAStarContextStrc* pContext)
{
    if (pContext->nNodesCount == 900)
    {
        return 0;
    }
    D2PathIDAStarNodeStrc* pNewNode = &pContext->aNodesStorage[pContext->nNodesCount++];
    memset(pNewNode, 0, sizeof(*pNewNode));
    return pNewNode;
}

static inline int PATH_IDAStar_IsOutOfBounds_Inline(const D2PathIDAStarContextStrc* pContext, D2PathPointStrc tCoord)
{
    return tCoord.X < pContext->nCoord[0].X || tCoord.X > pContext->nCoord[1].X || tCoord.Y < pContext->nCoord[0].Y || tCoord.Y > pContext->nCoord[1].Y;
}

static D2PathIDAStarNodeStrc* __stdcall PATH_IDAStar_VisitNodes(int nFScoreCutoff, D2PathInfoStrc* pPathInfo, D2PathIDAStarContextStrc* pContext); // 0x0067A740

// build: context PATH_IDAStar_VisitNodes
static D2PathIDAStarNodeStrc* __stdcall PATH_IDAStar_VisitNodes(int nFScoreCutoff, D2PathInfoStrc* pPathInfo, D2PathIDAStarContextStrc* pContext)
{
    const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
    D2PathIDAStarNodeStrc* pCurrentNode = pContext->pCurrentNode;
    int nIterations = 0;
    while (pCurrentNode->tCoord.X != tTargetCoord.X || pCurrentNode->tCoord.Y != tTargetCoord.Y)
    {
        if (++nIterations > 10000)
        {
            return 0;
        }

        if (PATH_IDAStar_IsOutOfBounds_Inline(pContext, pCurrentNode->tCoord))
        {
            break;
        }

        D2PathPointStrc tNeighborCoords;
        tNeighborCoords.X = pCurrentNode->tCoord.X + aCoordOffsets[pCurrentNode->nNextNeighborIndex].nX;
        tNeighborCoords.Y = pCurrentNode->tCoord.Y + aCoordOffsets[pCurrentNode->nNextNeighborIndex].nY;

        int* pNeighborBestDistanceToStart = &pContext->aCoordData[tNeighborCoords.X + pContext->nXOffset + pContext->nStride * (tNeighborCoords.Y + pContext->nYOffset)];
        if (*pNeighborBestDistanceToStart == 0
         && COLLISION_CheckAnyCollisionWithPattern(pPathInfo->pStartRoom, tNeighborCoords.X, tNeighborCoords.Y, pPathInfo->nCollisionPattern, pPathInfo->nCollisionMask))
        {
            *pNeighborBestDistanceToStart = 1;
        }
        else
        {
            const short nDistanceBetweenPoints = (pCurrentNode->tCoord.X == tNeighborCoords.X || pCurrentNode->tCoord.Y == tNeighborCoords.Y) ? 2 : 3;
            const short nNewDistanceFromStart = nDistanceBetweenPoints + pCurrentNode->nBestDistanceFromStart;
            if (*pNeighborBestDistanceToStart == 0 || (unsigned int)*pNeighborBestDistanceToStart >= (unsigned int)nNewDistanceFromStart)
            {
                *pNeighborBestDistanceToStart = nNewDistanceFromStart;

                const short nHeuristicDistanceToTarget = PATH_AStar_Heuristic_Inline(tTargetCoord, tNeighborCoords);
                const short nNewNodeFScore = nHeuristicDistanceToTarget + nNewDistanceFromStart;
                if (nNewNodeFScore <= nFScoreCutoff)
                {
                    if (!pCurrentNode->pBestChild)
                    {
                        D2PathIDAStarNodeStrc* pNewNode = PATH_IDAStar_GetNewNode_Inline(pContext);
                        pCurrentNode->pBestChild = pNewNode;
                        if (!pNewNode)
                        {
                            return 0;
                        }
                        pNewNode->pParent = pCurrentNode;
                    }
                    pCurrentNode = pCurrentNode->pBestChild;
                    pCurrentNode->nHeuristicDistanceToTarget = nHeuristicDistanceToTarget;
                    pCurrentNode->nBestDistanceFromStart = nNewDistanceFromStart;
                    pCurrentNode->nFScore = nNewNodeFScore;
                    pCurrentNode->nEvaluationsCount = 0;
// build: symbol ?gnIdaStarNeighborSequences@* 0x006F17D8
                    pCurrentNode->pNeighborsSequence = gnIdaStarNeighborSequences[(sub_6FDAB770(tNeighborCoords, tTargetCoord) - pCurrentNode->pParent->nNextNeighborIndex) & 7];
                    if (pContext->bRandomDirection)
                    {
                        const unsigned int nRand = SEED_RollRandomNumber_Inline(pContext->pSeed);
                        pCurrentNode->nNextNeighborIndex = (gnIdaStarNeighborRandOffsets[nRand & 0x1F] + pCurrentNode->pParent->nNextNeighborIndex + *pCurrentNode->pNeighborsSequence) & 7;
                    }
                    else
                    {
                        pCurrentNode->nNextNeighborIndex = (pCurrentNode->pParent->nNextNeighborIndex + *pCurrentNode->pNeighborsSequence) & 7;
                    }
                    pCurrentNode->tCoord = tNeighborCoords;

                    if ((short)pCurrentNode->nHeuristicDistanceToTarget < pPathInfo->field_14)
                    {
                        return pCurrentNode;
                    }
                    continue;
                }
            }
        }

        pCurrentNode = sub_6FDC0840(pContext, pCurrentNode);
        if (!pCurrentNode)
        {
            return 0;
        }
    }
    return pCurrentNode;
}

static int PATH_IDAStar_FlushNodeToDynamicPath(D2PathIDAStarNodeStrc* pNode, D2PathInfoStrc* pPathInfo); // 0x0067A9F0

// build: context PATH_IDAStar_FlushNodeToDynamicPath
static int PATH_IDAStar_FlushNodeToDynamicPath(D2PathIDAStarNodeStrc* pNode, D2PathInfoStrc* pPathInfo)
{
    D2PathPointStrc* pPathPoints = pPathInfo->pDynamicPath->PathPoints;
    int nbPoints = 0;
    int nPrevDeltaX = -2;
    int nPrevDeltaY = -2;
    if (pNode)
    {
        D2PathPointStrc aTempPathPoints[78];
        D2PathPointStrc* pOut = &aTempPathPoints[77];
        do
        {
            if (nbPoints >= 78)
            {
                break;
            }
            D2PathIDAStarNodeStrc* pParent = pNode->pParent;
            if (pParent)
            {
                const int nDeltaX = pNode->tCoord.X - pNode->pParent->tCoord.X;
                const int nDeltaY = pNode->tCoord.Y - pNode->pParent->tCoord.Y;
                if (nDeltaX != nPrevDeltaX || nDeltaY != nPrevDeltaY)
                {
                    *pOut = pNode->tCoord;
                    ++nbPoints;
                    --pOut;
                    nPrevDeltaX = nDeltaX;
                    nPrevDeltaY = nDeltaY;
                }
            }
            pNode = pParent;
        }
        while (pNode);

        if (nbPoints > 1 && nbPoints < 78)
        {
            memcpy(pPathPoints, &aTempPathPoints[78 - nbPoints], sizeof(D2PathPointStrc) * nbPoints);
            return nbPoints;
        }
    }
    return 0;
}

// 0x0067AAA0
int D2DrlgCoordsStrc::PATH_IdaStar_ComputePathWithRooms(D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(nSubtileWidth * nSubtileHeight <= 50000, 369);
    D2PathIDAStarContextStrc tContext;
    memset(tContext.aCoordData, 0, sizeof(int) * ((nSubtileWidth + 6) * (nSubtileHeight + 6)));
    tContext.nCoord[0].X = nSubtileX;
    tContext.nCoord[0].Y = nSubtileY;
    tContext.nCoord[2].X = nSubtileWidth;
    tContext.nCoord[2].Y = nSubtileHeight;
    tContext.nCoord[1].X = tContext.nCoord[0].X + tContext.nCoord[2].X;
    tContext.nCoord[1].Y = tContext.nCoord[0].Y + tContext.nCoord[2].Y;
    tContext.nStride = tContext.nCoord[2].X + 6;
    tContext.nXOffset = 3 - tContext.nCoord[0].X;
    tContext.nYOffset = 3 - tContext.nCoord[0].Y;
    tContext.bRandomDirection = 0;
    if (pPathInfo->nPathType == 16)
    {
        tContext.bRandomDirection = 1;
        tContext.pSeed = &pPathInfo->pDynamicPath->pUnit->pSeed;
    }

    const D2PathPointStrc tStartCoord = pPathInfo->tStartCoord;
    const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
    D2PathIDAStarNodeStrc tStartNode;
    tStartNode.nBestDistanceFromStart = 0;
    int nDiffX = -(tStartCoord.X - tTargetCoord.X);
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }
    int nDiffY = tTargetCoord.Y - tStartCoord.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }
    tStartNode.nHeuristicDistanceToTarget = D2_MIN(nDiffX, nDiffY) + 2 * D2_MAX(nDiffX, nDiffY);
    tStartNode.nFScore = tStartNode.nHeuristicDistanceToTarget;
    tStartNode.tCoord = tStartCoord;
    tStartNode.nEvaluationsCount = -3;
    tStartNode.nNextNeighborIndex = sub_6FDAB770(tStartCoord, tTargetCoord) & 7;
    tStartNode.pBestChild = 0;
    tStartNode.pParent = 0;
    memset(&tContext.aNodesStorage[0], 0, sizeof(tContext.aNodesStorage[0]));
    tContext.pCurrentNode = &tContext.aNodesStorage[0];
    tStartNode.pNeighborsSequence = gnIdaStarNeighborSequences[0];
    tContext.nNodesCount = 1;

    int nFScoreCutoff = (short)tStartNode.nHeuristicDistanceToTarget;
    int nMaxFScore = nFScoreCutoff;
    switch (pPathInfo->nPathType)
    {
    case 0:
        nMaxFScore = (short)D2_MAX(nFScoreCutoff, (int)pPathInfo->nMinimumFScoreToEvaluate);
        break;
    case 16:
        nFScoreCutoff = (short)(nFScoreCutoff / 2 + tStartNode.nHeuristicDistanceToTarget);
        nMaxFScore = (short)D2_MAX(nFScoreCutoff, (int)pPathInfo->nMinimumFScoreToEvaluate);
        break;
    }

    D2PathIDAStarNodeStrc* pValidPathNode;
    do
    {
        *tContext.pCurrentNode = tStartNode;
        pValidPathNode = PATH_IDAStar_VisitNodes(nFScoreCutoff, pPathInfo, &tContext);
        nFScoreCutoff += 5;
        if (!pValidPathNode && tContext.nNodesCount == 900)
        {
            break;
        }
        tContext.nNodesCount = 1;
        if (pValidPathNode)
        {
            break;
        }
    }
    while (nFScoreCutoff < nMaxFScore);

    int nPathPoints = 0;
    if (pValidPathNode)
    {
        nPathPoints = PATH_IDAStar_FlushNodeToDynamicPath(pValidPathNode, pPathInfo);
        if (nPathPoints >= 78)
        {
            nPathPoints = 0;
        }
    }
    return nPathPoints;
}
