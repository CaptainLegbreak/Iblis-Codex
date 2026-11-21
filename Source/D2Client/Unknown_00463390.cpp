#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2UnitData.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;
struct D2InventoryStrc;





struct D2PlayerModeInfoStrc
{
    int nType;
    int nSeqMode;
    int nDoneMode;
};

extern D2PlayerModeInfoStrc gaPlayerModeInfo_00711E00[];                                                    // 0x00711E00
extern void* gpDrlgAct_007A0634;                                                                            // 0x007A0634
extern int gnInTown_007A5260;                                                                               // 0x007A5260

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
void __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, int* pArgs, int nArg);             // 0x00461250
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);                                       // 0x004647D0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);                // 0x004654C0
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);                                     // 0x0046BF30
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00473C90_SetGlobal(int nValue);                                                         // 0x00473C90
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY);                           // 0x004804A0
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
extern "C" int __fastcall sub_004807C0_UpdateUnitPath(D2UnitStrc* unit); // 0x004807C0
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004B3E10_RefreshNpcEntries(D2UnitStrc* pUnit);                                                            // 0x004B3E10
int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
void __fastcall sub_004C72F0(D2UnitStrc* pUnit);                                                            // 0x004C72F0
void __fastcall sub_004CAF60_UpdateFootsteps(D2UnitStrc* pUnit);                                                            // 0x004CAF60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);              // 0x0061ACD0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30
void __stdcall sub_0061AF10(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom);              // 0x0061AF10
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2);                                      // 0x00620FA0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);                                                // 0x00622230
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);                                                       // 0x00623E00
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit);                                                              // 0x0063A340
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                                // 0x00643A00
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath);                        // 0x00648640
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath);                                        // 0x00648A00
int __stdcall sub_00648A10_GetPathTargetY(D2DynamicPathStrc* pPath);                                        // 0x00648A10
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);                              // 0x00648AA0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pPath);                                                      // 0x00648DC0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath);                                                      // 0x00650590

static __declspec(noinline) void __stdcall sub_00460830_SetStateAndSync(int bSync, int nState, D2UnitStrc* pUnit);
static void __stdcall sub_00460830_SetStateAndSync(int bSync, int nState, D2UnitStrc* pUnit); // 0x00460830
static void __declspec(noinline) sub_00460DE0_UpdateRoomPosition(D2UnitStrc* pUnit);                       // 0x00460DE0
static void __declspec(noinline) sub_00460E70_UpdateRoomState(D2UnitStrc* pUnit);                          // 0x00460E70
static void __declspec(noinline) sub_00460F10_PlaceOnFreeCoords(D2UnitStrc* pUnit);                        // 0x00460F10
static __declspec(noinline) void __stdcall sub_004611F0_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit);
static void __stdcall sub_004611F0_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit);    // 0x004611F0
static void __declspec(noinline) sub_00463260_UpdateStoredUnit(D2UnitStrc* pUnit);                         // 0x00463260

#define UNIT_GETX(pUnit, outX) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outX = (pUnit)->pStaticPath->nXPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outX = PATH_GetXPosition((pUnit)->pDynamicPath); \
        else \
            outX = 0; \
        break; \
    }

#define UNIT_GETY(pUnit, outY) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outY = (pUnit)->pStaticPath->nYPos; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outY = PATH_GetYPosition((pUnit)->pDynamicPath); \
        else \
            outY = 0; \
        break; \
    }

static void __stdcall sub_00460830_SetStateAndSync(int bSync, int nState, D2UnitStrc* pUnit)
{
    sub_00480E70_SetUnitMode(pUnit, nState);
    if (!bSync)
        return;

    if (pUnit != sub_00463DE0_GetPlayerUnit())
        return;

    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    if (nX && nY)
        sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
}

static void sub_00460DE0_UpdateRoomPosition(D2UnitStrc* pUnit)
{
    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    DUNGEON_UpdatePops(pRoom, nX, nY, UNITS_IsCurrentRoomInvalid(pUnit));
}

