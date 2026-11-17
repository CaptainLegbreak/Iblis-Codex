struct D2DamageStrc
{
    char unk0x00[0x70];
};

struct D2CombatStrc
{
    char unk0x00[0x04];
    int dwAttackerType;
    int dwAttackerId;
    int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xA4];
    D2CombatStrc* pCombat;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2MonStatsTxt
{
    char unk0x000[0x168];
    signed char nColdEffect[3];
    char unk0x16B[0x3D];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1BC];
    int nMonTypeTxtRecordCount;
    unsigned int* pMonTypeNest;
    int nMonTypeIndex;
};

#define UNIT_MONSTER 1

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0057A830
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 31];
    }

    return 0;
}

// 0x0057AF30
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return -50;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return -50;
    }

    return pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty];
}

// 0x0057D690
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return 0;
    }

    for (D2CombatStrc* pCombat = pAttacker->pCombat; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == sub_0044BE50_GetUnitTypeOrInvalid(pAttacker) && pCombat->dwAttackerId == sub_00451F50_GetUnitGUID(pAttacker)
            && pCombat->dwDefenderType == sub_0044BE50_GetUnitTypeOrInvalid(pDefender) && pCombat->dwDefenderId == sub_00451F50_GetUnitGUID(pDefender))
        {
            return &pCombat->tDamage;
        }
    }

    return 0;
}
