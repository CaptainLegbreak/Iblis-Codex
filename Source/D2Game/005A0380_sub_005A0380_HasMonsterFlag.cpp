struct D2MonsterDataStrc
{
    unsigned char unk_00[0x1C];
    unsigned char unk_1C;
};
struct D2UnitStrc
{
    int dwUnitType;
    unsigned char dwClassId[0x10];
    D2MonsterDataStrc* pMonsterData;
};

static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005A0380
int __fastcall sub_005A0380_HasMonsterFlag(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = 0;
    if (GetUnitType(pUnit) == 1)
    {
        pMonsterData = pUnit->pMonsterData;
    }
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->unk_1C != 0;
}
