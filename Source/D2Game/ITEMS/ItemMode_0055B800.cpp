#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define ITEMQUAL_UNIQUE 7
#define QUESTSTATEFLAG_A1Q4 4
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q2 10
#define QFLAG_REWARDGRANTED 0
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GemsTxt;
struct D2CorpseStrc;
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2SkillsTxt;
struct D2ItemsTxt;
struct D2PlayerDataStrc;
struct D2QuestItemPairStrc;
struct D2BooksTxt;
struct D2StaticPathStrc;
struct D2EquipmentRefreshStateStrc;
struct SwapEntry;






extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc*, D2UnitStrc*, int, int, int); // 0x0053C4A0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*, const char*, int); // 0x005531C0
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc*); // 0x0055B7E0


void __fastcall sub_0056BD90_RefreshPetMaxForSkill(D2GameStrc*, D2UnitStrc*, int); // 0x0056BD90
void __fastcall sub_6FD11C90(D2UnitStrc*, int, int); // 0x0056C740
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc*); // 0x0056DFA0
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc*, D2UnitStrc*, int, int, int, int, int, int); // 0x0056E740
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0
void __fastcall SKILLITEM_ActivateAura(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005BF510
void __fastcall SKILLITEM_DeactivateAura(D2GameStrc*, D2UnitStrc*, int, int); // 0x005BF5D0
void __fastcall SUNITEVENT_Unregister(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C0B50
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc*); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc*, int*); // 0x00625820
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc*, int, int); // 0x00639E30
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*, int*, int*, int*, const char*, int); // 0x00645270
void __stdcall SKILLS_RefreshSkill(D2UnitStrc*, int); // 0x00646D60
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc*, int); // 0x00647110
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc*, int, int, int, const char*, int); // 0x00647280
void __stdcall D2Common_10954(D2UnitStrc*, int, int, int, int, int); // 0x00647530


extern "C" const char szItemModeCpp[]; // 0x006E1164
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2GemsTxt* pGemsTxt, int nArg2, int nArg5); // 0x0065FEC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc*, D2UnitStrc*); // 0x006277F0
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc*, D2UnitStrc*); // 0x0055C6E0
void __stdcall sub_006275B0_UpdateVitals(D2UnitStrc*); // 0x006275B0

struct D2UniqueItemsTxt
{
    short wId;
    char unk0x002[0x2A];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};


extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2QuestItemPairStrc gQuestItemPairs_00731FEC[4]; // 0x00731FEC
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
static __declspec(noinline) int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem);

struct D2BooksTxt
{
    char unk0x00[8];
    int dwScrollSkillId;
    int dwBookSkillId;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused); // 0x0063C3B0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem); // 0x0055BFF0
static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C070


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

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold); // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAmount); // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x0055DBC0
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* pWeapon); // 0x006233A0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc); // 0x0063E490
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590
void __fastcall ITEMMODE_MoveExcessBeltItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0
static __declspec(noinline) void __stdcall sub_0055D970_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit);
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc*, D2UnitStrc*, int); // 0x005678A0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005BF240
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc*, D2UnitStrc*); // 0x0058A0A0
void __fastcall sub_00570360_ResetSkills(D2GameStrc*, D2UnitStrc*); // 0x00570360
void __fastcall sub_00570C80_ResetStats(D2GameStrc*, D2UnitStrc*); // 0x00570C80
int __stdcall sub_00628C20_IsUsable(D2UnitStrc*); // 0x00628C20
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*, int, int); // 0x0065C3A0
int __fastcall sub_0055F240_GetOppositeBodyLoc(int); // 0x0055F240
int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00568770
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*, unsigned char, int); // 0x00621050
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc*, D2UnitStrc*, int, int, unsigned char, const char*, int); // 0x0063B950
int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc*, D2UnitStrc*, int, int, int, int, unsigned char); // 0x0063BCC0
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063BDB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
static void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon); // 0x0055C470
static __declspec(noinline) int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C4D0
static void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft); // 0x0055C4F0
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C560
static void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit); // 0x0055C5C0
void __fastcall sub_0055FB10_ReturnItem(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055FB10
int __stdcall sub_0063CB00_CheckPlacement(D2InventoryStrc*, D2UnitStrc*, int, int); // 0x0063CB00
int __stdcall sub_0063B950_PlaceItem(D2InventoryStrc*, D2UnitStrc*, int, int, int, const char*, int); // 0x0063B950
unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc*); // 0x0053E110
void __fastcall sub_00571C60_SendSkill(D2UnitStrc*, int, int, int); // 0x00571C60
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc*); // 0x00622F80
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc*); // 0x00622FF0
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc*, int*, int*); // 0x00623120
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc*, int*, int*); // 0x006231A0
void __stdcall sub_0063BE30_Return(D2InventoryStrc*, int); // 0x0063BE30

struct SwapEntry { int from; D2UnitStrc* item; int to; int mode; };
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00561E70
static __declspec(noinline) void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc*, D2UnitStrc*, D2UnitStrc*);
static __declspec(noinline) int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc*);
static __declspec(noinline) void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc*, int);
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
void __stdcall ITEMS_SetItemCell(D2UnitStrc*, unsigned char); // 0x00628320
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc*, D2UnitStrc*); // 0x0063C150
int __fastcall sub_6FC45B30(D2GameStrc*, D2UnitStrc*, unsigned short, int, int*); // 0x00560CD0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055EEA0
int __stdcall D2COMMON_10254_Return0(D2InventoryStrc*, int); // 0x0063BE30

