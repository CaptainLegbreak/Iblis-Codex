// build: ob1

enum D2C_ItemStats
{
    STAT_HITPOINTS = 6,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_DAMAGEPERCENT = 25,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_MAGICMINDAM = 52,
    STAT_MAGICMAXDAM = 53,
    STAT_COLDMINDAM = 54,
    STAT_COLDMAXDAM = 55,
    STAT_COLDLENGTH = 56,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
    STAT_LIFEDRAINMINDAM = 60,
    STAT_MANADRAINMINDAM = 62,
    STAT_STAMDRAINMINDAM = 64,
    STAT_STUNLENGTH = 66,
    STAT_SKILL_BYPASS_UNDEAD = 103,
    STAT_SKILL_BYPASS_DEMONS = 104,
    STAT_SKILL_BYPASS_BEASTS = 106,
    STAT_ITEM_DEMONDAMAGE_PERCENT = 121,
    STAT_ITEM_UNDEADDAMAGE_PERCENT = 122,
    STAT_ITEM_DEADLYSTRIKE = 141,
    STAT_DAMAGE_VS_MONTYPE = 180,
    STAT_POISON_COUNT = 326,
    STAT_PASSIVE_FIRE_MASTERY = 329,
    STAT_PASSIVE_LTNG_MASTERY = 330,
    STAT_PASSIVE_COLD_MASTERY = 331,
    STAT_PASSIVE_POIS_MASTERY = 332,
    STAT_FIRELENGTH = 315,
    STAT_BURNINGMIN = 316,
    STAT_BURNINGMAX = 317,
    STAT_PASSIVE_MAG_MASTERY = 357,
};

enum D2C_DamageFlags
{
    DAMAGEHITFLAG_BYPASSUNDEAD = 0x100,
    DAMAGEHITFLAG_BYPASSDEMON = 0x200,
    DAMAGEHITFLAG_BYPASSBEASTS = 0x400,
    DAMAGERESULTFLAG_CRITICALSTRIKE = 0x2000,
};

struct D2SeedStrc
{
    unsigned int lSeed;
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
struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
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
    int unk0x48[10];
};

struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short nMonType;
    char unk0x1E[0x18A];
};

struct D2MissilesTxt
{
    char unk0x00[0x36];
    short wProgOverlay;
    char unk0x38[0x14];
    int dwHitPar[2];
    char unk0x54[0x150];
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[2];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xE0];
    D2MissilesTxt* pMissilesCode;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                       // 0x0063E940
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2);                                         // 0x0057A830
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId);                                   // 0x0064B0C0
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesCode[nMissileId];
    }
    return 0;
}

static __forceinline D2MissilesTxt* GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        return GetMissilesTxtRecord(pMissile->dwClassId);
    }
    return 0;
}

static int __stdcall MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int nMinDamStat, int nMaxDamStat, int nMasteryStat); // 0x005A8910
// 0x005A8910
static int __stdcall MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int nMinDamStat, int nMaxDamStat, int nMasteryStat)
{
    int nMaxDam = STATLIST_UnitGetStatValue(pUnit, nMaxDamStat, 0);
    if (nMaxDam <= 0)
    {
        return 0;
    }

    int nMinDam = STATLIST_UnitGetStatValue(pUnit, nMinDamStat, 0);
    if (nMinDam <= 0)
    {
        return 0;
    }

    if (nMinDam > nMaxDam)
    {
        const int nTemp = nMinDam;
        nMinDam = nMaxDam;
        nMaxDam = nTemp;
    }

    if (nMasteryStat != -1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, nMasteryStat, 0);
        if (nMastery)
        {
            nMinDam += DATATBLS_ApplyRatio(nMinDam, nMastery, 100);
            nMaxDam += DATATBLS_ApplyRatio(nMaxDam, nMastery, 100);
        }
    }

    return nMinDam + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDam - nMinDam);
}

