#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
#include "D2GameObjs.h"
#include "D2DrlgMaps.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2Win32Base.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StaticPathStrc;

struct D2UnkMonCreateStrc3;

struct D2UnkMonCreateStrc;

union D2SeedStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

struct D2PlayerDataStrc;

struct D2Act4Quest1Strc;

struct D2QuestGUIDStrc;

struct D2ObjOperateFnStrc;

struct D2GSPacketSrv5D;

struct D2GSPacketSrv50;

struct D2Act4Quest2Strc;

struct D2Act4Quest3Strc;

struct D2Act3Quest1Strc;

struct D2Act3Quest3Strc;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

struct D2Act3Quest6Strc;

struct D2Act3Quest7Strc;

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70

D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern D2UnkMonCreateStrc2 gBonePrisonSpawnInfo_0073D4F0; // 0x0073D4F0

D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc*); // 0x005B2A00

enum D2C_SpawnRandomConstants
{
    MONSTATSFLAGINDEX_ISSPAWN = 0,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct4Q0NpcMessages[]; // 0x0073D580

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int a2, int a3); // 0x00619DA0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B3750

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B3740

int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned char nQuestId[2];
    unsigned char data[0x0C];
};

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C3A0

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005351C0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0

void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710

void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940

void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc); // 0x0054B830

void __stdcall sub_005B4FF0_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005B4FF0

bool __fastcall sub_005BBF80_IsOrbNotSmashed(D2GameStrc* pGame); // 0x005BBF80

int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3CD0

int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3DE0

bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x005B3E60

int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3F20

int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B59C0

int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7340

void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7740

int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70

int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC210

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D70


#define CENTER 3

#define MASK_A 0x100

#define MASK_B 0x1c09

#define OFFSET_BASE (g_006E2D50_offsets)


struct D2TileLibraryEntryStrc;

extern D2CoordStrc g_006E2D50_offsets[4];  // 0x006E2D50

D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc*,int*); // 0x00619660

int __stdcall sub_00604BC0_GetTileFlags(D2TileLibraryEntryStrc*); // 0x00604BC0

unsigned short __stdcall sub_0064CB30_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short); // 0x0064CB30

struct D2GameStrc;

#define MONSTER_TENTACLEHEAD1 261

#define MONSTATSFLAGINDEX_SETBOSS 4

#define MONSTATSFLAGINDEX_BOSSXFER 5

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall sub_00463830_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463830

int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790

int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags); // 0x005B2570

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

static __declspec(noinline) void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit); // 0x005B2830

D2UnitStrc* __fastcall sub_005B3130_SpawnOwned(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7); // 0x005B3130

int __fastcall sub_005B31B0_SpawnMinionsAt(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags); // 0x005B31B0

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

struct D2RoomCoordListStrc { tagRECT box[2]; char unknown20[8]; int nIndex; };

extern unsigned char gbNeverCount_006CE270; // 0x006CE270

extern unsigned int gdwSetBoss_006CE278; // 0x006CE278

extern unsigned int gdwBossTransfer_006CE27C; // 0x006CE27C

extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT*,tagPOINT);

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730

void __stdcall sub_00643560_GameTileToSubtileCoords(int*,int*); // 0x00643560

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740

int __stdcall D2Common_10095(D2ActiveRoomStrc*,int,int); // 0x0061B130

int __fastcall sub_005FD350_CanSpawn(int,D2ActiveRoomStrc*,int,int,int); // 0x005FD350

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064D9B0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230

void __fastcall sub_00547D90_RegisterSpawn(D2MonsterRegionStrc**,D2ActiveRoomStrc*,D2UnitStrc*,int); // 0x00547D90

D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc*,int,int); // 0x0061AD30

void __fastcall sub_00552D60_SetVision(D2UnitStrc*,D2RoomCoordListStrc*); // 0x00552D60

void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc*,unsigned char,int); // 0x005543B0

static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B21B0

static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B1CF0

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc*); // 0x005B1C50

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pUnit, struct D2MonsterEquipmentStrc* pItemInfo, int nLevel, unsigned int nFlags); // 0x00573B20

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet);                         // 0x00573570

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId);    // 0x005447A0

struct D2MonsterEquipmentStrc
{
	int nItemCode;
	unsigned char nBodyLoc;
	unsigned char unk0x05;
	unsigned char unk0x06;
	unsigned char unk0x07;
};

extern const D2MonsterEquipmentStrc gtAncientEquipment[12]; // 0x006E2C90

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" const char gszAct4Q2SourceFile[]; // 0x006E2DA4

extern char gpAct4Q1NpcMessages[]; // 0x0073D708

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3860

void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3E30

void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4020

void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3BB0

void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B39A0

void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B37F0

bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B38E0

void __fastcall sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4DA0

void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0

extern "C" const char gszAct4Q3SourceFile[];

extern char gpAct4Q3NpcMessages[];

extern char gpAct4Q4NpcMessages[];

extern char gpAct3IntroNpcMessages[];

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240

int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);

int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData);

void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

__forceinline int CLIENTS_GetUnitX_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// build: context sub_6FC6A150
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return 0;
    }

    return sub_6FC68D70(pGame, pUnit, D2Common_11063(pRoom, nMonsterId), nAnimMode, a5, nFlags);
}

// 0x005B24E0
int __fastcall sub_6FC6A230(D2GameStrc* pGame, D2UnitStrc* pOwner, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    if (!pOwner)
        return 0;

    int nResult = 0;
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnitStrc* pMinion = sub_6FC68D70(pGame, pOwner, nMonsterId, nAnimMode, a5, nFlags);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }
    return nResult;
}

