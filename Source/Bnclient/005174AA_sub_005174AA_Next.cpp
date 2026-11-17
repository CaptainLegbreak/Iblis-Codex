struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    int pNext;

    int sub_005174AA_Next(); // 0x005174AA
};

// 0x005174AA
int D2StormLinkStrc::sub_005174AA_Next()
{
    int nNext = pNext;
    if (nNext <= 0)
    {
        nNext = 0;
    }
    return nNext;
}
