#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
struct D2UnitStrc;




struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[2];
};



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

enum D2C_M86CorruptLancerAi
{
    MONMODE_ATTACK1 = 4,
    CORRUPTLANCER_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    CORRUPTLANCER_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    CORRUPTLANCER_AI_PARAM_STALL_DURATION = 2,
    CORRUPTLANCER_AI_PARAM_RUN_CHANCE_PCT = 3,
    CORRUPTLANCER_AI_PARAM_ALWAYS_RUN_DISTANCE = 4,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_1_CHANCE_PCT = 5,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_2_CHANCE_PCT = 6,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_3_CHANCE_PCT = 7,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEFB0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                     // 0x00649070

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F5D50
void __fastcall AITHINK_Fn036_CorruptLancer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiTickParam->nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_ALWAYS_RUN_DISTANCE))
    {
        PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
        sub_005DE190_SetAiParam(pUnit, 13, 100, 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, pAiTickParam->pMonstats2Txt->nSteps);
        pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (bCombat)
    {
        if (!pAiControl->dwAiParam[0] && !((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_ATTACK_CHANCE_PCT)))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_STALL_DURATION));
            return;
        }

        pAiControl->dwAiParam[0] = 0;

        if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_1_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        }
        else if (pMonStatsTxt->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_2_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        }
        else if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_3_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_RUN_CHANCE_PCT))
        {
            sub_005DE190_SetAiParam(pUnit, 13, 100, 0);
            AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, pAiTickParam->pMonstats2Txt->nSteps);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_STALL_DURATION));
}
