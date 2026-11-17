struct D2AiTickParamStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
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
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
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

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                          // 0x005DD280
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int nVelocity, short nMaxVelocity, int nAcceleration); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nSteps); // 0x005DEF80
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nDistance, int bUnk); // 0x005DEFE0
int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nSteps, int a5); // 0x005DF7D0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

// 0x005EFF50
void __fastcall AITHINK_Fn004_Bighead(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bInMeleeRange;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!bCombat && sub_6FCF2E70(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
        return;
    }

    if (UNITS_GetCurrentLifePercentage(pUnit) >= AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (nTargetDistance < 15 && AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
    }
    else
    {
        if (nTargetDistance < 3)
        {
            AITACTICS_SetVelocity(pUnit, 0, 50, 0);
            if (!D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 5, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            }
        }
        else
        {
            if (nTargetDistance > 15)
            {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 6);
                return;
            }

            if (AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= AI_PARAM(pGame, pMonStatsTxt, 1))
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
            else
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            }
        }
    }
}
