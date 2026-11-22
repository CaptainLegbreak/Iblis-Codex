#include "D2MissileIds.h"
#include "D2GameClient.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2MonModes.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"

#define UNITFLAG_TARGETABLE 0x00000002

#define UNITFLAG_ISVALIDTARGET 0x00000008

#define STAT_ITEM_ARMOR_PERCENT 16

#define STAT_SECONDARY_MINDAMAGE 23

#define STAT_SECONDARY_MAXDAMAGE 24

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_GOOD 2

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_MONUMOD 7

#define MONTYPEFLAG_RESURRECTED 8

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAG_NOXP 0x04000000

#define PARTYSCREENTYPE_HOSTILE 3

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2ModeChangeStrc;

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2MissileStrc;

struct D2GameStrc;

struct D2CoordStrc;

struct D2DataTablesStrc;

struct D2ClientStrc;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480

void __fastcall sub_005A0E80_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A0E80

void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A29A0

void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A3040

void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

extern const int gnBugLightningXOffsets_006E21A8[]; // 0x006E21A8

extern const int gnBugLightningYOffsets_006E2198[]; // 0x006E2198

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0

void __fastcall ITEMMODE_CompactBeltColumn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0

void __fastcall ITEMMODE_RemoveBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00561E70

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00

int __fastcall AIGENERAL_GetAiControlParam(D2UnitStrc* pUnit, int nIndex); // 0x0058EC50

int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

typedef void(__fastcall* PartyCommandFunc)(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure);

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern PartyCommandFunc gpfPartyCommands_6FD28E60[10]; // 0x006E2218

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057E990

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x005A60E0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

enum D2C_M187TrapConstants
{
    STAT_LEVEL = 12,
    STAT_TOHIT = 19,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

struct D2MissilesTxt;

void __fastcall QUESTSFX_Bloodraven(D2GameStrc*, D2UnitStrc*); // 0x005DFD90

void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFDB0

void __fastcall QUESTSFX_Andariel(D2GameStrc*, D2UnitStrc*); // 0x005DFE00

void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFE20

void __fastcall QUESTSFX_Izual(D2GameStrc*, D2UnitStrc*); // 0x005E0020

void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc*, D2UnitStrc*); // 0x005E0040

void __fastcall QUESTSFX_OnQuestCompleteModeChange(D2GameStrc*, D2UnitStrc*); // 0x005E0060

void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc*, D2UnitStrc*); // 0x005E0070

extern const unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall sub_005A0180_CheckMonsterFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillsTxt;

typedef void(__fastcall* CurseCallbackFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel);

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __fastcall SKILLS_ApplyCurseAroundTarget(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse); // 0x0056DBC0

void __fastcall MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005A23D0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

struct D2ActiveRoomStrc;

typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

typedef void (__fastcall* MinionCallbackFunc)(D2UnitStrc* pUnit, void* pArg1, void* pArg2);

extern UModInitFunc gpUModInitFunctions_0073C008[];                                                         // 0x0073C008

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                              // 0x0046C140

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                  // 0x00451F50

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0

void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00544E80

void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00545B50

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet);                         // 0x00573570

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* pArg1, void* pArg2, MinionCallbackFunc pfnCallback); // 0x0058F380

void __fastcall sub_005A0200(D2UnitStrc* pUnit, short nBossHcIdx);                             // 0x005A0200

void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique);              // 0x005A1650

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags); // 0x005B2F70

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags); // 0x005B3040

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                       // 0x0063EC70

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                          // 0x006556E0

int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods); // 0x005A0260

extern "C" __int64 __stdcall _alldiv(__int64 a, __int64 b); // 0x00684240

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

static void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercent);

D2UnitStrc* __fastcall D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSuperUnique); // 0x005A49B0

struct D2AuraEnchantStrc;

struct D2MonLvlTxt;

struct D2MonUModTxt;

struct D2AuraEnchantStrc
{
    int nLevel;
    int nLevelAdd;
    int nMul;
    int nDiv;
    int nSkillId;
};

extern D2AuraEnchantStrc gAuraEnchantTable_0073BF68[8]; // 0x0073BF68

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

enum D2C_H16ElemConstants
{
    MONLVL_DM = 6,
};

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x0059F8A0
void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_AllocMissileData(pMissile);
    pMissile->dwUnitId = nUnitGUID;
    pMissile->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_ISVALIDTARGET);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pMissile);
    sub_6FC35570(pGame, pMissile, 0, 0, 0);
}

// build: context MonsterDataOf
static inline D2MonsterDataStrc* MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// build: context UModsOf
static inline unsigned char* UModsOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nMonUmod;
    }
    return 0;
}

// build: context HasMonTypeFlag
static inline int HasMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nTypeFlag & nFlag;
    }
    return 0;
}

