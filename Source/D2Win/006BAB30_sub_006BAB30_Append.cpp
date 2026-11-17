struct sub_006BAB30_Node
{
    char unk_00[0x10];
    sub_006BAB30_Node* pNext;
    sub_006BAB30_Node* pPrev;
};

struct sub_006BAB30_List
{
    int unk_00[2];
    sub_006BAB30_Node* pHead;
    sub_006BAB30_Node* pTail;
};

static __declspec(noinline) void sub_006BAB30_Append(sub_006BAB30_List* pList, sub_006BAB30_Node* pNode);

// 0x006BAB30
static void sub_006BAB30_Append(sub_006BAB30_List* pList, sub_006BAB30_Node* pNode)
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

void __cdecl sub_006BAB30_EmitCaller(sub_006BAB30_List* pList, sub_006BAB30_Node* pNode)
{
    sub_006BAB30_Append(pList, pNode);
}
