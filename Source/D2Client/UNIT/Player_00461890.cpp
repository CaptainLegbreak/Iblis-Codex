#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GfxLightStrc;


struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    unsigned short nClientFlags;
};


struct D2PlayerCmdStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pPlayer;
    D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nArg;
    int nMode;
    D2SkillStrc* pSkill;
};

struct D2SkillsTxt
{
    char unk0x00[0x4];
    unsigned char nFlags[8];
    char unk0x0C[0x8];
    char nAuraTargetState;
    char unk0x15[0x19];
    unsigned short wSrvDoFunc;
    char unk0x30[0x20C];
};

struct D2ClientEntryStrc
{
    int unk0x00[2];
    int nValue;
};

struct D2MonStatsTxt
{
    char unk0x00[0xC];
    unsigned char nFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern void* gpDrlgAct_007A0634;                                                                            // 0x007A0634
extern int gnInTown_007A5260;                                                                               // 0x007A5260
extern unsigned int gdwLastTick_007A5268;                                                                   // 0x007A5268
extern int gdwGlobal_007A5264;                                                                              // 0x007A5264
extern int gnStringCount_00711EF0;                                                                          // 0x00711EF0
extern D2StringRefStrc gaStringRefs_00711DDC[];                                                             // 0x00711DDC
extern "C" const char gszPlayerCpp_006D6A34[];                                                              // 0x006D6A34

unsigned int __cdecl sub_0044BEF0();                                                                        // 0x0044BEF0
unsigned int __cdecl sub_0044DA90();                                                                        // 0x0044DA90
unsigned int __cdecl sub_0044DAA0();                                                                        // 0x0044DAA0
unsigned int __cdecl sub_0044DAC0();                                                                        // 0x0044DAC0
void __fastcall sub_0044DAD0(unsigned int nValue);                                                          // 0x0044DAD0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
void __cdecl sub_00453EC0();                                                                                // 0x00453EC0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_0045AFF0(int* pX, int* pY);                                                             // 0x0045AFF0
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit);                                        // 0x0045C470
int __stdcall sub_00461D60_IsPendingMode(int nArg1, int nArg2);                                             // 0x00461D60
int __fastcall sub_00464600(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                            // 0x00464600
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00467A70(D2UnitStrc* pUnit);                                                            // 0x00467A70
D2UnitStrc* __fastcall sub_00467880_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830();                                                                                 // 0x00468830
int __fastcall sub_00474080_GetDistance(int nDX, int nDY);                                                  // 0x00474080
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitType, int nUnitId, int nX, int nY);         // 0x00478700
int __cdecl sub_00454970();                                                                                 // 0x00454970
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_00460780_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2);             // 0x00460780
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
int __fastcall sub_00462930_FilterMessage(D2PlayerCmdStrc* pCmd);                                           // 0x00462930
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00463D90(int nArg);                                                                     // 0x00463D90
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);                // 0x004654C0
void __fastcall sub_00466CB0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00466CB0
void __fastcall sub_00467410_SetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue);            // 0x00467410
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);                                     // 0x0046BF30
void __fastcall sub_0046C700(D2UnitStrc* pUnit);                                                            // 0x0046C700
void __fastcall sub_0046EC10(D2UnitStrc* pUnit);                                                            // 0x0046EC10
void __fastcall sub_0046ECE0_PruneGfxNodes(D2UnitStrc* pUnit);                                              // 0x0046ECE0
void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, char nValue);                                // 0x0046F020
void __fastcall sub_00473C90_SetGlobal(int nValue);                                                         // 0x00473C90
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall sub_00481030(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);                // 0x00481030
void __fastcall sub_004B3E10(D2UnitStrc* pUnit);                                                            // 0x004B3E10
void __cdecl sub_004C1E30();                                                                                // 0x004C1E30
void __fastcall sub_004C68F0(D2UnitStrc* pUnit);                                                            // 0x004C68F0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                       // 0x004D9FC0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall sub_0061AA40(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall sub_0061ACD0_SetRoomPos(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);              // 0x0061ACD0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30
void __stdcall sub_0061AF10(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom);              // 0x0061AF10
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall sub_00620E40_GetClassSpeed(D2UnitStrc* pUnit, int nClassId, int* pSpeed, int* pBase);        // 0x00620E40
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer);                                   // 0x00622060
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);                                                // 0x00622230
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);       // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);                                                    // 0x00622DC0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                                  // 0x00640E90
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);                                                // 0x006486C0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                      // 0x00641530
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                                // 0x00643A00
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                      // 0x00648460
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath);                                            // 0x00648A40
int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath);                                            // 0x00648A60
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);                              // 0x00648AA0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                          // 0x00649970
void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50
void __stdcall sub_00649F70(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649F70
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __cdecl sub_004608C0();                                                                                // 0x004608C0

// build: context sub_00460830_SetStateAndSync
static void __stdcall sub_00460830_SetStateAndSync(int bSync, int nState, D2UnitStrc* pUnit)
{
    sub_00480E70_SetState(pUnit, nState);
    if (!bSync)
        return;

    if (pUnit != sub_00463DE0_GetStoredUnit())
        return;

    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    if (nX && nY)
        sub_004804E0_SetPosition(pUnit, nX, nY, 0, 0, 0);
}

// 0x00460D50
void __fastcall sub_00460D50_FreeClientPlayer(D2UnitStrc* pUnit)
{
    sub_0046C700(pUnit);
    sub_0046EC10(pUnit);
    if (gpDrlgAct_007A0634)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;
    sub_00466CB0(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
        sub_004743D0_ReleaseOverlayResource(pResource);
    sub_00464930_FreeLight(pUnit);
    if (pUnit == sub_00463DD0())
        sub_00463D90(0);
    UNITS_FreePlayerData(0, pUnit);
    sub_004608C0();
}

// build: context sub_00460DE0_UpdateRoomPosition
static void sub_00460DE0_UpdateRoomPosition(D2UnitStrc* pUnit)
{
    int nX;
    UNIT_GETX(pUnit, nX);
    int nY;
    UNIT_GETY(pUnit, nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    sub_0061ACD0_SetRoomPos(pRoom, nX, nY, UNITS_IsCurrentRoomInvalid(pUnit));
}

// build: context sub_00460E70_UpdateRoomState
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
        sub_004B3E10(pUnit);
    gnInTown_007A5260 = bInTown;
    sub_00473C90_SetGlobal(sub_0061AA40(pRoom));
    sub_0046BF30_CheckThroneLevel(pRoom);
}

// build: context sub_00460F10_PlaceOnFreeCoords
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
    UNIT_GETX_K5(pUnit, tCoords.nX);
    UNIT_GETY_K5(pUnit, tCoords.nY);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return;

    if (!COLLISION_CheckMaskWithPattern(pRoom, tCoords.nX, tCoords.nY, PATH_GetUnitCollisionPattern(pUnit), 0xC01))
        return;

    COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0xC01, 1);
    sub_004654C0_SetUnitPosition(pUnit, tCoords.nX, tCoords.nY, 0);
}

