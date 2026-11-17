struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0();                                               // 0x0044DD20
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __fastcall sub_00455AE0_CloseUIVar(int nUIVar);                                                        // 0x00455AE0
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __cdecl sub_00469D50();                                                                                // 0x00469D50
void __fastcall sub_0046AA20(int nArg1, int nArg2);                                                         // 0x0046AA20
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0

extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[];                                                      // 0x0072478C
int gnGlobal_007C02B8;                                                                                      // 0x007C02B8

// 0x004A5D00
void __cdecl sub_004A5D00_OpenSliderHandlers()
{
    gnGlobal_007C02B8 = 1;
    sub_00455AE0_CloseUIVar(0xB);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
}

// 0x004A5DE0
void __cdecl sub_004A5DE0_CloseSliderHandlers()
{
    if (gnGlobal_007C02B8)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
        gnGlobal_007C02B8 = 0;
    }
}

#include "gen/data/Source/D2Client/004A5D00_sub_004A5D00_OpenSliderHandlers.inc"
