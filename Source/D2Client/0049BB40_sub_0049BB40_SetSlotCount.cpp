struct D2RosterSlotStrc
{
    int bFlag;
    int nX;
    int nY;
    int unk0x0C;
    int nCount;
    int nType;
    int nState;
    int bActive;
};

#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    D2RosterSlotStrc f_0[5];
    char unkA0[0x25];
    int nId;
    char unkC9[4];
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)

// 0x0049BB40
static __forceinline void sub_0049BB40_SetSlotCount(D2RosterUnitStrc* pRow, int nSlot)
{
    if (pRow->f_0[nSlot].nState != 1)
        pRow->f_0[nSlot].nCount = 1;
}

void __fastcall sub_M110_Emit_0049BB40(D2RosterUnitStrc* pRow, int nSlot)
{
    sub_0049BB40_SetSlotCount(pRow, nSlot + 1);
}
