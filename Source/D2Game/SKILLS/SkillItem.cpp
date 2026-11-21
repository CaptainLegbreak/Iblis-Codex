#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2AnimData.h"
#include "D2Path.h"
#include "D2ItemModes.h"

#define IFLAG_TARGETING 4

#define OBJECT_STASH 267

#define UPDATEUI_CLOSEALL 17

#define UPDATEUI_OPENCUBE 21

#define SKILL_FIREBALL 47

#define STAT_HITPOINTS 6

#define STAT_LEVEL 12

#define STAT_ATTACKRATE 68

#define STAT_VALUE 71

#define STATE_SLOWED 24

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;

struct D2pSpellTblStrc;

struct D2CurseStrc;

struct D2SkillsTxt;

struct D2MonEquipTxt;

struct Unit005A0180;

union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem); // 0x0062BB20

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590

typedef int (__fastcall* PSPELLFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId);

struct D2pSpellTblStrc
{
    PSPELLFN pfSpellPrepare;
    PSPELLFN pfSpellDo;
};

extern D2pSpellTblStrc gPSpellTable_00741790[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

enum D2C_Z09ItemConstants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
    STAT_STAMINA = 0x0A,
    STAT_MAXSTAMINA = 0x0B,
    STAT_STAMINARECOVERYBONUS = 0x1C,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20

int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId); // 0x005BEDA0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0

int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status); // 0x0055E170

int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90

D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970

enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
    EVENTTYPE_PERIODICSTATS = 9,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0

struct D2MonEquipTxt
{
    char unk0x00[0x1C];
};

struct D2AnimSeqTxt
{
    unsigned short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues); // 0x005BFDA0

extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask); // 0x005A0180

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50

int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc*,D2UnitStrc*,int); // 0x005C6870

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0

void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*,unsigned char); // 0x00571A10

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define MONSTATS2FLAGINDEX_SMALL 10

#define MONSTATS2FLAGINDEX_LARGE 11

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

static void sub_005BE1C0_SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit);

int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY);

enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    SKILL_HOWL = 130,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                     // 0x00472210

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* room); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int level); // 0x006427F0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70

void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* game,D2UnitStrc* unit); // 0x00535430

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* game,D2UnitStrc* unit,D2ActiveRoomStrc* room,int x,int y,int level,D2UnitStrc** out,int object,int permanent); // 0x0056D130

void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380

void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* unit,int id); // 0x005353B0

void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* unit,int id); // 0x00552AF0

D2UnitStrc* __fastcall sub_00553720_ResolveObjectOwner(D2GameStrc* game,D2UnitStrc* unit); // 0x00553720

void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* game,D2UnitStrc* unit); // 0x0058CF00

D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0

void __fastcall sub_0053B3D0_SendByte(D2ClientStrc* client,unsigned char code); // 0x0053B3D0

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc*, int); // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc*, int); // 0x0062A620

static __forceinline int GetUnitType(D2UnitStrc* unit) { return unit?unit->dwUnitType:UNIT_INVALID; }

struct D2AiControlStrc;

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2StatListStrc;

struct D2UnitEventStrc;

enum D2C_G4Constants
{
    STATE_INFERNO = 12,
    STATE_DIMVISION = 23,
    STATE_TAUNT = 27,
    STATE_TERROR = 56,
    STATE_RESTINPEACE = 172,
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
    STAT_MANA = 8,
    STAT_DAMAGERESIST = 36,
    STAT_MAGICRESIST = 37,
    STAT_FIRERESIST = 39,
    STAT_LIGHTRESIST = 41,
    STAT_COLDRESIST = 43,
    STAT_POISONRESIST = 45,
    STAT_MODIFIERLIST_SKILL = 350,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAGEX_TELEPORTED = 0x10000,
    UNITEVENTFLAG_IN_CALLBACK = 1,
    UNITEVENTFLAG_SHOULD_BE_FREED = 2,
    ITEMDROPFLAG_STAFFMODUSEILVL = 0x20,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);

struct D2UnitEventStrc
{
    unsigned char nUnitEvent;
    unsigned char unk0x01;
    unsigned short nFlags;
    unsigned int nEventGroup;
    int unk0x08;
    int nGUID1;
    int nGUID2;
    D2UnitEventCallbackFunction pCallback;
    D2UnitEventStrc* pPrevious;
    D2UnitEventStrc* pNext;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);            // 0x00463740

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

int __fastcall sub_0056F640_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5);   // 0x0056F640

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __stdcall sub_005C0D70(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId);                    // 0x005C0D70

void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pItem, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl);   // 0x005C0F90

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0

short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1560

void __fastcall D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet);                   // 0x005C40D0

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

int __fastcall sub_005C6BF0_GetConvertedMode(D2UnitStrc* pUnit, int nMode);                                 // 0x005C6BF0

int __fastcall sub_6FCFE4C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7); // 0x005C7040

int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0

int __fastcall SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x005C8E30

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                       // 0x005D3CF0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0

void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810

int __stdcall sub_006229F0_IsRayFreeFromUnit(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);      // 0x006229F0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670

int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem);                                                        // 0x0062BBD0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0

int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel);                       // 0x00663270

D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0

int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                          // 0x006633D0

void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

struct D2ModeChangeStrc;

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60

void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int nFlag1, int nFlag2); // 0x0058F030

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pMode, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pMode); // 0x005A7E60

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNode); // 0x005B1900

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pPath, unsigned char nStep); // 0x00649070

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EC10

enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};

int __fastcall sub_005C07A0_UnitEventCallback(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0

D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0

struct D2AffixIndexAndPtrStrc
{
    int nIndex;
    D2MagicAffixTxt* pAffix;
};

D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90

int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0

int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc*, const D2MagicAffixTxt*); // 0x0065E620

int __fastcall sub_00472280(D2SeedStrc*, int, int); // 0x00472280

void __stdcall ITEMMODS_AssignProperty(int, D2UnitStrc*, D2UnitStrc*, const void*, int, int); // 0x0065FEC0

static __forceinline int ClampLevel(int v) { if (v <= 1) return 1; if (v >= 99) return 99; return v; }

struct D2AiCmdStrc;

struct D2StaticPathStrc;

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D9B0

D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010

enum D2C_Y11SkillItemConstants
{
    STATE_UNINTERRUPTABLE = 0x36,
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

void __fastcall sub_6FCC60D0(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char a6); // 0x005717C0

int __fastcall sub_005FDA80_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7); // 0x005FDA80

// 0x005BE130
int __fastcall SKILLITEM_pSpell01_Initializer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    ITEMS_SetItemFlag(pItem, 4, 1);

    const int nSpellIcon = ITEMS_GetSpellIcon(pItem);
    if (nSpellIcon >= 0)
    {
        D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 64), pItem, nSpellIcon, 0, 1, nSkillId);
    }

    return 1;
}

// 0x005BE180
static int sub_005BE180_INVENTORY_ContainsItem(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        if (INVENTORY_UnitIsItem(pInvItem) == pTarget)
        {
            return 1;
        }
    }

    return 0;
}

// 0x005BE1C0
static void sub_005BE1C0_SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 119, ".\\SKILLS\\SkillItem.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 0);
            D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 122), pItem, -1, 1, 0, -1);
        }
    }
}

