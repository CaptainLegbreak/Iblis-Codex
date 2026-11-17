struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrev;
    int nNext;
    D2StormLinkStrc* __thiscall sub_005174C0(int nLinkOffset);
};

// 0x005174C0
D2StormLinkStrc* __thiscall D2StormLinkStrc::sub_005174C0(int nLinkOffset)
{
    int nNextLink = nNext;
    if (nNextLink < 0)
    {
        return (D2StormLinkStrc*)~nNextLink;
    }

    if (nLinkOffset < 0)
    {
        nLinkOffset = (int)this - pPrev->nNext;
    }

    return (D2StormLinkStrc*)(nNextLink + nLinkOffset);
}
