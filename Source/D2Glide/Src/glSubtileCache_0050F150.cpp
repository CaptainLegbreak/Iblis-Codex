#include "D2Glide.h"

static D2GlideTileCacheEntryStrc* sub_M117_TilePopHead(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
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

// 0x0050F150
static void sub_0050F150_TileCacheEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_M117_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F4F0
static void sub_0050F4F0_FloorCacheAppendFree(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    if (!pCache->pFreeHead)
    {
        pCache->pFreeHead = pEntry;
        pCache->pFreeTail = pEntry;
        return;
    }

    pCache->pFreeTail->pNext = pEntry;
    pEntry->pPrev = pCache->pFreeTail;
    pCache->pFreeTail = pEntry;
}

// 0x0050F540
static D2GlideFloorCacheEntryStrc* sub_0050F540_FloorCachePopFree(D2GlideFloorCacheStrc* pCache)
{
    D2GlideFloorCacheEntryStrc* pEntry = pCache->pFreeHead;
    if (!pEntry)
        return 0;
    pCache->pFreeHead = pEntry->pNext;
    if (pCache->pFreeHead)
        pCache->pFreeHead->pPrev = 0;
    else
        pCache->pFreeTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// build: context sub_M117_Emit_0050F150
D2GlideFloorCacheEntryStrc* __fastcall sub_M117_Emit_0050F150(D2GlideTileCacheStrc* pTileCache, D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    sub_0050F150_TileCacheEvict(pTileCache);
    sub_0050F4F0_FloorCacheAppendFree(pCache, pEntry);
    return sub_0050F540_FloorCachePopFree(pCache);
}
