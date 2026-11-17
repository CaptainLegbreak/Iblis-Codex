class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_004B4830_Rebuild();                                                                        // 0x004B4830
extern D2NpcTradeObjStrc* gpTradeObj_007C0D83;                                                              // 0x007C0D83
extern void* gpRes_007C0D77;                                                                                // 0x007C0D77

// 0x004B69E0
void __cdecl sub_004B69E0_CloseTrade()
{
    if (gpTradeObj_007C0D83)
    {
        if (gpRes_007C0D77)
        {
            sub_004B8020(gpRes_007C0D77);
            delete gpTradeObj_007C0D83;
            gpTradeObj_007C0D83 = 0;
            gpRes_007C0D77 = 0;
        }
        sub_004B4830_Rebuild();
    }
}
