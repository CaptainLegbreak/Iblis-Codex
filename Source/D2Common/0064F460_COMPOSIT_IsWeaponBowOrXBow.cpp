struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC8 - 0x64];
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

// 0x0064F460
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    int nMode = -1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 566);
    }

    COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nMode, pInventory, &nWeaponClassId);

    return nWeaponClassId == 1 || nWeaponClassId == 7;
}
