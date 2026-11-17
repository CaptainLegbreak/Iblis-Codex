extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GlideTileStrc
{
    int unk0x00;
    short nCacheIndex;
    short unk0x06;
    int unk0x08[2];
    unsigned char* pData;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x42];
    short nCacheIndex;
    char unk0x44[0x0C];
    int nSubtiles;
    D2GlideTileStrc* pSubtiles;
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

struct D2GlideTileCacheStrc;

extern D2GlideTileCacheStrc gGlideTileCache_0087EB48;
extern D2GlideFloorCacheStrc gGlideFloorCache_0087EB68;

void __fastcall sub_0050F1B0_TileCacheRelease(D2GlideTileCacheStrc* pCache, int nIndex);
D2GlideFloorCacheEntryStrc* __fastcall sub_0050F570_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex);
void __fastcall sub_0050F750_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex);

// 0x0050F4D0
static __declspec(noinline) void sub_0050F4D0_FloorCacheAppendUsed(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
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

void __fastcall sub_0050F670_FloorCacheTouch(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    if (pCache->nUsed <= 1)
    {
        return;
    }

    D2_ASSERT(nIndex, 0xBC);
    D2_ASSERT(nIndex <= pCache->nCount, 0xBD);
    D2_ASSERT(nIndex >= 1, 0xBE);
    sub_0050F4D0_FloorCacheAppendUsed(pCache, sub_0050F570_FloorCacheUnlink(pCache, nIndex - 1));
}

void __fastcall sub_0050FCB0_GlideReleaseTileCache(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheIndex > 0)
    {
        sub_0050F750_FloorCacheRemove(&gGlideFloorCache_0087EB68, (short)(pTile->nCacheIndex - 1));
    }

    for (int i = 0; i < pTile->nSubtiles; ++i)
    {
        if (pTile->pSubtiles[i].nCacheIndex > 0)
        {
            sub_0050F1B0_TileCacheRelease(&gGlideTileCache_0087EB48, (short)(pTile->pSubtiles[i].nCacheIndex - 1));
        }
    }
}
