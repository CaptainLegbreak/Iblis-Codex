struct D2Node006BB1F0Strc
{
    unsigned char unk_00[0x10];
    D2Node006BB1F0Strc* pNext10;
    D2Node006BB1F0Strc* pPrev14;
};
struct D2List006BB1F0Strc
{
    unsigned char unk_00[8];
    D2Node006BB1F0Strc* pHead8;
    D2Node006BB1F0Strc* pTailC;
    unsigned char unk_10[8];
    D2Node006BB1F0Strc* pNodes18;
};

// 0x006BB1F0
D2Node006BB1F0Strc* __fastcall sub_006BB1F0_TakeNode(D2List006BB1F0Strc* pList, int nIndex)
{
    D2Node006BB1F0Strc* pHead = pList->pHead8;
    if (!pHead)
    {
        return 0;
    }
    D2Node006BB1F0Strc* pNode = &pList->pNodes18[nIndex];
    if (pNode == pHead)
    {
        pList->pHead8 = pHead->pNext10;
        if (pList->pHead8)
        {
            pList->pHead8->pPrev14 = 0;
        }
        else
        {
            pList->pTailC = 0;
        }
        pHead->pNext10 = 0;
        pHead->pPrev14 = 0;
        return pHead;
    }
    if (pNode == pList->pTailC)
    {
        pList->pTailC = pList->pTailC->pPrev14;
        pList->pTailC->pNext10 = 0;
    }
    else
    {
        pNode->pPrev14->pNext10 = pNode->pNext10;
        pNode->pNext10->pPrev14 = pNode->pPrev14;
    }
    pNode->pNext10 = 0;
    pNode->pPrev14 = 0;
    return pNode;
}
