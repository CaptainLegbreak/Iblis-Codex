#include "D2ObjectIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2PlayerModes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GfxLightStrc;
struct Unicode;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2MonsterDataStrc;
struct D2PlayerCmdStrc;
struct D2SkillRefStrc;
struct D2SkillsTxt;
struct D2ClientEntryStrc;
struct D2MonStatsTxt;
struct D2StringRefStrc;

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);



extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern void* gpDrlgAct_007A0634;
// build: symbol ?gnInTown@* 0x007A5260
extern int gnInTown;
// build: symbol ?gdwLastClampTick@* 0x007A5268
extern unsigned int gdwLastClampTick;
// build: symbol ?gbPlayerCommandPending@* 0x007A5264
extern int gbPlayerCommandPending;
// build: symbol ?gnStringCount@* 0x00711EF0
extern int gnStringCount;
// build: symbol ?gaStringRefs@* 0x00711DDC
extern D2StringRefStrc gaStringRefs[];
// build: symbol _gszPlayerCpp 0x006D6A34
extern "C" const char gszPlayerCpp[];
unsigned int __cdecl GAME_SetClickHandled(); // 0x0044BEF0
unsigned int __cdecl sub_0044DA90();
unsigned int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0
unsigned int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0
void __fastcall GAME_SetInteractDeadline(unsigned int nValue); // 0x0044DAD0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);
void __cdecl UI_CancelCursorItemUse();
int __fastcall GAME_GetUIVarState(int nUIVar); // 0x004538D0
void __fastcall AUTOMAP_ScreenToMap(int* pX, int* pY); // 0x0045AFF0
void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
int __stdcall PLAYER_IsPendingMode(int nArg1, int nArg2); // 0x00461D60
int __fastcall CUNIT_CanUseSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00464600
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __cdecl SELECT_ClearSelection(); // 0x00466FE0
D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10
void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830();
int __fastcall sub_00474080_GetDistance(int nDX, int nDY);
void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680
void __fastcall MSG_SendFourDwords(char nCommand, int nUnitType, int nUnitId, int nX, int nY); // 0x00478700
int __cdecl INV_GetScreenHeightMinusPanel(); // 0x00454970
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);
void __fastcall VIEW_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x00460780
int __fastcall AUTOMAP_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance);
int __fastcall PLAYER_FilterCommandMessage(D2PlayerCmdStrc* pCmd); // 0x00462930
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00463D90(int nArg);
D2UnitStrc* __cdecl sub_00463DD0();
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930
void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg); // 0x00466CB0
void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410
int __cdecl sub_00468740();

struct D2ActiveRoomStrc { char unknown0[76]; int x, y, width, height; };

void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);
void __fastcall GFX_RemoveAiTargetUnit(D2UnitStrc* pUnit); // 0x0046C700
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10
void __fastcall GFX_PruneGfxNodes(D2UnitStrc* pUnit); // 0x0046ECE0
void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, char nValue); // 0x0046F020
void __fastcall sub_00473C90_SetGlobal(int nValue);
void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0
D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey); // 0x00478E40
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall UNITMODE_DoUnitAction(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00481030
void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit); // 0x004B3E10
void __cdecl ITEM_ResetWeaponClasses(); // 0x004C1E30
void __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
int __stdcall sub_0061AA40(D2ActiveRoomStrc* pRoom);
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);
void __stdcall sub_0061ACD0_SetRoomPos(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);
void __stdcall sub_0061AF10(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom);
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);
void __stdcall sub_00620E40_GetClassSpeed(D2UnitStrc* pUnit, int nClassId, int* pSpeed, int* pBase);
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer);
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);
int __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);
int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath);
int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath);
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);
void __stdcall D2Common_10228(D2UnitStrc* pUnit);
void __stdcall sub_00649F70(D2UnitStrc* pUnit, int nArg);
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask);
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms);
void __cdecl PLAYER_RefreshAdjacentPlayers(); // 0x004608C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*, D2ActiveRoomStrc***, int*); // 0x00619790
extern D2UnitStrc* gapClientUnitTable[6 * 0x80]; // 0x007A5E70
extern D2UnitStrc* gapServerUnitTable[6 * 0x80]; // 0x007A5270

// build: symbol ?PLAYER_SetModeAndSync@* 0x00460830
static void __stdcall PLAYER_SetModeAndSync(int bSync, int nState, D2UnitStrc* pUnit)
{
    UNITMODE_SetUnitMode(pUnit, nState);
    if (!bSync)
        return;

    if (pUnit != sub_00463DE0_GetStoredUnit())
        return;

    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    if (nX && nY)
        UNITMODE_SetPosition(pUnit, nX, nY, 0, 0, 0);
}