// build: context sub_00461010_ResetPlayerState
static void sub_00461010_ResetPlayerState(D2UnitStrc* pUnit)
{
    sub_004C1E30();
    sub_00649F70(pUnit, 0);
    sub_00464810(pUnit);
    if (pUnit)
        pUnit->dwFlags &= ~4;
    if (!STATES_CheckState(pUnit, 7) && pUnit)
        pUnit->dwFlags &= ~2;
    sub_0046ECE0_PruneGfxNodes(pUnit);
    sub_0046F020_FillGfxEntries(pUnit, 0);
    STATLIST_SetUnitStat(pUnit, 6, 0, 0);
}

// 0x00461070
static void __stdcall sub_00461070_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount_00711EF0 > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs_00711DDC[nIndex].nStringId;
    if (nStringId)
        sub_004CB9C0_Request(pUnit, nStringId);
}

// 0x004610C0
static int __stdcall sub_004610C0_CheckSkillUse(int* pUseState, D2SkillStrc** ppSkill, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0);
        nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    sub_00461070_RequestSkillString(pUnit, nUseState);
    return 0;
}

// build: context sub_00461160_CheckCommandSkill
static int sub_00461160_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_004610C0_CheckSkillUse(pUseState, &pCmd->pSkill, pCmd->pPlayer);
}

