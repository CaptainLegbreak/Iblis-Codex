struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc;

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

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
    int unk0x10[6];
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M86FallenShamanAi
{
    MONMODE_ATTACK1 = 4,
    MONTYPEFLAG_CHAMPION = 4,
    MONTYPEFLAG_UNIQUE = 8,
    FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT = 0,
    FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT = 2,
    FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE = 3,
    FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE = 4,
};

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                               // 0x005A0180
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F1380
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005FD470

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F1440
void __fastcall AITHINK_Fn013_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->bCombat && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2FallenShamanAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE) * AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE);

    if (!MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) || MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION))
    {
        sub_6FCF1E80(pGame, pUnit, &arg, 0, 9);
    }
    else
    {
        sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_FallenShaman, 1);
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
    }

    D2UnitStrc* pResurrectTarget = arg.pTarget;
    if (pResurrectTarget && arg.nCounter && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0))
    {
        AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pResurrectTarget, 0, 0);
        return;
    }

    if (pTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    D2UnitStrc* pNearTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pNearTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pNearTarget, 0, 0);
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
