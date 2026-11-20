#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define EVENTTYPE_ENDANIM 1
#define STAT_HITPOINTS 6
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define STATE_PLAYERBODY 7
#define UNIT_MONSTER 1
#define PLRMODE_NEUTRAL 1
#define ITEMTYPE_WEAPON 45
#define STAT_DEXTERITY 2
#define STAT_LEVEL 12
#define STAT_ATTACKRATE 68
#define IFLAG_BROKEN 0x100
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAGEX_TELEPORTED 0x00010000
#define UNITFLAG_HASTXTMSG 0x00000100

struct D2CorpseStrc;
struct D2PlayerDataStrc;
struct D2SkillsTxt;
struct D2PlayerModeChartStrc;
struct D2UnkPlrModeStrc2;
struct D2CharStatsTxt;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2CoordStrc;
union D2SeedStrc;
struct D2CorpsePositionStrc;
struct D2ItemsTxt;



typedef void(__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCustomId, int nCustomParam);

extern const EventCallbackFunction gpPlayerEventCallbacks_006E1810[15]; // 0x006E1810


int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C


struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[2];
    union
    {
        struct
        {
            unsigned char nFlags[8];
        };
        struct
        {
            unsigned char unk_04[0x3];
            unsigned char nFlags0;
        };
    };
    char unk0x0C[0x0A];
    unsigned char nSeqInput;
    unsigned char unk_17[0x17];
    unsigned short wSrvDoFunc;
    unsigned char unk_30[0x20C];
};


typedef void (__fastcall* PLRMODESTARTXY)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);

typedef void (__fastcall* PLRMODESTARTID)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget);

struct D2PlayerModeChartStrc
{
    PLRMODESTARTXY pfnStartXY;
    PLRMODESTARTID pfnStartID;
};

extern D2PlayerModeChartStrc gsPlayerModeChart_006E1740[]; // 0x006E1740
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057ED70
int __fastcall sub_0057EEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int a4, D2SkillStrc* pSkill); // 0x0057EEC0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __cdecl sub_006248E0_Log(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380
void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x0057FCA0
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY); // 0x0057F020


int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
void __fastcall sub_6FC45930(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
void __fastcall sub_0055D930(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused); // 0x0055D930
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __fastcall sub_6FC7C260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, unsigned int nValue); // 0x00535510
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630
void __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, int nUnitId, int bFree); // 0x0063D4E0
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nExperience); // 0x0057EAB0
int __fastcall sub_00562F30(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody); // 0x00562F30
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

struct D2UnkPlrModeStrc2
{
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, int nWeaponGUID); // 0x006233A0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pPreviousItem); // 0x0063CD80
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
static void __stdcall sRestoreWeapon(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pWeapon); // 0x00580030

typedef void(__fastcall* STATLIST_UpdateFn)(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther);

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall D2GAME_SendPacket0x47_6FC3EEE0(D2ClientStrc* pClient, D2UnitStrc* pPlayer); // 0x0053D370
void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, int a3); // 0x0053D3C0
void __fastcall sub_6FC81C00(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00547F70
void __fastcall sub_6FC82270(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005484B0
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther); // 0x00548520
void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580
void __fastcall sub_6FCC5F20(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00597890
void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, STATLIST_UpdateFn pfCallback); // 0x00625870
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

struct D2CharStatsTxt
{
    char pad0x00[0x3A];
    unsigned char nManaRegen;
    unsigned char unk_3B[0x7];
    unsigned char nRunDrain;
    char unk0x43[0xC4 - 0x43];
};

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent); // 0x00571A10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
static __declspec(noinline) int EVENTS_HpRegen(D2UnitStrc* pUnit); // 0x00580610
static __declspec(noinline) void EVENTS_StaminaRegen(D2UnitStrc* pUnit); // 0x00580500
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005406A0
void __fastcall sub_6FC7E640(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575630
static void __stdcall sub_0057F540_DropItemsOnCorpseOverflow(D2GameStrc* pGame, D2UnitStrc* pUnit);
extern "C" const char gszPlrModesSourceFile_006E17E0[]; // 0x006E17E0
unsigned int __stdcall INVENTORY_GetCorpseCount(D2InventoryStrc*); // 0x0063D5F0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*,int,int); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230
void __fastcall sub_00553180(D2UnitStrc*,D2ClientStrc*); // 0x00553180
const char* __fastcall CLIENTS_GetName(D2ClientStrc*); // 0x00538830
void __stdcall sub_006220F0(D2UnitStrc*,const char*); // 0x006220F0
void __fastcall SUNIT_InitSeed(D2UnitStrc*,D2SeedStrc*); // 0x00552DF0
void __stdcall STATES_ToggleState(D2UnitStrc*,int,int); // 0x00639DB0
int __fastcall CLIENTS_GetExperienceLoss(D2ClientStrc*); // 0x00539210
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc*,int); // 0x005391E0
void __stdcall sub_0063D470(D2InventoryStrc*,int,int,int); // 0x0063D470
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc*,int); // 0x0063D430
void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*,unsigned char,int); // 0x00621050
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc*,D2UnitStrc*,int,int,unsigned char,const char*,int); // 0x0063B950
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc*,D2UnitStrc*,int); // 0x0063B210
void __fastcall QUESTS_ItemPickedUp(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00543D80
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*,D2UnitStrc*,int); // 0x0063BDB0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc*,unsigned char); // 0x00627D70
void __fastcall sub_0057F390_SetCorpseGold(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x0057F390
void __fastcall sub_0053DF80_SendCorpse(D2GameStrc*,int,int,int); // 0x0053DF80

struct D2CorpsePositionStrc { D2CoordStrc coords; D2ActiveRoomStrc* room; };

static int __stdcall sub_0057F690_FreeStaleCorpses(D2GameStrc* pGame, D2UnitStrc* pUnit);
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
extern const unsigned char gbMask_006CE284; // 0x006CE284

struct D2ItemsTxt
{
    char unk0x00[0xD8];
    int dwSpeed;
};

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall sub_0057F240_EmitWalk(D2UnitStrc* pPlayer);
static __declspec(noinline) int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer);
static void __stdcall sub_0057FF70_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer); // 0x0057FF70