// 0x005BE230
int __fastcall SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pTarget, 0x10, 147, ".\\SKILLS\\SkillItem.cpp"))
    {
        return 0;
    }

    if (!sub_005BE180_INVENTORY_ContainsItem(pTarget, pUnit))
    {
        return 0;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pUnit, pTarget);
    return 1;
}

static __forceinline int GetItemType(D2UnitStrc* pItem)
{
    int nType = 6;
    if (pItem)
    {
        nType = pItem->dwUnitType;
    }
    return nType;
}

// 0x005BE290
int __fastcall sub_005BE290_CreateTownPortal(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,int unused1,int unused2,int unused3,int unused4)
{
 if(GetUnitType(unit)!=0) return 0;
 unit->dwFlags|=0x40;
 D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
 unsigned char act=DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(room));
 int town=DUNGEON_GetTownLevelIdFromActNo(act);
 if(DUNGEON_IsRoomInTown(room) || DUNGEON_GetLevelIdFromRoom(room)==136) {
  sub_00553380_SendEvent(unit,24,unit);return 0;
 }
 PLAYER_RemoveTownPortal(game,unit);
 D2UnitStrc* portal=0;
 int result=D2GAME_CreatePortalObject_6FD13DF0(game,unit,room,CLIENTS_GetUnitX(unit),CLIENTS_GetUnitY(unit),town,&portal,59,0);
 sub_00553380_SendEvent(unit,7,0);
 if(result) {
  PLAYER_SetUniqueIdInPlayerData(unit,!portal?-1:portal->dwUnitId);
  if(portal) {
   OBJECTS_SetUnitIdInTimerArg(portal,unit->dwUnitId);
   D2UnitStrc* other=sub_00553720_ResolveObjectOwner(game,portal);
   if(other) {
    OBJECTS_SetUnitIdInTimerArg(other,unit->dwUnitId);
    ACT5Q5_OnPortalOpened(game,other);
   }
   ACT5Q5_OnPortalOpened(game,portal);
  }
 }
 if(item) {
  const int nItemId = item->dwUnitId;
  const int nItemType = GetItemType(item);
  D2ClientStrc* client=sub_005531C0_GetClient(unit,".\\SKILLS\\SkillItem.cpp",218,nItemType,nItemId);
  sub_0053B3D0_SendByte(client,124);
 }
 return result;
}

// build: context GetItemStatCost
static __forceinline D2ItemStatCostTxt* GetItemStatCost(int nStat)
{
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount)
        return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

// 0x005BE3F0
int __fastcall sub_005BE3F0_ApplyPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int a4, int a5, int a6, int a7)
{
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxt) return 0;
    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwLen);
    const int nState = pItemsTxt->wState;
    D2StatListStrc* pStatList = 0;
    int nOldLength = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount) return 0;
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList) nOldLength = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }
    int nResult = 0;
    int bUpdateLife = 0;
    for (int i = 0; i < 3; ++i)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const int nStat = pItemsTxt->wStat[i];
        if (nStat < 0 || nStat >= sgptDataTables->nItemStatCostTxtRecordCount) break;
        D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
        if (!pCost) continue;
        int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxt->dwCalc[i]);
        switch (nStat)
        {
        case 74: nValue <<= 8;
        case 6:
        {
            nValue = ITEMS_GetBonusLifeBasedOnClass(pUnit, nValue);
            const int nVitality = STATLIST_UnitGetStatValue(pUnit, 3, 0);
            if (nVitality > 0)
            {
                const unsigned int nChance = (unsigned int)ITEMS_RollLimitedRandomNumber(pSeed, nVitality) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        case 26: nValue <<= 8;
        case 8:
        {
            nValue = ITEMS_GetBonusManaBasedOnClass(pUnit, nValue);
            const int nEnergy = STATLIST_UnitGetStatValue(pUnit, 1, 0);
            if (nEnergy > 0)
            {
                const unsigned int nChance = (unsigned int)ITEMS_RollLimitedRandomNumber(pSeed, nEnergy) >> 1;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (int)nChance) nValue += nValue;
            }
            break;
        }
        }
        nValue <<= pCost->nValShift;
        if (nValue <= 0) continue;
        switch (nStat)
        {
        case 6: bUpdateLife = 1;
        case 74:
            if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                nValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nValue);
            break;
        }
        if (nLength <= 0)
        {
            const int nCurrent = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            const int nMaxStat = pCost->wMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nCurrent + nValue > nMaxValue)
                    nValue = nMaxValue - nCurrent;
            }
            STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
            nResult = 1;
        }
        else
        {
            const int nExpireFrame = pGame->dwGameFrame + nOldLength + nLength;
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                if (!pStatList) continue;
                STATLIST_SetState(pStatList, nState);
                STATES_ToggleState(pUnit, nState, 1);
                if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                {
                    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                }
                STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }
            D2COMMON_10476(pStatList, nExpireFrame);
            const int nTotalValue = STATLIST_GetStatValue(pStatList, nStat, 0) * nOldLength + nValue;
            if (i == 0) EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
            const int nTotalLength = nLength + nOldLength;
            if (nTotalLength > 0) STATLIST_SetStat(pStatList, nStat, nTotalValue / nTotalLength, 0);
            nResult = 1;
        }
    }
    if (bUpdateLife && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const unsigned char nOldLife = STATLIST_UnitGetStatValue(pUnit, 352, 0);
        const unsigned char nNewLife = MONSTERMODE_GetHpPercent128(pUnit);
        int nDifference = nOldLife - nNewLife;
        if (nDifference < 0) nDifference = -nDifference;
        if (nDifference > 4)
        {
            SUNITMSG_QueueLifeUpdate(pUnit, nNewLife);
            STATLIST_SetUnitStat(pUnit, 352, nNewLife, 0);
        }
    }

    return nResult;
}

