struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    unsigned int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc;
struct D2SkillStrc;

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

struct D2FetishShamanAiCallbackArgStrc
{
    D2UnitStrc* pClosestDeadTarget;
    int nSquaredDistanceToClosestDeadTarget;
    int nMaxSearchRangeSquared;
    D2UnitStrc* pClosestAliveTarget;
    int nSquaredDistanceToClosestAliveTarget;
    int nAliveTargets;
    int nHealCapability;
    int unk0x1C[3];
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M172FetishShamanAi
{
    STATE_INFERNO = 12,
    UNIT_TYPES_COUNT = 6,
    FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT = 0,
    FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY = 1,
    FETISHSHAMAN_AI_PARAM_HEAL_RANGE = 2,
    FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
    FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE = 4,
};

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                            // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nSkillFlags);             // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AIUTIL_TargetCallback pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);
D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F99A0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }
    return pUnit->dwUnitType;
}

// 0x005F9A80
void __fastcall AITHINK_Fn065_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nSkillLevel;
    D2SkillStrc* pSkill;

    if (pMonStatsTxt->nSkill[0] < 0
        || !(pSkill = SKILLS_GetSkillById(pUnit, pMonStatsTxt->nSkill[0], -1))
        || (nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1)) <= 0)
    {
        nSkillLevel = 1;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < nSkillLevel && !STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        aiCmd.nCmdParam[1] = sub_00451F50(pTarget);
        aiCmd.nCmdParam[2] = sub_0044BE50(pTarget);
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    D2FetishShamanAiCallbackArgStrc arg;
    arg.pClosestDeadTarget = 0;
    arg.nSquaredDistanceToClosestDeadTarget = 0x7FFFFFFF;
    arg.nMaxSearchRangeSquared = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE) * AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE);
    arg.pClosestAliveTarget = 0;
    arg.nSquaredDistanceToClosestAliveTarget = 0x7FFFFFFF;
    arg.nAliveTargets = 0;
    arg.nHealCapability = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY);
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_FetishShaman, 1);

    D2UnitStrc* pDeadTarget = arg.pClosestDeadTarget;
    if (pDeadTarget && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], arg.pClosestDeadTarget, 0, 0))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 14;
        aiCmd.nCmdParam[1] = pDeadTarget->dwUnitId;
        aiCmd.nCmdParam[2] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

        if (arg.nSquaredDistanceToClosestDeadTarget > AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_RANGE))
        {
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pDeadTarget, 10);
        }
        else
        {
            AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[2], pDeadTarget, 0, 0);
        }
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
