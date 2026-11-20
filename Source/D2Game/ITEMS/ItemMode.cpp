#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#pragma intrinsic(_ReadWriteBarrier)

#define MONSTATSFLAGINDEX_NORATIO 2
#define MONSTATSFLAGINDEX_BOSS 6
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNITFLAG_INITSEEDSET 0x00000010
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAG_TARGETABLE 0x2
#define IFLAG_NEWITEM 0x1
#define IFLAG_TARGETING 0x4
#define IFLAG_IDENTIFIED 0x10
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_STATREGEN 3
#define IFLAG_QUANTITY 0x20
#define IFLAG_BROKEN 0x00000100
#define STAT_GOLD 14
#define ITEMTYPE_GOLD 4
#define UNITFLAG_ISRESURRECT 0x02000000

struct D2SeedStrc;
struct D2TradeItemStrc;
struct D2SkillsTxt;
struct D2ItemsTxt;
struct D2ItemDataStrc;
struct D2PlayerTradeStrc;
struct D2PlayerDataStrc;
struct D2MonStatsTxt;
struct D2PetInfoStrc;
struct D2SaveHeaderStrc;
struct D2ItemModeArgStrc;
struct D2DifficultyLevelsTxt;
struct D2ItemCodeListStrc;
struct D2BooksTxt;
struct D2GameStrc;
struct D2UnitStrc;
struct D2CoordStrc;
struct D2HirelingTxt;
struct D2StatStrc;
struct D2DataTablesStrc;
struct D2RunesTxt;
struct D2StaticPathStrc;
struct D2EquipmentRefreshStateStrc;
struct D2ItemDropStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2DynamicPathStrc;

extern unsigned char gaByteTable_007455C0[256]; // 0x007455C0
extern unsigned char gaByteTable_00745640[256]; // 0x00745640

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x2];
    int bExpansion;
    int dwGameType;
    unsigned short wItemFormat;
    unsigned char unk_7A[0x2E];
    unsigned int dwGameFrame;
    char unk0xAC[0x24];
    int pGameSeed;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2ItemDataStrc* pItemData;
        D2PlayerDataStrc* pPlayerData;
    };
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x60 - 0x2C - 4];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x0055DBC0
void __fastcall sub_005FE000_StoreTileFreeCallback(void* pfnCallback); // 0x005FE000
extern void* gpGlobal_00882D08; // 0x00882D08
int __stdcall sub_006BE450(void* pObject); // 0x006BE450
void __stdcall sub_006BF5F0(void* pObject); // 0x006BF5F0

struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};

struct D2PlayerTradeStrc
{
    int nSaveLength;
    unsigned char* pSaveData;
    D2TradeItemStrc* pItemTrade;
    int nGoldInTrade;
    int nGoldInTradeOtherPlayer;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    int dwTradeState;
    int unk0x54;
    int dwAcceptTradeTick;
    D2PlayerTradeStrc* pTrade;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};


struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2HirelingTxt
{
    char unk0x00[0x114];
    unsigned short wNameFirst;
};

struct D2SaveHeaderStrc
{
    unsigned char unk0x00[0xAF];
    unsigned char MercSaveData[4];
    unsigned char f_B3[4];
    unsigned char wMercName[2];
    unsigned char wMercHirelingId[2];
    unsigned char nMercExperience[4];
};

typedef int D2CorpseStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x005378E0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543DB0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed); // 0x00552DF0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C6E0
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00566BF0
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName); // 0x006220F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
void __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0
void __stdcall sub_0063C550_Return(D2InventoryStrc* pInventory, int nX); // 0x0063C550
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory); // 0x0063E0B0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0
int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int a2); // 0x00537860
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053ECF0
void __fastcall sub_6FC42050(D2UnitStrc* pItem, D2ClientStrc* pClient); // 0x0055BED0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740

enum
{
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc*, int); // 0x0063C7F0


struct D2DifficultyLevelsTxt
{
    char pad00[0x08];
    int dwUberCodeOddsNorm;
    int dwUberCodeOddsGood;
    char pad10[0x20 - 0x10];
    int dwUltraCodeOddsNorm;
    int dwUltraCodeOddsGood;
};

struct D2ItemCodeListStrc
{
    unsigned char nCountA;
    char pad01[3];
    unsigned int dwCodesA[30];
    unsigned char nCountB;
    char pad7D[3];
    unsigned int dwCodesB[1];
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
void __stdcall sub_0055C2C0(D2UnitStrc* pItem, int nArg); // 0x0055C2C0
void __stdcall sub_0055A2A0(D2UnitStrc* pUnit, int nArg); // 0x0055A2A0

struct D2StatStrc
{
    union
    {
        struct
        {
            unsigned short nLayer;
            unsigned short nStat;
        };
        int nPackedValue;
    };
    int nValue;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges); // 0x0065C940
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);
void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00567400
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
extern "C" char __stdcall sub_00628250(D2UnitStrc* pUnit); // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00568770
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, unsigned char nPage); // 0x006282D0
int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCC0

struct D2BooksTxt
{
    char unk0x00[8];
    int dwScrollSkillId;
    int dwBookSkillId;
};

extern "C" const char szItemModeCpp[]; // 0x006E1164
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity);
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused); // 0x0063C3B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
static int sub_00560020_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

struct D2RunesTxt { char unk_00[0x81]; unsigned char nServer; };
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558580
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055FE80
void __stdcall sub_006276C0_MergeSocketStats(D2UnitStrc*, D2UnitStrc*); // 0x006276C0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0
int __stdcall sub_0062BEB0_IsSocketFiller(D2UnitStrc*); // 0x0062BEB0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc*); // 0x0062BED0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void*, D2UnitStrc*); // 0x0063ABD0
void __stdcall sub_006600A0_ApplyRuneWord(D2UnitStrc*, D2UnitStrc*, int); // 0x006600A0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGold); // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pUnit); // 0x00554630
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055CC90
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x006272B0

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};


struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    int* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    int unk0x24;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int unk0x2C;
    int nQuality;
    char unk0x34[0x40 - 0x34];
    int dwFlags1;
    int unk0x44;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    char unk0x50[0x84 - 0x50];
};

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
static __declspec(noinline) void __stdcall sub_0055E590_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2);
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine); // 0x0063B950
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C790
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60
int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc*, D2UnitStrc*, D2UnitStrc**, D2UnitStrc**, int*); // 0x0055F2D0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc*, int); // 0x00627D70
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063BDB0
static __declspec(noinline) int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem);
static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem);
extern "C" void _ReadWriteBarrier(void);

// 0x0052B270
int __fastcall sub_0052B270()
{
    return sub_006BE450(gpGlobal_00882D08);
}

// 0x0052B6F0
void __fastcall sub_0052B6F0()
{
    sub_006BF5F0(gpGlobal_00882D08);
}

// 0x00550130
void __cdecl sub_00550130_Nop()
{
}

#include "gen/data/Source/D2Game/ITEMS/ItemMode.inc"

// 0x00555DA0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms)
{
    const int nX = pCoords->nX + 2;
    const int nY = pCoords->nY + 3;

    if (D2GAME_GetRoom_6FC52070(pRoom, nX, nY))
    {
        pReturnCoords->nX = nX;
        pReturnCoords->nY = nY;
    }
    else
    {
        pReturnCoords->nX = pCoords->nX;
        pReturnCoords->nY = pCoords->nY;
    }

    return COLLISION_GetFreeCoordinatesWithField(pRoom, pReturnCoords, pCoords, nUnitSize, 0x3E01, 0x801, bAllowNeighborRooms);
}

// 0x00558AA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (!pRoom)
    {
        return;
    }

    UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
    UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
    UNITROOM_AddUnitToRoom(pItem, pRoom);

    if (pItem)
    {
        pItem->dwFlags |= 0x1002;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    ITEMS_SetInvPage(pItem, 0xFF);

    if (pItem)
    {
        pItem->dwFlags |= 0x2000000;
    }

    pItem->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(pGame, pItem);

    if (pUnit)
    {
        QUESTS_ItemDropped(pGame, pUnit, pItem);
    }
}

// 0x0055AFA0
void __fastcall sub_6FC52110(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems)
{
    int nLevel = 0;
    if (pGame->bExpansion && pGame->nDifficulty > 0 && pMonster && pMonster->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
        if (pMonStatsTxtRecord && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7]) && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7]))
        {
            nLevel = STATLIST_UnitGetStatValue(pMonster, 0xC, 0);
        }
    }

    D2TCExShortStrc* pTCRecord = DATATBLS_GetTreasureClassExRecordFromIdAndLevel(nTCId, nLevel);
    if (pTCRecord)
    {
        D2GAME_DropTC_6FC51360(pGame, pMonster, pPlayer, pTCRecord, nQuality, nItemLevel, a7, ppItems, pnItemsDropped, nMaxItems);
    }
}

