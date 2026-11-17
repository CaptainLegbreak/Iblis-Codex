struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StatListStrc;

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
    char unk0x000[0x32]; short nVelocity; short nRun; char unk0x036[0x20];
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
int __fastcall sub_6FCD0E80(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
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

int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int nFlags, int nVelocity, unsigned char nUnused); // 0x005DE190

// 0x005F4A70
void __fastcall sub_005F4A70_Think(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nFlags = AI_PARAM(pGame, pStats, 4);
    const int bAttack = nFlags & 1;
    const int bSkill1 = nFlags & 2;
    const int bSkill2 = nFlags & 4;
    if (pAi->dwAiParam[2] > 0) --pAi->dwAiParam[2];
    int nNewDistance;
    D2UnitStrc* pNewTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nNewDistance, 0);
    if (sub_6FCF2E70(pUnit)) {
        if (!pAi->dwAiParam[0]) pAi->dwAiParam[0] = 1;
        if (nDistance < 30 && nDistance > pAi->dwAiParam[1]) pAi->dwAiParam[1] = nDistance;
        if (bCombat) {
            if (AI_ROLL_PERCENT(pSeed) <= 30 && bAttack)
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
                else AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pTarget, 0, 0);
            }
            else AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pUnit);
    if (pAi->dwAiParam[0] == 2) {
        if (nLife >= 75) {
            pAi->dwAiParam[0] = 1;
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
        if (nDistance < 14 || nDistance <= pAi->dwAiParam[1]) {
            int nVelocity = 0;
            if (pStats->nVelocity > 0) nVelocity = 100 * pStats->nRun / pStats->nVelocity - 100;
            nVelocity = nVelocity <= 0 ? 0 : nVelocity;
            nVelocity = nVelocity >= 120 ? 120 : nVelocity;
            AITACTICS_SetVelocity(pUnit, 0, nVelocity, 0);
            if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 8, 1)) return;
        }
        if (nDistance < AI_PARAM(pGame, pStats, 2) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 1)) {
            if (bSkill1 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bSkill2 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bAttack && pNewTarget && nNewDistance <= 20) { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; }
            else sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }
    if (nLife < 33) {
        pAi->dwAiParam[0] = 2;
        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 8, 0)) return;
    }
    if (bCombat) {
        pAi->dwAiParam[0] = 1;
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pStats, 0)) {
            if (!bAttack || !pNewTarget || (int)SEED_RollLimitedRandomNumber(pSeed, 100) > 30) {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            if (nNewDistance <= 20) { { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; } return; }
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33) sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (nDistance < AI_PARAM(pGame, pStats, 2)) {
        pAi->dwAiParam[0] = 1;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 1)) {
            if (bSkill1 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bSkill2 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bAttack && pNewTarget && nNewDistance <= 20) {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 75) { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; }
                else sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
            } else AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
        if (nDistance > 20) { AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7); return; }
        if (nDistance < 9 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 8, 0);
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pAi->dwAiParam[0] == 1) { AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7); return; }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