// 0x005B2700
int __stdcall sub_005B2700_FindPosition(D2ActiveRoomStrc* room,int* outX,int* outY)
{
    int count;
    D2DrlgTileDataStrc* tiles=sub_00619660_GetFloorTiles(room,&count);
    if (!tiles) return 0;
    if (!count) return 0;
    unsigned start=ITEMS_RollLimitedRandomNumber(room?&room->pSeed:0,count);
    if (!start) start=1;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(room,&bounds);
    unsigned index=start;
    unsigned stop=start-1;
    while (index!=stop) {
        D2DrlgTileDataStrc* tile=&tiles[index];
        if (tile->pTile && (sub_00604BC0_GetTileFlags(tile->pTile)&2)) {
            int x=5*(tile->nPosX+bounds.nTileXPos)+CENTER;
            int y=5*(tile->nPosY+bounds.nTileYPos)+CENTER;
            if (!sub_0064CB30_CheckMask(room,x,y,MASK_A)) {
                D2CoordStrc* offset=OFFSET_BASE;
                do {
                    if (!COLLISION_CheckMaskWithSize(room,x+offset->nX,y+offset->nY,2,MASK_B)) {
                        *outX=x;
                        *outY=y;
                        return 1;
                    }
                    ++offset;
                } while ((int)offset < (int)(OFFSET_BASE+4));
            }
        }
        index=(index+1)%(unsigned)count;
    }
    return 0;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x005B2830
static void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    int nChainId;
    DATATBLS_GetMonsterChainInfo(nMonsterId, 0, &nChainId);

    D2GameStrc* pGame = pMonCreate->pGame;
    const unsigned short nFlags = pMonCreate->nFlags;
    const short nMinion = pMonStatsTxtRecord->wMinion[0];
    if (nMinion < 0)
    {
        return;
    }
    const int nCount = *(volatile int*)&sgptDataTables->nMonStatsTxtRecordCount;
    if (nMinion >= nCount)
    {
        return;
    }

    const int nBaseId = sub_00463830_GetBaseIdFromMonsterId(nMonsterId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_TENTACLEHEAD1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS])
        {
            AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        }

        int nMinionIndex = 0;
        int nThreshold = 0;
        if (pMonStatsTxtRecord->wMinion[1] >= 0 && pMonStatsTxtRecord->wMinion[1] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            nThreshold = 1;
        }

        const int nMinions = sub_004CC790_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        for (int i = 0; i < nMinions; ++i)
        {
            D2UnitStrc* pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, pMonStatsTxtRecord->wMinion[nMinionIndex], 1, 4, 0x40);
            if (pMonster && (pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS]))
            {
                AIGENERAL_SetOwnerData(pGame, pMonster, sub_00451F50_GetUnitGUID(pUnit), 1, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pUnit, pMonster);
            }

            ++nMinionIndex;
            if (nMinionIndex > nThreshold)
            {
                nMinionIndex = 0;
            }
        }
    }
    else
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        const int nMinions = sub_004CC790_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        const unsigned int bNonWaterSpawn = ~((unsigned int)nFlags >> 2) & 1;
        sub_005B2570_SpawnMinionsAround(pGame, pUnit, pMonStatsTxtRecord->wMinion[0], 1, nMinions, bNonWaterSpawn, 0x40);
    }
}

// build: context MONSTERREGION_SanitizeMonsterId_Inline
static __forceinline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x5B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x14, 0);
        break;
    case 0x18:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xD, 0);
        break;
    case 0x60:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xA, 0);
        break;
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14A:
    case 0x162:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xE, 0);
        break;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xF, 0);
        break;
    case 0x1CD:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x21, 0);
        break;
    case 0x1B4:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x22, 0);
        break;
    case 0x1F5:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x23, 0);
        break;
    case 0xD3:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xB, 0);
    case 0x21C:
    case 0x21D:
    case 0x21E:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        break;
    }
}

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
	const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
	const D2MonsterEquipmentStrc* pItemInfo = &gtAncientEquipment[nClassId - 540];

	int nItemId;
	int nCount = 4;
	do
	{
		D2MonsterEquipmentStrc itemInfo = *pItemInfo;
		D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemInfo->nItemCode, &nItemId);
		switch (pGame->nDifficulty)
		{
		case 1:
			itemInfo.nItemCode = pItemsTxtRecord->dwUberCode;
			break;

		case 2:
			itemInfo.nItemCode = pItemsTxtRecord->dwUltraCode;
			break;
		}

		sub_6FC61190(pGame, pUnit, &itemInfo, nLevel, 4);
		pItemInfo += 3;
		--nCount;
	}
	while (nCount);
}

// build: context MONSTERS_GetMonStatsTxtRecord_Inline
static __forceinline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// build: context MONSTERS_ValidateMonsterId_Inline
static __forceinline int MONSTERS_ValidateMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

