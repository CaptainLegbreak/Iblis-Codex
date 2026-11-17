struct D2MonsterDataStrc
{
    char unk0x00[0x14];
    short wField14;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

// 0x004AC730
D2MonsterDataStrc* __fastcall sub_004AC730_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return pUnit->pMonsterData;
    return 0;
}

// 0x004AC760
short __fastcall sub_004AC760_GetMonsterDataWord14(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_004AC730_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wField14;
}
