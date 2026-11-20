#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A2Q3_TAINTEDSUN 10
#define QUEST_A2Q4_HORAZONTOME 11
#define QUEST_A3Q1_LAMESENTOME 15
#define OBJMODE_OPENED 2
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define STRCOLOR_DARK_GOLD 4
#define LEVEL_DURIELSLAIR 73
#define LEVEL_DURANCEOFHATELEV1 100
#define LEVEL_GLACIALCAVESLEV1 118
#define LEVEL_ROCKYSUMMIT 120
#define LEVEL_THEWORLDSTONEKEEPLEV1 128
#define OBJECT_DREHYA_START_IN_TOWN 459
#define OBJECT_NIHLATHAK_START_IN_TOWN 461
#define OBJECT_LARZUK_STANDARD 543
#define OBJRGN_WELL_DISTANCE 100
#define OBJRGN_SHRINE_DISTANCE 50
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_NEUTRAL 1
#define UNIT_ALIGNMENT_GOOD 2
#define MONTYPEFLAG_OTHER 1
#define ACT_III 2
#define MONSTER_JERHYN 0xC9
#define MONSTER_ACT2GUARD2 0x14B
#define MONSTER_FETISH11 0x197
#define MONSTATSFLAGINDEX_FLYING 14
#define NUM_QUEST_PLAYER_GUIDS 32
#define LEVEL_FIRST_COUNCIL_LIMIT 108
#define QUEST_LOG_FLAGS 2
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define UNITFLAG_TARGETABLE 0x00000002
struct D2QuestChainStrc;
struct D2QuestInfoStrc;
struct D2ObjectControlStrc;
struct Client;
struct Flags;
struct D2PlayerDataStrc;
struct D2SuperUniquesTxt;
struct D2ObjInitFnStrc;
struct D2NPCMessageStrc;
struct D2NPCMessageTableStrc;
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2QuestTimerStrc;
struct D2ItemsTxt;
struct D2LevelsTxt;
struct D2ObjectRoomCoordStrc;
struct D2MonsterRegionStrc;
struct D2GSPacketSrv29;
struct D2PackedGuidStrc;
struct D2MessageStrc;
struct D2GSPacketSrv27;
struct D2GSPacketSrv5D;
struct D2UnkPlrMsgStrc;
struct D2QuestGUIDStrc;
struct D2MonStatsTxt;
struct D2QuestInitTableStrc;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv89;
struct D2GSPacketSrv91;
struct Obj00545290;
struct Obj005452C0;
struct D2DrlgCoordsStrc;
struct QuestInfo;
struct PlayerData;
struct Packet;
struct D2ObjOperateFnStrc;
struct D2Unk00545D40Rec;


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    unsigned char unk_1C[0x44];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs);

typedef void (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    D2NPCMessageTableStrc* pNPCMessages;
    int nQuestFilter;
    unsigned char unk_E4[0xC];
    QUESTSEQFILTER pfSeqFilter;
    D2QuestDataStrc* pPrev;
};

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};


struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
    unsigned int dwClass;
    unsigned int dwHcIdx;
    char unk0x0C[0x28];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0


struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
    D2SeedStrc pSeed;
    unsigned char unk0x20;
    unsigned char unk_21[0x3];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F380
void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F440
void __fastcall sub_0059A3F0(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059A3F0
void __fastcall sub_005B7310(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2NPCMessageStrc
{
    int nNPCNo;
    unsigned short nStringIndex;
    unsigned short nPad;
    int nMenu;
};

struct D2NPCMessageTableStrc
{
    D2NPCMessageStrc pMessages[16];
    int nMessages;
};

void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu); // 0x006612F0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

typedef int (__stdcall* FARPROC)();

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    int unk0x10;
    int unk0x14;
    int unk0x18;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0



typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

struct D2QuestTimerStrc
{
    QUESTUPDATE pfUpdate;
    D2QuestDataStrc* pQuest;
    unsigned int dwTicks;
    unsigned int dwTimeout;
    D2QuestTimerStrc* pNext;
};


struct D2LevelsTxt
{
    char unk0x00[0x30];
    unsigned char nQuest;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
    int nShrines;
    int nWells;
    int nTrapMonsterId;
    D2CoordStrc wellCoordinates[4];
    D2CoordStrc shrineCoordinates[10];
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
    char unk0x1048[0xC8];
    D2ObjectRoomCoordStrc* pObjectRoomCoord;
};

struct D2MonsterRegionStrc
{
    char unk0x000[0x2C8];
    unsigned int dwUniqueCount;
    unsigned int dwMonSpawnCount;
    char unk0x2D0[0x08];
    unsigned char nQuest;
};

struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4
extern int dword_6FD4DC34; // 0x008846DC
extern const D2UnkPlrMsgStrc stru_6FD30708[]; // 0x007319E8
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_6FC84C70(D2GameStrc* pGame, const char* szMessage, unsigned char nColor); // 0x0054A930
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket); // 0x0053D700
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593CB0
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059D6A0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DB20
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BBFA0
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel); // 0x0058D090
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058E640
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AD80
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AE10
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x00587950
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId); // 0x00573500
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40
void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50


extern unsigned int gdwBitMasks[]; // 0x006CE268
void __fastcall sub_0059B6C0_JerhynSpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6C0
void __fastcall sub_0059B6D0_Act2Guard2SpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6D0
void __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BAC70
void __fastcall sub_005BACF0_GoldenBirdSpawnCheck(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BACF0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C150
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
extern "C" const char gszObjRgnSourceFile[]; // 0x006E0C40
extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    unsigned char unk0x001[37];
};

