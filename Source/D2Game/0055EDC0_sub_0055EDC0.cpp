struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc { char unk00[0x60]; D2InventoryStrc* pInventory; };
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc*, int); // 0x0063C7F0
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063C4F0
void __stdcall sub_0063C550_Return(D2InventoryStrc*, int); // 0x0063C550
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc*, D2UnitStrc*); // 0x0063CC70
void __stdcall UNITS_RefreshInventory(D2UnitStrc*, int); // 0x00621000
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, int, int); // 0x006280D0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, int, int, const char*); // 0x006280A0
// 0x0055EDC0
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    nX &= 3;
    int nDestinationRow = 0;
    nX = nX > 0 ? nX : 0;
    nX = nX < 3 ? nX : 3;
    for (int nRow = 0; nRow < 4; ++nRow)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nX + 4 * nRow);
        if (pItem)
        {
            if (nDestinationRow != nRow)
            {
                INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nX + 4 * nDestinationRow);
                ITEMS_SetItemFlag(pItem, 0x400, 1);
                ITEMS_SetItemFlag(pItem, 1, 1);
                if (ITEMS_CheckItemFlag(pItem, 0x4000, 4883, ".\\ITEMS\\ItemMode.cpp"))
                    ITEMS_SetItemFlag(pItem, 0x4000, 0);
                UNITS_RefreshInventory(pUnit, 1);
                INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                sub_0063C550_Return(pInventory, nX + 4 * nRow);
            }
            ++nDestinationRow;
        }
    }
}
