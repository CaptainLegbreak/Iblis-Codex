struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_00420750_UnlinkAll();
};

// 0x00420750
void D2TSListStrc::sub_00420750_UnlinkAll()
{
    D2TSLinkStrc* pNode;
    while ((pNode = Head()) != 0)
    {
        pNode->Unlink();
    }
}
