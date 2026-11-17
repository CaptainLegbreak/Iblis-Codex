struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount);// 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
void __cdecl sub_00453EE0_ClosePanel();                                                                     // 0x00453EE0
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode);                                                      // 0x0045AEA0
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __fastcall sub_0046AA20(int nArg1, int nArg2);                                                         // 0x0046AA20
void __cdecl sub_0047B2E0();                                                                                // 0x0047B2E0
void __cdecl sub_0047B4E0();                                                                                // 0x0047B4E0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __cdecl sub_00489EE0();                                                                                // 0x00489EE0
void __cdecl sub_0048A500();                                                                                // 0x0048A500
void __cdecl sub_00494FC0();                                                                                // 0x00494FC0
void __cdecl sub_0049A020_FreeRosterUnits();                                                                // 0x0049A020
void __cdecl sub_0049CF50();                                                                                // 0x0049CF50
void __cdecl sub_0049FF00();                                                                                // 0x0049FF00
void __cdecl sub_004A01A0();                                                                                // 0x004A01A0
void __cdecl sub_004A28D0();                                                                                // 0x004A28D0
void __cdecl sub_004A3000();                                                                                // 0x004A3000
void __fastcall sub_004A5200(int nArg);                                                                     // 0x004A5200
void __cdecl sub_004ABF10();                                                                                // 0x004ABF10
void __cdecl sub_004B3F10();                                                                                // 0x004B3F10
void __fastcall sub_004B8940_CloseWait(int bReopen);                                                        // 0x004B8940
int __cdecl sub_004B9180();                                                                                 // 0x004B9180

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[];                                                    // 0x006D5F28
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F58[];                                                    // 0x006D5F58
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FAC[];                                                    // 0x006D5FAC
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FC4[];                                                    // 0x006D5FC4
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FD0[];                                                    // 0x006D5FD0
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FE8[];                                                    // 0x006D5FE8
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6000[];                                                    // 0x006D6000
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D600C[];                                                    // 0x006D600C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6024[];                                                    // 0x006D6024
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6030[];                                                    // 0x006D6030
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[];                                                    // 0x006D6084
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D60C0[];                                                    // 0x006D60C0
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D615C[];                                                    // 0x006D615C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61B0[];                                                    // 0x006D61B0
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61C8[];                                                    // 0x006D61C8
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6204[];                                                    // 0x006D6204
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D621C[];                                                    // 0x006D621C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D62C4[];                                                    // 0x006D62C4
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6300[];                                                    // 0x006D6300
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6318[];                                                    // 0x006D6318
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D633C[];                                                    // 0x006D633C
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6360[];                                                    // 0x006D6360
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F878[];                                                    // 0x0070F878
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F8D8[];                                                    // 0x0070F8D8
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F930[];                                                    // 0x0070F930
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F9D0[];                                                    // 0x0070F9D0
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA30[];                                                    // 0x0070FA30
extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA84[];                                                    // 0x0070FA84
extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0
extern int gnPanelFlag_007A2864;                                                                            // 0x007A2864

// 0x00455AE0
void __fastcall sub_00455AE0_ClearPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        gnPanelFlag_007A2864 = 0x0;
        return;
    case 0x0:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F28, 0x4);
        return;
    case 0x3:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FC4, 0x1);
        return;
    case 0x4:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FAC, 0x2);
        sub_00453AE0();
        sub_004ABF10();
        return;
    case 0x2:
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FD0, 0x2);
    case 0x12:
        sub_00453AE0();
        return;
    case 0x1:
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F58, 0x4);
        sub_00453AE0();
        return;
    case 0x5:
        sub_0047B2E0();
        sub_0047B4E0();
        if (!gaUIVarStates_007A27C0[0xC] && !gaUIVarStates_007A27C0[0x17] && !gaUIVarStates_007A27C0[0x19]
            && !gaUIVarStates_007A27C0[0x1A] && !gaUIVarStates_007A27C0[0x1B] && !gaUIVarStates_007A27C0[0x1C]
            && !gaUIVarStates_007A27C0[0x1D] && !gaUIVarStates_007A27C0[0x1E] && !gaUIVarStates_007A27C0[0x20])
            sub_0046AA20(0x1, 0x1);
        if (gaUIVarStates_007A27C0[0xA])
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        return;
    case 0x6:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FE8, 0x2);
        return;
    case 0x13:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6000, 0x1);
        return;
    case 0x7:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D600C, 0x2);
        return;
    case 0x8:
    case 0xE:
        sub_00453AE0();
        sub_004B3F10();
        return;
    case 0x9:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6030, 0x7);
        sub_00466FE0();
        return;
    case 0xB:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6024, 0x1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D60C0, 0xD);
        sub_004A5200(0);
        return;
    case 0xC:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        sub_004B3F10();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0xF:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F8D8, 0x7);
        sub_004A28D0();
        sub_00453AE0();
        return;
    case 0x11:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D615C, 0x4);
        sub_004A3000();
        return;
    case 0x10:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61B0, 0x2);
        sub_0049FF00();
        sub_00453AE0();
        return;
    case 0x14:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61C8, 0x5);
        sub_0049CF50();
        sub_00453AE0();
        return;
    case 0x15:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6204, 0x2);
        return;
    case 0x16:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D621C, 0x2);
        sub_0049A020_FreeRosterUnits();
        sub_00453AE0();
        return;
    case 0x17:
        if (sub_004B9180())
            return;
        sub_0045AEA0_SetPanelSlide(0);
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        sub_00453AE0();
        sub_004B8940_CloseWait(0);
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x19:
        sub_00453EE0_ClosePanel();
        sub_0045AEA0_SetPanelSlide(0);
        sub_00489EE0();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        sub_00453AE0();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x1A:
        sub_0045AEA0_SetPanelSlide(0);
        sub_0048A500();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        sub_00453AE0();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x18:
        sub_004A01A0();
        return;
    case 0x1F:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070FA84, 0x2);
        return;
    case 0x21:
        sub_00494FC0();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D62C4, 0x5);
        return;
    case 0x22:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6300, 0x2);
        return;
    case 0x23:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6318, 0x3);
        return;
    case 0x24:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D633C, 0x3);
        sub_00487990_ResetHover();
        return;
    case 0x25:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6360, 0x2);
        return;
    }
}
