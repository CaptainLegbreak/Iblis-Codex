#include "D2Game.h"
#include "D2Structs.h"


struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
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

struct D2SkillsTxt
{
    char unk0x000[0x80];
    short nAuraState;
    char unk0x082[0x1BA];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

enum D2C_M144UberIzualAi
{
    MONMODE_ATTACK1 = 4,
    COLLIDE_MASK_BARRIER = 6,
    IZUAL_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT = 1,
    IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT = 2,
    IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT = 3,
    IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS = 4,
    IZUAL_AI_PARAM_NUM_SWINGS = 5,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                          // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                          // 0x00648900

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
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

// 0x005F8C80
void __fastcall AITHINK_Fn144_UberIzual(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nX = AI_GetUnitX(pTarget);
    const int nY = AI_GetUnitY(pTarget);

    if (pMonStatsTxt->nSkill[1] >= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[1]);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
            return;
        }
    }

    if (UNITS_TestCollisionWithUnit(pUnit, pTarget, COLLIDE_MASK_BARRIER))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nX, nY);
        return;
    }

    if (pAiControl->dwAiParam[1])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[1]);
        pAiControl->dwAiParam[1] = 0;
        return;
    }

    if (!bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < 10 && pAiControl->dwAiParam[2] <= 0 && AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
            pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
            return;
        }

        if (pAiControl->dwAiParam[2] <= 0 && !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT))
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

    if (pAiControl->dwAiParam[2] <= 0 && !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_ATTACK_CHANCE_PCT))
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