// build: context SetMonTypeFlag
static inline void SetMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    if (bSet)
    {
        pMonsterData->nTypeFlag |= nFlag;
    }
    else
    {
        pMonsterData->nTypeFlag &= ~nFlag;
    }
}

// build: context CountUMods
static inline int CountUMods(unsigned char* pUMods)
{
    int nIndex = 0;
    while (nIndex < 9 && pUMods[nIndex])
    {
        ++nIndex;
    }
    return nIndex;
}

// build: context CountUModsTo
static inline int CountUModsTo(unsigned char* pUMods)
{
    for (int i = 0; i < 9; ++i)
    {
        if (!pUMods[i])
        {
            return i;
        }
    }
    return 9;
}

// build: context TestMonTypeFlag
static inline int TestMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & nFlag))
    {
        return 1;
    }
    return 0;
}

// build: context UModsOfData
static inline unsigned char* UModsOfData(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pMonsterData = pUnit->pMonsterData;
    }

    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// build: context InitUMod
static inline void InitUMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pfnInit = gpUModInitFunctions_0073C008[nUMod];
    if (pfnInit)
    {
        pfnInit(pUnit, nUMod, bUnique);
    }
}

// build: context MonStatsTxtRecord
static inline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// build: context CheckMonStatsFlag
static inline unsigned int CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
    }
    return 0;
}

// build: context MonStatsTxtRecordOrNull
static inline D2MonStatsTxt* MonStatsTxtRecordOrNull(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

// build: context TestMonStatsFlag
static inline unsigned int TestMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecordOrNull(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// build: context MonUModTxtRecord
static inline D2MonUModTxt* MonUModTxtRecord(int nUMod)
{
    if (!(nUMod < sgptDataTables->nMonUModTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonUModTxt[nUMod];
}

// build: context SuperUniqueHcIdx
static inline int SuperUniqueHcIdx(int nSuperUnique)
{
    if (nSuperUnique >= 0 && nSuperUnique < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUnique].dwHcIdx;
    }
    return -1;
}

// build: context RollRandomInline
static inline unsigned int RollRandomInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// build: context RollLimitedInline
static inline int RollLimitedInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
    {
        return RollRandomInline(pSeed) % nMax;
    }

    return RollRandomInline(pSeed) & (nMax - 1);
}

// 0x005A02E0
static void __stdcall sub_005A02E0_AddUMod(int nUMod, D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    if (D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData)
    {
        int nIndex = 0;
        while (nIndex < 9 && pMonsterData->nMonUmod[nIndex])
        {
            ++nIndex;
        }

        if (nIndex < 9)
        {
            pMonsterData->nMonUmod[nIndex] = (unsigned char)nUMod;
        }
    }
}

// 0x005A0320
static void __stdcall sub_005A0320_MarkUnique(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, MONSTER_GetLevelId(pUnit));
        if (pMonsterRegion && !TestMonTypeFlag(pUnit, 8))
        {
            ++pMonsterRegion->dwUniqueCount;
        }

        SetMonTypeFlag(pUnit, 8, 1);
    }
}

// 0x005A03E0
static int __stdcall MONSTERUNIQUE_CanAssignUMod(D2UnitStrc* pUnit, D2MonUModTxt* pMonUModTxtRecord, int bExpansion)
{
    if (!pMonUModTxtRecord->nEnabled)
    {
        return 0;
    }

    if (!bExpansion && pMonUModTxtRecord->wVersion >= 100)
    {
        return 0;
    }

    for (int i = 0; i < 2; ++i)
    {
        const short nExcludeMonType = pMonUModTxtRecord->wExclude[i];
        if (nExcludeMonType <= 0)
        {
            break;
        }

        if (sub_005A0070(pUnit, nExcludeMonType))
        {
            return 0;
        }
    }

    switch (pMonUModTxtRecord->nFPick)
    {
    case 1:
        if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 4))
        {
            return 0;
        }
        break;

    case 2:
        if (pUnit)
        {
            if (TestMonStatsFlag(pUnit->dwClassId, 1))
            {
                return 0;
            }

            if (TestMonStatsFlag(pUnit->dwClassId, 17))
            {
                return 0;
            }
        }
        break;

    case 3:
        if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
        {
            return 0;
        }
        break;
    }

    return 1;
}

