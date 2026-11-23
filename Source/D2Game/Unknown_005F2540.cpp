#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"
struct D2GameStrc;
struct D2UnitStrc;

enum D2C_ScarabAIParams
{
    SCARAB_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SCARAB_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 1,
    SCARAB_AI_PARAM_STALL_DURATION = 2,
    SCARAB_AI_PARAM_JAB_CHANCE_PCT = 3,
    SCARAB_AI_PARAM_COMMAND_CHANCE_PCT = 4,
};

void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                       // 0x0058ED10
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit);                           // 0x0058EE80
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeedUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F2540
void __fastcall AITHINK_Fn020_Scarab(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pCurrentAiCmd && nDistance < 20 && AIGENERAL_GetMinionOwner(pUnit) == pUnit
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_COMMAND_CHANCE_PCT))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pCurrentAiCmd = &aiCmd;
    }

    if (pCurrentAiCmd && pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat && pMonStatsTxt->nSkill[0] >= 0)
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        }
        else
        {
            sub_005DE190_SetAiParam(pUnit, 2, 100, 0);
            if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        return;
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_JAB_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_STALL_DURATION));
        return;
    }

    if (!pAiControl->dwAiParam[0])
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 0, 0);
        pAiControl->dwAiParam[0] = 1;
        return;
    }

    sub_005DE190_SetAiParam(pUnit, 2, 0, 4);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);

    if ((int)(AI_RollSeedUnit(pUnit) % 100) > 10)
    {
        pAiControl->dwAiParam[0] = 0;
    }
}
