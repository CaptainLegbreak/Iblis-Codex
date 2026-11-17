struct D2InventoryStrc;
struct D2UnitStrc { int type, classId; void* pool; int id; char unknown10[0x50]; D2InventoryStrc* inventory; };
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