// 0x0057ED70
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM) + 5;
}

#include "gen/data/Source/D2Game/PLAYER/PlrModes.inc"

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0057ED90
static int sub_0057ED90_CanEndSequence(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqInput > 0)
        {
            return 1;
        }
    }

    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, 1) + 0x05;
}

// 0x0057EDD0
static int sub_6FC81890(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory) && nMode != 0 && nMode != 17)
    {
        return 0;
    }

    switch (nMode)
    {
    case 0:
    case 1:
    case 5:
    case 17:
        return 1;

    default:
        break;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit) || nMode == 4 || nMode == 9)
        {
            return 1;
        }
        return 0;

    case 0:
    case 4:
    case 9:
    case 17:
        return 0;

    case 12:
        return sub_0057ED70_IsEndAnimDue(pGame, pUnit) ? 1 : 0;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return 0;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return 0;
        }
        break;

    case 18:
        return sub_0057ED90_CanEndSequence(pGame, pUnit);

    default:
        break;
    }

    return 1;
}

static __forceinline int sub_GetConcStat(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x2A);
    return STATLIST_GetStatValue(pStatList, 0xA4, 0);
}

static __forceinline int sub_GetAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// 0x0057EEC0
int __fastcall sub_0057EEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int bCheckUsedSkill, D2SkillStrc* pSkill)
{
    if (STATES_CheckState(pUnit, 0x36))
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 0;
    }

    if (nMode == 0 || !bCheckUsedSkill)
    {
        return 1;
    }

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
    {
        return 1;
    }

    const int nUsedSkillId = SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 185);

    D2SkillsTxt* pUsedSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nUsedSkillId);
    if (!pUsedSkillsTxtRecord)
    {
        return 1;
    }

    if (pSkill == pUsedSkill && (pUsedSkillsTxtRecord->wSrvDoFunc == 67 || pUsedSkillsTxtRecord->wSrvDoFunc == 76))
    {
        return 1;
    }

    if (pUsedSkillsTxtRecord->nFlags0 & gbMask_006CE284)
    {
        if ((STATES_CheckState(pUnit, 0x2A)
            && (int)(SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100)) < sub_GetConcStat(pUnit))
            || STATES_CheckState(pUnit, 0x0F))
        {
            if (sub_GetAnimMode(pUnit) == 1)
            {
                sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
                return 1;
            }

            return 0;
        }

        return 1;
    }

    if (sub_GetAnimMode(pUnit) == 1)
    {
        sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
        return 1;
    }

    switch (nMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
    case 13:
    case 18:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit) != 0)
        {
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}

// 0x0057F070
int __fastcall sub_0057F070_PLRMODE_ModeCheck_Death(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x0057F080
int __fastcall sub_0057F080_PLRMODE_ModeCheck_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x0057F240
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

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
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
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pTorsoArmor ? -1 : pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            int nSpeed = pItemsTxtRecord->dwSpeed;
            nSpeed = nSpeed / 10 + 1;
            nStaminaLost *= nSpeed;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 154, 0);
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

