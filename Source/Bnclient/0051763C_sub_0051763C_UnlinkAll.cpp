struct D2ListStrc {
    int unused0;
    int unused4;
    int head;
    void __thiscall sub_005175F1_UnlinkEntry(int offset); // 0x005175F1
    void __thiscall sub_0051763C_UnlinkAll();
};
// 0x0051763C
void __thiscall D2ListStrc::sub_0051763C_UnlinkAll()
{
    for (;;) {
        int first = head > 0 ? head : 0;
        if (!first) return;
        sub_005175F1_UnlinkEntry(first);
    }
}
