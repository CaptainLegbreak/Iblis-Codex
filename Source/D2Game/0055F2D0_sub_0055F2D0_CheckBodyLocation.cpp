struct D2UnitStrc { int dwUnitType; int dwClassId; };
int __fastcall sub_0055F240_GetOppositeBodyLoc(int); // 0x0055F240
int __fastcall sub_0055F240_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0
int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc*, D2UnitStrc*); // 0x0062A1E0
__forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}
// 0x0055F2D0
int __fastcall sub_0055F2D0_CheckBodyLocation(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
{
    if (!pUnit || !pItem || GetUnitType(pItem) != 4) return 0;
    D2UnitStrc* pPrimary = *ppPrimary;
    if (pPrimary)
    {
        if (*ppOther) return 0;
    }
    else if (!*ppOther) return 1;
    int nOpposite = sub_0055F240_GetOppositeBodyLoc(*pBodyLoc);
    if (pPrimary)
    {
        *ppPrimary = *ppOther;
        *ppOther = pPrimary;
        *pBodyLoc = nOpposite;
    }
    switch (*pBodyLoc)
    {
    case 4: case 5: case 11: case 12:
        if (ITEMS_GetAmmoType(pItem) > 0)
        {
            if (!*ppOther) return 1;
            return ITEMS_CheckItemTypeId(*ppOther, ITEMS_GetAmmoType(pItem)) != 0;
        }
        if (ITEMS_GetQuiverType(pItem))
        {
            if (!*ppOther) return 1;
            if (ITEMS_GetAmmoType(*ppOther) <= 0) return 0;
            return ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        }
        if (ITEMS_GetAmmoType(*ppOther) > 0) return ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        if (ITEMS_GetQuiverType(*ppOther) > 0) return ITEMS_CheckItemTypeId(pItem, ITEMS_GetQuiverType(*ppOther)) != 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem) && !ITEMS_Is1Or2Handed(pUnit, pItem)) return 0;
        if (ITEMS_CheckWeaponIfTwoHanded(*ppOther) && !ITEMS_Is1Or2Handed(pUnit, *ppOther)) return 0;
        {
            int bItemWeapon = ITEMS_CheckItemTypeId(pItem, 45);
            int bOtherWeapon = ITEMS_CheckItemTypeId(*ppOther, 45);
            if (bItemWeapon)
            {
                if (bOtherWeapon)
                {
                    if (GetUnitType(pUnit) == 1) return 1;
                    switch (pUnit->dwClassId)
                    {
                    case 4: return 1;
                    case 6:
                        if (ITEMS_CheckItemTypeId(pItem, 67) && ITEMS_CheckItemTypeId(*ppOther, 67)) return 1;
                        return 0;
                    default: return 0;
                    }
                }
            }
            else if (!bOtherWeapon) return 0;
            return *ppPrimary == 0;
        }
    default: return *ppPrimary == 0;
    }
}
