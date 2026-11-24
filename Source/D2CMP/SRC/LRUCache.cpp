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

struct T006090E0
{
    void* pMemPool;
    unsigned int nMaxSize;
    unsigned int nCurrentSize;
    unsigned int nCount;
    D2LRUNodeStrc* pNodes;
    unsigned int nNodes;
    D2LRUNodeStrc* f_18;
    D2LRUNodeStrc* f_1C;
    D2LRUNodeStrc* f_20;
    D2LRUNodeStrc* f_24;
    void (__fastcall* pfnRelease)(D2LRUNodeStrc* pNode);
    unsigned int nAdds;
    unsigned int nUses;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char gszLRUCacheSourceFile[];                                                              // 0x006E5F1C

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define LRU_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static __inline void __fastcall LRUCacheAppendUsed(T006090E0* pCache, D2LRUNodeStrc* pNode);

static __inline void __fastcall LRUCacheAppendFree(T006090E0* pCache, D2LRUNodeStrc* pNode);

static D2LRUNodeStrc* __fastcall LRUCachePopUsed(T006090E0* pCache);

static __inline D2LRUNodeStrc* __fastcall LRUCACHE_UnlinkUsedHead(T006090E0* pCache);

static __inline D2LRUNodeStrc* __fastcall LRUCachePopFree(T006090E0* pCache);

static D2LRUNodeStrc* __fastcall LRUCacheUnlinkUsed(T006090E0* pCache, D2LRUNodeStrc* pNode);

static D2LRUNodeStrc* __fastcall LRUCacheTakeFreeNode(T006090E0* pCache, unsigned int nSize);

void __fastcall LRUCacheInit(T006090E0* pCache, void* pMemPool, unsigned int nMaxSize, void (__fastcall* pfnRelease)(D2LRUNodeStrc*), unsigned int nNodes);

// 0x00609020
void __fastcall LRUCacheInit(D2LRUCacheStrc* pCache, void* pMemPool, unsigned int nCostLimit, void (__fastcall* pfnRelease)(D2LRUNodeStrc*), unsigned int nNodes)
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

// 0x006090E0
static __inline void __fastcall LRUCacheAppendUsed(T006090E0* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->f_1C)
    {
        pCache->f_18 = pNode;
        pCache->f_1C = pNode;
        return;
    }

    pCache->f_1C->pNext = pNode;
    pNode->pPrev = pCache->f_1C;
    pCache->f_1C = pNode;
}

// 0x00609100
static __inline void __fastcall LRUCacheAppendFree(T006090E0* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->f_24)
    {
        pCache->f_20 = pNode;
        pCache->f_24 = pNode;
        return;
    }

    pCache->f_24->pNext = pNode;
    pNode->pPrev = pCache->f_24;
    pCache->f_24 = pNode;
}