// 0x0057F410
static void __stdcall sub_6FC802F0(D2GameStrc* pGame, int nBodyloc, D2UnitStrc* hItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int bUpdateSets = sub_0062A360(pUnit, hItem);
    sub_0063D2B0_DetachItem(pInventory, hItem);
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hItem);

    D2_ASSERT(hRemove, 0x25D);
    D2_ASSERT(hItem == hRemove, 0x25E);

    sub_0063BE30(pInventory, nBodyloc);

    if (ITEMS_GetItemType(hItem) == 0x13)
    {
        sub_6FC45930(pGame, pUnit, 0);
    }

    if (hItem)
    {
        hItem->dwFlags &= ~0x02;
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, hItem, pUnit, 0, 1);
    ITEMS_SetItemFlag(hItem, 0x20, 1);
    ITEMS_SetItemCMDFlag(hItem, 1, 1);
    ITEMS_SetItemCMDFlag(hItem, 0x10, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, hItem);

    if (bUpdateSets)
    {
        sub_0055D930(pUnit, hItem, 0);
    }

    ITEMS_UpdateSets(pUnit, hItem, 1, 1);
    UNITS_RefreshInventory(pUnit, 1);
}

// 0x0057F4F0
static void sub_6FC803F0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x27D);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_SetItemCMDFlag(pItem, 1, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pPlayer, 1);
}

// build: context sub_M10_Emit_0057F700
// calling-convention shim (not game code)
void __fastcall sub_M10_Emit_0057F700(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nBodyLoc)
{
    sub_0057F690_FreeStaleCorpses(pGame, pUnit);
    sub_0057F540_DropItemsOnCorpseOverflow(pGame, pUnit);
    sub_6FC803F0(pGame, pItem, pUnit);
    sub_6FC802F0(pGame, nBodyLoc, pItem, pUnit);
}

// 0x0057F540
static void __stdcall sub_0057F540_DropItemsOnCorpseOverflow(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    for (int nBodyLoc = -1; nBodyLoc < 0x0D; ++nBodyLoc)
    {
        D2UnitStrc* pItem = 0;
        if (nBodyLoc == -1)
        {
            pItem = INVENTORY_GetCursorItem(pInventory);
        }
        else
        {
            pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        }

        if (pItem)
        {
            if (nBodyLoc == -1)
            {
                sub_6FC803F0(pGame, pItem, pUnit);
            }
            else
            {
                D2_ASSERT(pItem->dwAnimMode == 1, 0x2A8);
                sub_6FC802F0(pGame, nBodyLoc, pItem, pUnit);
            }

            D2UnitStrc* pDupedItem = ITEMS_Duplicate(pGame, pItem, pUnit, 1);
            D2CoordStrc tCoord;
            UNITS_GetCoords(pUnit, &tCoord);
            D2CoordStrc tReturnCoords;
            D2ActiveRoomStrc* pFreeRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &tCoord, &tReturnCoords, 1, 1);
            D2GAME_DropItem_6FC52260(pGame, pUnit, pDupedItem, pFreeRoom, tReturnCoords.nX, tReturnCoords.nY);
        }
    }

    const int nGold = STATLIST_UnitGetStatValue(pUnit, 0x0E, 0);
    if (pUnit->dwUnitType == 0)
    {
        UNITS_GetInventoryGoldLimit(pUnit);
    }
    STATLIST_SetUnitStat(pUnit, 0x0E, 0, 0);
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    sub_6FC7C260(pGame, pUnit, nUnitId, nGold);
}

// 0x0057F690
static int __stdcall sub_0057F690_FreeStaleCorpses(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    int nCount = 0;

    D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pInventory);
    while (pCorpse)
    {
        D2CorpseStrc* pNextCorpse = INVENTORY_GetNextCorpse(pCorpse);
        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
        if (!SUNIT_GetServerUnit(pGame, 0, nCorpseGUID))
        {
            INVENTORY_FreeCorpse(pInventory, nCorpseGUID, 1);
        }
        else
        {
            ++nCount;
        }
        pCorpse = pNextCorpse;
    }

    return nCount;
}

// build: context ApplyRatio
static __forceinline int ApplyRatio(int nValue,int nMultiplier,int nDivisor)
{
 if(!nDivisor) return 0;
 if(nValue>0x100000) {
  if(nDivisor>(nValue>>4)) return (int)(nValue*(__int64)nMultiplier/nDivisor);
  return nMultiplier*(nValue/nDivisor);
 }
 if(nMultiplier>0x10000) {
  if(nDivisor<=(nMultiplier>>4)) return nValue*(nMultiplier/nDivisor);
  return (int)(nValue*(__int64)nMultiplier/nDivisor);
 }
 return nMultiplier*nValue/nDivisor;
}