static void sub_00460E70_UpdateRoomState(D2UnitStrc* pUnit)
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
    if (gnInTown_007A5260 != bInTown && !bInTown)
        sub_004B3E10_RefreshNpcEntries(pUnit);
    gnInTown_007A5260 = bInTown;
    sub_00473C90_SetGlobal(DUNGEON_CheckLOSDraw(pRoom));
    sub_0046BF30_CheckThroneLevel(pRoom);
}

static inline int PLAYER_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    if (pUnit->pDynamicPath)
        return PATH_GetXPosition(pUnit->pDynamicPath);
    return 0;
}

static inline int PLAYER_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    if (pUnit->pDynamicPath)
        return PATH_GetYPosition(pUnit->pDynamicPath);
    return 0;
}

static void sub_00460F10_PlaceOnFreeCoords(D2UnitStrc* pUnit)
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
    tCoords.nX = PLAYER_GetUnitXInline(pUnit);
    tCoords.nY = PLAYER_GetUnitYInline(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    if (!COLLISION_CheckMaskWithPattern(pRoom, tCoords.nX, tCoords.nY, PATH_GetUnitCollisionPattern(pUnit), 0xC01))
        return;

    COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0xC01, 1);
    sub_004654C0_SetUnitPosition(pUnit, tCoords.nX, tCoords.nY, 0);
}

static void __stdcall sub_004611F0_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        SKILLS_SetFlags(pSkill, nFlags | 2);
        sub_004C68F0_DoUsedSkill(pUnit);
        return;
    }

    if (bKeep)
        return;

    const int bFlag = pUnit ? (pUnit->dwFlags >> 6) & 1 : 0;
    if (!bFlag)
        sub_004C68F0_DoUsedSkill(pUnit);
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* unit)
{
    int type = 6;
    if (unit) type = unit->dwUnitType;
    return type;
}

inline int UNITS_GetUnitIdInline(D2UnitStrc* unit)
{
    return !unit ? -1 : unit->dwUnitId;
}

static void sub_00463260_UpdateStoredUnit(D2UnitStrc* unit)
{
    if (unit != sub_00463DE0_GetPlayerUnit())
        return;
    if (STATLIST_UnitGetStatValue(unit, STAT_STAMINA, 0))
        return;
    D2DynamicPathStrc* path = unit->pDynamicPath;
    int args[7] = {};
    D2UnitStrc* target = sub_004648F0_GetPathTargetUnit(unit);
    if (PATH_GetTargetUnit(path))
    {
        args[0] = UNITS_GetUnitTypeInline(target);
        args[1] = UNITS_GetUnitIdInline(target);
        sub_00461250_QueueMove(0, unit, args, 0);
        return;
    }
    args[0] = D2COMMON_10175_PathGetFirstPointX(path);
    args[1] = sub_00648A10_GetPathTargetY(path);
    void* related = D2Common_10958(unit, 0);
    if (related)
        sub_004743D0_ReleaseOverlayResource(related);
    sub_004611F0_ReleaseUsedSkill(unit == sub_00463DD0_GetPlayerUnit(), unit);
    UNITS_SetUsedSkill(unit, 0);
    path = unit->pDynamicPath;
    if (unit->dwAnimMode == 19)
        return;
    PATH_ResetToPreviousType(path);
    int idle, move;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(unit)))
    {
        idle = 5;
        move = 6;
    }
    else
    {
        idle = 1;
        move = 2;
    }
    if (sub_004804A0_SetPathTargetPos(unit, args[0], args[1]))
        sub_00480E70_SetUnitMode(unit, move);
    else
        sub_00460830_SetStateAndSync(1, idle, unit);
}

static inline int PLAYER_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

static inline void PLAYER_SetPlayerState(D2UnitStrc* pUnit, int nState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
        pUnit->pPlayerData->nState = nState;
}

