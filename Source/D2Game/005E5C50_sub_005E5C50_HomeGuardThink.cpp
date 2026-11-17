struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2AiParamStrc;
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2MonsterDataStrc { char pad00[0x2C]; D2AiParamStrc* pAiParam; };
struct D2StaticPathStrc { char pad00[0xC]; int nX; int nY; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMem; int dwUnitId; int dwAnimMode; D2MonsterDataStrc* pMonsterData; char pad18[8]; D2SeedStrc pSeed; int unk28; union { D2StaticPathStrc* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };
struct D2GameStrc { char pad00[0x6D]; unsigned char nDifficulty; };
struct D2MonStatsTxt { char pad00[0x56]; short wAiParam[8][3]; };
struct D2AiTickParamStrc { void* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2AiCmdStrc { D2AiCmdStrc* pNext; D2AiCmdStrc* pPrev; int nCmdParam[5]; };
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId); // 0x00540E60
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmd, int bSet); // 0x0058EEF0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pCmd); // 0x0058EF40
void __fastcall D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(D2AiParamStrc* pAiParam, int nFlags, int nVelocity, unsigned char nUnused); // 0x005A6260
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int nFlags, int nVelocity, unsigned char nUnused); // 0x005DE190
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DED20
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEDE0
int __fastcall sub_6FCE5520(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E5B70
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
static __forceinline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nX; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}
static __forceinline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nY; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}
static __forceinline D2AiParamStrc* GetAiParam(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData ? pUnit->pMonsterData->pAiParam : 0;
}
// 0x005E5C50
void __fastcall sub_005E5C50_HomeGuardThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    if (!pMonStats) return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom) return;
    D2UnitStrc* pTarget = pTick->pTarget;
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd)
    {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        cmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    if (!pCmd->nCmdParam[1] || !pCmd->nCmdParam[2])
    {
        pCmd->nCmdParam[1] = GetX(pUnit);
        pCmd->nCmdParam[2] = GetY(pUnit);
    }
    int nRegion = D2Common_10095(pRoom, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
    if (nRegion != D2Common_10095(pRoom, GetX(pUnit), GetY(pUnit)))
    {
        D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if (nRegion != D2Common_10095(pRoom, GetX(pTarget), GetY(pTarget)))
    {
        if (CLIENTS_GetUnitX(pUnit) == pCmd->nCmdParam[1] && CLIENTS_GetUnitY(pUnit) == pCmd->nCmdParam[2])
        {
            if (nDistance < 25 && sub_6FCE5520(pGame, pUnit, pTick)) return;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 40)
    {
        D2GAME_MONSTERMODE_SetVelocityParams_6FC62FC0(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if (sub_6FCE5520(pGame, pUnit, pTick)) return;
    int nDifficulty = pGame->nDifficulty;
    int nRoll = (int)SEED_RollLimitedRandomNumber(pSeed, 100);
    if (bCombat)
    {
        if (nRoll < pMonStats->wAiParam[2][nDifficulty] + 10)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][nDifficulty]);
        return;
    }
    if (nRoll < pMonStats->wAiParam[0][nDifficulty])
    {
        AITACTICS_SetVelocity(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][nDifficulty]);
}
