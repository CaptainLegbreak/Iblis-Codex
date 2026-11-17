#include "D2Glide.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GlideTileCacheEntryStrc;
struct D2GlideTileCacheStrc;
struct D2GlideFloorCacheEntryStrc;
struct D2GlideFloorCacheStrc;

struct D2GlideTileCacheEntryStrc
{
    union
    {
        int unk0x00;
        int nId;
    };
    unsigned int f_4;
    D2GlideTileStrc* pTile;
    D2GlideTileCacheEntryStrc* pNext;
    D2GlideTileCacheEntryStrc* pPrev;
};

struct D2GlideTileCacheStrc
{
    unsigned int nBlockSize;
    int nCount;
    int nUsed;
    D2GlideTileCacheEntryStrc* pHead;
    D2GlideTileCacheEntryStrc* pTail;
    D2GlideTileCacheEntryStrc* f_14;
    D2GlideTileCacheEntryStrc* f_18;
    D2GlideTileCacheEntryStrc* pEntries;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gdwGlobal_0087EFB8; // 0x0087EFB8

struct D2GlideTileStrc
{
    int unk0x00;
    short nCacheIndex;
    short unk0x06;
};

struct D2GlideFloorCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2TileLibraryEntryStrc* pTile;
    D2GlideFloorCacheEntryStrc* pNext;
    D2GlideFloorCacheEntryStrc* pPrev;
};

struct D2GlideFloorCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideFloorCacheEntryStrc* pHead;
    D2GlideFloorCacheEntryStrc* pTail;
    D2GlideFloorCacheEntryStrc* f_14;
    D2GlideFloorCacheEntryStrc* f_18;
    D2GlideFloorCacheEntryStrc* pEntries;
};

// 0x0050ED90
int __fastcall sub_0050ED90_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->nBlockSize = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideTileCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideTileCacheEntryStrc), ".\\Src\\glSubtileCache.cpp", 0x29, 0);
    D2_ASSERT(pCache->pEntries, 0x2A);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideTileCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideTileCacheEntryStrc* pEntry = &pCache->pEntries[i];
        pEntry->unk0x00 = i;
        if (i < pCache->nCount - 1)
        {
            pEntry->pNext = &pCache->pEntries[i + 1];
        }
        if (i > 0)
        {
            pEntry->pPrev = &pCache->pEntries[i - 1];
        }
        pEntry->f_4 = nStart + i * nBlockSize;
    }

    pCache->nUsed = 0;
    pCache->pHead = 0;
    pCache->pTail = 0;
    pCache->f_14 = pCache->pEntries;
    pCache->f_18 = &pCache->pEntries[pCache->nCount - 1];

    if (!gdwGlobal_0087EFB8)
    {
        for (int i = 1; i < pCache->nCount - 1; ++i)
        {
            const unsigned int nEntryAddress = pCache->pEntries[i].f_4;
            if (nEntryAddress < 0x200000 && pCache->nBlockSize + nEntryAddress > 0x200000)
            {
                pCache->pEntries[i - 1].pNext = &pCache->pEntries[i + 1];
                pCache->pEntries[i + 1].pPrev = &pCache->pEntries[i - 1];
                pCache->pEntries[i].pPrev = 0;
                pCache->pEntries[i].pNext = 0;
                ++pCache->nUsed;
                break;
            }
        }

        if (pCache->pEntries[pCache->nCount - 1].f_4 < 0x200000 && pCache->nBlockSize + pCache->pEntries[pCache->nCount - 1].f_4 > 0x200000)
        {
            pCache->pEntries[pCache->nCount - 1].pPrev = 0;
            pCache->pEntries[pCache->nCount - 2].pNext = 0;
            pCache->f_18 = &pCache->pEntries[pCache->nCount - 2];
            --pCache->nCount;
        }
    }

    return pCache->nCount * nBlockSize + nStart;
}

