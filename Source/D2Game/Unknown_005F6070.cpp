#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

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

enum D2C_M80SkeletonBowAi
{
    MONMODE_ATTACK1 = 4,
    SKELETONBOW_AI_PARAM_SHOOT_CHANCE_PCT = 0,
    SKELETONBOW_AI_PARAM_STALL_DURATION = 1,
    SKELETONBOW_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SKELETONBOW_AI_PARAM_WALK_STEPS = 3,
    SKELETONBOW_AI_PARAM_TARGET_DISTANCE = 4,
};

int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F6070
void __fastcall AITHINK_Fn037_SkeletonBow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (sub_6FCF2E70(pUnit))
    {
        D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
        if (pTarget)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pTarget && nDistance < 20)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if ((int)(AI_RollUnitSeed(pUnit) % 100) < 20)
        {
            sub_005DF7D0(pGame, pUnit, pTickTarget, 3, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_WALK_STEPS), AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_TARGET_DISTANCE));
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}
