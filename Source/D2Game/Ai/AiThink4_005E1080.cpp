#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define SKILLSFLAGINDEX_AURA 5
#define STAT_LEVEL 12
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2PantherAiCallbackArgStrc;
struct D2SkillsTxt;

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M80PantherJavelinAi
{
    PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT = 1,
    PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE = 2,
    PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT = 3,
    PANTHERJAVELIN_AI_PARAM_STALL_DURATION = 4,
    PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE = 5,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1080
void __fastcall AITHINK_Fn095_PantherJavelin(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2UnitStrc* pTargetUnit = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);

    if (nDistance < 8 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        sub_005DEFE0_Escape(pGame, pUnit, pTickTarget, 16, 1);
        return;
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE) - 6 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTickTarget, 4);
        return;
    }

    if (!pTargetUnit || nDistance >= AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE))
    {
        D2PantherAiCallbackArgStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;

        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

        if (arg.pTarget && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, arg.pTarget, 7);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int MONSTERS_GetValidMonsterId(int nMonsterId)
{
    if (nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x005E4D30
void __fastcall AITHINK_SelectHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nHirelingId, D2UnitStrc* pTarget, D2SeedStrc* pSeed)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nChance = pHirelingTxtRecord->dwDefaultChance;
    int nLevelDiff = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelDiff < 0)
    {
        nLevelDiff = 0;
    }

    int nSkillChances[6];
    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        const int nSkillId = pHirelingTxtRecord->dwSkill[i];

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        nSkillChances[i] = 0;

        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
        {
            continue;
        }

        if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
            && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            continue;
        }

        if (nSkillId == SKILL_INFERNO)
        {
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pTarget && sub_006416D0_UnitEdgeDistance(pUnit, pTarget) > SKILLS_GetSkillLevel(pUnit, pSkill, 1) / 2 + 4)
            {
                continue;
            }
        }

        nChance += pHirelingTxtRecord->dwChance[i] + nLevelDiff * pHirelingTxtRecord->dwChancePerLvl[i] / 4;
        nSkillChances[i] = nChance;
    }

    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, nChance + 1);

    if (nRoll >= pHirelingTxtRecord->dwDefaultChance)
    {
        int i = 0;
        while (nRoll > nSkillChances[i] && i < 6)
        {
            ++i;
        }

        if (i < 6)
        {
            const int nSkillId = pHirelingTxtRecord->dwSkill[i];
            if (nSkillId > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, nSkillId, -1);
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }

                AITACTICS_UseSkill(pGame, pUnit, pHirelingTxtRecord->nMode[i], nSkillId, pTarget, 0, 0);
                return;
            }
        }
    }

    switch (MONSTERS_GetValidMonsterId(nMonsterId))
    {
    case MONSTER_ROGUEHIRE:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], pTarget, 0, 0);
        return;

    case MONSTER_ACT2HIRE:
    case MONSTER_ACT3HIRE:
    case MONSTER_ACT5HIRE1:
    case MONSTER_ACT5HIRE2:
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        break;

    default:
        break;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
