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

struct D2StatListStrc;

enum D2C_M101SuccubusConstants
{
    UNIT_PLAYER = 0,
    MONMODE_ATTACK1 = 4,
};

enum D2C_SuccubusAIParams
{
    SUCCUBUS_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SUCCUBUS_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    SUCCUBUS_AI_PARAM_CURSE_CHANCE_PCT = 2,
    SUCCUBUS_AI_PARAM_CURSE_RANGE = 3,
    SUCCUBUS_AI_PARAM_MELEE_STALL_DURATION = 4,
    SUCCUBUS_AI_PARAM_RANGED_STALL_DURATION = 5,
    SUCCUBUS_AI_PARAM_CURSE_LEVEL = 6,
    SUCCUBUS_AI_PARAM_CURSE2_LEVEL = 7,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1E00
void __fastcall AITHINK_Fn118_Succubus(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20) && nDistance < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_RANGE)
        && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[0] > 0 && UNITS_GetCurrentLifePercentage(pTarget) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[1] > 0 && UNITS_GetCurrentLifePercentage(pUnit) <= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] > 0)
        {
            if (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || !pTarget || pTarget->dwUnitType != UNIT_PLAYER)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] > 0 && pTarget && pTarget->dwUnitType == UNIT_PLAYER)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[4] > 0 && AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL) > 0)
    {
        D2UnitStrc* pFoundTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
        if (pFoundTarget && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pFoundTarget, 0, 0);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_RANGED_STALL_DURATION));
}