// build: context MONSTERUNIQUE_ToggleUnitFlag_Inline
static __forceinline void MONSTERUNIQUE_ToggleUnitFlag_Inline(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    void* pRoom = pMonCreate->pRoom;
    const int nMonsterId = pMonCreate->nMonsterId;

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecord_Inline(nMonsterId);
    int nBaseId;
    if (!pMonStatsTxtRecord)
    {
        nBaseId = nMonsterId;
    }
    else
    {
        nBaseId = pMonStatsTxtRecord->nBaseId;
    }

    switch (MONSTERS_ValidateMonsterId_Inline(nBaseId))
    {
    case 0xD3:
        if (nMonsterId != 0x2C4)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0xD);
            QUESTS_CreateChainRecord(pGame, pUnit, 9);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0xAF:
    {
        const int nWarrivId = MONSTERS_ValidateMonsterId_Inline(0xAF);
        QUESTS_WarrivSpawn(pGame, pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nWarrivId);
        return;
    }
    case 0xFA:
        QUESTS_CreateChainRecord(pGame, pUnit, 0xC);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x800);
        MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
        return;
    case 0xF3:
        if (nMonsterId != 0x2C1)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x17);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x16E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x13);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        return;
    case 0xF2:
        if (nMonsterId != 0x2C0)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x14);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1E, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x11, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x9C:
        if (nMonsterId != 0x2C3)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 6);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1D, 1);
        return;
    case 0x199:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x18);
        return;
    case 0x100:
        if (nMonsterId != 0x2C2)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x16);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0x197:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x11);
        return;
    case 0xE5:
        QUESTS_CreateChainRecord(pGame, pUnit, 8);
        return;
    case 0x10B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xC, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        QUESTS_CreateChainRecord(pGame, pUnit, 2);
        STATES_ToggleState(pUnit, 0x76, 1);
        return;
    case 0x11C:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x124:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1F, 0);
        return;
    case 0x192:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x1B2:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x20);
        return;
    case 0x20E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x22);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x21C:
        MONSTERSPAWN_EquipAncientBarbarians(pUnit);
        return;
    case 0x220:
        if (nMonsterId != 0x2C5)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x24);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    }
}

// build: context GetMonStats2
static __forceinline D2MonStats2Txt* GetMonStats2(int nId)
{
    if(nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nIndex=sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if(nIndex<0 || nIndex>=sgptDataTables->nMonStats2TxtRecordCount) return 0;
    return &sgptDataTables->pMonStats2Txt[nIndex];
}

// build: context SEED_RollRandomNumber
static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context ITEMS_RollRandomNumber
static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed);
}

// 0x005B2A00
D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc* pCreate)
{
    D2MonStatsTxt* pRecord=DATATBLS_GetMonStatsTxtRecord_Inline(pCreate->nMonsterId);
    if(!pRecord) return 0;
    D2MonStats2Txt* pRecord2=GetMonStats2(pCreate->nMonsterId);
    if(!pRecord2) return 0;
    const unsigned short nFlags=pCreate->nFlags;
    D2ActiveRoomStrc* pRoom=pCreate->pRoom;
    unsigned int nCollisionMask;
    switch(pRecord2->nSpawnCol)
    {
    case 1:nCollisionMask=0x1c0;break;
    case 2:nCollisionMask=0x3f11;break;
    case 3:nCollisionMask=0;break;
    case 0:nCollisionMask=0x3c01;break;
    default:nCollisionMask=0x3c01;break;
    }
    tagRECT area;
    int nAreaTile,bCheckTile;
    if(!pCreate->pRoomCoordList)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom,&coords);
        area.bottom=coords.nSubtileY+coords.nSubtileHeight;area.left=coords.nSubtileX;area.right=coords.nSubtileX+coords.nSubtileWidth;area.top=coords.nSubtileY;
        nAreaTile=0;bCheckTile=0;
    }
    else
    {
        CopyRect(&area,&pCreate->pRoomCoordList->box[1]);
        sub_00643560_GameTileToSubtileCoords((int*)&area.left,(int*)&area.top);
        sub_00643560_GameTileToSubtileCoords((int*)&area.right,(int*)&area.bottom);
        nAreaTile=pCreate->pRoomCoordList->nIndex;bCheckTile=1;
    }
    if (!pRoom)
        return 0;
    if (!&pRoom->pSeed)
        return 0;
    int nRadius,nMaxRadius;
    if(pCreate->nMaxSearchRings<0) nRadius=0; else nRadius=3;
    if(!nRadius) nMaxRadius=0; else nMaxRadius=3*pCreate->nMaxSearchRings;
    {
    int nSpawnY=0,nSpawnX=0;
    if(pRecord2->nSpawnCol==1 && !(pCreate->nMonsterId>=0x102 && pCreate->nMonsterId<=0x107) && pCreate->nMonsterId!=0x99)
    {
        sub_005B2700_FindPosition(pRoom,&nSpawnX,&nSpawnY);
        pRoom=sub_00463740_FindRoomAtPoint(pRoom,nSpawnX,nSpawnY);
    }
    else
    {
        if(nRadius>nMaxRadius) return 0;
        do
        {
            D2SeedStrc* pSeed=&pRoom->pSeed;
            int nX=pCreate->nX,nY=pCreate->nY;
            const int nDiameter=2*nRadius;
            int nOffsetX,nOffsetY,nStepX,nStepY;
            if(ITEMS_RollRandomNumber(pSeed)&1)
            {
                nOffsetX=nRadius; if (nX) nOffsetY=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); else nOffsetY=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); nStepX=0; nStepY=1;
            }
            else
            {
                if (nX && nRadius) nOffsetX=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); else nOffsetX=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1);nOffsetY=nRadius;nStepX=1;nStepY=0;
            }
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetX=-nOffsetX;
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetY=-nOffsetY;
            nX+=nOffsetX;nY+=nOffsetY;
            const int nMinX=pCreate->nX-nRadius,nMaxX=nMinX+nDiameter;
            const int nMinY=pCreate->nY-nRadius,nMaxY=nMinY+nDiameter;
            int nSteps=4*nDiameter;
            if(!nSteps) nSteps=1;
            while(nSteps>0)
            {
                if(nX==nMinX && nY==nMinY) {nStepX=1;nStepY=0;}
                if(nX==nMaxX)
                {
                    if(nY==nMinY) {nStepX=0;nStepY=1;}
                    if(nY==nMaxY) {nStepX=-1;nStepY=0;}
                }
                if(nX==nMinX)
                {
                    if(nY==nMaxY) {nStepX=0;nStepY=-1;}
                    if(nY==nMinY && nX==nMaxX && nY==nMaxY) {nStepX=0;nStepY=0;}
                }
                nX+=nStepX;nY+=nStepY;
                tagPOINT point;point.x=nX;point.y=nY;
                if(PtInRect(&area,point) && (!bCheckTile || D2Common_10095(pRoom,nX,nY)==nAreaTile)
                    && sub_005FD350_CanSpawn(pCreate->nMonsterId,pRoom,nX,nY,1)
                    && (!COLLISION_CheckMaskWithSize(pRoom,nX,nY,pRecord2->nSizeX,nCollisionMask) || (pCreate->nFlags&0x80)))
                {
                    nSpawnX=nX;nSpawnY=nY;nRadius=nMaxRadius;break;
                }
                --nSteps;
            }
            const int nNext=nRadius+3;
            *(int volatile*)&nRadius=nNext;
            if(nStepX && nStepY && nFlags){if(nNext>nMaxRadius)break;}else{if(nNext>nMaxRadius)break;}
        }while(1);
    }
    if(!nSpawnX || !nSpawnY) return 0;
    if(nFlags&1) return (D2UnitStrc*)1;
    int nAllocFlags=1;if(nFlags&0x20)nAllocFlags=3;
    D2UnitStrc* pMonster=SUNIT_AllocUnitData(1,pCreate->nMonsterId,nSpawnX,*(int volatile*)&nSpawnY,pCreate->pGame,pRoom,nAllocFlags,pCreate->nAnimMode,pCreate->nUnitGUID);
    if(pMonster)
    {
        int bNeverCount=nFlags&8;
        if(pRecord->nMonStatsFlags[2]&gbNeverCount_006CE270) bNeverCount=1;
        sub_00547D90_RegisterSpawn(pCreate->pGame->pMonReg,pRoom,pMonster,bNeverCount);
        D2RoomCoordListStrc* pList=pCreate->pRoomCoordList;
        if(!pList) pList=D2Common_10096(pRoom,nSpawnX,nSpawnY);
        sub_00552D60_SetVision(pMonster,pList);
        switch(pRecord->nAlign)
        {
        default:sub_005543B0_AssignAlignment(pMonster,0,1);break;
        case 2:sub_005543B0_AssignAlignment(pMonster,1,1);break;
        case 1:sub_005543B0_AssignAlignment(pMonster,2,1);pMonster->dwFlags|=0x20000;break;
        }
        if(!(nFlags&2)) MONSTERSPAWN_SetupNormalMods(pCreate,pMonster);
        MONSTERSPAWN_SetupBossMods(pCreate,pMonster);
        if(!(nFlags&0x40)) MONSTERSPAWN_SpawnMinionParty(pCreate,pMonster);
    }
    return pMonster;
    }
}

