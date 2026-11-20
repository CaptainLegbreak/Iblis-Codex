#include "D2Game.h"
#include "D2Structs.h"

#define GRISWOLD_WALK_FLAGS 7
struct D2SeedStrc;
struct D2MonStatsTxt;
struct Control;
struct MonStats;
struct Tick;



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

enum D2C_M74MegademonConstants
{
    MONMODE_ATTACK1 = 4,
    STATE_INFERNO = 12,
};

enum D2C_MegademonAIParams
{
    MEGADEMON_AI_PARAM_INFERNO_RANGED_CHANCE_PCT = 0,
    MEGADEMON_AI_PARAM_INFERNO_MELEE_CHANCE_PCT = 1,
    MEGADEMON_AI_PARAM_SWING_MELEE_CHANCE_PCT = 2,
    MEGADEMON_AI_PARAM_APPROACH_CHANCE_PCT = 3,
    MEGADEMON_AI_PARAM_CIRCLE_MELEE_CHANCE_PCT = 4,
    MEGADEMON_AI_PARAM_INFERNO_TIMER = 5,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

struct Unit { char seedPad[0x20]; D2SeedStrc seed; };

struct Control { char controlPad[0x18]; int params[2]; };

struct MonStats { char statsPad[0x170]; short skills[8]; };

struct Tick { Control* control; char pad4[0x18]; MonStats* stats; };

extern const int skill_choices[2][2]; // 0x006E34E0
Skill* __fastcall sub_006439B0(Unit*,int,int); // 0x006439B0

static __forceinline int SEED_RollPercentage(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005E0C80
void __fastcall AITHINK_Fn089_Megademon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nSkillLevel = 0;
    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pMonStatsTxt->nSkill[0], -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        }
    }

    if (nSkillLevel <= 0)
    {
        nSkillLevel = 1;
    }

    const int bInferno = STATES_CheckState(pUnit, STATE_INFERNO);
    if (pMonStatsTxt->nSkill[0] >= 0 && !bCombat && nTargetDistance < nSkillLevel && !bInferno)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            const int nDifficulty = pGame->nDifficulty;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < pMonStatsTxt->wAiParam[MEGADEMON_AI_PARAM_INFERNO_RANGED_CHANCE_PCT][nDifficulty])
            {
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[MEGADEMON_AI_PARAM_INFERNO_TIMER][nDifficulty];
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }
        }
    }
    else
    {
        if (bInferno)
        {
            STATES_ToggleState(pUnit, STATE_INFERNO, 0);
        }

        if (bCombat)
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0]
                && SEED_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_INFERNO_MELEE_CHANCE_PCT))
            {
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_INFERNO_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            if (SEED_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_SWING_MELEE_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            if (SEED_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_CIRCLE_MELEE_CHANCE_PCT))
            {
                sub_005DF7D0(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }
    }

    if (SEED_RollPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005E2CD0
void __fastcall sub_005E2CD0(void* game,Unit* unit,Tick* tick)
{
    int choice=SEED_RollRandomNumber(&unit->seed)&1;
    for (int i=0;i<2;++i) {
        choice=(choice+1)%2;
        if (sub_006439B0(unit,tick->stats->skills[skill_choices[choice][0]],-1)) {
            tick->control->params[0]=skill_choices[choice][0];
            tick->control->params[1]=skill_choices[choice][1];
            return;
        }
    }
    tick->control->params[0]=0;
    tick->control->params[1]=0;
}

#include "gen/data/Source/D2Game/Unknown_005E0C80.inc"

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

// 0x005E34C0
void __fastcall AITHINK_Fn123_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005E5AC0
void __fastcall AITHINK_Fn090_Griswold(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < 80)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }
    else
    {
        if (AI_RollPercentage(pUnit) < 50)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, GRISWOLD_WALK_FLAGS);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005ECB70
void __fastcall AITHINK_InitializeRaven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = -1;
    pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[2][pGame->nDifficulty] + 1;
    pAiControl->dwAiParam[2] = SEED_RollRandomNumber(&pUnit->pSeed) & 1;
}