inline D2ItemStatCostTxt* GetStatCost(int nStat) {
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

// 0x0055B800
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nLayerStatId, int nPreviousValue, int nNewValue)
{
    if (!pGame || !pUnit) return;
    int nStat = (unsigned int)nLayerStatId >> 16;
    D2ItemStatCostTxt* pCost = GetStatCost(nStat);
    if (!pCost) return;
    int nItemGUID = 0;
    if (pOther) nItemGUID = pOther->dwUnitId;
    if (pCost->wItemEvent[0] > 0) {
        if (nNewValue) {
            if (!SUNITEVENT_GetEvent(pGame, pUnit, 2, nLayerStatId, nLayerStatId)) {
                sub_6FD156A0(pGame, pUnit, pCost->wItemEvent[0], nLayerStatId, 0, pCost->wItemEventFunc[0], 2, nLayerStatId);
                short nSecondEvent = pCost->wItemEvent[1];
                if (nSecondEvent > 0) sub_6FD156A0(pGame, pUnit, nSecondEvent, nLayerStatId, 0, pCost->wItemEventFunc[1], 2, nLayerStatId);
            }
        } else SUNITEVENT_Unregister(pGame, pUnit, 2, nLayerStatId);
    }
    switch (nStat) {
    case 7:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 6, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 6, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
                if (pUnit->dwUnitType == 1) {
                    D2MonStatsTxt* pMonStats = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
                    if (pMonStats && pMonStats->nDamageRegen) STATLIST_SetUnitStat(pUnit, 74, ((nNewValue >> 8) * pMonStats->nDamageRegen) >> 4, 0);
                }
            }
        }
        break;
    case 9:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 8, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 8, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 11:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, 10, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, 10, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 97:
    case 107:
        {
            int nSkillId = (unsigned short)nLayerStatId;
            D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
            if (nSkillId && (nStat != 107 || pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == pSkills->nCharClass)) {
                D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                if (!pSkill) {
                    pSkill = SKILLS_AddSkill(pUnit, nSkillId);
                    SKILLS_AssignSkill(pUnit, nSkillId, 0, 0, ".\\ITEMS\\ItemMode.cpp", 249);
                    D2ClientStrc* pClient;
                    if (pUnit->dwUnitType == 0) pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 253);
                    else pClient = 0;
                    D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(pClient, pUnit, nSkillId, 0, 0);
                }
                SKILLS_RefreshSkill(pUnit, nSkillId);
                sub_0056BD90_RefreshPetMaxForSkill(pGame, pUnit, nSkillId);
                if (nNewValue <= 0) {
                    nNewValue = 1;
                    if (SKILLS_GetSkillLevel(pUnit, pSkill, 0)) {
                        nNewValue = 0;
                        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1)) return;
                    }
                    if (UNITS_GetLeftSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 1, 0, -1);
                    if (UNITS_GetRightSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                    if (nNewValue) SKILLS_AssignSkill(pUnit, nSkillId, 0, 1, ".\\ITEMS\\ItemMode.cpp", 282);
                }
            }
        }
        break;
    case 83:
        if (pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == (unsigned short)nLayerStatId)
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 304);
            if (nType == 0 && nClass == (unsigned short)nLayerStatId)
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 188:
        if (pUnit->dwUnitType == 0 && (!pUnit ? -1 : pUnit->dwClassId) == ((unsigned short)nLayerStatId >> 3))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 325);
            if (nType == 0 && nClass == ((unsigned short)nLayerStatId >> 3))
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 126:
    case 127:
        D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        break;
    case 151:
        {
            int nAuraSkill = (unsigned short)nLayerStatId;
            if (nNewValue) SKILLITEM_ActivateAura(pGame, pUnit, nItemGUID, nAuraSkill, nNewValue);
            else SKILLITEM_DeactivateAura(pGame, pUnit, nItemGUID, nAuraSkill);
        }
        break;
    case 204:
        if (pOther) {
            int nShift = sgptDataTables->nStuff;
            int nLevel = sgptDataTables->nShiftedStuff;
            int nLayer = (unsigned short)nLayerStatId;
            int nSkillId = nLayer >> nShift;
            nLevel &= nLayer;
            int nCharges = STATLIST_UnitGetStatValue(pOther, nStat, nLayer) & 255;
            if (nCharges > 0 && STATLIST_GetOwner(pOther, 0) == pUnit) {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, nCharges, 0);
            } else {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, 0, 1);
                sub_0056BD90_RefreshPetMaxForSkill(pGame, pUnit, nSkillId);
            }
        }
        break;
    case 98:
        {
            int nState = (unsigned short)nLayerStatId;
            if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount) {
                int bState = STATES_CheckState(pUnit, nState);
                if (nNewValue) {
                    if (bState) return;
                    sub_6FD11C90(pUnit, nState, 0);
                    STATES_ToggleState(pUnit, nState, 1);
                } else {
                    if (!bState) return;
                    sub_6FD11C90(pUnit, nState, 1);
                    STATES_ToggleState(pUnit, nState, 0);
                }
                STATES_ToggleGfxStateFlag(pUnit, nState, 1);
            }
        }
        break;
    }
}

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline D2InventoryStrc* GetUnitInventory(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }
    return pInventory;
}

// 0x0055C2C0
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4)
{
    if (!pUnit || sub_0044BE50(pItem) != 4)
    {
        return;
    }

    const int v_dwUnitType_74 = *(int *)&pUnit->dwUnitType;
    if (v_dwUnitType_74 == 0 && STATES_CheckState(pUnit, 7))
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        if (pUnit->dwUnitType != 4)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        const int v_dwGemOffset_93 = *(int *)&pItemsTxtRecord->dwGemOffset;
        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(v_dwGemOffset_93);
        if (!pGemsTxtRecord)
        {
            return;
        }

        sub_0065FEC0_ItemApplyProps(2, 0, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        if (pUnit->dwUnitType != 4)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord((*(int *)&pItemsTxtRecord->dwGemOffset));
        if (!pGemsTxtRecord)
        {
            return;
        }

        sub_0065FEC0_ItemApplyProps(5, pUnit, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    sub_0055C270_OnItemToBelt(pUnit, pItem);

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    D2UnitStrc* pLeftHandWeapon = 0;
    if (nUnitType == 0)
    {
        pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pUnit));
    }

    int bType = 1;
    if (UNITS_CanDualWield(pUnit))
    {
        if (pItem != pLeftHandWeapon && ITEMSIsA(pItem, 0x2D))
        {
            bType = 0;
        }

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2B8, szItemModeCpp) && !a4)
        {
            {
                if (pUnit->pDynamicPath)
                {
                    UnitUpdateAnimRateAndVel(pUnit, szItemModeCpp, 0x2CF);
                }
                return;
            }
        }
    }
    else
    {
        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2C1, szItemModeCpp) && !a4)
        {
            goto skip_merge;
        }
    }

    STATLIST_MergeStatLists(pUnit, pItem, bType);
