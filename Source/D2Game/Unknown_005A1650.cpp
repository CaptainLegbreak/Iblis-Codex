#include "D2SkillIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
union D2SeedStrc;
struct D2MonsterDataStrc;
struct D2AuraEnchantStrc;
struct D2MissilesTxt;
struct D2MonLvlTxt;
struct D2MonUModTxt;

struct D2AuraEnchantStrc
{
    int nLevel;
    int nLevelAdd;
    int nMul;
    int nDiv;
    int nSkillId;
};

extern D2AuraEnchantStrc gAuraEnchantTable_0073BF68[8]; // 0x0073BF68
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

enum D2C_H16ElemConstants
{
    MONLVL_DM = 6,
    STAT_LEVEL = 12,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

// 0x005A01E0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return -1;
    }
    return pMonsterData->wBossHcIdx;
}

// 0x005A1650
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1 || !bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 0)
    {
        nLevel = 1;
    }

    int nCount = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (gAuraEnchantTable_0073BF68[i].nLevel <= nLevel)
        {
            ++nCount;
        }
    }

    if (!nCount)
    {
        nCount = 1;
    }

    const unsigned short wNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, wNameSeed);
    int nIndex = SEED_RollLimitedRandomNumber(&tSeed, nCount);
    if (MONSTERUNIQUE_GetBossHcIdx(pUnit) == 37)
    {
        nIndex = 5;
    }

    if (pUnit->dwClassId == 0x2C0)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_CONVICTION, 20, 1);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_CONVICTION, -1);
        return;
    }

    int nSkillLevel = (gAuraEnchantTable_0073BF68[nIndex].nLevelAdd + nLevel) * gAuraEnchantTable_0073BF68[nIndex].nMul / gAuraEnchantTable_0073BF68[nIndex].nDiv;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 99);

    D2GAME_SetSkills_6FD14C60(pUnit, gAuraEnchantTable_0073BF68[nIndex].nSkillId, nSkillLevel, 1);
    D2GAME_AssignSkill_6FD13800(pUnit, 0, gAuraEnchantTable_0073BF68[nIndex].nSkillId, -1);
}

#include "gen/data/Source/D2Game/Unknown_005A1650.inc"
#include "D2Txt.h"
#include "D2TxtTables.h"

static __forceinline D2MissilesTxt* MONUNIQUE_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static __forceinline D2MonLvlTxt* MONUNIQUE_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
        return &sgptDataTables->pMonLvlTxt[nLevel];
    return 0;
}

static __forceinline int MONUNIQUE_GetMonUModConstant_Inline(int nIndex)
{
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonUModTxtRecordCount)
        return 0;
    D2MonUModTxt* pRecord = &sgptDataTables->pMonUModTxt[nIndex];
    if (!pRecord)
        return (int)pRecord;
    return pRecord->dwConstants;
}

static __forceinline unsigned int MONUNIQUE_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005A21D0
static void __stdcall sub_005A21D0_ApplyElementalDamageStats(D2UnitStrc* pUnit, int nMinDamageStatId, int nMaxDamageStatId, int nLengthStatId, D2GameStrc* pGame)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = MONUNIQUE_GetMissilesTxtRecord_Inline(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[1] & gdwBitMasks[5])
            return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = MONUNIQUE_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
        return;

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    const int nMinDamage = MONUNIQUE_GetMonUModConstant_Inline(28) * nDamage / 100;
    const int nMaxDamage = MONUNIQUE_GetMonUModConstant_Inline(31) * nDamage / 100;

    D2StatListStrc* pStatList = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetStat(pStatList, nMaxDamageStatId, nMaxDamage, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, nMaxDamage, 0);
    }

    if (nLengthStatId == -1)
        return;

    const int nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetStat(pStatList, nLengthStatId, nLength, 0);
    else
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
}

void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
        return;

    const unsigned int nRand = MONUNIQUE_RollSeed_Inline(&pUnit->pSeed) % 5;
    sub_005A21D0_ApplyElementalDamageStats(pUnit, gnUniqueElementalStats_006E21B8[nRand][0], gnUniqueElementalStats_006E21B8[nRand][1], gnUniqueElementalStats_006E21B8[nRand][2], pGame);
}
