struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x60 - 0x04];
    D2InventoryStrc* pInventory;
};

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

// 0x004C10E0
int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bResult = ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0);
    if (bResult && ITEMS_GetQuiverType(pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pOtherArmItem == pItem)
        {
            pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        }

        if (!pOtherArmItem || !ITEMS_CheckItemTypeId(pOtherArmItem, ITEMS_GetQuiverType(pItem)))
        {
            bResult = 0;
        }
    }

    return bResult;
}
