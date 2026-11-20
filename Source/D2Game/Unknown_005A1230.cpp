#include "D2Game.h"

struct D2MonsterDataStrc;

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
void __fastcall sub_005A0E80_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A0E80
static __declspec(noinline) void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercent);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

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
    sub_005A0E80_ApplyMonsterPenalty(pUnit, nUMod, bUnique);
}

// 0x005A1370
int __fastcall MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, 31, 0);
            STATLIST_SetUnitStat(pUnit, 31, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, 39, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, 41, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, 43, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, 45, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, 37, 0);

        if (nFireResist >= 100) ++nImmunities;
        if (nLightResist >= 100) ++nImmunities;
        if (nColdResist >= 100) ++nImmunities;
        if (nPoisonResist >= 100) ++nImmunities;
        if (nDamageResist >= 100) ++nImmunities;
        if (nMagicResist >= 100) ++nImmunities;

        if (nImmunities < 2)
        {
            if (nUMod == 8)
            {
                if (nColdResist < 100)
                {
                    int nNewColdResist = nColdResist + 40;
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, 39, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, 43, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, 41, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, 45, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, 37, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, 36, nDamageResist + 50, 0);
        }
    }
}
