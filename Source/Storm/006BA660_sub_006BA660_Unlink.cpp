struct D2Node006BA660Strc
{
    unsigned char unk_00[0x18];
    D2Node006BA660Strc* pNext18;
    D2Node006BA660Strc* pPrev1C;
};
struct D2List006BA660Strc
{
    unsigned char unk_00[8];
    D2Node006BA660Strc* pHead8;
    D2Node006BA660Strc* pTailC;
    unsigned char unk_10[8];
    D2Node006BA660Strc* pNodes18;
};

// 0x006BA660
D2Node006BA660Strc* __fastcall sub_006BA660_Unlink(D2List006BA660Strc* pList, int nIndex)
{
    D2Node006BA660Strc* pHead = pList->pHead8;
    if (!pHead)
    {
        return 0;
    }
    D2Node006BA660Strc* pNode = &pList->pNodes18[nIndex];
    if (pNode == pHead)
    {
        pList->pHead8 = pHead->pNext18;
        if (pList->pHead8)
        {
            pList->pHead8->pPrev1C = 0;
        }
        else
        {
            pList->pTailC = 0;
        }
        pHead->pNext18 = 0;
        pHead->pPrev1C = 0;
        return pHead;
    }
    if (pNode == pList->pTailC)
    {
        pList->pTailC = pList->pTailC->pPrev1C;
        pList->pTailC->pNext18 = 0;
    }
    else
    {
        pNode->pPrev1C->pNext18 = pNode->pNext18;
        pNode->pNext18->pPrev1C = pNode->pPrev1C;
    }
    pNode->pNext18 = 0;
    pNode->pPrev1C = 0;
    return pNode;
}