// 0x005BE7B0
int __fastcall SKILLITEM_pSpell04_ApplyPotionStats(D2GameStrc* game,D2UnitStrc* unit,D2UnitStrc* item,D2UnitStrc* target,int x,int y,int skillId)
{
 D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1:item->dwClassId);
 if(!record)return 0;
 int duration=ITEMMODS_EvaluateItemFormula(unit,item,record->dwLen);
 int state=record->wState;
 D2StatListStrc* list=0;
 int remaining=0;
 if(duration>0){
  if(state<=0 || state>=sgptDataTables->nStatesTxtRecordCount)return 0;
  list=STATLIST_GetStatListFromUnitAndState(unit,state);
  if(list)remaining=D2COMMON_10473(list)-game->dwGameFrame;
 }
 int changed=0,updateLife=0;
 for(int i=0;i<3;++i){
  int stat=record->wStat[i];
  if(stat<0 || stat>=sgptDataTables->nItemStatCostTxtRecordCount)break;
  D2ItemStatCostTxt* cost=&sgptDataTables->pItemStatCostTxt[stat];
  if(!cost)continue;
  int value=ITEMMODS_EvaluateItemFormula(unit,item,record->dwCalc[i]);
  if(stat==26 || stat==74)value<<=8;
  value=value<<cost->nValShift;
  if(value<=0)continue;
  switch(stat){
   case 6:updateLife=1;
   case 74:if(!sub_0044BE50_GetUnitTypeOrInvalid(unit))value=SKILLS_SharePotionLifeWithBloodGolem(game,unit,value);break;
  }
  if(duration<=0){
   const int current=STATLIST_UnitGetStatValue(unit,stat,0);
   if(cost->wMaxStat<sgptDataTables->nItemStatCostTxtRecordCount){
    int maximum=STATLIST_UnitGetStatValue(unit,cost->wMaxStat,0);
    if(current+value>maximum)value=maximum-current;
   }
   STATLIST_AddUnitStat(unit,stat,value,0);
   changed=1;
  }else{
   int expiry=game->dwGameFrame+remaining+duration;
   if(!list){
    int const nUnitGUID = sub_00451F50_GetUnitGUID(unit);
    list=STATLIST_AllocStatList(game->pMemoryPool,2,expiry,sub_0044BE50_GetUnitTypeOrInvalid(unit),nUnitGUID);
    if(!list)continue;
    STATLIST_SetState(list,state);
    STATES_ToggleState(unit,state,1);
    if(sub_0044BE50_GetUnitTypeOrInvalid(unit)){
     sub_00540E60(game,unit,3,0);
     EVENT_SetEvent(game,unit,3,game->dwGameFrame+1,0,0);
    }
    STATLIST_SetStatRemoveCallback(list,sub_6FD10E50);
    D2COMMON_10475_PostStatToStatList(unit,list,1);
   }
   D2COMMON_10476(list,expiry);
   int total=STATLIST_GetStatValue(list,stat,0)*remaining+value;
   if(i==0)EVENT_SetEvent(game,unit,12,expiry,0,0);
   if(duration+remaining>0)STATLIST_SetStat(list,stat,total/(duration+remaining),0);
   changed=1;
  }
 }
 if(updateLife && unit && unit->dwUnitType==UNIT_PLAYER){
  unsigned char previous=(unsigned char)STATLIST_UnitGetStatValue(unit,352,0);
  unsigned char life=MONSTERMODE_GetHpPercent128(unit);
  int difference=(int)previous-(int)life;
  if(difference<0)difference=-difference;
  if(difference>4){
   SUNITMSG_QueueLifeUpdate(unit,life);
   STATLIST_SetUnitStat(unit,352,life,0);
  }
 }
 return changed;
}

// build: context SKILLS_GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId < 0)
    {
        return 0;
    }

    if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

// 0x005BEAC0
int __fastcall SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    const int nState = pItemsTxtRecord->wState;

    D2StatListStrc* pStatList = 0;
    int nRemainingDuration = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
        {
            return 0;
        }

        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            nRemainingDuration = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
        }
    }

    int nResult = 0;
    int bAffectsHitpoints = 0;

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->wMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nPercentage = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nPercentage > 0)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, pItemStatCostTxtRecord->wMaxStat, 0);
                int nAddValue = DATATBLS_ApplyRatio(nMaxValue, nPercentage, 100);
                if (nPercentage == 100)
                {
                    nAddValue = nMaxValue;
                }

                switch (nStatId)
                {
                case 6:
                    bAffectsHitpoints = 1;
                case 74:
                    if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                    {
                        nAddValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nAddValue);
                    }
                    break;
                }

                if (nLength <= 0)
                {
                    const int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
                    if (nOldValue + nAddValue > nMaxValue)
                    {
                        nAddValue = nMaxValue - nOldValue;
                    }

                    STATLIST_AddUnitStat(pUnit, nStatId, nAddValue, 0);
                    nResult = 1;
                }
                else
                {
                    const int nExpireFrame = pGame->dwGameFrame + nRemainingDuration + nLength;
                    if (!pStatList)
                    {
                        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                        if (!pStatList)
                        {
                            continue;
                        }

                        STATLIST_SetState(pStatList, nState);
                        STATES_ToggleState(pUnit, nState, 1);

                        if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                        {
                            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                            EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                        }

                        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
                        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    }

                    D2COMMON_10476(pStatList, nExpireFrame);

                    const int nTimeDependentValue = nAddValue + nRemainingDuration * STATLIST_GetStatValue(pStatList, nStatId, 0);
                    if (!i)
                    {
                        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
                    }

                    if (nRemainingDuration + nLength > 0)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, nStatId, nTimeDependentValue / (nRemainingDuration + nLength), 0);
                    }

                    nResult = 1;
                }
            }
        }
    }

    if (bAffectsHitpoints && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const unsigned char nNewSentHpPct = MONSTERMODE_GetHpPercent128(pUnit);
        SUNITMSG_QueueLifeUpdate(pUnit, nNewSentHpPct);
        STATLIST_SetUnitStat(pUnit, 352, nNewSentHpPct, 0);
    }

    return nResult;
}

// 0x005BEDA0
int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nState = pItemsTxtRecord->wState;
    if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    if (nLength <= 0)
    {
        return 0;
    }

    sub_6FD11C90(pUnit, nState, 0);

    int nRemaining = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        nRemaining = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
    }

    const int nEndFrame = pGame->dwGameFrame + nRemaining + nLength;

    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nState);
        STATES_ToggleState(pUnit, nState, 1);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    if (nEndFrame)
    {
        D2COMMON_10476(pStatList, nEndFrame);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nEndFrame, 0, 0);
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount && sub_0045C4F0_GetItemStatCostTxtRecord(nStatId))
        {
            const int nValue = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_STAMINARECOVERYBONUS && nValue > 0)
                {
                    const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
                    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
                    {
                        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina + 0x100, 0);
                    }
                }
            }
        }
    }

    return 1;
}

// 0x005BEF90
int __fastcall sub_005BEF90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nResult = 0;
    for (int i = 0; i < 2; ++i)
    {
        const int nCurseState = pItemsTxtRecord->wCurseState[i];
        if (nCurseState > 0 && nCurseState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nCurseState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            if (STATES_CheckState(pUnit, nCurseState))
            {
                STATES_ToggleState(pUnit, nCurseState, 0);
            }

            nResult = 1;
        }
    }

    if (SKILLITEM_pSpell09_StaminaPotion(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId))
    {
        nResult = 1;
    }

    return nResult;
}

// 0x005BF060
int __fastcall sub_005BF060(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    const int nStatId = ITEMS_GetFileIndex(pItem);
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        const int nValue = STATLIST_UnitGetStatValue(pItem, STAT_VALUE, 0);
        if (nValue)
        {
            STATLIST_AddUnitStat(pUnit, nStatId, nValue, 0);
            return 1;
        }
    }

    return 0;
}

// 0x005BF0C0
int __fastcall SKILLITEM_pSpell07_OpenCube(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        if (!pInteractUnit || pInteractUnit->dwUnitType != UNIT_OBJECT || pInteractUnit->dwClassId != OBJECT_STASH)
        {
            return 0;
        }

        SUNIT_ResetInteractInfo(pUnit);
        sub_6FC4B830(pGame, pUnit);
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 947), UPDATEUI_CLOSEALL);
    }

    SUNIT_SetInteractInfo(pUnit, UNIT_ITEM, !pItem ? -1 : pItem->dwUnitId);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 961), UPDATEUI_OPENCUBE);
    sub_6FC4B830(pGame, pUnit);
    return 0;
}

// 0x005BF170
int __fastcall SKILLITEM_pSpell10_CastFireBallOnTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit)
    {
        return SKILLITEM_CastSkillOnTarget(pUnit, SKILL_FIREBALL, 1, pTargetUnit, 0);
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), 0);
}