// 0x0055B030
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    D2UnitStrc* pGoldPiles[32];
    int nCount;
    sub_0055A090_DropGoldPiles(pGame, pUnit, nValue, pGoldPiles, &nCount, 32);
}

// 0x0055B060
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    const unsigned int nGoldLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const unsigned int nGold = STATLIST_UnitGetStatValue(pUnit, 14, 0);
    if (nGold == nGoldLimit)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nValue);
    }
    else if (nGold + nValue > nGoldLimit)
    {
        PLRTRADE_AddGold(pUnit, 14, nGoldLimit - nGold);
        ITEMS_DropGoldPile(pGame, pUnit, nValue + nGold - nGoldLimit);
    }
    else
    {
        PLRTRADE_AddGold(pUnit, 14, nValue);
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

// 0x0055BED0
void __fastcall sub_6FC42050(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (!pItem || UNIT_HasFlag(pItem, UNITFLAG_INITSEEDSET) || pItem->dwAnimMode != IMODE_ONGROUND)
    {
        return;
    }

    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (UNIT_HasFlag(pItem, UNITFLAG_SENDREFRESHMSG))
    {
        D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(pClient, pPlayer, pItem, 0);
    }
    else
    {
        D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(pClient, pPlayer, pItem, 0);
    }
}

// 0x0055BF30
void __fastcall sub_6FC420B0(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (pItem && UNIT_HasFlag(pItem, UNITFLAG_DOUPDATE))
    {
        sub_6FC42050(pItem, pClient);
    }
}

// 0x0055BF50
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_CheckItemFlag(pInvItem, IFLAG_TARGETING, 0x1D6, ".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(pInvItem, IFLAG_TARGETING, 0);
            if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == UNIT_PLAYER)
            {
                D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1DA), pInvItem, 0xFF, 1, 0, 0xFFFF);
            }
        }
    }
}

// 0x0055BFE0
void __fastcall sub_0055BFE0_ClearTargetingFlags(D2UnitStrc* pUnit)
{
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1E5);
}

// 0x0055BFF0
static __declspec(noinline) int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x1EC);

    if (ITEMSIsA(pItem, 0x16) || ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            if (ITEMSIsA(pItem, 0x16))
            {
                return pBooksTxtRecord->dwScrollSkillId;
            }

            if (ITEMSIsA(pItem, 0x12))
            {
                return pBooksTxtRecord->dwBookSkillId;
            }
        }
    }

    return -1;
}

// 0x0055C110
static __declspec(noinline) int __stdcall sub_0055C110_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId != -1)
    {
        int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
        if (nQuantity || !ITEMSIsA(pItem, 0x12))
        {
            if (!nQuantity)
            {
                nQuantity = 1;
            }

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            int nNewQuantity;
            if (bAddQuantity)
            {
                if (!pSkill)
                {
                    nNewQuantity = nQuantity;
                    STATLIST_AddUnitStat(pUnit, 5, nNewQuantity, 0);
                    sub_6FD136E0(pUnit, nSkillId);
                    pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                    D2_ASSERT(pSkill, 0x225);
                }
                else
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) + nQuantity;
                }
            }
            else
            {
                if (pSkill)
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) - nQuantity;
                    if (nNewQuantity < 0)
                    {
                        nNewQuantity = 0;
                    }
                }
                else
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x230);
                    exit(-1);
                }
            }

            SKILLS_SetQuantity(pSkill, nNewQuantity);

            int nUnitGUID;
            int nUnitType;
            if (!pUnit)
            {
                nUnitGUID = -1;
                nUnitType = 6;
            }
            else
            {
                nUnitGUID = pUnit->dwUnitId;
                nUnitType = pUnit->dwUnitType;
            }

            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, szItemModeCpp, 0x234), nUnitType, nUnitGUID, nSkillId, nNewQuantity);

            if (!nNewQuantity)
            {
                if (UNITS_GetLeftSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 1, 0, -1);
                }

                if (UNITS_GetRightSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                }
            }

            return 1;
        }
    }

    return 0;
}

// 0x0055C470
static __declspec(noinline) void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
{
    *ppRightHandWeapon = 0;
    *ppMainWeapon = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        *ppMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRightHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (*ppMainWeapon == pRightHandWeapon)
        {
            *ppRightHandWeapon = pLeftHandWeapon;
        }
        else
        {
            *ppRightHandWeapon = pRightHandWeapon;
        }

        if (*ppRightHandWeapon && !ITEMSIsA(*ppRightHandWeapon, 0x2D))
        {
            *ppRightHandWeapon = 0;
        }
    }
}

// 0x0055C4D0
static __declspec(noinline) int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }

    return 1;
}

// 0x0055C4F0
static __declspec(noinline) void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
{
    if (!pUnit || !pCurrentSkill)
    {
        return;
    }

    int nSkillId;
    int nOwnerGUID;
    if (bLeft)
    {
        UNITS_GetLeftSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }
    else
    {
        UNITS_GetRightSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill || pSkill == pCurrentSkill)
    {
        return;
    }

    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeft, nSkillId, nOwnerGUID);
}

// 0x0055C560
static __declspec(noinline) int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 0x30) || pSkillsTxtRecord->nAuraTargetState != 2)
    {
        return 0;
    }

    return sub_0055C4D0_IsSkillUsable(pUnit, pSkill) != 0;
}

// 0x0055C5C0
static __declspec(noinline) void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pRightHandWeapon;
    D2UnitStrc* pMainWeapon;
    sub_0055C470_GetWeapons(pUnit, &pMainWeapon, &pRightHandWeapon);
    if (!pMainWeapon)
    {
        return;
    }

    int bThrown = ITEMSIsA(pMainWeapon, 0x30) && !ITEMSIsA(pMainWeapon, 0x2E);
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pLeftSkill))
    {
        UNITS_InitLeftSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 1, 2, -1);
        pLeftSkill = UNITS_GetLeftSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pLeftSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pLeftSkill, 1);
        break;
    }

    bThrown = pRightHandWeapon && ITEMSIsA(pRightHandWeapon, 0x30) && !ITEMSIsA(pRightHandWeapon, 0x2E);
    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pRightSkill))
    {
        UNITS_InitRightSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, 4, -1);
        pRightSkill = UNITS_GetRightSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pRightSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pRightSkill, 0);
        break;
    }
}

static __forceinline void AddGoldToUnit(D2UnitStrc* pUnit, int nGold)
{
    if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) + nGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER && nNewGold > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, STAT_GOLD, nGold, 0);
        }
    }
}

// build: context sub_0055C850_PickupGold
static void __stdcall sub_0055C850_PickupGold(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pGoldPile)
{
    const int nInventoryLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nUnitGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nPileGold = STATLIST_UnitGetStatValue(pGoldPile, STAT_GOLD, 0);
    int nRemainingGold = 0;

    int nPickedGold = nPileGold;
    if (nPileGold + nUnitGold > nInventoryLimit)
    {
        nPickedGold = nInventoryLimit - nUnitGold;
        nRemainingGold = nPileGold - nPickedGold;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pGoldPile);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        PLRTRADE_AddGold(pUnit, STAT_GOLD, nPickedGold);
    }
    else if (SUNIT_GetPartyId(pUnit) != -1)
    {
        nRemainingGold = PARTY_ShareGoldDrop(pGame, pUnit, nPileGold);
    }
    else
    {
        AddGoldToUnit(pUnit, nPickedGold);
    }

    int nUnitGUID = -1;
    int nUnitType = 6;
    if (pGoldPile)
    {
        nUnitGUID = pGoldPile->dwUnitId;
        nUnitType = pGoldPile->dwUnitType;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pGoldPile), nUnitType, nUnitGUID);
    UNITS_FreeCollisionPath(pGoldPile);
    UNITROOM_RemoveUnitFromRoom(pGoldPile);

    if (pGoldPile)
    {
        pGoldPile->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pGoldPile);

    if (nRemainingGold > 0)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nRemainingGold);
        SUNIT_AttachSound(pUnit, 0x17, pUnit);
    }
}

// build: context sub_0055C9A0_DropBackToGround
static void __stdcall sub_0055C9A0_DropBackToGround(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nSound)
{
    int nUnitGUID = -1;
    int nUnitType = 6;
    if (pItem)
    {
        nUnitGUID = pItem->dwUnitId;
        nUnitType = pItem->dwUnitType;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), nUnitType, nUnitGUID);
    ITEMS_SetInvPage(pItem, 0xFF);

    if (pItem)
    {
        pItem->dwFlags |= UNITFLAG_SENDREFRESHMSG;
    }

    UNITS_ChangeAnimMode(pItem, IMODE_ONGROUND);
    SUNIT_AttachSound(pUnit, nSound, pUnit);
}

