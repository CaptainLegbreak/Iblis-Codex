struct D2MonsterDataStrc
{
    char unknown00[0x18];
    int unknown18;
};
struct D2UnitStrc
{
    int dwUnitType;
    char unknown04[0x10];
    D2MonsterDataStrc* pMonsterData;
};
static __forceinline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

// 0x004ACD50
void __fastcall sub_004ACD50_ClearMonsterField18(D2UnitStrc* unit, void* unused, int unusedStack)
{
    if (GetUnitType(unit) == 1)
    {
        D2MonsterDataStrc* data = unit->pMonsterData;
        if (data)
            data->unknown18 = 0;
    }
}
