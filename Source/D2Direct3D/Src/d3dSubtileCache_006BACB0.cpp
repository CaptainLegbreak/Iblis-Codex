#include "D2Direct3D.h"
#include "D2GlideTypes.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
static __declspec(noinline) void sub_006BAB30_AppendTail(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode);
__declspec(noinline) D2SubtilePoolEntryStrc* __fastcall sub_006BABD0_Unlink(D2SubtilePoolStrc* pList, int nIndex);

D2SubtilePoolEntryStrc* __fastcall sub_006BABD0_TakeNode(D2SubtilePoolStrc* pList); // 0x006BABD0

// 0x006BAB30
static void sub_006BAB30_AppendTail(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
{
    if (!pList->pInUseFirst)
    {
        pList->pInUseFirst = pNode;
        pList->pInUseLast = pNode;
        return;
    }
    pList->pInUseLast->pNext = pNode;
    pNode->pPrev = pList->pInUseLast;
    pList->pInUseLast = pNode;
}

// build: context sub_006BABD0_Unlink
D2SubtilePoolEntryStrc* __fastcall sub_006BABD0_Unlink(D2SubtilePoolStrc* pList, int nIndex)
{
    D2SubtilePoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
        return 0;

    D2SubtilePoolEntryStrc* pNode = &pList->pEntries[nIndex];
    if (pNode == pHead)
    {
        pList->pInUseFirst = pHead->pNext;
        if (pHead->pNext)
            pHead->pNext->pPrev = 0;
        else
            pList->pInUseLast = 0;
        pHead->pNext = 0;
        pHead->pPrev = 0;
        return pHead;
    }

    if (pNode == pList->pInUseLast)
    {
        pList->pInUseLast = pNode->pPrev;
        pList->pInUseLast->pNext = 0;
    }
    else
    {
        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x006BACB0
void __fastcall sub_006BACB0_MoveToTail(D2SubtilePoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nCapacity, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BAB30_AppendTail(pList, sub_006BABD0_Unlink(pList, nIndex - 1));
    }
}

// 0x006BAD70
void __fastcall sub_006BAD70_MoveNode(D2SubtilePoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2SubtilePoolEntryStrc* pNode = sub_006BABD0_TakeNode(pList);
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