// build: context sub_00461180_RefreshSkillRef
static int __stdcall sub_00461180_RefreshSkillRef(int* pUseState, D2UnitStrc* pUnit, D2SkillRefStrc* pRef)
{
    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, pRef->nSkillId, pRef->nOwnerGUID);
    if (!pSkill)
        return 1;

    if (!sub_004610C0_CheckSkillUse(pUseState, &pSkill, pUnit))
        return 0;

    const int nOldSkillId = pRef->nSkillId;
    pRef->nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp_006D6A34, 0x32C);
    if (pRef->nSkillId != nOldSkillId)
        pRef->nOwnerGUID = -1;
    return 1;
}

// build: context sub_004611F0_ReleaseUsedSkill
static void __stdcall sub_004611F0_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        SKILLS_SetFlags(pSkill, nFlags | 2);
        sub_004C68F0(pUnit);
        return;
    }

    if (bKeep)
        return;

    const int bFlag = pUnit ? (pUnit->dwFlags >> 6) & 1 : 0;
    if (!bFlag)
        sub_004C68F0(pUnit);
}

// build: context sub_00461700_SendCommand
static void __stdcall sub_00461700_SendCommand(int bTarget, D2PlayerCmdStrc* pCmd)
{
    if (sub_00468740() > sub_00454970())
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
                    sub_00481030(0xA, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(7, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(9, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(6, pCmd->pPlayer, nType, nId, 0);
            }
        }
        if (pCmd->dwFlags & 2)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(0x11, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(0xE, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(0x10, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(0xD, pCmd->pPlayer, nType, nId, 0);
            }
        }
        return;
    }

    if (pCmd->dwFlags & 1)
    {
        if (pCmd->dwFlags & 8)
            sub_00481030(8, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            sub_00481030(5, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
    if (pCmd->dwFlags & 2)
    {
        if (pCmd->dwFlags & 8)
            sub_00481030(0xF, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            sub_00481030(0xC, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
}

// 0x00461840
static int __stdcall sub_00461840_WalkTo(int nMode, D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    if (!D2Common_10142(pPath, pUnit, 0))
        return 0;

    const int nTargetX = sub_00648A40_GetTargetX(pPath);
    const int nTargetY = sub_00648A60_GetTargetY(pPath);
    sub_00481030(nMode, pUnit, nTargetX, nTargetY, 0);
    return 1;
}

static __forceinline int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0

// build: context UNITS_GetXPosition
static __forceinline int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit)
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

static __forceinline int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit); // 0x0045AE20

// build: context UNITS_GetYPosition
static __forceinline int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit)
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

// 0x00461890
static void __stdcall sub_00461890_OperateObject(int nObjectIdArg, D2PlayerCmdStrc* pCmd)
{
    const int nObjectId = nObjectIdArg;
    D2UnitStrc* pObject = sub_00463990(nObjectId, 2);
    if (!pObject)
        return;

    D2_ASSERT(DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId), 0x4C4);
    int bSetMode = 1;
    if ((!pObject ? -1 : pObject->dwClassId) == 0x3B && STATES_CheckState(sub_00463DD0(), 0x66))
        bSetMode = 0;

    if (UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
    {
        if (bSetMode)
            sub_00481030(0x13, pCmd->pPlayer, 2, nObjectId, 0);
        return;
    }

    int nY = UNITS_GetYPosition(pCmd->pTarget);
    int nX = UNITS_GetXPosition(pCmd->pTarget);
    sub_00461840_WalkTo(pCmd->nArg, pCmd->pPlayer, nX, nY);
    if (bSetMode)
        sub_00460780_SetPlayerMode(0x13, pCmd->pPlayer, 2, nObjectId);
}

// 0x004619E0
static void sub_004619E0_InteractWithTarget(D2PlayerCmdStrc* pCmd, int nTargetId)
{
    switch (D2Common_10399(pCmd->pTarget, pCmd->pPlayer))
    {
    case 0:
    case 1:
    case 2:
        if (!sub_00622B50_TestInteractCollision(pCmd->pTarget, pCmd->pPlayer, 0x804))
        {
            sub_00481030(0x13, pCmd->pPlayer, 0, nTargetId, 0);
            return;
        }
        break;
    }

    sub_00481030(pCmd->nMode, pCmd->pPlayer, 0, nTargetId, 0);
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = 1;
        pPlayer->pPlayerData->nMode = 0x13;
        pPlayer->pPlayerData->nArg1 = 0;
        pPlayer->pPlayerData->nArg2 = nTargetId;
    }
}

// 0x00461A70
void __fastcall sub_00461A70_TargetUnitCommand(D2UnitStrc* pUnit)
{
    D2PlayerCmdStrc tCmd;
    tCmd.pTarget = pUnit;
    tCmd.pPlayer = sub_00463DD0();
    tCmd.nMode = 2;
    sub_004619E0_InteractWithTarget(&tCmd, !pUnit ? -1 : pUnit->dwUnitId);
}

// build: context sub_00461B40_ApproachForAura
static int sub_00461B40_ApproachForAura(D2PlayerCmdStrc* pCmd, int nArg1, int nArg2)
{
    int nRange = 0;
    int nDistance = 0;
    D2_ASSERT(pCmd->pTarget, 0x52F);
    D2_ASSERT(pCmd->pPlayer, 0x530);
    if (pCmd->dwFlags & 0x20)
    {
        sub_00461700_SendCommand(1, pCmd);
        return 1;
    }

    if (sub_00461AC0_IsInAuraRange(pCmd->pSkill, pCmd->pTarget, &nRange, &nDistance))
    {
        sub_00461700_SendCommand(1, pCmd);
        return 1;
    }

    if (pCmd->dwFlags & 1)
        sub_00460780_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
    if (pCmd->dwFlags & 2)
        sub_00460780_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);

    const int nDelta = nDistance - nRange;
    D2_ASSERT(nDelta > 0, 0x548);
    D2_ASSERT(nDistance, 0x549);
    const int nPlayerX = CLIENTS_GetUnitX(pCmd->pPlayer);
    const int nPlayerY = CLIENTS_GetUnitY(pCmd->pPlayer);
    const int nDX = CLIENTS_GetUnitX(pCmd->pTarget) - nPlayerX;
    const int nDY = CLIENTS_GetUnitY(pCmd->pTarget) - nPlayerY;
    sub_00461840_WalkTo(pCmd->nArg, pCmd->pPlayer, nDX * nDelta / nDistance + nPlayerX, nPlayerY + nDY * nDelta / nDistance);
    return 1;
}

// build: context sub_00461C70_UseSkillOnTarget
static void __stdcall sub_00461C70_UseSkillOnTarget(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    if (!sub_00461160_CheckCommandSkill(pCmd, 0))
        return;

    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    D2UnitStrc* pUnit = sub_00463990(nArg2, nArg1);
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
            D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
            if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
            {
                sub_00461B40_ApproachForAura(pCmd, nArg1, nArg2);
                return;
            }
        }

        switch (nResult)
        {
        case 1:
        case 4:
            if (!(pCmd->dwFlags & 0x20))
            {
                sub_00481030(pCmd->nMode, pCmd->pPlayer, nArg1, nArg2, 0);
                if (pCmd->dwFlags & 1)
                    sub_00460780_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
                if (pCmd->dwFlags & 2)
                    sub_00460780_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);
                return;
            }
            bTarget = 0;
            break;
        default:
            bTarget = 1;
            break;
        }
    }
    sub_00461700_SendCommand(bTarget, pCmd);
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

