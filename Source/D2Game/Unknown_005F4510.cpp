#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F4510
void __fastcall AITHINK_Fn026_Arach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);

    if (pAiControl->dwAiParam[0] == 1)
    {
        pAiControl->dwAiParam[1] = 0;

        if (nLifePercentage > 75)
        {
            pAiControl->dwAiParam[0] = 0;

            if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                pAiControl->dwAiParam[0] = 2;
                AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
                return;
            }

            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 0);
            return;
        }

        if (bCombat && AI_PARAM(pGame, pMonStatsTxt, 0) > 25 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0) - 25)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 3) || AIUTIL_IsGettingHit(pUnit))
        {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        pAiControl->dwAiParam[0] = 0;
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 12, 0);
        return;
    }

    if (bCombat)
    {
        pAiControl->dwAiParam[0] = 2;

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, 4))
        {
            pAiControl->dwAiParam[0] = 1;

            if (pMonStatsTxt->nSkill[0] < 0 || STATES_CheckState(pUnit, 22))
            {
                AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 0);
                return;
            }

            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
            return;
        }

        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if (!AIUTIL_IsGettingHit(pUnit) && pAiControl->dwAiParam[1] != 1)
    {
        ++pAiControl->dwAiParam[2];

        if (pAiControl->dwAiParam[2] > 20)
        {
            pAiControl->dwAiParam[2] = 0;
        }

        pAiControl->dwAiParam[1] = 0;

        if (pAiControl->dwAiParam[2] != 1 || (int)SEED_RollLimitedRandomNumber(pSeed, 100) >= AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }

        pAiControl->dwAiParam[1] = 1;
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
        return;
    }

    pAiControl->dwAiParam[1] = 1;
    AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
}
