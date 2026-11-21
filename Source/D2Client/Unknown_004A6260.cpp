#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl sub_00454980();                                                                                // 0x00454980
int __fastcall sub_00469C20_QueryKey(int nId, int nMode, int nCommand, int* pKey);                          // 0x00469C20
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[];                                                      // 0x0072478C
extern int gnGlobal_007C02B0;                                                                               // 0x007C02B0
extern int gnGlobal_007C02B8;                                                                               // 0x007C02B8
extern unsigned long gnGlobal_007C02C8;                                                                     // 0x007C02C8

// 0x004A5D70
static inline void __stdcall sub_004A5D70_RegisterMsgHandlers(int bReset)
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    if (bReset)
    {
        sub_00454980();
        gnGlobal_007C02B8 = 0;
    }
}

static void sub_004A6260_UpdateKeyState(int nCommand);

// 0x004A6260
static void sub_004A6260_UpdateKeyState(int nCommand)
{
    int nKey = 0;
    if (sub_00469C20_QueryKey(*(int*)gpListEntries_00724264[gnGlobal_007C02B0].nId, gnGlobal_007246D4, nCommand, &nKey))
    {
        sub_004A5D70_RegisterMsgHandlers(1);
    }
    else if ((unsigned short)nKey)
    {
        gwGlobal_007C02C4 = nKey;
        gnGlobal_007C02C8 = GetTickCount();
    }
}

// build: context sub_004A6310_ToggleMsgHandler
void __stdcall sub_004A6310_ToggleMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bReturn = 0;
        return;
    }

    sub_004A6260_UpdateKeyState(0x100);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall sub_004A6350_CommandMsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x004A6350