// build: symbol ?PLAYER_FreeClientPlayer@* 0x00460D50
void __fastcall PLAYER_FreeClientPlayer(D2UnitStrc* pUnit)
{
    GFX_RemoveAiTargetUnit(pUnit);
    GFX_FreeGfxData(pUnit);
    if (gpDrlgAct_007A0634)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;
    CUNIT_RemoveInventoryUnits(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
        DLIGHTMAP_ReleaseLight(pResource);
    CUNIT_FreeLight(pUnit);
    if (pUnit == sub_00463DD0())
        sub_00463D90(0);
    UNITS_FreePlayerData(0, pUnit);
    PLAYER_RefreshAdjacentPlayers();
}

// build: symbol ?PLAYER_UpdateRoomPosition@* 0x00460DE0
static void PLAYER_UpdateRoomPosition(D2UnitStrc* pUnit)
{
    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    sub_0061ACD0_SetRoomPos(pRoom, nX, nY, UNITS_IsCurrentRoomInvalid(pUnit));
}

// build: symbol ?PLAYER_UpdateRoomState@* 0x00460E70
static void PLAYER_UpdateRoomState(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nPortalFlags = UNITS_GetPlayerPortalFlags(pUnit);
    nPortalFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
    UNITS_SetPlayerPortalFlags(pUnit, nPortalFlags);
    sub_0061AF10(gpDrlgAct_007A0634, PATH_GetNextRoom(pUnit->pDynamicPath), UNITS_GetRoom(pUnit));
    const int bInTown = DUNGEON_IsRoomInTown(pRoom) != 0;
    if (gnInTown != bInTown && !bInTown)
        NPCMENU_RefreshNpcEntries(pUnit);
    gnInTown = bInTown;
    sub_00473C90_SetGlobal(sub_0061AA40(pRoom));
    sub_0046BF30_CheckThroneLevel(pRoom);
}

// build: symbol ?PLAYER_PlaceOnFreeCoords@* 0x00460F10
static void PLAYER_PlaceOnFreeCoords(D2UnitStrc* pUnit)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    switch (nMode)
    {
    case 1:
    case 5:
        break;
    default:
        return;
    }

    D2CoordStrc tCoords;
    UNIT_GETX_K5(pUnit, tCoords.nX);
    UNIT_GETY_K5(pUnit, tCoords.nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    if (!COLLISION_CheckMaskWithPattern(pRoom, tCoords.nX, tCoords.nY, PATH_GetUnitCollisionPattern(pUnit), 0xC01))
        return;

    COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0xC01, 1);
    CUNIT_SetUnitPosition(pUnit, tCoords.nX, tCoords.nY, 0);
}

void PLAYER_ResetPlayerState(D2UnitStrc* pUnit); // 0x00461010

// build: symbol ?PLAYER_RequestSkillString@* 0x00461070
static void __stdcall PLAYER_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs[nIndex].nStringId;
    if (nStringId)
        UNITSND_PlayPlayerSpeech(pUnit, nStringId);
}

// build: symbol ?PLAYER_CheckSkillUse@* 0x004610C0
static int __stdcall PLAYER_CheckSkillUse(int* pUseState, D2SkillStrc** ppSkill, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_ATTACK);
        nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    PLAYER_RequestSkillString(pUnit, nUseState);
    return 0;
}

// build: symbol ?PLAYER_CheckCommandSkill@* 0x00461160
static int PLAYER_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return PLAYER_CheckSkillUse(pUseState, &pCmd->pSkill, pCmd->pPlayer);
}

// build: symbol ?PLAYER_RefreshSkillRef@* 0x00461180
static int __stdcall PLAYER_RefreshSkillRef(int* pUseState, D2UnitStrc* pUnit, D2SkillRefStrc* pRef)
{
    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, pRef->nSkillId, pRef->nOwnerGUID);
    if (!pSkill)
        return 1;

    if (!PLAYER_CheckSkillUse(pUseState, &pSkill, pUnit))
        return 0;

    const int nOldSkillId = pRef->nSkillId;
    pRef->nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp, 0x32C);
    if (pRef->nSkillId != nOldSkillId)
        pRef->nOwnerGUID = -1;
    return 1;
}

void __stdcall PLAYER_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit); // 0x004611F0

