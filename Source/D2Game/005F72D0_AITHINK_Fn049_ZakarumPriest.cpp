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
    char unk0x6E[0xA8 - 0x6E];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    char unk0x00[0x14];
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
    unsigned int unk0x0C[3];
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2ZakarumPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nMaxLifePercentage;
    int nMaxDistance;
    int unk0x10[6];
};

enum D2C_M197ZakarumPriestAi
{
    ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT = 1,
    ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT = 2,
    ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT = 3,
    ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER = 4,
    ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE = 5,
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                          // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                          // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AIUTIL_TargetCallback pfnCallback, int nCallbackId); // 0x005DD0B0
int __fastcall sub_005DD290_NoMissileBarrierCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget);              // 0x005DD290
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                              // 0x005DD2B0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback);
D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7240
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

static __forceinline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F72D0
void __fastcall AITHINK_Fn049_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    if (bCombat || sub_6FCF2E70(pUnit))
    {
        if (pMonStatsTxt->nSkill[2] >= 0 && nLifePercentage < 33 && pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + 4 * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);

            int nTargetX;
            int nShift = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            nTargetX = CLIENTS_GetUnitX(pTarget);
            int nTargetY = CLIENTS_GetUnitY(pTarget);
            if (bCombat)
            {
                nShift = 2;
            }

            nTargetX = ((nTargetX - nX) << nShift) + nTargetX;
            nTargetY = ((nTargetY - nY) << nShift) + nTargetY;

            if (sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY);
                return;
            }
        }

        if (bCombat && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }

    D2ZakarumPriestAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxLifePercentage = 0x7FFFFFFF;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE) * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE);
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_ZakarumPriest, 1);

    if (pMonStatsTxt->nSkill[0] >= 0 && arg.pTarget && (int)(AI_RollSeed(pSeed) % 100) < 25)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0);
        return;
    }

    if (sub_005DD290_NoMissileBarrierCollision(pUnit, pTarget))
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
                return;
            }

            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame + 20;
                return;
            }
        }
    }
    else
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT) && pMonStatsTxt->nSkill[3] >= 0
            && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < 30)
    {
        sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    }
}