// 0x00609120
static D2LRUNodeStrc* __fastcall LRUCachePopUsed(T006090E0* pCache)
{
    D2LRUNodeStrc* pNode = pCache->f_18;
    if (!pNode)
    {
        return 0;
    }

    pCache->f_18 = pNode->pNext;
    if (pCache->f_18)
    {
        pCache->f_18->pPrev = 0;
    }
    else
    {
        pCache->f_1C = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

static __inline D2LRUNodeStrc* __fastcall LRUCACHE_UnlinkUsedHead(T006090E0* pCache)
{
    D2LRUNodeStrc* pNode = pCache->f_18;
    if (!pNode)
    {
        return 0;
    }

    pCache->f_18 = pNode->pNext;
    if (pCache->f_18)
    {
        pCache->f_18->pPrev = 0;
    }
    else
    {
        pCache->f_1C = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x00609150
static __inline D2LRUNodeStrc* __fastcall LRUCachePopFree(T006090E0* pCache)
{
    D2LRUNodeStrc* pNode = pCache->f_20;
    if (!pNode)
    {
        return 0;
    }

    pCache->f_20 = pNode->pNext;
    if (pCache->f_20)
    {
        pCache->f_20->pPrev = 0;
    }
    else
    {
        pCache->f_24 = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x00609180
static D2LRUNodeStrc* __fastcall LRUCacheUnlinkUsed(T006090E0* pCache, D2LRUNodeStrc* pNode)
{
    if (pCache->f_18)
    {
        LRU_ASSERT(pNode, 370);

        if (pNode == pCache->f_18)
        {
            return LRUCachePopUsed(pCache);
        }

        if (pNode == pCache->f_1C)
        {
            pCache->f_1C = pCache->f_1C->pPrev;
            pCache->f_1C->pNext = 0;
        }
        else
        {
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
        }

        pNode->pNext = 0;
        pNode->pPrev = 0;
    }

    return pNode;
}

// 0x00609200
void __fastcall LRUCacheIterate(T006090E0* pCache, int (__fastcall* pfnCallback)(D2LRUNodeStrc*, void*), void* pUserData)
{
    LRU_ASSERT(pCache, 412);

    for (D2LRUNodeStrc* pNode = pCache->f_18; pNode; )
    {
        D2LRUNodeStrc* pNext = pNode->pNext;
        if (!pfnCallback(pNode, pUserData))
        {
            return;
        }

        pNode = pNext;
    }
}

// 0x00609250
static D2LRUNodeStrc* __fastcall LRUCacheTakeFreeNode(T006090E0* pCache, unsigned int nSize)
{
    if (pCache->nCount == pCache->nNodes)
    {
        return 0;
    }

    if (pCache->nCurrentSize + nSize > pCache->nMaxSize)
    {
        return 0;
    }

    D2LRUNodeStrc* pNode = LRUCachePopFree(pCache);
    LRUCacheAppendUsed(pCache, pNode);
    LRU_ASSERT(pNode, 159);

    ++pCache->nCount;
    pCache->nCurrentSize += nSize;
    return pNode;
}

// 0x006092D0
void __fastcall LRUCacheRelease(T006090E0* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->nCount)
    {
        return;
    }

    if (!pNode)
    {
        pNode = LRUCACHE_UnlinkUsedHead(pCache);
    }
    else
    {
        LRUCacheUnlinkUsed(pCache, pNode);
    }

    if (pNode)
    {
        pCache->nCurrentSize -= pNode->nSize;
        if (pNode->nCost)
        {
            pCache->pfnRelease(pNode);
        }

        if (pNode->pData)
        {
            FOG_FreeServerMemory(pCache->pMemPool, pNode->pData, gszLRUCacheSourceFile, 200, 0);
            pNode->pData = 0;
            pNode->nSize = 0;
            pNode->nCost = 0;
        }

        LRUCacheAppendFree(pCache, pNode);
    }

    --pCache->nCount;
}

// 0x006093E0
void __fastcall LRUCacheDestroy(T006090E0* pCache)
{
    while (pCache->nCount)
    {
        LRUCacheRelease(pCache, 0);
    }

    if (pCache->pNodes)
    {
        FOG_FreeServerMemory(pCache->pMemPool, pCache->pNodes, gszLRUCacheSourceFile, 99, 0);
        pCache->pNodes = 0;
    }
}

// 0x00609420
D2LRUNodeStrc* __fastcall LRUCacheAlloc(T006090E0* pCache, unsigned int nSize, int nFlags)
{
    LRU_ASSERT(nSize < pCache->nMaxSize, 118);

    ++pCache->nAdds;
    ++pCache->nUses;

    D2LRUNodeStrc* pNode = LRUCacheTakeFreeNode(pCache, nSize);
    while (!pNode)
    {
        LRUCacheRelease(pCache, 0);
        pNode = LRUCacheTakeFreeNode(pCache, nSize);
    }

    pNode->pData = sub_0040B430(pCache->pMemPool, nSize, gszLRUCacheSourceFile, 132, 0);
    LRU_ASSERT(pNode->pData, 133);
    pNode->nSize = nSize;
    pNode->nCost = nFlags;
    return pNode;
}

// 0x00609380
void __fastcall LRUCacheTouch(T006090E0* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->nCount)
    {
        return;
    }

    ++pCache->nUses;
    LRU_ASSERT(pNode, 233);

    LRUCacheUnlinkUsed(pCache, pNode);
    LRUCacheAppendUsed(pCache, pNode);
}
