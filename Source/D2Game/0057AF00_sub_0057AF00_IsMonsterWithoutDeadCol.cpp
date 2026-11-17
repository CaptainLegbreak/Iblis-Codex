#define UNIT_MONSTER 1
#define MONSTATS2FLAGINDEX_DEADCOL_0057AF00 0x13

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                    // 0x004638A0

// 0x0057AF00
static __declspec(noinline) int sub_0057AF00_IsMonsterWithoutDeadCol(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return !sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_DEADCOL_0057AF00);
}

int __fastcall sub_M424_Emit_0057AF00(D2UnitStrc* pUnit, int nBias)
{
    return sub_0057AF00_IsMonsterWithoutDeadCol(pUnit) + nBias;
}
