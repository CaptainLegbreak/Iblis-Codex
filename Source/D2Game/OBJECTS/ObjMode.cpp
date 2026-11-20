#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define OBJMODE_OPENED 2
#define EVENTTYPE_FREEHOVER 6
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAG_HASTXTMSG 0x00000100
#define UNIT_OBJECT 2
#define UNITFLAGEX_TELEPORTED 0x10000
#define UNITFLAG_TARGETABLE 0x00000002
#define MONSTER_TRAP_FIREBOLT 0x146
#define MONSTER_TRAP_POISONCLOUD 0x149
#define MONSTER_TRAP_LIGHTNING 0x14A
#define MONSTER_TRAP_NOVA 0x171
#define ITEMTYPE_GEM 20
#define OBJMODE_SPECIAL1 3
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_TILE 5
#define PLRMODE_DEAD 17
#define MONMODE_DEAD 12
#define STAT_STAMINA 10
#define STATE_FREEZE 1
#define STATE_POISON 2
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_PERIODICSTATS 9
#define ITEMQUAL_NORMAL 2

struct D2ObjectControlStrc;
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2ObjOperateFnStrc;
struct D2ObjectDataStrc;
struct D2DrlgCoordsStrc;
struct D2ContextDataStrc;
struct D2ContextStrc;
struct D2MonStats2Txt;
struct D2GSPacketSrv58;
struct D2PlayerDataStrc;
struct D2ItemsTxt;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ShrineTableStrc;
struct D2CurseStrc;
struct D2SkillContext00583BF0Strc;
struct D2Event00583BF0Strc;
struct D2EventState00583BF0Strc;
struct D2TimerArg2Strc;
struct D2ObeliskPowerUpStrc;
struct D2PortalFlags00585580Strc;
struct D2ObjectsTxt;
struct D2UnitStrc;
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2CoordStrc;
struct D2ItemDropStrc;
struct D2DataTablesStrc;
struct D2ShrinesTxt;
struct D2TimerArgStrc;


struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
    unsigned short unk0x06;
    void* pShrineTxt;
    int dwOperateGUID;
};




struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

typedef int(__stdcall* FARPROC)();

typedef void(__fastcall* ObjTrapHandlerFunction)(D2GameStrc* pGame, D2UnitStrc* pObject);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern ObjTrapHandlerFunction gpObjectTrapHandlerTable_00732CEC[10]; // 0x00732CEC
extern int gnObjectTrapHandlers_00732D14; // 0x00732D14
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit); // 0x00621B00
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005449E0


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

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

struct D2ContextDataStrc { unsigned char padding[16]; unsigned int state; };

struct D2ContextStrc { int unknown; D2ContextDataStrc* data; };

int __fastcall sub_00581F60_HandleState(D2ContextStrc* context, void* argument); // 0x00581F60


int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit); // 0x0055B7E0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20

#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
};

#pragma pack(pop)

void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

struct D2PlayerDataStrc
{
    char szName[0x10];
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
extern "C" char* __cdecl _strrev(char* szString); // 0x00687860


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2ShrinesTxt
{
    unsigned char nCode;
    char unk0x01[0x03];
    int dwArg0;
    int dwArg1;
    int dwDurationInFrames;
};


D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pLastItem); // 0x0063CD80
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nCell); // 0x00628320
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
__declspec(noinline) static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer);


int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __stdcall UNITFINDS_GetNearestTestedUnit(D2UnitStrc* pUnit, int nX, int nY, int nSize, int (__fastcall* pfnUnitTest)(D2UnitStrc*, D2UnitStrc*)); // 0x0065A800
int __fastcall sub_6FC76F60(D2UnitStrc* pMonster, D2UnitStrc* pUnit1); // 0x00582750
void __fastcall sub_005A4940_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4940



typedef void(__fastcall* ObjShrineFunction)(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2ShrineTableStrc
{
    ObjShrineFunction pfShrineCallback;
    int unk0x04;
    int unk0x08;
};

extern const D2ShrineTableStrc gpShrineTable_006E1850[]; // 0x006E1850
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
D2StatListStrc* __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback); // 0x00582800
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583A40
static __declspec(noinline) int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit); // 0x00583840

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    void* pStateRemoveCallback;
};

struct D2SkillContext00583BF0Strc
{
    unsigned char unk_00[4];
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
};

struct D2Event00583BF0Strc
{
    unsigned char nType;
    unsigned char unk_01[0x0B];
    int nDuration;
};

struct D2EventState00583BF0Strc
{
    int nState;
    int unk_04[2];
};

extern D2EventState00583BF0Strc gaEventStates_006E1858[]; // 0x006E1858
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit); // 0x0056DE40
void __fastcall sub_6FC77C10(); // 0x00583BD0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp); // 0x00584330

enum
{
    OBJMODE_NEUTRAL = 0,
    OBJMODE_OPERATING = 1,
    EVENTTYPE_ENDANIM = 1,
    LEVEL_PALACECELLARLEV3 = 54,
    LEVEL_ARCANESANCTUARY = 74,
    ARCANE_TILECALC = 11,
};

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId); // 0x0059BAF0

struct D2TimerArg2Strc
{
    int nUnitGUID;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    int dwUnitId;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

typedef int (__fastcall* ObjOperateFunction)(D2ObjOperateFnStrc* pOp, int nOperate);

extern ObjOperateFunction gpObjOperateFnTable_00732D18[]; // 0x00732D18
int __fastcall OBJECTS_OperateFunction23_Waypoint(D2ObjOperateFnStrc* pOp, int nOperate); // 0x00584E30
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00547170
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, int* pWaypointNo); // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, int nWaypointNo); // 0x00660E50