// build: context sub_00461DC0_InteractWithUnit
static void __stdcall sub_00461DC0_InteractWithUnit(int nUnitType, int nUnitId, D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayerUnit = sub_00463DD0();
    int nRange;
    D2UnitStrc* pTarget = pCmd->pTarget;
    if (pTarget)
    {
        switch (pTarget->dwUnitType)
        {
        case 2:
        {
            if (pCmd->dwFlags & 8)
                return;
            DATATBLS_GetObjectsTxtRecord(pTarget ? pTarget->dwClassId : -1);
            int bSetMode = 1;
            if (pCmd->pTarget && pCmd->pTarget->dwClassId == 0x3B && STATES_CheckState(pPlayerUnit, 0x66))
                bSetMode = 0;
            if (UNITS_IsObjectInInteractRange(pCmd->pPlayer, pCmd->pTarget) && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                if (bSetMode)
                {
                    sub_00481030(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                    sub_0044BEF0();
                }
                return;
            }
            if (sub_00461D60_IsPendingMode(nUnitType, nUnitId))
                return;
            const int nY = CLIENTS_GetUnitY(pCmd->pTarget);
            sub_00461840_WalkTo(pCmd->nArg, pCmd->pPlayer, CLIENTS_GetUnitX(pCmd->pTarget), nY);
            if (bSetMode)
            {
                sub_00460780_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
                sub_0044BEF0();
            }
            return;
        }
        case 4:
        {
            if (pCmd->dwFlags & 8)
                return;
            if (D2Common_10399(pTarget, pCmd->pPlayer) <= 4 && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                sub_00481030(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                sub_0044BEF0();
                return;
            }
            if (sub_00461D60_IsPendingMode(nUnitType, nUnitId))
                return;
            sub_00481030(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
            sub_00460780_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            sub_0044BEF0();
            return;
        }
        case 0:
        {
            if (D2Common_10399(pTarget, pCmd->pPlayer) <= 4 && !sub_00622B50_TestInteractCollision(pCmd->pPlayer, pCmd->pTarget, 0x804))
            {
                sub_00481030(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
                return;
            }
            sub_00481030(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
            sub_00460780_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            return;
        }
        case 5:
        {
            if (sub_0044DAA0() < sub_0044DAC0())
                return;
            if (D2Common_10399(pCmd->pTarget, pCmd->pPlayer) > 4)
            {
                sub_00481030(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
                sub_00460780_SetPlayerMode(0x13, pCmd->pPlayer, nUnitType, nUnitId);
            }
            else
            {
                sub_00481030(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
            }
            sub_0044DAD0(sub_0044DAA0() + 0x1F4);
            return;
        }
        case 1:
        {
            D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pTarget ? pTarget->dwClassId : -1);
            if (pMonStatsTxt && (pMonStatsTxt->nFlags[1] & gdwBitMasks[1]))
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
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxt = E06_GetUnitMonStatsTxt(pTarget);
        if (pMonStatsTxt && (pMonStatsTxt->nFlags[1] & gdwBitMasks[1]) && (pMonStatsTxt->nFlags[1] & gdwBitMasks[0]))
        {
            if (pTarget->pDynamicPath)
                D2Common_10153(pTarget->pDynamicPath);
            D2UnitStrc* pUnit = pCmd->pTarget;
            const int nId = pUnit ? pUnit->dwUnitId : -1;
            const int nType = pUnit ? pUnit->dwUnitType : 6;
            const int nY = CLIENTS_GetUnitY(pUnit);
            sub_00478700_SendCommand(0x59, nType, nId, CLIENTS_GetUnitX(pCmd->pTarget), nY);
            pUnit = pCmd->pTarget;
            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pUnit->pMonsterData->nClientFlags |= 1;
            sub_00480E70_SetState(pCmd->pTarget, 1);
        }
    }

    if (D2Common_10399(pCmd->pTarget, pCmd->pPlayer) <= nRange)
    {
        sub_00481030(0x13, pCmd->pPlayer, nUnitType, nUnitId, 0);
        return;
    }

    sub_00481030(pCmd->nMode, pCmd->pPlayer, nUnitType, nUnitId, 0);
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = 1;
        pPlayer->pPlayerData->nMode = 0x13;
        pPlayer->pPlayerData->nArg1 = nUnitType;
        pPlayer->pPlayerData->nArg2 = nUnitId;
    }
}

static inline int E06_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline int E06_GetPlayerModeArg1(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

static inline int E06_GetPlayerModeArg2(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

static inline void E06_ClearPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// build: context sub_004621D0_PrepareCommand
static int sub_004621D0_PrepareCommand(D2PlayerCmdStrc* pCmd)
{
    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    if (pCmd->pSkill && (pCmd->dwFlags & 2) && nResult != 1)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pCmd->pSkill);
        if (!pSkillsTxt)
            return 0;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCmd->pPlayer);
        if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]) && DUNGEON_IsRoomInTown(pRoom))
        {
            sub_004CB9C0_Request(pCmd->pPlayer, 0x18);
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
            if (sub_00463990(nModeArg2, nModeArg1))
                sub_0045C470_ClearPendingAction(pCmd->pPlayer);
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
    pCmd->pTarget = sub_00467880_FindSkillTarget(pCmd->pSkill, pCmd->pTarget, &pCmd->nX, &pCmd->nY, pCmd->dwFlags, bForce);
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
        return 1;
    }
    if (sub_00468830() == 8)
        sub_00478680_SendPacket5(0x4C, -1);
    return 1;
}

// 0x00462370
static void sub_00462370_ResumeWalk(D2PlayerCmdStrc* pCmd)
{
    D2UnitStrc* pPlayer = pCmd->pPlayer;
    if (!pPlayer || pPlayer->dwUnitType != 0)
        return;

    if (sub_004648F0_GetTargetUnit(pPlayer))
        return;

    int nMode;
    switch (pPlayer->dwAnimMode)
    {
    case 2:
    case 6:
        nMode = 1;
        break;
    case 3:
        nMode = 3;
        break;
    default:
        return;
    }
    sub_00461840_WalkTo(nMode, pPlayer, pCmd->nX, pCmd->nY);
}

// build: context sub_004623C0_ClampTarget
static int __stdcall sub_004623C0_ClampTarget(D2UnitStrc* pUnit, D2PlayerCmdStrc* pCmd)
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
    if (pUnit->dwUnitType == 0 && (pCmd->dwFlags & 8))
    {
        switch (pUnit->dwAnimMode)
        {
        case 2:
        case 3:
        case 6:
            if (dwTick - gdwLastTick_007A5268 < 7)
                return 0;
            break;
        }
    }

    gdwLastTick_007A5268 = dwTick;
    return 1;
}

// 0x00462560
static int sub_00462560_IsSkillFlagSet(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp_006D6A34, 0x75A);
        D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
        if (pSkillsTxt->nFlags[1] & gdwBitMasks[0])
            return 1;
    }
    return 0;
}

// build: context sub_004625B0_ExecuteCommand
static void sub_004625B0_ExecuteCommand(D2PlayerCmdStrc* pCmd)
{
    if (!sub_004621D0_PrepareCommand(pCmd))
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
        pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(*ppSkill);
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
        case 2:
        case 4:
            if (!(pSkillsTxt->nFlags[3] & gdwBitMasks[3]))
                goto no_target;
            bAuraTarget = 1;
            break;
        case 5:
            dwFlags |= 0x100;
            goto no_target;
        }
    }

    if (pTarget->dwUnitType != 1 || !sub_00464820_IsDeadOrDying(pTarget) || (pSkillsTxt->nFlags[3] & gdwBitMasks[0]))
        goto with_target;

