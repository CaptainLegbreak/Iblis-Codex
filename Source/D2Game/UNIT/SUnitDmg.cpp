#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"

#define UNIT_MONSTER 1

#define MONSTATS2FLAGINDEX_DEADCOL_0057AF00 0x13

#define STAT_ITEM_DEMONDAMAGE_PERCENT 121

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_OBJECT 2

#define ITEMTYPE_GOLD 4

#define ITEMQUAL_NORMAL 2

#define STAT_STAMINA 10

#define OBJECT_FIRE_SMALL 160

#define OBJECT_FIRE_LARGE 162

#define OBJMODE_NEUTRAL 0

#define OBJMODE_OPERATING 1

#define OBJMODE_OPENED 2

#define EVENTTYPE_ENDANIM 1

#define EVENTTYPE_QUESTFN 7

#define UNITFLAG_TARGETABLE 0x00000002

#define UNITFLAG_SKSRVDOFUNC 0x00000040

#define GOLD_PILE_COUNT 32

#define UNIT_PLAYER 0

#define STAT_HITPOINTS 6

#define DAMAGEHITFLAG_2 2

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

#define DAMAGERESULTFLAG_WILLDIE 0x02

#define UNIT_INVALID 6

#define STAT_LEVEL 12

struct D2CombatStrc;

struct D2ObjectControlStrc;

struct D2MonStatsTxt;

struct D2MonsterDataStrc;

struct D2UnkDamageRecordStrc;

struct D2StatReduceCtx;

struct D2StatReduceRec;

struct Context;

struct Record;

struct D2DrlgCoordsStrc;

struct D2CurseStrc;

struct D2ObjOperateFnStrc;

union D2SeedStrc;

struct D2DamageStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct Unit;

struct D2CoordStrc;

struct D2ObjectsTxt;

struct D2PetInfoStrc;

struct D2HirelingTxt;

struct D2PartyExpStrc;

struct D2CombatStrc
{
    D2GameStrc* pGame;
    int dwAttackerType;
    int dwAttackerId;
    int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

struct D2UnkDamageRecordStrc
{
    int unk0x00[3];
    int nValue;
};

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

struct D2StatReduceCtx
{
    int unk0x00;
    int unk0x04;
    D2UnitStrc* pUnit;
    int unk0x0C;
    int unk0x10;
    int bCapped;
};

struct D2StatReduceRec
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nStatId;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

static __declspec(noinline) int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue);

struct Unit
{
    int type;
};

struct Context
{
    Game* game;
    Difficulty* difficulty;
    Unit* attacker;
    Unit* defender;
    int attackerFlag;
    int defenderFlag;
    Damage* damage;
    int zeroReduction;
    int flatReduction1;
    int flatReduction2;
};

extern Record gVar_00732980_Records[12]; // 0x00732980

extern int __fastcall sub_00451F30_HasFlags(Unit*,unsigned int); // 0x00451F30

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

__declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FAF0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest); // 0x005540A0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130

void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x005594C0

D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x00559630

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660

int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0

typedef char chkCombatNext_M125[(int)&((D2CombatStrc*)0)->pNext == 0x84 ? 1 : -1];

typedef char chkUnitCombat_M125[(int)&((D2UnitStrc*)0)->pCombat == 0xAC ? 1 : -1];

struct D2HirelingTxt
{
    char unk0x00[0x20];
    int dwExpPerLvl;
};

struct D2PartyExpStrc
{
    D2UnitStrc* pDefenderUnit;
    D2UnitStrc* pMembers[8];
    int nMemberLevels[8];
    int nMembers;
    int nLevelSum;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570880

int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc*, D2UnitStrc*, void*);

void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0

void __fastcall SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x0057E5A0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, int nLevel); // 0x00572840

void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x005726C0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

struct T0057E5A0 {
    D2UnitStrc* pReference;
    D2UnitStrc* players[8];
    int levels[8];
    int count, totalLevel;
};

int __stdcall PATH_GetX(D2DynamicPathStrc* path); // 0x006488C0

int __stdcall PATH_GetY(D2DynamicPathStrc* path); // 0x00648900

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* unit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* unit); // 0x0045AE20

struct D2BodyLocWeightStrc
{
    int nBodyLoc;
    int nWeight;
};

extern D2BodyLocWeightStrc gaBodyLocWeights_00732B90[];                                                     // 0x00732B90

extern int gnBodyLocWeightCount_00732BC8;                                                                   // 0x00732BC8

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0

void __fastcall sub_00559E30_DecreaseDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);           // 0x00559E30

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __fastcall SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005D10C0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40

int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

#define D2MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2SkillsTxt;

struct D2ModeChangeStrc;

struct D2DamageHitClassMappingStrc;

extern "C" const D2DamageHitClassMappingStrc gsDamageHitClassMapping_006E16D8[8]; // 0x006E16D8

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A54F0

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0


void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A43A0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit); // 0x006223F0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2); // 0x0057A830

void __fastcall sub_005347B0_Stub5(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nChance, int nRand); // 0x005347B0

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

static unsigned char s_nHitClassCounter_0088CAD0; // 0x0088CAD0

#define STAT_ITEM_UNDEADDAMAGE_PERCENT 122

#define STAT_MANA 8

#define STAT_DAMAGE_VS_MONTYPE 180

#define PLRMODE_DEATH 0

#define PLRMODE_DEAD 17

#define MONMODE_DEATH 0

#define MONMODE_DEAD 12

#define MONSTATSFLAGINDEX_KILLABLE 15

#define MONSTATS2FLAGINDEX_OBJCOL 18

#define MONSTER_BARRICADEDOOR1 432

#define MONSTER_BARRICADEDOOR2 433

struct D2DifficultyLevelsTxt;

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x14];
    int dwMonsterFreezeDiv;
    int dwMonsterColdDiv;
    char unk0x1C[0x0C];
    int dwLifeStealDiv;
    int dwManaStealDiv;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057AD80

int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30

void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057B170

void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4390

void __fastcall sub_6FCF8DD0(D2UnitStrc* pUnit); // 0x005D6410

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x00625310

int __stdcall STATLIST_GetExpireFrame(D2StatListStrc* pStatList); // 0x00625330

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210

static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass); // 0x0057CE30

static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage); // 0x0057CEC0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __fastcall sub_6FC7D470(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x005751A0

void __fastcall sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame); // 0x005A4EF0

void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0053F720

void __stdcall sub_0066A220_Stub(D2UnitStrc* pPlayer, int nMonsterId); // 0x0066A220

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker); // 0x00543A30

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0057A830
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 31];
    }

    return 0;
}

// 0x0057A880
static int __stdcall sub_0057A880_AddRolledDamage(D2UnitStrc* pUnit, int nMin, int nMaxPct, int nMax, int nDamage, int nMinPct)
{
    if (nMax > 0)
    {
        nMin += DATATBLS_ApplyRatio(nMin, nMinPct, 100);
        nMax += DATATBLS_ApplyRatio(nMax, nMaxPct, 100);
        nDamage += nMin;
        if (nMax > nMin)
        {
            nDamage += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin);
        }
    }

    return nDamage < 0 ? 0 : nDamage;
}

// 0x0057A8E0
static int __stdcall sub_0057A8E0_AddStatDamage(int nStatMin, int nStatPct, int nMinPct, int nMaxPct, int nDamage, int nStatMax, D2UnitStrc* pUnit)
{
    const int nMax = STATLIST_UnitGetStatValue(pUnit, nStatMax, 0) << 8;
    if (nMax < 8)
    {
        return nDamage < 0 ? 0 : nDamage;
    }

    const int nMin = STATLIST_UnitGetStatValue(pUnit, nStatMin, 0) << 8;
    if (nStatPct != -1)
    {
        const int nPct = STATLIST_UnitGetStatValue(pUnit, nStatPct, 0);
        nMinPct += nPct;
        nMaxPct += nPct;
    }

    return sub_0057A880_AddRolledDamage(pUnit, nMin, nMaxPct, nMax, nDamage, nMinPct);
}

// calling-convention shim (not game code)
static __forceinline unsigned int sub_I19_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __declspec(noinline) int __stdcall SUNITDMG_AddLeechedLife(D2UnitStrc* pUnit, int nLifeLeeched)
{
    if (nLifeLeeched <= 0)
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_DEATH_DELAY))
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int nHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nNewHp = (nHp + nLifeLeeched < nMaxHp) ? nHp + nLifeLeeched : nMaxHp;
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

    if (nNewHp != nMaxHp)
    {
        return nLifeLeeched;
    }

    return nMaxHp - nHp;
}

static __declspec(noinline) int __stdcall SUNITDMG_AddLeechedMana(D2UnitStrc* pUnit, int nManaLeeched)
{
    if (nManaLeeched <= 0)
    {
        return 0;
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nNewMana = (nMana + nManaLeeched < nMaxMana) ? nMana + nManaLeeched : nMaxMana;
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

    if (nNewMana != nMaxMana)
    {
        return nManaLeeched;
    }

    return nMaxMana - nMana;
}

static __declspec(noinline) int sub_0057AA60_DrainMana(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain <= 0)
    {
        return 0;
    }

    int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) - nDrain;
    if (nMana < DRAIN_MIN)
    {
        nMana = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    return nMana ? nDrain : 0;
}

static __declspec(noinline) int sub_0057AAA0_DrainStamina(D2UnitStrc* pUnit, int nDrain)
{
    if (nDrain <= 0)
    {
        return 0;
    }

    int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) - nDrain;
    if (nStamina < 0 || nStamina < DRAIN_MIN)
    {
        nStamina = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nStamina, 0);
    return nStamina ? nDrain : 0;
}

