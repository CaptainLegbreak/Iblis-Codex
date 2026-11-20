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
    unsigned int unk0x04[1];
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

enum D2C_BaboonAIParams
{
    STAT_HPREGEN = 74,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    BABOON_AI_PARAM_HURT_PCT = 0,
    BABOON_AI_PARAM_CIRCLE_CHANCE_PCT = 1,
    BABOON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    BABOON_AI_PARAM_REGEN_BONUS = 4,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);            // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);    // 0x00627260

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline int AI_RollPercentage(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F0CD0
void __fastcall AITHINK_Fn011_Baboon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nVel;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);

    if (pMonStatsTxt->nVelocity <= 0)
    {
        goto zero_vel;
    }
    nVel = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity;
    if (nVel < 100)
    {
zero_vel:
        nVel = 0;
    }
    else
    {
        nVel -= 100;
        if (nVel > 120)
        {
            nVel = 120;
        }
    }

    if (pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[1] = 0;
        --pAiControl->dwAiParam[0];

        if (!pAiControl->dwAiParam[0] || nLifePercentage > 75)
        {
            const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0) - pAiControl->dwAiParam[2];
            STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nValue, 0);
        }

        if (!bCombat)
        {
            if (nLifePercentage > 75)
            {
                pAiControl->dwAiParam[0] = 0;
                sub_005DE190_SetAiParam(pUnit, 13, nVel, 0);
                sub_6FCD0410(pGame, pUnit, pTarget, 7);
                return;
            }
        }
        else if (AI_RollPercentage(pSeed) < 33)
        {
            if (AI_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nTargetDistance >= 24 && !sub_6FCF2E70(pUnit))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33)
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        sub_005DE190_SetAiParam(pUnit, 2, nVel, 0);

        if (!sub_005DEFE0_Escape(pGame, pUnit, pTarget, 15, 1))
        {
            if (bCombat)
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        }
        return;
    }

    if (!bCombat)
    {
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    if (sub_6FCF2E70(pUnit))
    {
        if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_HURT_PCT) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            pAiControl->dwAiParam[0] = SEED_RollLimitedRandomNumber(pSeed, 5) + 2;

            const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
            if (nHpRegen)
            {
                pAiControl->dwAiParam[2] = (nHpRegen * AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_REGEN_BONUS)) / 8;
                STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nHpRegen + pAiControl->dwAiParam[2], 0);
            }
            else
            {
                pAiControl->dwAiParam[2] = 0;
            }

            sub_005DE190_SetAiParam(pUnit, 2, nVel, 0);
            sub_005DEFE0_Escape(pGame, pUnit, pTarget, 15, 0);
            return;
        }

        if (pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
            pAiControl->dwAiParam[1] = 0;
            return;
        }
    }

    if (!pAiControl->dwAiParam[1] || AI_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        pAiControl->dwAiParam[1] = 1;
        if (AI_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
        pAiControl->dwAiParam[1] = 0;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
