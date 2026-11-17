struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2);                             // 0x00645510
int __fastcall sub_004B11F0(D2UnitStrc* pUnit);                                                             // 0x004B11F0

// 0x004F3FB0
D2UnitStrc* __fastcall sub_004F3FB0_GetTargetMonster(D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != 1)
    {
        return 0;
    }
    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
    return sub_004B11F0(pTarget) ? pTarget : 0;
}
