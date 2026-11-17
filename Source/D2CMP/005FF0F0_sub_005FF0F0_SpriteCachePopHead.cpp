extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszSpriteCacheSourceFile[];                                                           // 0x006E364C

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);             // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);             // 0x006CC214
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();                                     // 0x006CC260

typedef void (__fastcall* D2SpriteCacheFreeFn)(unsigned int nKey);

struct D2SpriteCacheNodeStrc;
struct NodeLinks { D2SpriteCacheNodeStrc* pNext; D2SpriteCacheNodeStrc* pPrev; void Clear() { pNext = 0; pPrev = 0; } };
struct D2SpriteCacheNodeStrc
{
    void* pData;
    unsigned int nSize;
    unsigned int nKey;
    unsigned int dwFlags;
    unsigned int dwTick;
    NodeLinks link;
};

struct D2SpriteCacheLockStrc
{
    char data[0x18];
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

// build: context sub_005FF1B0_SpriteCacheUnlinkNode
static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    D2_ASSERT(pNode, 0xAFC);
    if (pNode->dwFlags & 1)
    {
        if (!pCache->pHeadB)
        {
            return;
        }
        if (pNode == pCache->pHeadB)
        {
            sub_005FF0F0_SpriteCachePopHead(1, pCache);
            return;
        }
        if (pNode == pCache->pTailB)
        {
            pCache->pTailB = pCache->pTailB->link.pPrev;
            pCache->pTailB->link.pNext = 0;
            pNode->link.pNext = 0;
            pNode->link.pPrev = 0;
            return;
        }
    }
    else
    {
        if (!pCache->pHeadA)
        {
            return;
        }
        if (pNode == pCache->pHeadA)
        {
            sub_005FF0F0_SpriteCachePopHead(0, pCache);
            return;
        }
        if (pNode == pCache->pTailA)
        {
            pCache->pTailA = pCache->pTailA->link.pPrev;
            pCache->pTailA->link.pNext = 0;
            pNode->link.pNext = 0;
            pNode->link.pPrev = 0;
            return;
        }
    }
    if (pNode->link.pPrev || pNode->link.pNext)
    {
        pNode->link.pPrev->link.pNext = pNode->link.pNext;
        pNode->link.pNext->link.pPrev = pNode->link.pPrev;
        pNode->link.pNext = 0;
        pNode->link.pPrev = 0;
    }
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

static D2SpriteCacheNodeStrc* __stdcall sub_005FF0F0_SpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache); // 0x005FF0F0

static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode); // 0x005FF1B0

D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0
