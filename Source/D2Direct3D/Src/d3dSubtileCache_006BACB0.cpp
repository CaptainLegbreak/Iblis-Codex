#include "D2Direct3D.h"

#define LRU_ASSERT(expr, line) if (!(expr)) { sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), line); exit(-1); }

struct sub_006BACB0_Node;
struct sub_006BACB0_List;
struct D2Owner006BAD70Strc;
struct D2Node006BAD70Strc;
struct D2List006BAD70Strc;

struct sub_006BACB0_Node
{
    char unk_00[0x10];
    sub_006BACB0_Node* pNext;
    sub_006BACB0_Node* pPrev;

};

struct sub_006BACB0_List
{
    int nMax;
    int nCount;
    sub_006BACB0_Node* pHead;
    sub_006BACB0_Node* pTail;
    char unk_10[8];
    sub_006BACB0_Node* pEntries;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const char* __fastcall sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* szExpression, const char* szFile, int nLine); // 0x00408A60
static __declspec(noinline) void sub_006BAB30_AppendTail(sub_006BACB0_List* pList, sub_006BACB0_Node* pNode);
__declspec(noinline) sub_006BACB0_Node* __fastcall sub_006BABD0_Unlink(sub_006BACB0_List* pList, int nIndex);

struct D2Owner006BAD70Strc
{
    unsigned char unk_0[4];
    unsigned short wFlags4;
};

struct D2Node006BAD70Strc
{
    unsigned char unk_00[4];
    D2Owner006BAD70Strc* pOwner4;
    unsigned char unk_08[8];
    D2Node006BAD70Strc* pNext10;
    D2Node006BAD70Strc* pPrev14;
};

struct D2List006BAD70Strc
{
    unsigned char unk_00[4];
    int nCount4;
    unsigned char unk_08[8];
    D2Node006BAD70Strc* pHead10;
    D2Node006BAD70Strc* pTail14;
};

D2Node006BAD70Strc* __fastcall sub_006BABD0_TakeNode(D2List006BAD70Strc* pList); // 0x006BABD0

// 0x006BAB30
static void sub_006BAB30_AppendTail(sub_006BACB0_List* pList, sub_006BACB0_Node* pNode)
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

// build: context sub_006BABD0_Unlink
sub_006BACB0_Node* __fastcall sub_006BABD0_Unlink(sub_006BACB0_List* pList, int nIndex)
{
    sub_006BACB0_Node* pHead = pList->pHead;
    if (!pHead)
        return 0;

    sub_006BACB0_Node* pNode = &pList->pEntries[nIndex];
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

// 0x006BACB0
void __fastcall sub_006BACB0_MoveToTail(sub_006BACB0_List* pList, int nIndex)
{
    if (pList->nCount > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nMax, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BAB30_AppendTail(pList, sub_006BABD0_Unlink(pList, nIndex - 1));
    }
}

// 0x006BAD70
void __fastcall sub_006BAD70_MoveNode(D2List006BAD70Strc* pList)
{
    if (pList->nCount4)
    {
        D2Node006BAD70Strc* pNode = sub_006BABD0_TakeNode(pList);
        if (pNode)
        {
            if (pNode->pOwner4)
            {
                pNode->pOwner4->wFlags4 = 0;
                pNode->pOwner4 = 0;
            }
            if (!pList->pHead10)
            {
                pList->pHead10 = pNode;
                pList->pTail14 = pNode;
            }
            else
            {
                pList->pTail14->pNext10 = pNode;
                pNode->pPrev14 = pList->pTail14;
                pList->pTail14 = pNode;
            }
        }
        --pList->nCount4;
    }
}
