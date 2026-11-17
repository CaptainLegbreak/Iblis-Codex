struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
    virtual void Slot3(int nArg);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

void __cdecl sub_00480230();                                                                                // 0x00480230
extern D2ClientSlotHolderStrc* gpSlotHolder_007BC990;                                                       // 0x007BC990

// 0x00480320
void __fastcall sub_00480320_CallHolderSlot3(int nArg)
{
    if (gpSlotHolder_007BC990)
    {
        gpSlotHolder_007BC990->pObj->Slot3(nArg);
        sub_00480230();
    }
}