// 0x0055CF50
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 1368);
    D2_ASSERT(pUnit, 1369);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 1374);

    if (INVENTORY_GetCursorItem(pInventory) || PLAYER_IsBusy(pUnit))
    {
        return;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 1390);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    if (pItem->dwAnimMode != IMODE_ONGROUND)
    {
        *pItemStatus = 1;
        return;
    }

    if (!sub_6FC425F0(pGame, pUnit, pItem))
    {
        sub_0055C9A0_DropBackToGround(pUnit, pItem, 0x13);
        return;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        sub_0055C850_PickupGold(pGame, pUnit, pItem);
    }
    else
    {
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
        INVENTORY_SetCursorItem(pInventory, pItem);
        UNITS_ChangeAnimMode(pItem, IMODE_ONCURSOR);
        ITEMS_SetItemCMDFlag(pItem, 64, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        UNITS_RefreshInventory(pUnit, 1);
        pItem->dwFlags &= ~UNITFLAG_ISRESURRECT;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
    }

    SUNIT_AttachSound(pUnit, 1, pUnit);
}

// 0x0055D560
static void sub_6FC43160(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ItemModeArgStrc* pItemModeArg)
{
    D2_ASSERT(pItem, 0x675);
    D2_ASSERT(pUnit, 0x676);
    memset(pItemModeArg, 0, sizeof(D2ItemModeArgStrc));
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 0 && pUnit->dwClassId == 4)
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    const int nUnitType2 = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType2 == 0 && pUnit->dwClassId == 6 && ITEMSIsA(pItem, 0x43))
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    if (ITEMSIsA(pItem, 0x1B))
    {
        pItemModeArg->bIsBow = 1;
    }
    if (ITEMSIsA(pItem, 0x23))
    {
        pItemModeArg->bIsCrossBow = 1;
    }
    if (ITEMSIsA(pItem, 5))
    {
        pItemModeArg->bIsBowQuiver = 1;
    }
    if (ITEMSIsA(pItem, 6))
    {
        pItemModeArg->bIsCrossBowQuiver = 1;
    }
    if (ITEMSIsA(pItem, 0x33))
    {
        pItemModeArg->bIsShield = 1;
    }
    if (ITEMS_CheckWeaponIfTwoHanded(pItem))
    {
        pItemModeArg->bIsTwoHanded = 1;
    }
    if (ITEMSIsA(pItem, 0x2D))
    {
        pItemModeArg->bIsWeapon = 1;
    }
    if (ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0))
    {
        pItemModeArg->bIsThrowable = 1;
    }
    if (ITEMSIsA(pItem, 0x0A))
    {
        pItemModeArg->bIsRing = 1;
    }
}

// 0x0055D670
static int sub_6FC43280(D2ItemModeArgStrc* pArg2, D2ItemModeArgStrc* pArg1)
{
    if (pArg1->bIsBow && pArg2->bIsBowQuiver || pArg1->bIsBowQuiver && pArg2->bIsBow)
    {
        return 1;
    }
    if (pArg1->bIsCrossBow && pArg2->bIsCrossBowQuiver || pArg1->bIsCrossBowQuiver && pArg2->bIsCrossBow)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsShield || pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bIsShield)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bCanUse2Weapons && pArg2->bCanUse2Weapons)
    {
        return 1;
    }
    if (pArg1->bIsRing && pArg2->bIsRing)
    {
        return 1;
    }
    return 0;
}

int __fastcall sub_6FC42F20(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pBodyLoc, int bSkipRequirementCheck)
{
    D2_ASSERT(pUnit, 0x6DC);
    D2_ASSERT(pItem, 0x6DD);
    if (bSkipRequirementCheck)
    {
        if (!ITEMS_IsBodyItem(pItem) || !ITEMS_CheckItemFlag(pItem, 0x10, 0x6E2, ".\\ITEMS\\ItemMode.cpp") || !sub_0062A4E0_TestItem(pItem) || ITEMS_GetItemType(pItem) == 0x26)
        {
            return 0;
        }
    }
    else
    {
        if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0) || !ITEMS_IsBodyItem(pItem) || !ITEMS_CheckItemFlag(pItem, 0x10, 0x6EB, ".\\ITEMS\\ItemMode.cpp") || !sub_0062A4E0_TestItem(pItem) || ITEMS_GetItemType(pItem) == 0x26)
        {
            return 0;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (ITEMS_GetQuiverTypeFromItemType(ITEMS_GetItemType(pItem)))
    {
        if (!pRightArmItem || !ITEMSIsA(pItem, ITEMS_GetAmmoType(pRightArmItem)))
        {
            if (!pLeftArmItem || !ITEMSIsA(pItem, ITEMS_GetAmmoType(pLeftArmItem)))
            {
                return 0;
            }
        }
    }
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);
    if (nBodyLoc1 == nBodyLoc2)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1))
        {
            *pBodyLoc = nBodyLoc1;
            return 1;
        }
        return 0;
    }
    D2ItemModeArgStrc itemModeArg1;
    D2ItemModeArgStrc itemModeArg2;
    sub_6FC43160(pUnit, pItem, &itemModeArg1);
    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc2);
    if (pItem1 && pItem2)
    {
        return 0;
    }
    if (!pItem1 && !pItem2)
    {
        *pBodyLoc = nBodyLoc1;
        return 1;
    }
    if (pItem1)
    {
        sub_6FC43160(pUnit, pItem1, &itemModeArg2);
        if (!sub_6FC43280(&itemModeArg2, &itemModeArg1))
        {
            return 0;
        }
        *pBodyLoc = nBodyLoc2;
        return 1;
    }
    sub_6FC43160(pUnit, pItem2, &itemModeArg2);
    if (!sub_6FC43280(&itemModeArg2, &itemModeArg1))
    {
        return 0;
    }
    *pBodyLoc = nBodyLoc1;
    return 1;
}

// 0x0055D920
void __stdcall sub_0055D920_Nop()
{
}

// 0x0055D940
static void __stdcall sub_0055D940_DetachItemAndUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    sub_0063D2B0_DetachItem(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == IMODE_EQUIP)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }
}

void __fastcall sub_K11_Emit0055D940(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    sub_0055D940_DetachItemAndUpdate(pGame, pUnit, pItem);
    sub_0055D940_DetachItemAndUpdate(pGame, pItem, pUnit);
}

// 0x0055DB00
int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bResult = ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0);
    if (bResult && ITEMS_GetQuiverType(pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pOtherArmItem == pItem)
        {
            pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        }

        if (!pOtherArmItem || !ITEMSIsA(pOtherArmItem, ITEMS_GetQuiverType(pItem)))
        {
            bResult = 0;
        }
    }

    return bResult;
}

// 0x0055DB80
D2ClientStrc* __fastcall sub_0055DB80_GetClientFromUnitOrOwner(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xA44);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        return UnitGetClient(pOwner, ".\\ITEMS\\ItemMode.cpp", 0xA49);
    }

    return 0;
}

// 0x0055DF00
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused, int nArg)
{
    sub_0055DBC0(pGame, pUnit, nArg);
}

// 0x0055DF10
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket)
{
    D2_ASSERT(pGame, 0xF6F);
    D2_ASSERT(pUnit, 0xF70);

    if (pItem)
    {
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemove, 0xF76);
    D2_ASSERT(pItem == pRemove, 0xF77);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF7B, pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nRecordId, 0, nPage);
    ITEMS_SetInvPage(pItem, INVPAGE_NULL);

    if (bSendPacket)
    {
        sub_00571600(pItem, UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF7E));
    }

    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

