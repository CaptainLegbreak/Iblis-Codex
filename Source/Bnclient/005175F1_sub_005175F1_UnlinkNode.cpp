struct D2StormFaultLinkStrc;

struct D2StormLinkFieldStrc
{
    void __thiscall sub_005174E2_Unlink(); // 0x005174E2
};

struct D2StormListHeadStrc
{
    D2StormLinkFieldStrc* __thiscall sub_0051752F_GetLink(D2StormFaultLinkStrc* pNode); // 0x0051752F
    void __thiscall sub_005175F1_UnlinkNode(D2StormFaultLinkStrc* pNode);
};

// 0x005175F1
void D2StormListHeadStrc::sub_005175F1_UnlinkNode(D2StormFaultLinkStrc* pNode)
{
    sub_0051752F_GetLink(pNode)->sub_005174E2_Unlink();
}