// 0x0057AAE0
static __declspec(noinline) void __stdcall sub_0057AAE0_ApplyStun(D2UnitStrc* pAttacker, int nStunLength, D2UnitStrc* pDefender)
{
    if (nStunLength <= 0)
    {
        return;
    }

    if (pDefender && pDefender->dwUnitType == 1)
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 8) && (int)(sub_I19_RollSeedInline(&pAttacker->pSeed) % 100) < 90)
        {
            return;
        }

        if (MONSTERS_IsBoss(0, pDefender))
        {
            return;
        }

        if (!DATATBLS_GetMonStatsTxtRecord(pDefender->dwClassId)->nVelocity)
        {
            return;
        }

        if (MONSTERS_GetHirelingTypeId(pDefender) && nStunLength >= 13)
        {
            nStunLength = 13;
        }
        else if (nStunLength > 250)
        {
            nStunLength = 250;
        }
    }
    else if (nStunLength > 250)
    {
        nStunLength = 250;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 21);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    const int nStunEndFrame = pGame->dwGameFrame + nStunLength;
    if (!pStatList)
    {
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nStunEndFrame, !pAttacker ? 6 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId);
        EVENT_SetEvent(pGame, pDefender, 12, nStunEndFrame, 0, 0);
        STATLIST_SetState(pNewStatList, 21);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
        STATES_ToggleState(pDefender, 21, 1);
    }
    else
    {
        STATLIST_SetExpireFrame(pStatList, nStunEndFrame);
        EVENT_SetEvent(pGame, pDefender, 12, nStunEndFrame, 0, 0);
    }
}

// 0x0057AD80
void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (!SUNIT_IsDead(pUnit))
    {
        STATES_ToggleState(pUnit, 107, 0);
    }

    UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\SUnitDmg.cpp", 338);
}

// 0x0057AF00
static __declspec(noinline) int sub_0057AF00_IsMonsterWithoutDeadCol(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return !sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_DEADCOL_0057AF00);
}

// 0x0057AF30
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return -50;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return -50;
    }

    return pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty];
}

static __declspec(noinline) void __stdcall SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, int nPoisonDamage, int nPoisonLength, D2UnitStrc* pDefender)
{
    if (nPoisonLength <= 0 || nPoisonDamage <= 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 2);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    if (pDefender && pDefender->dwUnitType == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 3, 0);
        EVENT_SetEvent(pGame, pDefender, 3, pGame->dwGameFrame + 1, 0, 0);
    }

    const int nExpireFrame = pGame->dwGameFrame + nPoisonLength;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 2, 1);
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, pAttacker ? pAttacker->dwUnitType : 6, pAttacker ? pAttacker->dwUnitId : -1);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
        sub_006270B0(pNewStatList, 0x4A, -nPoisonDamage, 0);
        STATLIST_SetState(pNewStatList, 2);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
    }
    else if (-STATLIST_GetStatValue(pStatList, 0x4A, 0) <= nPoisonDamage)
    {
        D2COMMON_10476(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
        STATLIST_SetStat(pStatList, 0x4A, -nPoisonDamage, 0);
    }
}

static __declspec(noinline) void __stdcall SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, int nBurnDamage, int nBurnLength, D2UnitStrc* pDefender)
{
    if (nBurnLength <= 0 || nBurnDamage <= 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 0x73);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    if (pDefender && pDefender->dwUnitType == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 3, 0);
        EVENT_SetEvent(pGame, pDefender, 3, pGame->dwGameFrame + 1, 0, 0);
    }

    const int nExpireFrame = pGame->dwGameFrame + nBurnLength;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 0x73, 1);
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, pAttacker ? pAttacker->dwUnitType : 6, pAttacker ? pAttacker->dwUnitId : -1);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
        sub_006270B0(pNewStatList, 0x4A, -nBurnDamage, 0);
        STATLIST_SetState(pNewStatList, 0x73);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
    }
    else if (-STATLIST_GetStatValue(pStatList, 0x4A, 0) <= nBurnDamage)
    {
        D2COMMON_10476(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
        STATLIST_SetStat(pStatList, 0x4A, -nBurnDamage, 0);
    }
}

// 0x0057AF80
static __declspec(noinline) void __stdcall SUNITDMG_ApplyColdState(D2UnitStrc* pAttacker, int nColdLength, D2UnitStrc* pDefender)
{
    if (nColdLength <= 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 11);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    int nColdEffect;
    if (!pDefender || pDefender->dwUnitType != 1)
    {
        nColdEffect = -50;
    }
    else
    {
        const int nClassId = pDefender->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
        if (!pMonStatsTxtRecord)
        {
            nColdEffect = -50;
        }
        else
        {
            nColdEffect = pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty];
        }
    }

    if (!nColdEffect)
    {
        return;
    }

    if (pDefender && pDefender->dwUnitType == 1 && nColdEffect < 0)
    {
        const int nColdDivisor = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterColdDiv;
        if (nColdDivisor)
        {
            nColdLength /= nColdDivisor;
        }
    }

    nColdLength = (nColdLength > 1) ? nColdLength : 1;

    const int nExpireFrame = pGame->dwGameFrame + nColdLength;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 11, 1);

        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pAttacker ? 6 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
        STATLIST_SetState(pNewStatList, 11);
        STATLIST_SetStatRemoveCallback(pNewStatList, SUNITDMG_RemoveShatterState);
        D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
        sub_006270B0(pNewStatList, 0x43, nColdEffect, 0);
        sub_006270B0(pNewStatList, 0x44, nColdEffect, 0);
        sub_006270B0(pNewStatList, 0x45, nColdEffect, 0);
        UnitUpdateAnimRateAndVel(pDefender, ".\\UNIT\\SUnitDmg.cpp", 0x1DC);
    }
    else if (STATLIST_GetExpireFrame(pStatList) < nExpireFrame)
    {
        STATLIST_SetExpireFrame(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
    }

    if ((int)(sub_I19_RollSeedInline(&pDefender->pSeed) % 100) < 20 && pDefender && pDefender->dwUnitType == 1
        && !sub_004638A0_CheckMonStats2Flag(pDefender->dwClassId, 0x13))
    {
        STATES_ToggleState(pDefender, 0x6B, 1);
        return;
    }

    STATES_ToggleState(pDefender, 0x6B, 0);
}

int __fastcall sub_M424_Emit_0057AF00(D2UnitStrc* pUnit, int nBias)
{
    return sub_0057AF00_IsMonsterWithoutDeadCol(pUnit) + nBias;
}

// 0x0057B170
void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    SUNIT_SetCombatMode(SUNIT_GetGameFromUnit(pUnit), pUnit, 1);

    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
        if (pMonStatsTxtRecord)
        {
            int nAiDelay;
            if (!pGame->nGameType && !pGame->dwGameType)
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[0];
            }
            else
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
            }

            if (nAiDelay <= 0)
            {
                nAiDelay = 15;
            }

            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x0057B630
static void __stdcall sub_0057B630_AddDemonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    if (MONSTERS_IsDemon(pTarget))
    {
        const int nBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
        if (nBonus > 0)
        {
            pRecord->nValue += nBonus;
        }
    }
}

// 0x0057B660
static void sub_0057B660_AddUndeadDamagePercent(D2DamageStrc* pDamage, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (MONSTERS_IsUndead(pDefender))
    {
        int nPct = 0;
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        if (pWeapon && ITEMSIsA(pWeapon, ITEMTYPE_BLUNT))
        {
            nPct = 50;
        }

        nPct += STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
        if (nPct > 0)
        {
            pDamage->dwEnDmgPct += nPct;
        }
    }
}

void __stdcall sub_A08_EmitDamageHelpers(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a, int b, int c, int d, int e, int f)
{
    pDamage->dwPhysDamage = sub_0057A8E0_AddStatDamage(a, b, c, d, pDamage->dwPhysDamage, f, pAttacker);
    pDamage->dwFireDamage = sub_0057A8E0_AddStatDamage(b, c, d, e, pDamage->dwFireDamage, a, pAttacker);
    pDamage->dwEnDmgPct = sub_0057A880_AddRolledDamage(pAttacker, a, b, c, pDamage->dwEnDmgPct, d);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pAttacker, pDefender);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pDefender, pAttacker);
}

// build: context SUNITDMG_ApplyFreezeState
static __declspec(noinline) void __stdcall SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, int nFreezeLength, D2UnitStrc* pDefender)
{
    if (nFreezeLength <= 0)
    {
        return;
    }

    int nDefenderType = 6;
    if (pDefender)
    {
        nDefenderType = pDefender->dwUnitType;
    }

    switch (nDefenderType)
    {
    case 0:
        SUNITDMG_ApplyColdState(pAttacker, nFreezeLength, pDefender);
        return;

    case 1:
        if (STATES_CheckState(pDefender, 0x36))
        {
            return;
        }

        if (MONSTERS_IsBoss(DATATBLS_GetMonStatsTxtRecord(!pDefender ? -1 : pDefender->dwClassId), pDefender) || MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 8))
        {
            SUNITDMG_ApplyColdState(pAttacker, nFreezeLength, pDefender);
            return;
        }

        if (MONSTERS_GetHirelingTypeId(pDefender))
        {
            SUNITDMG_ApplyColdState(pAttacker, nFreezeLength, pDefender);
            return;
        }
        break;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 1);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    if (SUNITDMG_GetColdEffect(pGame, pDefender) >= 0)
    {
        return;
    }

    if (pDefender && pDefender->dwUnitType == 1)
    {
        const int nFreezeDivisor = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterFreezeDiv;
        D2_ASSERT(nFreezeDivisor, 0x254);
        nFreezeLength /= nFreezeDivisor;
    }

    int nExpireFrame = pGame->dwGameFrame + nFreezeLength;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 1, 1);

        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pAttacker ? 6 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId);
        STATLIST_SetState(pNewStatList, 1);
        STATLIST_SetStatRemoveCallback(pNewStatList, SUNITDMG_RemoveFreezeState);
        D2COMMON_10475_PostStatToStatList(pDefender, pNewStatList, 1);
    }
    else
    {
        const int nStatListExpireFrame = STATLIST_GetExpireFrame(pStatList);
        if (nStatListExpireFrame < nExpireFrame)
        {
            STATLIST_SetExpireFrame(pStatList, nExpireFrame);
        }
        else
        {
            nExpireFrame = nStatListExpireFrame;
        }
    }

    EVENT_SetEvent(pGame, pDefender, 12, nExpireFrame, 0, 0);
    D2_ASSERT((pDefender ? pDefender->dwUnitType : 6) == 1, 0x276);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 2, 0);
    EVENT_SetEvent(pGame, pDefender, 2, pGame->dwGameFrame + nFreezeLength + 1, 0, 0);
}

