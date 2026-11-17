struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC8 - 0x08];
    unsigned int dwFlagEx;
};

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassCode(D2UnitStrc* pUnit, int nUnitType, int nClass, int nMode, D2InventoryStrc* pInventory, int* pWeaponClassId); // 0x0064F060

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x0064F380
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5)
{
    if (!pUnit)
    {
        return ' hth';
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;

    if (nAnimMode == -1)
    {
        nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    }

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        const int nMode = nAnimMode;
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\COMPOSIT\\Composit.cpp", 566);

        if (!a5)
        {
            nAnimMode = nMode;
        }
    }

    return COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nAnimMode, pInventory, pWeaponClassId);
}