// 0x005A0500
static int sub_005A0500_RollChampionUMod(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    int aPicks[512];
    int nPickCount = 0;

    if (!pGame)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return 0;
    }

    const int bExpansion = pGame->bExpansion;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    if (!pMonUModTxtRecord)
    {
        return 0;
    }

    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wCPick[nDifficulty];
        if (nPick > 0 && pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion))
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = SEED_RollLimitedRandomNumber(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

// 0x005A0600
static int __stdcall MONSTERUNIQUE_RollNonChampionUMod(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pUsedUMods)
{
    int aPicks[512];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;

    const int bExpansion = pGame->bExpansion;
    int nPickCount = 0;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wUPick[nDifficulty];
        if (nPick > 0 && !pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion) && !pUsedUMods[i])
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = RollLimitedInline(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

// 0x005A0120
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x005A0260
int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods)
{
    int nCount;
    for (nCount = 0; nCount < 9; nCount++, pUMods++)
    {
        if (!*pUMods)
        {
            return nCount;
        }
    }
    return 9;
}

// 0x005A0760
static void __stdcall MONSTERUNIQUE_AssignRandomUMods(D2GameStrc* pGame, D2UnitStrc* pUnit, int bAllowChampion)
{
    unsigned char bUModUsageTable[256];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex >= 8)
    {
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return;
    }

    if (bAllowChampion)
    {
        int nChance;
        if (sgptDataTables->nMonUModTxtRecordCount <= 0)
        {
            nChance = 0;
        }
        else
        {
            D2MonUModTxt* pRecord = sgptDataTables->pMonUModTxt;
            if (!pRecord)
            {
                nChance = 0;
            }
            else
            {
                nChance = pRecord->dwConstants;
            }
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < nChance)
        {
            SetMonTypeFlag(pUnit, 4, 1);
            sub_005A02E0_AddUMod(sub_005A0500_RollChampionUMod(pUnit, pGame), pUnit);
            return;
        }
    }

    int nRandCount = SEED_RollLimitedRandomNumber(pSeed, 1) + 1;
    nRandCount += pGame->nDifficulty;
    if (nRandCount + nIndex >= 9)
    {
        nRandCount = 9 - nIndex;
    }

    memset(bUModUsageTable, 0, sgptDataTables->nMonUModTxtRecordCount);
    for (int i = 0; i < nIndex; ++i)
    {
        bUModUsageTable[pUMods[i]] = 1;
    }

    pUMods += nIndex;
    while (nRandCount)
    {
        const int nUMod = MONSTERUNIQUE_RollNonChampionUMod(pGame, pUnit, bUModUsageTable);
        if (!nUMod)
        {
            break;
        }

        *pUMods = nUMod;
        --nRandCount;
        ++pUMods;
        bUModUsageTable[nUMod] = 1;
    }
}

// 0x005A11F0
void __fastcall MONSTERUNIQUE_UMod37_Fanatic(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && bUnique)
    {
        STATLIST_SetUnitStat(pUnit, STAT_ITEM_ARMOR_PERCENT, -70, 0);
        sub_005A0E80_ApplyMonsterPenalty(pUnit, nUMod, bUnique);
    }
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

enum { STAT_HITPOINTS = 6, STAT_MAXHP = 7, MONTYPEFLAG_POSSESSED = 0x20 };

static inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return pUnit->pMonsterData;
    return 0;
}

static inline int MONSTERUNIQUE_ApplyPercentage(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
        return 0;
    if (nValue <= 0x100000)
    {
        if (nMultiplier <= 0x10000)
            return (int)((unsigned int)nMultiplier * (unsigned int)nValue) / nDivisor;
        if (nDivisor <= (nMultiplier >> 4))
            return (int)((unsigned int)nValue * (unsigned int)(nMultiplier / nDivisor));
    }
    else if (nDivisor <= (nValue >> 4))
    {
        return (int)((unsigned int)nMultiplier * (unsigned int)(nValue / nDivisor));
    }
    return (int)(nMultiplier * (__int64)nValue / nDivisor);
}

// 0x005A1370
int __fastcall MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, 31, 0);
            STATLIST_SetUnitStat(pUnit, 31, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, 39, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, 41, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, 43, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, 45, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, 36, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, 37, 0);

        if (nFireResist >= 100) ++nImmunities;
        if (nLightResist >= 100) ++nImmunities;
        if (nColdResist >= 100) ++nImmunities;
        if (nPoisonResist >= 100) ++nImmunities;
        if (nDamageResist >= 100) ++nImmunities;
        if (nMagicResist >= 100) ++nImmunities;

        if (nImmunities < 2)
        {
            if (nUMod == 8)
            {
                if (nColdResist < 100)
                {
                    int nNewColdResist = nColdResist + 40;
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, 39, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, 43, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, 41, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, 45, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, 37, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, 43, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, 39, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, 41, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, 36, nDamageResist + 50, 0);
        }
    }
}

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

// 0x005A01E0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return -1;
    }
    return pMonsterData->wBossHcIdx;
}

