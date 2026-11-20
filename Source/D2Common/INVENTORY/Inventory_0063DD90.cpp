#include "D2Structs.h"
struct D2InventoryStrc;


int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc);                                     // 0x0062ED50
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem);                                   // 0x0062A1E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD);                        // 0x00621050
int __stdcall sub_0063CB00_CanPlaceInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc, int nInventoryRecordId); // 0x0063CB00

static __declspec(noinline) int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2);
static int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0063DBC0

static int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!pItem1 || !pItem2
        || ITEMS_GetAmmoType(pItem1) && ITEMS_CheckItemTypeId(pItem2, ITEMS_GetAmmoType(pItem1))
        || ITEMS_GetAmmoType(pItem2) && ITEMS_CheckItemTypeId(pItem1, ITEMS_GetAmmoType(pItem2)))
    {
        return 1;
    }

    if (ITEMS_GetQuiverType(pItem1) || ITEMS_GetQuiverType(pItem2))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem1) && !ITEMS_Is1Or2Handed(pUnit, pItem1))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem2) && !ITEMS_Is1Or2Handed(pUnit, pItem2))
    {
        return 0;
    }

    if (ITEMS_CheckItemTypeId(pItem1, 0x2D) && ITEMS_CheckItemTypeId(pItem2, 0x2D))
    {
        if (!pUnit)
        {
            return 0;
        }

        if (pUnit->dwUnitType == 1)
        {
            switch (MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId))
            {
            case 0x1A1:
            case 0x1A2:
                return ITEMS_CheckItemTypeId(pItem1, 0x43) && ITEMS_CheckItemTypeId(pItem2, 0x43);

            case 0x21C:
            case 0x21D:
            case 0x21E:
                return 1;

            default:
                return 0;
            }
        }

        if (pUnit->dwUnitType != 0)
        {
            return 0;
        }

        if (pUnit->dwClassId == 4)
        {
            return 1;
        }

        if (pUnit->dwClassId != 6 || !ITEMS_CheckItemTypeId(pItem1, 0x43))
        {
            return 0;
        }

        if (!ITEMS_CheckItemTypeId(pItem2, 0x43))
        {
            return 0;
        }
    }
    else
    {
        if (ITEMS_CheckItemTypeId(pItem1, 0x2D))
        {
            return 1;
        }

        if (!ITEMS_CheckItemTypeId(pItem2, 0x2D))
        {
            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_0063DD90_CheckHandSlots(D2UnitStrc* pUnit, int nOtherLoc, D2UnitStrc* pNewItem, D2UnitStrc* pLocItem, D2UnitStrc* pOtherItem);
static int __stdcall sub_0063DD90_CheckHandSlots(D2UnitStrc* pUnit, int nOtherLoc, D2UnitStrc* pNewItem, D2UnitStrc* pLocItem, D2UnitStrc* pOtherItem); // 0x0063DD90

// 0x0063DD90
static int __stdcall sub_0063DD90_CheckHandSlots(D2UnitStrc* pUnit, int nOtherLoc, D2UnitStrc* pNewItem, D2UnitStrc* pLocItem, D2UnitStrc* pOtherItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pNewItem)
    {
        if (pLocItem)
        {
            if (ITEMS_AreStackablesEqual(pLocItem, pNewItem))
            {
                return 6;
            }

            if (sub_0063DBC0_PairIsWieldable(pUnit, pNewItem, pOtherItem))
            {
                return 5;
            }

            return sub_0063CB00_CanPlaceInBodyLoc(pInventory, pNewItem, nOtherLoc, UNITS_GetInventoryRecordId(pUnit, 0, 1)) ? 7 : 0;
        }

        if (pOtherItem)
        {
            return sub_0063DBC0_PairIsWieldable(pUnit, pNewItem, pOtherItem) ? 1 : 2;
        }

        return 1;
    }

    if (pLocItem)
    {
        return 3;
    }

    if (pOtherItem && ITEMS_CheckWeaponIfTwoHanded(pOtherItem))
    {
        return 4;
    }

    return 0;
}

int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (pItem)
    {
        if (!ITEMS_CheckBodyLocation(pItem, nBodyLoc))
        {
            return 0;
        }

        if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 1, 0, 0, 0))
        {
            return 0;
        }
    }

    switch (nBodyLoc)
    {
    case 0:
        return 0;

    case 4:
    case 5:
    {
        const int nOtherLoc = nBodyLoc != 5 ? 5 : 4;
        D2UnitStrc* pLocItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        D2UnitStrc* pOtherItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
        return sub_0063DD90_CheckHandSlots(pUnit, nOtherLoc, pItem, pLocItem, pOtherItem);
    }

    case 11:
    case 12:
    {
        const int nOtherLoc = nBodyLoc != 12 ? 12 : 11;
        D2UnitStrc* pLocItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        D2UnitStrc* pOtherItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
        return sub_0063DD90_CheckHandSlots(pUnit, nOtherLoc, pItem, pLocItem, pOtherItem);
    }

    default:
    {
        D2UnitStrc* pEquipped = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pItem)
        {
            return pEquipped ? 5 : 1;
        }
        return pEquipped ? 3 : 0;
    }
    }
}