skip_merge:

    if (pUnit->pDynamicPath)
    {
        UnitUpdateAnimRateAndVel(pUnit, szItemModeCpp, 0x2CF);
    }
}

// 0x0055C730
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals)
{
    if (!pTarget || !pItem || pItem->dwUnitType != 4)
        return;
    if (pTarget->dwUnitType == 0 && STATES_CheckState(pTarget, 7))
        return;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 9, pItem->dwUnitId);
    if (pTarget != STATLIST_GetOwner(pItem, 0))
        return;
    if (ITEMS_GetItemQuality(pItem) == 5)
        ITEMS_UpdateSets(pTarget, pItem, 1, 0);
    const int nTargetType = pTarget ? pTarget->dwUnitType : 6;
    D2UnitStrc* pLeftWeapon = 0;
    if (nTargetType == 0)
        pLeftWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pTarget));
    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x3D8, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        STATLIST_ExpireUnitStatlist(pTarget, pItem);
    if (UNITS_CanDualWield(pTarget) && pLeftWeapon && ITEMSIsA(pItem, 0x2D) && pLeftWeapon != pItem)
    {
        if (!ITEMS_CheckItemFlag(pLeftWeapon, 0x100, 0x3E6, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        {
            if (STATLIST_GetOwner(pLeftWeapon, 0))
                STATLIST_MergeStatLists(pTarget, pLeftWeapon, 1);
        }
    }
    sub_0055C6E0_OnItemToCursor(pTarget, pItem);
    if (bUpdateVitals)
        sub_006275B0_UpdateVitals(pTarget);
}

int __fastcall sub_0055CA00_MatchFieldPair(D2ItemsTxt* pRecord1, D2ItemsTxt* pRecord2, int nValue1, int nValue2)
{
    if (pRecord1->dwCode == nValue1 && pRecord2->dwCode == nValue2)
    {
        return 1;
    }

    if (pRecord1->dwCode == nValue2 && pRecord2->dwCode == nValue1)
    {
        return 1;
    }

    return 0;
}

static __forceinline int ITEMS_IsItemInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_ITEM;
}

static __forceinline D2UniqueItemsTxt* DATATBLS_GetUniqueItemsTxtRecordInline(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }
    return 0;
}

static __forceinline unsigned char GetQuestIndex(const D2ItemsTxt* pRecord)
{
    unsigned char nQuest = 0;
    if (pRecord)
    {
        nQuest = pRecord->nQuest;
    }
    return nQuest;
}

// 0x0055CA40
static int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem)
{
    int nUniqueId = -1;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7])
        {
            nUniqueId = pUniqueItemsTxtRecord->wId;
        }
    }

    while (pPreviousItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pPreviousItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pPreviousItem);
        if (pCheckedItem == pItem)
        {
            break;
        }

        if (!ITEMS_IsItemInline(pCheckedItem))
        {
            pPreviousItem = pNext;
            continue;
        }

        if (nUniqueId >= 0 && ITEMS_GetInvPage(pCheckedItem) != 1 && ITEMS_GetItemQuality(pCheckedItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pCheckedItem) == nUniqueId)
        {
            return 1;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCheckedItem->dwClassId);
        if (pItemsTxtRecord->nQuest && ITEMS_GetInvPage(pCheckedItem) != 1 && GetQuestIndex(pItemsTxtRecord) == pItemsTxtRecordArg->nQuest)
        {
            if (pItemsTxtRecordArg->dwCode == pItemsTxtRecord->dwCode
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 43j', ' 43g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' skb', ' dkb')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 33d', ' 33g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' fsm')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' piv')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' 1fq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rhq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' yeq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rbq'))
            {
                return 1;
            }
        }

        pPreviousItem = pNext;
    }

    return 0;
}

int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pPreviousItem = INVENTORY_GetFirstItem(pInventory);
    if (!pInventory)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7] && sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
        {
            return 0;
        }
    }

    if (!pItemsTxtRecord->nQuest)
    {
        return 1;
    }

    const unsigned int nItemCode = pItemsTxtRecord->dwCode;
    if (nItemCode == ' ssa')
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 43j')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED))
        {
            return 0;
        }
    }
    else if (nItemCode == ' zyx')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 33g')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 2rt')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }
    }

    const int nQuest = pItemsTxtRecord->nQuest;
    if (nQuest - 1 == QUESTSTATEFLAG_A2Q1)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' xob')
        {
            return 0;
        }
    }
    else if (nQuest - 1 == QUESTSTATEFLAG_A1Q4)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' gel')
        {
            return 0;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            if (pItemsTxtRecord->nQuest == gQuestItemPairs_00731FEC[i].nItemQuest)
            {
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
                if (QUESTRECORD_GetQuestState(pQuestFlags, gQuestItemPairs_00731FEC[i].nQuestFlag, QFLAG_REWARDGRANTED))
                {
                    return 0;
                }
            }
        }
    }

    if (sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
    {
        return 0;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pUnit->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pPlayer && pPlayer->pInventory)
        {
            D2UnitStrc* pFirstItem = INVENTORY_GetFirstItem(pPlayer->pInventory);
            if (pFirstItem && sub_6FC428F0(pItem, pItemsTxtRecord, pFirstItem))
            {
                return 0;
            }
        }
    }

    return 1;
}

// build: context sub_0055BFF0_GetBookSkillId
static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
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

// build: context sub_0055C070_AddBookScrollSkillQuantity
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

// 0x0055D0D0
static int __stdcall sub_0055D0D0_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pStackItem = 0;
    int nCounter = 0;
    int nQuantity1, nQuantity2;

    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) <= 0) goto NotStacked;
    do
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
            nQuantity1 = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            nQuantity2 = STATLIST_UnitGetStatValue(pStackItem, 0x46, 0);
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
            else goto MergeStack;
        }
    } while (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0);

    if (!nCounter)
    {
NotStacked:
        return 0;
    }

    D2_ASSERT(0, 0x606);
    return 0;