// 0x005BF1F0
int __fastcall SKILLITEM_pSpell11_CastFireBallToCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, unsigned short nX, unsigned short nY, int nSkillId)
{
    if (!DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
    {
        return 0;
    }

    return SKILLITEM_CastSkillOnPosition(pUnit, SKILL_FIREBALL, 1, nX, nY, 0);
}

// 0x005BF240
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nItemType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemType == UNIT_ITEM)
    {
        int nPSpell = -1;
        int nSkillId = -1;

        if (ITEMSIsA(pItem, ITEMTYPE_BOOK) || ITEMSIsA(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord)
            {
                nPSpell = pBooksTxtRecord->dwPSpell;
                nSkillId = pBooksTxtRecord->dwBookSkillId;
            }
        }

        if (nPSpell <= 0)
        {
            const int nClassId = pItem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            if (pItemsTxtRecord)
            {
                nPSpell = pItemsTxtRecord->dwPspell;
            }

            if (nPSpell <= 0)
            {
                return 0;
            }
        }

        if (nPSpell >= gnPSpellTableCount_0074178C)
        {
            return 0;
        }

        if (gPSpellTable_00741790[nPSpell].pfSpellPrepare && !ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 1130, ".\\SKILLS\\SkillItem.cpp"))
        {
            if (!gPSpellTable_00741790[nPSpell].pfSpellPrepare(pGame, pUnit, pItem, 0, nX, nY, nSkillId))
            {
                sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
                const unsigned int nItemGUID = pItem->dwUnitId;
                const int nItemType = pItem->dwUnitType;
                D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1135), 0x7C, nItemType, nItemGUID);
            }

            return 0;
        }

        if (!gPSpellTable_00741790[nPSpell].pfSpellDo)
        {
            return 0;
        }

        ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 1);

        const int nResult = gPSpellTable_00741790[nPSpell].pfSpellDo(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
        if (!nResult)
        {
            sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
            const unsigned int nItemGUID = pItem->dwUnitId;
            const int nItemType = pItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\SKILLS\\SkillItem.cpp", 1151), 0x7C, nItemType, nItemGUID);
        }

        return nResult;
    }

    return 0;
}

// 0x005BF3D0
int __fastcall SKILLS_SrvDo113_Scroll_Book(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInvItem;
    D2UnitStrc* pItem;
    for (pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        pItem = INVENTORY_UnitIsItem(pInvItem);
        if (ITEMSIsA(pItem, ITEMTYPE_BOOK))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwBookSkillId == nSkillId && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
            {
                break;
            }
        }
        else if (ITEMSIsA(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord && pBooksTxtRecord->dwScrollSkillId == nSkillId)
            {
                break;
            }
        }
    }

    if (pInvItem)
    {
        switch (INVENTORY_GetItemNodePage(pInvItem))
        {
        case 1:
        {
            int nUnused;
            ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused);
            return 1;
        }
        case 2:
        {
            int nUnused;
            ITEMMODE_UseBeltItem(pGame, pUnit, !pItem ? -1 : pItem->dwUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), &nUnused, 0);
            return 1;
        }
        }
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005BF510
void __fastcall SKILLITEM_ActivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a5);
    const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, a5, nSkillId);

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
    {
        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 1, 0);
    }
}

inline int AiSpecialStateFromAuraState(int nAuraState)
{
    switch (nAuraState)
    {
    case STATE_DIMVISION: return AISPECIALSTATE_DIMVISION;
    case STATE_TERROR: return AISPECIALSTATE_TERROR;
    case STATE_TAUNT: return AISPECIALSTATE_TAUNT;
    default: return AISPECIALSTATE_NONE;
    }
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// build: context SUNITEVENT_FreeEvent
static void __fastcall SUNITEVENT_FreeEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitEventStrc* pUnitEvent)
{
    D2UnitEventStrc* pNext = pUnitEvent->pNext;
    if (pUnitEvent->pPrevious)
    {
        pUnitEvent->pPrevious->pNext = pNext;
    }
    else
    {
        pUnit->pSrvUnitEventsList = pNext;
    }

    if (pUnitEvent->pNext)
    {
        pUnitEvent->pNext->pPrevious = pUnitEvent->pPrevious;
    }

    FOG_FreePool(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 149, 0);
}

// 0x005BF5D0
void __fastcall SKILLITEM_DeactivateAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int a4, int nSkillId)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a4);
}

// 0x005BF670
int __fastcall SKILLITEM_EventFunc06_AttackerTakesDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwPhysDamage = nDamage << 8;
    damage.dwHitClass = 0x8D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF720
int __fastcall SKILLITEM_EventFunc10_AttackerTakesLightDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwLtngDamage = nDamage << 8;
    damage.dwHitClass = 0x4D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF7D0
int __fastcall SKILLITEM_EventFunc11_ApplyFireDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwFireDamage = nDamage << 8;
    damage.dwHitClass = 0x2D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

// 0x005BF880
int __fastcall SKILLITEM_EventFunc12_ApplyColdDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    int bCanBeAttacked = 0;
    if (pAttacker && pUnit)
    {
        bCanBeAttacked = (pUnit->dwFlags >> 2) & 1;
    }
    if (!bCanBeAttacked)
    {
        return 0;
    }

    const int nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nDamage <= 0)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nLength = 25;
    if (nAttackerLevel > nDefenderLevel)
    {
        const int nLevelDiff = nAttackerLevel - nDefenderLevel;
        nLength += 10 * nLevelDiff;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x4021;
    damage.dwColdLen = nLength;
    damage.dwColdDamage = nDamage << 8;
    damage.dwHitClass = 0x3D;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
    return 1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x005BF960
int __stdcall sub_005BF960_StatCallback_Knockback(D2UnitStrc* pUnit, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned int nStatLayer, int nUnused)
{
    if (!pUnit || !pDefender || !pDamage)
    {
        return 0;
    }

    if (STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, nStatLayer >> 16, nStatLayer) <= 0)
    {
        return 0;
    }

    int nChance = 64;
    if (sub_0044BE50(pDefender) == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(sub_00623C60(pDefender));
        if (pMonStats2TxtRecord)
        {
            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_LARGE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_LARGE & 7])
            {
                nChance = 32;
            }
            else if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                nChance = 128;
            }
        }
    }

    if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) & 127) >= nChance)
    {
        return 0;
    }

    pDamage->wResultFlags |= 8;
    return 1;
}

// 0x005BFA10
int __fastcall SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (sub_00472210_SeedRollMasked(&pAttacker->pSeed, 128) >= nChance)
    {
        return 0;
    }

    AIUTIL_ApplyTerrorCurseState(pGame, pAttacker, pUnit, SKILL_HOWL, 20, 20);
    return 1;
}

// 0x005BFAA0
int __fastcall SKILLITEM_EventFunc09_Stupidity(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        goto ReturnZero;
    }

    if (!pUnit)
    {
        goto ReturnZero;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
ReturnZero:
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, STAT_LEVEL, 0);
    int nChance = 5 * (nAttackerLevel + 4 * nValue - STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) + 6);
    if (nEvent == 6 && nChance > 0)
    {
        nChance /= 3;
    }

    nChance = D2_MIN(D2_MAX(nChance, 1), 99);

    const int nRoll = SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 100);
    if (nRoll >= nChance)
    {
        return 0;
    }

    int nLevel = (nChance - nRoll) / 5 + 1;
    nLevel = D2_MIN(D2_MAX(nLevel, 1), 20);

    sub_6FD0B9F0(pGame, pAttacker, pUnit, nLevel);
    return 1;
}

