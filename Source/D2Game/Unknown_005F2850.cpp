#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

enum D2C_MummyAIParams
{
    MUMMY_AI_PARAM_AWAKE_DISTANCE = 0,
    MUMMY_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    MUMMY_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    MUMMY_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    MUMMY_AI_PARAM_STALL_DURATION = 4,
};

static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    *(unsigned __int64*)pSeed = lSeed;
    return lSeed;
}

static __forceinline unsigned int SEED_RollPercentage(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed) % 100;
}

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return SEED_RollPercentage(&pUnit->pSeed);
}

static __forceinline int SEED_RollPercentageHalves(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

static __forceinline int SEED_RollPercentageFrom(D2SeedStrc* pSeed, unsigned int nLowSeed, unsigned int nHighSeed)
{
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F2850
void __fastcall AITHINK_Fn021_Mummy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (AIUTIL_IsGettingHit(pUnit) && !bCombat)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (nDistance > pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_AWAKE_DISTANCE][pGame->nDifficulty])
    {
        if (AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_APPROACH_CHANCE_PCT][pGame->nDifficulty])
        {
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_STALL_DURATION][pGame->nDifficulty]);
        }
        return;
    }

    if (bCombat)
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
        if (SEED_RollPercentageHalves(&pUnit->pSeed, nLowSeed, nHighSeed) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_ATTACK_CHANCE_PCT][pGame->nDifficulty])
        {
            if (SEED_RollPercentageFrom(&pUnit->pSeed, nLowSeed, nHighSeed) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_STALL_DURATION][pGame->nDifficulty]);
    }

    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}
