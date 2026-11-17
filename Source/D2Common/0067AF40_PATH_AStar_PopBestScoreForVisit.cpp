#pragma pack(push, 1)
struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
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
};
#pragma pack(pop)

extern const int gaIdaStar_PointCacheHashMaskX[128]; // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[128]; // 0x006F1B98

static __declspec(noinline) D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext);

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