// 0x0057F700
D2UnitStrc* __fastcall sub_0057F700_CreateDeadBody(D2GameStrc* pGame,D2UnitStrc* pUnit,int nX,int nY,D2ActiveRoomStrc* pRoom)
{
 D2ActiveRoomStrc* pInitialRoom=pRoom;
 sub_0057F690_FreeStaleCorpses(pGame,pUnit);
 D2InventoryStrc* pInventory=pUnit->pInventory;
 if(INVENTORY_GetCorpseCount(pInventory)>15) {sub_0057F540_DropItemsOnCorpseOverflow(pGame,pUnit);return 0;}
 D2_ASSERT(pInitialRoom,0x2FD);
 D2ActiveRoomStrc* pCorpseRoom=D2GAME_GetRoom_6FC52070(pInitialRoom,nX,nY);
 if (!pCorpseRoom) {

  char szMessage[256];
  D2_MAYBE_UNUSED(szMessage);
  sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x2FF); exit(-1);
 }
 D2UnitStrc* pCorpse=SUNIT_AllocUnitData(0,pUnit->dwClassId,nX,nY,pGame,pCorpseRoom,1,17,0);
 D2_ASSERT(pCorpse,0x304);
 D2ClientStrc* pClient=UnitGetClient(pUnit,gszPlrModesSourceFile_006E17E0,0x306);
 pCorpse->dwFlags&=~4;
 sub_00553180(pCorpse,pClient);
 sub_006220F0(pCorpse,CLIENTS_GetName(pClient));
 SUNIT_InitSeed(pCorpse,&pGame->pGameSeed);
 UNITS_ChangeAnimMode(pCorpse,17);
 STATES_ToggleState(pCorpse,7,1);
 pCorpse->dwFlagEx|=0x1000;
 pCorpse->dwFlags|=2;
 int nExperience=ApplyRatio(CLIENTS_GetExperienceLoss(pClient),75,100);
 CLIENTS_SetExperienceLoss(pClient,0);
 STATLIST_SetUnitStat(pCorpse,13,nExperience,0);
 sub_0063D470(pInventory,!pCorpse ? -1 : pCorpse->dwUnitId,0,1);
 D2InventoryStrc* pCorpseInventory=pCorpse->pInventory;
 D2_ASSERT((!pCorpse ? -1 : pCorpse->dwUnitId)!=(!pUnit ? -1 : pUnit->dwUnitId),0x31A);
 INVENTORY_SetOwnerId(pCorpseInventory,!pUnit ? -1 : pUnit->dwUnitId);
 for(int nBodyLoc=-1;nBodyLoc<13;++nBodyLoc) {
  D2UnitStrc* hItem=0;
  if(nBodyLoc==-1) hItem=INVENTORY_GetCursorItem(pInventory);
  else hItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
  if(!hItem) continue;
  if(nBodyLoc==-1) sub_6FC803F0(pGame,hItem,pUnit);
  else {
   D2_ASSERT(hItem->dwAnimMode==1,0x339);
   sub_6FC802F0(pGame,nBodyLoc,hItem,pUnit);
  }
  ITEMS_SetInvPage(hItem,0);
  D2UnitStrc* pDupedItem=ITEMS_Duplicate(pGame,hItem,pUnit,1);
  if(nBodyLoc==-1) {
   int nRecord=UNITS_GetInventoryRecordId(pCorpse,0,pGame->bExpansion);
   if(INVENTORY_PlaceItemAtFreePosition(pCorpseInventory,pDupedItem,nRecord,0,0,gszPlrModesSourceFile_006E17E0,0x349) && INVENTORY_PlaceItemInSocket(pCorpseInventory,pDupedItem,1)) {
    if(pDupedItem) pDupedItem->dwFlags&=~2;
    UNITS_ChangeAnimMode(pDupedItem,0);
    if(pDupedItem) pDupedItem->dwFlags&=~0x02000000;
    ITEMS_SetItemCMDFlag(pDupedItem,2,1);
    INVENTORY_AddItemToTradeInventory(pCorpseInventory,pDupedItem);
    UNITS_RefreshInventory(pCorpse,1);
    QUESTS_ItemPickedUp(pGame,pCorpse,pDupedItem);
    continue;
   }
  } else {
   if(INVENTORY_PlaceItemInBodyLoc(pCorpseInventory,pDupedItem,nBodyLoc)) {
    int nPage=3;
    if(nBodyLoc==11||nBodyLoc==12) nPage=4;
    if(INVENTORY_PlaceItemInSocket(pCorpseInventory,pDupedItem,nPage)) {
     ITEMS_SetBodyLocation(pDupedItem,(unsigned char)nBodyLoc);
     if(pDupedItem) pDupedItem->dwFlags&=~2;
     UNITS_ChangeAnimMode(pDupedItem,1);
     ITEMS_SetInvPage(pDupedItem,255);
     ITEMS_SetItemCMDFlag(pDupedItem,8,1);
     if(pDupedItem) pDupedItem->dwFlags&=~0x02000000;
     INVENTORY_AddItemToTradeInventory(pCorpseInventory,pDupedItem);
     UNITS_RefreshInventory(pCorpse,1);
     QUESTS_ItemPickedUp(pGame,pCorpse,pDupedItem);
     continue;
    }
   }
  }
  D2CoordStrc coords,returned;
  UNITS_GetCoords(pUnit,&coords);
  D2ActiveRoomStrc* pFreeRoom=D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit),&coords,&returned,1,1);
  D2GAME_DropItem_6FC52260(pGame,pUnit,pDupedItem,pFreeRoom,returned.nX,returned.nY);
 }
 int nGold=STATLIST_UnitGetStatValue(pUnit,14,0);
 if(pUnit->dwUnitType==0) UNITS_GetInventoryGoldLimit(pUnit);
 STATLIST_SetUnitStat(pUnit,14,0,0);
 sub_0057F390_SetCorpseGold(pGame,pUnit,pCorpse,nGold,1);
 sub_0053DF80_SendCorpse(pGame,!pUnit ? -1 : pUnit->dwUnitId,!pCorpse ? -1 : pCorpse->dwUnitId,1);
 return pCorpse;
}