typedef int(__fastcall* ObeliskPowerUpFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);

struct D2ObeliskPowerUpStrc
{
    ObeliskPowerUpFunction pPowerUpCallback;
    unsigned int nChance;
    int nValue;
};

extern D2ObeliskPowerUpStrc gaObeliskPowerUps_00732EB0[21]; // 0x00732EB0

struct D2PortalFlags00585580Strc
{
    unsigned char nFlags;
};

D2UnitStrc* __fastcall sub_00553720_GetPortalPair(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553720
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, unsigned char nDestLevel, int nSourceLevel); // 0x0056CF40
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlags00585580Strc tFlags); // 0x00622300
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag); // 0x00622350

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord); // 0x00552AA0
unsigned char __fastcall sub_00552AB0(); // 0x00552AB0
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit); // 0x00578C20
void __fastcall OBJMODE_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pUnit2, void* pUnitHealed); // 0x005856A0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nTCIndex); // 0x00654E80
extern const int gnChestActLevelIds_006E1988[10]; // 0x006E1988

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90
void __fastcall sub_00583BF0_ApplyEventCurse(D2SkillContext00583BF0Strc* pContext, D2Event00583BF0Strc* pEvent);
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

#include "gen/data/Source/D2Game/OBJECTS/ObjMode.inc"

// 0x0045D0A0
void __fastcall sub_0045D0A0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0B0
void __fastcall sub_0045D0B0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0C0
void __fastcall sub_0045D0C0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0D0
void __fastcall sub_0045D0D0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0E0
void __fastcall sub_0045D0E0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D130
void __fastcall sub_0045D130_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D140
void __fastcall sub_0045D140_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D150
void __fastcall sub_0045D150_PacketNop(const unsigned char* pPacket)
{
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x00581490
void __fastcall sub_6FC74AC0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && (unsigned short)pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pObject->dwClassId);
        if (pObjectsTxtRecord->nMode[2])
        {
            pObject->dwAnimMode = OBJMODE_OPENED;
            if (!pObjectsTxtRecord->nHasCollision[2])
            {
                UNITS_FreeCollisionPath(pObject);
            }
        }
    }
}

// 0x005814D0
void __fastcall sub_6FC74B00(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (UNITS_IsShrine(pObject))
    {
        UNITROOM_RefreshUnit(pObject);
        SetUnitFlagMask(pObject, UNITFLAG_DOUPDATE);
        UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
        pObject->pObjectData->dwOperateGUID = 0;
    }
}

// 0x00581620
void __fastcall sub_6FC74CA0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (!pObject)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pObject->pHoverText;
    if (pHoverText)
    {
        const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
        if (nTimeout <= pGame->dwGameFrame)
        {
            CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
            pObject->pHoverText = 0;
            UNITROOM_RefreshUnit(pObject);
            pObject->dwFlags |= UNITFLAG_HASTXTMSG;
        }
        else
        {
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_FREEHOVER, nTimeout, 0, 0);
        }
    }
}

// 0x005817A0
void __fastcall sub_6FC74DF0(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject));
    const unsigned char nTrapType = pObject->pObjectData->InteractType & 0x7F;
    if (nTrapType >= gnObjectTrapHandlers_00732D14)
    {
        return;
    }

    if (nTrapType == 8)
    {
        if (nLevelId >= 75)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x161);
            gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
            return;
        }
    }
    else if (nTrapType == 3)
    {
        if (nLevelId < 40 && nLevelId != 25)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x16C);
            gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
            return;
        }
    }
    else if ((nTrapType == 1 || nTrapType == 4) && nLevelId < 40)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[2]), 0x176);
        gpObjectTrapHandlerTable_00732CEC[2](pGame, pObject);
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gpObjectTrapHandlerTable_00732CEC[nTrapType]), 0x17B);
    gpObjectTrapHandlerTable_00732CEC[nTrapType](pGame, pObject);
}

// 0x00581A10
void __fastcall sub_00581A10_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    QUESTS_ObjectEvents(pGame, pObject);
}

// 0x00581B50
static void sub_00581B50_TeleportToUnit(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, D2UnitStrc* pPlayer)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    if (COLLISION_GetFreeCoordinates(pRoom, &tCoord, 3, 0x1C09, 0) && sub_6FCBDFE0(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pRoom, tCoord.nX, tCoord.nY, 0, 0))
    {
        D2DrlgCoordsStrc tRoomCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 865), DUNGEON_GetLevelIdFromRoom(pRoom), tRoomCoords.nTileXPos, tRoomCoords.nTileYPos);
        UNITROOM_RefreshUnit(pPlayer);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= UNITFLAGEX_TELEPORTED;
        }
    }
}

// 0x00581CD0
int __fastcall OBJECTS_OperateFunction30_ExplodingChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pOp->pPlayer, 0);
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pOp->pPlayer, 1);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