static __forceinline int sub_E03_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_E03_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0055E590
static void __stdcall sub_0055E590_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2)
{
    D2InventoryStrc* pInventory;
    int nSrcValue;
    int nDstValue;
    int nMaxStack;
    int nQuantity;
    int nRemaining;
    int bRemoveSource;

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return;
    }

    pInventory = pUnit->pInventory;
    nSrcValue = STATLIST_UnitGetStatValue(pItem1, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x114B);

    nDstValue = STATLIST_UnitGetStatValue(pItem2, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x114D);

    nMaxStack = ITEMS_GetTotalMaxStack(pItem2);
    D2_ASSERT(nMaxStack >= 0, 0x114F);

    nQuantity = nSrcValue + nDstValue;
    bRemoveSource = 1;
    if (nQuantity > nMaxStack)
    {
        STATLIST_SetUnitStat(pItem2, 0x46, nMaxStack, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1155), pItem2, 1, 0x46, nMaxStack, 0);

        nRemaining = nDstValue - nMaxStack + nSrcValue;
        bRemoveSource = 0;
        D2_ASSERT(nRemaining >= 0, 0x1158);

        STATLIST_SetUnitStat(pItem1, 0x46, nRemaining, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x115B), pItem1, 1, 0x46, nRemaining, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pItem2) - nDstValue, pUnit, pItem2);
        }
    }
    else
    {
        if (ITEMS_HasDurability(pItem1))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem1, 0x48, 0);
            if (nDurability < STATLIST_UnitGetStatValue(pItem2, 0x48, 0))
            {
                STATLIST_SetUnitStat(pItem2, 0x48, nDurability, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1170), pItem2, 1, 0x48, nDurability, 0);
            }
        }

        D2_ASSERT(nQuantity >= 0, 0x1176);

        STATLIST_SetUnitStat(pItem2, 0x46, nQuantity, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1179), pItem2, 1, 0x46, nQuantity, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pItem2);
        }
    }

    if (bRemoveSource)
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        D2GAME_PACKETS_SendPacket0x42_6FC3EE40(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1184), pUnit);
        ITEMS_RemoveFromAllPlayers(pGame, pItem1);
    }
    else
    {
        ITEMS_SetItemFlag(pItem2, 8, 1);
    }
}

// 0x0055E7C0
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x1192);
    D2_ASSERT(pUnit, 0x1193);

    *pItemStatus = 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1198);

    if (nItemGUID1 == nItemGUID2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pItem1 = SUNIT_GetServerUnit(pGame, 4, nItemGUID1);
    if (!pItem1)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem1->dwUnitType != 4)
    {
        return 0;
    }

    D2UnitStrc* pItem2 = SUNIT_GetServerUnit(pGame, 4, nItemGUID2);
    if (!pItem2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem2->dwUnitType != 4)
    {
        return 0;
    }

    if (ITEMS_GetInvPage(pItem2) == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return 0;
    }

    const int nClassId1 = pItem1->dwClassId;
    _ReadWriteBarrier();
    const int nClassId2 = pItem2->dwClassId;
    _ReadWriteBarrier();
    if (nClassId1 != nClassId2)
    {
        return 1;
    }

    sub_0055E590_MergeStacks(pGame, pItem1, pUnit, pItem2);
    ITEMS_SetItemCMDFlag(pItem2, 0x100, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem2);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

// 0x0055EB30
int __fastcall sub_6FC48D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5)
{
    D2_ASSERT(pGame, 0x128A);
    D2_ASSERT(pUnit, 0x128B);

    *a5 = 0;

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1290);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != 4 || pCursorItem->dwAnimMode != 4 || !ITEMS_CheckIfBeltable(pCursorItem))
    {
        return 0;
    }

    D2UnitStrc* pBeltItem = SUNIT_GetServerUnit(pGame, 4, nBeltItemGUID);
    if (!pBeltItem || pBeltItem->dwUnitType != 4)
    {
        return 0;
    }

    const int nBeltItemMode = pBeltItem ? pBeltItem->dwAnimMode : 0;
    if (nBeltItemMode != 2)
    {
        *a5 = 1;
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pBeltItem);
    D2_ASSERT(pRemove, 0x12B8);
    D2_ASSERT(pBeltItem == pRemove, 0x12B9);

    sub_0063C550_Return(pInventory, CLIENTS_GetUnitX(pBeltItem));
    INVENTORY_SetCursorItem(pInventory, pBeltItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pBeltItem);

    pBeltItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pBeltItem, pUnit, 0, 1);
    UNITS_ChangeAnimMode(pBeltItem, 4);
    ITEMS_SetItemCMDFlag(pBeltItem, 0x1000, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pBeltItem);
    if (INVENTORY_PlaceItemInBeltSlot(pInventory, pCursorItem, CLIENTS_GetUnitX(pBeltItem)))
    {
        UNITS_SetXForStaticUnit(pCursorItem, CLIENTS_GetUnitX(pBeltItem));
        UNITS_SetYForStaticUnit(pCursorItem, 0);
        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 2))
        {
            sub_0055C270_OnItemToBelt(pUnit, pCursorItem);

            pCursorItem->dwFlags &= ~2;

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                sITEMSAddStatsList(pGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 2);
            ITEMS_SetInvPage(pCursorItem, 0xFF);
            ITEMS_SetItemCMDFlag(pCursorItem, 0x1000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);
            sub_0055DBC0(pGame, pUnit, 0);
            return 1;
        }

        D2_ASSERT(0, 0x12D4);
    }

    D2_ASSERT(0, 0x12D8);
}

// 0x0055EDC0
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    nX &= 3;
    int nDestinationRow = 0;
    nX = nX > 0 ? nX : 0;
    nX = nX < 3 ? nX : 3;
    for (int nRow = 0; nRow < 4; ++nRow)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nX + 4 * nRow);
        if (pItem)
        {
            if (nDestinationRow != nRow)
            {
                INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nX + 4 * nDestinationRow);
                ITEMS_SetItemFlag(pItem, 0x400, 1);
                ITEMS_SetItemFlag(pItem, 1, 1);
                if (ITEMS_CheckItemFlag(pItem, 0x4000, 4883, ".\\ITEMS\\ItemMode.cpp"))
                    ITEMS_SetItemFlag(pItem, 0x4000, 0);
                UNITS_RefreshInventory(pUnit, 1);
                INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                sub_0063C550_Return(pInventory, nX + 4 * nRow);
            }
            ++nDestinationRow;
        }
    }
}

// 0x0055EEA0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pItem || INVENTORY_GetCursorItem(pInventory) != pItem)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\ITEMS\\ItemMode.cpp", 0x139A);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    return 1;
}

// 0x0055F120
void __cdecl sub_0055F120_Nop()
{
}

// 0x0055F130
void __fastcall sub_0055F130_UpdateStatListsExpiration(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x0055F240
int __fastcall sub_0055F240_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

// 0x0055F2A0
D2UnitStrc* __fastcall sub_0055F2A0_GetItemFromOppositeBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pDefault, int nBodyLoc)
{
    const int nOpposite = sub_0055F240_GetOppositeBodyLoc(nBodyLoc);
    if (!nOpposite)
    {
        return pDefault;
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, nOpposite);
}

// build: context GetUnitType
static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x0055F2D0
int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
{
    if (!pUnit || !pItem || GetUnitType(pItem) != 4) return 0;
    D2UnitStrc* pPrimary = *ppPrimary;
    if (pPrimary)
    {
        if (*ppOther) return 0;
    }
    else if (!*ppOther) return 1;
    int nOpposite = sub_0055F240_GetOppositeBodyLoc(*pBodyLoc);
    if (pPrimary)
    {
        *ppPrimary = *ppOther;
        *ppOther = pPrimary;
        *pBodyLoc = nOpposite;
    }
    switch (*pBodyLoc)
    {
    case 4: case 5: case 11: case 12:
        if (ITEMS_GetAmmoType(pItem) > 0)
        {
            if (!*ppOther) return 1;
            return ITEMSIsA(*ppOther, ITEMS_GetAmmoType(pItem)) != 0;
        }
        if (ITEMS_GetQuiverType(pItem))
        {
            if (!*ppOther) return 1;
            if (ITEMS_GetAmmoType(*ppOther) <= 0) return 0;
            return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        }
        if (ITEMS_GetAmmoType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        if (ITEMS_GetQuiverType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetQuiverType(*ppOther)) != 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem) && !ITEMS_Is1Or2Handed(pUnit, pItem)) return 0;
        if (ITEMS_CheckWeaponIfTwoHanded(*ppOther) && !ITEMS_Is1Or2Handed(pUnit, *ppOther)) return 0;
        {
            int bItemWeapon = ITEMSIsA(pItem, 45);
            int bOtherWeapon = ITEMSIsA(*ppOther, 45);
            if (bItemWeapon)
            {
                if (bOtherWeapon)
                {
                    if (GetUnitType(pUnit) == 1) return 1;
                    switch (pUnit->dwClassId)
                    {
                    case 4: return 1;
                    case 6:
                        if (ITEMSIsA(pItem, 67) && ITEMSIsA(*ppOther, 67)) return 1;
                        return 0;
                    default: return 0;
                    }
                }
            }
            else if (!bOtherWeapon) return 0;
            return *ppPrimary == 0;
        }
    default: return *ppPrimary == 0;
    }
}

// 0x0055F590
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_CheckIfSocketable(pItem) && pItem->pInventory && INVENTORY_GetItemCount(pItem->pInventory) > 0)
    {
        return 1;
    }

    return 0;
}