struct D2BitBufferStrc;

struct D2QuestDataStrc;

struct D2UnitStrc;

// 0x005B3040
D2UnitStrc* __fastcall sub_005B3040_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pCoordList;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B3090
D2UnitStrc* __fastcall sub_005B3090_SpawnAtPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pGame = pGame;
    monCreate.pRoom = pRoom;
    monCreate.pRoomCoordList = 0;
    monCreate.nMaxSearchRings = -1;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B30E0
D2UnitStrc* __fastcall sub_005B30E0_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = nUnitGUID;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}

// 0x005B3130
D2UnitStrc* __fastcall sub_005B3130_SpawnOwned(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7)
{
    D2UnkMonCreateStrc tRequest;
    tRequest.nUnitGUID = 0;
    tRequest.nMonsterId = a3;
    tRequest.nAnimMode = a4;
    tRequest.pGame = pGame;
    tRequest.pRoom = (D2ActiveRoomStrc*)pRoom;
    tRequest.pRoomCoordList = 0;
    tRequest.nMaxSearchRings = a5;
    tRequest.nFlags = a7;
    tRequest.nX = a1;
    tRequest.nY = a2;
    D2UnitStrc* pUnit = sub_005B2A00_SpawnNormalMonster(&tRequest);
    if (pUnit)
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, a6);
    }
    return pUnit;
}

// 0x005B31B0
int __fastcall sub_005B31B0_SpawnMinionsAt(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    int nResult = 0;
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnkMonCreateStrc monCreate;
        monCreate.nUnitGUID = 0;
        monCreate.nMonsterId = nMonsterId;
        monCreate.nAnimMode = nAnimMode;
        monCreate.pGame = pGame;
        monCreate.pRoomCoordList = 0;
        monCreate.pRoom = pRoom;
        monCreate.nMaxSearchRings = a5;
        monCreate.nFlags = nFlags;
        monCreate.nX = nX;
        monCreate.nY = nY;

        D2UnitStrc* pMinion = sub_005B2A00_SpawnNormalMonster(&monCreate);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }

    return nResult;
}

// build: context sub_005B2830_Shim
// calling-convention shim (not game code)
void __fastcall sub_005B2830_Shim(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    MONSTERSPAWN_SpawnMinionParty(pMonCreate, pUnit);
}