MergeStack:
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

// build: context sub_0055D370_TryMergeBookQuantity
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

// build: context sub_0055FFA0_AddScrollToBook
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

// build: context sub_00560020_PickupStackable
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

// build: context sub_J07_Emit_00560020
int __fastcall sub_J07_Emit_00560020(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    return sub_00560020_PickupStackable(pGame, pUnit, pItem);
}

// 0x0055C470
static void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
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
static void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
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
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
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
static void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
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

// 0x0055D970
static void __stdcall sub_0055D970_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        return;
    }

    sub_0063D1D0_InventoryItemCall(pInventory, pItem);

    if (UNITS_GetAnimOrSeqMode(pItem) == 1)
    {
        sITEMSAddStatsList(pGame, pItem, pUnit, 1);
        return;
    }
    if (UNITS_GetAnimOrSeqMode(pItem) == 0 && ITEMS_IsCharmUsable(pItem, pUnit))
    {
        sITEMSAddStatsList(pGame, pItem, pUnit, 1);
    }
}

// build: context sub_0055F900_EquipItemRefresh
void __fastcall sub_0055F900_EquipItemRefresh(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }

    ITEMS_SetItemFlag(pItem, 0x200, 1);
    ITEMS_SetItemFlag(pItem, 0x100, 0);
    if (pInventory)
    {
        sub_0055D970_UpdateEquippedItemStats(pGame, pItem, pUnit);
        sub_0055DBC0(pGame, pUnit, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    if (nMaxDurability > 0)
    {
        STATLIST_SetUnitStat(pItem, 0x48, nMaxDurability, 0);
        if (pUnit)
        {
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x193C), pItem, 1, 0x48, nMaxDurability, 0);
        }
    }

    ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    if (pUnit)
    {
        sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    }
}

// 0x0055E000
static __declspec(noinline) void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

// 0x0055E050
static __declspec(noinline) int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMSIsA(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

// build: context sub_0055E0D0_DecrementBook
static __declspec(noinline) void __stdcall sub_0055E0D0_DecrementBook(D2UnitStrc* player, int skillId)
{
    D2SkillStrc* skill = SKILLS_GetSkillById(player, skillId, -1);
    D2_ASSERT(skill, 0xFC4);
    int quantity = SKILLS_GetQuantity(skill) - 1;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(player) == skill) D2GAME_AssignSkill_6FD13800(player, 0, 0, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id = !player ? -1 : player->dwUnitId;
    int type = !player ? 6 : player->dwUnitType;
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(player, ".\\ITEMS\\ItemMode.cpp", 0xFC2), type, id, skillId, quantity);
}

static __forceinline D2InventoryStrc* UNITS_GetInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x0055E170
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status)
{
    D2_ASSERT(ptGame, 0x105A);
    D2_ASSERT(hUnit, 0x105B);
    *status = 0;
    sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1060);
    D2UnitStrc* item = SUNIT_GetServerUnit(ptGame, 4, itemId);
    if (!item) { *status = 1; return 0; }
    if (item->dwUnitType != 4 || INVENTORY_GetCursorItem(UNITS_GetInventory(hUnit))) return 0;
    if (item->dwAnimMode || !sub_00628C20_IsUsable(item)) { *status = 1; return 0; }
    if (ITEMS_GetItemType(item) == 18 && STATLIST_UnitGetStatValue(item, 70, 0) <= 0) return 0;
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1)) return 0;
    if (SKILLITEM_pSpell_Handler(ptGame, hUnit, item, item, x, y)) {
        if (ITEMS_GetItemType(item) == 18) {
            int skillId = sub_0055E050_GetBookSkillIdChecked(item);
            if (skillId != -1 && STATLIST_UnitGetStatValue(item, 70, 0) > 0) {
            STATLIST_AddUnitStat(item, 70, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10B2), item, 1, 70, STATLIST_UnitGetStatValue(item, 70, 0), 0);
            int id = item->dwUnitId;
            int type = item->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10B3), 0x7C, type, id);
            sub_0055E0D0_DecrementBook(hUnit, skillId);
            return 1;
            }
        } else {
        int skillId = sub_0055E050_GetBookSkillIdChecked(item);
        if (skillId != -1) {
            D2SkillStrc* skill = SKILLS_GetSkillById(hUnit, skillId, -1);
            if (skill) {
                int quantity = SKILLS_GetQuantity(skill) - 1;
                if (quantity <= 0) {
                    if (UNITS_GetRightSkill(hUnit) == skill) D2GAME_AssignSkill_6FD13800(hUnit, 0, 0, -1);
                    quantity = 0;
                }
                SKILLS_SetQuantity(skill, quantity);
                int id = hUnit->dwUnitId;
                int type = hUnit->dwUnitType;
                D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10C6), type, id, skillId, quantity);
            }
        }
        sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10C9);
        sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, item);
        }
        return 1;
    }
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(sub_00623C60(item));
    D2BitBufferStrc* flags = sub_00543520(ptGame, hUnit);
    if (record->dwCode == 0x20737361) {
        sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10D5);
        if (QUESTRECORD_GetQuestState(flags, 9, 5)) {
            QUESTRECORD_ClearQuestState(flags, 9, 5);
            STATLIST_AddUnitStat(hUnit, 5, 1, 0);
            QUESTS_SendLogUpdate(hUnit, 8);
            sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x207A7978) {
        sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10E5);
        if (QUESTRECORD_GetQuestState(flags, 20, 5)) {
            QUESTRECORD_ClearQuestState(flags, 20, 5);
            STATLIST_AddUnitStat(hUnit, 7, 0x1400, 0);
            QUESTS_SendLogUpdate(hUnit, 18);
            sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x20327274) {
        sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10F8);
        if (QUESTRECORD_GetQuestState(flags, 37, 8) && !QUESTRECORD_GetQuestState(flags, 37, 7)) {
            QUESTRECORD_SetQuestState(flags, 37, 7);
            ACT5Q3_ApplyResistanceReward(ptGame, hUnit);
            QUESTS_SendLogUpdate(hUnit, 33);
            sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x20616F74) {
        sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x110D);
        sub_00570360_ResetSkills(ptGame, hUnit);
        sub_00570C80_ResetStats(ptGame, hUnit);
        sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, item);
        SUNIT_AttachSound(hUnit, 2, hUnit);
        return 1;
    }
    return 0;
}

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

__forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x0055F2D0
int __fastcall sub_0055F2D0_CheckBodyLocation(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
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

// 0x00560200
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int bAutoPosition, int bNotify, D2InventoryStrc* pInventory)
{
    if (!pGame || !pPlayer) return 0;
    sub_0055BF50_ClearTargetingFlags(pPlayer, szItemModeCpp, 0x87B);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nUnitId);
    if (!pItem) return 0;
    if (pItem->dwUnitType != 4) return 0;
    if (pItem->dwAnimMode != 4) return 0;
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (!pInventory)
    {
        pInventory = pPlayer->pInventory;
        if (!pInventory) return 0;
    }
    int bTrade = 0;
    int bClearCursor = 1;
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, pGame->bExpansion);
    if (pPlayer->dwUnitType == 0)
    {
        switch (nPage)
        {
        case 1: bClearCursor = 0; break;
        case 2: bTrade = 1; break;
        }
    }
    if (bAutoPosition)
    {
        if (!INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, nInventoryRecordId, 0, nPage, szFile, nLine)) goto failed;
    }
    else
    {
        if (nX < 0) nX = 0;
        if (nY < 0) nY = 0;
        if (!INVENTORY_PlaceItemAtInventoryPage(pInventory, pItem, nX, nY, nInventoryRecordId, 0, nPage)) goto failed;
    }
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
    failed:
        return 0;
    }
    if (ITEMS_GetInvPage(pItem) != 4) sub_0055C270_OnItemToBelt(pPlayer, pItem);
    pItem->dwFlags &= ~2u;
    if (ITEMS_IsCharmUsable(pItem, pPlayer)) sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
    if (bClearCursor) INVENTORY_SetCursorItem(pInventory, 0);
    UNITS_ChangeAnimMode(pItem, 0);
    if (bNotify)
    {
        ITEMS_SetItemCMDFlag(pItem, 2, 1);
        if (sub_0055F590_CheckItem(pItem, szItemModeCpp, 0x8EA)) ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x8EE, szItemModeCpp)) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    }
    if (bTrade == 1) PLRTRADE_AddItemToTrade(pGame, pPlayer, pItem);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_0055DBC0(pGame, pPlayer, 0);
        UNITS_RefreshInventory(pPlayer, 1);
    }
    return 1;
}

// 0x00560F00
int __fastcall ITEMMODE_SwapCursorAndBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pFailed)
{
 D2_ASSERT(ptGame, 0xca7);
 D2_ASSERT(pUnit, 0xca8);
 if (nBodyLoc >= 11) return 0;
 *pFailed = 0;
 sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0xcb0);
 D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
 if (!pItem) { *pFailed = 0; return 0; }
 if (pItem->dwUnitType != 4) return 0;
 if (pItem->dwAnimMode != 4) { *pFailed = 0; return 0; }
 const int nLoc = nBodyLoc;
 if (D2Common_10299(pUnit, nLoc, pItem, bSkipRequirementCheck) != 5) { *pFailed = 0; return 0; }
 D2InventoryStrc* pInventory = pUnit->pInventory;
 D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
 if (pWeapon) UNITS_SetWeaponGUID(pUnit, pWeapon);
 D2UnitStrc* hBodyItem = INVENTORY_GetItemFromBodyLoc(pInventory, nLoc);
 INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hBodyItem, nLoc);
 if (!hBodyItem) goto fail;
 if (hBodyItem->dwAnimMode != 1)
 {
fail:
  *pFailed = 1;
  return 0;
 }
 D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hBodyItem, pUnit, 0, 1);
 if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
 {
  sITEMSAddStatsList(ptGame, hBodyItem, pUnit, 0);
  SUNIT_AttachSound(pUnit, 20, 0);
  return 0;
 }
 if (ITEMS_GetItemType(pItem) == 19) ITEMMODE_MoveExcessBeltItems(ptGame, pUnit, pItem);
 sub_0062A360(pUnit, hBodyItem);
 INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hBodyItem);
 D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, hBodyItem);
 D2_ASSERT(pRemoved, 0xcee);
 D2_ASSERT(hBodyItem == pRemoved, 0xcef);
 sub_0063BE30(pInventory, nLoc);
 INVENTORY_SetCursorItem(pInventory, hBodyItem);
 if (hBodyItem) hBodyItem->dwFlags &= ~2;
 UNITS_ChangeAnimMode(hBodyItem, 4);
 ITEMS_SetItemFlag(hBodyItem, 0x80, 1);
 ITEMS_SetItemCMDFlag(hBodyItem, 0x20, 1);
 ITEMS_SetItemFlag(hBodyItem, 1, 1);
 if (ITEMS_CheckItemFlag(hBodyItem, 0x4000, 0xcf7, szItemModeCpp)) ITEMS_SetItemFlag(hBodyItem, 0x4000, 0);
 INVENTORY_AddItemToTradeInventory(pInventory, hBodyItem);
 if (INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nLoc))
 {
  if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
  {
    ITEMS_SetBodyLocation(pItem, nBodyLoc);
    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
    sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
    pItem->dwFlags &= ~2;
    UNITS_ChangeAnimMode(pItem, 1);
    ITEMS_SetInvPage(pItem, 255);
    ITEMS_SetItemFlag(pItem, 0x40, 1);
    ITEMS_SetItemFlag(pItem, 1, 1);
    ITEMS_SetItemCMDFlag(pItem, 0x20, 1);
    ITEMS_SetItemFlag(pItem, 1, 1);
    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xd12, szItemModeCpp)) ITEMS_SetItemFlag(pItem, 0x4000, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    sub_0055DBC0(ptGame, pUnit, 0);
    return 1;
  }
  *pFailed = 1;
  return 0;
 }
 *pFailed = 1;
 return 0;
}

