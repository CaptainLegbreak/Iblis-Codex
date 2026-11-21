#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define UNIT_MONSTER 1
#define MONTYPEFLAG_CHAMPION 4

struct D2GfxLightStrc;
union D2SeedStrc;
struct D2MonsterDataStrc;
struct D2MonStats2Txt;





D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit); // 0x00464930
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

static __forceinline unsigned __int64 SEED_RollLocalSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004ACC70
void __fastcall sub_004ACC70_InitMonsterLight(D2UnitStrc* pUnit, int nUnused, int bInit)
{
    if (!bInit)
    {
        return;
    }

    sub_00464930_FreeLight(pUnit);

    D2GfxLightStrc* pLight;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        D2SeedStrc seed;
        seed.nHighSeed = (unsigned int)(lSeed >> 32);
        seed.nLowSeed = (unsigned int)lSeed;
        const int nBlue = (int)lSeed;
        const int nGreen = (int)SEED_RollLocalSeed(&seed);
        const int nRed = (int)SEED_RollLocalSeed(&seed);
        pUnit->pSeed = seed;
        pLight = sub_00474160_MakeLightEntry(pUnit, 0, 7, 0xFF, nRed, nGreen, nBlue);
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }

        pLight = sub_00474160_MakeLightEntry(pUnit, 0, 7, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, sub_00474350_GetLightSize(pLight));
}

static __forceinline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

// 0x004ACD50
void __fastcall sub_004ACD50_ClearMonsterField18(D2UnitStrc* unit, void* unused, int unusedStack)
{
    if (GetUnitType(unit) == 1)
    {
        D2MonsterDataStrc* data = unit->pMonsterData;
        if (data)
            data->dwDurielFlag = 0;
    }
}

// 0x004ACDB0
int __fastcall sub_004ACDB0_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0);
            STATLIST_SetUnitStat(pUnit, STAT_ARMORCLASS, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, STAT_FIRERESIST, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTRESIST, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, STAT_COLDRESIST, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, STAT_POISONRESIST, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAGICRESIST, 0);

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
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, nDamageResist + 50, 0);
        }
    }
}
