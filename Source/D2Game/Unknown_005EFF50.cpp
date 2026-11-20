#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
union D2SeedStrc;
struct D2MonStatsTxt;



struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
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

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_005DD280(D2UnitStrc* pUnit); // 0x005DD280
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int nVelocity, short nMaxVelocity, int nAcceleration); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nSteps); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nDistance, int bUnk); // 0x005DEFE0
int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nSteps, int a5); // 0x005DF7D0
D2UnitStrc* __fastcall sub_005DDC30_FindTarget(D2GameStrc*, D2UnitStrc*, int*, int); // 0x005DDC30
void __fastcall AITACTICS_Idle(D2GameStrc*, D2UnitStrc*, int); // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0

// 0x005EFF50
void __fastcall AITHINK_Fn004_Bighead(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bInMeleeRange;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!bCombat && sub_6FCF2E70(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
        return;
    }

    if (sub_005DD280(pUnit) >= AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (nTargetDistance < 15 && AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
    }
    else
    {
        if (nTargetDistance < 3)
        {
            AITACTICS_SetVelocity(pUnit, 0, 50, 0);
            if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 5, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            }
        }
        else
        {
            if (nTargetDistance > 15)
            {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 6);
                return;
            }

            if (AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= AI_PARAM(pGame, pMonStatsTxt, 1))
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
            else
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            }
        }
    }
}

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F9270
void __fastcall sub_005F9270_ThinkSkillModes(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[2])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
        pAiControl->dwAiParam[2] = 1;
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[2] == 2 && pGame->dwGameFrame > pAiControl->dwAiParam[1])
    {
        if (nDistance > AI_GetParam(pGame, pMonStatsTxt, 5) || !bCombat && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 20);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[2] = 1;
            return;
        }
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && pAiControl->dwAiParam[2] == 1 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (bCombat || nDistance < AI_GetParam(pGame, pMonStatsTxt, 5)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 3);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
        return;
    }

    D2UnitStrc* pNewTarget = sub_005DDC30_FindTarget(pGame, pUnit, &nDistance, 0);
    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pNewTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
}
