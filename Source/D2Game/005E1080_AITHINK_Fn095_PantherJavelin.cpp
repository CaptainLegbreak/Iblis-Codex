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

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M80PantherJavelinAi
{
    MONMODE_ATTACK1 = 4,
    PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT = 1,
    PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE = 2,
    PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT = 3,
    PANTHERJAVELIN_AI_PARAM_STALL_DURATION = 4,
    PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE = 5,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1080
void __fastcall AITHINK_Fn095_PantherJavelin(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2UnitStrc* pTargetUnit = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);

    if (nDistance < 8 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 16, 1);
        return;
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE) - 6 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTickTarget, 4);
        return;
    }

    if (!pTargetUnit || nDistance >= AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE))
    {
        D2PantherAiCallbackArgStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;

        sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

        if (arg.pTarget && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, arg.pTarget, 7);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
}