// 0x005B3270
int __fastcall MONSTERSPAWN_SpawnFormation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* pInfo, short nFlags)
{
    int nResult = 0;
    D2UnitStrc* pLeader = 0;
    int bForce = 0;
    int bIncrement = 0;
    if (pInfo->unk0x08 & 1) bIncrement = 1;
    if (nFlags & 1) bForce = 1;
    const int nCount = pInfo->nRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pInfo = (D2UnkMonCreateStrc2*)pInfo->records;
        D2UnkMonCreateStrc3* pRecord = (D2UnkMonCreateStrc3*)pInfo;
        switch (bForce ? 4 : pRecord->nSpawnType)
        {
        case 1:
            pLeader = sub_005B3130_SpawnOwned(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0, 0);
            if (pLeader) nResult = 1;
            break;
        case 2:
            pLeader = sub_005B3130_SpawnOwned(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0);
            if (pLeader) nResult = 1;
            break;
        case 5:
            if (pOwner)
            {
                D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0);
                if (pMinion)
                {
                    AIGENERAL_SetOwnerData(pGame, pMinion, sub_00451F50_GetUnitGUID(pOwner), sub_0044BE50_GetUnitTypeOrInvalid(pOwner), 0, 0);
                    nResult = 1;
                }
            }
            break;
        case 3:
            if (pLeader && sub_005B31B0_SpawnMinionsAt(pGame, pLeader, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0)) nResult = 1;
            break;
        case 0:
        {
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.nMaxSearchRings = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (sub_005B2A00_SpawnNormalMonster(&monCreate)) nResult = 1;
            break;
        }
        case 4:
        {
            nResult = 1;
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.nMaxSearchRings = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (!sub_005B2A00_SpawnNormalMonster(&monCreate)) return 0;
            break;
        }
        }
        if (bIncrement) ++nClassId;
    }
    return nResult;
}

// 0x005B34C0
int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7)
{
    int nResult = 0;
    if (a6 == 340)
    {
        if (!pTargetUnit)
            return 0;

        const int nX = CLIENTS_GetUnitX_Inline(pTargetUnit);
        const int nY = CLIENTS_GetUnitY_Inline(pTargetUnit);
        nResult = sub_005B3270(pGame, pRoom, nX, nY, 0, 340, 8, &gBonePrisonSpawnInfo_0073D4F0, a7);
    }
    return nResult;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005B3570
int __fastcall MONSTERSPAWN_SpawnRandomMonsterForLevel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord->nNumNormalMonsters, 1264);

    int nIndex = ITEMS_RollLimitedRandomNumber(pRoom ? &pRoom->pSeed : 0, pLevelsTxtRecord->nNumNormalMonsters);
    int nMonsterId = -1;
    int nCounter = 0;
    for (nCounter = 0; nCounter < pLevelsTxtRecord->nNumNormalMonsters; ++nCounter)
    {
        ++nIndex;
        if (nIndex >= pLevelsTxtRecord->nNumNormalMonsters)
        {
            nIndex = 0;
        }

        nMonsterId = pLevelsTxtRecord->wNormalMonsters[nIndex];
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ISSPAWN >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ISSPAWN & 7])
        {
            break;
        }
    }

    if (nMonsterId == -1)
    {
        return 0;
    }

    D2_ASSERT(nCounter < pLevelsTxtRecord->nNumNormalMonsters, 1287);

    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = 1;
    monCreate.pRoom = pRoom;
    monCreate.pRoomCoordList = 0;
    monCreate.nMaxSearchRings = 5;
    monCreate.pGame = pGame;
    monCreate.nFlags = 0;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate) != 0;
}

// 0x005B36A0
void __fastcall ACT4Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo == 367 && pQuestArg->nMessageIndex == 664)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, 24, 0);
    }
}

// 0x005B36D0
void __fastcall ACT4Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pTarget = pQuestArg->pTarget;
    if (!pTarget || pTarget->dwClassId != 367)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 24, 0))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId, 0);
    }
}

// 0x005B3740
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x005B3780
void __fastcall ACT4Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q0_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT4Q0_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct4Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 24;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q0_ActiveFilterCallback;
}

// 0x005B3860
int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 2);
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        if (pQuestDataEx->unk0x0C)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 25, 4);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 3);
    }

    return 0;
}

// 0x005B38E0
bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 0xA1);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

void __cdecl sub_005BDB10_Return()
{
}

// 0x005B3940
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, 22);
    }

    return 0;
}

// 0x005B39A0
void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestData->pGame;
    unsigned short nNpcId = pQuestArg->nNPCNo;
    unsigned short nMessageId = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNpcId == 0x16F)
    {
        if (nMessageId == 0x29E)
        {
            pQuestDataEx->bTyraelActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xD3);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }
        if (nMessageId == 0x2A4 && QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13))
            {
                if (pQuestData->fState != 5)
                {
                    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xDE);
                    if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
                    {
                        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDF);
                        exit(-1);
                    }
                    pQuestData->pfSeqFilter(pQuestData);
                    pQuestData->dwFlags &= 0xFFFFFF00;
                    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
                }
                pQuestData->pCallback[2] = 0;
                QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, 13);
            }
            QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 0);
            QUESTRECORD_ClearQuestState(pFlags, pQuestData->eFilter, 1);
            QUESTRECORD_ResetIntermediateStateFlags(pFlags, pQuestData->eFilter);
            STATLIST_AddUnitStat(pQuestArg->pPlayer, 5, 2, 0);
            QUESTS_SendLogUpdate(pQuestArg->pPlayer, 22);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNpcId == 0x196 && nMessageId == 0x2A3)
    {
        pQuestDataEx->bIzualGhostActivated = 1;
        pQuestDataEx->bGhostActivated = 1;
        QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 5);
        if (pQuestData->fLastState != 4)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
        }
    }
}

static int nIndices_0073D56C[] =                                                                            // 0x0073D56C
{
    -1, 0, 1, -1, -1
};

static int nIndices_0073DBA0[] =                                                                            // 0x0073DBA0
{
    -1, 0, 1, 2, 3, 4
};

