struct D2ListNode006C4D70Strc
{
    D2ListNode006C4D70Strc* pPrevLink;
    D2ListNode006C4D70Strc* pNext;
    int unk08;
    int nId;
    int unk10[11];
    int nValue;
};
struct D2List006C4D70Strc
{
    int nLinkOffset;
    D2ListNode006C4D70Strc* pTail;
    D2ListNode006C4D70Strc* pHead;
};
extern D2List006C4D70Strc gList_0074C48C; // 0x0074C48C
extern D2List006C4D70Strc gList_0074C498; // 0x0074C498

// 0x006C4D70
int __stdcall sub_006C4D70_FindValue(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        D2List006C4D70Strc* pList = i ? &gList_0074C498 : &gList_0074C48C;
        for (D2ListNode006C4D70Strc* pNode = pList->pHead; (int)pNode > 0; pNode = pNode->pNext)
        {
            if (pNode->nId == nId)
            {
                return pNode->nValue;
            }
        }
    }
    return 0;
}
