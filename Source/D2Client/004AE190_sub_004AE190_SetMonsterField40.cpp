struct D2MonsterDataStrc
{
    char unk0x00[0x40];
    int dwField40;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1

static __forceinline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x004AE190
void __fastcall sub_004AE190_SetMonsterField40(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwField40 = nValue;
    }
}

// 0x004AE1B0
int __fastcall sub_004AE1B0_GetMonsterField40(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->dwField40;
}
