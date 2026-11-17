struct D2GameStrc;
struct D2StatListStrc;
struct D2MonStatsTxt;
struct Unit005A0180;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    unsigned int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
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
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);       // 0x00627260
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues);                        // 0x005BFDA0
extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask);                         // 0x005A0180
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __fastcall MONSTER_GetHpBonus(int nPlayerCount);                                                         // 0x005738F0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused);                              // 0x00621E40
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster);                     // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling);                                             // 0x0063EE90
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BFE60
int __fastcall SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    const int nValues[] = { 9, 18, 27, 36, 45 };
    int nHpRegen = SKILLITEM_CalculateOpenWoundsHpRegen(nLevel, nValues) + 40;
    if (pUnit->dwUnitType == 0)
    {
        nHpRegen /= 4;
        if (nEvent == 6)
        {
            nHpRegen /= 2;
        }
    }
    else if (pUnit->dwUnitType == 1 && sub_005A0180((Unit005A0180*)pUnit, 0x0C))
    {
        nHpRegen /= 2;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 200;
    curse.nStat = 74;
    curse.nStatValue = -nHpRegen;
    curse.nState = 62;
    sub_0056E970(&curse);
    return 1;
}

// 0x005BFFC0
int __fastcall SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nDivisor = 4;
    if (pUnit->dwUnitType == 0)
    {
        nDivisor = 10;
    }
    else if (pUnit->dwUnitType == 1)
    {
        if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            nDivisor = 10;
        }
        else
        {
            if (MONSTERS_IsBoss(0, pUnit) || sub_005A0180((Unit005A0180*)pUnit, 2))
            {
                nDivisor = 8;
            }

            int nPlayerCount = STATLIST_UnitGetStatValue(pUnit, 100, 0);
            if (nPlayerCount < 1)
            {
                nPlayerCount = 1;
            }

            const int nHpBonus = MONSTER_GetHpBonus(nPlayerCount);
            if (nHpBonus)
            {
                nDivisor += DATATBLS_ApplyRatio(nDivisor, nHpBonus, 100);
            }
        }
    }

    if (nEvent == 6)
    {
        nDivisor *= 2;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    int nCrushingBlowHp = nHitpoints / nDivisor;

    int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
    if (nDamageResist >= 100)
    {
        nDamageResist = 100;
    }

    if (nDamageResist > 0)
    {
        nCrushingBlowHp -= DATATBLS_ApplyRatio(nCrushingBlowHp, nDamageResist, 100);
    }

    int nNewHp = nHitpoints - nCrushingBlowHp;
    nNewHp = nNewHp > 0 ? nNewHp : 0;
    STATLIST_SetUnitStat(pUnit, 6, nNewHp, 0);

    if (nNewHp <= 0 && pDamage)
    {
        pDamage->wResultFlags |= 2;
    }

    if (nCrushingBlowHp > 0)
    {
        UNITS_SetOverlay(pUnit, 147, 0);
    }

    return 1;
}