// 0x005A1650
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1 || !bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 0)
    {
        nLevel = 1;
    }

    int nCount = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (gAuraEnchantTable_0073BF68[i].nLevel <= nLevel)
        {
            ++nCount;
        }
    }

    if (!nCount)
    {
        nCount = 1;
    }

    const unsigned short wNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, wNameSeed);
    int nIndex = SEED_RollLimitedRandomNumber(&tSeed, nCount);
    if (MONSTERUNIQUE_GetBossHcIdx(pUnit) == 37)
    {
        nIndex = 5;
    }

    if (pUnit->dwClassId == 0x2C0)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_CONVICTION, 20, 1);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_CONVICTION, -1);
        return;
    }

    int nSkillLevel = (gAuraEnchantTable_0073BF68[nIndex].nLevelAdd + nLevel) * gAuraEnchantTable_0073BF68[nIndex].nMul / gAuraEnchantTable_0073BF68[nIndex].nDiv;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 99);

    D2GAME_SetSkills_6FD14C60(pUnit, gAuraEnchantTable_0073BF68[nIndex].nSkillId, nSkillLevel, 1);
    D2GAME_AssignSkill_6FD13800(pUnit, 0, gAuraEnchantTable_0073BF68[nIndex].nSkillId, -1);
}

static inline D2MissilesTxt* MONUNIQUE_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static inline D2MonLvlTxt* MONUNIQUE_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
        return &sgptDataTables->pMonLvlTxt[nLevel];
    return 0;
}

static inline int MONUNIQUE_GetMonUModConstant_Inline(int nIndex)
{
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonUModTxtRecordCount)
        return 0;
    D2MonUModTxt* pRecord = &sgptDataTables->pMonUModTxt[nIndex];
    if (!pRecord)
        return (int)pRecord;
    return pRecord->dwConstants;
}

static inline unsigned int MONUNIQUE_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005A21D0
static void __stdcall sub_005A21D0_ApplyElementalDamageStats(D2UnitStrc* pUnit, int nMinDamageStatId, int nMaxDamageStatId, int nLengthStatId, D2GameStrc* pGame)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = MONUNIQUE_GetMissilesTxtRecord_Inline(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[1] & gdwBitMasks[5])
            return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = MONUNIQUE_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
        return;

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    const int nMinDamage = MONUNIQUE_GetMonUModConstant_Inline(28) * nDamage / 100;
    const int nMaxDamage = MONUNIQUE_GetMonUModConstant_Inline(31) * nDamage / 100;

    D2StatListStrc* pStatList = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetStat(pStatList, nMaxDamageStatId, nMaxDamage, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, nMaxDamage, 0);
    }

    if (nLengthStatId == -1)
        return;

    const int nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetStat(pStatList, nLengthStatId, nLength, 0);
    else
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
}

// 0x005A2530
void __fastcall MONSTERUNIQUE_CastAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if (((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 3) < 1)
    {
        return;
    }

    int nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 5 + 1;
    if (nSkillLevel < 1)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_AMPLIFYDAMAGE);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, SKILL_AMPLIFYDAMAGE, nSkillLevel);
    SKILLS_ApplyCurseAroundTarget(pGame, 3, pUnit, nSkillLevel, D2_MIN(D2_MAX(nRange, 1), 40), MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage);
}

// 0x005A2840
void __fastcall MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);

    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
    if (!pMissile)
    {
        return;
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = 0x6400;
    damage.dwFireDamage = 0x6400;
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 6, &damage, 0, 0, 0, 0x583);
}

// 0x005A2BA0
void __fastcall MONSTERUNIQUE_CastLightUniqueMissileIfNotGetHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && (!pUnit || pUnit->dwAnimMode != MONMODE_GETHIT))
    {
        MONSTERUNIQUE_CastLightUniqueMissile(pGame, pUnit, nUMod, bUnique);
    }
}

// 0x005A2BD0
void __fastcall MONSTERUNIQUE_CastColdUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 2;
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, MISSILE_COLDUNIQUE, 0, nLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
}

// 0x005A2C20
void __fastcall MONSTERUNIQUE_CastCorpsePoisonCloud(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nLevel <= 1)
    {
        nLevel = 1;
    }

    SKILLS_CreateMissileAtOffset(pGame, MISSILE_CORPSEPOISONCLOUD, pUnit, 0, nLevel, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
}

// 0x005A2CC0
void __fastcall MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused)
{
    D2GameStrc* pGame = (D2GameStrc*)pGameArg;
    AIGENERAL_FreeMinionList(pUnit);
    AIGENERAL_SetOwnerData(pGame, pUnit, -1, 1, 0, 0);

    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }
}

inline int D2Clamp(int v, int low, int high)
{
    return (v < low) ? low : (high < v) ? high : v;
}

// 0x005A2D80
void __fastcall MONSTERUNIQUE_AddSecondaryDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage > 0 && (!pUnit || pUnit->dwClassId != MONSTER_ROGUEHIRE))
    {
        nMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0) - 1;
        nMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0) - 1;
        if (nMinDamage < 0)
        {
            nMinDamage = 0;
        }
        if (nMaxDamage < 0)
        {
            nMaxDamage = 0;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStat(pStatList, STAT_MAXDAMAGE, nMaxDamage, 0);
    }
}