// 0x0055F850
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    ITEMS_SetItemFlag(pItem, 0x100, 1);
    sub_0063D2B0_DetachItem(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == 1)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }

    sub_0055DBC0(pGame, pUnit, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    STATLIST_SetUnitStat(pItem, 0x48, 0, 0);

    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x191E), pItem, 1, 0x48, 0, 0);
    ITEMS_UpdateSets(pUnit, pItem, 1, 1);
    SUNIT_AttachSound(pUnit, 9, pUnit);
}

// 0x0055FB10
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x19A0);
    D2_ASSERT(pItem, 0x19A1);

    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x100000, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
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

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0055FB80
unsigned int __fastcall sub_0055FB80_PickItemCode(D2GameStrc* pGame, D2ItemCodeListStrc* pList, D2UnitStrc* pUnit, int bGood)
{
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nIndex = SEED_RollLimitedRandomNumberInline(pSeed, pList->nCountA + pList->nCountB);
    unsigned int dwCode;
    if (nIndex < pList->nCountA)
    {
        dwCode = pList->dwCodesA[nIndex];
    }
    else
    {
        dwCode = pList->dwCodesB[nIndex - pList->nCountA];
    }

    int nItemId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (!pItemsTxt)
    {
        return dwCode;
    }

    D2_ASSERT(pItemsTxt->wVersion <= pGame->wItemFormat, 6601);

    if (pItemsTxt->dwUberCode == 0x20202030 || !pItemsTxt->dwUberCode)
    {
        return dwCode;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUberCodeOddsGood : pDifficultyLevelsTxtRecord->dwUberCodeOddsNorm))
    {
        dwCode = pItemsTxt->dwUberCode;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUltraCodeOddsGood : pDifficultyLevelsTxtRecord->dwUltraCodeOddsNorm))
        {
            dwCode = pItemsTxt->dwUltraCode;
        }
    }

    return dwCode;
}

// 0x0055FCC0
void __fastcall sub_6FC4BA50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory);
    while (pNode)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pNode);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        D2_ASSERT(pItem, 0x19FD);

        if (INVENTORY_GetItemNodePage(pNode) == 3 || INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit))
        {
            sub_0062A360(pUnit, pItem);
            sub_0063D2B0_DetachItem(pInventory, pItem);
            D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemove, 0x1A0F);
            D2_ASSERT(pItem == pRemove, 0x1A10);

            if (INVENTORY_GetItemNodePage(pNode) == 3)
            {
                sub_0063BE30_Return(pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));
            }

            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
            sub_0055DBC0(pGame, pUnit, 0);
        }

        pNode = pNext;
    }

    INVENTORY_RemoveAllItems(pInventory);
}

// 0x0055FDE0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    sub_0055DBC0(pGame, pUnit, 0);
    if (a3)
    {
        UNITS_RefreshInventory(pUnit, 1);
    }
}

// 0x0055FE00
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);

    if (pItem && pItem->dwAnimMode != IMODE_STORED)
    {
        return;
    }

    if (!ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        return;
    }

    sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
    sub_0055DBC0(pGame, pPlayer, 0);
    UNITS_RefreshInventory(pPlayer, 1);
}

// 0x0055FE60
void __stdcall sub_0055FE60_AttachToOwner(D2UnitStrc* pItem)
{
    sub_0055C2C0(pItem, 0);
}

// 0x0055FE80
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ClientStrc* pClient = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 6809);
    }

    D2StatStrc stats[64];
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, stats, 64);
    int bRecharged = 0;
    for (int i = 0; i < nStats; ++i)
    {
        const int nLayer = stats[i].nLayer;
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
        const int nValue = stats[i].nValue >> 8;
        if ((stats[i].nValue & 0xFF) < nValue)
        {
            ITEMMODS_UpdateItemWithSkillCharges(pItem, nSkillId, nSkillLevel, nValue);

            bRecharged = 1;
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, STAT_ITEM_CHARGED_SKILL,
                    (nValue & 0xFF) + (nValue << 8),
                    (nSkillLevel & (unsigned short)sgptDataTables->nShiftedStuff) + (nSkillId << sgptDataTables->nStuff));
            }
        }
    }

    return bRecharged;
}

static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x202);
    D2_ASSERT(pItem, 0x203);

    const int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId == -1)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        const int nQuantity = SKILLS_GetQuantity(pSkill) + nQuantityBonus;
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitType = pUnit->dwUnitType;
        const int nUnitGUID = pUnit->dwUnitId;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, szItemModeCpp, 0x20B), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
}

static int __stdcall sub_0055D0D0_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pStackItem = 0;
    int nCounter = 0;

    while (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0)
    {
        ++nCounter;

        if (ITEMS_GetAutoStack(pItem))
        {
            if (ITEMS_GetQuiverType(pItem))
            {
                pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
                if (!pStackItem)
                {
                    pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
                }
            }
            else
            {
                pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
            }
        }

        if (!pStackItem)
        {
            return 0;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity1 = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            const int nQuantity2 = STATLIST_UnitGetStatValue(pStackItem, 0x46, 0);
            if (nQuantity1 + nQuantity2 > ITEMS_GetTotalMaxStack(pStackItem))
            {
                const int nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
                D2_ASSERT(nMaxStack >= 0, 0x5C7);

                STATLIST_SetUnitStat(pStackItem, 0x46, nMaxStack, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5CA), pStackItem, 1, 0x46, nMaxStack, 0);

                const int nRest = nQuantity2 - nMaxStack + nQuantity1;
                D2_ASSERT(nRest >= 0, 0x5CC);

                STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pStackItem) - nQuantity2, pUnit, pStackItem);
                }
            }
            else
            {
                const int nQuantity = nQuantity2 + nQuantity1;
                D2_ASSERT(nQuantity >= 0, 0x5D7);

                if (ITEMS_HasDurability(pItem))
                {
                    const int nDurability = STATLIST_UnitGetStatValue(pItem, 0x48, 0);
                    if (nDurability < STATLIST_UnitGetStatValue(pStackItem, 0x48, 0))
                    {
                        STATLIST_SetUnitStat(pStackItem, 0x48, nDurability, 0);
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5E4), pStackItem, 1, 0x48, nDurability, 0);
                    }
                }

                STATLIST_SetUnitStat(pStackItem, 0x46, nQuantity, 0);
                STATLIST_SetUnitStat(pItem, 0x46, 0, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5ED), pStackItem, 1, 0x46, nQuantity, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(nQuantity1, pUnit, pStackItem);
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (pItem)
                {
                    pItem->dwFlags &= ~2;
                }

                ITEMS_RemoveFromAllPlayers(pGame, pItem);
                INVENTORY_SetCursorItem(pInventory, 0);
                return 1;
            }
        }
    }

    if (nCounter)
    {
        D2_ASSERT(0, 0x606);
    }

    return 0;
}

int __stdcall sub_0055D370_TryMergeBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x622);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pInventory, pItem, 0);
    if (!pBook)
    {
        return 0;
    }

    const int nSrcValue = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x62E);

    const int nDstValue = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x630);

    const int nDstMaxValue = ITEMS_GetTotalMaxStack(pBook);
    D2_ASSERT(nDstMaxValue >= 0, 0x632);

    const int nQuantity = nDstValue + nSrcValue;
    if (nQuantity > nDstMaxValue)
    {
        STATLIST_SetUnitStat(pBook, 0x46, nDstMaxValue, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x638), pBook, 1, 0x46, nDstMaxValue, 0);

        const int nRest = nDstValue - nDstMaxValue + nSrcValue;
        D2_ASSERT(nRest >= 0, 0x63A);

        STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x63D), pItem, 1, 0x46, nRest, 0);
        sub_0055C070_AddBookScrollSkillQuantity(nDstMaxValue - nDstValue, pUnit, pBook);
        return 1;
    }

    D2_ASSERT(nQuantity >= 0, 0x645);

    STATLIST_SetUnitStat(pBook, 0x46, nQuantity, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x648), pBook, 1, 0x46, nQuantity, 0);
    sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pBook);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    INVENTORY_SetCursorItem(pInventory, 0);
    return 1;
}

// 0x0055FFA0
static int sub_0055FFA0_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScroll)
{
    D2_ASSERT(pGame, 0x610);

    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pUnit->pInventory, pScroll, 0);
    if (pBook)
    {
        int nItemStatus;
        const int nBookGUID = pBook->dwUnitId;
        return ITEMMODE_AddScrollToBook(pGame, pUnit, !pScroll ? -1 : pScroll->dwUnitId, nBookGUID, &nItemStatus);
    }

    return 0;
}

int __fastcall sub_J07_Emit_00560020(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    return sub_00560020_PickupStackable(pGame, pUnit, pItem);
}

