#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

struct D2StaticPathStrc;

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pUnit) ((int)((unsigned int)SEED_RollRandomNumber(&(pUnit)->pSeed) % 100))

enum D2C_VileDogAIParams
{
    VILEDOG_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    VILEDOG_AI_PARAM_STALL_DURATION = 1,
    VILEDOG_AI_PARAM_APPROACH_CHANCE_PCT = 2,
};

// 0x005FA280
void __fastcall AITHINK_Fn069_VileDog(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    if (bCombat)
    {
        if (AI_ROLL_PERCENT(pUnit) < AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_STALL_DURATION));
        return;
    }

    if (AI_ROLL_PERCENT(pUnit) < AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
