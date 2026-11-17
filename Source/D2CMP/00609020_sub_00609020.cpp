struct D2LRUNodeStrc
{
    void* pValue;
    unsigned int nKey;
    unsigned int nCost;
    D2LRUNodeStrc* pNext;
    D2LRUNodeStrc* pPrev;
};

struct D2LRUCacheStrc
{
    void* pMemPool;
    unsigned int nCostLimit;
    unsigned int nCostInUse;
    unsigned int nNodesInUse;
    D2LRUNodeStrc* pNodes;
    unsigned int nNodes;
    D2LRUNodeStrc* pUsedFirst;
    D2LRUNodeStrc* pUsedLast;
    D2LRUNodeStrc* pFreeFirst;
    D2LRUNodeStrc* pFreeLast;
    void (__fastcall* pfnRelease)(D2LRUNodeStrc*);
    unsigned int nHits;
    unsigned int nMisses;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

// 0x00609020
void __fastcall sub_00609020(D2LRUCacheStrc* pCache, void* pMemPool, unsigned int nCostLimit, void (__fastcall* pfnRelease)(D2LRUNodeStrc*), unsigned int nNodes)
{
    pCache->pMemPool = pMemPool;
    pCache->nCostLimit = nCostLimit;
    pCache->nCostInUse = 0;
    pCache->pfnRelease = pfnRelease;
    pCache->nNodes = nNodes;

    unsigned int nSize = pCache->nNodes * sizeof(D2LRUNodeStrc);
    pCache->pNodes = (D2LRUNodeStrc*)FOG_AllocPool(pCache->pMemPool, nSize, ".\\SRC\\LRUCache.cpp", 48, 0);
    memset(pCache->pNodes, 0, nSize);

    for (unsigned int i = 0; i < pCache->nNodes; ++i)
    {
        D2LRUNodeStrc* pNode = &pCache->pNodes[i];
        if (i < pCache->nNodes - 1)
        {
            pNode->pNext = &pCache->pNodes[i + 1];
        }
        if (i > 0)
        {
            pNode->pPrev = &pCache->pNodes[i - 1];
        }
        pNode->pValue = 0;
        pNode->nKey = 0;
        pNode->nCost = 0;
    }

    pCache->nNodesInUse = 0;
    pCache->pUsedFirst = 0;
    pCache->pUsedLast = 0;
    pCache->nHits = 0;
    pCache->nMisses = 0;
    pCache->pFreeFirst = pCache->pNodes;
    pCache->pFreeLast = &pCache->pNodes[pCache->nNodes - 1];
}
