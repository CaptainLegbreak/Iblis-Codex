struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem);                                   // 0x0062A1E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900

// 0x0063DBC0
static __declspec(noinline) int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2)
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

int __fastcall sub_G08_Emit_0063DBC0(D2UnitStrc* pItem2, D2UnitStrc* pItem1, D2UnitStrc* pUnit)
{
    return sub_0063DBC0_PairIsWieldable(pUnit, pItem1, pItem2);
}
