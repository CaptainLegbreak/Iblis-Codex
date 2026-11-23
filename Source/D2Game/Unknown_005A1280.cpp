#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"




#define UNIT_MONSTER 1

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit);                                                             // 0x00463860
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId);                                              // 0x00463900

// 0x005A0D20
static void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercentage)
{
    int nHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nBonus;
    if (nHitpoints > 0x100000)
    {
        if (100 > (nHitpoints >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nPercentage * (nHitpoints / 100);
        }
    }
    else if (nPercentage > 0x10000)
    {
        if (100 > (nPercentage >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nHitpoints * (nPercentage / 100);
        }
    }
    else
    {
        nBonus = nPercentage * nHitpoints / 100;
    }

    nHitpoints += nBonus;
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
}

// 0x005A1280
void __fastcall sub_005A1280_UModChampion(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame || !bUnique)
    {
        return;
    }

    sub_005A0D20_AddLifePercent(pUnit, -75);

    int nDamage = 300;
    int nToHit = nDamage;
    D2DifficultyLevelsTxt* pRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pRecord)
    {
        nDamage = pRecord->dwChampionDmgBonus * 300 / 100;
        nToHit = nDamage;
        if (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) == 0x76)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_DAMAGEPERCENT, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHit, 0);
}
