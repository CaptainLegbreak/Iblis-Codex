#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ItemsTxt;
struct D2ServerCallbackFunctions;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2CharStatsTxt;
struct D2ItemsTxtSpeed;
struct D2PlayerModeChartStrc;







extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554CA0
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY); // 0x0057F020
void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C9D90
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
D2ItemsTxtSpeed* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget); // 0x00648B90

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef void (__fastcall* PLRMODESTARTXY)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);

typedef void (__fastcall* PLRMODESTARTID)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget);

struct D2PlayerModeChartStrc
{
    PLRMODESTARTXY pfnStartXY;
    PLRMODESTARTID pfnStartID;
};

extern D2PlayerModeChartStrc gsPlayerModeChart_006E1740[]; // 0x006E1740
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_SetClientDead_6FC33830(D2ClientStrc* pClient, void* pArg); // 0x00538260
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2UnitStrc* __fastcall sub_0057F700(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2ActiveRoomStrc* pRoom); // 0x0057F700
void __fastcall D2GAME_KillPlayerPets_6FC7CD10(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575BC0
void __fastcall CLIENTS_ToggleFlag(D2ClientStrc* pClient, unsigned short nFlag, int bSet); // 0x00538650
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag); // 0x00538670
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pAttacker); // 0x00535AB0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall ITEMS_DropPlayerEar(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055A200
void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0054D8A0
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0053F720
void __fastcall PLAYER_StopInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005350F0

static __forceinline int sub_F05_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_GetInteractAction(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 ? pPlayer->pPlayerData->nMode : 0;
}

static __forceinline int sub_F05_GetInteractUnitType(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 && pPlayer->pPlayerData ? pPlayer->pPlayerData->nArg1 : 0;
}

static __forceinline int sub_F05_GetInteractUnitGUID(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 && pPlayer->pPlayerData ? pPlayer->pPlayerData->nArg2 : 0;
}

static __forceinline int sub_F05_IsInteracting(D2UnitStrc* pPlayer)
{
    if (!pPlayer || pPlayer->dwUnitType != 0 || !pPlayer->pPlayerData)
    {
        return 0;
    }

    return pPlayer->pPlayerData->nState;
}

static __forceinline void sub_F05_SetInteractFlag(D2UnitStrc* pPlayer, int nFlag)
{
    if (pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = nFlag;
    }
}

static __forceinline D2CharStatsTxt* sub_F05_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x0057F090
static void __stdcall sub_0057F090_StartMovement(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode)
{
    D2_ASSERT(ptGame, 0x138);

    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    PATH_ResetToPreviousType(pPath);

    switch (nMode)
    {
    case 3:
        if (STATLIST_UnitGetStatValue(pPlayer, 10, 0))
        {
            break;
        }
    case 2:
    case 6:
        nMode = DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)) != 0 ? 6 : 2;
        break;

    case 19:
        PATH_SetType(pPath, 8);
        D2COMMON_10190_PATH_SetDistance(pPath, 5);
        break;
    }

    D2Common_10142(pPath, pPlayer, 0);
    UNITS_SetUsedSkill(pPlayer, 0);

    if (!PATH_GetNumberOfPathPoints(pPath))
    {
        PLRMODE_StartXY_Neutral(ptGame, pPlayer, 1, 0, 0);
    }
    else
    {
        SUNIT_SetCombatMode(ptGame, pPlayer, nMode);
        D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(ptGame, pPlayer);
        SUNIT_ResetRecurringModeChangeEvent(ptGame, pPlayer);
    }
}

// 0x0057F1F0
void __fastcall PLRMODE_StartXY_WalkRunKnockback(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(ptGame, 0x17C);

    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    sub_0057F090_StartMovement(ptGame, pPlayer, nMode);
}

// build: context sub_0057F240_DrainRunStamina
static int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
    {
        return 1;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = sub_F05_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nStaminaLost = 2 * pCharStatsTxtRecord->nRunDrain;
    if (!pPlayer->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pTorsoArmor = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 3);
    if (pTorsoArmor)
    {
        D2ItemsTxtSpeed* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            nStaminaLost *= pItemsTxtRecord->dwSpeed / 10 + 1;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 0x9A, 0);
    if (nStaminaDrainPct)
    {
        nStaminaLost += nStaminaLost * nStaminaDrainPct / -100;
    }

    if (nStaminaLost < 1)
    {
        nStaminaLost = 1;
    }

    STATLIST_AddUnitStat(pPlayer, 10, -nStaminaLost, 0);

    if (STATLIST_UnitGetStatValue(pPlayer, 10, 0) <= 0)
    {
        STATLIST_SetUnitStat(pPlayer, 10, 0, 0);
        return 0;
    }

    return 1;
}