static int nIndices_0073F188[] =                                                                            // 0x0073F188
{
    -1, 0, 1, 2, 3, 4
};

static int nIndices_007401B8[] =                                                                            // 0x007401B8
{
    -1, 0, 1, 2, 3, 4
};

// 0x005B3BB0
void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);

    int nNpcId;
    if (!pQuestArg->pTarget)
    {
        nNpcId = -1;
    }
    else
    {
        nNpcId = pQuestArg->pTarget->dwClassId;
        if (nNpcId == 406 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 406, 3);
            return;
        }
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone))
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        const int nIndex = nIndices_0073DBA0[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B3CD0
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 25, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 14);
        QUESTS_SendLogUpdateEx(pUnit, 22, 0);
    }

    return 0;
}

// 0x005B3D30
int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        SUNIT_AttachSound(pUnit, 74, pUnit);
    }

    return 0;
}

// 0x005B3D70
void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 3)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 25);
}

// 0x005B3DE0
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT4Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B3E30
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x005B3E60
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuest->pQuestDataEx;
    if (pQuest->fState == 4 && pQuest->fLastState != 4 && pQuest->fLastState != 13)
    {
        pQuest->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuest, 3, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }

    if (pQuestDataEx->bNeedToSpawnIzualGhost)
    {
        pQuestDataEx->bNeedToSpawnIzualGhost = 0;

        D2ActiveRoomStrc* pRoom = sub_00619DA0_ActLookup(pGame->pAct[3], pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY);
        if (pRoom)
        {
            if (!D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, -1, 0)
                && !D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, 3, 0))
            {
                D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, 406, 8, 5, 0);
            }
        }
    }

    pQuestDataEx->bIzualGhostIsSpawning = 0;
    return 1;
}

// 0x005B4020
void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 511);

    pQuestData->pCallback[2] = 0;

    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 513);

    pQuestData->pCallback[8] = 0;

    pQuestDataEx->pTargetUnit = pQuestArg->pTarget;
    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
                QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);
            }
        }
        pQuestDataEx->bNeedToSpawnIzualGhost = 1;
        UNITS_GetCoords(pQuestArg->pTarget, &pQuestDataEx->pCoords);

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetCompletionFlag);
    }

    if (!pQuestDataEx->bIzualGhostIsSpawning)
    {
        pQuestDataEx->bIzualGhostIsSpawning = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q1_SpawnIzualGhost, 3);
    }
}

// 0x005B4140
void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }
    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
    {
        return;
    }
    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 571);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
    if (!pQuestData->fLastState)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
    }
}

// 0x005B41D0
void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 367)
    {
        return;
    }
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTyraelActivated != 1)
    {
        return;
    }
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bTyraelActivated = 0;
    pQuestData->pCallback[2] = 0;
}

// 0x005B4220
void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 4) == 1)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x0C = 1;
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B42B0
void __fastcall ACT4Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    pQuestData->pNPCMessages = gpAct4Q1NpcMessages;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT4Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT4Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q1_Callback13_PlayerStartedGame;
    pQuestData->eFilter = 25;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q1_ActiveFilterCallback;
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 672, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q1_SeqCallback;
    pQuestData->nSeqId = 24;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest1Strc));
}

// 0x005B4530
bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 145);
    }
    return 1;
}

// 0x005B4560
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 2);
        return 0;
    }
    if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 26, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 4);
    }
    return 0;
}

// 0x005B4790
void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bCustom3 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 7);
    const int bCustom2 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 6);
    const int bCustom5 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 9);
    const int bCustom4 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 8);

    if (!pQuestData->pGame->bExpansion)
    {
        if (bCustom3 && nNpcId == 367)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 2);
            return;
        }
        if (bCustom2 && nNpcId == 246)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 2);
            return;
        }
        if (bCustom3)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 3);
            }
            return;
        }
        if (bCustom2)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 3);
            }
            return;
        }
    }

    if (bRewardGranted == 1)
    {
        if (!pQuestData->pGame->bExpansion)
        {
            return;
        }

        if (!bCustom5)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 4);
            }
            else if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 5);
            }
        }

        if (!bCustom4)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 4);
            }
            else if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 5);
            }
        }
        return;
    }

    if ((pQuestData->fState < 4 || bPrimaryGoalDone) && pQuestData->bNotIntro && pQuestData->fState)
    {
        const int nIndex = nIndices_0073D56C[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 7)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B4970
int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 14);
    QUESTS_SendLogUpdateEx(pUnit, 23, 0);
    return 0;
}

// 0x005B4A80
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    sub_6FC7BEC0(pGame, pUnit);
    UNITS_GetPlayerData(pUnit)->bBusy = 1;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)QUESTS_GetQuestData(pGame, 23)->pQuestDataEx;
    pQuestDataEx->unk0x20 = (int)pUnit;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        LEVEL_WarpUnit(pGame, pUnit, 103, 0);

        D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 440);
        D2GSPacketSrv5D packet5D = {};
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 23;
        packet5D.nFlags = 1;
        sub_6FC3F380(pClient, &packet5D);
    }
    else
    {
        D2GSPacketSrv50 packet50;
        packet50.nHeader = 0x50;
        *(unsigned short*)packet50.nQuestId = 23;
        D2GAME_SendPacket0x50_6FC3F440(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 474), &packet50);
    }

    return 0;
}

// 0x005B4DF0
int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted, 0);
    }
    return 0;
}

// 0x005B4E40
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 23);
    }
    return 0;
}

