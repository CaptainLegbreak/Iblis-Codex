struct D2UnitStrc
{
    unsigned int dwUnitType;
};

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);// 0x00625500
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit);                                                     // 0x00623C60

// 0x00645F00
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue)
{
    int nWeaponClass = 0;
    int nValue = 0;

    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 0)
    {
        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 27;
        }

        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 41;
        }

        return 0;
    }
    else
    {
        nWeaponClass = UNITS_GetWeaponClass(pUnit);
        if (nWeaponClass == 1)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 0;
        }
        else if (nWeaponClass == 7)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 157, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 158, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 31;
        }

        return -1;
    }
}