struct D2GSPacketSrv89
{
    unsigned char nHeader;
    unsigned char nEvent;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __fastcall sub_0053D830_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket); // 0x0053D830
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520
void __fastcall sub_0053DFE0_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket); // 0x0053DFE0
extern D2QuestInitTableStrc gpQuestInitTable_00731510[]; // 0x00731510
int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005456F0
int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom); // 0x0059DFD0
void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BB550
void __fastcall sub_0058CFD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CFD0
void __fastcall sub_00592090_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00592090
void __fastcall sub_00594060_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00594060
void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00588CA0
void __fastcall sub_00589540_RemoveNihlathakFromTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00589540
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A500
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058A730
void __fastcall sub_0058B940_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058B940
void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058C0E0
void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593290
void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005942C0
void __fastcall sub_00594630_QuestGoldDrop(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00594630
void __fastcall sub_005956C0_ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005956C0
void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059B710
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall sub_005B5750(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B5750
void __fastcall sub_005B6710(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B6710
void __fastcall sub_005B85E0_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B85E0
void __fastcall sub_005BCAC0(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BCAC0
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572420

int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572470
void __fastcall sub_0053E060_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket); // 0x0053E060

struct Obj00545290 { unsigned int dwValues[32]; unsigned short wCount80; };

struct Obj005452C0 { unsigned char bUnknown00[0x1C]; unsigned int dwValues1C[32]; unsigned short wCount9C; };

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

struct QuestInfo { char pad[0x20]; unsigned char effect; };

struct Game { char pad[0x6D]; unsigned char difficulty; char pad6e[0x1086]; QuestInfo* quests; };

struct PlayerData { char pad[0x10]; Flags* quests[3]; };

struct Packet { unsigned char header; unsigned char effect; };

extern const char quest_source_file[]; // 0x006E0BE4
PlayerData* __stdcall sub_006221A0(Unit*); // 0x006221A0
Client* __fastcall sub_005531C0(Unit*, const char*, int); // 0x005531C0
void __fastcall sub_0053D670(Client*, unsigned char, unsigned char, int, Flags*, unsigned char); // 0x0053D670
void __fastcall sub_0053DFE0(Client*, Packet*); // 0x0053DFE0

enum { EFFECT_PACKET = 0x89, FLAGS_PACKET = 0x28 };

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};


void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);

struct D2Unk00545D40Rec
{
    int nFirst;
    int nSecond;
    unsigned char nKind;
    unsigned char bActive;
    unsigned char b0A;
    unsigned char b0B;
    char unk0x0C[0x90];
    unsigned short w9C;
    char unk0x9E[0x5A];
};

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);

// 0x00543540
D2PlrIntroStrc* __fastcall sub_00543540_GetPlayerIntro(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
}

// 0x00543560
int __fastcall sub_00543560_GetSuperUniqueHcIdx(int nSuperUnique)
{
    if (nSuperUnique >= 0 && nSuperUnique < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUnique].dwHcIdx;
    }
    return -1;
}

// 0x00543690
D2QuestDataStrc* __fastcall sub_00543690_FindQuestEvent(D2UnitStrc* pUnit, int nQuestId)
{
    for (D2QuestChainStrc* i = pUnit->pQuestEventList; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }

        if (i->pQuestData->nQuestNo == nQuestId)
        {
            return i->pQuestData;
        }
    }

    return 0;
}

// 0x00543640
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x005448B0
void __fastcall OBJECTS_InitFunction18_JerhynPosition(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynStartObject(pQuestData, pOp);
    }
}

// 0x005448E0
void __fastcall OBJECTS_InitFunction19_JerhynPositionEx(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynPalaceObject(pQuestData, pOp);
    }
}

// 0x00544910
void __fastcall OBJECTS_InitFunction20_TaintedAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData)
    {
        sub_0059A3F0(pQuestData, pOp);
        return;
    }

    int nAnimMode = 0;
    if (pOp->pObject)
    {
        nAnimMode = pOp->pObject->dwAnimMode;
    }

    if (nAnimMode != OBJMODE_OPENED)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x00544E30
void __fastcall OBJECTS_InitFunction23_LamEsenTomeStand(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q1_LAMESENTOME);
    D2_ASSERT(pQuestData, 2435);

    sub_005B7310(pQuestData, pOp);
}

// 0x00543790
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex)
{
    D2NPCMessageTableStrc* pTables = pQuest->pNPCMessages;

    for (int i = 0; i < pTables[nIndex].nMessages; ++i)
    {
        if (pTables[nIndex].pMessages[i].nNPCNo == nNPCID)
        {
            int nMenu = pTables[nIndex].pMessages[i].nMenu;
            if (nMenu == 1)
            {
                nMenu = 0;
            }

            TEXT_AddNodeToTextList(pTextControl, pTables[nIndex].pMessages[i].nStringIndex, nMenu);
        }
    }
}

// 0x005438B0
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame)
{
    if (pGame->pQuestControl)
    {
        return &pGame->pQuestControl->pSeed;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 507);
    exit(-1);
}

// 0x00544470
int __stdcall QUESTS_CheckFirstPickedSet(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 1971);

    if (!pGame->pQuestControl)
    {
        return 0;
    }

    return pGame->pQuestControl->bPickedSet;
}

// 0x00544720
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2080);

    QUESTRECORD_SetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}

// 0x00544760
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2092);

    return QUESTRECORD_GetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}