static inline int PLAYER_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline D2PlayerDataStrc* PLAYER_GetPlayerData(D2UnitStrc* pUnit)
{
    return (pUnit && pUnit->dwUnitType == UNIT_PLAYER) ? pUnit->pPlayerData : 0;
}

static inline int PLAYER_IsLocalPlayer(D2UnitStrc* pUnit)
{
    return pUnit == sub_00463DD0_GetPlayerUnit();
}

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SkillRefStrc
{
    int nSkillId;
    int nOwnerGUID;
};
struct D2UnitTargetStrc { int nX, nY, nParam; };
int __stdcall sub_00461180_RefreshSkillRef(int* pUseState, D2UnitStrc* pUnit, D2SkillRefStrc* pRef); // 0x00461180
void sub_00461010_ResetPlayerState(D2UnitStrc* pUnit); // 0x00461010
int __cdecl sub_0044BF00(); // 0x0044BF00
int __cdecl sub_0044BF10(); // 0x0044BF10
void __cdecl sub_0044DA40(); // 0x0044DA40
void __cdecl sub_00466FE0(); // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
int __fastcall sub_00456300_CloseUIVars(int, int); // 0x00456300
int __fastcall sub_00480780_SetPathTargetUnit(D2UnitStrc*, int, int); // 0x00480780
void __fastcall sub_00480930_InteractWithUnit(unsigned short, int); // 0x00480930
void __fastcall sub_00480D20_SetModeOverlay(D2UnitStrc*, int); // 0x00480D20
void __fastcall sub_00480EF0_MoveToPosition(D2UnitStrc*, int, int, int); // 0x00480EF0
int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc*, D2SkillRefStrc*); // 0x004C6EB0
int __fastcall sub_004C6F40_StartSkillAtPos(D2UnitStrc*, D2SkillRefStrc*); // 0x004C6F40
void __fastcall sub_004CC5B0_UpdateUnitSound(D2UnitStrc*, int, int); // 0x004CC5B0
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc*); // 0x0063A400
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc*, D2UnitStrc**); // 0x0063C8F0
void __stdcall PATH_SetType(D2DynamicPathStrc*, int); // 0x00648CF0
void __stdcall sub_00648E40_SetByte90(D2DynamicPathStrc*, unsigned char); // 0x00648E40
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970