// build: symbol ?PLAYER_SendCommand@* 0x00461700
static void __stdcall PLAYER_SendCommand(int bTarget, D2PlayerCmdStrc* pCmd)
{
    if (sub_00468740() > INV_GetScreenHeightMinusPanel())
        return;

    if (bTarget == 1)
    {
        D2UnitStrc* pTarget = pCmd->pTarget;
        int nId;
        int nType = 6;
        if (pTarget)
        {
            nType = pTarget->dwUnitType;
            nId = pTarget->dwUnitId;
        }
        else
        {
            nId = -1;
        }
        if (pCmd->dwFlags & 1)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0xA, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(7, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(9, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(6, pCmd->pPlayer, nType, nId, 0);
            }
        }
        if (pCmd->dwFlags & 2)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0x11, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(0xE, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    UNITMODE_DoUnitAction(0x10, pCmd->pPlayer, nType, nId, 0);
                else
                    UNITMODE_DoUnitAction(0xD, pCmd->pPlayer, nType, nId, 0);
            }
        }
        return;
    }

    if (pCmd->dwFlags & 1)
    {
        if (pCmd->dwFlags & 8)
            UNITMODE_DoUnitAction(8, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            UNITMODE_DoUnitAction(5, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
    if (pCmd->dwFlags & 2)
    {
        if (pCmd->dwFlags & 8)
            UNITMODE_DoUnitAction(0xF, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            UNITMODE_DoUnitAction(0xC, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
}

// build: symbol ?PLAYER_WalkTo@* 0x00461840
static int __stdcall PLAYER_WalkTo(int nMode, D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    if (!D2Common_10142(pPath, pUnit, 0))
        return 0;

    const int nTargetX = sub_00648A40_GetTargetX(pPath);
    const int nTargetY = sub_00648A60_GetTargetY(pPath);
    UNITMODE_DoUnitAction(nMode, pUnit, nTargetX, nTargetY, 0);
    return 1;
}

// build: symbol ?PLAYER_OperateObject@* 0x00461890
static void __stdcall PLAYER_OperateObject(int nObjectId, D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pObject = CUNIT_FindClientUnit(nObjectId, 2);
    if (!pObject)
        return;

    D2_ASSERT(DATATBLS_GetObjectsTxtRecord(pObject->dwClassId), 0x4C4);
    int bSetMode = 1;
    if (pObject->dwClassId == OBJECT_TOWN_PORTAL && STATES_CheckState(sub_00463DD0(), STATE_JUST_PORTALED))
        bSetMode = 0;

    if (UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
    {
        if (bSetMode)
            UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, 2, nObjectId, 0);
        return;
    }

    int nY;
    UNIT_GETY(pCmd->pTarget, nY);
    int nX;
    UNIT_GETX(pCmd->pTarget, nX);
    PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, nX, nY);
    if (bSetMode)
        VIEW_SetPlayerMode(0x13, pCmd->pPlayer, 2, nObjectId);
}

// build: symbol ?PLAYER_InteractWithTarget@* 0x004619E0
static void PLAYER_InteractWithTarget(D2PlayerCmdStrc* pCmd, int nTargetId)
{
    switch (D2Common_10399(pCmd->pTarget, pCmd->pPlayer))
    {
    case 0:
    case 1:
    case 2:
        if (!sub_00622B50_TestInteractCollision(pCmd->pTarget, pCmd->pPlayer, 0x804))
        {
            UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, 0, nTargetId, 0);
            return;
        }
        break;
    }

    UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, 0, nTargetId, 0);
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = 1;
        pPlayer->pPlayerData->nMode = 0x13;
        pPlayer->pPlayerData->nArg1 = 0;
        pPlayer->pPlayerData->nArg2 = nTargetId;
    }
}

// build: symbol ?PLAYER_InteractWithUnitTarget@* 0x00461A70
void __fastcall PLAYER_InteractWithUnitTarget(D2UnitStrc* pUnit)
{
    D2PlayerCmdStrc tCmd;
    tCmd.pTarget = pUnit;
    tCmd.pPlayer = sub_00463DD0();
    tCmd.nMode = 2;
    PLAYER_InteractWithTarget(&tCmd, !pUnit ? -1 : pUnit->dwUnitId);
}

// build: symbol ?PLAYER_ApproachForAura@* 0x00461B40
static int PLAYER_ApproachForAura(D2PlayerCmdStrc* pCmd, int nArg1, int nArg2)
{
    int nRange = 0;
    int nDistance = 0;
    D2_ASSERT(pCmd->pTarget, 0x52F);
    D2_ASSERT(pCmd->pPlayer, 0x530);
    if (pCmd->dwFlags & 0x20)
    {
        PLAYER_SendCommand(1, pCmd);
        return 1;
    }

    if (AUTOMAP_IsInAuraRange(pCmd->pSkill, pCmd->pTarget, &nRange, &nDistance))
    {
        PLAYER_SendCommand(1, pCmd);
        return 1;
    }

    if (pCmd->dwFlags & 1)
        VIEW_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
    if (pCmd->dwFlags & 2)
        VIEW_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);

    const int nDelta = nDistance - nRange;
    D2_ASSERT(nDelta > 0, 0x548);
    D2_ASSERT(nDistance, 0x549);
    const int nPlayerX = CLIENTS_GetUnitX(pCmd->pPlayer);
    const int nPlayerY = CLIENTS_GetUnitY(pCmd->pPlayer);
    const int nDX = CLIENTS_GetUnitX(pCmd->pTarget) - nPlayerX;
    const int nDY = CLIENTS_GetUnitY(pCmd->pTarget) - nPlayerY;
    PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, nDX * nDelta / nDistance + nPlayerX, nPlayerY + nDY * nDelta / nDistance);
    return 1;
}