// 0x005439A0
static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs)
{
    for (D2QuestChainStrc* i = pArgs->pTarget->pQuestEventList; i; i = i->pNext)
    {
        if (i->pQuestData->pfCallback[pArgs->nEvent] && (i->pQuestData->bActive == 1 || bForceActive))
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)i->pQuestData->pfCallback[pArgs->nEvent]), 0x23E);
            i->pQuestData->pfCallback[pArgs->nEvent](i->pQuestData, pArgs);
        }
    }
}

void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (!pDefender->pQuestEventList)
    {
        return;
    }
    if (pGame->nGameType == 3 && !pAttacker)
    {
        D2ClientStrc* pClient = sub_00539070_GetClientList(pGame);
        if (pClient)
        {
            pAttacker = CLIENTS_GetPlayerFromClient(pClient, 0);
        }
    }
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 8;
    pArgs.pTarget = pDefender;
    if (pAttacker && pAttacker->dwUnitType == 0)
    {
        pArgs.pPlayer = pAttacker;
    }
    else
    {
        pArgs.pPlayer = 0;
        if (pAttacker && pAttacker->dwUnitType == 1)
        {
            int nOwnerType;
            int nOwnerId;
            AIGENERAL_GetOwnerData(pAttacker, &nOwnerId, &nOwnerType);
            if (nOwnerType == 0)
            {
                pArgs.pPlayer = SUNIT_GetServerUnit(pGame, 0, nOwnerId);
            }
        }
    }
    bool bForceActive = 0;
    if (MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2))
    {
        const int nSuperUniqueId = MONSTERUNIQUE_GetBossHcIdx(pDefender);
        const int nHcIdx = nSuperUniqueId >= 0 && nSuperUniqueId < sgptDataTables->nSuperUniquesTxtRecordCount ? sgptDataTables->pSuperUniquesTxt[nSuperUniqueId].dwHcIdx : -1;
        switch (nHcIdx)
        {
        case 26:
        case 27:
        case 29:
        case 36:
        case 37:
        case 38:
        case 39:
        case 42:
        case 43:
        case 44:
        case 45:
        case 60:
            bForceActive = 1;
            break;
        }
    }
    switch (pDefender->dwClassId)
    {
    case 0xF2:
    case 0xF3:
    case 0x187:
    case 0x220:
        bForceActive = 1;
        break;
    }
    QUESTS_StatusCycler(bForceActive, &pArgs);
}

// 0x00543CE0
void __fastcall sub_00543CE0_QuestStatusEvent0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 0;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543D80
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 4;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543DB0
void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 5;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543DE0
void __fastcall sub_00543DE0_QuestStatusEvent6(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 6;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = 0;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543F10
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks)
{
    D2QuestInfoStrc* pQuestControl = pQuest->pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2_ASSERT(!pQuestControl->bExecuting, 1047);

    D2QuestTimerStrc* pPrevious = pQuestControl->pTimer;
    D2QuestTimerStrc* pQuestTimer = (D2QuestTimerStrc*)sub_0040B430(pQuest->pGame->pMemoryPool, sizeof(D2QuestTimerStrc), gszQuestsSourceFile, 1050, 0);
    pQuestTimer->pNext = pPrevious;
    pQuestTimer->pfUpdate = pfnCallback;
    pQuestTimer->pQuest = pQuest;
    pQuestTimer->dwTicks = nTicks + pQuestControl->dwTick;
    pQuestTimer->dwTimeout = nTicks;
    pQuestControl->pTimer = pQuestTimer;
}

// 0x00544300
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate)
{
    pQuest->fLastState = nIterateState;
    if (bIterate == 1)
    {
        if (pfIterate)
        {
            SUNIT_IterateUnitsOfType(pQuest->pGame, UNIT_PLAYER, pUnit, pfIterate);
            return;
        }

        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1464);
        exit(-1);
    }
}

// 0x00544350
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine)
{
    char szMsg[128];
    pQuestData->fState = nState;
    wsprintfA(szMsg, "changing state to %d\n", nState);
    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pQuestData->pGame, szMsg, STRCOLOR_DARK_GOLD);
    }
}

// 0x00544520
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2QuestInfoStrc* pQuestHead = pGame->pQuestControl;
    D2_ASSERT(pQuestHead->bPickedSet, 2013);

    D2GSPacketSrv29 packet29;
    packet29.nHeader = 0x29;
    QUESTRECORD_CopyRecordToBuffer(pQuestHead->pQuestFlags, packet29.pData, sizeof(packet29.pData), 0);
    D2GAME_PACKETS_SendPacket0x29_6FC3F370(pClient, &packet29);
}

// 0x00544840
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitId)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nUnitId);
    if (!pItem || !ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord)
    {
        return;
    }

    if (pItemsTxtRecord->dwCode == ' dkb')
    {
        ACT1Q4_SendStoneOrderToClient(pGame, pUnit);
    }
    else if (pItemsTxtRecord->dwCode == ' srt')
    {
        ACT2Q6_SendTombIdToClient(pGame, pUnit);
    }
}

// 0x005456A0
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 3274);

    D2GSPacketSrv27 packet27;
    packet27.nHeader = 0x27;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    memcpy(&packet27.dwUnitGUID, &nUnitGUID, sizeof(nUnitGUID));
    packet27.nUnitType = UNIT_OBJECT;
    packet27.pMessages[0].nMenu = 0;
    packet27.pMessages[0].nStringId = nMessage;
    packet27.nCount = 1;
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
}

