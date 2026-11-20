#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"



struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
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
};

enum D2C_M422FingerMageAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_WALK = 5,
    STATE_TERROR = 84,
    FINGERMAGE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT = 1,
    FINGERMAGE_AI_PARAM_FLEE_LIFE_PCT = 2,
    FINGERMAGE_AI_PARAM_ESCAPE_LIFE_PCT = 3,
    FINGERMAGE_AI_PARAM_CAST_RANGE = 4,
    FINGERMAGE_AI_PARAM_FLEE_TICKS = 5,
    FINGERMAGE_AI_PARAM_APPROACH_RANGE = 6,
    FINGERMAGE_AI_PARAM_IDLE_FRAMES = 7,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005FA380
void __fastcall AITHINK_Fn070_FingerMage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    int nVel = 0;

    if (pMonStatsTxt->nVelocity > 0)
    {
        const int nExcess = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        nVel = nExcess > 0 ? nExcess : 0;
        if (nVel >= 120)
        {
            nVel = 120;
        }
    }

    if (sub_6FCF2E70(pUnit))
    {
        pAiControl->dwAiParam[0] = 0;

        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_RANGE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        ++pAiControl->dwAiParam[1];

        if (nLifePercentage > AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_FLEE_LIFE_PCT) || (int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 25 || pAiControl->dwAiParam[1] > AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_FLEE_TICKS))
        {
            pAiControl->dwAiParam[0] = 0;
        }
        else if (nDistance < 14)
        {
            AITACTICS_SetVelocity(pUnit, 0, nVel, 0);
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, 14, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if (!AIGENERAL_GetMinionOwner(pUnit) && nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_ESCAPE_LIFE_PCT))
    {
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;
        sub_005DEFE0_Escape(pGame, pUnit, pTarget, 9, 0);
        return;
    }

    if (bCombat)
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        sub_005DF7D0(pGame, pUnit, pTarget, MONMODE_WALK, 0);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_RANGE))
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (STATES_CheckState(pTarget, STATE_TERROR))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_IDLE_FRAMES));
        return;
    }

    if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_APPROACH_RANGE))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}
