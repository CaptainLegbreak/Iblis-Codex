struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
};

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0
extern int gaFrameBonus_006E8E60[][7];                                                                      // 0x006E8E60

static inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->dwUnitType;
}

static inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

static inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->dwAnimMode;
}

// 0x00623B10
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit)
{
    int nUnitType = UNITS_GetUnitTypeInline(pUnit);
    int nClassId = UNITS_GetClassIdInline(pUnit);
    int nAnimMode = UNITS_GetAnimModeInline(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0x118A);

    if (nUnitType != 0)
        return 0;

    switch (nAnimMode)
    {
    case 7:
    case 8:
    {
        D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
        unsigned short nWeaponClass = 0;
        if (pWeapon)
            nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
        return gaFrameBonus_006E8E60[nWeaponClass][nClassId];
    }
    case 15:
    case 16:
        if (UNITS_CanDualWield(pUnit))
        {
            D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
            unsigned short nWeaponClass = 0;
            if (pWeapon)
                nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
            return gaFrameBonus_006E8E60[nWeaponClass][nClassId];
        }
        break;
    }

    return 0;
}

#include "gen/data/Source/D2Common/00623B10_UNITS_GetFrameBonus.inc"