// 0x00545920
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nLevelId == 0 || DRLG_GetActNoFromLevelId(nLevelId) < nAct)
        {
            return;
        }
    }

    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nFlags = 0;
    packet5D.nQuestId = nQuestId;
    packet5D.nState = 12;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 3458);
    sub_6FC3F380(pClient, &packet5D);
}

// 0x00545B80
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nTargetLevel)
{
    switch (nTargetLevel)
    {
    case LEVEL_DURIELSLAIR:
        return ACT2Q6_IsDurielsLairClosed(pGame, pPlayer);

    case LEVEL_DURANCEOFHATELEV1:
        return ACT3Q5_IsDuranceOfHateClosed(pGame, pPlayer);

    case LEVEL_GLACIALCAVESLEV1:
    case LEVEL_THEWORLDSTONEKEEPLEV1:
        if (nSourceLevel != LEVEL_ROCKYSUMMIT)
        {
            return 0;
        }
        return ACT5Q5_IsArreatSummitClosed(pGame, pPlayer, nTargetLevel);

    case LEVEL_THEWORLDSTONECHAMBER:
        return ACT5Q6_IsWorldStoneChamberClosed(pGame, pPlayer);

    default:
        return 0;
    }
}

// 0x00545C30
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex)
{
    int nClassId = DATATBLS_MapSuperUniqueId(nType, nIndex);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), pPosition->nX, pPosition->nY);
    if (pRoom)
    {
        return D2GAME_SpawnPresetMonster_6FC66560(pGame, pRoom, nClassId, pPosition->nX, pPosition->nY, 1);
    }

    return 0;
}

// 0x00545C90
void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_OBJECT)
    {
        return;
    }

    switch (pUnit->dwClassId)
    {
    case OBJECT_DREHYA_START_IN_TOWN:
        ACT5Q3_ChangeDrehyaMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_NIHLATHAK_START_IN_TOWN:
        ACT5Q3_ChangeNihlathakMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_LARZUK_STANDARD:
        ACT5Q1_ChangeLarzukMapAI(pGame, pUnit, pMapAI);
        break;

    default:
        break;
    }
}

// 0x00545CD0
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return;
    }

    const unsigned char nQuestId = DATATBLS_GetLevelsTxtRecord(nLevelId)->nQuest;
    if (!nQuestId)
    {
        return;
    }

    if (bDebug)
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 0)
        {
            return;
        }
    }
    else
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 1)
        {
            return;
        }
    }

    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pGame, "Error attaching to unit", STRCOLOR_DARK_GOLD);
    }
}

// 0x00547170
void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = (D2ObjectRoomCoordStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ObjectRoomCoordStrc), ".\\OBJECTS\\objrgn.cpp", 375, 0);

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    pObjectRoomCoord->nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    pObjectRoomCoord->nY = nY;

    pObjectRoomCoord->pRoom = pRoom;
    pObjectRoomCoord->pNext = pObjectControl->pObjectRoomCoord;
    pObjectControl->pObjectRoomCoord = pObjectRoomCoord;
}

// 0x005473A0
bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nWells; ++i)
    {
        int nDistance = pObjectRegion->wellCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->wellCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

// 0x00547430
bool __fastcall OBJRGN_CanSpawnShrine(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nShrines; ++i)
    {
        int nDistance = pObjectRegion->shrineCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->shrineCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

// 0x00547DD0
void __fastcall sub_6FC681C0(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit, int nPreviousAlignment, int nNewAlignment)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && !SUNIT_IsDead(pUnit) && !MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (pMonsterRegion && !pMonsterRegion->nQuest && nPreviousAlignment != nNewAlignment)
        {
            if (nPreviousAlignment == UNIT_ALIGNMENT_EVIL && (nNewAlignment == UNIT_ALIGNMENT_NEUTRAL || nNewAlignment == UNIT_ALIGNMENT_GOOD))
            {
                --pMonsterRegion->dwMonSpawnCount;
            }

            if (nNewAlignment == UNIT_ALIGNMENT_EVIL && nPreviousAlignment != UNIT_ALIGNMENT_UNASSIGNED)
            {
                ++pMonsterRegion->dwMonSpawnCount;
            }
        }
    }
}

// 0x00547ED0
void __fastcall sub_6FC682C0(D2MonsterRegionStrc** ppMonRegion, int nLevelId1, int nLevelId2, int nAlignment, int bDead, int a6, D2UnitStrc* pUnit)
{
    D2MonsterRegionStrc* pMonsterRegion1 = ppMonRegion[nLevelId1];
    D2MonsterRegionStrc* pMonsterRegion2 = ppMonRegion[nLevelId2];
    if (pUnit)
    {
        if (pMonsterRegion2 != pMonsterRegion1)
        {
            MONSTER_SetLevelId(pUnit, nLevelId1);
        }

        if (!a6 && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion2->dwMonSpawnCount;

            if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_OTHER))
            {
                --pMonsterRegion2->dwUniqueCount;
            }
        }
    }
    else
    {
        if (!a6 && !bDead && nAlignment == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion1->dwMonSpawnCount;
        }
    }
}

// 0x005484B0
void __fastcall sub_6FC82270(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    PlrMsgFunc pfSendMode = stru_6FD30708[nAnimMode].field_0;
    if (pfSendMode)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pfSendMode), 328);
        pfSendMode(pGame, pUnit, pClient, nAnimMode);
    }
}

