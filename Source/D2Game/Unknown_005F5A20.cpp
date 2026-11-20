#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"





struct D2MonStats2Txt;

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
    D2MonStats2Txt* pMonstats2Txt;
};

enum D2C_M408CorruptArcherAi
{
    MONMODE_ATTACK1 = 4,
    CORRUPTARCHER_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    CORRUPTARCHER_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    CORRUPTARCHER_AI_PARAM_STALL_DURATION = 2,
    CORRUPTARCHER_AI_PARAM_RUN_CHANCE_PCT = 3,
    CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE = 4,
    CORRUPTARCHER_AI_PARAM_USE_SKILL_2_CHANCE_PCT = 5,
    CORRUPTARCHER_AI_PARAM_USE_SKILL_3_CHANCE_PCT = 6,
    CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE = 7,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEFB0
int __fastcall sub_6FCD06D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005F5A20
void __fastcall AITHINK_Fn035_CorruptArcher(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
    if (!pTarget)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < 50)
        {
            sub_005DF7D0(pGame, pUnit, pTickTarget, 3, 0);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (!bCombat && sub_6FCF2E70(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (nDistance < 6 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_RUN_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 0, 100, 0);
        if (sub_6FCD06D0(pGame, pUnit, pTarget, 12, 1))
        {
            return;
        }
    }

    if (AI_GetParam(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE) > 0 && nDistance > AI_GetParam(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE)
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 0, 10, 0);
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE));
        return;
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE))
    {
        AITACTICS_SetVelocity(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE));
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_USE_SKILL_2_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_USE_SKILL_3_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_STALL_DURATION));
}
