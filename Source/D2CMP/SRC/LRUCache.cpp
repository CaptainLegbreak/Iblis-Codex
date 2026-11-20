#include "D2CMP.h"
#include "D2CmpCache.h"

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
        pNode->pData = 0;
        pNode->nSize = 0;
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