// 0x00548520
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 339);
    D2_ASSERT(pClient, 340);

    if (pUnit == pPlayer)
    {
        D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(pClient, nStat, nNewValue);
    }
    else
    {
        sub_6FC3D830(pClient, 0x20, !pUnit ? -1 : pUnit->dwUnitId, nStat, nNewValue);
    }
}

// 0x005490E0
int __fastcall sub_005490E0_CheckCursorItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1123);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_ONCURSOR && INVENTORY_GetCursorItem(pUnit->pInventory) == pItem)
    {
        return 0;
    }

    return 1;
}

// 0x00549150
int __fastcall sub_00549150_CheckStoredItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1146);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_STORED && INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return 1;
}

// 0x005491B0
int __fastcall sub_005491B0_CheckStoredOrEquippedItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1169);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_STORED && pItem->dwAnimMode != IMODE_EQUIP)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}

// 0x005492F0
int __fastcall sub_005492F0_CheckBeltItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1256);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_INBELT)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}

// build: context QUESTS_GetQuestData_Inlined
static D2QuestDataStrc* QUESTS_GetQuestData_Inlined(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int QUESTS_QuickCheckPlayerGUID_Inlined(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00544070
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine)
{
    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pGame, szMessage, STRCOLOR_DARK_GOLD);
    }
}

// 0x005447A0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, D2UnitStrc* pWarriv, int nXpos, int nYpos, int nWarrivID)
{
    if (nWarrivID >= 0 && nWarrivID < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nWarrivID)
        {
        case MONSTER_JERHYN:
            sub_0059B6C0_JerhynSpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        case MONSTER_ACT2GUARD2:
            sub_0059B6D0_Act2Guard2SpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        }
    }
}

// 0x00544E80
void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inlined(pGame, QUEST_A3Q4_GOLDENBIRD);

    if (!pUnit)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pQuestData && pQuestData->bNotIntro == 1 && pUnit->dwClassId != MONSTER_FETISH11
        && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_FLYING >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_FLYING & 7]))
    {
        ACT3Q4_UnitIterate_SetGoldenBirdBoss(pQuestData, pUnit);
    }
}

// 0x00544F20
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestChainStrc* pQuestChain = pUnit->pQuestEventList;
    if (!pQuestChain)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = pQuestChain->pQuestData;
    if (pQuestData->nQuestFilter != 20 || pQuestData->bActive != 1)
    {
        return;
    }

    sub_005BACF0_GoldenBirdSpawnCheck(pQuestData, pUnit);
}

// 0x00545200
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID)
{
    if (pQuestGUID->nPlayerCount >= NUM_QUEST_PLAYER_GUIDS)
    {
        return;
    }

    if (QUESTS_QuickCheckPlayerGUID_Inlined(pQuestGUID, dwGUID))
    {
        return;
    }

    pQuestGUID->nPlayerGUIDs[pQuestGUID->nPlayerCount] = dwGUID;
    ++pQuestGUID->nPlayerCount;
}

// 0x00545240
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            if (i != pGUIDs->nPlayerCount - 1)
            {
                pGUIDs->nPlayerGUIDs[i] = pGUIDs->nPlayerGUIDs[pGUIDs->nPlayerCount - 1];
            }

            --pGUIDs->nPlayerCount;
            return 1;
        }
    }

    return 0;
}

// 0x005440A0
static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0x534);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;
    switch (nAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, nFlags);
        D2GAME_RemoveItem_6FC471F0(pGame, pPlayer, pItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pItem);
        int a5;
        sub_6FC45B30(pGame, pPlayer, nBodyLoc, 1, &a5);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        break;
    }
}

// 0x00544160
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode)
{
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, dwCode);
    if (pItem)
    {
        QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
    }
}

int dword_6FD4DC34; // 0x008846DC

// 0x00544410
static void sub_00544410_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, nChainNo);
    D2_ASSERT(pQuest, 0x5F3);
    pQuest->bNotIntro = 0;
    pQuest->bActive = 0;
    pQuest->fLastState = 0;
}

