#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2ItemsWorld.h"
struct D2UnitStrc;
struct D2AiParamStrc;
union D2SeedStrc;
struct D2AiCmdStrc;
struct D2MonsterDataStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonRegDataStrc;
struct D2MonsterRegionStrc;

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

struct D2MonsterDataStrc { char pad00[0x2C]; D2AiParamStrc* pAiParam; };

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned int dwMonStatsFlags;
    unsigned char unk_10[0x46];
    short wAiParam[8][3];
    unsigned char unk_86[0x122];
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId); // 0x00540E60
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmd, int bSet); // 0x0058EEF0
void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pCmd); // 0x0058EF40
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int nFlags, int nVelocity, unsigned char nUnused); // 0x005A6260
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DED20
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEDE0
int __fastcall sub_6FCE5520(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E5B70
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall sub_00573520_GetLevelIdFromUnit(D2UnitStrc* pUnit); // 0x00573520
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** pMonReg, int nLevelId); // 0x00547BB0

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

static __forceinline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}

static __forceinline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

static __forceinline D2AiParamStrc* GetAiParam(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pAiParam : 0;
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
        sub_005A6260_SetAiParamFields(GetAiParam(pUnit), 1, 0, 0);
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
        sub_005A6260_SetAiParamFields(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 40)
    {
        sub_005A6260_SetAiParamFields(GetAiParam(pUnit), 1, 0, 0);
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
        sub_005DE190_SetAiParam(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][nDifficulty]);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (nMax & (nMax - 1))
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (!(nMonsterId >= 0))
        return 0;
    if (!(nMonsterId < sgptDataTables->nMonStatsTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

static __forceinline unsigned int TestMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return ((unsigned char*)&pMonStatsTxtRecord->dwMonStatsFlags)[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x005E6020
bool __fastcall sub_005E6020_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId)
{
    *pClassId = 453 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 453;

    int const nLevelId = sub_00573520_GetLevelIdFromUnit(pUnit);
    D2MonsterRegionStrc* pMonRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevelId);
    const int nMonsterId = pMonRegion->pMonData[SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMonRegion->nMonCount)].nMonHcIdx;
    if (TestMonStatsFlag(nMonsterId, 21))
    {
        *pClassId = nMonsterId;
        return true;
    }

    for (int i = 0; i < pMonRegion->nMonCount; ++i)
    {
        const int nId = pMonRegion->pMonData[i].nMonHcIdx;
        if (TestMonStatsFlag(nId, 21))
        {
            *pClassId = nId;
            return true;
        }
    }

    *pClassId = 496 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 496;
    return true;
}
