struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2MissilesTxt
{
    char unk0x00[0x36];
    short wProgOverlay;
    char unk0x38[0x40];
    int dwDmgParam[2];
    char unk0x80[0x10];
    unsigned int dwDmgCalc;
    char unk0x94[0x110];
};

struct D2SkillsTxt
{
    char unk0x000[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
};

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define UNIT_MONSTER 1
#define STAT_DAMAGEPERCENT 25
#define STAT_COLDLENGTH 56

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                            // 0x004E6CA0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);      // 0x00644F20
void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD2F0

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005AD050
void __fastcall MISSMODE_SrvDmg01_FireArrow_MagicArrow_ColdArrow(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
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

    const int nPhysDamage = pDamage->dwPhysDamage;
    int nDamageReduction = DATATBLS_ApplyRatio(nPhysDamage, nPercentage, 100);
    nDamageReduction = D2_MIN(nDamageReduction, nPhysDamage);
    pDamage->dwPhysDamage = nPhysDamage - nDamageReduction;
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamageReduction);
}

// 0x005AD1B0
void __fastcall MISSMODE_SrvDmg02_IceArrow_RoyalStrikeChaos(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const int nColdLength = STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
        pDamage->dwFrzLen = DATATBLS_ApplyRatio(nColdLength, pMissilesTxtRecord->dwDmgParam[0] < 0 ? 0 : pMissilesTxtRecord->dwDmgParam[0], 100);
        pDamage->dwColdLen = 0;
    }
}

// 0x005AD3E0
void __fastcall MISSMODE_SrvDmg07_Warcry_ShockWave(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        nStunLength = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nLevel);
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD450
void __fastcall MISSMODE_SrvDmg08_EruptionCrack(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 0);
    }
}

// 0x005AD4A0
void __fastcall MISSMODE_SrvDmg09_Twister(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        nStunLength = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1];
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD530
void __fastcall MISSMODE_SrvDmg11_RabiesContagion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nPoisonLength = MISSILE_GetTargetX(pMissile) - pGame->dwGameFrame;
    if (nPoisonLength < 10 || nPoisonLength > SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1))
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    pDamage->dwPoisLen = nPoisonLength;
}

// 0x005AD5C0
void __fastcall MISSMODE_SrvDmg13_BlessedHammerEx(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
        if (pOwner)
        {
            pDamage->dwPhysDamage += pDamage->dwPhysDamage * STATLIST_UnitGetStatValue(pOwner, STAT_DAMAGEPERCENT, 0) / 100;
        }

        MISSMODE_SrvDmg05_BlessedHammer(pGame, pMissile, pUnit, pDamage);
    }
}
