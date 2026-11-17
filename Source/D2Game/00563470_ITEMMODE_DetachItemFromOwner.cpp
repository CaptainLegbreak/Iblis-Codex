struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x0C];
    int dwAnimMode;
    char unk_14[0x4C];
    D2InventoryStrc* pInventory;
};
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
void __stdcall ITEMS_SetOrRemoveFlag(int*, int, int); // 0x006287B0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc*, unsigned char); // 0x00628320
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, unsigned int); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0055DF10
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc*, D2UnitStrc*); // 0x0063C150
int __fastcall sub_6FC45B30(D2GameStrc*, D2UnitStrc*, unsigned short, int, int*); // 0x00560CD0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055EEA0

static __forceinline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x00563470
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pUnit)
        return;
    if (UNIT_TypeOrInvalid(pItem) != 4)
        return;
    D2UnitStrc* pValidItem = pItem;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;
    switch (pValidItem->dwAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pValidItem, ITEMS_GetInvPage(pValidItem));
        if (UNIT_TypeOrInvalid(pUnit) == 0)
        {
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1A75);
            if (pClient)
            {
                int nFlags = 0;
                ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
                D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pValidItem, nFlags);
            }
        }
        D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pValidItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pValidItem);
        int nResult;
        sub_6FC45B30(pGame, pUnit, nBodyLoc, 1, &nResult);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pUnit, pValidItem);
        break;
    }
}
