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

// 0x0050EB60
static int sub_0050EB60_ListTakeFree(D2GlideTexCacheStrc* pList)
{
    if (pList->nUsed == pList->nCount)
    {
        return 0;
    }

    D2GlideTexCacheEntryStrc* pNode = pList->f_14;
    if (pNode)
    {
        pList->f_14 = pNode->pNext;
        if (pList->f_14)
        {
            pList->f_14->pPrev = 0;
        }
        else
        {
            pList->f_18 = 0;
        }
        pNode->pNext = 0;
        pNode->pPrev = 0;
        if (!pList->pHead)
        {
            pList->nUsed += 1;
            pList->pHead = pNode;
            pList->pTail = pNode;
            return pNode->nId + 1;
        }
    }
    else
    {
        D2_ASSERT(pNode, 0xC1);
    }

    pList->pTail->pNext = pNode;
    pNode->pPrev = pList->pTail;
    pList->nUsed += 1;
    pList->pTail = pNode;
    return pNode->nId + 1;
}

static D2GlideTexCacheEntryStrc* sub_N19_TexPopHead(D2GlideTexCacheStrc* pCache)
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

void __fastcall sub_0050EC40_TexCacheEvict(D2GlideTexCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTexCacheEntryStrc* pEntry = sub_N19_TexPopHead(pCache);
    if (pEntry)
    {
        if (pEntry->pOwner)
        {
            pEntry->pOwner[pEntry->nOwnerIndex].unk0x00 = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].unk0x04 = 0;
            pEntry->pOwner = 0;
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

// 0x0050ED10
int __fastcall sub_0050ED10_ListRefill(D2GlideTexCacheStrc* pList)
{
    int nId;
    while (!(nId = sub_0050EB60_ListTakeFree(pList)))
    {
        sub_0050EC40_TexCacheEvict(pList);
    }
    return nId;
}