static __forceinline int GetUnitTypeChecked(const D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// 0x005BFBB0
int __fastcall sub_005BFBB0_DamageToMana(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || GetUnitTypeChecked(pAttacker) != 0)
    {
        return 0;
    }
    if (!pDamage)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, 8, 0);
    if (nMana >= nMaxMana)
        return 0;
    int nNewMana = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, nValue, 100) + nMana;
    nNewMana = nNewMana > 0 ? nNewMana : 0;
    STATLIST_SetUnitStat(pAttacker, 8, nNewMana < nMaxMana ? nNewMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}

// 0x005BFC60
int __fastcall sub_005BFC60_EventFuncFreeze(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
    {
        return 0;
    }

    int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);

    int nBonus = nValue - 1;
    if (nBonus < 0)
    {
        nBonus = 0;
    }

    if (nEvent == 6)
    {
        nAttackerLevel -= nEvent;
    }

    int nChance = 5 * (4 * nBonus - nUnitLevel + nAttackerLevel + 10);
    if (nEvent == 6)
    {
        nChance /= 3;
    }

    int nPercent = D2_MIN(D2_MAX(nChance, 0), 100);

    const unsigned __int64 lSeed = (unsigned __int64)pAttacker->pSeed.nHighSeed + (unsigned __int64)pAttacker->pSeed.nLowSeed * 0x6AC690C5;
    pAttacker->pSeed.nLowSeed = (unsigned int)lSeed;
    pAttacker->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    const int nRoll = (int)((unsigned int)lSeed % 100);
    if (nRoll >= nPercent)
    {
        return 0;
    }

    int nLength = 2 * (nPercent - nRoll) + 25;
    nLength = D2_MIN(D2_MAX(nLength, 25), 250);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFrzLen = nLength;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    return 1;
}

// 0x005BFDA0
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues)
{
    if (nLevel <= 1 || !pValues)
    {
        return 0;
    }

    if (nLevel > 60)
    {
        return (pValues[4] * (nLevel - 60)) + 15 * (pValues[1] + pValues[2] + pValues[3]) + 14 * pValues[0];
    }

    if (nLevel > 45)
    {
        return (pValues[3] * (nLevel - 45)) + 15 * (pValues[1] + pValues[2]) + 14 * pValues[0];
    }

    if (nLevel > 30)
    {
        return 15 * pValues[1] + pValues[2] * (nLevel - 30) + 14 * pValues[0];
    }

    if (nLevel > 15)
    {
        return pValues[1] * (nLevel - 15) + 14 * pValues[0];
    }

    return pValues[0] * (nLevel - 1);
}

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BFE60
int __fastcall SKILLITEM_EventFunc15_OpenWounds(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    const int nValues[] = { 9, 18, 27, 36, 45 };
    int nHpRegen = SKILLITEM_CalculateOpenWoundsHpRegen(nLevel, nValues) + 40;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nHpRegen /= 4;
        if (nEvent == 6)
        {
            nHpRegen /= 2;
        }
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER && sub_005A0180((Unit005A0180*)pUnit, 0x0C))
    {
        nHpRegen /= 2;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 200;
    curse.nStat = 74;
    curse.nStatValue = -nHpRegen;
    curse.nState = 62;
    sub_0056E970(&curse);
    return 1;
}

// 0x005BFFC0
int __fastcall SKILLITEM_EventFunc16_CrushingBlow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    int nDivisor = 4;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nDivisor = 10;
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            nDivisor = 10;
        }
        else
        {
            if (MONSTERS_IsBoss(0, pUnit) || sub_005A0180((Unit005A0180*)pUnit, 2))
            {
                nDivisor = 8;
            }

            int nPlayerCount = STATLIST_UnitGetStatValue(pUnit, 100, 0);
            if (nPlayerCount < 1)
            {
                nPlayerCount = 1;
            }

            const int nHpBonus = MONSTER_GetHpBonus(nPlayerCount);
            if (nHpBonus)
            {
                nDivisor += DATATBLS_ApplyRatio(nDivisor, nHpBonus, 100);
            }
        }
    }

    if (nEvent == 6)
    {
        nDivisor *= 2;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    int nCrushingBlowHp = nHitpoints / nDivisor;

    int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
    if (nDamageResist >= 100)
    {
        nDamageResist = 100;
    }

    if (nDamageResist > 0)
    {
        nCrushingBlowHp -= DATATBLS_ApplyRatio(nCrushingBlowHp, nDamageResist, 100);
    }

    int nNewHp = nHitpoints - nCrushingBlowHp;
    nNewHp = nNewHp > 0 ? nNewHp : 0;
    STATLIST_SetUnitStat(pUnit, 6, nNewHp, 0);

    if (nNewHp <= 0 && pDamage)
    {
        pDamage->wResultFlags |= 2;
    }

    if (nCrushingBlowHp > 0)
    {
        UNITS_SetOverlay(pUnit, 147, 0);
    }

    return 1;
}

// 0x005C0130
int __fastcall sub_005C0130_RestoreManaAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || pAttacker->dwUnitType != UNIT_PLAYER)
        return 0;
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
        return 0;
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pAttacker);
    int nMana = STATLIST_UnitGetStatValue(pAttacker, 8, 0);
    if (nMana >= nMaxMana)
        return 0;
    nMana += nValue << 8;
    nMana = nMana > 0 ? nMana : 0;
    STATLIST_SetUnitStat(pAttacker, 8, nMana < nMaxMana ? nMana : nMaxMana, 0);
    UNITS_SetOverlay(pAttacker, 152, 0);
    return 1;
}

// 0x005C0260
int __fastcall SKILLITEM_EventFunc18_HealAfterDemonKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !MONSTERS_IsDemon(pUnit))
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, STAT_HITPOINTS, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, STAT_HITPOINTS, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C0310
int __fastcall SKILLITEM_EventFunc19_Slow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    int nSlowValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nSlowValue)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
    {
        if (nSlowValue >= 50)
        {
            nSlowValue = 50;
        }
    }
    else if (nUnitType == UNIT_MONSTER)
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 12))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_IsBoss(0, pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            if (nSlowValue >= 50)
            {
                nSlowValue = 50;
            }
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
        {
            if (nSlowValue >= 75)
            {
                nSlowValue = 75;
            }
        }
        else
        {
            if (nSlowValue >= 90)
            {
                nSlowValue = 90;
            }
        }
    }
    else
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAttacker;
    curse.pTarget = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = 750;
    curse.nStat = STAT_VELOCITYPERCENT;
    curse.nStatValue = -nSlowValue;
    curse.nState = STATE_SLOWED;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    sub_006270B0(pStatList, STAT_ATTACKRATE, -nSlowValue, 0);
    sub_006270B0(pStatList, STAT_OTHER_ANIMRATE, -nSlowValue, 0);
    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillItem.cpp", 2186);
    return 1;
}

