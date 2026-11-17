struct D2GameStrc;
struct D2SeedStrc { union { struct { unsigned int nLowSeed, nHighSeed; }; unsigned __int64 lSeed; }; };
struct D2UnitStrc { int dwUnitType, dwClassId; void* pPool; unsigned int dwUnitId; int padding[4]; D2SeedStrc pSeed; };
struct D2AiControlStrc { int nAiSpecialState; int padding[4]; int dwAiParam[3]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; };
struct D2AiCmdStrc { D2AiCmdStrc* pNextCmd; D2AiCmdStrc* pPrevCmd; int nCmdParam[5]; };
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfn)(D2UnitStrc*, void*, void*)); // 0x0058F380
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3); // 0x005E5710
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DED90
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
static __forceinline unsigned __int64 Roll(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = nSeed;
    return nSeed;
}
static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)Roll(&pUnit->pSeed) % 100;
}
// 0x005E5870
void __fastcall AITHINK_Formation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc cmd;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2AiCmdStrc* pCurrentCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentCmd && pCurrentCmd->nCmdParam[0] == 8)
    {
        AIGENERAL_FreeMinionList(pUnit);
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    int bAnyDead = 0;
    AIGENERAL_ExecuteCallbackOnMinions(pUnit, &bAnyDead, 0, sub_6FCE4FD0);
    if (!sub_6FCF2E70(pUnit) && !bAnyDead)
    {
        if (AIGENERAL_GetMinionOwner(pUnit) == pUnit)
        {
            if (AI_RollPercentage(pUnit) < 30)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }
            int nPhase = pAiControl->dwAiParam[2] + 1;
            if (nPhase >= 100) nPhase = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            int nOffset = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 10);
            if (nPhase < 25)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += nOffset; nY -= 5;
            }
            if (nPhase >= 25 && nPhase < 50)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += 5; nY += nOffset;
            }
            if (nPhase >= 50 && nPhase < 75)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += nOffset; nY += 5;
            }
            if (nPhase >= 75)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX -= 5; nY += nOffset;
            }
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX, nY))
            {
                cmd.nCmdParam[0] = 2;
                cmd.nCmdParam[1] = nX;
                cmd.nCmdParam[2] = nY;
                AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &cmd);
            }
            else
            {
                nPhase += 25;
            }
            pAiControl->dwAiParam[2] = nPhase;
            return;
        }
        if (!pCurrentCmd)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
        int nX = pCurrentCmd->nCmdParam[1] + pAiControl->dwAiParam[0];
        int nY = pCurrentCmd->nCmdParam[2] + pAiControl->dwAiParam[1];
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nX, nY);
        return;
    }
    cmd.nCmdParam[0] = 8;
    AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &cmd);
    AIGENERAL_FreeMinionList(pUnit);
    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
