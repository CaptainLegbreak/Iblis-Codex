#include "D2StateIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"


int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005FD470
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

enum D2C_ClawViperAIParams
{
    CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT = 0,
    CLAWVIPER_AI_PARAM_CHARGE_DISTANCE = 1,
    CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    CLAWVIPER_AI_PARAM_STALL_DURATION = 4,
    CLAWVIPER_AI_PARAM_CHARGE_COLOR = 5,
    CLAWVIPEREX_AI_PARAM_SHOOT_DISTANCE = 6,
    CLAWVIPEREX_AI_PARAM_SHOOT_TIMER = 7,
};

// 0x005F1B60
void __fastcall AITHINK_Fn016_ClawViper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->pAiControl->dwAiParam[0])
    {
        switch (AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 0);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 0);
            break;
        }
    }

    if (bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_DISTANCE)
        && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);

        switch (AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 1);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 1);
            break;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (AI_RollPercentage(pUnit) < 50)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
}
