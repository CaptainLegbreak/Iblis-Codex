#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x4F];
    unsigned char nAIdel[3];
    char unk0x052[0x04];
    short wAiParam[8][3];
    char unk0x086[0xEA];
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

enum D2C_M394IzualAi
{
    MONMODE_ATTACK1 = 4,
    IZUAL_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT = 1,
    IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT = 2,
    IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT = 3,
    IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS = 4,
    IZUAL_AI_PARAM_NUM_SWINGS = 5,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall ACT4Q1_OnIzualActivated(D2GameStrc* pGame);                                                 // 0x005B4390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                          // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                          // 0x00648900

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_RollChance(pGame, pSeed, pMonStatsTxt, nParamId) ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, nParamId))

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int AI_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int AI_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005F89B0
void __fastcall AITHINK_Fn055_Izual(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nX = AI_GetUnitX(pTarget);
    const int nY = AI_GetUnitY(pTarget);

    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        ACT4Q1_OnIzualActivated(pGame);
    }

    if (pAiControl->dwAiParam[1])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[1]);
        pAiControl->dwAiParam[1] = 0;
        return;
    }

    if (!bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < 10)
        {
            if (pAiControl->dwAiParam[2] > 0)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
                pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
                pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
                return;
            }
        }

        if (pAiControl->dwAiParam[2] <= 0 && (int)(ITEMS_RollRandomNumber(pSeed) % 100) >= AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT))
        {
            if (nTargetDistance > 10)
            {
                D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 6, 9);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
            }
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pAiControl->dwAiParam[2] <= 0 && (int)(ITEMS_RollRandomNumber(pSeed) % 100) >= AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        pAiControl->dwAiParam[2] = 0;
        if (pMonStatsTxt->nSkill[0] < 0 || !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
        }
        else
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
            pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
        }
        return;
    }

    if (pAiControl->dwAiParam[2] > 0)
    {
        --pAiControl->dwAiParam[2];
    }

    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
}
