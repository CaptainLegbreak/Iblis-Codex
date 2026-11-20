#include "D2Direct3D.h"

struct sub_006BA760_Node
{
    char unk_00[0x18];
    sub_006BA760_Node* pNext;
    sub_006BA760_Node* pPrev;

};

struct sub_006BA760_List
{
    int nMax;
    int nCount;
    sub_006BA760_Node* pHead;
    sub_006BA760_Node* pTail;
    char unk_10[8];
    sub_006BA760_Node* pEntries;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

static __declspec(noinline) void sub_006BA5C0_AppendTail(sub_006BA760_List* pList, sub_006BA760_Node* pNode);
// 0x006BA5C0
static void sub_006BA5C0_AppendTail(sub_006BA760_List* pList, sub_006BA760_Node* pNode)
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

__declspec(noinline) sub_006BA760_Node* __fastcall sub_006BA660_Unlink(sub_006BA760_List* pList, int nIndex);

// build: context sub_006BA660_Unlink
sub_006BA760_Node* __fastcall sub_006BA660_Unlink(sub_006BA760_List* pList, int nIndex)
{
    sub_006BA760_Node* pHead = pList->pHead;
    if (!pHead)
        return 0;

    sub_006BA760_Node* pNode = &pList->pEntries[nIndex];
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

// 0x006BA760
void __fastcall sub_006BA760_MoveToTail(sub_006BA760_List* pList, int nIndex)
{
    if (pList->nCount > 1)
    {
        LRU_ASSERT(nIndex, 245);
        LRU_ASSERT(nIndex <= pList->nMax, 246);
        LRU_ASSERT(nIndex >= 1, 248);
        sub_006BA5C0_AppendTail(pList, sub_006BA660_Unlink(pList, nIndex - 1));
    }
}
