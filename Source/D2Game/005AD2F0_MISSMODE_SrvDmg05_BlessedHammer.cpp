struct D2GameStrc;
struct D2DamageStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char unk0x00[0x78];
    int dwDmgParam[2];
    char unk0x80[0x124];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                       // 0x0063E940

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AD2F0
void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nBaseDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    if (pMissilesTxtRecord->dwDmgParam[0] > 0 && MONSTERS_IsUndead(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[0], 100));
    }

    if (pMissilesTxtRecord->dwDmgParam[1] > 0 && MONSTERS_IsDemon(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[1], 100));
    }
}
