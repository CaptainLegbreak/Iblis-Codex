#include "D2Client.h"

struct D2MsgHandlerEntryStrc;
struct D2RectStrc;

struct D2UnitStrc
{
    int type;
    int classId;
    void* pool;
    int id;
    char unknown10[0x50];
    D2InventoryStrc* inventory;
};

extern int gnGlobal_007C5470; // 0x007C5470
extern int gnGlobal_007C5474; // 0x007C5474
extern int gnGlobal_007C547C; // 0x007C547C
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc*); // 0x00468070
int __fastcall sub_004B9A00(int, D2UnitStrc*, int, int, int); // 0x004B9A00
void __fastcall sub_00478700_SendCommand(char, int, int, int, int); // 0x00478700
void __cdecl sub_004B3FE0(); // 0x004B3FE0
void __cdecl sub_004C0090_CloseUseItemPanel(); // 0x004C0090

typedef void(__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern unsigned long gdwTick_007C5488; // 0x007C5488
extern D2MsgHandlerEntryStrc gaMsgHandlers_00727950[]; // 0x00727950
void __fastcall sub_00456300(int nArg1, int nArg2); // 0x00456300
int __cdecl sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __cdecl sub_00487B80(); // 0x00487B80
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700
void __cdecl sub_0044DA40(); // 0x0044DA40
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

// 0x004C02F0
int __cdecl sub_004C02F0_ClosePanel()
{
    int mode = gnGlobal_007C5474;
    if (mode == 3) return 0;
    if (mode == 2) {
        D2UnitStrc* player = sub_00463DD0_GetPlayerUnit();
        D2InventoryStrc* inventory = player ? player->inventory : 0;
        sub_00468070_SetCursorItemState(player ? INVENTORY_GetCursorItem(inventory) : 0);
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    if (!gnGlobal_007C5470) {
        D2UnitStrc* player = sub_00463DD0_GetPlayerUnit();
        int id = !player ? -1 : player->id;
        int value = gnGlobal_007C547C;
        sub_00478700_SendCommand(0x44, id, value, 0, 2);
        sub_004C0090_CloseUseItemPanel();
    } else {
        sub_004B3FE0();
        sub_004C0090_CloseUseItemPanel();
    }
    return 1;
}

// 0x004C0380
void __cdecl sub_004C0380_OpenPanel()
{
    sub_00456300(0, 0);
    gnGlobal_007C5474 = 1;
    gdwTick_007C5488 = GetTickCount();
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00727950, 8);
    sub_00487B80();
    if (!sub_00455F20(14, 0, 0))
    {
        if (!gnGlobal_007C5470)
        {
            D2UnitStrc* pPlayer = sub_00463DD0();
            sub_00478700_SendCommand(0x44, !pPlayer ? -1 : pPlayer->id, gnGlobal_007C547C, 0, 2);
            sub_004C0090();
        }
        else
        {
            sub_004B3FE0();
            sub_004C0090();
        }
        return;
    }

    sub_0044DA40();
    D2RectStrc tRect;
    tRect.nTop = 0x5B;
    tRect.nLeft = 0x6B;
    tRect.nBottom = 0x116;
    tRect.nRight = 0xDE;
    sub_00467430(&tRect);
}