// build: symbol ?PLAYER_UseSkillOnTarget@* 0x00461C70
static void __stdcall PLAYER_UseSkillOnTarget(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_CheckCommandSkill(pCmd, 0))
        return;

    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nArg2, nArg1);
    if (!pUnit)
        return;

    int bTarget;
    if (UNITS_IsInMeleeRange(pCmd->pPlayer, pCmd->pTarget, UNITS_IsInMovingModeEx(pUnit)))
    {
        bTarget = 1;
    }
    else
    {
        D2SkillStrc* pSkill = pCmd->pSkill;
        if (pSkill)
        {
            D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
            if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
            {
                PLAYER_ApproachForAura(pCmd, nArg1, nArg2);
                return;
            }
        }

        switch (nResult)
        {
        case 1:
        case 4:
            if (!(pCmd->dwFlags & 0x20))
            {
                UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nArg1, nArg2, 0);
                if (pCmd->dwFlags & 1)
                    VIEW_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
                if (pCmd->dwFlags & 2)
                    VIEW_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);
                return;
            }
            bTarget = 0;
            break;
        default:
            bTarget = 1;
            break;
        }
    }
    PLAYER_SendCommand(bTarget, pCmd);
}

static inline D2MonStatsTxt* E06_GetUnitMonStatsTxt(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    const int nClassId = pUnit->dwClassId;
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nClassId];
    return 0;
}

// build: symbol ?PLAYER_InteractWithUnit@* 0x00461DC0
static void __stdcall PLAYER_InteractWithUnit(int nUnitType, int nUnitId, D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayerUnit = sub_00463DD0();
    int nRange;
    D2UnitStrc* pTarget = pCmd->pTarget;
    if (pTarget)
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        {
            if (pCmd->dwFlags & 8)
                return;
            DATATBLS_GetObjectsTxtRecord(pTarget ? pTarget->dwClassId : -1);
            int bSetMode = 1;
            if (pCmd->pTarget && pCmd->pTarget->dwClassId == 0x3B && STATES_CheckState(pPlayerUnit, STATE_JUST_PORTALED))
                bSetMode = 0;
            if (UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                if (bSetMode)
                {
                    UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                    GAME_SetClickHandled();
                }
                return;
            }
            if (PLAYER_IsPendingMode(nUnitType, nUnitId))
                return;
            const int nY = CLIENTS_GetUnitY(pCmd->pTarget);
            PLAYER_WalkTo(pCmd->nArg, pCmd->pPlayer, CLIENTS_GetUnitX(pCmd->pTarget), nY);
            if (bSetMode)
            {
                VIEW_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
                GAME_SetClickHandled();
            }
            return;
        }
        case UNIT_ITEM:
        {
            if (pCmd->dwFlags & 8)
                return;
            if (D2Common_10399(pTarget, pCmd->pPlayer) <= 4 && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                GAME_SetClickHandled();
                return;
            }
            if (PLAYER_IsPendingMode(nUnitType, nUnitId))
                return;
            UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
            VIEW_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            GAME_SetClickHandled();
            return;
        }
        case UNIT_PLAYER:
        {
            if (D2Common_10399(pTarget, pCmd->pPlayer) <= 4 && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                return;
            }
            UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
            VIEW_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            return;
        }
        case UNIT_TILE:
        {
            if (GAME_GetCurrentTime() < GAME_GetInteractDeadline())
                return;
            if (D2Common_10399(pCmd->pTarget, pCmd->pPlayer) > 4)
            {
                UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
                VIEW_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            }
            else
            {
                UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
            }
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            return;
        }
        case UNIT_MONSTER:
        {
            D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pTarget ? pTarget->dwClassId : -1);
            if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]))
            {
                nRange = 2;
                goto check_range;
            }
            break;
        }
        }
    }

    nRange = 5;