// 0x005B5880
int __fastcall OBJECTS_OperateFunction73_LastLastPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2GameStrc* pGame = pOp->pGame;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->hPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);
    if (!pRoom)
    {
        return 0;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return 0;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);

        D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1370);
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOp->hPlayer);
        if (pClient && !PLAYER_IsBusy(pOp->hPlayer))
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            pPlayerData->bBusy = 1;

            D2GSPacketSrv5D packet5D = {};
            packet5D.nHeader = 0x5D;
            packet5D.nQuestId = 23;
            packet5D.nFlags = 2;
            sub_6FC3F380(pClient, &packet5D);
            sub_0053D940_SendPacket0x61(pClient, 5);
        }
    }

    D2GAME_PlayerChangeAct_6FC867C0(pOp->pGame, pOp->hPlayer, 109, 5);
    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->hPlayer);
    sub_005B4FF0_ActivateHarrogathWaypoint(pOp->pGame, pOp->hPlayer);
    return 0;
}

// 0x005B6100
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNPCNo != 246)
    {
        return;
    }

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (nMessageIndex == 678)
    {
        pQuestDataEx->bCainActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 462);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 679)
    {
        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm', 0, 2, 1))
        {
            pQuestDataEx->bCainActivated = 1;
            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 513);
            }
            pQuestDataEx->bSoulstoneAcquired = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nMessageIndex == 680)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13) && pQuestData->fState != 5)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q3_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 530);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 531);
                pQuestData->pfSeqFilter(pQuestData);
            }

            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 1);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x005B62D0
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (pQuestData->fState && bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) && pQuestData->bNotIntro)
    {
        if (pQuestData->fState == 1)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
            }
            else if (!((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired && pQuestData->fLastState < 3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
        else
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm') && pQuestData->fLastState < 3 && !((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
    }
}

// 0x005B65D0
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' hfh';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestArg->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

// 0x005B7400
void __fastcall ACT3Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 17, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 17, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' bbb'))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
    }
    else if (pQuestData->bNotIntro && pQuestData->fState < 4)
    {
        const int nIndex = nIndices_0073F188[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B74E0
int __fastcall ACT3Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
        }
    }
    return 0;
}

// 0x005B7A60
int __fastcall OBJECTS_OperateFunction28_LamEsenTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 15);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    if (!pOp->hObject || pOp->hObject->dwAnimMode == 0)
    {
        D2GameStrc* pGame = pOp->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->hPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        pOp->hObject->dwDropItemCode = ' bbb';
        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, 2);

            D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nTomesInGame += 1;
            pQuestDataEx->bTomeActive = 1;
            pQuestDataEx->bTomeDropped = 1;
            pQuestDataEx->nTomeObjectMode = 2;
            pQuestDataEx->nTomeGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;

            pQuestData->pCallback[0] = ACT3Q1_Callback00_NpcActivate;
            pQuestData->pCallback[11] = ACT3Q1_Callback11_ScrollMessage;

            if (pQuestData->fState != 3)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 699);
            }

            if (pQuestData->fLastState != 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, false);
            }
        }
    }

    return 0;
}

// 0x005B8B20
int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pGame, pUnit, ' 33g'))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 5);
        return 0;
    }

    if (((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnDropped)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 4);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 3))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 2);
        }
    }
    else
    {
        if (pQuestData->fState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 3);
        }
    }

    return 0;
}

// 0x005B8E10
bool __fastcall ACT3Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
        return false;
    }

    if (nNpcId == 253)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g') || pQuest->fState != 1)
        {
            return false;
        }

        return true;
    }
    else if (nNpcId == 255)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
        {
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            return true;
        }
    }
    else if (nNpcId == 252)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            return true;
        }
    }

    return false;
}

// 0x005B8EC0
void __fastcall ACT3Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 19, 0);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        return;
    }

    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    if (pGidbinn && QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
    {
        const int bNoCustom4 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8);
        const int bNoCustom3 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 7);
        if (nNpcId == 252)
        {
            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }
        else
        {
            if (nNpcId == 255 && bNoCustom4)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
                return;
            }

            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }

        if (bNoCustom4)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
            return;
        }

        if (pQuestData->fState < 4 && !pGidbinn)
        {
            const int nIndex = nIndices_007401B8[pQuestData->fState];
            if (nIndex != -1 && (unsigned int)nIndex < 8)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
            }
        }
    }
}

// 0x005B9700
void __fastcall ACT3Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pGidbinn)
    {
        ++pQuestDataEx->nGidbinnsInGame;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
    if (pGidbinn)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 4;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        pQuestDataEx->nAltarObjectMode = 2;
        pQuestData->fState = 5;

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            pQuestData->fLastState = 5;
        }
        else if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            pQuestData->fLastState = 6;
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 0);
            pQuestData->bNotIntro = 0;
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 2;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 4) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 3) == 1)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 2) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 1;
        }
    }
    }
    else
    {
        pQuestDataEx->nAltarObjectMode = 2;
    }
}

// 0x005B9980
void __fastcall ACT3Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 991);

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (!pQuestDataEx->bBossHasSpawned || !pQuestData->bNotIntro || (!MONSTERUNIQUE_CheckMonTypeFlag(pQuestArg->pTarget, 14) && !MONSTERS_IsBoss(0, pQuestArg->pTarget)))
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' 33g';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestDataEx->bGidbinnDropped = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestData->pCallback[8] = 0;
    }
    else
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}

// 0x005B9D90
bool __fastcall ACT3Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        return false;
    }

    if (nNpcId == 254)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g'))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
        {
            return true;
        }
    }
    else if (nNpcId == 264)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j'))
        {
            return true;
        }
    }
    else if (nNpcId == 245)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            return true;
        }
    }

    return false;
}

