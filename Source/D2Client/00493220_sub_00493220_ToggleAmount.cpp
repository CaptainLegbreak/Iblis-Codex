struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

// 0x00493220
static __forceinline void sub_00493220_ToggleAmount(int* pTotal, int* pAmount)
{
    if (*pAmount)
    {
        *pTotal -= *pAmount;
        *pAmount = 0;
    }
    else
    {
        *pAmount = 10;
        *pTotal += 10;
    }
}

// 0x004934B0
D2UnitStrc* __cdecl sub_004934B0_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return 0;
    return INVENTORY_GetCursorItem(pPlayer->pInventory);
}

void __fastcall sub_M110_Emit_00493220(int* pTotal, int* pAmount)
{
    sub_00493220_ToggleAmount(pTotal + 1, pAmount);
}