// calling-convention shim (not game code)
int __fastcall sub_M380_Emit_0057F700(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nBodyLoc, int nExtra)
{
    sub_0057F540_DropItemsOnCorpseOverflow(pGame, pUnit);
    sub_6FC803F0(pGame, pItem, pUnit);
    sub_6FC802F0(pGame, nBodyLoc, pItem, pUnit);
    return nExtra + 0x35;
}

// 0x0057FAF0
static int __stdcall sub_0057FAF0_CanPickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    D2_ASSERT(pPlayer, 909);
    D2_ASSERT(pDeadBody, 910);
    D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 911);
    const int nOwnerGUID = INVENTORY_GetOwnerId(pDeadBody->pInventory);
    if (pPlayer->dwUnitId == nOwnerGUID)
    {
        return 1;
    }
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
    if (pOwner)
    {
        return PLAYERLIST_CheckFlag(pOwner, pPlayer, 1);
    }
    return 0;
}

// 0x0057FB70
void __fastcall sub_0057FB70_PickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    if (!STATES_CheckState(pDeadBody, STATE_PLAYERBODY))
    {
        return;
    }
    if (!sub_0057FAF0_CanPickUpCorpse(pGame, pPlayer, pDeadBody))
    {
        return;
    }
    D2InventoryStrc* const pBodyInventory = pDeadBody->pInventory;
    const int nOwnerGUID = INVENTORY_GetOwnerId(pBodyInventory);
    if ((!pPlayer ? -1 : pPlayer->dwUnitId) == nOwnerGUID)
    {
        const int nExperience = STATLIST_UnitGetStatValue(pDeadBody, STAT_EXPERIENCE, 0);
        if (nExperience)
        {
            STATLIST_SetUnitStat(pDeadBody, STAT_EXPERIENCE, 0, 0);
            SUNITDMG_AddExperience(pGame, pPlayer, nExperience);
        }
    }
    if (sub_00562F30(pGame, pPlayer, pDeadBody))
    {
        const int nCorpseGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2InventoryStrc* const pInventory = pPlayer->pInventory;
        INVENTORY_FreeCorpse(pInventory, nCorpseGUID, 1);
        const int nBodyGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        const int nBodyType = !pDeadBody ? 6 : pDeadBody->dwUnitType;
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pDeadBody), nBodyType, nBodyGUID);
        const int nDeadGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, pPlayer->dwUnitId, nDeadGUID, 0);
        UNITS_FreeCollisionPath(pDeadBody);
        SUNIT_RemoveUnit(pGame, pDeadBody);
        SUNIT_AttachSound(pPlayer, 0x5D, pPlayer);
    }
    else
    {
        SUNIT_AttachSound(pPlayer, 0x17, pPlayer);
    }
}

// 0x0057FC60
static __forceinline int sub_0057FC60_IsOtherPlayerOrMinion(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget || pUnit->dwUnitType != UNIT_PLAYER || pUnit == pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    if (pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && pOwner != pUnit)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0057FE20
int __fastcall sub_0057FE20_PLRMODE_ModeCheck_GetHit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

int __fastcall sub_M120_Emit_0057FC60(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return sub_0057FC60_IsOtherPlayerOrMinion(pUnit, pTarget);
}

// 0x0057FF70
static void __stdcall sub_0057FF70_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer)
{
    int nNewBodyLoc = nBodyLoc;
    const int nWeaponGUID = UNITS_GetWeaponGUID(pPlayer);
    if (!nWeaponGUID)
    {
        return;
    }

    D2UnitStrc* pWeaponItem = SUNIT_GetServerUnit(pGame, 0x04, nWeaponGUID);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (pWeaponItem && pInventory && !ITEMS_GetInvPage(pWeaponItem) && INVENTORY_CompareWithItemsParentInventory(pInventory, pWeaponItem) && sub_6FC42F20(pPlayer, pWeaponItem, &nNewBodyLoc, 0))
    {
        nBodyLoc = nNewBodyLoc;
        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pInventory, nNewBodyLoc), 0x4EA);

        sub_6FC49F80(pGame, pPlayer, nWeaponGUID, nBodyLoc);
    }

    UNITS_SetWeaponGUID(pPlayer, 0);
}

void __fastcall sub_0057F240_EmitCaller(void* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == 0 && !sub_0057F240_DrainRunStamina(pPlayer))
    {
        sub_0057F240_EmitWalk(pPlayer);
    }
}

