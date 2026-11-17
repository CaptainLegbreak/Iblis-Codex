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

struct D2ActiveRoomStrc;
struct D2AiControlStrc;

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
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

struct D2PlayerCountBonusStrc
{
    int nHp;
    int nExperience;
    int nMonsterSkillBonus;
    int nDifficulty;
    int nPlayerCount;
};

enum D2C_CorruptRogueAIParams
{
    CORRUPTROGUE_AI_PARAM_APPROACH = 0,
    CORRUPTROGUE_AI_PARAM_STALL_DURATION = 1,
    CORRUPTROGUE_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    CORRUPTROGUE_AI_PARAM_RUN_VELOCITY = 3,
    CORRUPTROGUE_AI_PARAM_RUN_CHANCE_PCT = 4,
};

enum D2C_M85RogueConstants
{
    MONMODE_ATTACK1 = 4,
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster); // 0x00573930
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEFB0

static __forceinline int AI_RollPercentageInline(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

// 0x005F0B00
void __fastcall AITHINK_Fn010_CorruptRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2PlayerCountBonusStrc playerCountBonus;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    MONSTER_GetPlayerCountBonus(pGame, &playerCountBonus, UNITS_GetRoom(pUnit), pUnit);

    if (nTargetDistance > 20 - 3 * playerCountBonus.nDifficulty)
    {
        AITACTICS_SetVelocity(pUnit, 13, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_VELOCITY), 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
        return;
    }

    if (bCombat)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_STALL_DURATION));
        }
        return;
    }

    if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_APPROACH))
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_CHANCE_PCT))
        {
            AITACTICS_SetVelocity(pUnit, 13, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_VELOCITY), 0);
            AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
            return;
        }
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_STALL_DURATION));
}
