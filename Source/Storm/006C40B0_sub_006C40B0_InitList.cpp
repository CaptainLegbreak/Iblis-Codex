struct sub_006C40B0_Link
{
    sub_006C40B0_Link* pPrev;
    unsigned int dwNext;
};

struct sub_006C40B0_List
{
    int unk_00;
    sub_006C40B0_Link tLink;
};

// 0x006C40B0
void __fastcall sub_006C40B0_InitList(sub_006C40B0_List* pList)
{
    sub_006C40B0_Link* pLink = &pList->tLink;
    pLink->pPrev = pLink;
    pList->tLink.dwNext = ~(unsigned int)pLink;
}