check_range:
    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxt = E06_GetUnitMonStatsTxt(pTarget);
        if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]) && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[0]))
        {
            if (pTarget->pDynamicPath)
                D2Common_10153(pTarget->pDynamicPath);
            D2UnitStrc* pUnit = pCmd->pTarget;
            const int nId = pUnit ? pUnit->dwUnitId : -1;
            const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
            const int nY = CLIENTS_GetUnitY(pUnit);
            MSG_SendFourDwords(0x59, nType, nId, CLIENTS_GetUnitX(pCmd->pTarget), nY);
            pUnit = pCmd->pTarget;
            if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
                pUnit->pMonsterData->nClientFlags |= 1;
            UNITMODE_SetUnitMode(pCmd->pTarget, 1);
        }
    }

    if (D2Common_10399(pCmd->pTarget, pCmd->pPlayer) <= nRange)
    {
        UNITMODE_DoUnitAction(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
        return;
    }

    UNITMODE_DoUnitAction(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = 1;
        pPlayer->pPlayerData->nMode = 0x13;
        pPlayer->pPlayerData->nArg1 = nUnitType;
        pPlayer->pPlayerData->nArg2 = nUnitId;
    }
}

static inline int E06_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline int E06_GetPlayerModeArg1(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

static inline int E06_GetPlayerModeArg2(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

static inline void E06_ClearPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// build: symbol ?PLAYER_PrepareCommand@* 0x004621D0
static int PLAYER_PrepareCommand(D2PlayerCmdStrc* pCmd)
{
    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    if (pCmd->pSkill && (pCmd->dwFlags & 2) && nResult != 1)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pCmd->pSkill);
        if (!pSkillsTxt)
            return 0;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCmd->pPlayer);
        if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]) && DUNGEON_IsRoomInTown(pRoom))
        {
            UNITSND_PlayPlayerSpeech(pCmd->pPlayer, 0x18);
            return 0;
        }

        if (pSkillsTxt->nFlags[0] & gdwBitMasks[4])
            return 0;
    }

    if (pCmd->dwFlags & 0x40)
    {
        pCmd->nArg = 3;
        pCmd->nMode = 4;
    }
    else
    {
        pCmd->nArg = 1;
        pCmd->nMode = 2;
    }

    const int nMode = E06_GetPlayerMode(pCmd->pPlayer);
    if (nMode)
    {
        if (nMode == 0x13)
        {
            const int nModeArg2 = E06_GetPlayerModeArg2(pCmd->pPlayer);
            const int nModeArg1 = E06_GetPlayerModeArg1(pCmd->pPlayer);
            if (CUNIT_FindClientUnit(nModeArg2, nModeArg1))
                GFX_ClearPendingAction(pCmd->pPlayer);
        }
        else
        {
            E06_ClearPlayerMode(pCmd->pPlayer);
        }
    }

    if (!pCmd->pSkill)
        return 0;

    int bForce = (pCmd->dwFlags >> 5) & 1;
    if ((pCmd->dwFlags & 2) && !pCmd->pTarget)
        bForce = 1;
    pCmd->pTarget = SELECT_GetSkillTarget(pCmd->pSkill, pCmd->pTarget, &pCmd->nX, &pCmd->nY, pCmd->dwFlags, bForce);
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
        return 1;
    }
    if (sub_00468830() == 8)
        MSG_SendDword(0x4C, -1);
    return 1;
}

// 0x00462370
static void PLAYER_ResumeWalk(D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
        return;

    if (sub_004648F0_GetTargetUnit(pPlayer))
        return;

    int nMode;
    switch (pPlayer->dwAnimMode)
    {
    case PLRMODE_WALK:
    case PLRMODE_TOWNWALK:
        nMode = 1;
        break;
    case PLRMODE_RUN:
        nMode = 3;
        break;
    default:
        return;
    }
    PLAYER_WalkTo(nMode, pPlayer, pCmd->nX, pCmd->nY);
}