no_target:
    {
        const unsigned int bNoTarget = dwFlags & 0x20;
        if (bNoTarget || ((dwFlags & 2) && nResult != 1))
        {
            nResult = 0;
            if (!sub_004610C0_CheckSkillUse(&nResult, ppSkill, pCmd->pPlayer))
                return;
            D2SkillStrc* pSkill = *ppSkill;
            if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerCpp_006D6A34, 0x7AF) || nResult != 1 || bNoTarget)
            {
                sub_00461700_SendCommand(0, pCmd);
                sub_00467A70(0);
                return;
            }
        }

        if (!sub_004623C0_ClampTarget(pCmd->pPlayer, pCmd))
            return;
        sub_00461840_WalkTo(pCmd->nArg, pPlayer, pCmd->nX, pCmd->nY);
        sub_00467A70(0);
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
                D2SkillsTxt* pTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
                if (pTxt && (pTxt->nFlags[3] & gdwBitMasks[3]))
                {
                    if (!sub_004610C0_CheckSkillUse(0, ppSkill, pCmd->pPlayer))
                        return;
                    sub_00461700_SendCommand(1, pCmd);
                    return;
                }
            }

            if ((pTarget->dwFlags >> 2) & 1)
            {
                if ((pSkillsTxt->nFlags[3] & gdwBitMasks[1]) || (pSkillsTxt->nFlags[3] & gdwBitMasks[2]) || sub_00465C60_CheckUnitPair(pPlayer, pTarget))
                {
                    if (nTargetType == 2)
                    {
                        if (dwFlags & 0x20)
                            return;
                        sub_00461890_OperateObject(nTargetId, pCmd);
                        return;
                    }

                    if (nTargetType == 0)
                    {
                        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
                        {
                            sub_004619E0_InteractWithTarget(pCmd, nTargetId);
                            return;
                        }
                        sub_00461C70_UseSkillOnTarget(0, nTargetId, pCmd);
                        return;
                    }

                    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                    {
                        if (!sub_00462560_IsSkillFlagSet(*ppSkill))
                            return;
                        sub_00461C70_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                        return;
                    }
                    sub_00461C70_UseSkillOnTarget(nTargetType, nTargetId, pCmd);
                    return;
                }
            }

            if (dwFlags & 0x20)
            {
                if (!sub_004610C0_CheckSkillUse(0, ppSkill, pCmd->pPlayer))
                    return;
                sub_00461700_SendCommand(0, pCmd);
                return;
            }
        }
        else if (dwFlags & 0x20)
        {
            return;
        }

        if (nTargetType != 1)
        {
            sub_00461DC0_InteractWithUnit(nTargetType, nTargetId, pCmd);
            return;
        }

        if (!(dwFlags & 4))
            return;

        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (pMonStatsTxt && (pMonStatsTxt->nFlags[1] & gdwBitMasks[1]))
        {
            sub_00461DC0_InteractWithUnit(1, nTargetId, pCmd);
            return;
        }

        sub_00481030(pCmd->nMode, pPlayer, 1, nTargetId, 0);
    }
}