// 0x005A8C70
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (!pAttacker)
    {
        return 0;
    }

    switch (MISSILE_GetElemTypeFromMissileId(!pAttacker ? -1 : pAttacker->dwClassId))
    {
    case 0:
    {
        pDamage->dwPhysDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MINDAMAGE, STAT_MAXDAMAGE, -1);

        if (pDefender)
        {
            int nDamagePercent = STATLIST_UnitGetStatValue(pAttacker, STAT_DAMAGEPERCENT, 0);
            if (MONSTERS_IsDemon(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
            }

            if (MONSTERS_IsUndead(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
            }

            if (nDamagePercent <= -90)
            {
                nDamagePercent = -90;
            }

            int nPhysicalBase = pDamage->dwPhysDamage;
            nDamagePercent = nPhysicalBase * nDamagePercent / 100;
            nDamagePercent += nPhysicalBase;
            pDamage->dwPhysDamage = nDamagePercent;
        }

        if (STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEADLYSTRIKE, 0))
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->wResultFlags |= DAMAGERESULTFLAG_CRITICALSTRIKE;
        }

        return pDamage->dwPhysDamage;
    }
    case 1:
    {
        pDamage->dwFireDamage = MISSMODE_RollDamageValue(pAttacker, STAT_FIREMINDAM, STAT_FIREMAXDAM, STAT_PASSIVE_FIRE_MASTERY);
        return pDamage->dwFireDamage;
    }
    case 2:
    {
        pDamage->dwLtngDamage = MISSMODE_RollDamageValue(pAttacker, STAT_LIGHTMINDAM, STAT_LIGHTMAXDAM, STAT_PASSIVE_LTNG_MASTERY);
        return pDamage->dwLtngDamage;
    }
    case 3:
    {
        pDamage->dwMagDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MAGICMINDAM, STAT_MAGICMAXDAM, STAT_PASSIVE_MAG_MASTERY);
        return pDamage->dwMagDamage;
    }
    case 4:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_COLDMAXDAM, STAT_PASSIVE_COLD_MASTERY);
        pDamage->dwColdLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    case 5:
    {
        pDamage->dwPoisDamage = MISSMODE_RollDamageValue(pAttacker, STAT_POISONMINDAM, STAT_POISONMAXDAM, STAT_PASSIVE_POIS_MASTERY);
        pDamage->dwPoisLen = STATLIST_UnitGetStatValue(pAttacker, STAT_POISONLENGTH, 0);

        const int nPoisonCount = STATLIST_UnitGetStatValue(pAttacker, STAT_POISON_COUNT, 0);
        if (nPoisonCount > 1)
        {
            pDamage->dwPoisLen /= nPoisonCount;
        }
        return 25 * pDamage->dwPoisDamage;
    }
    case 6:
    {
        pDamage->dwLifeLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_LIFEDRAINMINDAM, 0);
        return 0;
    }
    case 7:
    {
        pDamage->dwManaLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_MANADRAINMINDAM, 0);
        return 0;
    }
    case 8:
    {
        pDamage->dwStamLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_STAMDRAINMINDAM, 0);
        return 0;
    }
    case 9:
    {
        pDamage->dwStunLen = STATLIST_UnitGetStatValue(pAttacker, STAT_STUNLENGTH, 0);
        return 0;
    }
    case 11:
    {
        pDamage->dwBurnDamage = MISSMODE_RollDamageValue(pAttacker, STAT_BURNINGMIN, STAT_BURNINGMAX, STAT_PASSIVE_FIRE_MASTERY);
        pDamage->dwBurnLen = STATLIST_UnitGetStatValue(pAttacker, STAT_FIRELENGTH, 0);
        return 25 * pDamage->dwBurnDamage;
    }
    case 12:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_COLDMAXDAM, STAT_PASSIVE_COLD_MASTERY);
        pDamage->dwFrzLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    default:
        break;
    }

    return 0;
}