int __fastcall OBJECTS_OperateFunction27_TeleportPad(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    if (!pRoom)
    {
        return 0;
    }
    const int nClassId = pOp->pObject ? pOp->pObject->dwClassId : -1;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        if (pUnit->dwUnitType == UNIT_OBJECT && pUnit != pOp->pObject && pUnit->dwClassId == nClassId)
        {
            sub_00581B50_TeleportToUnit(pUnit, pRoom, pOp->pPlayer);
            return 0;
        }
    }
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    D2ActiveRoomStrc** ppList = ppRoomList;
    const unsigned int nCount = nNumRooms;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        if (ppList[i] != pRoom)
        {
            for (D2UnitStrc* pUnit = ppList[i]->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
            {
                if (pUnit->dwUnitType == UNIT_OBJECT && pUnit != pOp->pObject && pUnit->dwClassId == nClassId)
                {
                    sub_00581B50_TeleportToUnit(pUnit, ppList[i], pOp->pPlayer);
                    return 0;
                }
            }
        }
    }
    return 0;
}

// 0x00582080
int __fastcall OBJECTS_OperateFunction61_HarrogathMainGate(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->pObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(pOp->pObject);
    const int nSizeY = UNITS_GetUnitSizeY(pOp->pObject);
    const unsigned int nTickCount = GetTickCount();
    const int nAnimMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;

    if (nTickCount < pOp->pObject->dwTickCount + 500)
    {
        return 1;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    switch (nAnimMode)
    {
    case 0:
        UNITS_FreeCollisionPath(pOp->pObject);
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        pOp->pObject->dwTickCount = nTickCount;
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        break;

    case 2:
        UNITS_BlockCollisionPath(pOp->pObject, pRoom, pCoord.nX, pCoord.nY);
        UNITS_ChangeAnimMode(pOp->pObject, 0);
        pOp->pObject->dwTickCount = nTickCount;
        break;
    }

    return 1;
}

// 0x00582180
int __fastcall sub_00582180_FilterState(D2ContextStrc* context, void* argument)
{
    if (context->data)
    {
        unsigned int state = context->data->state;
        if ((short)state && (short)state == 2)
            return sub_00581F60_HandleState(context, argument);
    }
    return 0;
}

// 0x005821A0
int __fastcall OBJECTS_OperateFunction29_SlimeDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        UNITS_FreeCollisionPath(pOp->pObject);

        const int nMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;
        const int bSelectable = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nSelectable[nMode];
        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            if (bSelectable)
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
        }

        if (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nMode[2])
        {
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }

    return 1;
}

// 0x00582420
static void sub_00582420_SpawnTrapMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);

    if (!sub_6FC6A090(pGame, UNITS_GetRoom(pUnit), tCoord.nX, tCoord.nY, nMonsterId, 1, 136))
    {
        D2ActiveRoomStrc* pRoom;
        D2Common_10136(UNITS_GetRoom(pUnit), &tCoord, 0, COLLIDE_MASK_PLACEMENT, &pRoom);
        if (pRoom)
        {
            D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, tCoord.nX, tCoord.nY, nMonsterId, 1, 3, 8);
        }
    }
}

// 0x00582490
void __fastcall D2GAME_OBJECTS_TrapHandler1_6FC75C70(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_LIGHTNING);
}

// 0x005824B0
void __fastcall D2GAME_OBJECTS_TrapHandler2_6_6FC75D00(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_FIREBOLT);
}

// 0x005824D0
void __fastcall D2GAME_OBJECTS_TrapHandler3_6FC75D90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_POISONCLOUD);
}

// 0x005824F0
void __fastcall D2GAME_OBJECTS_TrapHandler4_6FC75E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_NOVA);
}

// 0x005825B0
static int sub_005825B0_HasItemOfType(D2UnitStrc* pUnit, int nItemType)
{
    D2_ASSERT(pUnit->pInventory, 1747);
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMSIsA(pCheckedItem, nItemType))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00582610
int __fastcall OBJECTS_OperateFunction17_Obelisk(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pOp->pGame, pOp->pPlayer);
    D2ClientStrc* pClient = UnitGetClient(pOp->pPlayer, ".\\OBJECTS\\ObjMode.cpp", 1772);
    const int nAnimMode = !pOp->pObject ? 0 : pOp->pObject->dwAnimMode;
    if (nAnimMode)
    {
        if (nAnimMode == OBJMODE_SPECIAL1 && pInteractUnit == pOp->pObject)
        {
            SUNIT_ResetInteractInfo(pOp->pPlayer);
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
            return 1;
        }
        return 1;
    }

    if (PLAYER_IsBusy(pOp->pPlayer) == 1)
    {
        return 1;
    }

    if (!sub_005825B0_HasItemOfType(pOp->pPlayer, ITEMTYPE_GEM))
    {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 1;
    }

    SUNIT_SetInteractInfo(pOp->pPlayer, UNIT_OBJECT, !pOp->pObject ? -1 : pOp->pObject->dwUnitId);
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_SPECIAL1);

    D2GSPacketSrv58 packet58;
    packet58.nHeader = 0x58;
    const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    packet58.nUnitId = nUnitId;
    packet58.unk0x05 = 0;
    sub_0053D8D0_SendPacket0x58(pClient, &packet58);
    return 1;
}

// 0x00582710
int __fastcall sub_00582710_IsLivingUnit(D2UnitStrc* unit, void* unused)
{
    int result = 1;
    if (!unit)
        result = 0;
    else if (unit->dwUnitType == 1)
    {
        if (MONSTERS_IsDead(unit))
            result = 0;
    }
    else if (unit->dwUnitType != 0 || !unit->dwAnimMode || unit->dwAnimMode == 17)
        result = 0;
    return result;
}