// 0x0050EF40
static __declspec(noinline) void sub_0050EF40_TileCacheAppendUsed(D2GlideTileCacheStrc* pCache, D2GlideTileCacheEntryStrc* pEntry)
{
    if (!pCache->pHead)
    {
        pCache->pHead = pEntry;
        pCache->pTail = pEntry;
        return;
    }

    pCache->pTail->pNext = pEntry;
    pEntry->pPrev = pCache->pTail;
    pCache->pTail = pEntry;
}

static __declspec(noinline) D2GlideTileCacheEntryStrc* sub_0050EF80_TileCachePopUsed(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
    {
        return 0;
    }

    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
    {
        pCache->pHead->pPrev = 0;
    }
    else
    {
        pCache->pTail = 0;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EF80
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
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

static void sub_0050F4F0_FloorCacheAppendFree(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
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

static D2GlideFloorCacheEntryStrc* sub_0050F540_FloorCachePopFree(D2GlideFloorCacheStrc* pCache)
{
    D2GlideFloorCacheEntryStrc* pEntry = pCache->f_14;
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

D2GlideFloorCacheEntryStrc* __fastcall sub_M117_Emit_0050F150(D2GlideTileCacheStrc* pTileCache, D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    sub_0050F150_TileCacheEvict(pTileCache);
    sub_0050F4F0_FloorCacheAppendFree(pCache, pEntry);
    return sub_0050F540_FloorCachePopFree(pCache);
}

// 0x0050EFE0
static D2GlideTileCacheEntryStrc* sub_0050EFE0_TileCacheUnlink(int nIndex, D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
    {
        return 0;
    }

    D2_ASSERT(pCache->pEntries, 0x17D);
    D2GlideTileCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        return sub_0050EF80_TileCachePopUsed(pCache);
    }

    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050F0F0
void __fastcall sub_0050F0F0_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex)
{
    if (pCache->nUsed <= 1)
    {
        return;
    }

    D2_ASSERT(nIndex, 0xBA);
    D2_ASSERT(nIndex <= pCache->nCount, 0xBB);
    D2_ASSERT(nIndex >= 1, 0xBC);
    sub_0050EF40_TileCacheAppendUsed(pCache, sub_0050EFE0_TileCacheUnlink(nIndex - 1, pCache));
}

// 0x0050F1B0
void __fastcall sub_0050F1B0_TileCacheRelease(D2GlideTileCacheStrc* pCache, int nIndex)
{
    if (!pCache->nUsed)
    {
        return;
    }

    D2GlideTileCacheEntryStrc* pEntry = sub_0050EFE0_TileCacheUnlink(nIndex, pCache);
    if (pEntry)
    {
        if (pEntry->pTile)
        {
            pEntry->pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }

        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

static D2GlideTileCacheEntryStrc* sub_N19_TilePopHead(D2GlideTileCacheStrc* pCache)
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

static void sub_N19_TileEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_N19_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F070
static int sub_0050F070_TileCacheAlloc(D2GlideTileCacheStrc* pCache)
{
    if (pCache->nUsed == pCache->nCount)
        return 0;

    D2GlideTileCacheEntryStrc* pEntry = pCache->f_14;
    if (pEntry)
    {
        pCache->f_14 = pEntry->pNext;
        if (pCache->f_14)
            pCache->f_14->pPrev = 0;
        else
            pCache->f_18 = 0;
        pEntry->pNext = 0;
        pEntry->pPrev = 0;
    }
    D2_ASSERT(pEntry, 0x9D);

    if (!pCache->pHead)
    {
        ++pCache->nUsed;
        pCache->pHead = pEntry;
        pCache->pTail = pEntry;
        return pEntry->nId + 1;
    }

    pCache->pTail->pNext = pEntry;
    pEntry->pPrev = pCache->pTail;
    ++pCache->nUsed;
    pCache->pTail = pEntry;
    return pEntry->nId + 1;
}

// 0x0050F2B0
short __fastcall sub_0050F2B0_TileCacheAdd(D2GlideTileCacheStrc* pCache)
{
    int nId;
    while (!(nId = sub_0050F070_TileCacheAlloc(pCache)))
        sub_N19_TileEvict(pCache);
    return nId;
}
