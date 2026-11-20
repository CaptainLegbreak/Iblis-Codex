#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SKILL_AMPLIFYDAMAGE 66
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_LEVEL 12
#define UNIT_MONSTER 1
#define MONMODE_DEATH 0
struct D2MonUModTxt;
struct D2DifficultyLevelsTxt;
struct D2MonStatsTxt;
struct D2CurseStrc;
struct D2SkillsTxt;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsInitStrc;
struct D2ModeChangeStrc;




struct D2MonUModTxt
{
    char unk0x00[0x1C];
    int dwConstant;
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x34];
    int dwChampionDmgBonus;
    unsigned char unk_38[0x4];
    int nMonsterCEDamagePercent;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0


typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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


int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150


struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0


D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __fastcall MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused); // 0x005A2CC0

static __forceinline int sub_A17E0_GetUModConstant(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nUMod];
    if (!pMonUModTxtRecord)
    {
        return 0;
    }
    return pMonUModTxtRecord->dwConstant;
}

// 0x005A17E0
void __fastcall sub_005A17E0_UModDamageBonus(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    int nDamage;
    int nToHit;
    if (bUnique)
    {
        nDamage = sub_A17E0_GetUModConstant(15);
        nToHit = sub_A17E0_GetUModConstant(13);
    }
    else
    {
        nDamage = sub_A17E0_GetUModConstant(14);
        nToHit = sub_A17E0_GetUModConstant(12);
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = nDamage * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHit = nToHit * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;

        const int nMonsterId = sub_00463860_GetMonsterId(pUnit);
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount && nMonsterId == 0x76)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, 0x19, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, 0x77, nToHit, 0);
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005A1910
void __fastcall sub_005A1910_ApplyVelocity(D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nVelocity > 0)
        {
            const int nValue = 0x800 / pMonStatsTxtRecord->nVelocity - 0x80;
            STATLIST_AddUnitStat(pUnit, 0x43, D2_MIN(D2_MAX(nValue, 10), 100), 0);
        }
    }
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005A23D0
void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel)
{
    if (!sub_00554200(pGame, pUnit, pTarget))
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_AMPLIFYDAMAGE);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2CurseStrc curse = {};

    curse.pTarget = pTarget;
    curse.pUnit = pUnit;
    curse.nSkill = SKILL_AMPLIFYDAMAGE;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, SKILL_AMPLIFYDAMAGE, nSkillLevel);
    curse.nStat = pSkillsTxtRecord->wAuraStat[0];
    curse.nStatValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], SKILL_AMPLIFYDAMAGE, nSkillLevel);
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = 0;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], SKILL_AMPLIFYDAMAGE, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
            }
        }
    }
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor <= (nMultiplier >> 4))
        {
            return nValue * (nMultiplier / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x005A2620
void __fastcall sub_005A2620_CastExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    D2UnitStrc* pMissile = sub_6FD11420(pGame, 117, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile) return;
    int nGameType;
    if (pGame->nGameType || pGame->dwGameType) nGameType = 1;
    else nGameType = 0;
    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    const int nMonsterId = pUnit->dwClassId;
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, 12, 0), 1, &monStatsInit);
    D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (!pDifficulty) return;
    int nDamage = DATATBLS_ApplyRatio(monStatsInit.nMaxHP, pDifficulty->nMonsterCEDamagePercent, 100);
    if (pGame->nDifficulty == 0) nDamage += nDamage / -4;
    else if (pGame->nDifficulty == 1) nDamage += nDamage / -3;
    else if (pGame->nDifficulty == 2) nDamage /= 8;
    const int nMinDamage = ApplyRatio_Inline(nDamage, 60, 100);
    const int nRoll = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nDamage - nMinDamage) + nMinDamage;
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwPhysDamage = nRoll << 6;
    damage.dwFireDamage = nRoll << 6;
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pGame->nDifficulty + 4, &damage, 0, 0, 0, 0x581);
}

// 0x005A2D10
void __fastcall MONSTERUNIQUE_KillMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return;
    }

    AIGENERAL_ExecuteCallbackOnMinions(pUnit, pGame, 0, MONSTERUNIQUE_MinionCallback_KillMinion);
    AIGENERAL_SetOwnerData(pGame, pOwner, -1, UNIT_MONSTER, 0, 0);
    if (pOwner == pUnit || pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pOwner, MONMODE_DEATH, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}