// build: context QUESTS_SequenceCycler
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl->bPickedSet)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        int anActQuests[5];
        memset(anActQuests, 0, sizeof(anActQuests));
        pQuestControl->bPickedSet = 1;
        if (!bGameEnter)
        {
            if (byte_0073150C)
            {
                for (int i = 0; i < gnQuestInitTableCount_00731888; ++i)
                {
                    D2_ASSERT(gpQuestInitTable_00731510[i].nAct < 5, 0x637);
                    if (!gpQuestInitTable_00731510[i].bNoSetState
                        && (QUESTRECORD_GetQuestState(pQuestFlags, gpQuestInitTable_00731510[i].nQuestNo, 0)
                            || QUESTRECORD_GetQuestState(pQuestFlags, gpQuestInitTable_00731510[i].nQuestNo, 15)))
                    {
                        sub_00544410_ClearQuestIntroState(pGame, gpQuestInitTable_00731510[i].nChainNo);
                        ++anActQuests[gpQuestInitTable_00731510[i].nAct];
                        QUESTRECORD_SetQuestState(pQuestControl->pQuestFlags, gpQuestInitTable_00731510[i].nQuestNo, 15);
                    }
                }
            }
            for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
            {
                if (pQuest->pfCallback[13])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfCallback[13]), 0x640);
                    D2QuestArgStrc pArgs;
                    pArgs.pGame = pGame;
                    pArgs.pPlayer = pPlayer;
                    pArgs.nEvent = 13;
                    pQuest->pfCallback[13](pQuest, &pArgs);
                }
            }
        }
        D2QuestDataStrc* pQuestSeq0 = QUESTS_GetQuestData(pGame, 1);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq0->pfSeqFilter), 0x64D);
        pQuestSeq0->pfSeqFilter(pQuestSeq0);
        D2QuestDataStrc* pQuestSeq1 = QUESTS_GetQuestData(pGame, 8);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq1->pfSeqFilter), 0x650);
        pQuestSeq1->pfSeqFilter(pQuestSeq1);
        D2QuestDataStrc* pQuestSeq2 = QUESTS_GetQuestData(pGame, 18);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq2->pfSeqFilter), 0x653);
        pQuestSeq2->pfSeqFilter(pQuestSeq2);
        D2QuestDataStrc* pQuestSeq3 = QUESTS_GetQuestData(pGame, 22);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq3->pfSeqFilter), 0x656);
        pQuestSeq3->pfSeqFilter(pQuestSeq3);
        D2QuestDataStrc* pQuestSeq4 = QUESTS_GetQuestData(pGame, 31);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq4->pfSeqFilter), 0x65A);
        pQuestSeq4->pfSeqFilter(pQuestSeq4);
    }
    else
    {
        for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
        {
            if (pQuest->pfCallback[14])
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfCallback[14]), 0x666);
                D2QuestArgStrc pArgs;
                pArgs.pGame = pGame;
                pArgs.nEvent = 14;
                pArgs.pPlayer = pPlayer;
                pQuest->pfCallback[14](pQuest, &pArgs);
            }
        }
    }

    D2GSPacketSrv5E packet5E;
    packet5E.nHeader = 0x5E;
    for (int i = 0; i < gnQuestInitTableCount_00731888; ++i)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, gpQuestInitTable_00731510[i].nChainNo);
        D2_ASSERT(pQuest, 0x67C);
        packet5E.unk0x001[i] = pQuest->bNotIntro;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0x681);
    sub_0053D830_SendPacket0x5E(pClient, &packet5E);
    QUESTS_UpdatePlayerFlags(pGame, pPlayer);
    QUESTS_SendCurrentFlags(pGame, pClient);

    D2QuestDataStrc* pQuestData1 = QUESTS_GetQuestData(pGame, 1);
    if (pQuestData1 && ACT1Q1_CanClientFXBeTriggered(pQuestData1))
    {
        D2GSPacketSrv89 packet89;
        packet89.nHeader = 0x89;
        packet89.nEvent = 0;
        sub_0053DFE0_SendPacket0x89(pClient, &packet89);
    }
}

// 0x005444B0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId)
{
    D2_ASSERT(pGame, 1987);
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 1989);

    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nQuestId)
        {
            return pQuestData->bNotIntro == 1;
        }
    }

    return 1;
}

// 0x005455B0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(UnitGetClient(pUnit, gszQuestsSourceFile, 3239), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
}

// 0x00545760
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2)
{
    pGame->pQuestControl->unk0x20 = a2;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, QUESTS_FXIterate);
}

// 0x00545830
int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom)
{
    if (nLevel == LEVEL_DURIELSLAIR)
    {
        return ACT2Q6_ActivateTomb(pGame, pCoord, ppRoom);
    }

    return 0;
}

// 0x005458E0
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, unsigned char nQuestId)
{
    D2GSPacketSrv5D packet5D = {};

    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = nQuestId;
    packet5D.nFlags = QUEST_LOG_FLAGS;

    D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, 3433);
    sub_6FC3F380(pClient, &packet5D);
}

// 0x00545990
void __stdcall sub_00545990(int nUnused)
{
}

// 0x00545B50
void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) < LEVEL_FIRST_COUNCIL_LIMIT)
    {
        ACT3Q5_SpawnCouncil(pGame, pUnit);
    }
    else
    {
        sub_0058CFD0(pGame, pUnit);
    }
}