int __fastcall PLRMODE_UpdateMovement(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventCustomId, int nEventCustomParam)
{
    sub_6FCBC7E0(pGame, pPlayer);

    if (STATES_CheckState(pPlayer, 13))
    {
        SKILLS_CreateBlazeMissile(pGame, pPlayer);
    }

    if (pPlayer && pPlayer->dwAnimMode == 3 && !sub_0057F240_DrainRunStamina(pPlayer))
    {
        sub_0057F090_StartMovement(pGame, pPlayer, 2);
    }

    int nPathResult = SUNIT_UpdateUnitPath(pGame, pPlayer);
    const unsigned int nTickCount = GetTickCount();
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (nTickCount > pPlayerData->dwPositionHistoryTick + 25)
    {
        const unsigned char nHistoryIndex = pPlayerData->nPositionHistoryIndex;
        unsigned char nPreviousIndex;
        if (!nHistoryIndex)
        {
            nPreviousIndex = 19;
        }
        else
        {
            nPreviousIndex = nHistoryIndex - 1;
        }

        const int nPlayerX = sub_F05_PlrGetUnitX(pPlayer);
        const int nPlayerY = sub_F05_PlrGetUnitY(pPlayer);
        if (PATH_ComputeSquaredDistance(nPlayerX, nPlayerY, pPlayerData->pPositionHistory[nPreviousIndex].nX, pPlayerData->pPositionHistory[nPreviousIndex].nY) > 45)
        {
            pPlayerData->pPositionHistory[nHistoryIndex].nX = nPlayerX;
            pPlayerData->pPositionHistory[nHistoryIndex].nY = nPlayerY;
            pPlayerData->dwPositionHistoryTick = nTickCount;

            ++pPlayerData->nPositionHistoryIndex;
            if (pPlayerData->nPositionHistoryIndex >= 20)
            {
                pPlayerData->nPositionHistoryIndex = 0;
            }
        }
    }

    if (nPathResult == 2)
    {
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData && pPlayer->pPlayerData->nState)
        {
            const int nAction = sub_F05_GetInteractAction(pPlayer);
            if (nAction >= 0)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nAction);
                if (pSkill)
                {
                    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pPlayer, pSkill);
                    StartModeID(pGame, pPlayer, pSkill, nSkillMode, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), 0);
                    nPathResult = 1;
                }
                else
                {
                    PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                }
            }
            else
            {
                PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                sub_6FC828D0(pPlayer, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), nAction == -2, pGame);
            }

            sub_F05_SetInteractFlag(pPlayer, 0);
            return nPathResult;
        }

        PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
    }

    return nPathResult;
}

// 0x0057F190
void __fastcall PLRMODE_StartID_WalkRunKnockback(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptGame, 0x16E);

    const int nCurMode = nMode;
    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    if (nCurMode != 19 || pPlayer->dwAnimMode != nCurMode)
    {
        sub_00648B90_SetPathTarget(pPath, pTargetUnit);
        sub_0057F090_StartMovement(ptGame, pPlayer, nCurMode);
    }
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0057F330
static void sub_6FC814F0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    STATLIST_SetUnitStat(pPlayer, 0x06, 0, 0);
    D2Common_10469(pPlayer);
    STATES_UpdateStayDeathFlags(pPlayer, 0);
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x234);
    D2GAME_SetClientDead_6FC33830(pClient, 0);
    PATH_SetUnitDeadCollision(pPlayer, 1);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x08, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x09, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
}

// 0x0057FCA0
void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY)
{
    sub_0057F700(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetRoom(pUnit));
    D2GAME_KillPlayerPets_6FC7CD10(pGame, pUnit);

    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x434);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);

    if (!gpD2EventCallbackTable_6FD45830 || CLIENTS_CheckFlag(pClient, 0x04))
    {
        D2GAME_SAVE_WriteFile_6FC8A500(pGame, pUnit, CLIENTS_GetName(UnitGetClient(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x43A)), 0);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 0x11);
    sub_6FCBC4D0(pUnit);
    sub_6FC814F0(pGame, pUnit);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pUnit);
}

// 0x00580EC0
void __fastcall PLRMODE_StartID_Death(D2GameStrc* pGame, D2UnitStrc* pDefender, int nMode, D2UnitStrc* pAttacker)
{
    bool bIsDruid = false;
    if (pDefender && pDefender->dwUnitType == 0 && pDefender->dwClassId == 0x05)
    {
        bIsDruid = true;
    }

    if (SKILLS_RemoveTransformStatesFromShapeshiftedUnit(pDefender) && bIsDruid)
    {
        D2_ASSERT(pGame, 0x805);

        if (pDefender->pInventory && INVENTORY_GetCursorItem(pDefender->pInventory))
        {
            return;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[1].pfnStartXY), 0x812);

        gsPlayerModeChart_006E1740[1].pfnStartXY(pGame, pDefender, 1, 0, 0);
        return;
    }

    PLAYER_ApplyDeathPenalty(pGame, pDefender, pAttacker);
    SUNIT_SetCombatMode(pGame, pDefender, 0);
    D2ClientStrc* pClient = UnitGetClient(pDefender, ".\\PLAYER\\PlrModes.cpp", 0x40B);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);
    sub_6FCBC4D0(pDefender);
    sub_6FC814F0(pGame, pDefender);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pDefender);
    sub_6FCBCE70(pGame, pDefender);

    if (!STATES_CheckState(pDefender, 0x07) && pDefender)
    {
        pDefender->dwFlags &= ~0x02;
    }

    if (pDefender && pAttacker && pDefender->dwUnitType == 0 && pDefender != pAttacker)
    {
        D2UnitStrc* pOwner;
        if (pAttacker->dwUnitType == 0
            || pAttacker->dwUnitType == 1 && (pOwner = AIGENERAL_GetMinionOwner(pAttacker)) != 0 && pOwner->dwUnitType == 0 && pOwner != pDefender)
        {
            ITEMS_DropPlayerEar(pGame, pDefender);
        }
    }

    if (pAttacker)
    {
        D2GAME_PLRMSG_Last_6FC89450(pGame, pAttacker, pDefender);
        ARENA_ProcessKillEvent(pGame, pAttacker, pDefender);
    }

    PLAYER_StopInteractions(pGame, pDefender);
}