static __declspec(noinline) void __stdcall sub_0057C420_ApplyLeech(D2UnitStrc* pDefender, D2GameStrc* pGame, D2UnitStrc* pAttacker, D2DamageStrc* pDamage)
{
    if (!pDamage->dwLifeLeech && !pDamage->dwManaLeech)
    {
        return;
    }

    int nDrain;
    if (!pDefender || pDefender->dwUnitType != 1)
    {
        nDrain = 100;
    }
    else
    {
        if (!pDefender->pMonsterData || !pDefender->pMonsterData->pMonstatsTxt)
        {
            return;
        }

        nDrain = pDefender->pMonsterData->pMonstatsTxt->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return;
        }
    }

    pDamage->dwLifeLeech <<= 6;
    pDamage->dwManaLeech <<= 6;

    int nUnitType = 0;
    if (pAttacker && pAttacker->dwUnitType == 0)
    {
        D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(SUNIT_GetGameFromUnit(pAttacker)->nDifficulty);
        if (pDifficultyLevelsTxtRecord->dwLifeStealDiv)
        {
            pDamage->dwLifeLeech /= pDifficultyLevelsTxtRecord->dwLifeStealDiv;
        }

        if (pDifficultyLevelsTxtRecord->dwManaStealDiv)
        {
            pDamage->dwManaLeech /= pDifficultyLevelsTxtRecord->dwManaStealDiv;
        }
    }
    else if (!pAttacker || pAttacker->dwUnitType != 1 || !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        nUnitType = pAttacker ? pAttacker->dwUnitType : 6;
        int nClassId = pAttacker ? pAttacker->dwClassId : -1;
        int nAnimMode = pAttacker ? pAttacker->dwAnimMode : 0;
        D2COMMON_11013_ConvertMode(pAttacker, &nUnitType, &nClassId, &nAnimMode, ".\\UNIT\\SUnitDmg.cpp", 0x64C);
    }

    if (!nUnitType)
    {
        const int nPhysDamage = pDamage->dwPhysDamage;
        int bManaLeeched = 0;
        if (nPhysDamage <= 0)
        {
            return;
        }

        if (pDamage->dwManaLeech)
        {
            int nLeechedMana = DATATBLS_ApplyRatio(nPhysDamage, pDamage->dwManaLeech, 100);
            if (nDrain != 100)
            {
                nLeechedMana = DATATBLS_ApplyRatio(nLeechedMana, nDrain, 100);
            }

            SUNITDMG_AddLeechedMana(pAttacker, nLeechedMana / 64);
            bManaLeeched = 1;
        }

        if (pDamage->dwLifeLeech)
        {
            int nLeechedHp = DATATBLS_ApplyRatio(nPhysDamage, pDamage->dwLifeLeech, 100);
            if (nDrain != 100)
            {
                nLeechedHp = DATATBLS_ApplyRatio(nLeechedHp, nDrain, 100);
            }

            SUNITDMG_AddLeechedLife(pAttacker, nLeechedHp / 64);
            if (bManaLeeched)
            {
                if (SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 2))
                {
                    UNITS_SetOverlay(pAttacker, 0x98, 0);
                }
                else
                {
                    UNITS_SetOverlay(pAttacker, 0x97, 0);
                }
            }
            else
            {
                UNITS_SetOverlay(pAttacker, 0x97, 0);
            }
        }
        else if (bManaLeeched)
        {
            UNITS_SetOverlay(pAttacker, 0x98, 0);
        }
    }
    else
    {
        const int nMana = STATLIST_UnitGetStatValue(pDefender, 8, 0);
        const int nStamina = STATLIST_UnitGetStatValue(pDefender, 10, 0);
        pDamage->dwLifeLeech /= 64;
        pDamage->dwManaLeech /= 64;
        const int nLifeLeech = (pDamage->dwLifeLeech < pDamage->dwPhysDamage) ? pDamage->dwLifeLeech : pDamage->dwPhysDamage;
        const int nManaLeech = (pDamage->dwManaLeech < nMana) ? pDamage->dwManaLeech : nMana;
        const int nStaminaLeech = (pDamage->dwStamLeech < nStamina) ? pDamage->dwStamLeech : nStamina;
        int nTotalLeech = nLifeLeech + nManaLeech + nStaminaLeech;
        if (nTotalLeech)
        {
            if (nDrain != 100)
            {
                nTotalLeech = DATATBLS_ApplyRatio(nTotalLeech, nDrain, 100);
            }

            const int nMissingHp = STATLIST_GetMaxLifeFromUnit(pAttacker) - STATLIST_UnitGetStatValue(pAttacker, 6, 0);
            nTotalLeech = (nTotalLeech < nMissingHp) ? nTotalLeech : nMissingHp;
            if (nTotalLeech > 0)
            {
                STATLIST_AddUnitStat(pAttacker, 6, nTotalLeech, 0);
                UNITS_SetOverlay(pAttacker, 0x97, 0);
            }
        }
    }
}

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage)
{
    if (!SUNIT_AreUnitsHostile(pGame, pAttacker, pDefender) && !(pDamage->dwHitFlags & 0x1000))
    {
        pDamage->wResultFlags &= (unsigned short)~(1 | 2);
        return;
    }

    if (!UNITS_GetRoom(pDefender))
    {
        pDamage->wResultFlags &= (unsigned short)~(1 | 2);
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pDefender)))
    {
        if (!pAttacker || pAttacker->dwUnitType != 1)
        {
            pDamage->wResultFlags &= (unsigned short)~2;
            return;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[2]))
        {
            pDamage->wResultFlags &= (unsigned short)~2;
            return;
        }
    }

    int nAttackerUnitType;
    if (!pAttacker)
    {
        nAttackerUnitType = 6;
    }
    else
    {
        nAttackerUnitType = pAttacker->dwUnitType;
    }

    int nDefenderUnitType;
    if (!pDefender)
    {
        nDefenderUnitType = 6;
    }
    else
    {
        nDefenderUnitType = pDefender->dwUnitType;
        if (nDefenderUnitType == 1 && !sub_00457490_CheckMonStatsFlag(pDefender->dwClassId, 15))
        {
            return;
        }
    }

    if (SUNIT_IsDead(pDefender))
    {
        return;
    }

    UNITS_StoreLastAttacker(pDefender, pAttacker);

    if (bMissile)
    {
        SUNITDMG_CalculateTotalDamage(pGame, pAttacker, pDefender, pDamage);
    }

    if (!(pDamage->wResultFlags & 0x20) && pDamage->wResultFlags & 1)
    {
        if (bMissile)
        {
            if (pDamage->dwHitFlags & 0x20)
            {
                if (!(pDamage->dwHitFlags & 0x80))
                {
                    SUNITEVENT_Trigger(pGame, 6, pAttacker, pDefender, pDamage);
                }
                SUNITEVENT_Trigger(pGame, 2, pDefender, pAttacker, pDamage);
            }
        }
        else
        {
            SUNITEVENT_Trigger(pGame, 5, pAttacker, pDefender, pDamage);
            SUNITEVENT_Trigger(pGame, 1, pDefender, pAttacker, pDamage);
        }
    }

    const int nPhysDamage = pDamage->dwPhysDamage;
    pDamage->dwPhysDamage = (nPhysDamage < STATLIST_UnitGetStatValue(pDefender, 6, 0)) ? nPhysDamage : STATLIST_UnitGetStatValue(pDefender, 6, 0);

    sub_0057C420_ApplyLeech(pDefender, pGame, pAttacker, pDamage);

    if (nAttackerUnitType == 1 && pDamage->wResultFlags & 1)
    {
        MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(pGame, pAttacker);
    }

    SUNITDMG_AddLeechedLife(pDefender, pDamage->dwAbsLife);

    const int nDamageTotal = pDamage->dwDmgTotal;
    if (nDamageTotal > 0)
    {
        int nNewHp = STATLIST_UnitGetStatValue(pDefender, 6, 0) - nDamageTotal;
        if (nNewHp < 256)
        {
            nNewHp = 0;
        }
        STATLIST_SetUnitStat(pDefender, 6, nNewHp, 0);
    }

    sub_0057AA60_DrainMana(pDefender, pDamage->dwManaLeech);
    sub_0057AAA0_DrainStamina(pDefender, pDamage->dwStamLeech);
    sub_0057AAE0_ApplyStun(pAttacker, pDamage->dwStunLen, pDefender);
    SUNITDMG_ApplyColdState(pAttacker, pDamage->dwColdLen, pDefender);
    SUNITDMG_ApplyFreezeState(pAttacker, pDamage->dwFrzLen, pDefender);
    SUNITDMG_ApplyPoisonDamage(pAttacker, pDamage->dwPoisDamage, pDamage->dwPoisLen, pDefender);
    SUNITDMG_ApplyBurnDamage(pAttacker, pDamage->dwBurnDamage, pDamage->dwBurnLen, pDefender);

    if (STATLIST_UnitGetStatValue(pDefender, 6, 0) > 0)
    {
        pDamage->wResultFlags &= (unsigned short)~2;
        if (pDamage->dwDmgTotal && nDefenderUnitType == 1)
        {
            if (STATLIST_UnitGetStatValue(pDefender, 0x4A, 0))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 3, 0);
                EVENT_SetEvent(pGame, pDefender, 3, pGame->dwGameFrame + 1, 0, 0);
            }
            sub_6FCF8DD0(pDefender);
        }
    }
    else
    {
        pDamage->wResultFlags |= 2;
    }

    if (!(pDamage->wResultFlags & 0x20) && pDamage->wResultFlags & 2)
    {
        SUNITEVENT_Trigger(pGame, 10, pDefender, pAttacker, pDamage);
        SUNITEVENT_Trigger(pGame, 9, pAttacker, pDefender, pDamage);
    }
}

static __forceinline D2MonStatsTxt* U01_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* U01_GetUnitMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return U01_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