static __forceinline D2QuestDataStrc* QUESTS_FindQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x00544950
void __fastcall sub_00544950_ObjInitMalus(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_FindQuestData(pOp->pGame, 3);
    if (pQuestData)
    {
        sub_00592090_ACT1Q3_InitMalusObject(pQuestData, pOp);
        return;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode != 2)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x00544990
void __fastcall sub_00544990_ObjInitCainGibbet(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_FindQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        sub_00594060_InitCainGibbet(pQuestData, pOp);
        return;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode != 2)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x005449D0
void __cdecl sub_005449D0_ClearFlag()
{
    byte_0073150C = 0;
}

#include "gen/data/Source/D2Game/Quests/QUESTS.inc"

// 0x005449E0
void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    switch (nClassId)
    {
    case 131:
    {
        if (pRoom)
        {
            if (pUnit && pUnit->dwAnimMode == 1)
            {
                UNITS_ChangeAnimMode(pUnit, 2);
            }

            switch (DUNGEON_GetLevelIdFromRoom(pRoom))
            {
            case 108:
                sub_005B5750(pGame, pUnit);
                break;

            case 76:
                sub_6FC68D70(pGame, pUnit, 301, 1, -1, 0);
                break;
            }
        }
        break;
    }
    case 122:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
        if (pQuestData)
        {
            ACT2Q4_InitializeHaremBlockerObject(pQuestData, pUnit);
        }
        break;
    }
    case 26:
    {
        ACT1Q4_SpawnCainInTristram(pGame, pUnit);
        break;
    }
    case 189:
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (!DRLG_GetActNoFromLevelId(nLevelId))
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
            if (pQuestData)
            {
                ACT1Q4_UpdatePortalInTown(pQuestData, pUnit);
            }
        }
        else if (nLevelId != 109 && nLevelId < 113)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
            if (pQuestData)
            {
                ACT5Q2_UpdatePortalMode(pQuestData, pUnit);
            }
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
            if (pQuestData)
            {
                ACT5Q3_UpdateDrehyaPortalMode(pQuestData, pUnit);
            }
        }
        break;
    }
    case 341:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
        if (pQuestData)
        {
            sub_005BCAC0(pQuestData, pUnit);
        }
        break;
    }
    case 268:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
        if (pQuestData)
        {
            sub_00594630_QuestGoldDrop(pQuestData, pUnit);
        }
        break;
    }
    case 367:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
        if (pQuestData)
        {
            sub_005B85E0_OpenSewerStairs(pQuestData, pUnit);
        }
        break;
    }
    case 376:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 24);
        if (pQuestData)
        {
            sub_005B6710(pQuestData, pUnit);
        }
        break;
    }
    case 474:
    case 475:
    case 476:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 35);
        if (pQuestData)
        {
            ACT5Q5_SpawnAncientMonsters(pQuestData, pUnit);
        }
        break;
    }
    case 461:
    {
        sub_00589540_RemoveNihlathakFromTown(pGame, pUnit);
        break;
    }
    case 459:
    {
        sub_0058B940_RetryDrehyaPortal(pGame, pUnit);
        break;
    }
    case 460:
    {
        ACT5Q3_SpawnFrozenDrehya(pGame, pUnit);
        break;
    }
    case 371:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (pQuestData)
        {
            sub_005956C0_ACT1Q5_SpawnChestMissilesAndEvent(pQuestData, pUnit);
        }
        break;
    }
    }
}

// 0x00544F60
static void __stdcall QUESTS_SetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, const int* pNPCs, int nNPCs)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    for (int i = 0; i < nNPCs; ++i)
    {
        PLRINTRO_SetNpcIntroFlag(pPlayerIntro, pNPCs[i]);
    }
}

void __fastcall sub_K10_EmitSetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    static const int aNpcs[2] = { 1, 2 };
    QUESTS_SetIntroFlags(pGame, pPlayer, aNpcs, 2);
}

// 0x00544FA0
static void sub_00544FA0_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 6; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct1_NPCIds_007318B0[i]);
        break;
    }
    case 1:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 11; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct2_NPCIds_007318C8[i]);
        break;
    }
    case 2:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct3_NPCIds_007318F4[i]);
        break;
    }
    case 4:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct5_NPCIds_00731910[i]);
        break;
    }
    }
}

void sub_A04_Emit_005467E0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 1);
    sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 2);
}

// 0x00545090
static int __stdcall sub_00545090_FillNpcIntroFlags(D2PlrIntroStrc* pIntroFlags, const int* pNpcIds, int nCount, D2GSPacketSrv91* pPacket)
{
    int bUpdate = 0;
    memset(pPacket->pNPCFlags, -1, sizeof(pPacket->pNPCFlags));
    int nFound = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (PLRINTRO_GetNpcIntroFlag(pIntroFlags, pNpcIds[i]))
        {
            pPacket->pNPCFlags[nFound] = (unsigned short)pNpcIds[i];
            ++nFound;
            bUpdate = 1;
        }
    }
    return bUpdate;
}

// 0x00545100
void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    D2GSPacketSrv91 packet91;
    D2PlrIntroStrc* pIntroFlags = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    int bUpdate;
    switch (nAct)
    {
    case 0:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct1_NPCIds_007318B0, 6, &packet91);
        break;
    case 1:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct2_NPCIds_007318C8, 11, &packet91);
        break;
    case 2:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct3_NPCIds_007318F4, 7, &packet91);
        break;
    case 4:
        bUpdate = sub_00545090_FillNpcIntroFlags(pIntroFlags, gpAct5_NPCIds_00731910, 7, &packet91);
        break;
    default:
        return;
    }
    if (bUpdate)
    {
        packet91.nHeader = 0x91;
        packet91.nAct = nAct;
        sub_0053E060_SendPacket0x91(UnitGetClient(pUnit, gszQuestsSourceFile, 0xAB7), &packet91);
    }
}

// 0x00545290
extern "C" __declspec(dllexport) int __fastcall sub_00545290(Obj00545290* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount80;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}

// 0x005452C0
extern "C" __declspec(dllexport) int __fastcall sub_005452C0(Obj005452C0* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount9C;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues1C[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}

// 0x005452F0
int __fastcall sub_005452F0_GetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs)
{
    return pGUIDs->nPlayerCount;
}

// 0x005454E0
void __fastcall sub_005454E0_RemoveItemFromRoom(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    UNITS_FreeCollisionPath(pItem);
    UNITROOM_RemoveUnitFromRoom(pItem);
    if (pItem)
        pItem->dwFlags &= ~2;
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

// 0x00545FA0
void __fastcall sub_00545FA0_RemoveTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfUpdate)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;

    D2_ASSERT(!pQuestControl->bExecuting, 1068);

    D2QuestTimerStrc* pPrev = 0;
    for (D2QuestTimerStrc* pTimer = pQuestControl->pTimer; pTimer; pTimer = pTimer->pNext)
    {
        if (pTimer->pfUpdate == pfUpdate && pTimer->pQuest == pQuest)
        {
            if (!pPrev)
                pQuestControl->pTimer = pTimer->pNext;
            else
                pPrev->pNext = pTimer->pNext;
            FOG_FreeServerMemory(pQuest->pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 1086, 0);
            return;
        }
        pPrev = pTimer;
    }

    if (dword_6FD4DC34)
        sub_6FC84C70(pGame, "Error in timer usage", 4);
}

