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

enum D2C_M75AndarielConstants
{
    MONMODE_ATTACK1 = 4,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

static int AI_RollSeedPercentage(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005F5830
void __fastcall AITHINK_Fn034_Andariel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (pAiTickParam->bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    if (AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 2))
    {
        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (nRoll < AI_GetParam(pGame, pMonStatsTxt, 3))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[1] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }
    }

    sub_005DE190_SetAiParam(pUnit, 1, 0, 0);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}