// 0x005A2E00
void __fastcall MONSTERUNIQUE_AddRogueHireMissileSecondaryDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    int nMinDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
    int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    if (nMaxDamage <= 0)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || pOwner->dwClassId != MONSTER_ROGUEHIRE)
    {
        return;
    }

    nMinDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MINDAMAGE, 0) << 8) - 256;
    nMaxDamage += (STATLIST_UnitGetStatValue(pOwner, STAT_SECONDARY_MAXDAMAGE, 0) << 8) - 256;

    if (nMinDamage < 0)
    {
        nMinDamage = 0;
    }

    if (nMaxDamage < 0)
    {
        nMaxDamage = 0;
    }

    STATLIST_SetUnitStat(pUnit, STAT_MINDAMAGE, nMinDamage, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXDAMAGE, nMaxDamage, 0);
}

// 0x005A2EB0
void __fastcall MONSTERUNIQUE_ScarabModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (!pBoss || pBoss->dwAnimMode == MONMODE_GETHIT || pBoss->dwAnimMode == MONMODE_DEATH)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}

// 0x005A2EE0
void __fastcall MONSTERUNIQUE_CastBugLightningMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_BUGLIGHTNING;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nX = gnBugLightningXOffsets_006E21A8[i] + nUnitX;
        const int nY = gnBugLightningYOffsets_006E2198[i] + nUnitY;

        for (int j = 0; j < 2; ++j)
        {
            missileParams.nInitArg = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A30B0
void __fastcall MONSTERUNIQUE_ApplyMissileElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique && pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        MONSTERUNIQUE_ApplyElementalDamage(pGame, pUnit, nUMod, bUnique);
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

// 0x005A30E0
void __fastcall MONSTERUNIQUE_StealBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < 30)
    {
        return;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || pTarget->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2InventoryStrc* pInventory = pTarget->pInventory;
    for (int i = 0; i < 16; ++i)
    {
        D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, i);
        if (pBeltItem)
        {
            if (pBeltItem->dwUnitType == UNIT_ITEM && pBeltItem->dwAnimMode == IMODE_INBELT && !INVENTORY_GetCursorItem(pInventory))
            {
                D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pBeltItem, pTarget, 1);
                D2CoordStrc pCoord;
                UNITS_GetCoords(pTarget, &pCoord);

                D2CoordStrc pReturnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pTarget), &pCoord, &pReturnCoords, 1, 1);
                D2_ASSERT(pRoom, 2762);

                ITEMS_SetItemFlag(pDupeItem, IFLAG_INSTORE, 1);
                D2GAME_DropItem_6FC52260(pGame, pTarget, pDupeItem, pRoom, pReturnCoords.nX, pReturnCoords.nY);
                const int nX = CLIENTS_GetUnitX(pBeltItem);
                ITEMMODE_RemoveBeltItem(pGame, pTarget, pBeltItem);
                ITEMMODE_CompactBeltColumn(pGame, pTarget, nX);
            }
            return;
        }
    }
}

// 0x005A3250
void __fastcall MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    switch (!pUnit ? -1 : (unsigned int)pUnit->dwClassId)
    {
    case 156:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Andariel(pGame, pUnit);
        break;
    case 229:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnRadamentDeathMissile(pGame, pUnit);
        break;
    case 242:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnMephistoDeathControlMissile(pGame, pUnit);
        break;
    case 256:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Izual(pGame, pUnit);
        break;
    case 267:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Bloodraven(pGame, pUnit);
        break;
    case 540:
    case 541:
    case 542:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_OnQuestCompleteModeChange(pGame, pUnit);
        break;
    case 479:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_ShenkTheOverseer(pGame, pUnit);
        break;
    case 704:
    case 705:
    case 709:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_UberPrimeEvil(pGame, pUnit);
        break;
    }
}

