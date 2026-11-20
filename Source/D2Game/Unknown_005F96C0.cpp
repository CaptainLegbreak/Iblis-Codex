#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"




struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
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

enum D2C_M80SkeletonMageAi
{
    MONMODE_ATTACK1 = 4,
    SKELETONMAGE_AI_PARAM_SHOOT_CHANCE_PCT = 0,
    SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE = 1,
    SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SKELETONMAGE_AI_PARAM_TOO_CLOSE_DISTANCE = 3,
    SKELETONMAGE_AI_PARAM_WALK_AWAY_CHANCE_PCT = 4,
    SKELETONMAGE_AI_PARAM_FIRE_DIST = 5,
    SKELETONMAGE_AI_PARAM_CIRCLE_CHANCE_PCT = 6,
    SKELETONMAGE_AI_PARAM_STALL_DURATION = 7,
};
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F96C0
void __fastcall AITHINK_Fn064_SkeletonMage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pTarget)
    {
        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            AITACTICS_SetVelocity(pUnit, 0, 10, 0);
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE));
            return;
        }

        if (nDistance <= AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_TOO_CLOSE_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_WALK_AWAY_CHANCE_PCT))
        {
            AITACTICS_SetVelocity(pUnit, 0, 25, 0);
            if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 5, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTickTarget);
            }
            return;
        }

        if (nDistance < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_FIRE_DIST) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 0, 10, 0);
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTickTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTickTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_STALL_DURATION));
}
