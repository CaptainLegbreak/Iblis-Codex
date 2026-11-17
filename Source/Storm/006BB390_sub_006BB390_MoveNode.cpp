struct D2Owner006BB390Strc
{
    unsigned char unk_00[0x42];
    unsigned short wFlags42;
};
struct D2Node006BB390Strc
{
    unsigned char unk_00[4];
    D2Owner006BB390Strc* pOwner4;
    unsigned char unk_08[8];
    D2Node006BB390Strc* pNext10;
    D2Node006BB390Strc* pPrev14;
};
struct D2List006BB390Strc
{
    unsigned char unk_00[4];
    int nCount4;
    unsigned char unk_08[8];
    D2Node006BB390Strc* pHead10;
    D2Node006BB390Strc* pTail14;
};
D2Node006BB390Strc* __fastcall sub_006BB1F0_TakeNode(D2List006BB390Strc* pList); // 0x006BB1F0

// 0x006BB390
void __fastcall sub_006BB390_MoveNode(D2List006BB390Strc* pList)
{
    if (pList->nCount4)
    {
        D2Node006BB390Strc* pNode = sub_006BB1F0_TakeNode(pList);
        if (pNode)
        {
            if (pNode->pOwner4)
            {
                pNode->pOwner4->wFlags42 = 0;
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