// 0x005A3490
void __fastcall MONSTERUNIQUE_CastQueenPoisonCloudMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    missileParams.nMissile = MISSILE_QUEENPOISONCLOUD;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    const int nXOffsets[] = { 0, 1, 0, -1 };
    const int nYOffsets[] = { -1, 0, 1, 0 };

    for (int j = 0; j < 4; ++j)
    {
        const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
        const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
        const int nTargetX = nXOffsets[j] + nUnitX;
        const int nTargetY = nYOffsets[j] + nUnitY;

        for (int i = 0; i < 2; ++i)
        {
            missileParams.nInitArg = i;
            missileParams.nTargetX = nTargetX;
            missileParams.nTargetY = nTargetY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005A3610_IsWideMissile(int nMissileId)
{
    if (nMissileId < 0x3F)
    {
        return 0;
    }
    if (nMissileId > 0x42)
    {
        return 0;
    }
    return 1;
}

// 0x005A3610
void __fastcall MONSTERUNIQUE_CreateMultishotMissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, int nArg)
{
    if (!nArg || !pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    const int nMissileId = pMissile->dwClassId;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_005A0180_CheckMonsterFlag(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    int nY;
    if (!pTarget)
    {
        nArg = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nArg = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 0x53454953);
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDeltaX = CLIENTS_GetUnitX(pOwner) - nArg;
    int nDeltaY = CLIENTS_GetUnitY(pOwner) - nY;
    if (nDeltaX < 0)
    {
        nDeltaX = -1;
    }
    else if (nDeltaX > 0)
    {
        nDeltaX = 1;
    }

    if (nDeltaY < 0)
    {
        nDeltaY = -1;
    }
    else if (nDeltaY > 0)
    {
        nDeltaY = 1;
    }

    if (sub_005A3610_IsWideMissile(nMissileId))
    {
        nDeltaY = 0;
        nDeltaX = 0;
    }

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg - nDeltaY, nY + nDeltaX, 0);
    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg + nDeltaY, nY - nDeltaX, 0);

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x005A3840
void __fastcall MONSTERUNIQUE_ScheduleSelfResurrection(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwAnimMode != MONMODE_DEATH)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_EVIL)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MONUMOD, 0);

    if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStatsTxtRecord->wAiParam[7][pGame->nDifficulty])
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
}

// 0x005A3910
void __fastcall MONSTERUNIQUE_TrySelfResurrection(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (!SUNIT_IsDead(pUnit) || STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_RESURRECTED)
    {
        return;
    }

    if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
    {
        return;
    }

    if (COLLISION_CheckMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, COLLIDE_MASK_MONSTER_PATH))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 10 * pMonStatsTxtRecord->wAiParam[0][pGame->nDifficulty] + 1, 0, 0);
    }
    else if (AIGENERAL_GetAiControlParam(pUnit, 1) < 2 && D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_SELF_RESURRECT, 0, 0, 0);
            if (pUnit)
            {
                pUnit->dwFlags &= 0xFBFDFFFF;
            }
            const int nParam = AIGENERAL_GetAiControlParam(pUnit, 1);
            AIGENERAL_SetAiControlParam(pUnit, 1, nParam + 1);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 51, 0, 0);
        }
    }
}

// 0x005A3A80
void __fastcall MONSTERUNIQUE_ApplyShatterState(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        STATES_ToggleState(pUnit, STATE_SHATTER, 1);
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

// 0x005A3AA0
void __fastcall MONSTERUNIQUE_KillUnitOrRemovePet(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 3, 0, 0);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_RemovePet(pGame, pOwner, !pUnit ? -1 : pUnit->dwUnitId, 1);
        return;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEATH, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

static inline int MONSTERUNIQUE_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x005A3B50
void __fastcall MONSTERUNIQUE_SetTrapDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    int nLevel = 2;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (nLevelId)
    {
        nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
        nLevel = MAX(nLevel, 1);
    }

    const int nToHit = MIN(nLevel + 50, 90);
    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel, 0);
    STATLIST_SetUnitStat(pUnit, STAT_TOHIT, nToHit, 0);

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nUnitType == UNIT_MONSTER, 3138);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
    switch (MONSTERUNIQUE_GetClassIdInline(pUnit))
    {
    case MONSTER_TRAP_FIREBOLT:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    case MONSTER_TRAP_HORZMISSILE:
    case MONSTER_TRAP_VERTMISSILE:
    {
        const int nMinDamage = MIN(nLevel, (nLevel >> 1) + 1);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, nMinDamage, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, nLevel, 0);
        break;
    }
    case MONSTER_TRAP_POISONCLOUD:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMINDAM, nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMAXDAM, 2 * nLevel, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONLENGTH, 2 * nLevel, 0);
        break;
    }
    case MONSTER_TRAP_LIGHTNING:
    case MONSTER_TRAP_NOVA:
    {
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, 0, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMINDAM, nLevel >> 1, 0);
        STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMAXDAM, 3 * nLevel >> 1, 0);
        break;
    }
    }
}

// 0x005A6000
int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCallbackId, int nOtherPlayerGUID, int nParam)
{
    int bFailure = 0;
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOtherPlayerGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    if (gpfPartyCommands_6FD28E60[nCallbackId])
    {
        if (IsBadCodePtr((FARPROC)gpfPartyCommands_6FD28E60[nCallbackId]))
        {
            return 3;
        }

        gpfPartyCommands_6FD28E60[nCallbackId](pGame, pUnit, pOtherPlayer, nParam, &bFailure);
        if (bFailure)
        {
            return 3;
        }
    }

    return 0;
}