// 0x00580030
static void __stdcall sRestoreWeapon(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pWeapon)
{
    if ((ITEMS_CheckIfStackable(pWeapon) || ITEMS_CheckIfThrowable(pWeapon) || STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x7D, 0)) && STATLIST_UnitGetStatValue(pWeapon, 0x46, 0) <= 0)
    {
        if (STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x7D, 0))
        {
            STATLIST_SetUnitStat(pWeapon, 0x46, 0, 0);
            return;
        }

        if (ITEMSIsA(pWeapon, 0x2D) && ITEMS_IsMagSetRarUniCrfOrTmp(pWeapon))
        {
            if (!ITEMS_CheckItemFlag(pWeapon, 0x100, 0x513, gszPlrModesSourceFile_006E17E0))
            {
                sub_6FC4B580(pGame, pPlayer, pWeapon);
            }
            return;
        }

        const int bReload = ITEMS_GetReload(pWeapon);
        const int nItemType = ITEMS_GetItemType(pWeapon);
        unsigned char nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
        const int bReEquip = ITEMS_GetReEquip(pWeapon);
        UNITS_ChangeAnimMode(pPlayer, 1);

        int a5;
        sub_6FC45B30(pGame, pPlayer, nBodyLoc, 1, &a5);
        ITEMS_SetItemCMDFlag(pWeapon, 1, 1);

        if (bReload)
        {
            D2UnitStrc* pItem = 0;
            while ((pItem = INVENTORY_GetBackPackItemByType(pPlayer->pInventory, nItemType, pItem)) != 0)
            {
                const int nItemClassId = !pItem ? -1 : pItem->dwClassId;
                if (sub_00451F60_UnitClassId(pWeapon) == nItemClassId && !ITEMS_CheckItemFlag(pItem, 0x100, 0x531, gszPlrModesSourceFile_006E17E0))
                {
                    break;
                }
            }

            if (pItem)
            {
                const int nWeaponClassId = !pWeapon ? -1 : pWeapon->dwClassId;
                if (nWeaponClassId == pItem->dwClassId && !INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc) && sub_6FC49F80(pGame, pPlayer, !pItem ? -1 : pItem->dwUnitId, nBodyLoc))
                {
                    return;
                }
            }
        }

        if (bReEquip)
        {
            sub_0057FF70_RestoreWeapon(pGame, nBodyLoc, pPlayer);
        }
    }
}

// 0x005801E0
static void sub_005801E0_SaveActiveSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pSkills->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pSkills->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\PLAYER\\PlrModes.cpp", 0x56E);
    }
    else
    {
        pSkills->nLeftSkillOwnerGUID = -1;
        pSkills->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pSkills->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pSkills->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\PLAYER\\PlrModes.cpp", 0x57A);
    }
    else
    {
        pSkills->nRightSkillOwnerGUID = -1;
        pSkills->nRightSkillId = 0;
    }
}

// 0x00580260
static int sub_00580260_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 0x02:
    case 0x07:
        return 0;
    }

    return 1;
}

// 0x00580280
static void sub_00580280_RestoreActiveSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    if (pSkills->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit) && sub_00580260_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 1, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        }
    }

    if (pSkills->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit) && sub_00580260_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 0, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        }
    }
}

// 0x00580310
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        if (pInventory)
        {
            D2UnkPlrModeStrc2 tSkills;
            sub_005801E0_SaveActiveSkills(pUnit, &tSkills);

            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x04);
            if (pRightWeapon)
            {
                sRestoreWeapon(pGame, pUnit, pRightWeapon);
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x05);
            if (pLeftWeapon)
            {
                sRestoreWeapon(pGame, pUnit, pLeftWeapon);
            }

            sub_00580280_RestoreActiveSkills(pUnit, &tSkills);
        }
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00580380
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
        int bChangedToNeutral = 0;
        while (pItem)
        {
            if (INVENTORY_GetItemNodePage(pItem) == 3)
            {
                D2UnitStrc* pWeapon = INVENTORY_UnitIsItem(pItem);
                if (ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) && ITEMS_HasDurability(pWeapon)
                    && STATLIST_UnitGetStatValue(pWeapon, STAT_DURABILITY, 0) <= 0
                    && !ITEMS_CheckItemFlag(pWeapon, IFLAG_BROKEN, 1513, ".\\PLAYER\\PlrModes.cpp"))
                {
                    if (!bChangedToNeutral)
                    {
                        UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);
                        bChangedToNeutral = 1;
                    }

                    sub_6FC4B580(pGame, pPlayer, pWeapon);
                    pItem = INVENTORY_GetFirstItem(pInventory);
                    continue;
                }
            }

            pItem = INVENTORY_GetNextItem(pItem);
        }
    }
}

