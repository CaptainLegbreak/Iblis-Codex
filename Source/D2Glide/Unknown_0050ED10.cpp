#include "D2Glide.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

// 0x0050EB60
static int sub_0050EB60_ListTakeFree(D2GlideTexCacheStrc* pList)
{
    if (pList->nUsed == pList->nCount)
    {
        return 0;
    }

    D2GlideTexCacheEntryStrc* pNode = pList->pFreeHead;
    if (pNode)
    {
        pList->pFreeHead = pNode->pNext;
        if (pList->pFreeHead)
        {
            pList->pFreeHead->pPrev = 0;
        }
        else
        {
            pList->pFreeTail = 0;
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
            pEntry->pOwner[pEntry->nOwnerIndex].nCache = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].nId = 0;
            pEntry->pOwner = 0;
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