// 0x00582750
int __fastcall sub_6FC76F60(D2UnitStrc* pMonster, D2UnitStrc* pUnit1)
{
    if (pMonster == pUnit1)
    {
        return 0;
    }
    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (!pMonster || nUnitType != 1)
    {
        return 0;
    }
    if (STATLIST_AreUnitsAligned(pUnit1, pMonster) == 1)
    {
        return 0;
    }
    if (STATLIST_GetUnitAlignment(pMonster) != 0)
    {
        return 0;
    }
    if (MONSTERS_IsDead(pMonster))
    {
        return 0;
    }
    const int nAnimMode = pMonster->dwAnimMode;
    if (nAnimMode != 1 && nAnimMode != 2)
    {
        return 0;
    }
    const int nClassId = pMonster->dwClassId;
    if (!sub_0046C140_CheckMonStats2ModeFlag(nClassId, 2))
    {
        return 0;
    }
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord || !pMonStats2TxtRecord->nType)
    {
        return 0;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pMonster);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    if (MONSTERS_IsBoss(pMonStatsTxtRecord, pMonster))
    {
        return 0;
    }
    if (MONSTERS_IsPrimeEvil(pMonster))
    {
        return 0;
    }
    return MONSTERUNIQUE_CheckMonTypeFlag(pMonster, 31) == 0;
}

// 0x00582860
void __fastcall D2GAME_SHRINES_Health_6FC766B0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxLifeFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nDiff, 0);
    }
}

// 0x005828A0
void __fastcall D2GAME_SHRINES_FillMana_6FC766F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxManaFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nDiff, 0);
    }
}

// 0x005828E0
void __fastcall D2GAME_SHRINES_Refill_6FC76730(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHpDiff = STATLIST_GetMaxLifeFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0);
    if (nHpDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nHpDiff, 0);
    }

    const int nManaDiff = STATLIST_GetMaxManaFromUnit(pOp->pPlayer) - STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    if (nManaDiff)
    {
        STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nManaDiff, 0);
    }
}

// 0x00582940
void __fastcall D2GAME_SHRINES_ExchangeHealth_6FC76790(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_HITPOINTS, 0) >> 8;
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nHitpoints / 100 << 8;
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}

// 0x005829A0
void __fastcall D2GAME_SHRINES_ExchangeMana_6FC767F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nMana = STATLIST_UnitGetStatValue(pOp->pPlayer, STAT_MANA, 0);
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nMana / 100;
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_MANA, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->pPlayer, STAT_HITPOINTS, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}

// 0x00582A00
void __fastcall D2GAME_SHRINES_Enirhs_6FC76850(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    char* szName = UNITS_GetPlayerData(pOp->pPlayer)->szName;
    if (szName)
    {
        strncpy(szName, _strrev(szName), 16);
    }
}

// 0x00582AC0
static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int bResult = 0;
    D2CoordStrc tCoords;
    UNITS_GetCoords(pPlayer, &tCoords);

    D2CoordStrc tFreeCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pPlayer), &tCoords, &tFreeCoords, 1, 1);
    if (pRoom)
    {
        D2ItemDropStrc tItemDrop;
        memset(&tItemDrop, 0, sizeof(tItemDrop));
        tItemDrop.pUnit = 0;
        tItemDrop.pSeed = 0;
        tItemDrop.wItemFormat = pGame->wItemFormat;
        tItemDrop.nId = nItemId;
        tItemDrop.nX = tFreeCoords.nX;
        tItemDrop.pGame = pGame;
        tItemDrop.nSpawnType = 3;
        tItemDrop.nY = tFreeCoords.nY;
        tItemDrop.pRoom = pRoom;
        tItemDrop.wUnitInitFlags = 1;
        tItemDrop.nQuality = 2;
        tItemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
        D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &tItemDrop, 0);
        STATLIST_SetUnitStat(pNewItem, 0x46, 1, 0);
        UNITROOM_RefreshUnit(pNewItem);
        if (pNewItem)
        {
            pNewItem->dwFlags |= 1;
        }

        bResult = 1;
        if (pItem)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
            ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
            D2GAME_UpdateClientItem_6FC3E9D0(UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x80F), pPlayer, pItem, (unsigned int)nFlags);
            D2GAME_RemoveItem_6FC471F0(pGame, pPlayer, pItem, 0);
        }

    }

    return bResult;
}

// 0x00582C40
void __fastcall sub_00582C40_OperateGemShrine(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2InventoryStrc* pInventory = pOp->pPlayer->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, 0);
    int bUpgraded = 0;
    while (pItem)
    {
        if (bUpgraded)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord->dwUpgradeCode != ' non')
        {
            const int nItemId = DATATBLS_GetItemIdFromItemCode(pItemsTxtRecord->dwUpgradeCode);
            D2_ASSERT(nItemId != -1, 0x823);
            if (sub_00582AC0_UpgradeGem(pItem, nItemId, pOp->pGame, pOp->pPlayer))
            {
                bUpgraded = 1;
                pItem = 0;
            }
        }

        pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, pItem);
    }

    if (bUpgraded)
    {
        return;
    }

    D2SeedStrc* pSeed = &pOp->pPlayer->pSeed;
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;

    unsigned int dwCode;
    switch ((unsigned int)lSeed % 6)
    {
    case 0: dwCode = ' wcg'; break;
    case 1: dwCode = ' rcg'; break;
    case 2: dwCode = ' gcg'; break;
    case 3: dwCode = ' bcg'; break;
    case 4: dwCode = ' ycg'; break;
    default: dwCode = ' vcg'; break;
    }

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    D2_ASSERT(nItemId != -1, 0x84C);
    sub_00582AC0_UpgradeGem(0, nItemId, pOp->pGame, pOp->pPlayer);
}

