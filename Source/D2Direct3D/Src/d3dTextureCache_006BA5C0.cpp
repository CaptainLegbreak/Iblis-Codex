#include "D2D3DTypes.h"

static __declspec(noinline) void sub_006BA5C0_Append(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode);

// 0x006BA5C0
static void sub_006BA5C0_Append(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
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

void __cdecl sub_006BA5C0_EmitCaller(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
{
    sub_006BA5C0_Append(pList, pNode);
}