static __forceinline int U01_MonTypeMatches(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 0x1F];
    }

    return 0;
}

// 0x0057B6A0
static void __stdcall sub_0057B6A0_AddMonTypeDamagePercent(D2UnitStrc* pAttacker, D2DamageStrc* pDamage, D2UnitStrc* pDefender)
{
    const int nType = pDefender ? pDefender->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStats = U01_GetUnitMonStatsTxtRecord(pDefender);
        if (pMonStats && pMonStats->wMonType > 0)
        {
            D2StatStrc tStats[128];
            const int nMonType = pMonStats->wMonType;
            const int nStats = STATLIST_CopyStats(pAttacker, STAT_DAMAGE_VS_MONTYPE, tStats, 128);
            for (int i = 0; i < nStats; ++i)
            {
                if (U01_MonTypeMatches(tStats[i].nLayer, nMonType))
                {
                    pDamage->dwEnDmgPct += tStats[i].nValue;
                }
            }
        }
    }
}

void __fastcall sub_K11_Emit0057B630(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    sub_0057B630_AddDemonDamage(pAttacker, pTarget, pRecord);
}

// 0x0057BDD0
static int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int nStatId = pRec->nStatId;
    if (nStatId == -1)
    {
        return nValue;
    }

    if (nValue >= 100 && pCtx->bCapped)
    {
        return nValue;
    }

    int nStat = STATLIST_UnitGetStatValue(pCtx->pUnit, nStatId, 0);
    if (!nStat)
    {
        return nValue;
    }

    return nValue - nStat;
}

int __fastcall sub_Emit_0057BDD0(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int n = sub_0057BDD0_ReduceByStat(pCtx, pRec, nValue);
    return n + sub_0057BDD0_ReduceByStat(pCtx, pRec + 1, n);
}

static __declspec(noinline) int __cdecl sub_0057BE00_Resistance(Context* c,Record* r)
{
    int resistance=0;
    if(r->resistanceStat!=-1)
        resistance=sub_00625480_Stat(c->defender,r->resistanceStat,0);
    if(r->pierceStat!=-1 && (resistance<100 || !c->defenderFlag))
    {
        int pierce=sub_00625480_Stat(c->attacker,r->pierceStat,0);
        if(pierce) resistance-=pierce;
    }
    if(!c->defenderFlag && r->resistanceStat!=36 && r->resistanceStat!=37)
    {
        if(FIELD(c->game,112)) resistance+=FIELD(c->difficulty,0);
        else
        {
            switch(BYTEFIELD(c->game,109))
            {
            case 1: resistance-=20; break;
            case 2: resistance-=50; break;
            }
        }
    }
    if(resistance<=0)
    {
        if(resistance<=-100) resistance=-100;
    }
    else
    {
        if(!c->defenderFlag)
        {
            int maximum=75;
            if(r->maximumStat!=-1)
            {
                maximum=sub_00625480_Stat(c->defender,r->maximumStat,0)+75;
                if(maximum>=95) maximum=95;
            }
            else if(r->resistanceStat==36) maximum=50;
            resistance=(resistance>-100 ? resistance : -100)<maximum ? (resistance>-100 ? resistance : -100) : maximum;
        }
        if(r->resistanceStat==36 && sub_00639DF0_State(c->attacker,47) && sub_0063E990_ClassB(c->defender)) resistance=0;
    }
    return resistance;
}

static __declspec(noinline) int __cdecl sub_0057BF10_Absorb(Record* r,Context* c,int amount)
{
    if(r->absorbPercentStat!=-1)
    {
        int percent=sub_00625480_Stat(c->defender,r->absorbPercentStat,0);
        if(percent>=40) percent=40;
        if(percent>0)
        {
            int absorbed=sub_00483360_Ratio(amount,percent,100);
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
        int absorbed=sub_00625480_Stat(c->defender,r->absorbFlatStat,0)<<8;
        if(absorbed>0)
        {
            if(absorbed>=amount) absorbed=amount;
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
    }
    return amount;
}

// 0x0057BF80
static __declspec(noinline) int __stdcall sub_0057BF80_Apply(int ignore,Context* c,Record* r)
{
    int* field=&FIELD(c->damage,r->damageOffset);
    int amount=*field;
    int originalAmount=amount;
    if(amount<=0) { *field=0; return 0; }
    int resistance=sub_0057BE00_Resistance(c,r);
    if(ignore)
    {
        if(resistance>0) resistance=0;
    }
    else amount-=FIELD(c,28+4*r->reductionIndex);
    if(amount>0 && resistance)
    {
        if(resistance>=100) resistance=100;
        amount=sub_00483360_Ratio(amount,100-resistance,100);
    }
    sub_005347D0_Report(c->game,c->attacker,c->defender,originalAmount,resistance,FIELD(c,28+4*r->reductionIndex),amount,r->name,r->flags);
    originalAmount=amount;
    if(!ignore)
    {
        amount=sub_0057BF10_Absorb(r,c,amount);
        sub_005347E0_ReportAbsorb(c->game,c->attacker,c->defender,originalAmount-amount,r->name);
    }
    *field=amount;
    return amount;
}

// 0x0057C060
static __declspec(noinline) int __cdecl sub_0057C060_Scale(Context* c)
{
    if(c->attacker && c->defender && c->attacker!=c->defender)
    {
        if(c->defender->type==0)
        {
            if(c->attacker->type==0 || sub_0063EE90_ClassE(c->attacker)) return 17;
            Unit* attacker=c->attacker;
            if(sub_00451F30_HasFlags(attacker,0x80000000u) || sub_0063EE90_ClassE(attacker)) return 17;
        }
        else
        {
            if(sub_0063EE90_ClassE(c->defender) && sub_0063EE90_ClassE(c->attacker)) return 25;
            if(sub_0063EE90_ClassE(c->attacker) && sub_0063E9F0_ClassC(0,c->defender))
            {
                Difficulty* difficulty=c->difficulty;
                if(difficulty) return FIELD(difficulty,56);
                return 100;
            }
            if(sub_0063EDC0_ClassD(c->attacker))
            {
                Unit* defender=c->defender;
                if(sub_00451F30_HasFlags(defender,0x80000000u)) return sub_0063EE90_ClassE(defender) ? 200 : 400;
            }
        }
    }
    return 100;
}

// 0x0057C140
static __declspec(noinline) void __cdecl sub_0057C140_Durations(Context* c)
{
    if(FIELD(c->damage,48)>0 || FIELD(c->damage,52)>0)
    {
        if(sub_00625500_BaseStat(c->defender,153,0))
        {
            FIELD(c->damage,48)=0;
            FIELD(c->damage,52)=0;
        }
        else if(sub_00625500_BaseStat(c->defender,118,0))
        {
            FIELD(c->damage,48)/=2;
            FIELD(c->damage,52)/=2;
        }
    }
    if(FIELD(c->damage,44)>0 && sub_00639DF0_State(c->defender,133)) FIELD(c->damage,44)=0;
    if(FIELD(c->damage,24)>0 && sub_00639DF0_State(c->defender,131)) FIELD(c->damage,24)=0;
}

// 0x0057C1E0
void __fastcall sub_0057C1E0_Total(Game* game,Unit* attacker,Unit* defender,Damage* damage)
{
    Context c;
    c.game=game;
    c.difficulty=sub_00611D30_Difficulty(BYTEFIELD(game,109));
    c.attacker=attacker;
    c.defender=defender;
    c.damage=damage;
    c.attackerFlag=attacker && attacker->type==1 && !sub_0063EE90_ClassE(attacker);
    c.defenderFlag=defender && defender->type==1 && !sub_0063EE90_ClassE(defender);
    c.zeroReduction=0;
    int reduction=sub_00625480_Stat(defender,34,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction1=reduction;
    reduction=sub_00625480_Stat(defender,35,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction2=reduction;
    int scale=sub_0057C060_Scale(&c);
    if(scale!=100)
    {
        Record* r=gVar_00732980_Records;
        int remaining=12;
        do
        {
            if(r->scales)
            {
                int* field=&FIELD(damage,r->damageOffset);
                if(*field>0) *field=sub_00483360_Ratio(*field,scale,100);
            }
            ++r;
        } while(--remaining);
    }
    sub_005C0C30_Event(game,11,defender,attacker,damage);
    sub_0057C140_Durations(&c);
    int ignore=0;
    if(defender && defender->type==1)
    {
        int classB=sub_0063E990_ClassB(defender);
        int classA=sub_0063E940_ClassA(defender);
        if(classB && (FIELD(damage,0)&256)) ignore=1;
        if(classA && (FIELD(damage,0)&512)) ignore=1;
        if(!classB && !classA && (FIELD(damage,0)&1024)) ignore=1;
    }
    else if(FIELD(damage,0)&1024) ignore=1;
    Record* r=gVar_00732980_Records;
    for(int i=0;i<12;++i,++r)
    {
        if(r->requiresAttackerFlag && !c.attackerFlag) break;
        sub_0057BF80_Apply(ignore,&c,r);
    }
    FIELD(damage,76)=FIELD(damage,8)+(FIELD(damage,40)+FIELD(damage,36)+FIELD(damage,32)+FIELD(damage,28)+FIELD(damage,16));
    if(c.attackerFlag) FIELD(damage,76)+=FIELD(damage,56);
}

// 0x0057C980
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1897, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057C9F0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1951, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057CA80
static void __stdcall sub_0057CA80_AddCombatRecord(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pDefender && pDefender->dwUnitType == UNIT_OBJECT && (pDefender->dwClassId == 7 || pDefender->dwClassId == 11))
    {
        return;
    }

    if (pDefender->dwUnitType != UNIT_MONSTER && pDefender->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2CombatStrc* pCombat = (D2CombatStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2CombatStrc), ".\\UNIT\\SUnitDmg.cpp", 1995, 0);
    pCombat->pGame = pGame;
    pCombat->dwAttackerType = pAttacker->dwUnitType;
    pCombat->dwAttackerId = pAttacker->dwUnitId;
    pCombat->dwDefenderType = pDefender->dwUnitType;
    pCombat->dwDefenderId = pDefender->dwUnitId;
    memcpy(&pCombat->tDamage, pDamage, sizeof(pCombat->tDamage));
    pCombat->pNext = pAttacker->pCombat;
    pAttacker->pCombat = pCombat;
}

// calling-convention shim (not game code)
void __stdcall sub_U01_EmitMonTypeDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    sub_0057B6A0_AddMonTypeDamagePercent(pAttacker, pDamage, pDefender);
    sub_0057B6A0_AddMonTypeDamagePercent(pDefender, pDamage, pAttacker);
}

// 0x0057CB00
static int __stdcall sub_0057CB00(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nHitClass)
{
    if (STATES_CheckState(pUnit, 1))
    {
        return 1;
    }

    if (pDamage->dwPoisDamage && pDamage->dwPoisDamage == pDamage->dwDmgTotal)
    {
        return 1;
    }

    if (pDamage->dwDmgTotal < 0x100)
    {
        return 1;
    }

    int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nDivisor;
    switch (nHitClass)
    {
    case 2:
        nDivisor = 8;
        break;

    case 6:
        nDivisor = 8;
        break;

    case 10:
        nDivisor = 8;
        break;

    case 11:
        nDivisor = 8;
        break;

    case 4:
        nDivisor = 0x20;
        break;

    case 8:
        nDivisor = 0x20;
        break;

    case 5:
        nDivisor = 0x40;
        break;

    case 1:
        nDivisor = 0x10;
        break;

    case 3:
        nDivisor = 0x10;
        break;

    case 7:
        nDivisor = 0x10;
        break;

    case 9:
        nDivisor = 0x10;
        break;

    case 12:
        nDivisor = 0x10;
        break;

    default:
        nDivisor = 0x10;
        break;
    }

    if (pDamage->dwDmgTotal < nMaxLife / nDivisor)
    {
        return 1;
    }

    if (pDamage->dwDmgTotal < nMaxLife / (nDivisor / 2) && !sub_00472210_SeedRollMasked(&pUnit->pSeed, 2))
    {
        return 1;
    }

    if (pDamage->dwDmgTotal < nMaxLife / (nDivisor / 4) && !sub_00472210_SeedRollMasked(&pUnit->pSeed, 4))
    {
        return 1;
    }

    if (pUnit && pUnit->dwUnitType == 1 && !sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 3))
    {
        return 1;
    }

    return 0;
}

static __forceinline int UNIT_GetType(D2UnitStrc* pUnit)
{
 return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x0057CC30
static void __stdcall sub_0057CC30_OpenBarricadeObject(D2UnitStrc* pDefender, int nObjectId)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pDefender);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
    {
        pNext = pUnit->ptRoomNext;
        if (pUnit->dwUnitType == UNIT_OBJECT && pUnit->dwClassId == nObjectId)
        {
            D2CoordStrc tCoords;
            UNITS_GetCoords(pUnit, &tCoords);
            D2CoordStrc tDefenderCoords;
            UNITS_GetCoords(pDefender, &tDefenderCoords);

            if (tCoords.nX == tDefenderCoords.nX && tCoords.nY == tDefenderCoords.nY)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
                UNITS_FreeCollisionPath(pUnit);
                return;
            }
        }
    }
}

