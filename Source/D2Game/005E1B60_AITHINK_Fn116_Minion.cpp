#define MONMODE_ATTACK1 4
#define MONMODE_ATTACK2 5

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

struct D2AiControlStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
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

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit);                           // 0x0058EE80
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit);                       // 0x0058ED10

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x005E1B60
void __fastcall AITHINK_Fn116_Minion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    int bForced = 0;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1 && pCurrentAiCmd->nCmdParam[3] > pGame->dwGameFrame)
        {
            D2UnitStrc* pTargetUnit = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]);
            if (pTargetUnit && !SUNIT_IsDead(pTargetUnit))
            {
                bForced = 1;
                if (pTarget != pTargetUnit)
                {
                    pTarget = pTargetUnit;
                    sub_006416D0_UnitEdgeDistance(pUnit, pTargetUnit);
                    bCombat = UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
                }
            }
            else
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        else
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }

    if (bCombat)
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[1][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][pGame->nDifficulty]);
        }
    }
    else
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[2][pGame->nDifficulty])
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[3][pGame->nDifficulty]);
        }
    }
}