// build: symbol ?PLAYER_ClampTarget@* 0x004623C0
static int __stdcall PLAYER_ClampTarget(D2UnitStrc* pUnit, D2PlayerCmdStrc* pCmd)
{
    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    int nDX = pCmd->nX - nX;
    int nDY = pCmd->nY - nY;
    if (E06_ABS(nDX) >= 0x100 || E06_ABS(nDY) >= 0x100)
        return 0;
    if (E06_ABS(nDX) < 1 && E06_ABS(nDY) < 1)
        return 0;

    int nDistance = sub_00474080_GetDistance(nDX, nDY);
    if (nDistance <= 1)
        nDistance = 1;

    const unsigned int dwFlags = pCmd->dwFlags;
    int nRange = 3;
    if ((dwFlags & 4) && (dwFlags & 0x40))
        nRange = 5;
    else if (dwFlags & 8)
        nRange = (dwFlags & 0x40) ? 5 : 4;
    else if (dwFlags & 0x10)
        nRange = 0;

    if (nDistance < nRange)
    {
        const float fScale = (float)nRange / nDistance;
        nDX = (int)(nDX * fScale);
        nDY = (int)(nDY * fScale);
    }

    pCmd->nX = nX + nDX;
    pCmd->nY = nY + nDY;
    const unsigned int dwTick = sub_0044DA90();
    if (pUnit->dwUnitType == UNIT_PLAYER && (pCmd->dwFlags & 8))
    {
        switch (pUnit->dwAnimMode)
        {
        case 2:
        case 3:
        case 6:
            if (dwTick - gdwLastClampTick < 7)
                return 0;
            break;
        }
    }

    gdwLastClampTick = dwTick;
    return 1;
}

// build: symbol ?PLAYER_IsSkillFlagSet@* 0x00462560
static int PLAYER_IsSkillFlagSet(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp, 0x75A);
        D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
        if (pSkillsTxt->nFlags[1] & gdwBitMasks[0])
            return 1;
    }
    return 0;
}

// build: symbol ?PLAYER_ExecuteCommand@* 0x004625B0
static void PLAYER_ExecuteCommand(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_PrepareCommand(pCmd))
        return;

    D2UnitStrc* pPlayer = pCmd->pPlayer;
    unsigned int dwFlags = pCmd->dwFlags;
    D2UnitStrc* pTarget = pCmd->pTarget;
    D2SkillStrc** ppSkill = &pCmd->pSkill;
    int bAuraTarget = 0;
    int nResult = D2Common_11016(pPlayer, *ppSkill);
    D2SkillsTxt* pSkillsTxt = 0;
    if (*ppSkill)
    {
        pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(*ppSkill);
        if (!pSkillsTxt)
            goto no_target;
    }

    if (!pTarget)
        goto no_target;

    if (!pSkillsTxt)
        goto with_target;

    if ((pCmd->dwFlags & 2) && nResult != 1)
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
            if (!(pSkillsTxt->nFlags[3] & gdwBitMasks[3]))
                goto no_target;
            bAuraTarget = 1;
            break;
        case UNIT_TILE:
            dwFlags |= 0x100;
            goto no_target;
        }
    }

    if (pTarget->dwUnitType != UNIT_MONSTER || !CUNIT_IsDeadOrDying(pTarget) || (pSkillsTxt->nFlags[3] & gdwBitMasks[0]))
        goto with_target;

no_target:
    {
        const unsigned int bNoTarget = dwFlags & 0x20;
        if (bNoTarget || ((dwFlags & 2) && nResult != 1))
        {
            nResult = 0;
            if (!PLAYER_CheckSkillUse(&nResult, ppSkill, pCmd->pPlayer))
                return;
            D2SkillStrc* pSkill = *ppSkill;
            if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp, 0x7AF) || nResult != 1 || bNoTarget)
            {
                PLAYER_SendCommand(0, pCmd);
                SELECT_RefreshHoverUnit(0);
                return;
            }
        }

        if (!PLAYER_ClampTarget(pCmd->pPlayer, pCmd))
            return;
        PLAYER_WalkTo(pCmd->nArg, pPlayer, pCmd->nX, pCmd->nY);
        SELECT_RefreshHoverUnit(0);
        return;
    }

