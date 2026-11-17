struct D2Owner006BAD70Strc
{
    unsigned char unk_0[4];
    unsigned short wFlags4;
};
struct D2Node006BAD70Strc
{
    unsigned char unk_00[4];
    D2Owner006BAD70Strc* pOwner4;
    unsigned char f_8[8];
    D2Node006BAD70Strc* pNext10;
    D2Node006BAD70Strc* pPrev14;
};
struct D2List006BAD70Strc
{
    unsigned char unk_00[4];
    int nCount4;
    D2Node006BAD70Strc* pUsedHead8;
    D2Node006BAD70Strc* pUsedTailC;
    D2Node006BAD70Strc* pHead10;
    D2Node006BAD70Strc* pTail14;
};

static __forceinline D2Node006BAD70Strc* TakeNode(D2List006BAD70Strc* pList)
{
    D2Node006BAD70Strc* pNode = pList->pUsedHead8;
    if (!pNode)
    {
        return 0;
    }

    D2Node006BAD70Strc* pNewHead = pNode->pNext10;
    pList->pUsedHead8 = pNewHead;
    if (pNewHead)
    {
        pNewHead->pPrev14 = 0;
    }
    else
    {
        pList->pUsedTailC = 0;
    }

    pNode->pNext10 = 0;
    pNode->pPrev14 = 0;
    return pNode;
}

// 0x006BAD10
void __fastcall sub_006BAD10_ReleaseOldestNode(D2List006BAD70Strc* pList)
{
    if (pList->nCount4)
    {
        D2Node006BAD70Strc* pNode = TakeNode(pList);
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
