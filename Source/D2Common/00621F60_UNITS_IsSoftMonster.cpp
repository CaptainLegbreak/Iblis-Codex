#define UNIT_MONSTER 1
#define MONSTATS2FLAGINDEX_SOFT 0xC

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);

// 0x00621F60
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_SOFT) != 0;
}
