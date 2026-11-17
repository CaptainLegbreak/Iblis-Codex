#define UNIT_MONSTER 1
#define UNIT_INVALID 6

struct D2MonsterDataStrc
{
    char unk0x00[0x34];
    int unk0x34;
    int unk0x38;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->unk0x38;
        }
    }

    return 0;
}

// 0x00573100
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->unk0x34;
        }
    }

    return 0;
}

// 0x00573120
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            pMonsterData->unk0x38 = 0;
            pMonsterData->unk0x34 = 0;
        }
    }
}
