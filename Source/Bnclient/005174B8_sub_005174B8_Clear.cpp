struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    int pNext;

    void sub_005174B8_Clear(); // 0x005174B8
};

// 0x005174B8
void D2StormLinkStrc::sub_005174B8_Clear()
{
    pPrevLink = 0;
    pNext = 0;
}