static __forceinline unsigned int SEED_RollRandomNumber32(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005C0470
int __fastcall SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (pDamage && !(pDamage->dwHitFlags & DAMAGEHITFLAG_0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumber32(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_ITEMTGTDO >> 3] & gdwBitMasks[SKILLSFLAGINDEX_ITEMTGTDO & 7])
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pUnit, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
            return 1;
        }
    }
    else
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 1);
            return 1;
        }

        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 1);
    }

    return 1;
}

// 0x005C05A0
int __fastcall SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (!pDamage)
    {
        return 0;
    }

    if (!(pDamage->wResultFlags & DAMAGERESULTFLAG_GETHIT))
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    if (!sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C0670
int __fastcall SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if ((int)(SEED_RollRandomNumber32(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    if (!SKILLS_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}

// 0x005C0770
int __fastcall SKILLITEM_EventFunc29_RestInPeace(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (pAttacker && pUnit)
    {
        STATES_ToggleState(pUnit, STATE_RESTINPEACE, 1);
        return 1;
    }

    return 0;
}

inline int UNIT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

static __forceinline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static __forceinline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x005C07A0
int __fastcall sub_005C07A0_ReanimateMonster(D2GameStrc* pGame, int nUnusedRegister, D2UnitStrc* pCorpse, int nUnused1, int nUnused2, int nMonsterId, int nOwnerGUID)
{
    D2UnitStrc* pOwner = 0;
    if (UNIT_GetUnitType(pCorpse) == 1)
    {
        pOwner = SUNIT_GetServerUnit(pGame, 0, nOwnerGUID);
    }

    if (!pOwner)
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pCorpse, 0) || nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pCorpse);
    const int nY = CLIENTS_GetUnitY(pCorpse);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCorpse);
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
        return 0;
    D2MonStats2Txt* pMonStats2 = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2)
        return 0;
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pCorpse), CLIENTS_GetUnitX(pCorpse), CLIENTS_GetUnitY(pCorpse), PATH_GetUnitCollisionPattern(pCorpse), 0x8000);
    D2UnitStrc* pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, -1, 74);
    if (!pPet)
        return 0;
    pPet->dwFlags |= 0x0402000E;
    AITHINK_ExecuteAiFn(pGame, pPet, AIGENERAL_GetAiControlFromUnit(pPet), 0);
    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    AIGENERAL_SetOwnerData(pGame, pPet, sub_GetUnitGUIDChecked(pOwner), sub_GetUnitTypeChecked(pOwner), 0, 0);
    AIUTIL_SetOwnerGUIDAndType(pPet, pOwner);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, 2, 0);
    EVENT_SetEvent(pGame, pPet, 2, pGame->dwGameFrame + 25, 0, 0);
    sub_005543B0_AssignAlignment(pPet, 2, 0);
    pPet->dwFlags |= 0x80000000;
    STATES_ToggleState(pPet, 96, 1);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 21, 0);
    EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + 1500, 0, 0);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pOwner->dwNodeIndex);
    D2Common_10214(pPet);
    if (pMonStats2->nResurrectMode == 14)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pPet, 14, &modeChange);
        UNITS_SetUsedSkill(pPet, SKILLS_GetSkillById(pPet, 158, -1));
        PATH_SetStepNum(pPet->pDynamicPath, 1);
        modeChange.pTargetUnit = 0;
        modeChange.nX = nX;
        modeChange.nY = nY;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
    }
    STATES_ToggleState(pPet, 118, 1);
    STATES_ToggleState(pCorpse, 173, 1);
    return 1;
}

// 0x005C09E0
int __fastcall sub_005C09E0_SkillItemEventFunc_Reanimate(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    while (pAttacker)
    {
        if (sub_0044BE50(pAttacker) == UNIT_PLAYER)
        {
            const int nOwnerId = pAttacker->dwUnitId;
            // volatile only makes these reloads come from the stack copies of the register parameters, as the original does
            D2UnitStrc* pEventUnit = static_cast<D2UnitStrc* const volatile&>(pUnit);
            D2GameStrc* pOwnerGame = static_cast<D2GameStrc* const volatile&>(pGame);
            SUNITEVENT_Register(pOwnerGame, pEventUnit, UNITEVENT_13, static_cast<unsigned short>(nSkillId), nOwnerId, sub_005C07A0_UnitEventCallback, 0, nOwnerId);
            return 1;
        }

        pAttacker = AIGENERAL_GetMinionOwner(pAttacker);
    }

    return 0;
}

// 0x005C0AD0
D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitEventStrc* pUnitEvent = (D2UnitEventStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2UnitEventStrc), ".\\UNIT\\SUnitEvent.cpp", 87, 0);
    memset(pUnitEvent, 0x00, sizeof(D2UnitEventStrc));

    pUnitEvent->nUnitEvent = nUnitEvent;
    pUnitEvent->nGUID1 = nGUID1;
    pUnitEvent->nGUID2 = nGUID2;
    pUnitEvent->pCallback = pCallback;
    pUnitEvent->pNext = pUnit->pSrvUnitEventsList;
    pUnitEvent->nEventGroup = nQueueNo;
    pUnitEvent->unk0x08 = a8;

    if (pUnit->pSrvUnitEventsList)
    {
        pUnit->pSrvUnitEventsList->pPrevious = pUnitEvent;
    }

    pUnit->pSrvUnitEventsList = pUnitEvent;
    return pUnitEvent;
}

// 0x005C0B50
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4)
{
    if (!pUnit)
    {
        return;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nEventGroup == nTimerQueueNo && pUnitEvent->unk0x08 == a4)
        {
            if (pUnitEvent->nFlags & UNITEVENTFLAG_IN_CALLBACK)
            {
                pUnitEvent->nFlags |= UNITEVENTFLAG_SHOULD_BE_FREED;
            }
            else
            {
                SUNITEVENT_FreeEvent(pGame, pUnit, pUnitEvent);
            }
        }

        pUnitEvent = pNext;
    }
}

// 0x005C0BE0
D2UnitEventStrc* __fastcall SUNITEVENT_GetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4, int nGUID1)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nEventGroup == nTimerQueueNo && pUnitEvent->unk0x08 == a4 && pUnitEvent->nGUID1 == nGUID1)
        {
            return pUnitEvent;
        }

        pUnitEvent = pNext;
    }

    return 0;
}