static __forceinline unsigned int sub_I18_UnitIsRevived(D2UnitStrc* pUnit)
{
    if (pUnit)
        return pUnit->dwFlags >> 31;
    return 0;
}

// 0x0057CCB0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bPetKill)
{
    unsigned int nUnitType = UNIT_INVALID;
    if (pDefender)
    {
        nUnitType = pDefender->dwUnitType;
    }

    switch (nUnitType)
    {
    case UNIT_PLAYER:
    {
        if (!pDefender || pDefender->dwAnimMode == PLRMODE_DEATH || pDefender->dwAnimMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    }
    case UNIT_MONSTER:
    {
        if (!pDefender || pDefender->dwAnimMode == MONMODE_DEATH || pDefender->dwAnimMode == MONMODE_DEAD)
        {
            return;
        }

        if (!sub_00457490_CheckMonStatsFlag(pDefender->dwClassId, MONSTATSFLAGINDEX_KILLABLE))
        {
            return;
        }

        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pDefender);
        if (bPetKill && pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC7D470(pGame, pOwner, pDefender);
        }
        break;
    }
    default:
        return;
    }

    if (pAttacker)
    {
        sub_6FC62780(pAttacker, pDefender, pGame);
        ARENA_ProcessKillEvent(pGame, pAttacker, pDefender);

        const unsigned int nMonsterId = pDefender->dwClassId;
        if (nMonsterId < sgptDataTables->nMonStatsTxtRecordCount && pAttacker->dwUnitType == UNIT_PLAYER)
        {
            sub_0066A220_Stub(pAttacker, nMonsterId);
        }
    }

    if (pDefender->dwUnitType == UNIT_MONSTER)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pDefender, MONMODE_DEATH, &modeChange);

        if (pAttacker)
        {
            modeChange.nDirection = UNITS_GetDirectionToCoords(pDefender, CLIENTS_GetUnitX(pAttacker), CLIENTS_GetUnitY(pAttacker));
        }
        else
        {
            modeChange.nDirection = PATH_GetDirection(pDefender->pDynamicPath);
        }

        modeChange.pTargetUnit = pAttacker;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

        if (!sub_I18_UnitIsRevived(pDefender))
        {
            QUESTS_ParseKill(pGame, pDefender, pAttacker);
        }

        const int nClassId = pDefender->dwClassId;
        if (sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_OBJCOL))
        {
            if (nClassId == MONSTER_BARRICADEDOOR1)
            {
                sub_0057CC30_OpenBarricadeObject(pDefender, 571);
                return;
            }

            if (nClassId == MONSTER_BARRICADEDOOR2)
            {
                sub_0057CC30_OpenBarricadeObject(pDefender, 572);
            }
        }
    }
}

// 0x0057CE30
static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass)
{
    unsigned int nHitClass = 0;
    int nIndex = s_nHitClassCounter_0088CAD0 % 0x04;
    ++s_nHitClassCounter_0088CAD0;

    const int nEnd = nIndex + 0x04;

    while (nIndex < nEnd)
    {
        if (*(int*)((char*)pDamage + gsDamageHitClassMapping_006E16D8[nIndex].nDamageStrcOffset) > 0)
        {
            nHitClass = gsDamageHitClassMapping_006E16D8[nIndex].nHitClass;
            break;
        }

        ++nIndex;
    }

    if (!nHitClass)
    {
        if (pDamage->wResultFlags & 0x2000)
        {
            nHitClass = 0x10;
        }
    }

    if (!nBaseHitClass)
    {
        nBaseHitClass = 0x0D;
    }

    return nBaseHitClass | nHitClass;
}

// 0x0057CEA0
static __forceinline void sub_0057CEA0_ApplyHitClass(D2DamageStrc* pDamage, D2UnitStrc* pAttacker)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF))
    {
        pDamage->dwHitClass |= UNITS_GetHitClass(pAttacker);
    }
}

// 0x0057CEC0
static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF0))
    {
        pDamage->dwHitClass = SUNITDMG_GetHitClass(pDamage, pDamage->dwHitClass);
    }
}

static __forceinline int SUNITDMG_IsInDeathMode(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType != UNIT_OBJECT)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            if (pUnit->dwAnimMode == 0)
            {
                return 1;
            }
            break;
        case UNIT_MONSTER:
            if (pUnit->dwAnimMode == 0)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}

static void __stdcall sub_0057D3D0_DamageItems(D2UnitStrc* pAttacker, D2GameStrc* pGame, D2UnitStrc* pDefender)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        if (pWeapon)
        {
            sub_00559E30_DecreaseDurability(pGame, pAttacker, pWeapon);
        }
    }

    if (!pDefender || pDefender->dwUnitType != UNIT_PLAYER || !pDefender->pInventory)
    {
        return;
    }

    D2InventoryStrc* pInventory = pDefender->pInventory;
    D2UnitStrc* pItems[7] = {};
    int nTotal = 0;
    for (int i = 0; i < gnBodyLocWeightCount_00732BC8; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gaBodyLocWeights_00732B90[i].nBodyLoc);
        if (pItem && ITEMSIsA(pItem, 0x32))
        {
            nTotal += gaBodyLocWeights_00732B90[i].nWeight;
            pItems[i] = pItem;
        }
    }

    if (nTotal <= 0)
    {
        return;
    }

    int nIndex = ITEMS_RollLimitedRandomNumber(&pDefender->pSeed, gnBodyLocWeightCount_00732BC8);
    int nRoll = ITEMS_RollLimitedRandomNumber(&pDefender->pSeed, nTotal);
    do
    {
        if (pItems[nIndex])
        {
            if (nRoll < gaBodyLocWeights_00732B90[nIndex].nWeight)
            {
                sub_00559E30_DecreaseDurability(pGame, pDefender, pItems[nIndex]);
                return;
            }
            nRoll -= gaBodyLocWeights_00732B90[nIndex].nWeight;
        }
        nIndex = (nIndex + 1) % gnBodyLocWeightCount_00732BC8;
    }
    while (nRoll >= 0);
}

