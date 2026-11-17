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

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
};

#define ITEMTYPE_BLUNT 57
#define STAT_ITEM_UNDEADDAMAGE_PERCENT 122

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

// 0x0057A880
static int __stdcall sub_0057A880_AddRolledDamage(D2UnitStrc* pUnit, int nMin, int nMaxPct, int nMax, int nDamage, int nMinPct)
{
    if (nMax > 0)
    {
        nMin += DATATBLS_ApplyRatio(nMin, nMinPct, 100);
        nMax += DATATBLS_ApplyRatio(nMax, nMaxPct, 100);
        nDamage += nMin;
        if (nMax > nMin)
        {
            nDamage += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin);
        }
    }

    return nDamage < 0 ? 0 : nDamage;
}

// 0x0057A8E0
static int __stdcall sub_0057A8E0_AddStatDamage(int nStatMin, int nStatPct, int nMinPct, int nMaxPct, int nDamage, int nStatMax, D2UnitStrc* pUnit)
{
    const int nMax = STATLIST_UnitGetStatValue(pUnit, nStatMax, 0) << 8;
    if (nMax < 8)
    {
        return nDamage < 0 ? 0 : nDamage;
    }

    const int nMin = STATLIST_UnitGetStatValue(pUnit, nStatMin, 0) << 8;
    if (nStatPct != -1)
    {
        const int nPct = STATLIST_UnitGetStatValue(pUnit, nStatPct, 0);
        nMinPct += nPct;
        nMaxPct += nPct;
    }

    return sub_0057A880_AddRolledDamage(pUnit, nMin, nMaxPct, nMax, nDamage, nMinPct);
}

// 0x0057B660
static void sub_0057B660_AddUndeadDamagePercent(D2DamageStrc* pDamage, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (MONSTERS_IsUndead(pDefender))
    {
        int nPct = 0;
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        if (pWeapon && ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_BLUNT))
        {
            nPct = 50;
        }

        nPct += STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
        if (nPct > 0)
        {
            pDamage->dwEnDmgPct += nPct;
        }
    }
}

// calling-convention shim (not game code)
void __stdcall sub_A08_EmitDamageHelpers(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a, int b, int c, int d, int e, int f)
{
    pDamage->dwPhysDamage = sub_0057A8E0_AddStatDamage(a, b, c, d, pDamage->dwPhysDamage, f, pAttacker);
    pDamage->dwFireDamage = sub_0057A8E0_AddStatDamage(b, c, d, e, pDamage->dwFireDamage, a, pAttacker);
    pDamage->dwEnDmgPct = sub_0057A880_AddRolledDamage(pAttacker, a, b, c, pDamage->dwEnDmgPct, d);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pAttacker, pDefender);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pDefender, pAttacker);
}
