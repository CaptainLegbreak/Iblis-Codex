#include "D2GlideTypes.h"
#include "D2D3DTypes.h"

static __forceinline D2SubtilePoolEntryStrc* TakeNode(D2SubtilePoolStrc* pList)
{
    D2SubtilePoolEntryStrc* pNode = pList->pInUseFirst;
    if (!pNode)
    {
        return 0;
    }

    D2SubtilePoolEntryStrc* pNewHead = pNode->pNext;
    pList->pInUseFirst = pNewHead;
    if (pNewHead)
    {
        pNewHead->pPrev = 0;
    }
    else
    {
        pList->pInUseLast = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x006BAD10
void __fastcall sub_006BAD10_ReleaseOldestNode(D2SubtilePoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2SubtilePoolEntryStrc* pNode = TakeNode(pList);
        if (pNode)
        {
            if (pNode->pOwner)
            {
                pNode->pOwner->nCacheIndex = 0;
                pNode->pOwner = 0;
            }
            if (!pList->pSpareFirst)
            {
                pList->pSpareFirst = pNode;
                pList->pSpareLast = pNode;
            }
            else
            {
                pList->pSpareLast->pNext = pNode;
                pNode->pPrev = pList->pSpareLast;
                pList->pSpareLast = pNode;
            }
        }
        --pList->nInUse;
    }
}
