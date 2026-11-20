#include "D2Direct3D.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

static __declspec(noinline) void sub_006BA5C0_AppendTail(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode);
// 0x006BA5C0
static void sub_006BA5C0_AppendTail(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
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

__declspec(noinline) D2TexPoolEntryStrc* __fastcall sub_006BA660_Unlink(D2TexPoolStrc* pList, int nIndex);

// build: context sub_006BA660_Unlink
D2TexPoolEntryStrc* __fastcall sub_006BA660_Unlink(D2TexPoolStrc* pList, int nIndex)
{
    D2TexPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
        return 0;

    D2TexPoolEntryStrc* pNode = &pList->pEntries[nIndex];
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

// 0x006BA760
void __fastcall sub_006BA760_MoveToTail(D2TexPoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 245);
        LRU_ASSERT(nIndex <= pList->nCapacity, 246);
        LRU_ASSERT(nIndex >= 1, 248);
        sub_006BA5C0_AppendTail(pList, sub_006BA660_Unlink(pList, nIndex - 1));
    }
}
