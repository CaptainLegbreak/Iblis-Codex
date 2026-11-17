struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; };
struct D2MissilesTxt
{
    char unk0x00[0x90];
    unsigned int dwDmgCalc;
    char unk0x94[0x110];
};
struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};
struct D2DamageStrc { unsigned int dwHitFlags; unsigned short wResultFlags; unsigned short wExtra; int dwPhysDamage; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70
void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A91C0
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270
static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

// 0x005AD0F0
void __fastcall sub_005AD0F0_ConvertMissileDamage(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }
    int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwDmgCalc, -1, -1);
    if (nPercentage <= 0)
    {
        return;
    }
    nPercentage = D2_MIN(nPercentage, 100);
    int nDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercentage, 100);
    nDamage = D2_MIN(nDamage, pDamage->dwPhysDamage);
    nDamage += MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    MISSMODE_ResetDamageParams(pGame, pMissile, pDamage);
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamage);
}