static __forceinline unsigned char UNITS_GetHpPercent_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
        if (nMaxLife > 0 && nHitpoints < nMaxLife)
            return (nHitpoints << 7) / nMaxLife;
    }
    return 0x80;
}

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord_Inline(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

// 0x00580500
static __declspec(noinline) void EVENTS_StaminaRegen(D2UnitStrc* pUnit)
{
    int nStamina = STATLIST_UnitGetStatValue(pUnit, 0xA, 0);
    int nShift = 8;
    const int nStaminaRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, 0x1C, 0);

    int nAnimMode;
    if (!pUnit)
        nAnimMode = 0;
    else
        nAnimMode = pUnit->dwAnimMode;

    switch (nAnimMode)
    {
    case 6:
        nShift = 9;
        break;

    case 2:
        nShift = 9;
        if (nStamina >> 8)
            break;
        return;

    case 1:
    case 5:
        break;

    default:
        if (nStaminaRecoveryBonus < 1000)
            return;
        break;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (nStamina < nMaxStamina)
    {
        int nAdd = nMaxStamina >> nShift;
        if (nStaminaRecoveryBonus)
            nAdd += (nStaminaRecoveryBonus * nAdd) / 100;

        nStamina += nAdd;
        if (nStamina > nMaxStamina)
            nStamina = nMaxStamina;

        STATLIST_SetUnitStat(pUnit, 0xA, nStamina, 0);
    }
}

// 0x005805D0
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}

// 0x00580610
static __declspec(noinline) int EVENTS_HpRegen(D2UnitStrc* pUnit)
{
    const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, 0x4A, 0);
    if (!nHpRegen)
        return 1;

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nLife = nHpRegen + nHitpoints;
    if (nLife > nMaxHp)
    {
        nLife = nMaxHp;
        D2StatListStrc* pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x64);
        if (pHealthPotStatList)
        {
            D2Common_10474(pUnit, pHealthPotStatList);
            STATLIST_FreeStatList(pHealthPotStatList);
        }
    }

    if (nLife < 0x100)
        nLife = 0x100;

    STATLIST_SetUnitStat(pUnit, 6, nLife, 0);

    const unsigned char nLastSentHpPct = STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
    const unsigned char nHpPct = UNITS_GetHpPercent_Inline(pUnit);

    int nHpPctDiff = nLastSentHpPct - nHpPct;
    if (nHpPctDiff < 0)
        nHpPctDiff = -nHpPctDiff;

    if (nHpPctDiff > 4)
    {
        SUNITMSG_QueueLifeUpdate(pUnit, nHpPct);
        STATLIST_SetUnitStat(pUnit, 0x160, nHpPct, 0);
    }
    return 1;
}

// 0x005806F0
static __declspec(noinline) void EVENTS_ManaRegen(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);

        int nManaRecovery = 0;
        if (!STATES_CheckState(pUnit, 0x55))
        {
            D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord_Inline(pUnit->dwClassId);
            if (!pCharStatsTxtRecord)
                return;

            int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
            if (!nManaRegen)
                nManaRegen = 7500;

            int nManaMultiplier = nMaxMana / nManaRegen;
            if (nManaMultiplier < 1)
                nManaMultiplier = 1;

            nManaRecovery = DATATBLS_ApplyRatio(nManaMultiplier, STATLIST_UnitGetStatValue(pUnit, 0x1B, 0) + 100, 100);
        }

        nManaRecovery += STATLIST_UnitGetStatValue(pUnit, 0x1A, 0);
        if (nMaxMana <= nMana && nManaRecovery > 0)
        {
            D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x6A);
            if (pManaPotStatList)
            {
                D2Common_10474(pUnit, pManaPotStatList);
                STATLIST_FreeStatList(pManaPotStatList);
            }
        }

        if (nManaRecovery > nMaxMana - nMana)
            nManaRecovery = nMaxMana - nMana;

        if (nManaRecovery < -nMana)
            nManaRecovery = -nMana;

        if (nManaRecovery)
            STATLIST_AddUnitStat(pUnit, 8, nManaRecovery, 0);
    }
}

// 0x00580800
void __fastcall D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x00580810
void __fastcall D2GAME_EVENTS_StatRegen_6FC80F80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, nEventCustomId, nEventCustomParam);
    if (SUNIT_IsDead(pUnit))
        return;

    if (EVENTS_HpRegen(pUnit))
    {
        EVENTS_StaminaRegen(pUnit);
        EVENTS_ManaRegen(pUnit);
    }
}