static __forceinline int CLIENTS_GetUnitX_Shrine(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_Shrine(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00583050
void __fastcall D2GAME_SHRINES_Monster_6FC76ED0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2UnitStrc* pMonster = UNITFINDS_GetNearestTestedUnit(pOp->pPlayer, CLIENTS_GetUnitX_Shrine(pOp->pPlayer), CLIENTS_GetUnitY_Shrine(pOp->pPlayer), 0, sub_6FC76F60);
    if (pMonster)
    {
        sub_005A4940_PromoteToUnique(pOp->pGame, pMonster);
    }
}

static __declspec(noinline) void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon)
{
    *pToHit = UNITS_GetAttackRate(pUnit);
    D2_ASSERT(pSkill, 0x963);

    if (!pWeapon)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (pWeapon && ITEMS_GetItemType(pWeapon) == 0x26)
    {
        *pToHit = 0;
    }

    const int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, pSkill, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    const int nToHit = *pToHit;
    *pToHit = nToHit + nToHit * (pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit + nBonus) / 100;

    if (pUnit && pUnit->dwUnitType == 0)
    {
        const int nClassId = pUnit->dwClassId;
        D2CharStatsTxt* pCharStatsTxtRecord = 0;
        if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        {
            pCharStatsTxtRecord = &sgptDataTables->pCharStatsTxt[nClassId];
        }

        if (pCharStatsTxtRecord)
        {
            *pToHit += pCharStatsTxtRecord->dwToHitFactor;
        }
    }
}

static __forceinline int OBJMODE_GetToHitPercentageValue(D2UnitStrc* pUnit, D2UnitStrc* pWeapon, D2SkillStrc* pSkill)
{
    int nPercentage;
    OBJMODE_GetToHitPercentage(&nPercentage, 1, pUnit, pSkill, pWeapon);
    return nPercentage;
}

static __forceinline int OBJMODE_GetMinDamagePercentage(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    int bTwoHanded = 0;
    if (D2Common_10434(pUnit, 1) || pWeapon)
    {
        bTwoHanded = INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2;
    }

    if (bTwoHanded)
    {
        return STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
    }
    return STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
}

// build: context OBJMODE_CalculateShrineStatBonus
static __declspec(noinline) int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit && pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    switch (nStatId)
    {
    case 0x0B:
    case 0x1B:
    case 0x27:
    case 0x29:
    case 0x2B:
    case 0x2D:
    case 0x55:
    case 0xAB:
        return nValue;

    case 0x13:
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        return nValue * OBJMODE_GetToHitPercentageValue(pUnit, pWeapon, pSkill) / 100;
    }

    case 0x15:
        return nValue * OBJMODE_GetMinDamagePercentage(pUnit, pWeapon) / 100;

    default:
        return nValue * STATLIST_UnitGetStatValue(pUnit, nStatId, 0) / 100;
    }
}

// 0x005839B0
void __fastcall D2GAME_SHRINES_CombatBoost_6FC77690(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->nCode < gnShrineTableCount_00732EAC, 0x9C1);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[ptShrineData->nCode];
    const int nValue = OBJMODE_CalculateShrineStatBonus(0x13, ptShrineData->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, ptShrineData->dwDurationInFrames, ptShrineData->dwArg1, 0x19, pShrineRecord->unk0x08, 0);
    sub_006270B0(pStatList, 0x13, nValue, 0);
}

// 0x00583A70
void __fastcall D2GAME_SHRINES_Stamina_6FC779C0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->nCode < gnShrineTableCount_00732EAC, 0x9E7);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[ptShrineData->nCode];
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pOp->pPlayer);
    STATLIST_SetUnitStat(pOp->pPlayer, 0x0A, nMaxStamina, 0);
    const int nStatValue = OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, ptShrineData->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, ptShrineData->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, sub_6FC77AB0);
    sub_006270B0(pStatList, 0x0A, 2 * nStatValue, 0);
    sub_006270B0(pStatList, 0x1C, 1000, 0);
}

// 0x00583B30
void __fastcall D2GAME_SHRINES_DefensiveBoost_6FC77AE0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->nCode < gnShrineTableCount_00732EAC, 0x9F9);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[ptShrineData->nCode];
    const int nStatValue = pShrineRecord->unk0x04 != -1 ? OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, ptShrineData->dwArg0, pOp->pPlayer) : 0;

    sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, ptShrineData->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, 0);
}

// 0x00583BC0
void __fastcall sub_00583BC0_RefreshPassives(D2UnitStrc* pUnit)
{
    sub_6FD14C30(pUnit);
}

// 0x00583BF0
void __fastcall sub_00583BF0_ApplyEventCurse(D2SkillContext00583BF0Strc* pContext, D2Event00583BF0Strc* pEvent)
{
    D2CurseStrc tCurse = {};
    tCurse.pUnit = pContext->pUnit;
    tCurse.pTarget = pContext->pTarget;
    tCurse.nSkill = 0;
    tCurse.nSkillLevel = 0;
    tCurse.nDuration = pEvent->nDuration;
    tCurse.nStat = 11;
    tCurse.nStatValue = 0;
    tCurse.nState = gaEventStates_006E1858[pEvent->nType].nState;
    tCurse.pStateRemoveCallback = (void*)sub_6FC77C10;
    sub_0056E970(&tCurse);
    SKILLS_RefreshPassivesAndPetLimits(pContext->pTarget);
}