// 0x005C1260
void __fastcall sub_005C1260(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const int nClassId = ITEMS_GetStaffMods(pItem);
    if (nClassId < 0 || nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return;
    }

    if (SKILLS_GetPlayerSkillCount(nClassId) <= 0)
    {
        return;
    }

    const int nSkillId = SKILLS_GetClassSkillId(nClassId, 0);
    const int nItemLevel = pItemDrop->nItemLvl;
    if (!ITEMS_GetItemFormat(pItem))
    {
        sub_005C0D70(pItem, nItemLevel, nSkillId);
    }
    else
    {
        ITEMS_AssignModernStaffMods(pItem, nItemLevel, nSkillId, pItemDrop->dwFlags2 & ITEMDROPFLAG_STAFFMODUSEILVL ? pItemDrop->nItemLvl : 0);
    }
}

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005C12F0
short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    D2AffixIndexAndPtrStrc tAffixes[512];
    D2MagicAffixDataTbl* pTable = DATATBLS_GetMagicAffixDataTables();
    if (!pTable) return 0;
    D2MagicAffixTxt* pRecord;
    int nCount;
    if (bPrefix) { pRecord = pTable->pMagicPrefix; nCount = pTable->pAutoMagic - pRecord; }
    else { pRecord = pTable->pMagicSuffix; nCount = pTable->pMagicPrefix - pRecord; }
    if (!pRecord) return 0;
    const int nFirstIndex = pRecord - pTable->pMagicAffixTxt;
    int nIndex = -1;
    int nMax = 0;
    const unsigned int nRoll = RollSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    if ((nRoll & 1) || bForceAffixRoll)
    {
        int nLevel = ITEMS_GetItemLevel(pItem) + 2;
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);
        for (int i = 0; i < nCount; ++i)
        {
            if ((!bRequireSpawnableAffix || pRecord[i].bSpawnable) && (pRecord[i].wVersion < 100 || nFormat >= 100) && pRecord[i].nLevel <= nLevel && ITEMMODS_CanItemHaveMagicAffix(pItem, &pRecord[i]) && nMax < 511)
            {
                tAffixes[nMax].pAffix = &pRecord[i];
                tAffixes[nMax].nIndex = nFirstIndex + i;
                ++nMax;
            }
        }
        if (nMax <= 0) return 0;
        const int nRandom = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
        if (nRandom >= nMax) return 0;
        D2AffixIndexAndPtrStrc* pAffix = &tAffixes[nRandom];
        if (!pAffix) return 0;
        nIndex = pAffix->nIndex;
        if (nPreferredAffixIndex > 0)
        {
            nPreferredAffixIndex += nFirstIndex;
            if (nPreferredAffixIndex > 0)
            {
                for (int i = 0; i < nMax; ++i)
                {
                    D2AffixIndexAndPtrStrc* pCurrent = &tAffixes[i];
                    if (pCurrent->nIndex == nPreferredAffixIndex - 1)
                    {
                        nIndex = pCurrent->nIndex;
                        pAffix = pCurrent;
                        goto ApplyProperties;
                    }
                }
                nIndex = -1;
            }
        }
ApplyProperties:
        if (bAssignProperties) ITEMMODS_AssignProperty(0, 0, pItem, pAffix->pAffix, 0, 0);
    }
    return nIndex + 1;
}

// build: symbol ?ITEMS_RollMagicAffixes@@YIGPAUD2UnitStrc@@HHHHH@Z 0x005C18E0
unsigned short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

// build: symbol ?ITEMS_RollMagicAffixes@@YIFPAUD2UnitStrc@@HHHHHH@Z 0x005C1940
short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex, nAutoMagicGroup);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex);
}

// 0x005C2FF0
void __fastcall sub_005C2FF0_DamagePaladinCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == PCLASS_PALADIN)
    {
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);

        D2DamageStrc damage;
        memset(&damage, 0x00, sizeof(damage));

        damage.dwHitFlags |= 0x1000;
        damage.wResultFlags |= 4;
        damage.dwPhysDamage = nMaxHp / 8;
        damage.dwDmgTotal = nMaxHp / 8;

        SUNITDMG_ExecuteEvents(pGame, pUnit, pUnit, 0, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pUnit, &damage);
    }
}

// 0x005C32A0
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != IMODE_ONGROUND)
    {
        return 0;
    }

    if (!ITEMS_IsMetalItem(pTarget->dwClassId))
    {
        return 0;
    }

    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 256, ".\\SKILLS\\SkillNec.cpp"))
    {
        return 0;
    }

    return !STATLIST_GetOwner(pTarget, 0);
}

// 0x005C34B0
void __fastcall sub_005C34B0_ExecuteCurseTargetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        AITHINK_ExecuteAiFn(pGame, pTarget, AIGENERAL_GetAiControlFromUnitInline(pTarget), AiSpecialStateFromAuraState(pSkillsTxtRecord->wAuraTargetState));
    }
}

// 0x005C3540
int __fastcall sub_6FD0B3D0(D2UnitStrc* pUnit, int nStatId, int nResist)
{
    switch (nStatId)
    {
    case STAT_DAMAGERESIST:
    case STAT_MAGICRESIST:
    case STAT_FIRERESIST:
    case STAT_LIGHTRESIST:
    case STAT_COLDRESIST:
    case STAT_POISONRESIST:
        if (nResist > 0 || pUnit && pUnit->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pUnit) || STATLIST_GetUnitBaseStat(pUnit, nStatId, 0) < 100)
        {
            break;
        }

        return nResist / 5;

    default:
        break;
    }

    return nResist;
}

// 0x005C50C0
void __fastcall sub_005C50C0_SetSummonStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel)
{
    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
}

// 0x005C6C50
void __fastcall sub_6FCFE030(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList)
{
    sub_6FD11C90(pUnit, nStateId, 1);

    if (!pStatList)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (!pSkill)
    {
        return;
    }

    SKILLS_SetSkillMode(pSkill, sub_005C6BF0_GetConvertedMode(pUnit, 10));
    STATES_ToggleState(pUnit, nStateId, 0);
}

// 0x005C72F0
int __fastcall SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return sub_6FCFE4C0(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 0);
}

// 0x005C8FA0
int __fastcall SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_INFERNO) && STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < pSkillsTxtRecord->wStartMana << 8)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return SKILLS_StartInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
}

// 0x005C91C0
int __fastcall SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, -1);
    SKILLS_SetParam2(pSkill, 1);
    return 1;
}

// build: context SKILLS_SrvSt14_Hydra
int __fastcall SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    return pRoom && !DUNGEON_IsRoomInTown(pRoom);
}

// 0x005C9640
int __fastcall SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return SKILLS_DoInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
}

// 0x005CA360
int __fastcall SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (pLevelsTxtRecord && pLevelsTxtRecord->nTeleport != 0 && (pLevelsTxtRecord->nTeleport != 2 || !sub_006229F0_IsRayFreeFromUnit(pUnit, nTargetX, nTargetY, COLLIDE_MASK_PLAYER_FLYING)))
    {
        return sub_6FCBDFE0(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
    }

    return 0;
}

// 0x005CAF30
int __fastcall SKILLS_SrvDo083_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);
    return sub_0056F640_StartSkill(pGame, pUnit, nSkillId, nSkillLevel, 0);
}

// 0x005CBC80
int __fastcall SKILLS_SrvDo090_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x005CBF30
int __fastcall SKILLS_SrvSt50_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0x00, sizeof(damage));
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

// 0x005CC1F0
int __fastcall SKILLS_SrvDo094_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;

    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x005CC240
int __fastcall SKILLS_SrvSt53_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nDelay < 1)
    {
        nDelay = 1;
    }

    SKILLS_SetParam1(pSkill, nDelay + pGame->dwGameFrame);

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
    }

    return 1;
}

// 0x005CCC80
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            pRoom = UNITS_GetRoom(pOwner);
        }
    }

    if (!sub_6FCBDFE0(pGame, pUnit, pRoom, nX, nY, 0, 0))
    {
        return 0;
    }

    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlagEx |= UNITFLAGEX_TELEPORTED;
    return 1;
}

// 0x005CD870
int __fastcall SKILLS_SrvDo106_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    sub_6FD14170(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel));
    return 1;
}

