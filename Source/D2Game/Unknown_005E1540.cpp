#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

enum D2C_M86ReanimatedHordeAi
{
    UNITFLAG_ISVALIDTARGET = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
    UNITFLAG_TARGETABLE = 0x00000008,
    REANIMATEDHORDE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    REANIMATEDHORDE_AI_PARAM_MELEE_STALL_DURATION = 1,
    REANIMATEDHORDE_AI_PARAM_CHARGE_RANGE = 2,
    REANIMATEDHORDE_AI_PARAM_CHARGE_CHANCE_PCT = 3,
    REANIMATEDHORDE_AI_PARAM_FOLLOW_CHANCE_PCT = 4,
    REANIMATEDHORDE_AI_PARAM_WALK_FORWARD_CHANCE_PCT = 5,
    REANIMATEDHORDE_AI_PARAM_RANGED_STALL_DURATION = 6,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x005DC640
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1540
void __fastcall AITHINK_Fn114_ReanimatedHorde(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pUnit)
    {
        pUnit->dwFlags |= (UNITFLAG_ISVALIDTARGET | UNITFLAG_CANBEATTACKED | UNITFLAG_TARGETABLE);
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && sub_005DC640_HasFreeSpotNearTarget(pUnit, pTarget)
        && nDistance < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_CHARGE_RANGE) && nDistance > 5
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_CHARGE_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_FOLLOW_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_WALK_FORWARD_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_RANGED_STALL_DURATION));
}