// 0x00583FF0
int __fastcall OBJECTS_OperateFunction18_SecretDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        UNITS_FreeCollisionPath(pOp->pObject);
    }

    return 1;
}

static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00584060
int __fastcall OBJECTS_OperateFunction26_BookShelf(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);

        int nRand = (unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) % 20;
        if (nRand > 12)
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->pObject->dwDropItemCode = ' kbi';
            }
            else
            {
                pOp->pObject->dwDropItemCode = ' kbt';
            }
        }
        else
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->pObject->dwDropItemCode = ' csi';
            }
            else
            {
                pOp->pObject->dwDropItemCode = ' cst';
            }
        }

        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
    }

    return 1;
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

static int sub_00584240_ExplodeBarrel(D2ObjOperateFnStrc* pOp)
{
    D2ObjOperateFnStrc tNewOp = *pOp;
    D2CoordStrc tCoord;
    UNITS_GetCoords(pOp->pObject, &tCoord);
    for (D2UnitStrc* pUnit = UNITS_GetRoom(pOp->pObject)->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        const int nUnitType = pUnit->dwUnitType;
        const int nAnimMode = pUnit->dwAnimMode;
        if (pUnit != pOp->pObject && nUnitType != UNIT_TILE)
        {
            if (nUnitType == UNIT_PLAYER)
            {
                if (nAnimMode != PLRMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_MONSTER)
            {
                if (nAnimMode != MONMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_OBJECT)
            {
                if (pUnit && pUnit->dwClassId == OBJECT_EXPLODINGBARREL && pUnit->dwAnimMode == OBJMODE_NEUTRAL && sub_006416D0_UnitEdgeDistance(pOp->pObject, pUnit) <= 2)
                {
                    tNewOp.pObject = pUnit;
                    OBJECTS_OperateFunction07_ExplodingBarrel(&tNewOp);
                }
            }
        }
    }
    return 0;
}

// 0x00584330
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp)
{
    if ((!pOp->pObject ? 0 : pOp->pObject->dwAnimMode) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);
        sub_00584240_ExplodeBarrel(pOp);
        UNITS_FreeCollisionPath(pOp->pObject);
        D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

// 0x005843A0
int __fastcall sub_005843A0_ToggleObjectMode(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->pObject;
    switch (!pObject ? 0 : pObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pObject, 1);
        break;
    case 1:
        UNITS_ChangeAnimMode(pObject, 0);
        break;
    }
    return 0;
}

// 0x005843D0
int __fastcall OBJECTS_OperateFunction11_Torch(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->pObject;
    if (pObject && pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        switch (pObject->dwAnimMode)
        {
        case OBJMODE_OPERATING:
        case OBJMODE_OPENED:
            UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
            break;
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);
        pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005846B0
int __fastcall OBJECTS_OperateFunction34_ArcaneSanctuaryPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));

    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    else if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->pPlayer, LEVEL_PALACECELLARLEV3, 0);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_ARCANESANCTUARY);
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->pPlayer, LEVEL_ARCANESANCTUARY, ARCANE_TILECALC);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_PALACECELLARLEV3);
    }

    return 0;
}

// 0x00584820
void __fastcall sub_00584820_ClearSteegStoneGUID(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwClassId == OBJECT_STEEG_STONE)
    {
        D2TimerArg2Strc* pArg = UNITS_GetTimerArg(pObject)->unk0x00;
        if (!pUnit || (pArg && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pArg->nUnitGUID) == pUnit))
        {
            if (pArg)
            {
                pArg->nUnitGUID = -1;
            }
        }
    }
}

static __forceinline int sub_F05_WpGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00584F60
void __fastcall OBJMODE_TravelViaWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nWaypointGUID, int nLevelId)
{
    D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
    if (!pWaypoint)
    {
        return;
    }

    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pWaypoint);
    if (!pObjectsTxtRecord)
    {
        return;
    }

    const unsigned char nOperateFn = pObjectsTxtRecord->nOperateFn;
    if (nOperateFn >= 0x65 || gpObjOperateFnTable_00732D18[nOperateFn] != OBJECTS_OperateFunction23_Waypoint)
    {
        return;
    }

    const int nDestLevelId = (unsigned short)nLevelId;
    const int nWaypointLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pWaypoint));
    SUNIT_ResetInteractInfo(pPlayer);

    if (nWaypointLevelId == nDestLevelId || !(unsigned short)nLevelId)
    {
        return;
    }

    D2WaypointDataStrc* pWaypointData = sub_00547F50(pGame, pPlayer);
    int nWaypointNo;
    if (!WAYPOINTS_GetWaypointNoFromLevelId(nDestLevelId, &nWaypointNo) || !WAYPOINTS_IsActivated(pWaypointData, nWaypointNo))
    {
        return;
    }

    int nTileIndex;
    if (DUNGEON_IsTownLevelId(nDestLevelId) || nDestLevelId == 46 || nDestLevelId == 74 || nDestLevelId == 133
        || nDestLevelId == 134 || nDestLevelId == 135 || nDestLevelId == 136)
    {
        nTileIndex = 13;
    }
    else
    {
        nTileIndex = 0;
    }

    LEVEL_WarpUnit(pGame, pPlayer, nDestLevelId, nTileIndex);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    int nX;
    int nY;
    if (pRoom && pRoom == DUNGEON_FindActSpawnLocation(pGame->pAct[DRLG_GetActNoFromLevelId(nDestLevelId)], nDestLevelId, nTileIndex, &nX, &nY))
    {
        D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x1072);
        const int nUnitGUID = sub_F05_WpGetUnitId(pPlayer);
        D2CoordStrc tCoord;
        UNITS_GetCoords(pPlayer, &tCoord);
        sub_6FC817D0(pGame, pPlayer, 0, 2, tCoord.nX, tCoord.nY, 0);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 13, 0, nUnitGUID, 1, tCoord.nX + 3, tCoord.nY + 3, 0, 0);
    }

    OBJRGN_AllocObjectRoomCoords(pGame, pPlayer, pRoom);
}

