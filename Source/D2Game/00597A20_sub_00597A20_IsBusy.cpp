struct D2GameStrc;
struct D2InventoryStrc;
struct D2InventoryNodeStrc;
struct D2UnitStrc {
    unsigned char unknown0[0x60];
    D2InventoryStrc* inventory;
    unsigned char unknown64[0x64];
    unsigned int flags;
};
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc*); // 0x0063CBB0
D2InventoryNodeStrc* __stdcall sub_0063CD20(D2InventoryNodeStrc*); // 0x0063CD20
int __stdcall sub_0063CD40(D2InventoryNodeStrc*); // 0x0063CD40
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60

static __forceinline int CheckFlag(D2UnitStrc* unit, int bit)
{
    if (!unit)
    {
        return 0;
    }
    return (unit->flags >> bit) & 1;
}
// 0x00597A20
int __fastcall sub_00597A20_IsBusy(D2GameStrc* game, D2UnitStrc* unit)
{
    if (!CheckFlag(unit, 22) && !CheckFlag(unit, 23))
    {
        D2InventoryNodeStrc* node = INVENTORY_GetTradeInventory(unit->inventory);
        while (node)
        {
            D2UnitStrc* item = SUNIT_GetServerUnit(game, 4, sub_0063CD40(node));
            D2InventoryNodeStrc* next = sub_0063CD20(node);
            if (item)
            {
                return 1;
            }
            node = next;
        }
        return 0;
    }
    return 1;
}