// 0x0057D4F0
void __fastcall sub_0057D4F0_ExecuteMeleeDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    while (pCombat)
    {
        if (pCombat->dwAttackerType == sub_0044BE50_GetUnitTypeOrInvalid(pAttacker) && pCombat->dwAttackerId == sub_00451F50_GetUnitGUID(pAttacker)
            && pCombat->dwDefenderType == sub_0044BE50_GetUnitTypeOrInvalid(pDefender) && pCombat->dwDefenderId == sub_00451F50_GetUnitGUID(pDefender))
        {
            break;
        }
        pCombat = pCombat->pNext;
    }

    if (!pCombat)
    {
        return;
    }

    const int nUnitType = pAttacker->dwUnitType;
    D2DamageStrc tDamage = pCombat->tDamage;
    if (UNITS_IsInMeleeRange(pAttacker, pDefender, nUnitType == UNIT_MONSTER ? 3 : 1))
    {
        if (tDamage.wResultFlags & 1)
        {
            if (SUNITDMG_IsInDeathMode(pAttacker))
            {
                return;
            }

            tDamage.dwHitFlags = 0x20;
            SUNITDMG_ExecuteEvents(pGame, pAttacker, pDefender, 0, &tDamage);
            if (tDamage.nOverlay > 0)
            {
                UNITS_SetOverlay(pDefender, tDamage.nOverlay, 0);
            }

            if (!tDamage.nHitClassActiveSet && !(tDamage.dwHitClass & 0xF))
            {
                tDamage.dwHitClass |= UNITS_GetHitClass(pAttacker);
            }

            sub_0057D3D0_DamageItems(pAttacker, pGame, pDefender);
        }

        SUNITEVENT_Trigger(pGame, 7, pAttacker, pDefender, &tDamage);
        SUNITEVENT_Trigger(pGame, 3, pDefender, pAttacker, &tDamage);
        if (tDamage.wResultFlags & 1)
        {
            if (SUNITDMG_IsInDeathMode(pAttacker))
            {
                return;
            }

            SKILLS_ApplyThornsDamage(pGame, pAttacker, pDefender, &tDamage);
        }

        SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pDefender, &tDamage);
    }

    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pAttacker, pDefender);
}

// 0x0057D690
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return 0;
    }

    for (D2CombatStrc* pCombat = pAttacker->pCombat; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == sub_0044BE50_GetUnitTypeOrInvalid(pAttacker) && pCombat->dwAttackerId == sub_00451F50_GetUnitGUID(pAttacker)
            && pCombat->dwDefenderType == sub_0044BE50_GetUnitTypeOrInvalid(pDefender) && pCombat->dwDefenderId == sub_00451F50_GetUnitGUID(pDefender))
        {
            return &pCombat->tDamage;
        }
    }

    return 0;
}

// 0x0057D700
unsigned short __fastcall sub_0057D700_GetCombatResultFlags(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (!pCombat)
    {
        return 0;
    }

    for (; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId
            && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
        {
            return (unsigned char)pCombat->tDamage.wResultFlags;
        }
    }

    return 0;
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

// 0x0057D760
int __stdcall SUNITDMG_RollAndCompareValues(D2UnitStrc* pUnit, int* pFirstValue, int* pSecondValue)
{
    *pFirstValue = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, *pFirstValue);
    *pSecondValue = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, *pSecondValue);

    return *pFirstValue >= *pSecondValue;
}

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (UNITS_GetRoom(pUnit) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!pAttacker || pAttacker->dwUnitType != 1)
        {
            return;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[0x0A >> 3] & gdwBitMasks[0x0A & 7]))
        {
            return;
        }
    }

    if (pDamage->wResultFlags & 1)
    {
        sub_0057CEC0_SetHitClassIfUnset(pDamage);
        pUnit->dwLastHitClass = pDamage->dwHitClass;
    }

    if (STATES_CheckState(pUnit, 0x36))
    {
        if (pDamage->wResultFlags & 0x02)
        {
            STATES_ToggleState(pUnit, 0x5C, 1);
        }
        return;
    }

    int nType = 0x06;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
    {
        if (pDamage->wResultFlags & 0x80)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x41);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    StartModeID(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x100)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x42);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    StartModeID(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x200)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x44);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);

                if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wStSound > 0)
                    {
                        SUNIT_AttachSound(pUnit, 0x0C, pUnit);
                    }
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & (0x10 | 0x8000))
        {
            if (pDamage->wResultFlags & 0x4000)
            {
                return;
            }

            const int nLastBlockFrame = STATLIST_UnitGetStatValue(pUnit, 0x5F, 0);
            const int nBlockRate = STATLIST_UnitGetStatValue(pUnit, 0x66, 0);
            if ((int)(pGame->dwGameFrame - nLastBlockFrame) > nBlockRate / 0x08 + 0x0F)
            {
                sub_6FC817D0(pGame, pUnit, 0, 0x09, 0, 0, 0);
                STATLIST_SetUnitStat(pUnit, 0x5F, pGame->dwGameFrame, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x02)
        {
            if (pUnit && pUnit->dwAnimMode != 0 && pUnit->dwAnimMode != 0x11)
            {
                StartModeID(pGame, pUnit, 0, 0, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x08)
        {
            StartModeID(pGame, pUnit, 0, 0x13, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            return;
        }
        else
        {
            if (pDamage->wResultFlags & 0x04)
            {
                if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
                {
                    sub_6FC817D0(pGame, pUnit, 0, 0x04, pDamage->dwDmgTotal, 0, 0);
                    return;
                }
            }
            else
            {
                if (!(pDamage->wResultFlags & 0x4000))
                {
                    return;
                }
            }

            UNITROOM_RefreshUnit(pUnit);
            if (pUnit)
            {
                pUnit->dwFlags |= 0x8000;
            }
            return;
        }
    }
    case 1:
    {
        if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 0x0C)
        {
            return;
        }

        const unsigned short wResultFlags = pDamage->wResultFlags;
        if (wResultFlags & 0x08)
        {
            if (!sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 0x0D))
            {
                pDamage->wResultFlags = wResultFlags & (unsigned short)(~0x08) | 0x04;
            }
        }

        sub_6FC62DF0(pGame, pAttacker, pUnit, pDamage);

        if (pDamage->wResultFlags & 0x02)
        {
            SUNITDMG_KillMonster(pGame, pUnit, pAttacker, 1);
            return;
        }

        D2ModeChangeStrc modeChange;
        if (pDamage->wResultFlags & 0x08)
        {
            MONSTERMODE_GetModeChangeInfo(pUnit, 0x0D, &modeChange);
            modeChange.pTargetUnit = pAttacker;
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x10)
        {
            if (pDamage->wResultFlags & 0x4000 || pUnit->dwClassId == 0xF3 || pUnit->dwClassId == 0x14D || pUnit->dwClassId == 0x2C1
                || !sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 0x06))
            {
                MONSTER_SetAiState(pUnit, 0x13);
                return;
            }

            MONSTERMODE_GetModeChangeInfo(pUnit, 0x06, &modeChange);
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x04)
        {
            if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
            {
                MONSTERMODE_GetModeChangeInfo(pUnit, 0x03, &modeChange);
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                sub_6FC6E8A0(pGame, pUnit);
                return;
            }

            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 0x4000)
        {
            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 1 && pDamage->dwDmgTotal > 0)
        {
            const unsigned char nLastHpPct = (unsigned char)STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
            int nHpDiff = nLastHpPct - MONSTERMODE_GetHpPercent128(pUnit);
            if (nHpDiff < 0)
            {
                nHpDiff = -nHpDiff;
            }

            if (nHpDiff > 0x04)
            {
                UNITROOM_RefreshUnit(pUnit);
                pUnit->dwFlags |= 0x8000;
            }
        }
        return;
    }
    }
}

// 0x0057D810
static void SUNITDMG_PreventMonsterHeal(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (pAttacker && pAttacker->dwUnitType == 0 && (pDefender ? pDefender->dwUnitType : 6) == 1 && STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 117, 0))
    {
        if (pDefender->dwClassId >= 704 && pDefender->dwClassId <= 709)
        {
            return;
        }

        D2CurseStrc curse = {};
        curse.pUnit = pAttacker;
        curse.pTarget = pDefender;
        curse.nSkill = 0;
        curse.nSkillLevel = 1;
        curse.nDuration = 120000;
        curse.nStat = 31;
        curse.nStatValue = 0;
        curse.nState = 52;
        sub_0056E970(&curse);
    }
}

// 0x0057D8A0
static void __stdcall sub_0057D8A0_ApplyTargetDefenseModifiers(int* pAttackRate, int* pDefense, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 115, 0) && pDefender && pDefender->dwUnitType == 1
        && !MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 10) && !MONSTERS_IsBoss(0, pDefender) && !MONSTERS_GetHirelingTypeId(pDefender))
    {
        *pDefense = 0;
    }

    int nFractionalTargetAc = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 116, 0);
    if (nFractionalTargetAc > 0)
    {
        if (pDefender && (pDefender->dwUnitType == 0 || pDefender->dwUnitType == 1
            && (MONSTERS_IsBoss(0, pDefender) || MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2) || MONSTERS_GetHirelingTypeId(pDefender))))
        {
            nFractionalTargetAc /= 2;
        }

        nFractionalTargetAc = D2MIN(D2MAX(nFractionalTargetAc, 0), 100);

        const int nDefense = *pDefense;
        *pDefense = nDefense - DATATBLS_ApplyRatio(nDefense, nFractionalTargetAc, 100);
    }

    const int nDemonToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 123, 0);
    if (nDemonToHit && MONSTERS_IsDemon(pDefender))
    {
        *pAttackRate += nDemonToHit;
    }

    const int nUndeadToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 124, 0);
    if (nUndeadToHit && MONSTERS_IsUndead(pDefender))
    {
        *pAttackRate += nUndeadToHit;
    }
}