// 0x00585240
static __declspec(noinline) int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer)
{
    if (nSubType < gnObeliskPowerUps_00732FAC)
    {
        const unsigned __int64 lSeed = pPlayer->pSeed.nHighSeed + 0x6AC690C5i64 * pPlayer->pSeed.nLowSeed;
        pPlayer->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pPlayer->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((unsigned int)lSeed % 100 < gaObeliskPowerUps_00732EB0[nSubType].nChance)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback), 4341);
            return gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback(pGame, pPlayer, gaObeliskPowerUps_00732EB0[nSubType].nValue);
        }
    }

    return 0;
}

int __fastcall sub_M98_Emit_00585240(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ItemsTxt* pItemsTxtRecord, int nExtra)
{
    return sub_00585240_ApplyObeliskPowerUp(pGame, pItemsTxtRecord->nSubType, pPlayer) + nExtra;
}

// 0x00585580
void __fastcall sub_00585580_RetargetTownPortal(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nPortalGUID, int nDestLevel)
{
    D2_ASSERT(ptGame, 0x11DD);

    D2UnitStrc* pPortal = SUNIT_GetServerUnit(ptGame, 2, nPortalGUID);
    if ((pPortal ? pPortal->dwClassId : -1) != 0x3B || UNITS_CheckObjectPortalFlag(pPortal, 1))
    {
        return;
    }

    D2UnitStrc* pPair = sub_00553720_GetPortalPair(ptGame, pPortal);
    if (!pPair)
    {
        return;
    }

    D2_ASSERT(pPair->dwClassId == 0x3B, 0x11EA);
    D2_ASSERT((unsigned char)nDestLevel <= 0xFF, 0x11EC);

    pPortal->pObjectData->InteractType = (unsigned char)nDestLevel;
    D2PortalFlags00585580Strc tFlags;
    tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 1;
    UNITS_SetObjectPortalFlags(pPortal, tFlags);
    UNITS_ChangeAnimMode(pPortal, 3);

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPair), 2, !pPair ? -1 : pPair->dwUnitId);
    SUNIT_RemoveUnit(ptGame, pPair);

    D2UnitStrc* hDstPortal = D2GAME_CreateLinkPortal_6FD13B20(ptGame, pPlayer, pPortal, nDestLevel, DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal)));
    D2_ASSERT(hDstPortal, 0x11FB);

    tFlags.nFlags = UNITS_GetObjectPortalFlags(hDstPortal) | 3;
    UNITS_SetObjectPortalFlags(hDstPortal, tFlags);
}

// 0x00585720
static int __stdcall sub_00585720_WellHeal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ObjectsTxt* pObjectsTxtRecord)
{
    int bUsed = 0;

    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
    const int nFlags = pObjectsTxtRecord->dwParm[3];
    if (nLife < nMaxLife && (nFlags & 2))
    {
        unsigned int nNewLife = nLife + (nMaxLife * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewLife > nMaxLife)
        {
            nNewLife = nMaxLife;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nNewLife, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_HITPOINTS, nNewLife, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);
    if (nMana < nMaxMana && (nFlags & 1))
    {
        unsigned int nNewMana = nMana + (nMaxMana * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewMana > nMaxMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_MANA, nNewMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_MANA, nNewMana, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    const unsigned int nStamina = STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0);
    if (nStamina < nMaxStamina)
    {
        unsigned int nNewStamina = nStamina + (nMaxStamina * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewStamina > nMaxStamina)
        {
            nNewStamina = nMaxStamina;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nNewStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_STAMINA, nNewStamina, pPlayer);
        bUsed = 1;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_POISON);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_FREEZE);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pPlayer))
    {
        bUsed = 1;
    }

    PLAYERPETS_IteratePets(pGame, pPlayer, OBJMODE_PetIterate_Heal, &bUsed);
    return bUsed;
}

// 0x005858A0
int __fastcall OBJECTS_OperateFunction22_Well(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pOp->pObject);
    unsigned char nType = pOp->pObject->pObjectData->InteractType;
    if (nType)
    {
        if (sub_00585720_WellHeal(pOp->pGame, pOp->pPlayer, pObjectsTxtRecord))
        {
            nType -= 1;
            const unsigned char nMax = sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord);
            if (nType <= nMax && !(nType % (unsigned char)(nMax / sub_00552AB0())))
            {
                UNITS_ChangeAnimMode(pOp->pObject, sub_00552AB0() - nType / pObjectsTxtRecord->dwParm[2]);
            }

            pOp->pObject->pObjectData->InteractType = nType;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_AITHINK, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[0] + 1, 0, 0);
        }
    }
    return 0;
}

