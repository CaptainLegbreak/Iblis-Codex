struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x9C];
    D2PathPointStrc PathPoints[78];
};

struct D2PathInfoStrc
{
    char unk0x00[0x30];
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

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

static __declspec(noinline) int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode);

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