// 0x00580860
void __fastcall sub_6FC81650(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a4)
{
    D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (UNIT_HasFlagEx(pPlayer, UNITFLAGEX_TELEPORTED))
        {
            sub_6FC81CA0(pPlayer, pClient, 1);
        }
        else if (UNIT_HasFlagEx(pPlayer, 0x800) && pPlayer != pOtherPlayer)
        {
            sub_6FC81CA0(pPlayer, pClient, 0);
        }
    }

    if (!a4 && pPlayer && UNIT_HasFlagEx(pPlayer, UNITFLAGEX_HASINV))
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pPlayer, pClient, 0);
        D2GAME_SendPacket0x47_6FC3EEE0(pClient, pPlayer);
        D2GAME_SendPacket0x48_6FC3EF40(pClient, pPlayer, 0);
    }

    if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_DOUPDATE))
    {
        sub_6FC82270(pGame, pPlayer, pClient);
    }

    sub_6FCC6540(pPlayer, pClient);

    if (pPlayer)
    {
        if (UNIT_HasFlag(pPlayer, 0x400))
        {
            D2GAME_UpdateUnit_6FCC6080(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x100))
        {
            sub_00571620(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x8000))
        {
            sub_6FC81C00(pPlayer, pClient);
        }
    }

    if (STATES_IsAnyGfxStateFlagSet(pPlayer))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pPlayer, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pPlayer))
    {
        sub_6FCC5F20(pPlayer, pClient);
    }

    D2Common_10512(pPlayer, pOtherPlayer, STAT_VELOCITYPERCENT, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_ATTACKRATE, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_LEVEL, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_STRENGTH, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_DEXTERITY, D2GAME_UpdateAttribute_6FC822D0);
}

// 0x005809D0
void __fastcall sub_6FC817D0(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7)
{
    D2_ASSERT(ptGame, 0x805);

    if (sub_6FC81890(ptGame, pUnit, nMode) && (a7 || sub_0057EEC0(ptGame, pUnit, nMode, 1, pUsedSkill)))
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[nMode].pfnStartXY), 0x812);

        if (pUsedSkill)
        {
            UNITS_SetUsedSkill(pUnit, pUsedSkill);
        }

        gsPlayerModeChart_006E1740[nMode].pfnStartXY(ptGame, pUnit, nMode, nX, nY);
    }
}

// 0x00580A70
void __fastcall StartModeID(D2GameStrc* ptGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter)
{
    D2_ASSERT(ptGame, 0x835);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(ptGame, nUnitType, nTargetGUID);
    if (!pTarget)
    {
        sub_006248E0_Log(1, 2, 4, 4, ".\\PLAYER\\PlrModes.cpp", 0x83A, "StartModeID: Bad Target");
        return;
    }

    if (sub_6FC81890(ptGame, pPlayer, nMode) && (bAllowReEnter || sub_0057EEC0(ptGame, pPlayer, nMode, 1, pSkill)))
    {
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nMode = 0;
        }

        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[nMode].pfnStartID), 0x853);

        if (pSkill)
        {
            UNITS_SetUsedSkill(pPlayer, pSkill);
        }

        gsPlayerModeChart_006E1740[nMode].pfnStartID(ptGame, pPlayer, nMode, pTarget);
    }
}

// 0x00580B70
void __fastcall sub_6FC81B20(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    if (!pUnit)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
    {
        return;
    }

    const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
    if (nTimeout <= pGame->dwGameFrame)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_HASTXTMSG;
    }
    else
    {
        EVENT_SetEvent(pGame, pUnit, 6, nTimeout, 0, 0);
    }
}

// 0x00580BE0
void __fastcall sub_6FC81B90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    PARTY_SynchronizeWithClient(pGame, pUnit);
    sub_6FC7E640(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, 11, pGame->dwGameFrame + 30, 0, 0);
}

// 0x00581020
void __fastcall sub_6FC81250(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    switch (nAnimMode)
    {
    case 7:
    case 8:
    case 11:
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        break;

    default:
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (!pUsedSkill)
        {
            goto done;
        }

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 0x779));
        if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7]))
        {
            goto done;
        }

        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        break;
    }

done:
    switch (nAnimMode)
    {
    case 0:
        PLRMODE_StartXY_Dead(pGame, pUnit, 17, 0, 0);
        return;

    case 19:
        break;

    default:
        PLRMODE_StartXY_Neutral(pGame, pUnit, 1, 0, 0);
        return;
    }

    D2_ASSERT(pGame, 0x805);

    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        sub_0057ED70_IsEndAnimDue(pGame, pUnit);
        break;

    case 0:
    case 4:
    case 9:
    case 17:
        return;

    case 12:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit))
        {
            break;
        }
        return;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return;
        }
        break;

    case 18:
        if (!sub_0057ED90_CanEndSequence(pGame, pUnit))
        {
            return;
        }
        break;

    default:
        break;
    }

    if (!sub_0057EEC0(pGame, pUnit, 4, 1, 0))
    {
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gsPlayerModeChart_006E1740[4].pfnStartXY), 0x812);

    gsPlayerModeChart_006E1740[4].pfnStartXY(pGame, pUnit, 4, -1, 0);
}

// 0x00581220
void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam)
{
    if ((unsigned int)nEvent <= 14 && gpPlayerEventCallbacks_006E1810[nEvent])
    {
        gpPlayerEventCallbacks_006E1810[nEvent](pGame, pUnit, nCustomId, nCustomParam);
    }
}