static __forceinline int UNIT_GetMode(D2UnitStrc* pUnit) { return !pUnit ? 0 : pUnit->dwAnimMode; }

// 0x00561220
int __fastcall sub_00561220_SwapDualWieldedItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int* pFailure)
{
    D2_ASSERT(ptGame, 0xD38);
    D2_ASSERT(pUnit, 0xD39);
    *pFailure = 0;
    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem || pItem->dwUnitType != 4 || pItem->dwAnimMode != 4)
        return 0;
    if (D2Common_10299(pUnit, nBodyLoc, pItem, 0) != 7)
        return 0;
    if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        return 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xD60);
    int nRecord = UNITS_GetInventoryRecordId(pUnit, 0, ptGame->bExpansion);
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pOther;
    int nOtherBodyLoc;
    if (nBodyLoc == 5)
    {
        pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        nOtherBodyLoc = 4;
    }
    else
    {
        pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        nOtherBodyLoc = 5;
    }
    if (!sub_0063CB00_CheckPlacement(pInventory, pItem, nOtherBodyLoc, nRecord))
    {
        *pFailure = 1;
        return 0;
    }
    D2_ASSERT(pOther, 0xD73);
    if (UNIT_GetMode(pOther) != 1)
    {
        *pFailure = 1;
        return 0;
    }
    sub_0062A360(pUnit, pOther);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pOther);
    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pOther);
    D2_ASSERT(pRemoved, 0xD7D);
    D2_ASSERT(pOther == pRemoved, 0xD7E);
    sub_0063BE30(pInventory, nOtherBodyLoc);
    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pRemoved, pUnit, 0, 1);
    if (sub_0063B950_PlaceItem(pInventory, pRemoved, nRecord, 0, 0, ".\\ITEMS\\ItemMode.cpp", 0xD86))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pRemoved, 1))
        {
        ITEMS_SetInvPage(pRemoved, 0);
        pRemoved->dwFlags &= ~2;
        INVENTORY_SetCursorItem(pInventory, 0);
        UNITS_ChangeAnimMode(pRemoved, 0);
        if (sub_0055F590_CheckItem(pRemoved, ".\\ITEMS\\ItemMode.cpp", 0xD8D))
            ITEMS_SetItemFlag(pRemoved, 1, 1);
        if (ITEMS_CheckItemFlag(pRemoved, 0x4000, 0xD90, ".\\ITEMS\\ItemMode.cpp"))
            ITEMS_SetItemFlag(pRemoved, 0x4000, 0);
        ITEMS_SetItemCMDFlag(pRemoved, 0x4000, 1);
        ITEMS_SetItemFlag(pRemoved, 1, 1);
        INVENTORY_AddItemToTradeInventory(pInventory, pRemoved);
        }
        else
        {
            *pFailure = 1;
            return 0;
        }
    }
    D2UnitStrc* pEquipped = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
    D2_ASSERT(pEquipped, 0xD9F);
    if (pEquipped->dwAnimMode != 1)
    {
        *pFailure = 1;
        return 0;
    }
    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pEquipped, pUnit, 0, 1);
    if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
    {
        sITEMSAddStatsList(ptGame, pEquipped, pUnit, 0);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_0055FB10_ReturnItem(ptGame, pUnit, pItem);
        SUNIT_AttachSound(pUnit, 20, 0);
        UNITS_RefreshInventory(pUnit, 1);
        return 0;
    }
    sub_0062A360(pUnit, pEquipped);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pEquipped);
    D2UnitStrc* pRemovedEquipped = INVENTORY_RemoveItemFromInventory(pInventory, pEquipped);
    D2_ASSERT(pRemovedEquipped, 0xDB6);
    D2_ASSERT(pEquipped == pRemovedEquipped, 0xDB7);
    sub_0063BE30(pInventory, nBodyLoc);
    INVENTORY_SetCursorItem(pInventory, pEquipped);
    pEquipped->dwFlags &= ~2;
    UNITS_ChangeAnimMode(pEquipped, 4);
    ITEMS_SetItemCMDFlag(pEquipped, 0x10, 1);
    ITEMS_SetItemFlag(pEquipped, 1, 1);
    if (ITEMS_CheckItemFlag(pEquipped, 0x4000, 0xDBE, ".\\ITEMS\\ItemMode.cpp"))
        ITEMS_SetItemFlag(pEquipped, 0x4000, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pEquipped);
    if (sub_0063BDB0(pInventory, pItem, nBodyLoc))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
        {
        ITEMS_SetBodyLocation(pItem, nBodyLoc);
        sub_0063D1D0_InventoryItemCall(pInventory, pItem);
        sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
        pItem->dwFlags &= ~2;
        UNITS_ChangeAnimMode(pItem, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        ITEMS_SetItemFlag(pItem, 8, 1);
        ITEMS_SetItemCMDFlag(pItem, 8, 1);
        ITEMS_SetItemFlag(pItem, 1, 1);
        if (sub_0055F590_CheckItem(pItem, ".\\ITEMS\\ItemMode.cpp", 0xDD5))
            ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xDD8, ".\\ITEMS\\ItemMode.cpp"))
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
        sub_0055DBC0(ptGame, pUnit, 0);
        return 1;
        }
        *pFailure = 1;
        return 0;
    }
    *pFailure = 1;
    return 0;
}

static __forceinline int SkillUsable(D2UnitStrc* player, D2SkillStrc* skill)
{
    if (!skill) return 0;
    switch (SKILLS_GetUseState(player, skill)) { case 2: case 7: return 0; }
    return 1;
}

