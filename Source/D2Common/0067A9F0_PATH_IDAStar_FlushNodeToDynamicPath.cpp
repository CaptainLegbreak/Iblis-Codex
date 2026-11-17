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
