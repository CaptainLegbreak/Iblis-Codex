#include "D2D3DTypes.h"

static __declspec(noinline) void sub_006BAB30_Append(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode);

// 0x006BAB30
static void sub_006BAB30_Append(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
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

void __cdecl sub_006BAB30_EmitCaller(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
{
    sub_006BAB30_Append(pList, pNode);
}
