#include "D2CMP.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SpriteCacheNodeStrc;
struct D2SpriteCacheLockStrc;
struct D2SpriteCacheStrc;
struct D2CmpCelFileViewStrc;
struct D2CmpCelContextStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    unsigned int dwTick;
    D2SpriteCacheNodeStrc* pNext;
    D2SpriteCacheNodeStrc* pPrev;
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
    int nArg;
    D2SpriteCacheLockStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

struct D2CmpCelFileViewStrc
{
    int nVersion;
    char unk0x04[0x10];
    unsigned int nFrames;
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection); // 0x006CC214
D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0

static D2SpriteCacheNodeStrc* __stdcall sub_005FF3F0_SpriteCacheTakeNode(unsigned int nSize, int bLocked, D2SpriteCacheStrc* pCache);

// 0x005FEE90
void __fastcall sub_005FEE90_SpriteCacheInit(D2SpriteCacheStrc* pCache, void* pMemPool, unsigned int nMaxSize, int nArg)
{
    pCache->nMaxSize = nMaxSize;
    pCache->nArg = nArg;
    pCache->pMemPool = pMemPool;
    pCache->nTotalSize = 0;
    pCache->pNodes = (D2SpriteCacheNodeStrc*)sub_0040B430(pMemPool, sizeof(D2SpriteCacheNodeStrc) * 0x1400, ".\\SRC\\SpriteCache.cpp", 2273, 0);
    memset(pCache->pNodes, 0, sizeof(D2SpriteCacheNodeStrc) * 0x1400);

    for (int i = 0; i < 0x1400; ++i)
    {
        D2SpriteCacheNodeStrc* pNode = &pCache->pNodes[i];
        if (i < 0x1400 - 1)
        {
            pNode->pNext = &pCache->pNodes[i + 1];
        }

        if (i > 0)
        {
            pNode->pPrev = &pCache->pNodes[i - 1];
        }

        pNode->pData = 0;
        pNode->nSize = 0;
        pNode->nKey = 0;
    }

    pCache->f_24 = pCache->pNodes;
    pCache->nCount = 0;
    pCache->pHeadA = 0;
    pCache->pTailA = 0;
    pCache->pHeadB = 0;
    pCache->pTailB = 0;
    pCache->f_28 = &pCache->pNodes[0x1400 - 1];
    pCache->nHits = 0;
    pCache->f_4C = 0;
    InitializeCriticalSection(&pCache->tLock);
}

// 0x00601810
int __stdcall sub_00601810_IsGfxFrameValid(D2CmpCelContextStrc* pContext)
{
    D2CmpCelFileViewStrc* pCelFile = (D2CmpCelFileViewStrc*)pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->nVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    return pContext->nFrame <= pCelFile->nFrames;
}

// 0x005FF060
static void __stdcall sub_005FF060_SpriteCacheLinkNode(int bLocked, D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (bLocked)
    {
        if (!pCache->pTailB)
        {
            pCache->pHeadB = pNode;
            pCache->pTailB = pNode;
        }
        else
        {
            pCache->pTailB->pNext = pNode;
            pNode->pPrev = pCache->pTailB;
            pCache->pTailB = pNode;
        }
    }
    else
    {
        if (!pCache->pTailA)
        {
            pCache->pHeadA = pNode;
            pCache->pTailA = pNode;
        }
        else
        {
            pCache->pTailA->pNext = pNode;
            pNode->pPrev = pCache->pTailA;
            pCache->pTailA = pNode;
        }
    }
    pNode->dwTick = GetTickCount();
}

// 0x005FFC40
D2SpriteCacheNodeStrc* __fastcall sub_005FFC40_SpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked)
{
    D2_ASSERT(nSize < pCache->nMaxSize, 0x941);
    unsigned int dwOldest = 0;
    if (bLocked)
    {
        if (pCache->pHeadA)
        {
            dwOldest = pCache->pHeadA->dwTick;
        }
        if (pCache->pHeadB && dwOldest >= pCache->pHeadB->dwTick)
        {
            dwOldest = pCache->pHeadB->dwTick;
        }
    }
    D2SpriteCacheNodeStrc* pNode = sub_005FF3F0_SpriteCacheTakeNode(nSize, bLocked, pCache);
    while (!pNode)
    {
        if (bLocked && GetTickCount() - dwOldest < 15000)
        {
            return 0;
        }
        if (!sub_005FF4A0_SpriteCachePurge(pCache, 0, 1))
        {
            return 0;
        }
        pNode = sub_005FF3F0_SpriteCacheTakeNode(nSize, bLocked, pCache);
    }
    if (bLocked)
    {
        pNode->dwFlags |= 1;
    }
    else
    {
        pNode->dwFlags &= ~1;
    }
    pNode->pData = FOG_AllocPool(pCache->pMemPool, nSize, ".\\SRC\\SpriteCache.cpp", 0x96D, 0);
    pNode->nSize = nSize;
    pNode->nKey = nKey;
    pCache->nHits += 1;
    pCache->f_4C += 1;
    return pNode;
}

// 0x005FF3F0
static D2SpriteCacheNodeStrc* __stdcall sub_005FF3F0_SpriteCacheTakeNode(unsigned int nSize, int bLocked, D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = 0;
    EnterCriticalSection(&pCache->tLock);
    if (pCache->nCount != 0x1400 && pCache->nTotalSize + nSize <= pCache->nMaxSize)
    {
        pNode = pCache->f_24;
        if (!pNode)
        {
            pNode = 0;
        }
        else if (pNode->dwFlags & 2)
        {
            pNode = 0;
        }
        else
        {
            D2SpriteCacheNodeStrc* pNext = pNode->pNext;
            pCache->f_24 = pNext;
            if (pNext)
            {
                pNext->pPrev = 0;
            }
            else
            {
                pCache->f_28 = 0;
            }
            pNode->pNext = 0;
            pNode->pPrev = 0;
        }
        sub_005FF060_SpriteCacheLinkNode(bLocked, pCache, pNode);
        D2_ASSERT(pNode, 0x993);
        pCache->nCount += 1;
        pCache->nTotalSize += nSize;
    }
    LeaveCriticalSection(&pCache->tLock);
    return pNode;
}
