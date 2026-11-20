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

enum D2C_M79AiConstants
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);          // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static __forceinline int AI_RollPercentageInline(D2UnitStrc* pUnit)
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

// 0x005E2610
void __fastcall sub_005E2610(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < 95)
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }
    }
    else
    {
        if (AI_RollPercentage(pUnit) < 89)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005F00E0
void __fastcall AITHINK_Fn005_BloodHawk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (pAiControl->dwAiParam[0] == 1 && bCombat)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    pAiControl->dwAiParam[0] = 0;

    if (bCombat)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_SetVelocity(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 3), 0);
        if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 1))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_SetVelocity(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 4), nTargetDistance);
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    if (nTargetDistance > 3)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetVelocity(pUnit, 0, -50, 0);
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        }
        else
        {
            AITACTICS_SetVelocity(pUnit, 0, 0, 0);
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
        }
        return;
    }

    AITACTICS_SetVelocity(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 3), 0);
    if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 1))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
}
