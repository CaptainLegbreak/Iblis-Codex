#include "D2Structs.h"
#include "D2GameStrc.h"



struct D2AiControlStrc
{
    char unk0x00[0x14];
    int dwAiParam[3];
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

enum D2C_M144BatDemonAi
{
    STAT_HPREGEN = 74,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    MONMODE_SKILL2 = 9,
    MONMODE_SKILL3 = 10,
    MONMODE_SKILL4 = 11,
    BATDEMON_AI_PARAM_HURT_PCT = 0,
    BATDEMON_AI_PARAM_DISENGAGE_ON_HIT_CHANCE_PCT = 1,
    BATDEMON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BATDEMON_AI_PARAM_LIGHTNING_OR_ATTACK_1_CHANCE_PCT = 3,
    BATDEMON_AI_PARAM_REGEN_ROOSTED = 4,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);            // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);    // 0x00627260

static int AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static __forceinline bool AI_RollChanceLimited(D2GameStrc* pGame, D2SeedStrc* pSeed, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
    return nRoll < AI_GetParam(pGame, pMonStatsTxt, nParamId);
}

// 0x005F5040
void __fastcall AITHINK_Fn029_BatDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    const int nAiState = pAiControl->dwAiParam[0];

    if (nAiState && nAiState != 4)
    {
        if (nAiState == 1)
        {
            if (pAiControl->dwAiParam[1] > 1 && (bCombat || nTargetDistance < 7 || sub_6FCF2E70(pUnit) || nTargetDistance < 14 && nLifePercentage > 50))
            {
                if (pAiControl->dwAiParam[2])
                {
                    const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0) - pAiControl->dwAiParam[2];
                    STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nValue, 0);
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, 0);
                AITACTICS_Idle(pGame, pUnit, 6);
                pAiControl->dwAiParam[0] = 3;
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL4, 0);
                if (!pAiControl->dwAiParam[1])
                {
                    AITACTICS_Idle(pGame, pUnit, 10);
                }
                else
                {
                    AITACTICS_Idle(pGame, pUnit, 15);
                }

                ++pAiControl->dwAiParam[1];
            }
        }
        else if (nAiState == 2)
        {
            if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_HURT_PCT) && D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 15, 0))
            {
                pAiControl->dwAiParam[0] = 4;
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                pAiControl->dwAiParam[0] = 3;
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 15)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else if (nAiState == 3)
        {
            if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_HURT_PCT) && D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 15, 0))
            {
                pAiControl->dwAiParam[0] = 4;
            }
            else if (!bCombat)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            else if (pAiControl->dwAiParam[1] > 0)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                pAiControl->dwAiParam[1] = 0;
            }
            else if (sub_6FCF2E70(pUnit) && AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_DISENGAGE_ON_HIT_CHANCE_PCT)
                && D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 12, 0))
            {
                pAiControl->dwAiParam[0] = 2;
            }
            else if (AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if (AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_LIGHTNING_OR_ATTACK_1_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                }
                else
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                }
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else
        {
            if (nTargetDistance < 15)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                pAiControl->dwAiParam[0] = 3;
            }
            else
            {
                pAiControl->dwAiParam[0] = 4;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            }
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL3, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;

        const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
        if (nHpRegen)
        {
            pAiControl->dwAiParam[2] = (nHpRegen * AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_REGEN_ROOSTED)) / 8;
            STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nHpRegen + pAiControl->dwAiParam[2], 0);
        }
        else
        {
            pAiControl->dwAiParam[2] = 0;
        }
    }
}
