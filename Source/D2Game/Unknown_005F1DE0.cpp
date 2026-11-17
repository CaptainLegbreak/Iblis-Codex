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

enum D2C_M74ClawViperConstants
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    STATE_BLUE = 90,
    STATE_RED = 91,
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005FD470
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
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

enum D2C_ClawViperAIParams
{
    CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT = 0,
    CLAWVIPER_AI_PARAM_CHARGE_DISTANCE = 1,
    CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    CLAWVIPER_AI_PARAM_STALL_DURATION = 4,
    CLAWVIPER_AI_PARAM_CHARGE_COLOR = 5,
    CLAWVIPEREX_AI_PARAM_SHOOT_DISTANCE = 6,
    CLAWVIPEREX_AI_PARAM_SHOOT_TIMER = 7,
};

// 0x005F1DE0
void __fastcall AITHINK_Fn142_ClawViperEx(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->pAiControl->dwAiParam[0])
    {
        switch (AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 0);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 0);
            break;
        }
    }

    if (bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPEREX_AI_PARAM_SHOOT_DISTANCE))
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
        {
            if (pAiTickParam->pAiControl->dwAiParam[1] < pGame->dwGameFrame)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiTickParam->pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, CLAWVIPEREX_AI_PARAM_SHOOT_TIMER);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
            return;
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_DISTANCE)
        && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);

        switch (AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 1);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 1);
            break;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (AI_RollPercentage(pUnit) < 50)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
}
