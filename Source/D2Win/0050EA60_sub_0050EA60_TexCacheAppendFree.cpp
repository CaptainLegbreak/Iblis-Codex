struct D2GlideTexOwnerStrc
{
    int unk0x00;
    int unk0x04;
};

struct D2GlideTexCacheEntryStrc
{
    int nId;
    int unk0x04;
    D2GlideTexOwnerStrc* pOwner;
    int nOwnerIndex;
    int unk0x10;
    D2GlideTexCacheEntryStrc* pNext;
    D2GlideTexCacheEntryStrc* pPrev;
};

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

struct D2GlideTileStrc
{
    int unk0x00;
    short nCacheIndex;
    short unk0x06;
};

struct D2GlideTileCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2GlideTileStrc* pTile;
    D2GlideTileCacheEntryStrc* pNext;
    D2GlideTileCacheEntryStrc* pPrev;
};

struct D2GlideTileCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTileCacheEntryStrc* pHead;
    D2GlideTileCacheEntryStrc* pTail;
    D2GlideTileCacheEntryStrc* f_14;
    D2GlideTileCacheEntryStrc* f_18;
    D2GlideTileCacheEntryStrc* pEntries;
};

// 0x0050EA60
static void sub_0050EA60_TexCacheAppendFree(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
{
    if (!pCache->f_14)
    {
        pCache->f_14 = pEntry;
        pCache->f_18 = pEntry;
        return;
    }
    pCache->f_18->pNext = pEntry;
    pEntry->pPrev = pCache->f_18;
    pCache->f_18 = pEntry;
}

// 0x0050EA80
static D2GlideTexCacheEntryStrc* sub_0050EA80_TexCachePopUsed(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EAB0
static D2GlideTexCacheEntryStrc* sub_0050EAB0_TexCachePopFree(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->f_14;
    if (!pEntry)
        return 0;
    pCache->f_14 = pEntry->pNext;
    if (pCache->f_14)
        pCache->f_14->pPrev = 0;
    else
        pCache->f_18 = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EF60
static void sub_0050EF60_TileCacheAppendFree(D2GlideTileCacheEntryStrc* pEntry, D2GlideTileCacheStrc* pCache)
{
    if (!pCache->f_14)
    {
        pCache->f_14 = pEntry;
        pCache->f_18 = pEntry;
        return;
    }
    pCache->f_18->pNext = pEntry;
    pEntry->pPrev = pCache->f_18;
    pCache->f_18 = pEntry;
}

// 0x0050EFB0
static D2GlideTileCacheEntryStrc* sub_0050EFB0_TileCachePopFree(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->f_14;
    if (!pEntry)
        return 0;
    pCache->f_14 = pEntry->pNext;
    if (pCache->f_14)
        pCache->f_14->pPrev = 0;
    else
        pCache->f_18 = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

void __fastcall sub_M116_Emit_0050EA60(D2GlideTexCacheStrc* pTex, D2GlideTileCacheStrc* pTile)
{
    sub_0050EA60_TexCacheAppendFree(sub_0050EA80_TexCachePopUsed(pTex), pTex);
    sub_0050EA60_TexCacheAppendFree(sub_0050EAB0_TexCachePopFree(pTex), pTex);
    sub_0050EF60_TileCacheAppendFree(sub_0050EFB0_TileCachePopFree(pTile), pTile);
}
