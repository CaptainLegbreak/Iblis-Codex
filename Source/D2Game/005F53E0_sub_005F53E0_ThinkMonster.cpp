struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2UnitStrc { int dwUnitType, dwClassId; void* pPool; unsigned int dwUnitId; int padding[4]; D2SeedStrc pSeed; };
struct D2GameStrc { char pad0[0x6D]; unsigned char nDifficulty; };
struct D2AiControlStrc { int nAiSpecialState; int padding[4]; int dwAiParam[3]; };
struct D2MonStatsTxt { char pad0[0x56]; short nAiParam[8][3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2AiCmdStrc { D2AiCmdStrc* pNextCmd; D2AiCmdStrc* pPrevCmd; int nCmdParam[5]; };
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc*, D2UnitStrc*); // 0x0058ED10
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DEC80
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
int __fastcall sub_005DF7D0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005DF7D0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90
static __forceinline int RollPercentage(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed % 100;
}
static short AI_GetParam(D2GameStrc* pGame, D2MonStatsTxt* pRecord, int nIndex)
{
    return pRecord->nAiParam[nIndex][pGame->nDifficulty];
}
// 0x005F53E0
void __fastcall sub_005F53E0_ThinkMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* const pUnitSeed = &pUnit->pSeed;
    const int nTargetDistance = pTick->nTargetDistance;
    const int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pRecord = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2AiCmdStrc* pCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCmd)
    {
        if (pCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetVelocity(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        if (pCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetVelocity(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pTarget);
    switch (pAi->dwAiParam[0])
    {
    case 2:
        if (nTargetDistance > 12)
        {
            ++pAi->dwAiParam[1];
            if (pAi->dwAiParam[1] > 1)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
            }
            if (RollPercentage(pUnitSeed) < 20)
                sub_005DF7D0(pGame, pUnit, pTarget, 4, 0);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_SetVelocity(pUnit, 2, 50, 0);
        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 14, 1))
            return;
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        break;
    case 1:
        ++pAi->dwAiParam[1];
        if (pAi->dwAiParam[1] > AI_GetParam(pGame, pRecord, 2) && nLife > AI_GetParam(pGame, pRecord, 3))
        {
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = 0;
            AITACTICS_SetVelocity(pUnit, 2, 50, 0);
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 14, 1);
            return;
        }
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pUnitSeed, 100) < pRecord->nAiParam[0][pGame->nDifficulty])
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pRecord->nAiParam[1][pGame->nDifficulty]);
            return;
        }
        AITACTICS_SetVelocity(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    case 0:
        if (bCombat)
        {
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[0] = 1;
            if (RollPercentage(pUnitSeed) < AI_GetParam(pGame, pRecord, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pRecord, 1));
                return;
            }
        }
        AITACTICS_SetVelocity(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
