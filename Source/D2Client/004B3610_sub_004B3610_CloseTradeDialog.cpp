struct D2ClientDialogStrc;

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
};

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_004B2F50_ShowTradeDialog();                                                                // 0x004B2F50
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern D2ClientDialogStrc* gpDialog_007C0D77;                                                               // 0x007C0D77
extern D2NpcTradeObjStrc* gpTradeObj_007C0D83;                                                              // 0x007C0D83

// 0x004B3610
void __cdecl sub_004B3610_CloseTradeDialog()
{
    if (gpDialog_007C0D77)
    {
        sub_004B8020(gpDialog_007C0D77);
        delete gpTradeObj_007C0D83;
        gpTradeObj_007C0D83 = 0;
        gpDialog_007C0D77 = 0;
    }

    gnGlobal_007C0D31 = 5;
    sub_004B2F50_ShowTradeDialog();
}
