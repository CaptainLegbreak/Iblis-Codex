#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SpriteCacheNodeStrc;
struct NodeLinks;
struct D2SpriteCacheLockStrc;
struct D2SpriteCacheStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection); // 0x006CC214

struct NodeLinks { D2SpriteCacheNodeStrc* pNext; D2SpriteCacheNodeStrc* pPrev; void Clear() { pNext = 0; pPrev = 0; } };

struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    unsigned int dwTick;
    union
    {
        struct
        {
            NodeLinks link;
        };
        struct
        {
            D2SpriteCacheNodeStrc* pNext;
            D2SpriteCacheNodeStrc* pPrev;
        };
    };
};

struct D2SpriteCacheStrc
{
    void* pMemPool;
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    unsigned int nCount;
    D2SpriteCacheNodeStrc* pNodes;
    D2SpriteCacheNodeStrc* pHeadA;
    D2SpriteCacheNodeStrc* pTailA;
    D2SpriteCacheNodeStrc* pHeadB;
    D2SpriteCacheNodeStrc* pTailB;
    D2SpriteCacheNodeStrc* f_24;
    D2SpriteCacheNodeStrc* f_28;
    D2SpriteCacheFreeFn pfnFree;
    D2SpriteCacheLockStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

static D2SpriteCacheNodeStrc* __stdcall sub_005FF0F0_SpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache); // 0x005FF0F0
static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode); // 0x005FF1B0
D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0

// 0x005FF0F0
static D2SpriteCacheNodeStrc* __stdcall sub_005FF0F0_SpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = 0;
    if (bLocked)
    {
        if (!pCache->pHeadB)
            return 0;
        pNode = pCache->pHeadB;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadB = pCache->pHeadB->link.pNext;
        if (pCache->pHeadB)
            pCache->pHeadB->link.pPrev = 0;
        else
            pCache->pTailB = 0;
    }
    else
    {
        if (!pCache->pHeadA)
            return 0;
        pNode = pCache->pHeadA;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadA = pCache->pHeadA->link.pNext;
        if (pCache->pHeadA)
            pCache->pHeadA->link.pPrev = 0;
        else
            pCache->pTailA = 0;
    }
    pNode->link.pNext = 0;
    pNode->link.pPrev = 0;
    return pNode;
}

// 0x005FF4A0
D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked)
{
    if (!pCache->nCount)
    {
        return 0;
    }
    if (!pNode)
    {
        if (!pCache->pHeadB)
        {
            pNode = sub_005FF0F0_SpriteCachePopHead(0, pCache);
        }
        else
        {
            if (!pCache->pHeadA)
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(bLocked, pCache);
            }
            else if (bLocked)
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(pCache->pHeadB->dwTick < pCache->pHeadA->dwTick, pCache);
            }
            else
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(0, pCache);
            }
        }
        if (!pNode)
        {
            return 0;
        }
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
    }
    else
    {
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
        sub_005FF1B0_SpriteCacheUnlinkNode(pCache, pNode);
    }
    EnterCriticalSection(&pCache->tLock);
    pCache->nTotalSize -= pNode->nSize;
    LeaveCriticalSection(&pCache->tLock);
    if (pNode->nKey)
    {
        pCache->pfnFree(pNode->nKey);
        pNode->nKey = 0;
    }
    if (pNode->pData)
    {
        FOG_FreePool(pCache->pMemPool, pNode->pData, gszSpriteCacheSourceFile, 0x9E8, 0);
        pNode->pData = 0;
    }
    if (!pCache->f_28)
    {
        pCache->nCount -= 1;
        pCache->f_24 = pNode;
        pCache->f_28 = pNode;
    }
    else
    {
        pCache->f_28->link.pNext = pNode;
        pNode->link.pPrev = pCache->f_28;
        pCache->nCount -= 1;
        pCache->f_28 = pNode;
    }
    return pNode;
}

// 0x005FF1B0
static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* ptBlock)
{
    D2_ASSERT(ptBlock, 0xAFC);
    if (ptBlock->dwFlags & 1)
    {
        if (!pCache->pHeadB)
        {
            return;
        }
        if (ptBlock == pCache->pHeadB)
        {
            sub_005FF0F0_SpriteCachePopHead(1, pCache);
            return;
        }
        if (ptBlock == pCache->pTailB)
        {
            pCache->pTailB = pCache->pTailB->pPrev;
            pCache->pTailB->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    else
    {
        if (!pCache->pHeadA)
        {
            return;
        }
        if (ptBlock == pCache->pHeadA)
        {
            sub_005FF0F0_SpriteCachePopHead(0, pCache);
            return;
        }
        if (ptBlock == pCache->pTailA)
        {
            pCache->pTailA = pCache->pTailA->pPrev;
            pCache->pTailA->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    ptBlock->pNext = 0;
    ptBlock->pPrev = 0;
}

// 0x005FF5B0
void __fastcall sub_005FF5B0_SpriteCacheTouchNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->nCount)
    {
        return;
    }
    pCache->f_4C += 1;
    EnterCriticalSection(&pCache->tLock);
    D2_ASSERT(pNode, 0xA10);
    sub_005FF1B0_SpriteCacheUnlinkNode(pCache, pNode);
    pNode->dwFlags &= ~1;
    if (!pCache->pTailA)
    {
        pCache->pHeadA = pNode;
    }
    else
    {
        pCache->pTailA->pNext = pNode;
        pNode->pPrev = pCache->pTailA;
    }
    pCache->pTailA = pNode;
    pNode->dwTick = GetTickCount();
    LeaveCriticalSection(&pCache->tLock);
}