// build: context PLAYER_QueueMoveInline
static __forceinline int PLAYER_QueueMoveInline(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce)
{
    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource) sub_004743D0_ReleaseOverlayResource(pResource);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nCommand != 19)
    {
        const int bKeep = pUnit == pPlayer;
        sub_004611F0_ReleaseUsedSkill(bKeep, pUnit);
        UNITS_SetUsedSkill(pUnit, 0);
    }
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 19)
    {
        if (!bForce) return 1;
        PATH_RecacheRoomIfNeeded(pPath);
    }
    PATH_ResetToPreviousType(pPath);
    int nNeutralMode;
    int nMoveMode;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        nNeutralMode = 5;
        nMoveMode = 6;
    }
    else
    {
        nNeutralMode = 1;
        nMoveMode = 2;
    }
    switch (nCommand)
    {
    case 22:
        if (sub_00461180_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && sub_004C6EB0_StartSkillOnUnit(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 21:
        if (sub_00461180_RefreshSkillRef(0, pUnit, (D2SkillRefStrc*)pTarget) && sub_004C6F40_StartSkillAtPos(pUnit, (D2SkillRefStrc*)pTarget)) return 1;
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 1:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nX, pTarget->nY))
        {
            sub_00480E70_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 0:
        if (sub_00480780_SetPathTargetUnit(pUnit, pTarget->nX, pTarget->nY))
        {
            sub_00480E70_SetUnitMode(pUnit, nMoveMode);
            return 1;
        }
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 23:
        if (sub_004804A0_SetPathTargetPos(pUnit, pTarget->nX, pTarget->nY))
        {
            sub_00480E70_SetUnitMode(pUnit, 3);
            return 1;
        }
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 24:
        if (sub_00480780_SetPathTargetUnit(pUnit, pTarget->nX, pTarget->nY))
        {
            sub_00480E70_SetUnitMode(pUnit, 3);
            return 1;
        }
        sub_00460830_SetStateAndSync(1, nNeutralMode, pUnit);
        return 0;
    case 6:
        pUnit->dwLastHitClass = pTarget->nParam;
        sub_00480E70_SetUnitMode(pUnit, 4);
        sub_004804E0_SetPosition(pUnit, (unsigned short)pTarget->nX, (unsigned short)pTarget->nY, 1, 0, 0);
        return 1;
    case 19:
    {
        pUnit->dwLastHitClass = pTarget->nParam;
        sub_00480D20_SetModeOverlay(pUnit, 19);
        if (STATES_IsUnitShapeShifted(pUnit))
            sub_004CC5B0_UpdateUnitSound(pUnit, 3, 1);
        else
            sub_004CC5B0_UpdateUnitSound(pUnit, 19, 1);
        sub_004804E0_SetPosition(pUnit, (unsigned short)pTarget->nX, (unsigned short)pTarget->nY, 1, 0, 0);
        return 1;
    }
    case 20:
        pUnit->dwLastHitClass = pTarget->nParam;
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 11);
        sub_00648E40_SetByte90(pPath, 5);
        D2COMMON_10170_PathSetTargetPos(pPath, pTarget->nX, pTarget->nY);
        D2Common_10142(pPath, pUnit, 0);
        sub_00480E70_SetUnitMode(pUnit, 19);
        return 1;
    case 18:
    {
        pUnit->dwLastHitClass = pTarget->nParam;
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
            sub_00480E70_SetUnitMode(pUnit, 9);
        else
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass == 13) sub_00480E70_SetUnitMode(pUnit, 9);
        }
        sub_004804E0_SetPosition(pUnit, (unsigned short)pTarget->nX, (unsigned short)pTarget->nY, 1, 0, 0);
        return 1;
    }
    case 8:
        if (sub_00463DD0_GetPlayerUnit() == pUnit) sub_00456300_CloseUIVars(1, 0);
        pUnit->dwLastHitClass = pTarget->nParam;
        if (sub_00467A10() == pUnit)
        {
            if (!(sub_0044BF00() & 8) && !(sub_0044BF10() & 8)) sub_00466FE0();
            else
            {
                sub_0044DA40();
                sub_00467A70_RefreshHoverUnit(0);
            }
        }
        sub_004804E0_SetPosition(pUnit, (unsigned short)pTarget->nX, (unsigned short)pTarget->nY, 0, 0, 0);
        sub_00480E70_SetUnitMode(pUnit, 0);
        sub_00461010_ResetPlayerState(pUnit);
        sub_0045C470_ClearPendingAction(pUnit);
        return 1;
    case 9:
        sub_00480E70_SetUnitMode(pUnit, 17);
        sub_00461010_ResetPlayerState(pUnit);
        return 1;
    case 7:
    {
        int bDead = sub_00464820_IsDeadOrDying(pUnit);
        sub_004647D0_UpdateAttackableFlag(pUnit);
        pUnit->dwFlags |= 2;
        sub_00480E70_SetUnitMode(pUnit, nNeutralMode);
        if (pTarget) sub_00480EF0_MoveToPosition(pUnit, pTarget->nX, pTarget->nY, bDead);
        return 1;
    }
    case 2:
        sub_00480930_InteractWithUnit((unsigned short)pTarget->nX, pTarget->nY);
        return 1;
    case 25:
        sub_00480E70_SetUnitMode(pUnit, 13);
        sub_004804E0_SetPosition(pUnit, (unsigned short)pTarget->nX, (unsigned short)pTarget->nY, 0, 0, 0);
        return 1;
    default:
        D2_ASSERT(0, 0x432);
    }
}

