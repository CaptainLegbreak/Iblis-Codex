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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

enum D2C_M230QuillRatAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    QUILLRAT_AI_PARAM_ACTIVATE_DISTANCE = 0,
    QUILLRAT_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    QUILLRAT_AI_PARAM_WALK_DISTANCE = 3,
};

extern "C" D2AiCmdStrc* __fastcall sub_0058EE80(D2UnitStrc* pUnit);                                      // 0x0058EE80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0058ED10
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F1140
void __fastcall AITHINK_Fn014_QuillRat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (pCurrentAiCmd)
    {
        if (SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            return;
        }

        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }

    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (sub_6FCF2E70(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_ACTIVATE_DISTANCE))
    {
        if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE), 1))
        {
            return;
        }

        if (nDistance < 4)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }
    }

    unsigned char nWalkDist;
    if (AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE) < 3)
    {
        nWalkDist = 3;
    }
    else
    {
        nWalkDist = (unsigned char)AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE);
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, nWalkDist);
}
