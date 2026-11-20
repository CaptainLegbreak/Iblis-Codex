#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"





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

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
    int unk0x04[9];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M80SiegeBeastAi
{
    MONMODE_ATTACK1 = 4,
    UNIT_ALIGNMENT_EVIL = 0,
    SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE = 0,
    SIEGEBEAST_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    SIEGEBEAST_AI_PARAM_STAMP_MELEE_CHANCE_PCT = 2,
    SIEGEBEAST_AI_PARAM_MELEE_STALL_DURATION = 3,
    SIEGEBEAST_AI_PARAM_STOMP_RANGED_CHANCE_PCT = 4,
    SIEGEBEAST_AI_PARAM_CHARGE_CHANCE_PCT = 5,
    SIEGEBEAST_AI_PARAM_CHARGE_VELOCITY = 6,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                               // 0x00552FD0
int __fastcall sub_005DC640_HasFreeSpotNearTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x005DC640
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E1720
void __fastcall sub_005E17E0_SiegeBeastSetTower(D2UnitStrc* pUnit, D2UnitStrc* pTower);                    // 0x005E17E0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_MAX(a, b) ((a) > (b) ? (a) : (b))
#define AI_MIN(a, b) ((a) < (b) ? (a) : (b))

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1900
void __fastcall AITHINK_Fn115_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (!pOwner && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
    {
        D2SiegeBeastTowerAiCallbackArgStrc arg;
        arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE) * AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE);
        D2UnitStrc* pTower = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
        if (pTower)
        {
            sub_005E17E0_SiegeBeastSetTower(pTower, pUnit);
        }
    }

    if (bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_STAMP_MELEE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
            return;
        }

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTickTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < sub_004E6C70(pMonStatsTxt->nSkill[0])
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_STOMP_RANGED_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        return;
    }

    if (sub_005DC640_HasFreeSpotNearTarget(pUnit, pTickTarget) && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CHARGE_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 0, AI_MIN(AI_MAX(AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CHARGE_VELOCITY), 0), 127), 0);
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 12, 0);
        return;
    }

    D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 12, 0);
}
