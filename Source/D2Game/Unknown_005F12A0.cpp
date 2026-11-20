#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2PantherAiCallbackArgStrc;
struct D2AiCmdStrc;





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

enum D2C_AiThink005F12A0
{
    MONMODE_ATTACK1 = 4,
    AI_PARAM_WALK_CHANCE_PCT = 0,
    AI_PARAM_IDLE_FRAMES = 1,
    AI_PARAM_ATTACK_CHANCE_PCT = 2,
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

struct D2AiControlStrc { int nAiSpecialState; int padding[4]; int dwAiParam[3]; };

struct D2AiCmdStrc { D2AiCmdStrc* pNextCmd; D2AiCmdStrc* pPrevCmd; int nCmdParam[5]; };

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc*, D2UnitStrc*); // 0x0058ED10
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F12A0
void __fastcall sub_005F12A0_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_WALK_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

// 0x005F22B0
void __fastcall sub_005F22B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
        return;
    }

    if (!bCombat && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_SetVelocity(pUnit, 0, 75, 0);
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    D2PantherAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

    D2UnitStrc* pPanther = arg.pTarget;
    if (pPanther && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, 2) * AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        AITACTICS_SetVelocity(pUnit, 0, 75, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pPanther, 7);
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 25)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

static __forceinline int RollPercentage(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed % 100;
}

static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pRecord, int nIndex)
{
    return pRecord->wAiParam[nIndex][pGame->nDifficulty];
}

// 0x005F53E0
void __fastcall sub_005F53E0_ThinkMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* const pUnitSeed = &pUnit->pSeed;
    const int nTargetDistance = pTick->nTargetDistance;
    const int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pRecord = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2AiCmdStrc* pCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCmd)
    {
        if (pCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetVelocity(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        if (pCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetVelocity(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pTarget);
    switch (pAi->dwAiParam[0])
    {
    case 2:
        if (nTargetDistance > 12)
        {
            ++pAi->dwAiParam[1];
            if (pAi->dwAiParam[1] > 1)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
            }
            if (RollPercentage(pUnitSeed) < 20)
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_SetVelocity(pUnit, 2, 50, 0);
        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 14, 1))
            return;
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        break;
    case 1:
        ++pAi->dwAiParam[1];
        if (pAi->dwAiParam[1] > AI_GetParam(pGame, pRecord, 2) && nLife > AI_GetParam(pGame, pRecord, 3))
        {
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = 0;
            AITACTICS_SetVelocity(pUnit, 2, 50, 0);
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 14, 1);
            return;
        }
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pUnitSeed, 100) < pRecord->wAiParam[0][pGame->nDifficulty])
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pRecord->wAiParam[1][pGame->nDifficulty]);
            return;
        }
        AITACTICS_SetVelocity(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    case 0:
        if (bCombat)
        {
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[0] = 1;
            if (RollPercentage(pUnitSeed) < AI_GetParam(pGame, pRecord, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pRecord, 1));
                return;
            }
        }
        AITACTICS_SetVelocity(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
