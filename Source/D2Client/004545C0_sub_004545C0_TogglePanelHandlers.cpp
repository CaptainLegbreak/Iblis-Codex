struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* f_8;
};

int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6024[];                                                    // 0x006D6024
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[];                                                    // 0x006D6084
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D60C0[];                                                    // 0x006D60C0
extern void* gpGlobal_007A27A0;                                                                             // 0x007A27A0
int gnPanelState_007A27E8;                                                                                  // 0x007A27E8

// 0x004545C0
void __fastcall sub_004545C0_TogglePanelHandlers(int bRegister)
{
    if (bRegister)
    {
        if (gnPanelState_007A27E8)
        {
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 5);
        }
    }
    else
    {
        if (gnPanelState_007A27E8)
        {
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 5);
        }
    }
}

// 0x00454980
void __cdecl sub_00454980()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D60C0, 13);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6024, 1);
}

// 0x004549C0
int __cdecl sub_004549C0_IsPanelAllocated()
{
    return gpGlobal_007A27A0 != 0;
}

#include "gen/data/Source/D2Client/004545C0_sub_004545C0_TogglePanelHandlers.inc"