// 0x00545310
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg)
{
    if (pQuest->tPlayerGUIDs.nPlayerCount > 0)
    {
        QUESTS_FastRemovePlayerGUID(&pQuest->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// 0x00545340
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius)
{
    D2CoordStrc tCenter;
    tCenter.nX = pCoord->nX - (nSize >> 1);
    tCenter.nY = pCoord->nY - (nSize >> 1);

    D2CoordStrc tPos;
    tPos.nX = tCenter.nX;

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    for (int j = 1; j < nRadius; ++j)
    {
        const int i = -j;
        for (int y = j; y > i; y -= 2)
        {
            tPos.nY = y + tCenter.nY;

            D2ActiveRoomStrc* pRoom1 = pRoom;
            if (tPos.nY < drlgCoords.nSubtileY || tPos.nY >= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight)
            {
                pRoom1 = D2GAME_GetRoom_6FC52070(pRoom, tPos.nX, tPos.nY);
            }

            if (pRoom1)
            {
                for (int x = i; x < j; x += 2)
                {
                    D2ActiveRoomStrc* pRoom2 = pRoom1;
                    DUNGEON_GetRoomCoordinates(pRoom2, &drlgCoords);

                    tPos.nX = x + tCenter.nX;

                    if (tPos.nX < drlgCoords.nSubtileX || tPos.nY >= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                    {
                        pRoom2 = D2GAME_GetRoom_6FC52070(pRoom1, tPos.nX, tPos.nY);
                    }

                    if (pRoom2 && !COLLISION_CheckMaskWithSizeXY(pRoom2, tPos.nX, tPos.nY, 2 * nSize + 1, 2 * nSize + 1, fCollision)
                        && (unsigned int)tPos.nX >= (unsigned int)drlgCoords.nSubtileX && (unsigned int)tPos.nX < (unsigned int)(drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                        && (unsigned int)tPos.nY >= (unsigned int)drlgCoords.nSubtileY && (unsigned int)tPos.nY < (unsigned int)(drlgCoords.nSubtileY + drlgCoords.nSubtileHeight))
                    {
                        pCoord->nX = (nSize >> 1) + tPos.nX;
                        pCoord->nY = (nSize >> 1) + tPos.nY;
                        *ppRoom = D2GAME_GetRoom_6FC52070(pRoom, pCoord->nX, pCoord->nY);
                        return;
                    }
                }
            }
        }
    }

    *ppRoom = 0;
}

// 0x00545530
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pArgs->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED)
        && pQuest->tPlayerGUIDs.nPlayerCount > 0)
    {
        QUESTS_FastRemovePlayerGUID(&pQuest->tPlayerGUIDs, !pArgs->pPlayer ? -1 : pArgs->pPlayer->dwUnitId);
    }
}

// 0x005455F0
void __fastcall QUESTS_GUIDUpdate(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuest, int nSoundCMD)
{
    for (int i = 0; i < pQuestGUID->nPlayerCount; ++i)
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pQuestGUID->nPlayerGUIDs[i]);
        if (pUnit)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, nQuest, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, nQuest, QFLAG_REWARDPENDING) != 1)
            {
                QUESTRECORD_SetQuestState(pQuestFlags, nQuest, QFLAG_PRIMARYGOALDONE);
                QUESTRECORD_SetQuestState(pQuestFlags, nQuest, QFLAG_REWARDPENDING);

                if (nSoundCMD)
                {
                    SUNIT_AttachSound(pUnit, nSoundCMD, pUnit);
                }
            }
        }
    }
}

// 0x005456F0
int __fastcall sub_005456F0(Game* game, Unit* unit, void* unused)
{
    Packet packet;
    packet.header = EFFECT_PACKET;
    packet.effect = game->quests->effect;
    Flags* flags = sub_006221A0(unit)->quests[game->difficulty];
    sub_0053D670(sub_005531C0(unit, quest_source_file, 3239), FLAGS_PACKET, 6, 0, flags, 0);
    sub_0053DFE0(sub_005531C0(unit, quest_source_file, 3342), &packet);
    return 0;
}

// 0x00545850
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp)
{
    int bCanOperate = 1;
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        bCanOperate = 0;
    }

    if (bCanOperate)
    {
        D2CoordStrc tCoords;
        UNITS_GetCoords(pOp->pObject, &tCoords);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        if (pObjectsTxtRecord->nMode[1])
        {
            UNITS_ChangeAnimMode(pOp->pObject, 1);
            sub_005417D0_DirectDated(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
        return 1;
    }

    return 0;
}

// 0x00545D40
static void __stdcall sub_00545D40_InitRecord(D2Unk00545D40Rec* pRec, int nSecond, int nFirst, unsigned char nKind)
{
    memset(pRec, 0, sizeof(D2Unk00545D40Rec));
    pRec->nFirst = nFirst;
    pRec->nSecond = nSecond;
    pRec->b0A = 0;
    pRec->b0B = 0;
    pRec->bActive = 1;
    pRec->nKind = nKind;
    pRec->w9C = 0;
}

void __fastcall sub_K10_EmitInitRecord(D2Unk00545D40Rec* pRec, int n)
{
    sub_00545D40_InitRecord(pRec, n, n + 1, 2);
}
