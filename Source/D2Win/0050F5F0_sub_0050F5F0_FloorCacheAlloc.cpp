extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x42];
    short nCacheIndex;
};

struct D2GlideFloorCacheEntryStrc
{
    int nId;
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

void __fastcall sub_0050F6D0_FloorCacheEvict(D2GlideFloorCacheStrc* pCache);                                // 0x0050F6D0

// 0x0050F5F0
static int sub_0050F5F0_FloorCacheAlloc(D2GlideFloorCacheStrc* pCache)
{
    if (pCache->nUsed == pCache->nCount)
        return 0;

    D2GlideFloorCacheEntryStrc* pEntry = pCache->f_14;
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
    D2_ASSERT(pEntry, 0x9F);

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

// 0x0050F820
short __fastcall sub_0050F820_FloorCacheAdd(D2GlideFloorCacheStrc* pCache)
{
    int nId = sub_0050F5F0_FloorCacheAlloc(pCache);
    if (!nId)
    {
        sub_0050F6D0_FloorCacheEvict(pCache);
        nId = sub_0050F5F0_FloorCacheAlloc(pCache);
        D2_ASSERT(nId, 0x8B);
    }
    return nId;
}