with_target:
    {
        const int nTargetType = pTarget->dwUnitType;
        const int nTargetId = pTarget->dwUnitId;
        if (!bAuraTarget && (nTargetType == 2 || (nTargetType > 3 && nTargetType <= 5)) && (dwFlags & 2) && nResult != 1)
            return;

        if (SKILLS_GetSkillModeFromUnit(pPlayer, *ppSkill))
        {
            D2SkillStrc* pSkill = *ppSkill;
            if (pSkill)
            {
                D2SkillsTxt* pTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
                if (pTxt && (pTxt->nFlags[3] & gdwBitMasks[3]))
                {
                    if (!PLAYER_CheckSkillUse(0, ppSkill, pCmd->pPlayer))
                        return;
                    PLAYER_SendCommand(1, pCmd);
                    return;
                }
            }

            if ((pTarget->dwFlags >> 2) & 1)
            {
                if ((pSkillsTxt->nFlags[3] & gdwBitMasks[1]) || (pSkillsTxt->nFlags[3] & gdwBitMasks[2]) || CUNIT_IsHostileTo(pPlayer, pTarget))
                {
                    if (nTargetType == 2)
                    {
                        if (dwFlags & 0x20)
                            return;
                        PLAYER_OperateObject(nTargetId, pCmd);
                        return;
                    }

                    if (nTargetType == 0)
                    {
                        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
                        {
                            PLAYER_InteractWithTarget(pCmd, nTargetId);
                            return;
                        }
                        PLAYER_UseSkillOnTarget(0, nTargetId, pCmd);
                        return;
                    }

                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                    {
                        if (!PLAYER_IsSkillFlagSet(*ppSkill))
                            return;
                        PLAYER_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                        return;
                    }
                    PLAYER_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                    return;
                }
            }

            if (dwFlags & 0x20)
            {
                if (!PLAYER_CheckSkillUse(0, ppSkill, pCmd->pPlayer))
                    return;
                PLAYER_SendCommand(0, pCmd);
                return;
            }
        }
        else if (dwFlags & 0x20)
        {
            return;
        }

        if (nTargetType != 1)
        {
            PLAYER_InteractWithUnit(nTargetType, nTargetId, pCmd);
            return;
        }

        if (!(dwFlags & 4))
            return;

        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (pMonStatsTxt && (pMonStatsTxt->nMonStatsFlags[1] & gdwBitMasks[1]))
        {
            PLAYER_InteractWithUnit(1, nTargetId, pCmd);
            return;
        }

        UNITMODE_DoUnitAction(pCmd->nMode, pPlayer, 1, nTargetId, 0);
    }
}

// build: symbol ?PLAYER_CmdLeftSkill@* 0x004629A0
static int PLAYER_CmdLeftSkill(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
    {
        pCmd->dwFlags |= 0x80;
        PLAYER_ExecuteCommand(pCmd);
        return 1;
    }

    if (sub_00468830() == 6)
        UI_CancelCursorItemUse();
    else if (sub_00468830() == 8)
        MSG_SendDword(0x4C, -1);

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pCmd->pPlayer->pInventory);
    if (!pItem)
        return 1;

    MSG_SendDword(0x17, pItem->dwUnitId);
    return 0;
}

