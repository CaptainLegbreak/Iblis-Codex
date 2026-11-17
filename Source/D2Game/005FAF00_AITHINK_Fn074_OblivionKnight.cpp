struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x4];
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x8];
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

struct D2SkillsTxt
{
    char unk0x000[0x80];
    short nAuraState;
    short wAuraTargetState;
    char unk0x084[0x1B8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2OblivionKnightAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    int unk0x14[5];
};

enum D2C_M408OblivionKnightAi
{
    UNIT_MONSTER = 1,
    OBLIVIONKNIGHT_AI_PARAM_FLEE_RANGE = 0,
    OBLIVIONKNIGHT_AI_PARAM_ENGAGE_RANGE = 1,
    OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER = 2,
    OBLIVIONKNIGHT_AI_PARAM_CURSE_CHANCE_PCT = 3,
    OBLIVIONKNIGHT_AI_PARAM_SHOOT_CHANCE_PCT = 4,
    OBLIVIONKNIGHT_AI_PARAM_BONESPIRIT_CHANCE_PCT = 5,
    OBLIVIONKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT = 6,
    OBLIVIONKNIGHT_AI_PARAM_APPROACH_DISTANCE = 7,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                          // 0x005B0BD0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
D2UnitStrc* __fastcall AITHINK_TargetCallback_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005FAE40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005FAF00
void __fastcall AITHINK_Fn074_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2OblivionKnightAiCallbackArgStrc arg;
    int nDistance;

    arg.unk0x00 = 0;
    arg.unk0x04 = 0;
    arg.unk0x08 = 2500;
    arg.unk0x0C = 0x7FFFFFFF;
    arg.unk0x10 = 0x7FFFFFFF;
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_OblivionKnight, 1);

    D2UnitStrc* pAllyTarget = arg.unk0x00;

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_FLEE_RANGE))
    {
        if (pMonStatsTxt->nSkill[3] > 0)
        {
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[3]);
            if (pSkillsTxtRecord && pSkillsTxtRecord->wAuraTargetState > 0 && !STATES_CheckState(pTickTarget, pSkillsTxtRecord->wAuraTargetState))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTickTarget, 0, 0);
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER);
                return;
            }
        }

        if (pAllyTarget)
        {
            if (AITHINK_GetSquaredDistance(pAllyTarget, pTickTarget) > nTargetDistance * nTargetDistance && AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pAllyTarget, 4))
            {
                return;
            }
        }

        AITACTICS_SetVelocity(pUnit, 2, 50, 0);

        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 10, 1))
        {
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTickTarget, 0, 0);
            return;
        }
    }

    D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
    if (pTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_ENGAGE_RANGE))
    {
        if (pMonStatsTxt->nSkill[5] > 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[5], pMonStatsTxt->nSkill[5], pTickTarget, 0, 0);
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER);
            return;
        }

        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_BONESPIRIT_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0)
            {
                if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || pUnit->pMonsterData->nComponent[10] < 4u)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                    return;
                }
            }
        }
    }

    if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_APPROACH_DISTANCE))
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTickTarget, 6);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 70)
    {
        sub_005DF7D0(pGame, pUnit, pTickTarget, 3, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