// 0x00560020
static int sub_00560020_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x65F);

    if (ITEMSIsA(pItem, 0x16))
    {
        return sub_0055FFA0_AddScrollToBook(pGame, pUnit, pItem);
    }

    if (ITEMSIsA(pItem, 0x12))
    {
        return sub_0055D370_TryMergeBookQuantity(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckIfStackable(pItem) && ITEMS_GetAutoStack(pItem))
    {
        return sub_0055D0D0_AutoStackPickup(pGame, pUnit, pItem);
    }

    return 0;
}

// 0x005600A0
static __declspec(noinline) int __stdcall sub_005600A0_PlaceItemInInventory(D2GameStrc* pGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x746);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x749);

    if (INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion), 0, 0, szFile, nLine))
    {
        if (bRemove)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
            if (pRoom)
            {
                const int nUnitGUID = !pItem ? -1 : pItem->dwUnitId;
                const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
                DUNGEON_AllocDrlgDelete(pRoom, nUnitType, nUnitGUID);
                UNITS_FreeCollisionPath(pItem);
                UNITROOM_RemoveUnitFromRoom(pItem);
            }
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
        {
            INVENTORY_SetCursorItem(pInventory, 0);
            sub_0055C270_OnItemToBelt(pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                sITEMSAddStatsList(pGame, pItem, pUnit, 0);
            }

            if (pItem)
            {
                pItem->dwFlags &= ~2u;
            }

            UNITS_ChangeAnimMode(pItem, 0);
            ITEMS_SetItemCMDFlag(pItem, 0x80, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pUnit, 1);

            if (pItem)
            {
                pItem->dwFlags &= ~0x02000000u;
            }

            ITEMS_SetInvPage(pItem, nPage);
            QUESTS_ItemPickedUp(pGame, pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                sub_0055DBC0(pGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        D2_ASSERT(0, 0x76F);
    }

    return 0;
}

// 0x00560420
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus, int nUpdateMode, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int bAllowOccupiedCursor)
{
    D2_ASSERT(pGame, 0x906);
    D2_ASSERT(pUnit, 0x907);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventoryArg)
    {
        pInventory = pInventoryArg;
    }

    D2_ASSERT(pInventory, 0x910);

    if (INVENTORY_GetCursorItem(pInventory) && !bAllowOccupiedCursor)
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER && !PLAYER_IsBusy(pUnit) && sub_00628250(pItem))
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_STORED)
    {
        *pItemStatus = 1;
        return 0;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x936);

    pItem->dwFlags &= ~UNITFLAG_TARGETABLE;

    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemove, 0x947);
    D2_ASSERT(pItem == pRemove, 0x948);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);

    if (ITEMS_IsCharmUsable(pItem, pUnit))
    {
        sub_0055DBC0(pGame, pUnit, 0);
        UNITS_RefreshInventory(pUnit, 1);
    }

    sub_0055C6E0_OnItemToCursor(pUnit, pItem);

    const unsigned char nInvPage = sub_00628250(pItem);
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion);

    int bTrade = 0;
    int bEquip = 1;

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nInvPage)
        {
        case INVPAGE_EQUIP:
            bEquip = 0;
            break;
        case INVPAGE_TRADE:
            bTrade = 1;
            break;
        }
    }
    else
    {
        bEquip = 0;
    }

    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0x965, pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nInventoryRecordId, 0, nInvPage);

    ITEMS_SetItemCell(pItem, nInvPage);
    ITEMS_SetInvPage(pItem, INVPAGE_NULL);

    if (bEquip)
    {
        INVENTORY_SetCursorItem(pInventory, pItem);
    }

    UNITS_ChangeAnimMode(pItem, IMODE_ONCURSOR);

    if (nUpdateMode == 1)
    {
        if (bSetQuantityFlag)
        {
            ITEMS_SetItemFlag(pItem, IFLAG_QUANTITY, 1);
        }

        if (bTrade == 1)
        {
            PLRTRADE_RemoveItemFromTrade(pGame, pUnit, pItem);
        }

        ITEMS_SetItemCMDFlag(pItem, 4, 1);

        if (sub_0055F590_CheckItem(pItem, ".\\ITEMS\\ItemMode.cpp", 0x975))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);
        }

        if (sub_006280A0(pItem, IFLAG_NOEQUIP, 0x978, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NOEQUIP, 0);
        }

        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    return 1;
}

int dword_0088C6FC; // 0x0088C6FC

bool byte_0088C700; // 0x0088C700

// 0x00561B00
int __fastcall sub_6FC46D40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nGridItemGUID, int nX, int nY, int* pItemStatus)
{
    D2_ASSERT(pGame, 0xEC0);
    D2_ASSERT(pUnit, 0xEC1);

    *pItemStatus = 0;

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xEC6);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != 4 || pCursorItem->dwAnimMode != 4)
    {
        return 0;
    }

    D2UnitStrc* pGridItem = SUNIT_GetServerUnit(pGame, 4, nGridItemGUID);
    if (!pGridItem || pGridItem->dwUnitType != 4)
    {
        return 0;
    }

    const char nInvPage = sub_00628250(pGridItem);
    if (nInvPage == 3)
    {
        if (!byte_0088C700)
        {
            if (!DATATBLS_GetItemRecordFromItemCode(0x20786F62, &dword_0088C6FC))
            {
                return 0;
            }

            byte_0088C700 = 1;
        }

        const int nClassId = (pCursorItem ? pCursorItem->dwClassId : -1);
        if (nClassId == dword_0088C6FC)
        {
            return 0;
        }
    }
    else if (nInvPage == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pGridItem->dwAnimMode != 0)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pGridItem);
    D2_ASSERT(pRemove, 0xF12);
    D2_ASSERT(pGridItem == pRemove, 0xF13);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pGridItem, pUnit, 0, 1);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF15, pInventory, CLIENTS_GetUnitX(pGridItem), CLIENTS_GetUnitY(pGridItem), UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion), 0, nInvPage);

    ITEMS_SetInvPage(pGridItem, 0xFF);
    INVENTORY_SetCursorItem(pInventory, pGridItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pGridItem);
    ITEMS_SetCellOverlap(pGridItem, nInvPage);
    pGridItem->dwFlags &= ~2u;
    UNITS_ChangeAnimMode(pGridItem, 4);
    ITEMS_SetItemCMDFlag(pGridItem, 0x40000, 1);

    if (sub_0055F590_CheckItem(pGridItem, ".\\ITEMS\\ItemMode.cpp", 0xF1F))
    {
        ITEMS_SetItemFlag(pGridItem, 1, 1);
    }

    if (sub_006280A0(pGridItem, 0x4000, 0xF22, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(pGridItem, 0x4000, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pGridItem);

    if (INVENTORY_PlaceItemAtInventoryPage(pInventory, pCursorItem, nX, nY, UNITS_GetInventoryRecordId(pUnit, nInvPage, pGame->bExpansion), 0, nInvPage))
    {
        ITEMS_SetCellOverlap(pCursorItem, 0);
        ITEMS_SetInvPage(pCursorItem, nInvPage);
        UNITS_SetXForStaticUnit(pCursorItem, nX);
        UNITS_SetYForStaticUnit(pCursorItem, nY);

        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 1))
        {
            pCursorItem->dwFlags &= ~2u;
            sub_0055C270_OnItemToBelt(pUnit, pCursorItem);

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                sITEMSAddStatsList(pGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 0);

            if (sub_0055F590_CheckItem(pCursorItem, ".\\ITEMS\\ItemMode.cpp", 0xF48))
            {
                ITEMS_SetItemFlag(pCursorItem, 1, 1);
            }

            if (sub_006280A0(pCursorItem, 0x4000, 0xF4B, (unsigned int)".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(pCursorItem, 0x4000, 0);
            }

            ITEMS_SetItemCMDFlag(pCursorItem, 0x40000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);

            if (nInvPage == 2)
            {
                PLRTRADE_AddItemToTrade(pGame, pUnit, pCursorItem);
            }

            UNITS_RefreshInventory(pUnit, 1);

            if (ITEMS_IsCharmUsable(pGridItem, pUnit))
            {
                sub_0055DBC0(pGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        *pItemStatus = 1;
        return 0;
    }

    *pItemStatus = 1;
    return 0;
}

// 0x00562250
int __fastcall sub_6FC48B40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4)
{
    D2_ASSERT(pGame, 0x1249);
    D2_ASSERT(pUnit, 0x124A);

    *a4 = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x124F);

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *a4 = 1;
        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 2)
    {
        *a4 = 1;
        return 0;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x126D);

    const int nX = CLIENTS_GetUnitX(pItem);
    INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    sub_0063C550_Return(pInventory, nX);
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pItem);

    pItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x800, 1);
    UNITS_RefreshInventory(pUnit, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    sub_0055EDC0(pGame, pUnit, nX);
    return 1;
}

