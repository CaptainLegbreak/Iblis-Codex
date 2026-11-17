struct D2UnitStrc
{
    int dwUnitType;
};

int __fastcall sub_004AC7E0_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag);                     // 0x004AC7E0

// 0x004AE320
int __fastcall sub_004AE320_IsChampionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x04);
    return 0;
}

// 0x004AE360
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x08);
    return 0;
}

// 0x004AE380
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x10);
    return 0;
}

// 0x004AE3A0
int __fastcall sub_004AE3A0_IsSuperUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x02);
    return 0;
}
