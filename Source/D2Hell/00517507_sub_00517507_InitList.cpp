struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    unsigned int nNextLink;
};

struct D2StormListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;
};

// 0x00517507
void __fastcall sub_00517507_InitList(D2StormListStrc* pList)
{
    D2StormLinkStrc* pTerminator = &pList->tTerminator;
    pTerminator->pPrevLink = pTerminator;
    pList->tTerminator.nNextLink = ~(unsigned int)pTerminator;
}
