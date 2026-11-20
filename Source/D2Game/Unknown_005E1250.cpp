#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"



struct D2AiControlStrc
{
    char unk0x00[0x14];
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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

enum D2C_M188FetishBlowgunAi
{
    MONMODE_ATTACK1 = 4,
    FETISHBLOWGUN_AI_PARAM_STAY_IN_RANGE = 0,
    FETISHBLOWGUN_AI_PARAM_RUN_AWAY_CHANCE_PCT = 1,
};

extern "C" unsigned int __fastcall sub_0058EE80(D2UnitStrc* pUnit);                                        // 0x0058EE80
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0058ED10
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1250
void __fastcall AITHINK_Fn096_FetishBlowgun(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = (D2AiCmdStrc*)sub_0058EE80(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCmdTarget = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[2], pCurrentAiCmd->nCmdParam[1]);
            if (pCmdTarget)
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pCmdTarget);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }

        if (pCurrentAiCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCmdTarget = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[2], pCurrentAiCmd->nCmdParam[1]);
            if (pCmdTarget)
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_SetVelocity(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCmdTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }

        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }

    if (!bCombat)
    {
        if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, FETISHBLOWGUN_AI_PARAM_STAY_IN_RANGE))
        {
            AITACTICS_SetVelocity(pUnit, 0, 50, 0);
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 6);
            return;
        }

        if (nTargetDistance >= 6)
        {
            goto LSelectTarget;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHBLOWGUN_AI_PARAM_RUN_AWAY_CHANCE_PCT))
    {
        pAiControl->dwAiParam[0] = 2;
    }

LSelectTarget:
    int nDistance;
    D2UnitStrc* pSelected = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

    switch (pAiControl->dwAiParam[0])
    {
    case 0:
        ++pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] > (int)(AI_RollSeed(pSeed) % 3 + 3))
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = 0;
        }

        if (pSelected)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pSelected);
        }
        else
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
        }
        return;

    case 1:
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_SetVelocity(pUnit, 0, 50, 0);
        if (!sub_005DF7D0(pGame, pUnit, pTarget, 6, 1))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        }
        return;

    case 2:
        if (nTargetDistance > 12)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= 20 || !sub_005DF7D0(pGame, pUnit, pTarget, 4, 1))
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else
        {
            AITACTICS_SetVelocity(pUnit, 2, 50, 0);
            if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 14, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pSelected);
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
            }
        }
        return;

    default:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
}
