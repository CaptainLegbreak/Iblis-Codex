#define UNIT_MONSTER 1
#define UNIT_INVALID 6

struct D2UnitStrc;

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

struct D2MonStatsTxt
{
    char unk0x00[0xA0];
    unsigned char nDrain[3];
};

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
    char unk0x04[0x2C];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

static __forceinline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonstatsTxt;
    }

    return 0;
}

// 0x00573140
int __fastcall sub_6FC61F20(D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    if (!pNpc)
    {
        return 0;
    }

    const int nUnitType = pNpc ? pNpc->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pNpc);
    if (!pMonsterData)
    {
        return 0;
    }

    if (!pMonsterData->pMonInteract)
    {
        return 0;
    }

    for (D2InteractInfoStrc* pInteractInfo = pMonsterData->pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            return pInteractInfo->nInteract >= 1;
        }
    }

    return 1;
}

// 0x0057C3E0
int __fastcall sub_0057C3E0_GetMonsterDrain(D2UnitStrc* pUnit, int nUnused, D2GameStrc* pGame)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 100;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecordFromUnitInline(pUnit);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
}
