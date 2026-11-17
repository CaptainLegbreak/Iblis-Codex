struct D2OwnerSlot006BA7C0Strc
{
    int n0;
    int n4;
};
struct D2Node006BA7C0Strc;
struct D2Link006BA7C0Strc
{
    D2Node006BA7C0Strc* pNext;
    D2Node006BA7C0Strc* pPrev;
};
struct D2Node006BA7C0Strc
{
    unsigned char unk_00[4];
    D2OwnerSlot006BA7C0Strc* pOwnerSlots;
    int nOwnerIndex;
    unsigned char unk_0C[0x0C];
    D2Link006BA7C0Strc f_18;
};
struct D2List006BA7C0Strc
{
    unsigned char unk_00[4];
    int nCount4;
    D2Node006BA7C0Strc* pFreeHead8;
    D2Node006BA7C0Strc* pFreeTailC;
    D2Node006BA7C0Strc* pHead10;
    D2Node006BA7C0Strc* pTail14;
};

static inline void ResetLink(D2Link006BA7C0Strc* pLink)
{
    pLink->pNext = 0;
    pLink->pPrev = 0;
}

// 0x006BA7C0
void __fastcall sub_006BA7C0_MoveFreeNode(D2List006BA7C0Strc* pList)
{
    if (pList->nCount4)
    {
        D2Node006BA7C0Strc* pNode = pList->pFreeHead8;
        if (pNode)
        {
            pList->pFreeHead8 = pNode->f_18.pNext;
            if (pList->pFreeHead8)
            {
                pList->pFreeHead8->f_18.pPrev = 0;
            }
            else
            {
                pList->pFreeTailC = 0;
            }
            ResetLink(&pNode->f_18);
            if (pNode->pOwnerSlots)
            {
                pNode->pOwnerSlots[pNode->nOwnerIndex].n0 = 0;
                pNode->pOwnerSlots[pNode->nOwnerIndex].n4 = 0;
                pNode->pOwnerSlots = 0;
            }
            if (!pList->pHead10)
            {
                pList->pHead10 = pNode;
                pList->pTail14 = pNode;
            }
            else
            {
                pList->pTail14->f_18.pNext = pNode;
                pNode->f_18.pPrev = pList->pTail14;
                pList->pTail14 = pNode;
            }
        }
        --pList->nCount4;
    }
}