// 0x005CDD30
int __fastcall SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc* pUnit)
{
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit))
    {
        const int nMax = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
        const int nCurrent = pUnit->dwSeqFrame >> 8;
        for (int i = nCurrent + 1; i < nMax; ++i)
        {
            int nEvent;
            DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nCurrent << 8, &nEvent);
            if (nEvent)
            {
                return nEvent;
            }
        }
    }
    else
    {
        const int nMax = pUnit->dwFrameCountPrecise >> 8;
        const int nCurrent = pUnit->nSeqCurrentFramePrecise >> 8;
        if (nMax > pUnit->pAnimData->dwFrames)
        {
            return 0;
        }

        for (int i = nCurrent + 1; i < nMax; ++i)
        {
            if (pUnit->pAnimData->pFrameFlags[nCurrent])
            {
                return pUnit->pAnimData->pFrameFlags[nCurrent];
            }
        }
    }

    return 0;
}

// 0x005CF8C0
int __fastcall sub_005CF8C0_GetSeqEventFrame(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pMonSeqTxtRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pMonSeqTxtRecord)
    {
        const int nSequenceFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nSequenceFrameCount; ++i)
        {
            if (!pMonSeqTxtRecord->nEvent)
            {
                return i - 1;
            }
        }
    }

    return 7;
}

// 0x005D1280
int __fastcall SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    SKILLS_SetParam1(pSkill, nTimeout + pGame->dwGameFrame);

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
    }

    return 1;
}

// 0x005D2140
int __fastcall SKILLS_CanImpregnateTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    int nBaseId = sub_00463860(pTarget);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    switch (nBaseId)
    {
    case 546:
    case 551:
        return 0;
    }

    if (STATES_CheckState(pTarget, 110))
    {
        return 0;
    }

    return STATLIST_GetUnitAlignment(pTarget) != 2;
}

// 0x005D30A0
D2MonEquipTxt* __fastcall sub_005D30A0_GetMonEquipTxtRecord(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonEquipTxtRecordId < 0)
    {
        return 0;
    }

    return &sgptDataTables->pMonEquipTxt[pMonStatsTxtRecord->nMonEquipTxtRecordId];
}

// build: context SKILLS_SrvSt22_PsychicHammer
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_IsRoomInTown(pUnitRoom))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pTargetUnit);
    if (DUNGEON_IsRoomInTown(pTargetRoom))
    {
        return 0;
    }

    if (pTargetUnit->dwUnitType != UNIT_PLAYER && pTargetUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    return 1;
}

// build: context SKILLS_GetProgressiveSkillMissileId
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                if (nIndex > 1)
                {
                    if (nIndex >= 3)
                    {
                        nIndex = 3;
                    }
                }
                else
                {
                    nIndex = 1;
                }

                return (&pSkillsTxtRecord->wSrvMissile)[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wSrvMissileA;
}

// 0x005DC5C0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* hUnit, int nX, int nY)
{
    D2_ASSERT(hUnit, 267);
    D2DynamicPathStrc* hPath = hUnit->pDynamicPath;
    D2_ASSERT(hPath, 270);

    int nXDiff = PATH_GetXPosition(hPath) - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    int nYDiff = PATH_GetYPosition(hPath) - nY;
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x005DC920
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return 14;

    case UNIT_MONSTER:
    {
        const int nClassId = pUnit->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nThreat;
        }
        break;
    }

    default:
        break;
    }

    return 0;
}

// 0x005FCF30
void __fastcall sub_005FCF30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005FD0F0
void __fastcall AIBAAL_SpawnUberBaalMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc coord;
    coord.nX = UNITS_GetUnitXPosition(pUnit);
    coord.nY = UNITS_GetUnitYPosition(pUnit);

    const int nMinionTypes[3] = { 0x2DC, 0x2DB, 0x2DD };
    const int nMinionModes[3] = { 1, 7, 8 };
    const int nChoice = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 1;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coord, 2, 0x100, 0);
    if (pRoom)
    {
        D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, coord.nX, coord.nY, nMinionTypes[nChoice], nMinionModes[nChoice], -1, 0);
        if (pMinion)
        {
            pMinion->dwFlags |= 0x4000000;
            STATES_ToggleState(pMinion, 0xB8, 1);
        }
    }
}

// 0x005FD200
void __fastcall AITHINK_Fn145_UberBaal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}

static __forceinline int GetMonsterBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsTxtRecord(nId);
    if (!pRecord)
        return nId;
    return pRecord->nBaseId;
}

static __forceinline int ValidateMonsterId(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        return nId;
    return -1;
}

// 0x005FD350
int __fastcall sub_005FD350_CheckMonsterCollision(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int nFlag)
{
    switch (ValidateMonsterId(GetMonsterBaseId(nMonsterId)))
    {
    case 206:
    {
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY + 3);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nX, nY + 3, 2, 0x3C01))
            return 0;
        break;
    }
    case 228:
        nY += 2;
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!pRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    case 298:
        if (!nFlag)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
            if (!pRoom)
                return 0;
            if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 2, 0x3C01))
                return 0;
        }
        break;
    case 334:
    {
        int nAdjustedX = nX - 2;
        int nAdjustedY = nY - 2;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nAdjustedX, nAdjustedY);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nAdjustedX, nAdjustedY, 2, 0x1C0))
            return 0;
        break;
    }
    case 528:
    {
        nX += 2;
        nY += 4;
        D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!pTargetRoom)
            return 0;
        if (COLLISION_CheckMaskWithSize(pTargetRoom, nX, nY, 2, 0x3C01))
            return 0;
        break;
    }
    }
    return 1;
}

// 0x005FD9C0
int __fastcall sub_005FD9C0_SelectSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID)
{
    D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    D2UnitStrc* pTarget = sub_6FD15210(pUnit, pCurrentTarget, nSkillId, nSkillLevel);
    if (!pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    if (pUnitType)
    {
        *pUnitType = pTarget->dwUnitType;
        *pUnitGUID = pTarget->dwUnitId;
    }
    return 1;
}

// 0x005FDA10
int __fastcall sub_005FDA10_TargetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2, int* pTargetType, int* pTargetGUID)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        if (pTargetType)
        {
            int nTargetType = 6;
            if (pTarget)
            {
                nTargetType = pTarget->dwUnitType;
            }
            *pTargetType = nTargetType;
            unsigned int nTargetGUID;
            if (!pTarget)
            {
                nTargetGUID = 0xFFFFFFFFu;
            }
            else
            {
                nTargetGUID = pTarget->dwUnitId;
            }
            *pTargetGUID = nTargetGUID;
        }
    }
    return 1;
}

// 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5)
{
    if (!pUnit || !pTargetUnit)
    {
        return 0;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    int nTargetUnitType = UNIT_INVALID;
    int nTargetUnitGUID = -1;
    int nTargetX;
    int nTargetY;
    if (!sub_005FDA80_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, pTargetUnit, 0, 0, &nTargetUnitType, &nTargetUnitGUID, &nTargetX, &nTargetY, a5))
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (nTargetUnitType == UNIT_INVALID)
    {
        nUnitType = pTargetUnit->dwUnitType;
        nUnitGUID = pTargetUnit->dwUnitId;
    }
    else
    {
        nUnitType = nTargetUnitType;
        nUnitGUID = nTargetUnitGUID;
    }

    sub_6FCC60D0(pUnit, nSkillId, nSkillLevel, nUnitType, nUnitGUID, a5);
    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillItem.inc"
