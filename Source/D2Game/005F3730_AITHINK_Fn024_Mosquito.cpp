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

enum D2C_MosquitoAIParams
{
    MOSQUITO_AI_PARAM_MIN_SUCK_LOOP = 0,
    MOSQUITO_AI_PARAM_SUCK_LOOP_RNG = 1,
    MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT = 3,
    MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP = 4,
};

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMaxDistance);         // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F3730
void __fastcall AITHINK_Fn024_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT) || !pAiControl->dwAiParam[1])
        {
            ++pAiControl->dwAiParam[1];

            if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (AI_RollPercentage(pUnit) > 20)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[1] = 0;
    }

    if (pAiControl->dwAiParam[0] == 0)
    {
        AITACTICS_SetVelocity(pUnit, 13, 100, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
    }
    else if (pAiControl->dwAiParam[0] == 1)
    {
        AITACTICS_SetVelocity(pUnit, 0, 50, 0);
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP))
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
    }
    else if (pAiControl->dwAiParam[0] == 2)
    {
        AITACTICS_SetVelocity(pUnit, 2, 100, 0);
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 10, 1);
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;
    }
    else
    {
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}