// 0x005A6130
int __fastcall FRIENDLY_AreUnitsFriendly(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nType1 = UNIT_INVALID;
    if (pUnit1)
    {
        nType1 = pUnit1->dwUnitType;
    }

    switch (nType1)
    {
    case UNIT_PLAYER:
        return !PLAYERLIST_CheckFlag(pUnit1, pUnit2, PLAYERLIST_FLAG_HOSTILE);

    case UNIT_MONSTER:
    {
        int nType2 = UNIT_INVALID;
        if (pUnit2)
        {
            nType2 = pUnit2->dwUnitType;
        }

        switch (nType2)
        {
        case UNIT_PLAYER:
            return !PLAYERLIST_CheckFlag(pUnit2, pUnit1, PLAYERLIST_FLAG_HOSTILE);

        case UNIT_MONSTER:
            return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
        }
        break;
    }
    }

    return 0;
}

// build: context sub_005A0930_TransferUMods
static void __stdcall sub_005A0930_TransferUMods(D2UnitStrc* pOwner, D2UnitStrc* pMinion, int bFromStart)
{
    unsigned char* pOwnerUMods = UModsOfData(pOwner);
    unsigned char* pMinionUMods = UModsOfData(pMinion);
    if (!pOwnerUMods || !pMinionUMods)
    {
        return;
    }

    int nIndex = 0;
    if (!bFromStart)
    {
        nIndex = CountUModsTo(pMinionUMods);
    }
    pMinionUMods += nIndex;
    while (nIndex < 9)
    {
        const unsigned char nOwnerUMod = *pOwnerUMods;
        if (!nOwnerUMod)
        {
            break;
        }

        D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(nOwnerUMod);
        if (!pMonUModTxtRecord)
        {
            break;
        }

        if (pMonUModTxtRecord->nXfer)
        {
            *pMinionUMods = nOwnerUMod;
            ++pMinionUMods;
        }

        ++nIndex;
        ++pOwnerUMods;
    }
}

// 0x005A09E0
static D2UnitStrc* __stdcall MONSTERUNIQUE_SpawnUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nUnitGUID, int nClassId, int bAvoidWarps)
{
    if (!nX && !nY)
    {
        if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pRoomCoordList, nClassId, &nX, &nY, bAvoidWarps))
        {
            return 0;
        }
    }

    D2UnitStrc* pMonster = 0;
    if (pRoomCoordList)
    {
        pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pRoomCoordList, nX, nY, nClassId, 1, -1, 64);
    }
    else if (nUnitGUID == -1)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 64);
        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, 5, 64);
        }
    }
    else
    {
        pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
        if (!pMonster)
        {
            pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 5, 98);
            if (!pMonster)
            {
                if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nClassId, &nX, &nY, 0))
                {
                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
                }

                if (!pMonster)
                {
                    D2CoordStrc tCoord;
                    tCoord.nX = nX;
                    tCoord.nY = nY;
                    D2ActiveRoomStrc* pTargetRoom;
                    D2Common_10136(pRoom, &tCoord, 1, 0x3C01, &pTargetRoom);
                    if (!pTargetRoom)
                    {
                        return 0;
                    }

                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pTargetRoom, tCoord.nX, tCoord.nY, nClassId, 1, nUnitGUID, -1, 98);
                }
            }
        }
    }

    if (!pMonster)
    {
        return 0;
    }

    sub_005A0320_MarkUnique(pGame, pMonster);
    SetMonTypeFlag(pMonster, 1, 1);
    QUESTS_SetJadeFigurineBoss(pGame, pMonster);
    AIGENERAL_SetOwnerData(pGame, pMonster, !pMonster ? -1 : pMonster->dwUnitId, 1, 1, 0);
    return pMonster;
}

// 0x005A0BB0
static int sub_005A0BB0_GetMinionId(D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return pMonStatsTxtRecord->wMinion[0];
    }

    return nClassId;
}

// 0x005A0C00
static void __stdcall sub_005A0C00_SpawnMinionGroup(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMinGroup, int nMaxGroup)
{
    if (TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    const int nMinionId = sub_005A0BB0_GetMinionId(pUnit);
    if (nMinionId < 0 || nMinionId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    const int nMinionCount = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxGroup - nMinGroup + 1) + nMinGroup;
    for (int i = 0; i < nMinionCount; ++i)
    {
        D2UnitStrc* pMinion;
        if (pRoomCoordList)
        {
            pMinion = MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pRoomCoordList, pUnit, nMinionId, 1, 3, 64);
        }
        else
        {
            pMinion = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nMinionId, 1, 3, 64);
        }

        if (pMinion)
        {
            sub_005A0930_TransferUMods(pUnit, pMinion, 0);
            AIGENERAL_SetOwnerData(pGame, pMinion, sub_00451F50_GetUnitGUID(pUnit), 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pUnit, pMinion);
            AIUTIL_SetOwnerGUIDAndType(pMinion, pUnit);
            SetMonTypeFlag(pMinion, 0x10, 1);
        }
    }
}

