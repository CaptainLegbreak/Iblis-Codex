struct D2MonsterDataStrc
{
    char unk_00[0x16];
    unsigned short nTypeFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

extern "C" __int64 __stdcall _alldiv(__int64 a, __int64 b); // 0x00684240

enum { UNIT_MONSTER = 1, STAT_HITPOINTS = 6, STAT_MAXHP = 7, MONTYPEFLAG_POSSESSED = 0x20 };

int __fastcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
void __fastcall MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A0E80

static __forceinline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return pUnit->pMonsterData;
    return 0;
}

static __forceinline int MONSTERUNIQUE_ApplyPercentage(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
        return 0;
    if (nValue <= 0x100000)
    {
        if (nMultiplier <= 0x10000)
            return (int)((unsigned int)nMultiplier * (unsigned int)nValue) / nDivisor;
        if (nDivisor <= (nMultiplier >> 4))
            return (int)((unsigned int)nValue * (unsigned int)(nMultiplier / nDivisor));
    }
    else if (nDivisor <= (nValue >> 4))
    {
        return (int)((unsigned int)nMultiplier * (unsigned int)(nValue / nDivisor));
    }
    return (int)(nMultiplier * (__int64)nValue / nDivisor);
}

static __declspec(noinline) void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercent);

// build: context sub_005A0D20_AddLifePercent
static void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercent)
{
    int nHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    nHitpoints += MONSTERUNIQUE_ApplyPercentage(nHitpoints, nPercent, 100);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
}

// 0x005A1230
void __fastcall MONSTERUNIQUE_UMod38_Possessed(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (!pUnit || nUnitType != UNIT_MONSTER || !bUnique)
        return;

    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterData(pUnit);
    if (pMonsterData)
        pMonsterData->nTypeFlag |= MONTYPEFLAG_POSSESSED;

    sub_005A0D20_AddLifePercent(pUnit, 100);
    MONSTERUNIQUE_UMod16_Champion(pUnit, nUMod, bUnique);
}