// 0x00562660
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9)
{
    D2_ASSERT(pGame, 0x13A9);
    *bPlaced = 0;
    if (pUnit) sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x13B0);
    D2UnitStrc* pFiller = SUNIT_GetServerUnit(pGame, 4, nSocketFillerGUID);
    if (!pFiller)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pFiller->dwUnitType != 4) return 0;
    if (pFiller->dwAnimMode != 4)
    {
        *bPlaced = 1;
        return 0;
    }
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pItem->dwUnitType != 4) return 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x13DB, ".\\ITEMS\\ItemMode.cpp")) return 0;
    if (bCheckMode && pItem->dwAnimMode != 0 && pItem->dwAnimMode != 1) return 0;
    if (pFiller->dwUnitType != 4 || pItem->dwUnitType != 4 || !sub_0062BEB0_IsSocketFiller(pFiller)
        || !ITEMS_CheckItemFlag(pFiller, 0x10, 0x13EA, ".\\ITEMS\\ItemMode.cpp")
        || !ITEMS_CheckItemFlag(pItem, 0x800, 0x13EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CheckIfSocketable(pItem)) return 0;
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        pInventory = INVENTORY_AllocInventory(0, pItem);
        if (!pInventory) return 0;
    }
    const unsigned int nSockets = ITEMS_GetSockets(pItem);
    if (INVENTORY_GetItemCount(pInventory) >= nSockets) return 0;
    if (INVENTORY_PlaceItemInSocket(pInventory, pFiller, 1))
    {
    pFiller->dwFlags &= ~2u;
    if (bResetCursorItem && pUnit) INVENTORY_SetCursorItem(pUnit->pInventory, 0);
    sITEMSAddStatsList(pGame, pFiller, pItem, 0);
    sub_006276C0_MergeSocketStats(pFiller, pItem);
    UNITS_ChangeAnimMode(pFiller, 6);
    const D2RunesTxt* pRunesTxt = ITEMS_GetRunesTxtRecordFromItem(pItem);
    if (pRunesTxt && ((pRunesTxt->nServer && pGame->dwGameType) || !pRunesTxt->nServer))
    {
        sub_006600A0_ApplyRuneWord(pItem, pFiller, 0);
        ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
        ITEMS_ScheduleQuantityReplenishment(pGame, pItem);
        if (a9) D2GAME_RechargeItem_6FC4BD50(pGame, pUnit, pItem);
        bRefresh = 1;
    }
    if (bRefresh)
    {
        ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x143A, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        if (pUnit)
        {
            UNITS_RefreshInventory(pUnit, 1);
            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
        }
    }
    return 1;
    }
    else
    {
        D2_ASSERT(0, 0x1444);
    }
}

// 0x00562C40
static int __stdcall sub_6FC4A350(D2GameStrc* pGame, D2UnitStrc* pItem, int nLengthStatId, int nValueStatId, int nMaxValue)
{
    const int nLength = STATLIST_UnitGetStatValue(pItem, nLengthStatId, 0);
    if (!nLength)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetStatValue(pItem, nValueStatId, 0) + 1;
    if (nValue > nMaxValue)
    {
        return 1;
    }

    STATLIST_SetUnitStat(pItem, nValueStatId, nValue, 0);

    const int nOwnerGUID = ITEMS_GetOwnerId(pItem);
    if (nOwnerGUID != -1)
    {
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        if (pOwner)
        {
            D2ClientStrc* pClient = UnitGetClient(pOwner, ".\\ITEMS\\ItemMode.cpp", 5504);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, nValueStatId, nValue, 0);
                if (nValue >= 1)
                {
                    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 5510, ".\\ITEMS\\ItemMode.cpp"))
                    {
                        D2GAME_RepairBrokenItem_6FC4B630(pGame, pOwner, pItem);
                    }
                }
            }
        }
    }

    int nDuration = 2500 / nLength + 1;
    if (nDuration < 125)
    {
        nDuration = 125;
    }

    EVENT_SetEvent(pGame, pItem, EVENTTYPE_STATREGEN, pGame->dwGameFrame + nDuration, 0, 0);

    return 1;
}

// 0x00562D30
void __fastcall sub_6FC4A2E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemFlag(pUnit, IFLAG_BROKEN, 5542, ".\\ITEMS\\ItemMode.cpp") && ITEMS_HasDurability(pUnit) && sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_DURABILITY, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pUnit)))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pUnit))
    {
        sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_QUANTITY, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pUnit));
    }
}

// build: context ITEMMODE_GetOtherBodyLocItem
static __forceinline D2UnitStrc* ITEMMODE_GetOtherBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc, D2UnitStrc* pItem)
{
    const int nOppositeBodyLoc = sub_0055F240_GetOppositeBodyLoc(nBodyLoc);
    if (!nOppositeBodyLoc)
    {
        return pItem;
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, nOppositeBodyLoc);
}

// 0x00562F30
int __fastcall ITEMMODE_RecoverCorpseItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pCorpse)
{
    if (!pPlayer || !pCorpse)
    {
        return 0;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    D2InventoryStrc* pCorpseInventory = pCorpse->pInventory;
    if (!pPlayerInventory || !pCorpseInventory)
    {
        return 0;
    }

    int bItemRemoved = 0;
    int nCounter = 0;
    do
    {
        bItemRemoved = 0;
        nCounter = 0;
        for (int i = 1; i < 13; ++i)
        {
            int nBodyLoc = i;
            D2UnitStrc* pCorpseItem = INVENTORY_GetItemFromBodyLoc(pCorpseInventory, i);
            if (pCorpseItem)
            {
                ++nCounter;

                if (ITEMS_CheckRequirements(pCorpseItem, pPlayer, 0, 0, 0, 0))
                {
                    D2UnitStrc* pPlayerItem = INVENTORY_GetItemFromBodyLoc(pPlayerInventory, i);
                    D2UnitStrc* pOtherPlayerItem = ITEMMODE_GetOtherBodyLocItem(pPlayerInventory, i, pPlayerItem);

                    int bMoved = 0;
                    if (!ITEMMODE_CheckAndResolveBodySlotPair(pPlayer, pCorpseItem, &pPlayerItem, &pOtherPlayerItem, &nBodyLoc))
                    {
                        if (sub_005600A0_PlaceItemInInventory(pGame, 0, 0, szItemModeCpp, 0x176B, pPlayer, pCorpseItem))
                        {
                            ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                            ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                            bMoved = 1;
                        }
                    }
                    else
                    {
                        const int nResolvedBodyLoc = nBodyLoc;
                        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pPlayerInventory, nResolvedBodyLoc), 0x1775);

                        if (INVENTORY_PlaceItemInBodyLoc(pPlayerInventory, pCorpseItem, nResolvedBodyLoc))
                        {
                            int nSocketType = 3;
                            if (nResolvedBodyLoc == 11 || nResolvedBodyLoc == 12)
                            {
                                nSocketType = 4;
                            }

                            if (INVENTORY_PlaceItemInSocket(pPlayerInventory, pCorpseItem, nSocketType))
                            {
                                INVENTORY_SetCursorItem(pPlayerInventory, 0);
                                ITEMS_SetBodyLocation(pCorpseItem, nResolvedBodyLoc);
                                pCorpseItem->dwFlags &= ~2u;
                                UNITS_ChangeAnimMode(pCorpseItem, 1);
                                ITEMS_SetItemCMDFlag(pCorpseItem, 8, 1);
                                INVENTORY_AddItemToTradeInventory(pPlayerInventory, pCorpseItem);
                                UNITS_RefreshInventory(pPlayer, 1);
                                pCorpseItem->dwFlags &= ~0x02000000u;
                                ITEMS_SetInvPage(pCorpseItem, 0xFF);

                                if (nSocketType == 3)
                                {
                                    sub_0063D1D0_InventoryItemCall(pPlayerInventory, pCorpseItem);
                                    sITEMSAddStatsList(pGame, pCorpseItem, pPlayer, 0);
                                    sub_0055C270_OnItemToBelt(pPlayer, pCorpseItem);
                                    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pPlayer);
                                }

                                QUESTS_ItemPickedUp(pGame, pPlayer, pCorpseItem);
                                ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                                ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                                bMoved = 1;
                            }
                            else
                            {
                                sub_0063BE30_Return(pPlayerInventory, nResolvedBodyLoc);
                            }
                        }
                    }

                    if (bMoved)
                    {
                        ITEMS_SetItemFlag(pCorpseItem, 1, 1);
                        INVENTORY_RemoveItemFromInventory(pCorpseInventory, pCorpseItem);
                        sub_0063BE30_Return(pCorpseInventory, i);
                        bItemRemoved = 1;
                        --nCounter;
                    }
                }
            }
        }
    }
    while (nCounter && bItemRemoved);

    int bAllowInventoryFallback = 0;
    int nMoved;
    int nResult;
    while (1)
    {
        nMoved = 0;
        nResult = 1;
        D2UnitStrc* pCorpseItem = INVENTORY_GetFirstItem(pCorpseInventory);
        if (!pCorpseItem)
        {
            break;
        }

        do
        {
            D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pCorpseItem);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCorpseItem);
            if (!sub_6FC425F0(pGame, pPlayer, pItem))
            {
                nResult = 0;
            }
            else
            {
                if (!ITEMMODE_EquipItemAtResolvedBodyLocation(pGame, pPlayer, pItem, 0))
                {
                    if (ITEMS_CheckIfBeltable(pItem) && INVENTORY_PlaceItemInFreeBeltSlot(pPlayerInventory, pItem))
                    {
                        if (!INVENTORY_PlaceItemInSocket(pPlayerInventory, pItem, 2))
                            goto NextLooseItem;
                        INVENTORY_SetCursorItem(pPlayerInventory, 0);

                        D2_ASSERT(pItem, 0x24E);
                        if (pPlayer->dwUnitType == 0)
                        {
                            sub_0055C110_UpdateBookScrollSkillQuantity(1, pPlayer, pItem);
                        }

                        pItem->dwFlags &= ~2u;
                        if (ITEMS_IsCharmUsable(pItem, pPlayer))
                        {
                            sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
                        }

                        UNITS_ChangeAnimMode(pItem, 2);
                        pItem->dwFlags &= ~0x02000000u;
                        ITEMS_SetItemCMDFlag(pItem, 0x2000u, 1);
                        ITEMS_SetInvPage(pItem, 0xFF);
                        INVENTORY_AddItemToTradeInventory(pPlayerInventory, pItem);
                        UNITS_RefreshInventory(pPlayer, 1);
                    }
                    else if (!bAllowInventoryFallback)
                    {
                        goto NextLooseItem;
                    }
                    else if (!sub_005600A0_PlaceItemInInventory(pGame, 0, 0, szItemModeCpp, 0x17F1, pPlayer, pItem))
                    {
                        nResult = 0;
                        goto NextLooseItem;
                    }
                }
                ++nMoved;
                ITEMS_SetItemFlag(pItem, 1, 1);
            }
