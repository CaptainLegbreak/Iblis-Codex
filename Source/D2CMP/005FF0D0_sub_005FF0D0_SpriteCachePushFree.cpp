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
    int nArg;
    D2SpriteCacheLockStrc tLock;
    unsigned int nHits;
    unsigned int f_4C;
};

// 0x005FF0D0
static __forceinline void sub_005FF0D0_SpriteCachePushFree(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->f_28)
    {
        pCache->f_24 = pNode;
        pCache->f_28 = pNode;
    }
    else
    {
        pCache->f_28->pNext = pNode;
        pNode->pPrev = pCache->f_28;
        pCache->f_28 = pNode;
    }
}

// 0x005FF170
static __forceinline D2SpriteCacheNodeStrc* sub_005FF170_SpriteCachePopFree(D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = pCache->f_24;
    if (!pNode)
        return 0;
    if (pNode->dwFlags & 2)
        return 0;
    D2SpriteCacheNodeStrc* pNext = pNode->pNext;
    pCache->f_24 = pNext;
    if (pNext)
        pNext->pPrev = 0;
    else
        pCache->f_28 = 0;
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x005FF390
void __cdecl sub_005FF390_Nop()
{
}

D2SpriteCacheNodeStrc* __fastcall sub_M110_Emit_005FF0D0(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    sub_005FF0D0_SpriteCachePushFree(pCache, pNode);
    return sub_005FF170_SpriteCachePopFree(pCache);
}