static inline int I13_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static inline D2MonStatsTxt* I13_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x0057D9B0
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, 12, 0);
    int nTotalDefense = UNITS_GetDefense(pDefender);
    if (bMissile)
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 32, 0);
    }
    else
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 33, 0);
    }
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);

    int nAttackRate = 0;
    int nToHitPercent = 0;
    const int nAttackerType = I13_GetUnitType(pAttacker);
    if (nAttackerType == 0)
    {
        nAttackRate = UNITS_GetAttackRate(pAttacker);
        sub_0057D8A0_ApplyTargetDefenseModifiers(&nAttackRate, &nTotalDefense, pDefender, pAttacker);

        if (!bMissile)
        {
            D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
            if (pWeapon)
            {
                nToHitPercent = SKILLS_GetWeaponMasteryBonus(pAttacker, pWeapon, 0, 0);
            }
        }

        nToHitPercent += nStatValue + STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);

        {
            D2MonStatsTxt* pMonStatsTxtRecord = I13_GetMonStatsTxtRecord(pDefender);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType > 0)
            {
                const int nMonType = pMonStatsTxtRecord->wMonType;
                D2StatStrc stats[128];
                const int nStats = STATLIST_CopyStats(pAttacker, 179, stats, 128);
                for (int i = 0; i < nStats; ++i)
                {
                    if (SUNITDMG_CheckMonType(stats[i].nLayer, nMonType))
                    {
                        nToHitPercent += stats[i].nValue;
                    }
                }
            }
        }
    }

    else
    {
        nAttackRate = STATLIST_UnitGetStatValue(pAttacker, 19, 0);
        nAttackRate += nStatValue + 5 * STATLIST_UnitGetStatValue(pAttacker, 2, 0);
        nToHitPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);
    }

    nAttackRate += DATATBLS_ApplyRatio(nAttackRate, nToHitPercent, 100);
    if (nTotalDefense < 0)
    {
        nAttackRate -= nTotalDefense;
        nTotalDefense = 0;
    }

    if (nAttackRate < 0)
    {
        nTotalDefense -= nAttackRate;
        nAttackRate = 0;
    }

    if (nTotalDefense < 0)
    {
        nTotalDefense = 0;
    }

    const int nDivisor = nAttackRate + nTotalDefense;
    int nToHitFactor = 100;
    if (nDivisor)
    {
        nToHitFactor = 100 * nAttackRate / nDivisor;
    }

    int nChanceToHit = 2 * nAttackerLevel * nToHitFactor / (nDefenderLevel + nAttackerLevel);
    nChanceToHit = D2MIN(D2MAX(nChanceToHit, 5), 95);

    D2SeedStrc* pSeed = &pAttacker->pSeed;
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    const int nRand = (unsigned int)lSeed % 100;

    sub_005347B0_Stub5(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nChanceToHit, nRand);
    if (nRand < nChanceToHit)
    {
        SUNITDMG_PreventMonsterHeal(pAttacker, pDefender);
        return 1;
    }

    return 0;
}

// 0x0057DBF0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    const unsigned int nAttackerType = pAttacker->dwUnitType;
    if (!(pDamage->wResultFlags & 0x8380) && pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_2))
        {
            SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, 0, nSrcDam);
        }

        SUNITDMG_CalculateTotalDamage(pGame, pAttacker, pDefender, pDamage);

        int nTotalDamage = pDamage->dwPhysDamage + pDamage->dwFireDamage + pDamage->dwLtngDamage + pDamage->dwMagDamage + pDamage->dwColdDamage + pDamage->dwPoisDamage;
        if (nAttackerType == UNIT_MONSTER)
        {
            nTotalDamage += pDamage->dwLifeLeech;
        }

        const int nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
        if ((nTotalDamage & ~0xFF) > (nHitpoints & ~0xFF))
        {
            pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
        }
    }

    sub_0057CA80_AddCombatRecord(pGame, pAttacker, pDefender, pDamage);
}

// 0x0057E240
void __fastcall SUNITDMG_RollDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage)
{
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, pDamage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
}

// 0x0057E2F0
static int sub_0057E2F0_ApplyLevelDifferenceFactor(int nAttackerLevel, int nExperience, int nDefenderLevel)
{
    if (nDefenderLevel <= nAttackerLevel)
    {
        int nIndex = nAttackerLevel - nDefenderLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorLowerLevel_006E1668[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }
    else
    {
        if (nAttackerLevel >= 25 && nDefenderLevel > 0)
        {
            return DATATBLS_ApplyRatio(nExperience, nAttackerLevel, nDefenderLevel);
        }

        int nIndex = nDefenderLevel - nAttackerLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorHigherLevel_006E1694[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }

    return nExperience;
}

// 0x0057E350
int __fastcall sub_0057E350_ApplyExpRatio(int nValue, int nRatio, int nShift)
{
    if (nShift > 0 && nShift < 32)
    {
        if (nValue > (0x7FFFFFFF >> (nShift + (nRatio >> nShift))))
        {
            return (nValue >> nShift) * nRatio;
        }

        return nValue * nRatio >> nShift;
    }

    return nValue;
}

// 0x0057E390
static int __stdcall sub_0057E390_ApplyExpRatio(int nLevel, int nResult)
{
    if (nResult <= 0)
    {
        return nResult;
    }

    const int nRatio1 = DATATBLS_GetExpRatio(nLevel);
    const int nRatio2 = DATATBLS_GetExpRatio(0);
    if (nRatio2 > 0 && nRatio2 < 32)
    {
        if (nResult > (0x7FFFFFFF >> (nRatio2 + (nRatio1 >> nRatio2))))
        {
            nResult = nRatio1 * (nResult >> nRatio2);
        }
        else
        {
            nResult = nResult * nRatio1 >> nRatio2;
        }
    }

    return nResult;
}

// 0x0057E3F0
static unsigned int __stdcall sub_0057E3F0_CapHirelingExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, int nAttackerLevel, unsigned int nResult)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        return nResult;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pAttacker ? -1 : pAttacker->dwUnitId);
    if (!pPetInfo)
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nAttackerLevel);
    if (!pHirelingTxtRecord)
    {
        return 0;
    }

    const int nCurrentLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel, pHirelingTxtRecord->dwExpPerLvl);
    const int nNextLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    const unsigned int nMaxExp = (unsigned int)(nNextLevelExp - nCurrentLevelExp) >> 6;
    if (nResult > nMaxExp)
    {
        nResult = nMaxExp;
    }

    return nResult;
}

// 0x0057E480
static int __stdcall SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, int nAttackerLevel, D2UnitStrc* pAttacker, int nDefenderLevel, int nDefenderExperience)
{
    if (nDefenderExperience > 0x7FFFFF)
    {
        nDefenderExperience = 0x7FFFFF;
    }

    if (nDefenderExperience <= 0)
    {
        return 1;
    }

    const int nClassId = (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) ? pAttacker->dwClassId : 0;
    if (nAttackerLevel >= DATATBLS_GetMaxLevel(nClassId))
    {
        return 0;
    }

    int nResult = sub_0057E2F0_ApplyLevelDifferenceFactor(nAttackerLevel, nDefenderExperience, nDefenderLevel);
    nResult = sub_0057E390_ApplyExpRatio(nAttackerLevel, nResult);

    const int nAddExpPct = STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_ADDEXPERIENCE, 0);
    if (nAddExpPct)
    {
        nResult += DATATBLS_ApplyRatio(nResult, nAddExpPct, 100);
    }

    return sub_0057E3F0_CapHirelingExperience(pGame, pAttacker, nAttackerLevel, nResult);
}

// 0x0057E510
static void __stdcall SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOldLevel, unsigned int nExperienceGained)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    const int nClassId = pUnit->dwClassId;
    unsigned int nNewExperience = nExperienceGained + nExperience;
    const unsigned int nMaxExperience = DATATBLS_GetLevelThreshold(nClassId, DATATBLS_GetMaxLevel(nClassId) - 1);
    if (nNewExperience > nMaxExperience)
    {
        nNewExperience = nMaxExperience;
    }

    STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nNewExperience - nExperience, 0);
    STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNewExperience, 0);

    if (nOldLevel != DATATBLS_GetCurrentLevelFromExp(nClassId, nNewExperience))
    {
        PLAYERSTATS_LevelUp(pGame, pUnit);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pUnit, 0, 0);
    }
}

static __forceinline int GetReferenceX(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return unit->pStaticPath->nXPos;
    }
    return unit->pDynamicPath ? PATH_GetX(unit->pDynamicPath) : 0;
}

static __forceinline int GetReferenceY(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return unit->pStaticPath->nYPos;
    }
    return unit->pDynamicPath ? PATH_GetY(unit->pDynamicPath) : 0;
}

// 0x0057E5A0
void __fastcall SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* game, D2UnitStrc* unit, T0057E5A0* data)
{
    if (SUNIT_IsDead(unit))
        return;
    D2UnitStrc* reference = data->pReference;
    if (reference)
    {
        int x = GetReferenceX(reference);
        int y = GetReferenceY(reference);
        if (!x)
            return;
        int unitX = CLIENTS_GetUnitX(unit);
        int unitY = CLIENTS_GetUnitY(unit);
        if (!unitX)
            return;
        int dx = x - unitX;
        int dy = y - unitY;
        unsigned int distance = dx * dx + dy * dy;
        if (distance > 6400)
            return;
    }
    if (data->count >= 8)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 3877);
        exit(-1);
    }
    data->players[data->count] = unit;
    data->levels[data->count] = STATLIST_UnitGetStatValue(unit, 12, 0);
    data->totalLevel += data->levels[data->count];
    ++data->count;
}

// 0x0057E6C0
static void __stdcall sub_0057E6C0_DistributePartyExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDefender, int nPlayerLevel, int nDefenderLevel, int nDefenderExperience)
{
    D2PartyExpStrc partyExp;
    memset(&partyExp, 0, sizeof(partyExp));
    partyExp.pDefenderUnit = pDefender;
    PARTY_IteratePartyMembersInSameLevel(pGame, pPlayer, SUNITDMG_PartyCallback_ComputePartyExperience, &partyExp);

    if (partyExp.nMembers <= 0 || partyExp.nLevelSum <= 0)
    {
        return;
    }

    if (partyExp.nMembers == 1)
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, SUNITDMG_ComputeExperienceGain(pGame, nPlayerLevel, pPlayer, nDefenderLevel, nDefenderExperience));
        return;
    }

    const int nExperience = nDefenderExperience + 89 * nDefenderExperience * (partyExp.nMembers - 1) / 256;
    const float multiplier = (float)nExperience / (float)partyExp.nLevelSum;
    for (int i = 0; i < partyExp.nMembers; ++i)
    {
        const int nMemberLevel = partyExp.nMemberLevels[i];
        D2UnitStrc* pMember = partyExp.pMembers[i];
        const int nExperienceGained = SUNITDMG_ComputeExperienceGain(pGame, nMemberLevel, pMember, nDefenderLevel, (int)((float)nMemberLevel * multiplier));
        SUNITDMG_AddExperienceForPlayer(pGame, pMember, nMemberLevel, nExperienceGained);
    }
}

