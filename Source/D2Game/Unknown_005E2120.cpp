#include "D2Game.h"

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

enum D2C_M236SuccubusWitchAi
{
    UNIT_PLAYER = 0,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL2 = 9,
    SUCCUBUSWITCH_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SUCCUBUSWITCH_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT = 2,
    SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE = 3,
    SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT = 4,
    SUCCUBUSWITCH_AI_PARAM_STALL_DURATION = 5,
    SUCCUBUSWITCH_AI_PARAM_AMPLIFY_DAMAGE_TARGET_HP_PCT = 6,
    SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT = 7,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

// 0x005E2120
void __fastcall AITHINK_Fn119_SuccubusWitch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pTarget && !STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20) && nDistance < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE)
        && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[0] > 0 && UNITS_GetCurrentLifePercentage(pTarget) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_AMPLIFY_DAMAGE_TARGET_HP_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[1] > 0 && UNITS_GetCurrentLifePercentage(pUnit) <= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] > 0)
        {
            if (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || pTarget->dwUnitType != UNIT_PLAYER)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] > 0 && pTarget->dwUnitType == UNIT_PLAYER)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if (AI_ROLL_PERCENT(pSeed) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT)
            || !D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE), 1))
        {
            if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_STALL_DURATION));
            }
        }
    }
    else
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT) > 0
            && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            D2UnitStrc* pSkillTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
            if (pSkillTarget && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pSkillTarget, 0, 0);
                return;
            }
        }

        if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE)
            || AI_ROLL_PERCENT(pSeed) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT)
            || !D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE), 1))
        {
            if (pMonStatsTxt->nSkill[4] < 0)
            {
                D2UnitStrc* pSkillTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
                if (pSkillTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pSkillTarget);
                    return;
                }
            }

            if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_APPROACH_CHANCE_PCT))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            else
            {
                if (AI_ROLL_PERCENT(pSeed) >= 50 || !sub_005DF7D0(pGame, pUnit, pTarget, 6, 1))
                {
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_STALL_DURATION));
                }
            }
        }
    }
}