// 0x00463390
void __fastcall sub_00463390_UpdatePlayerMode(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int bPathDone = 0;
    if (gaPlayerModeInfo_00711E00[pUnit->dwAnimMode].nType == 1)
    {
        bPathDone = sub_004807C0_UpdateUnitPath(pUnit);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
            sub_00460DE0_UpdateRoomPosition(pUnit);
        sub_004CAF60_UpdateFootsteps(pUnit);
    }

    if (gaPlayerModeInfo_00711E00[pUnit->dwAnimMode].nType == 2)
    {
        D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
        if (pSkill)
        {
            int nFlags = SKILLS_GetFlags(pSkill);
            int bRelease = 1;
            if (nFlags & 1)
            {
                if (sub_004807C0_UpdateUnitPath(pUnit))
                {
                    SKILLS_SetFlags(pSkill, nFlags | 2);
                    sub_004C68F0_DoUsedSkill(pUnit);
                    *(unsigned int*)&bRelease = 0;
                }
                if (pUnit == sub_00463DD0_GetPlayerUnit())
                    sub_00460DE0_UpdateRoomPosition(pUnit);
            }

            const int nActionFrame = pUnit->nActionFrame;
            if (bRelease && !PLAYER_UnitHasFlag(pUnit, 0x40))
            {
                if (nActionFrame == 1 || nActionFrame == 2 || nActionFrame == 3)
                    sub_004C68F0_DoUsedSkill(pUnit);
            }
        }
    }

    switch (gaPlayerModeInfo_00711E00[pUnit->dwAnimMode].nSeqMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;
    case 1:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
            UNITS_StopSequence(pUnit);
        break;
    case 2:
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
            pUnit->wAnimSpeed = 0;
        }
        else
        {
            UNITS_StopSequence(pUnit);
        }
        break;
    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    if (pUnit->dwAnimMode == 18 && PLAYER_UnitHasFlag(pUnit, 0x4000))
        sub_00470610_Refresh(pUnit, 0);

    int bDone;
    switch (gaPlayerModeInfo_00711E00[pUnit->dwAnimMode].nDoneMode)
    {
    case 1:
        bDone = bPathDone;
        break;
    case 2:
    case 3:
        bDone = UNITS_IsAtEndOfFrameCycle(pUnit);
        break;
    default:
        bDone = 0;
        break;
    }

    if (bDone)
    {
        if (pUnit->dwAnimMode == 19)
        {
            int aArgs[7] = {};
            aArgs[0] = PLAYER_GetUnitXInline(pUnit);
            aArgs[1] = PLAYER_GetUnitYInline(pUnit);
            PATH_RecacheRoomIfNeeded(pPath);
            PATH_ResetToPreviousType(pPath);
            PLAYER_QueueMoveInline(6, pUnit, (D2UnitTargetStrc*)aArgs, 1);
        }
        else if (!PLAYER_GetPlayerMode(pUnit))
        {
            PLAYER_QueueMoveInline(7, pUnit, 0, 1);
        }
        else
        {
            PLAYER_SetPlayerState(pUnit, 1);
        }
    }

    if (UNITS_IsCurrentRoomInvalid(pUnit))
    {
        UNITS_SetCurrentRoomInvalid(pUnit, 0);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
            sub_00460E70_UpdateRoomState(pUnit);
    }

    D2COMMON_10193_PATH_AdjustDirection(pPath);
    if (pUnit->dwAnimMode == 3)
        sub_00463260_UpdateStoredUnit(pUnit);
    if (STATES_CheckStateMaskActiveOnUnit(pUnit))
        sub_004C72F0(pUnit);
    sub_00460F10_PlaceOnFreeCoords(pUnit);
}

#include "gen/data/Source/D2Client/Unknown_00463390.inc"
struct D2UnitStrc;