// 0x005616A0
int __fastcall sub_005616A0_SwapWeapons(D2GameStrc* ptGame, D2UnitStrc* hUnit, int* status)
{
    int i;
    SwapEntry entries[4] = { {4,0,11,4}, {5,0,12,4}, {11,0,4,3}, {12,0,5,3} };
    D2_ASSERT(ptGame, 0xE1E);
    D2_ASSERT(hUnit, 0xE1F);
    *status = 0;
    sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0xE24);
    D2InventoryStrc* inventory = hUnit->pInventory;
    int leftId, leftOwner, rightId, rightOwner;
    UNITS_GetSwitchLeftSkillDataResetLeftSkill(hUnit, &leftId, &leftOwner);
    UNITS_GetSwitchRightSkillDataResetRightSkill(hUnit, &rightId, &rightOwner);
    UNITS_InitSwitchRightSkill(hUnit);
    UNITS_InitSwitchLeftSkill(hUnit);
    i=0;
    if (i<4)
    {
        do
        {
            entries[i].item = INVENTORY_GetItemFromBodyLoc(inventory, entries[i].from);
            if (entries[i].item) {
                INVENTORY_GetSecondWieldingWeapon(hUnit, inventory, &entries[i].item, entries[i].from);
                if (!entries[i].item || entries[i].item->dwAnimMode != 1) { *status=1; return 0; }
            }
            ++i;
        } while (i<4);
    }
    if (entries[0].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, entries[0].item, hUnit, 0, 1);
    if (entries[1].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, entries[1].item, hUnit, 0, 1);
    SwapEntry* entry = entries;
    for (i=0; i<4; ++i, ++entry) {
        D2UnitStrc* item = entry->item;
        if (!item) continue;
        if (i<2) INVENTORY_UpdateWeaponGUIDOnRemoval(inventory, item);
        D2UnitStrc* removed = INVENTORY_RemoveItemFromInventory(inventory, entry->item);
        if (!removed || removed != entry->item) { *status=1; return 0; }
        sub_0063BE30_Return(inventory, entry->from);
        ITEMS_SetInvPage(removed, 255);
        ITEMS_SetItemCMDFlag(removed, 0x200000, 1);
        ITEMS_SetItemFlag(removed, 1, 1);
        if (ITEMS_CheckItemFlag(removed, 0x4000, 0xE5B, szItemModeCpp)) ITEMS_SetItemFlag(removed, 0x4000, 0);
        INVENTORY_AddItemToTradeInventory(inventory, removed);
    }
    for (i=0; i<4; ++i) {
        D2UnitStrc* item = entries[i].item;
        if (item) {
            if (!INVENTORY_PlaceItemInBodyLoc(inventory, item, entries[i].to)) { *status=1; return 0; }
            if (!INVENTORY_PlaceItemInSocket(inventory, item, entries[i].mode)) { *status=1; return 0; }
            ITEMS_SetBodyLocation(item, entries[i].to);
            if (entries[i].to == 4 || entries[i].to == 5) {
                sub_0063D1D0_InventoryItemCall(inventory, item);
                sITEMSAddStatsList(ptGame, item, hUnit, 0);
                ITEMS_SetItemFlag(item, 64, 1);
            } else {
                ITEMS_SetItemFlag(item, 128, 1);
            }
            item->dwFlags &= ~2;
            UNITS_ChangeAnimMode(item, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            ITEMS_SetItemCMDFlag(item, 0x200000, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            if (i<2) sub_0055C5C0_RefreshSkillsForEquippedWeapons(hUnit);
        }
    }
    sub_0055DBC0(ptGame, hUnit, 0);
    D2SkillStrc* leftSkill = SKILLS_GetSkillById(hUnit, leftId, leftOwner);
    D2SkillStrc* rightSkill = SKILLS_GetSkillById(hUnit, rightId, rightOwner);
    D2ClientStrc* hClient = UnitGetClient(hUnit, szItemModeCpp, 0xE93);
    D2_ASSERT(hClient, 0xE94);
    sub_00539230_SetWeaponSwitch(hClient, !CLIENTS_GetWeaponSwitch(hClient));
    D2GAME_PACKETS_SendPacket0x97_6FC3FB60(UnitGetClient(hUnit, szItemModeCpp, 0xE98));
    if (SkillUsable(hUnit, leftSkill)) {
        D2GAME_AssignSkill_6FD13800(hUnit, 1, leftId, leftOwner);
        sub_00571C60_SendSkill(hUnit, 1, leftId, leftOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetLeftSkill(hUnit);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEA2); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        sub_00571C60_SendSkill(hUnit, 1, id, owner);
    }
    if (SkillUsable(hUnit, rightSkill)) {
        D2GAME_AssignSkill_6FD13800(hUnit, 0, rightId, rightOwner);
        sub_00571C60_SendSkill(hUnit, 0, rightId, rightOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetRightSkill(hUnit);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEB0); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        sub_00571C60_SendSkill(hUnit, 0, id, owner);
    }
    return 1;
}

// 0x0055E0D0
static void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
        if (nQuantity <= 0)
        {
            if (UNITS_GetRightSkill(pUnit) == pSkill)
                D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
            nQuantity = 0;
        }
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, szItemModeCpp, 0xFC2), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFC4);
        exit(-1);
    }
}

