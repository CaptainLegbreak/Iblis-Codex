#include "D2Structs.h"


struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
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

enum D2C_M144SandMaggotAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    SANDMAGGOT_AI_PARAM_LAY_CHANCE_PCT = 0,
    SANDMAGGOT_AI_PARAM_SPIT_CHANCE_PCT = 1,
    SANDMAGGOT_AI_PARAM_NUMBER_OF_EGGS = 2,
    SANDMAGGOT_AI_PARAM_MELEE_CHANCE_PCT = 3,
    SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME = 4,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_005DD280(D2UnitStrc* pUnit);                                                             // 0x005DD280
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall sub_6FCD0150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                           // 0x005DE130
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);

static int AI_RollPercentage(D2UnitStrc* pUnit)
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

static __forceinline bool AI_RollChanceLimited(D2GameStrc* pGame, D2SeedStrc* pSeed, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
    return nRoll < AI_GetParam(pGame, pMonStatsTxt, nParamId);
}

static __forceinline bool AI_RollLimitedBelow(D2SeedStrc* pSeed, int nChance)
{
    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
    return nRoll < nChance;
}

// 0x005F1800
void __fastcall AITHINK_Fn015_SandMaggot(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nDistance;
    D2UnitStrc* pNearest = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

    if (pAiControl->dwAiParam[0] < 3 && !pTarget && (!pNearest || nDistance > 10) && pGame->dwGameFrame > pAiControl->dwAiParam[1] && pMonStatsTxt->nSkill[1] >= 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
        sub_6FCD0150(pGame, pUnit, 30);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
        pAiControl->dwAiParam[0] = 3;
        return;
    }

    if ((pTarget || pNearest && nDistance < 16) && pAiControl->dwAiParam[0] == 3)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[1] && pMonStatsTxt->nSkill[0] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            sub_6FCD0150(pGame, pUnit, 25);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
            pAiControl->dwAiParam[0] = 1;
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 3)
    {
        sub_6FCD0150(pGame, pUnit, 20);
        return;
    }

    if (sub_005DD280(pUnit) < 25 && pMonStatsTxt->nSkill[1] >= 0 && nDistance < 7 && pGame->dwGameFrame > pAiControl->dwAiParam[1]
        && AI_RollLimitedBelow(pSeed, 20))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        sub_6FCD0150(pGame, pUnit, 30);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
        pAiControl->dwAiParam[0] = 3;
        return;
    }

    if (bCombat && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MELEE_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pNearest && nDistance < 15 && AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, SANDMAGGOT_AI_PARAM_SPIT_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pNearest);
        return;
    }

    if (AI_RollPercentage(pUnit) < 20)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 6, 0);
        return;
    }

    if (pAiControl->dwAiParam[2] >= AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_NUMBER_OF_EGGS)
        || !AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, SANDMAGGOT_AI_PARAM_LAY_CHANCE_PCT))
    {
        sub_6FCD0150(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[0] == 2 && pMonStatsTxt->nSkill[2] >= 0)
    {
        ++pAiControl->dwAiParam[2];
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
        sub_6FCD0150(pGame, pUnit, 20);
        return;
    }

    sub_005DF7D0(pGame, pUnit, pTarget, 6, 0);
    pAiControl->dwAiParam[0] = 2;
}
