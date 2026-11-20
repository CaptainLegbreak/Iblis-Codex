#include "D2Structs.h"
#include "D2GameStrc.h"



struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
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

struct D2NihlathakOverseerAiCallbackArgStrc
{
    int nMaxDistance;
    int nDistantMaxDistance;
    int nMaxLifePercentage;
    D2UnitStrc* pTarget;
    D2UnitStrc* pDistantTarget;
    int nCounter;
    int unk0x18[4];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M81OverseerAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    UNIT_ALIGNMENT_GOOD = 2,
    OVERSEER_AI_PARAM_RALLY_SPELL_TIMER = 0,
    OVERSEER_AI_PARAM_HEAL_CHANCE_PCT = 1,
    OVERSEER_AI_PARAM_WHIP_CHANCE_PCT = 2,
    OVERSEER_AI_PARAM_COMFORT_DISTANCE = 3,
    OVERSEER_AI_PARAM_COMFORT_ZONE = 4,
    OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT = 5,
    OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT = 6,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00587900
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId);                             // 0x005DD2D0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x005DE830
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E26D0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

// 0x005E27A0
void __fastcall AITHINK_Fn120_Overseer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    ACT5Q1_OnSiegeBossActivated(pGame, pUnit);

    D2UnitStrc* pMinion = AITACTICS_GetTargetMinion(pGame, pUnit);
    if (pMonStatsTxt->nSkill[0] >= 0 && sub_6FCF2E70(pUnit) && pGame->dwGameFrame > pAiControl->dwAiParam[0]
        && pMinion && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMinion, 0, 0);
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_RALLY_SPELL_TIMER);
        return;
    }

    if (bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    D2NihlathakOverseerAiCallbackArgStrc arg;
    arg.nMaxDistance = 576;
    arg.nDistantMaxDistance = 400;
    arg.nMaxLifePercentage = 50;
    arg.pTarget = 0;
    arg.pDistantTarget = 0;
    arg.nCounter = 0;
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);

    D2UnitStrc* pHealTarget = arg.pTarget;
    D2UnitStrc* pDistantTarget = arg.pDistantTarget;
    int nCounter = arg.nCounter;

    if (pMonStatsTxt->nSkill[1] >= 0 && pHealTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_HEAL_CHANCE_PCT) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pHealTarget, 0, 0);
        return;
    }

    if (pMonStatsTxt->nSkill[2] && pDistantTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_WHIP_CHANCE_PCT)
        && STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_GOOD && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[2]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pDistantTarget, 0, 0);
        return;
    }

    if (nCounter)
    {
        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE))
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - nTargetDistance, 0);
            return;
        }

        if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE) + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            sub_005DF7D0(pGame, pUnit, pTarget, 5, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (AI_ROLL_PERCENT(pSeed) < 60)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
