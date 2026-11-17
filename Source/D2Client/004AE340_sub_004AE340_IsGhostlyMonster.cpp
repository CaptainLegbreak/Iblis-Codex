struct D2UnitStrc
{
    int dwUnitType;
};

int __fastcall sub_004AC7E0_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag);                     // 0x004AC7E0

// 0x004AE340
int __fastcall sub_004AE340_IsGhostlyMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x40);
    return 0;
}
