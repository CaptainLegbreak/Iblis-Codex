struct D2UnitStrc { unsigned int dwUnitType; unsigned int dwClassId; };
static __forceinline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}
static __forceinline int GetUnitClass(D2UnitStrc* unit)
{
    return !unit ? -1 : unit->dwClassId;
}

// 0x004F0F10
int __fastcall sub_004F0F10_IsTargetObject(D2UnitStrc* unit, void* unused)
{
    if (GetUnitType(unit) != 3)
        return 0;
    return GetUnitClass(unit) == 468;
}