// 0x00561ED0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xFCF);
    D2_ASSERT(hUnit, 0xFD0);
    D2UnitStrc* pTargetItem = SUNIT_GetServerUnit(ptGame, 4, nTargetGUID);
    D2UnitStrc* pUseItem = SUNIT_GetServerUnit(ptGame, 4, nUseItemGUID);
    *pItemStatus = 0;
    if (!pUseItem)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (!pTargetItem || pTargetItem == pUseItem)
    {
        sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0xFDD);
        return 0;
    }
    if ((!pUseItem ? 0 : pUseItem->dwAnimMode) == 2 && !ITEMSIsA(pUseItem, 0x16))
    {
        *pItemStatus = 1;
        return 0;
    }
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1))
    {
        *pItemStatus = 0;
        return 0;
    }
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != 4 || pUseItem->dwUnitType != 4)
        return 0;
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != (!pUseItem ? 6 : pUseItem->dwUnitType))
    {
        sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1004);
        return 0;
    }
    D2InventoryStrc* pInventory = hUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
        return 0;
    const int nTargetAnimMode = pTargetItem->dwAnimMode;
    const int nUseItemAnimMode = pUseItem->dwAnimMode;
    if (nTargetAnimMode != 0 && nTargetAnimMode != 1)
    {
        if (nUseItemAnimMode == 2)
        {
            sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1010);
            sub_00561E70_RemoveFromBelt(ptGame, hUnit, pUseItem);
        }
        else if (nUseItemAnimMode == 0)
        {
            if (ITEMS_GetItemType(pUseItem) == 0x12)
            {
                int nQuantity = STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) - 1;
                if (nQuantity < 0)
                    nQuantity = 0;
                STATLIST_SetUnitStat(pUseItem, 0x46, nQuantity, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, szItemModeCpp, 0x1019), pUseItem, 1, 0x46, nQuantity, 0);
            }
        }
        else
        {
            *pItemStatus = 1;
        }
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == 0x12 && STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) <= 0)
    {
        sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1023);
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x1024), 0x7C, nUnitType, nUnitGUID);
        return 0;
    }
    if (!SKILLITEM_pSpell_Handler(ptGame, hUnit, pUseItem, pTargetItem, 0, 0))
        goto Success;
    if (nUseItemAnimMode == 2)
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1)
        {
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
            sub_00561E70_RemoveFromBelt(ptGame, hUnit, pUseItem);
            sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1034);
            goto Success;
        }
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x1032), 0x7C, nUnitType, nUnitGUID);
        sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1034);
        goto Success;
    }
    if (nUseItemAnimMode)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == 0x12)
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1 && STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) > 0)
        {
            STATLIST_AddUnitStat(pUseItem, 0x46, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, szItemModeCpp, 0x103C), pUseItem, 1, 0x46, STATLIST_UnitGetStatValue(pUseItem, 0x46, 0), 0);
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
            const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
            const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x104A), 0x7C, nUnitType, nUnitGUID);
            sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x104C);
            return 1;
        }
    }
    else
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1)
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
    }
    sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, pUseItem);
    sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 0x104C);
Success:
    return 1;
}

// 0x005628C0
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nCubeGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 5287);
    D2_ASSERT(hUnit, 5288);

    sub_0055BF50_ClearTargetingFlags(hUnit, szItemModeCpp, 5291);

    *pItemStatus = 0;
    D2UnitStrc* pCube = SUNIT_GetServerUnit(ptGame, 4, nCubeGUID);
    if (!pCube)
    {
        *pItemStatus = 1;
        return 0;
    }
    if ((!pCube ? 0 : pCube->dwAnimMode) || ITEMS_GetBaseCode(pCube) != 0x20786F62)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1) && ITEMS_GetInvPage(pCube))
    {
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 3 && pItem->dwAnimMode != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    if ((!pCube ? 6 : pCube->dwUnitType) == 4)
    {
        if (!pCube ? 0 : pCube->dwAnimMode)
        {
            *pItemStatus = 1;
            return 0;
        }

        ITEMS_SetInvPage(pItem, 3);
        D2GAME_PlaceItem_6FC44410(szItemModeCpp, 5356, ptGame, hUnit, !pItem ? -1 : pItem->dwUnitId, 0, 0, 1, 1, 0);
        return 1;
    }

    return 0;
}

static __forceinline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x00563470
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pUnit)
        return;
    if (UNIT_TypeOrInvalid(pItem) != 4)
        return;
    D2UnitStrc* pValidItem = pItem;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;
    switch (pValidItem->dwAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pValidItem, ITEMS_GetInvPage(pValidItem));
        if (UNIT_TypeOrInvalid(pUnit) == 0)
        {
            D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1A75);
            if (pClient)
            {
                int nFlags = 0;
                ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
                D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pValidItem, nFlags);
            }
        }
        D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pValidItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pValidItem);
        int nResult;
        sub_6FC45B30(pGame, pUnit, nBodyLoc, 1, &nResult);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pUnit, pValidItem);
        break;
    }
}

// 0x00563D20
int __fastcall ITEMMODE_ReplaceOppositeHandItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xB7B);
    D2_ASSERT(pUnit, 0xB7C);

    *pItemStatus = 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0xB81);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    unsigned char nOtherBodyLoc;
    if (nBodyLoc != 5 && nBodyLoc != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (nBodyLoc == 5)
    {
        nOtherBodyLoc = 4;
    }
    else
    {
        nOtherBodyLoc = 5;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hOpposite = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherBodyLoc);
    if (!hOpposite)
    {
        *pItemStatus = 1;
        return 0;
    }

    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hOpposite, nOtherBodyLoc);
    if (!hOpposite)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2Common_10299(pUnit, nBodyLoc, pItem, bSkipRequirementCheck) != 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hOpposite, pUnit, 0, 1);

    if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
    {
        sITEMSAddStatsList(ptGame, hOpposite, pUnit, 0);
        SUNIT_AttachSound(pUnit, 0x14, 0);
        return 0;
    }

    D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pMainWeapon)
    {
        UNITS_SetWeaponGUID(pUnit, pMainWeapon);
    }

    sub_0062A360(pUnit, hOpposite);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hOpposite);

    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hOpposite);
    D2_ASSERT(hRemove, 0xBC8);
    D2_ASSERT(hOpposite == hRemove, 0xBC9);

    D2COMMON_10254_Return0(pInventory, nOtherBodyLoc);

    if (ITEMS_GetItemType(hRemove) == 19)
    {
        ITEMMODE_MoveExcessBeltItems(ptGame, pUnit, 0);
    }

    INVENTORY_SetCursorItem(pInventory, hOpposite);

    if (hOpposite)
    {
        hOpposite->dwFlags &= ~2;
    }

    UNITS_ChangeAnimMode(hOpposite, 4);

    if (INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
        {
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            sub_0063D1D0_InventoryItemCall(pInventory, pItem);
            sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
            pItem->dwFlags &= ~2;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            ITEMS_SetItemCMDFlag(pItem, 0x10000, 1);
            ITEMS_SetItemFlag(pItem, 1, 1);

            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xBE6, szItemModeCpp))
            {
                ITEMS_SetItemFlag(pItem, 0x4000, 0);
            }

            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
            sub_0055DBC0(ptGame, pUnit, 0);
        }
        else
        {
            *pItemStatus = 1;
            return 0;
        }
    }

    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}