// 0x005BA870
void __fastcall ACT3Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        return;
    }

    D2UnitStrc* pGoldenBird = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g');
    D2UnitStrc* pJadeFigurine = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j');
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        return;
    }

    if (pGoldenBird)
    {
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 4;
        }
        else
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 3;
        }
    }
    else if (pJadeFigurine)
    {
        pQuestDataEx->unk0x01 = 0;
        pQuestDataEx->unk0x0C = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else
        {
            pQuestData->fState = 1;
            pQuestData->fLastState = 1;
        }
    }
}

// 0x005BB210
void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) == 1)
    {
        return;
    }

    if (nNPCNo == 255)
    {
        if (nMessageIndex == 594)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 432);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 436);
            }

            ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNPCNo == 245)
    {
        if (nMessageIndex == 626 && QUESTRECORD_GetQuestState(pQuestFlags, 21, 4))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13) && pQuestData->fState != 7)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, 21, 13);
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 462);
            }

            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 465);
            pQuestData->pfSeqFilter(pQuestData);

            QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, 21, 4);

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x005BC5A0
void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 22, 11) && QUESTRECORD_GetQuestState(pQuestFlags, 22, 0))
    {
        return;
    }

    if (nNPCNo == 255 && nMessageIndex == 628)
    {
        if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 463);
        }
        else
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 467);
        }

        ((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        return;
    }

    if (nMessageIndex == 658 || nMessageIndex == 657 || nMessageIndex == 659 || nMessageIndex == 660
        || nMessageIndex == 661 || nMessageIndex == 662 || nMessageIndex == 663)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 11))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 13))
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q6_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 487);
            }

            QUESTRECORD_ClearQuestState(pQuestFlags, 22, 11);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

// 0x005BD0D0
int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 28);
    if (pQuestData)
    {
        D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bDarkWandererInitialized)
        {
            *pCoord = *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX;

            if (pQuestDataEx->bWandererCoordsCalculated)
            {
                return 1;
            }

            pCoord->nY += -20;
            pQuestDataEx->bWandererCoordsCalculated = 1;

            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nY += 9;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nX += 2;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nX += -4;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            *pCoord = *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX;
            pCoord->nY += -8;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nY += 5;
            *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
            return 1;
        }
    }

    return 0;
}

// 0x005BD500
bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 245)
    {
        if (pQuest->fState >= 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
        {
            return true;
        }

        int nParts = 0;
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 3))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 6))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 4))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq') && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 7) && sub_005BBF80_IsOrbNotSmashed(pQuest->pGame))
        {
            return true;
        }

        if (nParts == 4 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
        {
            return true;
        }
    }

    return false;
}

// 0x005BD850
bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;

    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        return true;
    }

    const int bStarted = QUESTRECORD_GetQuestState(pFlags, 18, 2);
    if (bStarted || pQuest->bNotIntro && pQuest->fState >= 2)
    {
        *pStatus = 1;
    }

    int nParts = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq'))
    {
        D2QuestDataStrc* pQuestData19 = QUESTS_GetQuestData(pQuest->pGame, 19);
        const bool bNotSmashed = pQuestData19 ? ((D2Act3Quest5Strc*)pQuestData19->pQuestDataEx)->bOrbSmashed == 0 : true;
        if (bNotSmashed)
        {
            *pStatus = 6;
        }
        else
        {
            *pStatus = 12;
        }
        return true;
    }

    int bBaseFlail = 0;
    int bEye = 0;
    int bHeart = 0;
    int bBrain = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
    {
        ++nParts;
        bBaseFlail = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
    {
        ++nParts;
        bEye = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
    {
        ++nParts;
        bHeart = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
    {
        ++nParts;
        bBrain = 1;
    }

    if (nParts == 4)
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 18, 5) ? 5 : 7;
        return true;
    }

    if (nParts)
    {
        if (!bEye)
        {
            *pStatus = 1;
            return true;
        }

        if (!bBrain)
        {
            *pStatus = 2;
            return true;
        }

        if (!bHeart)
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = bBaseFlail ? 7 : 3;
        return true;
    }

    if (bStarted)
    {
        *pStatus = 1;
        return true;
    }

    *pStatus = pQuest->fState > 1;
    return true;
}

void __fastcall ACT4Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, gszAct4Q3SourceFile, 433);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}

void __fastcall ACT4Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) == 0x20686668)
    {
        --pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20686668))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pfActiveFilter = ACT4Q3_ActiveFilterCallback;
    pQuestData->pQuestDataEx = 0;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;
    pQuestData->pNPCMessages = gpAct4Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfSeqFilter = ACT4Q3_SeqCallback;
    pQuestData->nSeqId = 23;
    pQuestData->eFilter = 27;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT4Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT4Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT4Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[8] = ACT4Q3_Callback08_MonsterKilled;
    pQuestData->pCallback[4] = ACT4Q3_Callback04_ItemPickedUp;

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest3Strc), gszAct4Q3SourceFile, 856, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest3Strc));
}

void __fastcall ACT4Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 408)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 23);
        if (!pQuest || !((D2Act4Quest2Strc*)pQuest->pQuestDataEx)->bDiabloKilled)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 1);
        }
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 0);
    }
}

void __fastcall ACT4Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q4_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct4Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 33;
    pQuestData->pfStatusFilter = ACT4Q4_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q4_ActiveFilterCallback;
}

void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT3Intro_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct3IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 42;
    pQuestData->pfStatusFilter = ACT3Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Intro_ActiveFilterCallback;
}

void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 465 || nMessageIndex == 466)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 16, 0);
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return;
    }

    const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
    if (nClassId == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 0);
    }
}

void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

#include "gen/data/Source/D2Game/Quests/a4q1.inc"