// 0x00585A80
D2UnitStrc* __fastcall sub_00585A80_DropItemWithIdAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemId, int nItemQuality)
{
    if (nItemId < 0)
    {
        return 0;
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2CoordStrc pReturnCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
    if (!pRoom)
    {
        return 0;
    }

    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));
    itemDrop.wItemFormat = pGame->wItemFormat;
    itemDrop.nId = nItemId;
    itemDrop.pUnit = pUnit;
    itemDrop.pSeed = 0;
    itemDrop.pGame = pGame;
    itemDrop.nSpawnType = 3;
    itemDrop.nX = pReturnCoords.nX;
    itemDrop.nY = pReturnCoords.nY;
    itemDrop.pRoom = pRoom;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.nQuality = nItemQuality;
    itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

    return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
}

// 0x00585B90
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality)
{
    D2_ASSERT(pOp->pObject, 0x1313);

    D2GameStrc* ptGame = SUNIT_GetGameFromUnit(pOp->pObject);

    D2_ASSERT(ptGame, 0x1315);
    D2_ASSERT(UNITS_GetObjectTxtRecordFromObject(pOp->pObject), 0x1317);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    if (!pRoom)
        return 0;

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);

    const int nCurrentMonsterLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, ptGame->nDifficulty, ptGame->bExpansion);
    const int nMinMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds_006E1988[2 * nAct], ptGame->nDifficulty, ptGame->bExpansion);
    const int nMaxMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds_006E1988[2 * nAct + 1], ptGame->nDifficulty, ptGame->bExpansion);

    int nMonsterLevelDiff = nMaxMonsterLevel - nMinMonsterLevel;
    if (nMonsterLevelDiff < 0)
        nMonsterLevelDiff = -nMonsterLevelDiff;

    const int nOffset = (nMonsterLevelDiff + 1) / 3;
    int nTCIndex;
    if (nCurrentMonsterLevel < nOffset + nMinMonsterLevel)
        nTCIndex = 0;
    else
        nTCIndex = (nCurrentMonsterLevel >= nMinMonsterLevel + 2 * nOffset) + 1;

    D2TCExShortStrc* pTCExRecord = DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(ptGame->nDifficulty, nAct, nTCIndex);
    if (!pTCExRecord)
        return 0;

    int nItemDropCount = 0;
    D2UnitStrc* ppDroppableItems[6] = {};
    D2GAME_DropTC_6FC51360(ptGame, pOp->pObject, pOp->pPlayer, pTCExRecord, nItemQuality, nTCIndex, 0, ppDroppableItems, &nItemDropCount, 6);
    return ppDroppableItems[0];
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static void __stdcall sub_00581680_DamagePlayersInRange(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->pRoomNext)
    {
        if (i->dwUnitType == UNIT_PLAYER && i->dwAnimMode != PLRMODE_DEAD && sub_006416D0_UnitEdgeDistance(pObject, i) <= pObjectsTxtRecord->dwParm[0] + 1)
        {
            OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, i, 1);
        }
    }
}

void __fastcall OBJMODE_UpdateTrapProximity(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwAnimMode == 1)
    {
        pObject->dwAnimMode = 2;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
    sub_00581680_DamagePlayersInRange(pGame, pObject);
    EVENT_SetEvent(pGame, pObject, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + SEED_RollRandomNumber_Inline(&pObjectControl->pSeed) % 35 + 15, 0, 0);
}

// 0x00585CE0
void __fastcall OBJMODE_UpdateTrappedSoul(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    switch (nMode)
    {
    case 1:
        EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 10, 0, 0);
        break;

    case 2:
    {
        D2ObjectDataStrc* pObjectData = pObject->pObjectData;
        const unsigned char nInteract = pObjectData->InteractType + 1;
        pObjectData->InteractType = nInteract;
        if (nInteract > 1)
        {
            D2ObjOperateFnStrc tOp;
            tOp.pGame = pGame;
            tOp.pObject = pObject;
            tOp.pPlayer = 0;
            tOp.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            tOp.nObjectIdx = pObject->dwClassId;
            if (OBJMODE_DropFromChestTCWithQuality(&tOp, 0))
            {
                UNITS_ChangeAnimMode(pObject, 3);
                EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, (pObjectsTxtRecord->dwFrameCnt[3] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            }
        }
        else
        {
            OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            sub_00581680_DamagePlayersInRange(pGame, pObject);
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 25, 0, 0);
        }
        break;
    }

    case 3:
        UNITS_ChangeAnimMode(pObject, 4);
        break;
    }
}

// 0x00586680
D2UnitStrc* __fastcall sub_00586680_RollChestDrop(D2ObjOperateFnStrc* pOp)
{
    if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
    {
        return OBJMODE_DropFromChestTCWithQuality(pOp, 0);
    }
    return 0;
}

// 0x005869F0
int __fastcall OBJECTS_OperateFunction48_TrappedSoul(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);

        if ((int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) < 90)
        {
            if (OBJMODE_DropFromChestTCWithQuality(pOp, 0))
            {
                UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_SPECIAL3);
            }
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSTATS, pOp->pGame->dwGameFrame + 20, 0, 0);
        }
    }

    return 0;
}

// 0x00586B30
int __fastcall sub_00586B30_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}
