struct TSLink
{
    void* m_prevlink;
    void* m_next;
    void __thiscall Unlink(); // 0x005174E2
};

struct D2ListStrc
{
    int nLinkOffset;
    TSLink tTerminator;
    void __thiscall sub_0051763C_UnlinkAll(); // 0x0051763C
};

extern D2ListStrc gFaultHandlerList; // 0x0072FA14

// 0x006CB401
void __cdecl sub_006CB401_StaticFini_gFaultHandlerList()
{
    gFaultHandlerList.sub_0051763C_UnlinkAll();
    gFaultHandlerList.tTerminator.Unlink();
}
