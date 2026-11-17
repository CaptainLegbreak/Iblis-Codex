struct sub_006BA5C0_Node
{
    char unk_00[0x18];
    sub_006BA5C0_Node* pNext;
    sub_006BA5C0_Node* pPrev;
};

struct sub_006BA5C0_List
{
    int unk_00[2];
    sub_006BA5C0_Node* pHead;
    sub_006BA5C0_Node* pTail;
};

static __declspec(noinline) void sub_006BA5C0_Append(sub_006BA5C0_List* pList, sub_006BA5C0_Node* pNode);

// 0x006BA5C0
static void sub_006BA5C0_Append(sub_006BA5C0_List* pList, sub_006BA5C0_Node* pNode)
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

void __cdecl sub_006BA5C0_EmitCaller(sub_006BA5C0_List* pList, sub_006BA5C0_Node* pNode)
{
    sub_006BA5C0_Append(pList, pNode);
}
