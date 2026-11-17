#define UNIT_MONSTER 1

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    int dwOwnerGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

static __forceinline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x004AE130
int __fastcall sub_004AE130(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->dwOwnerGUID;
}
