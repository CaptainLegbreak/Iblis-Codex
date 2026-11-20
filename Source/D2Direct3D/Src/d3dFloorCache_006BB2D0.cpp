#include "D2Direct3D.h"
#include "D2DrlgMaps.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

static __declspec(noinline) void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode);
// 0x006BB150
static void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode)
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

__declspec(noinline) D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_Unlink(D2FloorPoolStrc* pList, int nIndex);

// build: context sub_006BB1F0_Unlink
D2FloorPoolEntryStrc* __fastcall sub_006BB1F0_Unlink(D2FloorPoolStrc* pList, int nIndex)
{
    D2FloorPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
        return 0;

    D2FloorPoolEntryStrc* pNode = &pList->pEntries[nIndex];
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

// 0x006BB2D0
void __fastcall sub_006BB2D0_MoveToTail(D2FloorPoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nCapacity, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BB150_AppendTail(pList, sub_006BB1F0_Unlink(pList, nIndex - 1));
    }
}
