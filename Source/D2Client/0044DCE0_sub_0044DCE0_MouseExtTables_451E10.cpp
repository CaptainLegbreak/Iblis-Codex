struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};
typedef char D2MsgHandlerEntrySize[(sizeof(D2MsgHandlerEntryStrc) == 12) ? 1 : -1];
extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F2C4[1]; // 0x0070F2C4
extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F348[2]; // 0x0070F348
extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F360[2]; // 0x0070F360
extern "C" int __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0
extern "C" void __fastcall sub_00451DB0_RegisterMsgHandlers(int hwnd, D2MsgHandlerEntryStrc* table, unsigned int count); // 0x00451DB0
extern "C" void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

// 0x0044DCE0
extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F2C4, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F348, 2);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F360, 2);
}

// 0x0044DD20
extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F2C4, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F348, 2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F360, 2);
}

#include "gen/data/Source/D2Client/0044DCE0_sub_0044DCE0_MouseExtTables_451E10.inc"