// build: symbol ?PLAYER_CmdLeftSkillMove@* 0x00462A20
static int PLAYER_CmdLeftSkillMove(D2PlayerCmdStrc* pCmd)
{
    int bChanged = 0;
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    D2UnitStrc* pPlayer = pCmd->pPlayer;
    int nSpeed;
    int nBase;
    sub_00620E40_GetClassSpeed(pPlayer, !pPlayer ? -1 : pPlayer->dwClassId, &nSpeed, &nBase);
    nSpeed <<= 8;
    D2DynamicPathStrc* pPath = pCmd->pPlayer->pDynamicPath;
    const int nVelocity = STATLIST_UnitGetStatValue(pCmd->pPlayer, STAT_VELOCITYPERCENT, 0) * nSpeed / 100;
    if (sub_006486C0(pPath) == nVelocity)
    {
        if (pCmd->dwFlags & 0x40)
            bChanged = 1;
    }
    else
    {
        if (!(pCmd->dwFlags & 0x40))
            bChanged = 1;
    }

    if (pCmd->pTarget)
    {
        D2UnitStrc* pCurrent = sub_004648F0_GetTargetUnit(pCmd->pPlayer);
        if (pCmd->pTarget != pCurrent || bChanged)
        {
            PATH_SetTargetUnit(pPath, pCmd->pTarget);
            pCmd->dwFlags |= 0x80;
            PLAYER_ExecuteCommand(pCmd);
            return 1;
        }
    }
    else if (!(pCmd->dwFlags & 0x20))
    {
        if (E06_GetPlayerMode(pCmd->pPlayer))
            return 1;
        pCmd->dwFlags |= 0x80;
    }

    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462B40
static int PLAYER_UpdatePetCommand(D2PlayerCmdStrc* pCmd)
{
    PLAYER_FilterCommandMessage(pCmd);
    const int nPetId = sub_00478F20_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
        if (pPet && ROSTERPETS_FindEntry(nPetId)->nValue == 2)
            VIEW_SetPetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    PLAYER_ResumeWalk(pCmd);
    return 0;
}

// build: symbol ?PLAYER_CmdRightSkill@* 0x00462BA0
static int PLAYER_CmdRightSkill(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, gszPlayerCpp, 0x9DD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// build: symbol ?PLAYER_CmdRightSkillMove@* 0x00462C20
static int PLAYER_CmdRightSkillMove(D2PlayerCmdStrc* pCmd)
{
    if (!PLAYER_FilterCommandMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!CUNIT_CanUseSkill(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, gszPlayerCpp, 0x9FD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    PLAYER_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462CA0
static int sub_00462CA0_UpdatePetCommandNoWalk(D2PlayerCmdStrc* pCmd)
{
    PLAYER_FilterCommandMessage(pCmd);
    const int nPetId = sub_00478F20_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
        if (pPet && ROSTERPETS_FindEntry(nPetId)->nValue == 2)
            VIEW_SetPetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    return 0;
}

int __fastcall sub_00462D00_PlayerCommand(int nCommand, int nX, int nY, unsigned char nKeyFlags)
{
    if (GAME_GetUIVarState(9))
        return 0;

    if (gbPlayerCommandPending && (nX || nY))
        return 0;

    gbPlayerCommandPending = 1;
    AUTOMAP_ScreenToMap(&nX, &nY);
    D2PlayerCmdStrc tCmd = {};
    tCmd.dwFlags = 0;
    tCmd.pPlayer = sub_00463DD0();
    D2UnitStrc* pSelected = SELECT_GetSelectedUnit();
    tCmd.pTarget = pSelected;
    tCmd.nX = nX;
    tCmd.nY = nY;
    if (pSelected)
    {
        switch (pSelected->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
            tCmd.nX = CLIENTS_GetUnitX(pSelected);
            tCmd.nY = CLIENTS_GetUnitY(tCmd.pTarget);
            break;
        }
    }

    if ((nKeyFlags & 8) && STATLIST_UnitGetStatValue(tCmd.pPlayer, STAT_STAMINA, 0))
        tCmd.dwFlags |= 0x40;
    if (nKeyFlags & 4)
        tCmd.dwFlags |= 0x20;

    switch (nCommand)
    {
    case 0:
        if (tCmd.pTarget)
            SELECT_RefreshHoverUnit(tCmd.pTarget);
        else
            SELECT_ClearSelection();
        tCmd.dwFlags |= 5;
        return PLAYER_CmdLeftSkill(&tCmd);
    case 1:
        tCmd.dwFlags |= 9;
        return PLAYER_CmdLeftSkillMove(&tCmd);
    case 2:
        SELECT_ClearSelection();
        tCmd.dwFlags |= 0x11;
        return PLAYER_UpdatePetCommand(&tCmd);
    case 3:
        if (tCmd.pTarget)
            SELECT_RefreshHoverUnit(tCmd.pTarget);
        else
            SELECT_ClearSelection();
        tCmd.dwFlags |= 6;
        return PLAYER_CmdRightSkill(&tCmd);
    case 4:
        tCmd.dwFlags |= 0xA;
        return PLAYER_CmdRightSkillMove(&tCmd);
    case 5:
        SELECT_ClearSelection();
        tCmd.dwFlags |= 0x12;
        return sub_00462CA0_UpdatePetCommandNoWalk(&tCmd);
    }
    return 1;
}

D2UnitStrc* gpEmitUnit_E06;

D2PlayerCmdStrc* gpEmitCmd_E06;

D2SkillRefStrc* gpEmitRef_E06;

int gnEmitArg_E06;

void sub_E06_Emit_Player1()
{
    PLAYER_SetModeAndSync(1, gnEmitArg_E06, gpEmitUnit_E06);
    PLAYER_UpdateRoomPosition(gpEmitUnit_E06);
    PLAYER_UpdateRoomState(gpEmitUnit_E06);
    PLAYER_PlaceOnFreeCoords(gpEmitUnit_E06);
    PLAYER_ResetPlayerState(gpEmitUnit_E06);
    PLAYER_RefreshSkillRef(0, gpEmitUnit_E06, gpEmitRef_E06);
    PLAYER_ReleaseUsedSkill(gnEmitArg_E06 == 1, gpEmitUnit_E06);
}

// 0x00463720
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx & dwMask) != 0;
}

// 0x00463740
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y)
{
    if (!room) return 0;
    if (x >= room->x && x < room->x + room->width && y >= room->y && y < room->y + room->height) return room;
    D2ActiveRoomStrc** adjacent = 0;
    int count = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(room, &adjacent, &count);
    for (unsigned int i = 0; i < (unsigned int)count; ++i) {
        if (adjacent[i] && x >= adjacent[i]->x && x < adjacent[i]->x + adjacent[i]->width
            && y >= adjacent[i]->y && y < adjacent[i]->y + adjacent[i]->height)
            return adjacent[i];
    }
    return 0;
}

// 0x00463810
const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        return pUnit->pMonsterData->wszMonName;
    return 0;
}