// 0x005A2120
static void __stdcall MONSTERUNIQUE_SpawnMinions(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int bSpawnMinions, int nMinGroup, int nMaxGroup)
{
    if (bSpawnMinions)
    {
        sub_005A0C00_SpawnMinionGroup(pGame, pRoomCoordList, pUnit, nMinGroup, nMaxGroup);
    }

    for (int i = 0; i < 4; ++i)
    {
        const int nUMod = gnBaseUMods_006E2168[i];
        InitUMod(pUnit, nUMod, 1);
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (pUMods)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (!nUMod)
            {
                break;
            }

            InitUMod(pUnit, nUMod, 1);
            AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
        }
    }
}

// 0x005A43E0
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, pRoomCoordList, nX, nY, -1, nClassId, bAvoidWarps);
    if (!pMonster)
    {
        return 0;
    }

    MONSTERUNIQUE_AssignRandomUMods(pGame, pMonster, bAllowChampion);
    MONSTERUNIQUE_SpawnMinions(pGame, pRoom, pRoomCoordList, pMonster, 1, 3, 6);
    return pMonster;
}

// build: context SetBossIndex
static inline void SetBossIndex(D2UnitStrc* pUnit, short nIndex)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wBossHcIdx = nIndex;
        }
    }
}

// 0x005A4440
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned short nNameSeed, int bChampion, int bSuperUnique, short nBossHcIdx, unsigned char* pUMods)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, 0, nX, nY, nUnitGUID, nClassId, 1);
    if (!pMonster)
    {
        return pMonster;
    }

    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        unsigned char* pMonUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
        if (pMonUMods)
        {
            SetMonTypeFlag(pMonster, 4, bChampion);

            int bAuraEnchanted = 0;
            for (int i = 0; i < 9; ++i)
            {
                pMonUMods[i] = pUMods[i];
                if (pUMods[i] == 30)
                {
                    bAuraEnchanted = 1;
                }
            }

            MONSTERUNIQUE_SpawnMinions(pGame, pRoom, 0, pMonster, 0, 0, 0);

            pMonsterData = MonsterDataOf(pMonster);
            if (pMonsterData)
            {
                pMonsterData->wNameSeed = nNameSeed;
            }

            if (bAuraEnchanted)
            {
                MONSTERUNIQUE_UMod30_AuraEnchanted(pMonster, 30, 1);
            }

            if (bSuperUnique)
            {
                SetMonTypeFlag(pMonster, 2, 1);
                SetBossIndex(pMonster, nBossHcIdx);

                switch (nBossHcIdx)
                {
                case 6:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 5);
                    break;
                case 60:
                    QUESTS_CreateChainRecord(pGame, pMonster, 34);
                    break;
                case 42:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 31);
                    break;
                case 43:
                case 44:
                case 45:
                    QUESTS_CreateChainRecord(pGame, pMonster, 35);
                    break;
                case 26:
                case 27:
                case 29:
                    QUESTS_CreateChainRecord(pGame, pMonster, 19);
                    break;
                case 39:
                    QUESTS_CreateChainRecord(pGame, pMonster, 4);
                    break;
                case 36:
                case 37:
                case 38:
                    QUESTS_CreateChainRecord(pGame, pMonster, 23);
                    break;
                }
            }
        }
    }

    return pMonster;
}

// 0x005A4850
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (!pUMods)
    {
        return;
    }

    if (bUnique)
    {
        sub_005A0320_MarkUnique(pGame, pUnit);
    }

    const int nIndex = CountUMods(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        InitUMod(pUnit, nUMod, bUnique);
    }
}

// 0x005A48C0
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nUMod)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    unsigned char* pUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
    if (!pUMods || TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    sub_005A0320_MarkUnique(pGame, pUnit);
    SetMonTypeFlag(pUnit, 4 | 1, 1);

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        MONSTERUNIQUE_SpawnMinions(pGame, UNITS_GetRoom(pUnit), 0, pUnit, 1, 0, 0);
    }
}

// build: context PromoteGetUMods
static inline unsigned char* PromoteGetUMods(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        return pMonsterData ? pMonsterData->nMonUmod : 0;
    }
    return 0;
}

// build: context PromoteSetTypeFlag
static inline void PromoteSetTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1 && pUnit->pMonsterData)
        pUnit->pMonsterData->nTypeFlag |= nFlag;
}

void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
        return;

    const unsigned int nRand = MONUNIQUE_RollSeed_Inline(&pUnit->pSeed) % 5;
    sub_005A21D0_ApplyElementalDamageStats(pUnit, gnUniqueElementalStats_006E21B8[nRand][0], gnUniqueElementalStats_006E21B8[nRand][1], gnUniqueElementalStats_006E21B8[nRand][2], pGame);
}

#include "gen/data/Source/D2Game/MONSTER/MonsterUnique.inc"
