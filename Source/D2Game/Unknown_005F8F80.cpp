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

enum D2C_M388TentacleAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_DEAD = 12,
    MONMODE_SEQUENCE = 14,
    DEFAULT_FRAMES_PER_SECOND = 25,
    TENTACLE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    TENTACLE_AI_PARAM_SUBMERGE_CHANCE_PCT = 1,
    TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS = 2,
    TENTACLE_AI_PARAM_EMERGE_DURATION_SECONDS = 3,
    TENTACLE_AI_PARAM_STALL_DURATION = 4,
    TENTACLE_AI_PARAM_ACTIVE_DISTANCE = 5,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pAttacker, int a4);  // 0x0057CCB0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_RollChance(pGame, pSeed, pMonStatsTxt, nParamId) ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, nParamId))

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F8F80
void __fastcall AITHINK_Fn056_Tentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    const int nOwnerMode = pOwner->dwAnimMode;
    if (nOwnerMode == MONMODE_DEAD && AI_RollPercentage(pUnit) < 40)
    {
        SUNITDMG_KillMonster(pGame, pUnit, SUNIT_GetTargetUnit(pGame, pOwner), 1);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[2])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS);
        pAiControl->dwAiParam[2] = 1;
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[2] == 2 && pGame->dwGameFrame > pAiControl->dwAiParam[1])
    {
        if (nTargetDistance > AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_ACTIVE_DISTANCE)
            || !bCombat && AI_RollChance(pGame, pSeed, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_CHANCE_PCT)
            || nOwnerMode == MONMODE_SEQUENCE && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS);
            pAiControl->dwAiParam[2] = 1;
            return;
        }
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && pAiControl->dwAiParam[2] == 1 && pGame->dwGameFrame > pAiControl->dwAiParam[1]
        && (bCombat || nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_ACTIVE_DISTANCE) || nOwnerMode != MONMODE_SEQUENCE && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 5))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_EMERGE_DURATION_SECONDS);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_STALL_DURATION));
        return;
    }

    if (bCombat && AI_RollChance(pGame, pSeed, pMonStatsTxt, TENTACLE_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_STALL_DURATION));
}
