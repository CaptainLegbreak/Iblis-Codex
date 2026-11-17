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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2GlideTexCacheEntryStrc* __fastcall sub_0050EAE0_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex);   // 0x0050EAE0

// 0x0050EA40
static __declspec(noinline) void sub_0050EA40_TexCacheAppendUsed(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
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

// 0x0050EBE0
void __fastcall sub_0050EBE0_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId)
{
    if (pCache->nUsed > 1)
    {
        D2_ASSERT(nId, 0xDE);
        D2_ASSERT(nId <= pCache->nCount, 0xDF);
        D2_ASSERT(nId >= 1, 0xE0);
        sub_0050EA40_TexCacheAppendUsed(sub_0050EAE0_TexCacheUnlink(pCache, nId - 1), pCache);
    }
}