NextLooseItem:

            pCorpseItem = pNextItem;
        }
        while (pCorpseItem);

        if (!nMoved)
        {
            if (bAllowInventoryFallback)
            {
                break;
            }

            bAllowInventoryFallback = 1;
        }
    }
    sub_0055DBC0(pGame, pPlayer, 0);
    return nResult;
}

// 0x00566CC0
void __fastcall sub_6FC90C20(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x880);

    for (int i = 1; i < 13; ++i)
    {
        sub_0063BE30_Return(pPlayer->pInventory, i);
    }

    D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
    D2_ASSERT(pTrade, 0x888);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 9, 0);

    int nUnused;
    sub_005337F0_ReadItems(pGame, pPlayer, pTrade->pSaveData, 0x60, 0x2000, 0, &nUnused);

    const int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    const int nMode = pPlayer->dwAnimMode;
    if (nGold > 0 && nMode != 0 && nMode != 17)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nGold);
        PLRTRADE_AddGold(pPlayer, 14, pTrade->nGoldInTradeOtherPlayer);
    }
}

// 0x005679E0
void __fastcall sub_6FC91050(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState)
{
    UNITS_RefreshInventory(pPlayer1, 1);
    UNITS_RefreshInventory(pPlayer2, 1);

    if (pPlayer1)
    {
        pPlayer1->dwFlagEx |= 0x800000;
    }

    if (pPlayer2)
    {
        pPlayer2->dwFlagEx |= 0x800000;
    }

    SUNIT_ResetInteractInfo(pPlayer1);
    SUNIT_ResetInteractInfo(pPlayer2);

    sub_6FC90AE0(pGame, pPlayer1, 1);
    sub_6FC90AE0(pGame, pPlayer2, 1);

    PLRTRADE_Free(pGame, pPlayer1);
    PLRTRADE_Free(pGame, pPlayer2);

    pPlayerData1->dwTradeState = nTradeState;
    pPlayerData2->dwTradeState = 9;

    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x969), 0xC);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x96A), 0xC);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer1, 0xD, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer2, 0xD, 0);

    EVENT_SetEvent(pGame, pPlayer1, 0xD, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pPlayer2, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568640
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int nUnitType;
    int nUnitGUID;
    if (!SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        return;
    }

    SUNIT_ResetInteractInfo(pPlayer);

    if (!SUNIT_GetInteractInfo(pOtherPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (nUnitGUID != nPlayerGUID)
    {
        return;
    }

    UNITS_GetPlayerData(pPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);

    sub_6FC90AE0(pGame, pPlayer, 0);
    sub_6FC90AE0(pGame, pOtherPlayer, 1);

    PLRTRADE_Free(pGame, pPlayer);
    PLRTRADE_Free(pGame, pOtherPlayer);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC2F), 0xC);
    SUNIT_ResetInteractInfo(pOtherPlayer);

    UNITS_GetPlayerData(pOtherPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568DC0
unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID)
{
    if (nGUID == -1)
    {
        return 0;
    }

    if (!pPlayer->pInventory)
    {
        return 0;
    }

    int nIdx = 1;
    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory);
    while (pNode)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pNode);
        pNode = INVENTORY_GetNextItem(pNode);
        if ((!pCheckedItem ? -1 : pCheckedItem->dwUnitId) == nGUID)
        {
            D2_ASSERT(nIdx < 0x7FFF, 0x185);
            return nIdx;
        }

        ++nIdx;
    }

    return 0;
}

// 0x00568E60
void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader)
{
    D2UnitStrc* pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, pHireling->dwUnitId);
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, 0xC, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    *(unsigned int*)pSaveHeader->f_B3 = pPetInfo->nSeed;
    *(unsigned short*)pSaveHeader->wMercName = pPetInfo->wName;
    *(unsigned short*)pSaveHeader->wMercHirelingId = pPetInfo->nHirelingId;
    *(unsigned int*)pSaveHeader->nMercExperience = STATLIST_UnitGetStatValue(pHireling, 0xD, 0);
    *(unsigned int*)pSaveHeader->MercSaveData = 0;
    *(unsigned short*)pSaveHeader->wMercName -= pHirelingTxtRecord->wNameFirst;

    if (SUNIT_IsDead(pHireling))
    {
        *(unsigned int*)pSaveHeader->MercSaveData |= 0x10000;
    }
}

// 0x00569A00
int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a5, int a6)
{
    unsigned char* pData = *ppSection;
    int bHasIronGolem = 0;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    *(unsigned short*)pData = 'fk';
    pData += 2;

    D2UnitStrc* pIronGolem = sub_6FC7E8B0(pGame, pPlayer, 3, 1);
    D2UnitStrc* pGolemItem = 0;
    D2UnitStrc* pFirst;
    if (pIronGolem && pIronGolem->dwClassId == 0x123 && SKILLS_GetSkill(pPlayer, 0x5A, -1) && pIronGolem->pInventory
        && (pFirst = INVENTORY_GetFirstItem(pIronGolem->pInventory)) != 0 && (pGolemItem = INVENTORY_UnitIsItem(pFirst)) != 0)
    {
        bHasIronGolem = 1;
    }

    unsigned char* pFlag = pData;
    *pData = bHasIronGolem;
    ++pData;
    if (bHasIronGolem)
    {
        const int nLength = D2GAME_SAVE_SerializeItem_6FC89AD0(pGame, pPlayer, pGolemItem, pData, pEnd - pData, 0, a5, a6);
        if (nLength <= 0)
        {
            *pFlag = 0;
        }

        pData += nLength;
    }

    *ppSection = pData;
    return 0;
}

// 0x00569F20
void __fastcall sub_00569F20_InitPlayerFromClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, 1);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->pTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    pPlayerData->unk0x54 = 0;
}

// 0x005738D0
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_STATREGEN, 0);
}

// 0x005776E0
void __stdcall sub_005776E0(D2UnitStrc* pUnit)
{
    sub_0055A2A0(pUnit, 1);
}

// 0x00604A30
void __stdcall sub_00604A30_StoreTileFreeHandler(void* pfnCallback)
{
    sub_005FE000_StoreTileFreeCallback(pfnCallback);
}

// 0x0063E780
unsigned char __stdcall sub_0063E780_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_007455C0[nIndex];
}

// 0x0063E7C0
unsigned char __stdcall sub_0063E7C0_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_00745640[nIndex];
}