// 0x004629A0
static int sub_004629A0_CmdLeftSkill(D2PlayerCmdStrc* pCmd)
{
    if (!sub_00462930_FilterMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (sub_00464600(pCmd->pPlayer, pCmd->pSkill))
    {
        pCmd->dwFlags |= 0x80;
        sub_004625B0_ExecuteCommand(pCmd);
        return 1;
    }

    if (sub_00468830() == 6)
        sub_00453EC0();
    else if (sub_00468830() == 8)
        sub_00478680_SendPacket5(0x4C, -1);

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pCmd->pPlayer->pInventory);
    if (!pItem)
        return 1;

    sub_00478680_SendPacket5(0x17, pItem->dwUnitId);
    return 0;
}

// 0x00462A20
static int sub_00462A20_CmdLeftSkillMove(D2PlayerCmdStrc* pCmd)
{
    int bChanged = 0;
    if (!sub_00462930_FilterMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetLeftSkill(pCmd->pPlayer);
    if (!sub_00464600(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    D2UnitStrc* pPlayer = pCmd->pPlayer;
    int nSpeed;
    int nBase;
    sub_00620E40_GetClassSpeed(pPlayer, !pPlayer ? -1 : pPlayer->dwClassId, &nSpeed, &nBase);
    nSpeed <<= 8;
    D2DynamicPathStrc* pPath = pCmd->pPlayer->pDynamicPath;
    const int nVelocity = STATLIST_UnitGetStatValue(pCmd->pPlayer, 0x43, 0) * nSpeed / 100;
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
            sub_004625B0_ExecuteCommand(pCmd);
            return 1;
        }
    }
    else if (!(pCmd->dwFlags & 0x20))
    {
        if (E06_GetPlayerMode(pCmd->pPlayer))
            return 1;
        pCmd->dwFlags |= 0x80;
    }

    sub_004625B0_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462B40
static int sub_00462B40_UpdatePetCommand(D2PlayerCmdStrc* pCmd)
{
    sub_00462930_FilterMessage(pCmd);
    const int nPetId = sub_00478F20_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = sub_00463990(nPetId, 1);
        if (pPet && sub_00478E40_FindEntry(nPetId)->nValue == 2)
            sub_00467410_SetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    sub_00462370_ResumeWalk(pCmd);
    return 0;
}

// 0x00462BA0
static int sub_00462BA0_CmdRightSkill(D2PlayerCmdStrc* pCmd)
{
    if (!sub_00462930_FilterMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!sub_00464600(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, gszPlayerCpp_006D6A34, 0x9DD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    sub_004625B0_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462C20
static int sub_00462C20_CmdRightSkillMove(D2PlayerCmdStrc* pCmd)
{
    if (!sub_00462930_FilterMessage(pCmd))
        return 1;

    pCmd->pSkill = UNITS_GetRightSkill(pCmd->pPlayer);
    if (!sub_00464600(pCmd->pPlayer, pCmd->pSkill))
        return 1;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pCmd->pSkill, gszPlayerCpp_006D6A34, 0x9FD);
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    switch (pSkillsTxt->nAuraTargetState)
    {
    case 1:
        if (!(pCmd->dwFlags & 0x40))
            pCmd->dwFlags |= 0x80;
        break;
    }
    sub_004625B0_ExecuteCommand(pCmd);
    return 1;
}

// 0x00462CA0
static int sub_00462CA0_UpdatePetCommandNoWalk(D2PlayerCmdStrc* pCmd)
{
    sub_00462930_FilterMessage(pCmd);
    const int nPetId = sub_00478F20_FindPetIdByOwner(pCmd->pPlayer, 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pPet = sub_00463990(nPetId, 1);
        if (pPet && sub_00478E40_FindEntry(nPetId)->nValue == 2)
            sub_00467410_SetEntryValue(pCmd->pPlayer, pPet, 0);
    }
    return 0;
}

// build: context sub_00462D00_PlayerCommand
int __fastcall sub_00462D00_PlayerCommand(int nCommand, int nX, int nY, unsigned char nKeyFlags)
{
    if (sub_004538D0(9))
        return 0;

    if (gdwGlobal_007A5264 && (nX || nY))
        return 0;

    gdwGlobal_007A5264 = 1;
    sub_0045AFF0(&nX, &nY);
    D2PlayerCmdStrc tCmd = {};
    tCmd.dwFlags = 0;
    tCmd.pPlayer = sub_00463DD0();
    D2UnitStrc* pSelected = sub_00467A10();
    tCmd.pTarget = pSelected;
    tCmd.nX = nX;
    tCmd.nY = nY;
    if (pSelected)
    {
        switch (pSelected->dwUnitType)
        {
        case 2:
        case 4:
            tCmd.nX = CLIENTS_GetUnitX(pSelected);
            tCmd.nY = CLIENTS_GetUnitY(tCmd.pTarget);
            break;
        }
    }

    if ((nKeyFlags & 8) && STATLIST_UnitGetStatValue(tCmd.pPlayer, 0xA, 0))
        tCmd.dwFlags |= 0x40;
    if (nKeyFlags & 4)
        tCmd.dwFlags |= 0x20;

    switch (nCommand)
    {
    case 0:
        if (tCmd.pTarget)
            sub_00467A70(tCmd.pTarget);
        else
            sub_00466FE0();
        tCmd.dwFlags |= 5;
        return sub_004629A0_CmdLeftSkill(&tCmd);
    case 1:
        tCmd.dwFlags |= 9;
        return sub_00462A20_CmdLeftSkillMove(&tCmd);
    case 2:
        sub_00466FE0();
        tCmd.dwFlags |= 0x11;
        return sub_00462B40_UpdatePetCommand(&tCmd);
    case 3:
        if (tCmd.pTarget)
            sub_00467A70(tCmd.pTarget);
        else
            sub_00466FE0();
        tCmd.dwFlags |= 6;
        return sub_00462BA0_CmdRightSkill(&tCmd);
    case 4:
        tCmd.dwFlags |= 0xA;
        return sub_00462C20_CmdRightSkillMove(&tCmd);
    case 5:
        sub_00466FE0();
        tCmd.dwFlags |= 0x12;
        return sub_00462CA0_UpdatePetCommandNoWalk(&tCmd);
    }
    return 1;
}
