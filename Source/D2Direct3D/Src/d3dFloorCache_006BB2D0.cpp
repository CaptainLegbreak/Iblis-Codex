#include "D2Direct3D.h"

struct sub_006BB2D0_Node
{
    char unk_00[0x10];
    sub_006BB2D0_Node* pNext;
    sub_006BB2D0_Node* pPrev;

};

struct sub_006BB2D0_List
{
    int nMax;
    int nCount;
    sub_006BB2D0_Node* pHead;
    sub_006BB2D0_Node* pTail;
    char unk_10[8];
    sub_006BB2D0_Node* pEntries;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const char* __fastcall sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* szExpression, const char* szFile, int nLine); // 0x00408A60

#define LRU_ASSERT(expr, line) if (!(expr)) { sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), line); exit(-1); }

static __declspec(noinline) void sub_006BB150_AppendTail(sub_006BB2D0_List* pList, sub_006BB2D0_Node* pNode);
// 0x006BB150
static void sub_006BB150_AppendTail(sub_006BB2D0_List* pList, sub_006BB2D0_Node* pNode)
{
    if (!pList->pHead)
    {
        pList->pHead = pNode;
        pList->pTail = pNode;
        return;
    }
    pList->pTail->pNext = pNode;
    pNode->pPrev = pList->pTail;
    pList->pTail = pNode;
}

__declspec(noinline) sub_006BB2D0_Node* __fastcall sub_006BB1F0_Unlink(sub_006BB2D0_List* pList, int nIndex);

// build: context sub_006BB1F0_Unlink
sub_006BB2D0_Node* __fastcall sub_006BB1F0_Unlink(sub_006BB2D0_List* pList, int nIndex)
{
    sub_006BB2D0_Node* pHead = pList->pHead;
    if (!pHead)
        return 0;

    sub_006BB2D0_Node* pNode = &pList->pEntries[nIndex];
    if (pNode == pHead)
    {
        pList->pHead = pHead->pNext;
        if (pHead->pNext)
            pHead->pNext->pPrev = 0;
        else
            pList->pTail = 0;
        pHead->pNext = 0;
        pHead->pPrev = 0;
        return pHead;
    }

    if (pNode == pList->pTail)
    {
        pList->pTail = pNode->pPrev;
        pList->pTail->pNext = 0;
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
void __fastcall sub_006BB2D0_MoveToTail(sub_006BB2D0_List* pList, int nIndex)
{
    if (pList->nCount > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nMax, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BB150_AppendTail(pList, sub_006BB1F0_Unlink(pList, nIndex - 1));
    }
}
