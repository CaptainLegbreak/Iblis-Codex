struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    D2StormLinkStrc* pNextLink;
    void __thiscall sub_005174E2_Unlink(); // 0x005174E2
};

struct D2StormListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;
    void __thiscall sub_0051763C_UnlinkAll(); // 0x0051763C
    void __thiscall sub_005176D3_Destroy();
};

// 0x005176D3
void __thiscall D2StormListStrc::sub_005176D3_Destroy()
{
    sub_0051763C_UnlinkAll();
    tTerminator.sub_005174E2_Unlink();
}
