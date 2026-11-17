extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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