// 0x0057E7B0
static D2UnitStrc* __stdcall sub_0057E7B0_GetExperienceOwner(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    int nType = UNIT_INVALID;
    if (pAttacker)
    {
        nType = pAttacker->dwUnitType;
    }

    switch (nType)
    {
    case UNIT_MONSTER:
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        D2StatListStrc* pStatList = 0;
        if (STATES_CheckStateMaskExpOnUnit(pAttacker))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pAttacker, STATLIST_FLAG_EXP);
        }

        if (pDefender && STATES_CheckStateMaskExpOnUnit(pDefender))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pDefender, STATLIST_FLAG_EXP);
        }

        if (pStatList)
        {
            const int nOwnerType = STATLIST_GetOwnerType(pStatList);
            const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
            pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
        }

        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return pOwner;
        }

        return 0;
    }
    case UNIT_PLAYER:
        return pAttacker;
    }

    return 0;
}

// 0x0057E860
static void __stdcall SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, int nLevel, int nExperienceBonus)
{
    if (nExperienceBonus <= 0)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, !pHireling ? -1 : pHireling->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord || nLevel >= STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0))
    {
        return;
    }

    const unsigned int nCurrentExp = STATLIST_GetUnitBaseStat(pHireling, STAT_EXPERIENCE, 0);
    const unsigned int nNewExp = nCurrentExp + 2 * nExperienceBonus;
    const int nMaxLevel = DATATBLS_GetMaxLevel(0) - 1;
    if (nLevel >= nMaxLevel)
    {
        return;
    }

    STATLIST_SetUnitStat(pHireling, STAT_EXPERIENCE, nNewExp, 0);
    D2GAME_PACKETS_SendPacket0xA0_A1_A2_6FC3D610(UnitGetClient(pPlayer, ".\\UNIT\\SUnitDmg.cpp", 4029), pHireling, STAT_EXPERIENCE, nCurrentExp, nNewExp);

    int nNewLevel = nLevel;
    do
    {
        if ((unsigned int)MONSTERS_GetHirelingExpForNextLevel(nNewLevel + 1, pHirelingTxtRecord->dwExpPerLvl) > nNewExp)
        {
            break;
        }

        nNewLevel += 1;
    }
    while (nNewLevel < nMaxLevel);

    if (nNewLevel > nLevel)
    {
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pHireling, nNewLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 0);
        SUNIT_AttachSound(pHireling, 0x5B, pPlayer);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pHireling, 0, 0);
    }
}

// build: context SUNITDMG_DistributeExperience
void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    int nPlayerLevel;
    if (!pAttacker || !pDefender || pAttacker->dwUnitType != UNIT_PLAYER && pAttacker->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    const int nDefenderExperience = STATLIST_GetUnitBaseStat(pDefender, STAT_EXPERIENCE, 0);
    if (nDefenderExperience <= 0)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_0057E7B0_GetExperienceOwner(pGame, pAttacker, pDefender);
    if (!pPlayer)
    {
        return;
    }

    const int nDefenderLevel = STATLIST_GetUnitBaseStat(pDefender, STAT_LEVEL, 0);
    D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (pPet)
    {
        const int nPetLevel = STATLIST_GetUnitBaseStat(pPet, STAT_LEVEL, 0);
        int nExperienceBonus = SUNITDMG_ComputeExperienceGain(pGame, nPetLevel, pPet, nDefenderLevel, nDefenderExperience);
        if (pAttacker != pPet)
        {
            nExperienceBonus = 86 * nExperienceBonus / 256;
        }

        SUNITDMG_AddExperienceForHireling(pGame, pPlayer, pPet, nPetLevel, nExperienceBonus);
    }

    nPlayerLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
    if (SUNIT_GetPartyId(pPlayer) != -1)
    {
        sub_0057E6C0_DistributePartyExperience(pGame, pPlayer, pDefender, nPlayerLevel, nDefenderLevel, nDefenderExperience);
    }
    else
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, SUNITDMG_ComputeExperienceGain(pGame, nPlayerLevel, pPlayer, nDefenderLevel, nDefenderExperience));
    }
}

// 0x0057EAB0
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, int nExperienceBonus)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nExperienceBonus);
    }
    else
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, nExperienceBonus);
        }
    }
}

// 0x0057F390
void __fastcall sub_0057F390_DropCorpseGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody, int nGold, int nUnused)
{
    if (nGold > 0)
    {
        D2UnitStrc* pGoldPiles[GOLD_PILE_COUNT];
        int nCount = 0;
        sub_0055A090_DropGoldPiles(pGame, pDeadBody, nGold, pGoldPiles, &nCount, GOLD_PILE_COUNT);

        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pGold = pGoldPiles[i];
            D2_ASSERT(ITEMS_GetItemType(pGold) == ITEMTYPE_GOLD, 588);
            ITEMS_SetOwnerId(pGold, sub_00451F50_GetUnitGUID(pPlayer));
        }
    }
}

// 0x0057FDC0
void __fastcall PLRMODE_StartXY_Block(D2GameStrc* pGame, D2UnitStrc* hPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(hPlayer, 1095);

    SUNIT_SetCombatMode(pGame, hPlayer, nMode);
    sub_6FCBC4D0(hPlayer);
    UNITS_SetUsedSkill(hPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, hPlayer);
    sub_6FCBCE70(pGame, hPlayer);
}

// 0x0057FE30
void __fastcall PLRMODE_StartXY_GetHit(D2GameStrc* pGame, D2UnitStrc* hPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(hPlayer, 1136);

    SUNIT_SetCombatMode(pGame, hPlayer, nMode);
    sub_6FCBC4D0(hPlayer);
    UNITS_SetUsedSkill(hPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, hPlayer);
    sub_6FCBCE70(pGame, hPlayer);
}

// 0x0057FE90
void __fastcall PLRMODE_StartXY_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
    pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    SKILLS_StartUsedSkill(pGame, pPlayer);
}

// 0x0057FEF0
void __fastcall PLRMODE_StartID_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* hTarget)
{
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);

    D2_ASSERT(hTarget, 1215);

    UNITS_SetTargetUnitForDynamicUnit(pPlayer, hTarget);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);

    if (pPlayer)
    {
        pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    }

    SKILLS_StartUsedSkill(pGame, pPlayer);
}

// 0x00582380
void __fastcall D2GAME_OBJECTS_TrapHandler5_7_6FC75BC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pFireLarge = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_LARGE, pCoord.nX, pCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pFireLarge)
    {
        D2GAME_SetSparkChest_6FCBD7C0(pFireLarge, 2);
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    const int nX = pCoord.nX + 1;
    if (nX >= drlgCoords.nSubtileX && nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        D2UnitStrc* pFireSmall = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_SMALL, nX, pCoord.nY, pGame, UNITS_GetRoom(pUnit), 1, 1, 0);
        D2GAME_SetSparkChest_6FCBD7C0(pFireSmall, 2);
    }
}

// 0x00582800
void __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback)
{
    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 0;
    curse.pTarget = pTarget;
    curse.nDuration = nDuration;
    curse.nStat = nStat;
    curse.nStatValue = nStatValue;
    curse.nState = nState;
    curse.pStateRemoveCallback = pStateRemoveCallback;
    sub_0056E970(&curse);
}

// 0x00582A30
void __fastcall D2GAME_SHRINES_Portal_6FC76880(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);

    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->hPlayer, &pCoord);

    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    const int nTownId = DUNGEON_GetTownLevelIdFromActNo(nAct);

    if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pOp->hPlayer), &pCoord, 3, 0x1C09, 0))
    {
        D2GAME_CreatePortalObject_6FD13DF0(pOp->pGame, pOp->hPlayer, pRoom, pCoord.nX + 5, pCoord.nY + 5, nTownId, 0, OBJECT_TOWN_PORTAL, 0);
    }
}

// 0x00583A40
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
}

// 0x00583BD0
void __fastcall sub_6FC77C10(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    sub_6FD14C30(pUnit);
}

// 0x00583E70
int __fastcall OBJECTS_OperateFunction33_WirtsBody(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        pOp->hObject->dwDropItemCode = ' gel';

        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 10, 0, 0);
        }
    }

    return 1;
}

// 0x00584160
int __fastcall OBJECTS_OperateFunction19_ArmorStand(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);
        D2GAME_DropArmor_6FC4F830(pOp->pGame, UNITS_GetRoom(pOp->hObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005841D0
int __fastcall OBJECTS_OperateFunction20_WeaponRack(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);
        D2GAME_DropWeapon_6FC4FA50(pOp->pGame, UNITS_GetRoom(pOp->hObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x00584540
int __fastcall sub_6FC78B20(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    if (!pObject)
    {
        return 0;
    }

    const int nClassId = pObject->dwClassId;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && !DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
        {
            return 1;
        }

        if (!sub_00623660_IsInObjectInteractRange(pUnit, pObject))
        {
            return 1;
        }
    }

    int nResult = 1;
    OBJECTS_OperateHandler(pGame, pUnit, nObjectType, nObjectGUID, &nResult);
    return nResult;
}

// build: context SUNITDMG_SetExperienceForTargetLevel
void __fastcall SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    int nClassId;
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (nTargetLevel <= nLevel)
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nClassId = pUnit->dwClassId;
        const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        const unsigned int nThreshold = DATATBLS_GetLevelThreshold(nClassId, nTargetLevel);
        if (nThreshold > nExperience)
        {
            SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nThreshold - nExperience);
        }
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER || nLevel >= DATATBLS_GetMaxLevel(0))
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, pUnit->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, MONSTERS_GetHirelingExpForNextLevel(nTargetLevel, pHirelingTxtRecord->dwExpPerLvl) - nExperience);
}

struct D2StatListStrc;

void __fastcall sub_M109_Emit_0057CEA0(D2UnitStrc* pAttacker, D2DamageStrc* pDamage)
{
    sub_0057CEA0_ApplyHitClass(pDamage, pAttacker);
    UNITS_GetHitClass((D2UnitStrc*)pDamage);
}

#include "gen/data/Source/D2Game/UNIT/SUnitDmg.inc"
