struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2GameStrc;
struct D2SkillStrc;

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short wMonType;
};

#define D2MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, void* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit);                                                          // 0x006223F0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2);                                         // 0x0057A830
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_005347B0_Stub5(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nChance, int nRand); // 0x005347B0
void* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                                         // 0x0056E970
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                       // 0x0063E940
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990

// build: symbol ?SUNITDMG_PreventMonsterHeal@@YAXPAUD2UnitStrc@@0@Z 0x0057D810
static void SUNITDMG_PreventMonsterHeal(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (pAttacker && pAttacker->dwUnitType == 0 && (pDefender ? pDefender->dwUnitType : 6) == 1 && STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 117, 0))
    {
        if (pDefender->dwClassId >= 704 && pDefender->dwClassId <= 709)
        {
            return;
        }

        D2CurseStrc curse = {};
        curse.pUnit = pAttacker;
        curse.pTarget = pDefender;
        curse.nSkill = 0;
        curse.nSkillLevel = 1;
        curse.nDuration = 120000;
        curse.nStat = 31;
        curse.nStatValue = 0;
        curse.nState = 52;
        sub_0056E970(&curse);
    }
}

static void __stdcall sub_0057D8A0_ApplyTargetDefenseModifiers(int* pAttackRate, int* pDefense, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 115, 0) && pDefender && pDefender->dwUnitType == 1
        && !MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 10) && !MONSTERS_IsBoss(0, pDefender) && !MONSTERS_GetHirelingTypeId(pDefender))
    {
        *pDefense = 0;
    }

    int nFractionalTargetAc = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 116, 0);
    if (nFractionalTargetAc > 0)
    {
        if (pDefender && (pDefender->dwUnitType == 0 || pDefender->dwUnitType == 1
            && (MONSTERS_IsBoss(0, pDefender) || MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2) || MONSTERS_GetHirelingTypeId(pDefender))))
        {
            nFractionalTargetAc /= 2;
        }

        nFractionalTargetAc = D2MIN(D2MAX(nFractionalTargetAc, 0), 100);

        const int nDefense = *pDefense;
        *pDefense = nDefense - DATATBLS_ApplyRatio(nDefense, nFractionalTargetAc, 100);
    }

    const int nDemonToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 123, 0);
    if (nDemonToHit && MONSTERS_IsDemon(pDefender))
    {
        *pAttackRate += nDemonToHit;
    }

    const int nUndeadToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 124, 0);
    if (nUndeadToHit && MONSTERS_IsUndead(pDefender))
    {
        *pAttackRate += nUndeadToHit;
    }
}

static inline int I13_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static inline D2MonStatsTxt* I13_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x0057D9B0
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, 12, 0);
    int nTotalDefense = UNITS_GetDefense(pDefender);
    if (bMissile)
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 32, 0);
    }
    else
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 33, 0);
    }
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);

    int nAttackRate = 0;
    int nToHitPercent = 0;
    const int nAttackerType = I13_GetUnitType(pAttacker);
    if (nAttackerType == 0)
    {
        nAttackRate = UNITS_GetAttackRate(pAttacker);
        sub_0057D8A0_ApplyTargetDefenseModifiers(&nAttackRate, &nTotalDefense, pDefender, pAttacker);

        if (!bMissile)
        {
            D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
            if (pWeapon)
            {
                nToHitPercent = SKILLS_GetWeaponMasteryBonus(pAttacker, pWeapon, 0, 0);
            }
        }

        nToHitPercent += nStatValue + STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);

        {
            D2MonStatsTxt* pMonStatsTxtRecord = I13_GetMonStatsTxtRecord(pDefender);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType > 0)
            {
                const int nMonType = pMonStatsTxtRecord->wMonType;
                D2StatStrc stats[128];
                const int nStats = STATLIST_CopyStats(pAttacker, 179, stats, 128);
                for (int i = 0; i < nStats; ++i)
                {
                    if (SUNITDMG_CheckMonType(stats[i].nLayer, nMonType))
                    {
                        nToHitPercent += stats[i].nValue;
                    }
                }
            }
        }
    }

    else
    {
        nAttackRate = STATLIST_UnitGetStatValue(pAttacker, 19, 0);
        nAttackRate += nStatValue + 5 * STATLIST_UnitGetStatValue(pAttacker, 2, 0);
        nToHitPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);
    }

    nAttackRate += DATATBLS_ApplyRatio(nAttackRate, nToHitPercent, 100);
    if (nTotalDefense < 0)
    {
        nAttackRate -= nTotalDefense;
        nTotalDefense = 0;
    }

    if (nAttackRate < 0)
    {
        nTotalDefense -= nAttackRate;
        nAttackRate = 0;
    }

    if (nTotalDefense < 0)
    {
        nTotalDefense = 0;
    }

    const int nDivisor = nAttackRate + nTotalDefense;
    int nToHitFactor = 100;
    if (nDivisor)
    {
        nToHitFactor = 100 * nAttackRate / nDivisor;
    }

    int nChanceToHit = 2 * nAttackerLevel * nToHitFactor / (nDefenderLevel + nAttackerLevel);
    nChanceToHit = D2MIN(D2MAX(nChanceToHit, 5), 95);

    D2SeedStrc* pSeed = &pAttacker->pSeed;
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    const int nRand = (unsigned int)lSeed % 100;

    sub_005347B0_Stub5(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nChanceToHit, nRand);
    if (nRand < nChanceToHit)
    {
        SUNITDMG_PreventMonsterHeal(pAttacker, pDefender);
        return 1;
    }

    return 0;
}
