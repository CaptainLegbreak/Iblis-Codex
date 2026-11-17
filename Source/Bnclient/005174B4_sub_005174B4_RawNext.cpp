struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    int pNext;

    int sub_005174B4_RawNext(); // 0x005174B4
};

// 0x005174B4
int D2StormLinkStrc::sub_005174B4_RawNext()
{
    return pNext;
}
