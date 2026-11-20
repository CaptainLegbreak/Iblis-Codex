#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STAT_ITEM_UNDEADDAMAGE_PERCENT 122
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_DAMAGE_VS_MONTYPE 180
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2DifficultyLevelsTxt;
struct Context;
struct Record;
struct D2DamageContextStrc;
struct D2ResistTableEntryStrc;
struct D2SkillsTxt;
struct D2ModeChangeStrc;
struct D2DamageHitClassMappingStrc;
struct D2UnitFindArgStrc;



struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};



struct D2DifficultyLevelsTxt
{
    char unk0x00[0x14];
    int dwMonsterFreezeDiv;
    int dwMonsterColdDiv;
    char unk0x1C[0x0C];
    int dwLifeStealDiv;
    int dwManaStealDiv;
};


struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char unk0x06[0x02];
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    char unk0x50[0x10];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    unsigned char nConvType;
    char unk66[2];
    int nConvPct;
    int nOverlay;
};

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057AD80
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30
void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057B170
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4390
void __fastcall sub_6FCF8DD0(D2UnitStrc* pUnit); // 0x005D6410
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, unsigned int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x00625310
int __stdcall STATLIST_GetExpireFrame(D2StatListStrc* pStatList); // 0x00625330
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
static __declspec(noinline) void __stdcall SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nPoisonDamage, int nPoisonLength);
static __declspec(noinline) void __stdcall SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nBurnDamage, int nBurnLength);
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc*); // 0x00535BC0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc*, D2InventoryStrc*); // 0x0063D340
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc*, int, int); // 0x00625500
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc*); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc*); // 0x006298A0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc*, D2UnitStrc*, D2SkillStrc*, int); // 0x00645830
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc*,int); // 0x00535D10
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc*,int); // 0x00535E20
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc*); // 0x006259B0
int __stdcall MONSTERS_IsDemon(D2UnitStrc*); // 0x0063E940
int __fastcall sub_0057B420_RollPhysicalDamage(D2UnitStrc*,int,int,int,int,int,int,unsigned char); // 0x0057B420
int __stdcall sub_00645830_GetCriticalStrikeChance(D2UnitStrc*,D2UnitStrc*,int,int); // 0x00645830
int __fastcall sub_00472280(D2SeedStrc*,int,int); // 0x00472280
int __fastcall SUNITEVENT_Trigger(D2GameStrc*,int,D2UnitStrc*,D2UnitStrc*,void*); // 0x005C0C30
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc*,D2UnitStrc*,D2DamageStrc*); // 0x005A5560

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

struct D2DamageContextStrc
{
    void* pGame;
    void* pDifficultyLevelsTxt;
    D2UnitStrc* pAttacker;
    D2UnitStrc* pDefender;
    int bAttackerIsMonster;
    int bDefenderIsMonster;
    D2DamageStrc* pDamage;
};

struct D2ResistTableEntryStrc
{
    int nOffsetInDamageStrc;
    int nResStatId;
    int nMaxResStatId;
    int nPierceStatId;
    int nAbsorbPctStatId;
    int nAbsorbStatId;
};

static __declspec(noinline) int __cdecl sub_0057BF10_AbsorbDamage(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue);


struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit   ;
    int nX                        ;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

extern "C" const D2DamageHitClassMappingStrc gsDamageHitClassMapping_006E16D8[8]; // 0x006E16D8
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A54F0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
int __stdcall sub_0057CB00(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nHitClass); // 0x0057CB00
void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A43A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
// 0x0057CE30
static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass); // 0x0057CE30
// 0x0057CEC0
static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage); // 0x0057CEC0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
static __declspec(noinline) int sub_0057DCA0_GetWieldedTypeStatMax(D2UnitStrc* pUnit);
void __fastcall sub_005347C0_Stub6(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, const char*); // 0x005347C0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380
int __stdcall UNITS_GetBlockRate(D2UnitStrc*, int); // 0x00622720
int __stdcall UNITS_IsInMovingMode(D2UnitStrc*); // 0x00622D00
static __declspec(noinline) int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc*, D2UnitStrc*, int);

struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

typedef int (__fastcall* DAMAGECALLBACK)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(DAMAGECALLBACK lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD730
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask); // 0x00645950
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

static __forceinline unsigned int sub_I19_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0057A980
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

// 0x0057AA00
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

// 0x0057AA60
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

// 0x0057AAA0
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

// 0x0057AC50
static void __stdcall SUNITDMG_ApplyPoisonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nPoisonDamage, int nPoisonLength)
{
    if (nPoisonLength <= 0 || nPoisonDamage <= 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 2);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    if ((!pDefender ? 6 : pDefender->dwUnitType) == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 3, 0);
        EVENT_SetEvent(pGame, pDefender, 3, pGame->dwGameFrame + 1, 0, 0);
    }

    const int nExpireFrame = nPoisonLength + pGame->dwGameFrame;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 2, 1);
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pAttacker ? 6 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId);
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

// 0x0057ADD0
static void __stdcall SUNITDMG_ApplyBurnDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nBurnDamage, int nBurnLength)
{
    if (nBurnLength <= 0 || nBurnDamage <= 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 0x73);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pAttacker);
    if ((!pDefender ? 6 : pDefender->dwUnitType) == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pDefender, 3, 0);
        EVENT_SetEvent(pGame, pDefender, 3, pGame->dwGameFrame + 1, 0, 0);
    }

    const int nExpireFrame = nBurnLength + pGame->dwGameFrame;
    if (!pStatList)
    {
        STATES_ToggleState(pDefender, 0x73, 1);
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pAttacker ? 6 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId);
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

// build: context sub_0057C420_ApplyLeech
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

// build: context SUNITDMG_ExecuteEvents
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
    SUNITDMG_ApplyPoisonDamage(pAttacker, pDefender, pDamage->dwPoisDamage, pDamage->dwPoisLen);
    SUNITDMG_ApplyBurnDamage(pAttacker, pDefender, pDamage->dwBurnDamage, pDamage->dwBurnLen);

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

// 0x0057B420
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam)
{
    if (bGetStats)
    {
        if (!pItem) pItem = sub_6FC7C7B0(pUnit);
        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
            {
                nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
                nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x18, 0);
            }
            else
            {
                nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
                nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            }
        }
        else
        {
            nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
            if (nMinDmg <= 0) nMinDmg = 1;
            nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            if (nMaxDmg <= 1) nMaxDmg = 2;
        }
        nMinDmg <<= 8;
        nMaxDmg <<= 8;
    }
    const int nBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x6F, 0) << 8;
    nMinDmg += nBonus;
    nMaxDmg += nBonus;
    if (nMinDmg < 1) nMinDmg = 256;
    if (nMaxDmg <= nMinDmg) nMaxDmg = nMinDmg + 256;
    nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
    if (pItem)
    {
        int nFactor = ITEMS_GetStrengthBonus(pItem);
        if (nFactor) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
        nFactor = ITEMS_GetDexBonus(pItem);
        if (nFactor) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
        nDamagePercent += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, 0, 1);
    }
    else if (bGetStats) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0, 0);
    if (nDamagePercent <= -90) nDamagePercent = -90;
    int nResult = nDamage;
    if (nMaxDmg > 0)
    {
        const int nMin = nMinDmg + DATATBLS_ApplyRatio(nMinDmg, nMinPercent + nDamagePercent, 100);
        const int nMax = nMaxDmg + DATATBLS_ApplyRatio(nMaxDmg, nMaxPercent + nDamagePercent, 100);
        nResult = nMin + nDamage;
        if (nMax > nMin) nResult += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin);
    }
    nResult = nResult < 0 ? 0 : nResult;
    if (nSrcDam != 0x80) return DATATBLS_ApplyRatio(nResult, nSrcDam, 0x80);
    return nResult;
}

// 0x0057A880
static int __stdcall sub_0057A880_AddRolledDamage(D2UnitStrc* pUnit, int nMin, int nMax, int nMinPct, int nMaxPct, int nDamage)
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

    return sub_0057A880_AddRolledDamage(pUnit, nMin, nMax, nMinPct, nMaxPct, nDamage);
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

// 0x0057B7D0
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender,D2DamageStrc* pDamage,int nWeapon,unsigned char nSrcDam)
{
    if (!pAttacker || !pDefender) return;
    if (!nSrcDam) nSrcDam=128;
    PLAYER_ApplyWeaponStatsForSkill(pAttacker,nWeapon);
    const int nAttackerType=pAttacker->dwUnitType;
    const int nDefenderType=pDefender->dwUnitType;
    pDamage->dwHitFlags|=0x20;
    if ((!nAttackerType || STATLIST_GetUnitAlignment(pAttacker)==2) && nDefenderType==1)
    {
        int nTargetDefense=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,120,0);
        if(nTargetDefense)
        {
            int nDefense=STATLIST_UnitGetStatValue(pDefender,31,0)+nTargetDefense;
            if(nDefense<0) nDefense=0;
            STATLIST_SetUnitStat(pDefender,31,nDefense,0);
        }
        if(MONSTERS_IsDemon(pDefender))
        {
            int nPct=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,121,0);
            if(nPct>0) pDamage->dwEnDmgPct+=nPct;
        }
        sub_0057B660_AddUndeadDamagePercent(pDamage,pAttacker,pDefender);
        sub_0057B6A0_AddMonTypeDamagePercent(pAttacker,pDamage,pDefender);
    }
    if(!(pDamage->dwHitFlags&1))
    {
        pDamage->dwPhysDamage=sub_0057B420_RollPhysicalDamage(pAttacker,1,0,0,0,pDamage->dwEnDmgPct,pDamage->dwPhysDamage,nSrcDam);
        if(!nWeapon)
        {
            D2UnitStrc* pWeapon=sub_6FC7C7B0(pAttacker);
            if(pWeapon)
            {
                int nChance=sub_00645830_GetCriticalStrikeChance(pAttacker,pWeapon,0,2);
                if(nChance>0 && sub_00472280(&pAttacker->pSeed,0,100)<nChance) goto critical;
            }
        }
        {
            int nChance=STATLIST_UnitGetStatValue(pAttacker,337,0);
            if(nChance>0 && sub_00472280(&pAttacker->pSeed,0,100)<nChance) goto critical;
            nChance=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,141,0);
            if(nChance<=0 || sub_00472280(&pAttacker->pSeed,0,100)>=nChance) goto elemental;
        }
critical:
        pDamage->dwPhysDamage*=2;
        pDamage->wResultFlags|=0x2000;
    }
elemental:
    if(nSrcDam!=128)
    {
        pDamage->dwFireDamage=sub_0057A8E0_AddStatDamage(48,329,0,0,pDamage->dwFireDamage,49,pAttacker)*nSrcDam/128;
        pDamage->dwLtngDamage=sub_0057A8E0_AddStatDamage(50,330,0,0,pDamage->dwLtngDamage,51,pAttacker)*nSrcDam/128;
        pDamage->dwColdDamage=sub_0057A8E0_AddStatDamage(54,331,0,0,pDamage->dwColdDamage,55,pAttacker)*nSrcDam/128;
        pDamage->dwMagDamage=sub_0057A8E0_AddStatDamage(52,357,0,0,pDamage->dwMagDamage,53,pAttacker)*nSrcDam/128;
    }
    else
    {
        pDamage->dwFireDamage=sub_0057A8E0_AddStatDamage(48,329,0,0,pDamage->dwFireDamage,49,pAttacker);
        pDamage->dwLtngDamage=sub_0057A8E0_AddStatDamage(50,330,0,0,pDamage->dwLtngDamage,51,pAttacker);
        pDamage->dwColdDamage=sub_0057A8E0_AddStatDamage(54,331,0,0,pDamage->dwColdDamage,55,pAttacker);
        pDamage->dwMagDamage=sub_0057A8E0_AddStatDamage(52,357,0,0,pDamage->dwMagDamage,53,pAttacker);
    }
    int bHireling=sub_0063EE90_IsHireling(pAttacker);
    if(nAttackerType==1 && !bHireling)
    {
        if(!(pDamage->dwHitFlags&4)) pDamage->dwLifeLeech+=sub_0057A8E0_AddStatDamage(60,-1,0,0,pDamage->dwLifeLeech,61,pAttacker)*nSrcDam/128;
        if(!(pDamage->dwHitFlags&8)) pDamage->dwManaLeech+=sub_0057A8E0_AddStatDamage(62,-1,0,0,pDamage->dwManaLeech,63,pAttacker)*nSrcDam/128;
        if(!(pDamage->dwHitFlags&16)) pDamage->dwStamLeech+=sub_0057A8E0_AddStatDamage(64,-1,0,0,pDamage->dwStamLeech,65,pAttacker)*nSrcDam/128;
    }
    else if(!nAttackerType || bHireling)
    {
        if(!(pDamage->dwHitFlags&4)) pDamage->dwLifeLeech+=STATLIST_UnitGetStatValue(pAttacker,60,0);
        if(!(pDamage->dwHitFlags&8)) pDamage->dwManaLeech+=STATLIST_UnitGetStatValue(pAttacker,62,0);
        if(STATLIST_UnitGetStatValue(pAttacker,103,0)) pDamage->dwHitFlags|=0x100;
        if(STATLIST_UnitGetStatValue(pAttacker,104,0)) pDamage->dwHitFlags|=0x200;
        if(STATLIST_UnitGetStatValue(pAttacker,106,0)) pDamage->dwHitFlags|=0x400;
    }
    int nPoisonMin=STATLIST_UnitGetStatValue(pAttacker,57,0);
    int nPoisonMax=STATLIST_UnitGetStatValue(pAttacker,58,0);
    int nPoisonPct=0;
    if(nPoisonMax>0) nPoisonPct=STATLIST_UnitGetStatValue(pAttacker,332,0);
    pDamage->dwPoisDamage=sub_0057A880_AddRolledDamage(pAttacker,nPoisonMin,nPoisonMax,nPoisonPct,nPoisonPct,pDamage->dwPoisDamage)*nSrcDam/128;
    if(pDamage->dwPoisDamage)
    {
        int nOverride=STATLIST_UnitGetStatValue(pAttacker,101,0);
        if(nOverride>0) pDamage->dwPoisLen+=nOverride;
        else
        {
            pDamage->dwPoisLen+=STATLIST_UnitGetStatValue(pAttacker,59,0);
            int nCount=STATLIST_UnitGetStatValue(pAttacker,326,0);
            if(nCount>1) pDamage->dwPoisLen/=nCount;
        }
    }
    if(pDamage->dwColdDamage>0) pDamage->dwColdLen+=STATLIST_UnitGetStatValue(pAttacker,56,0)*nSrcDam/128;
    if(!pDamage->dwStunLen) pDamage->dwStunLen+=STATLIST_UnitGetStatValue(pAttacker,66,0)*nSrcDam/128;
    int nBurn=pDamage->dwBurnDamage*nSrcDam+316;
    nBurn+=ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed,1);
    pDamage->dwBurnDamage+=(nBurn<0 ? 0:nBurn)/128;
    if(pDamage->dwBurnLen) pDamage->dwBurnLen+=STATLIST_UnitGetStatValue(pAttacker,315,0)*nSrcDam/128;
    if((!nAttackerType || bHireling) && !(pDamage->wResultFlags&0x20)) SUNITEVENT_Trigger(pGame,3,pDefender,pAttacker,pDamage);
    if(pDamage->nConvType>0)
    {
        int nConverted=DATATBLS_ApplyRatio(pDamage->dwPhysDamage,pDamage->nConvPct,100);
        pDamage->dwPhysDamage-=nConverted;
        pDamage->dwPhysDamage=pDamage->dwPhysDamage<=0 ? 0:pDamage->dwPhysDamage;
        unsigned char nType=pDamage->nConvType;
        if(nType==10) nType=(unsigned char)SEED_RollLimitedRandomNumber(&pAttacker->pSeed,5)+1;
        switch(nType)
        {
        case 1:pDamage->dwFireDamage+=nConverted;break;
        case 2:pDamage->dwLtngDamage+=nConverted;break;
        case 3:pDamage->dwMagDamage+=nConverted;break;
        case 4:pDamage->dwColdDamage+=nConverted;pDamage->dwColdLen=pDamage->dwColdLen<50 ? 50:pDamage->dwColdLen;break;
        case 5:pDamage->dwPoisDamage+=nConverted/8;pDamage->dwPoisLen=pDamage->dwPoisLen<50 ? 50:pDamage->dwPoisLen;break;
        case 11:pDamage->dwFireDamage+=nConverted;pDamage->dwBurnLen=pDamage->dwBurnLen<50 ? 50:pDamage->dwBurnLen;break;
        case 12:pDamage->dwColdDamage+=nConverted;pDamage->dwFrzLen=pDamage->dwFrzLen<50 ? 50:pDamage->dwFrzLen;break;
        }
    }
    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pAttacker,pDefender,pDamage);
    PLAYER_RestoreWeaponStats(pAttacker,nWeapon);
}

// 0x0057BE00
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
        if(resistance<=-100)
        {
            resistance=-100;
        }
        return resistance;
    }
    else
    {
        if(!c->defenderFlag)
        {
            int maximum=75;
            const int nMaximumStat=r->maximumStat;
            if(nMaximumStat!=-1)
                maximum=sub_00625480_Stat(c->defender,nMaximumStat,0)+75;
            else if(r->resistanceStat==36) maximum=50;
            if(maximum>=95) maximum=95;
            resistance=(resistance>-100 ? resistance : -100)<maximum ? (resistance>-100 ? resistance : -100) : maximum;
        }
        if(r->resistanceStat==36 && sub_00639DF0_State(c->attacker,47) && sub_0063E990_ClassB(c->defender))
        {
            resistance=0;
        }
        return resistance;
    }
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

// 0x0057BF10
static int __cdecl sub_0057BF10_AbsorbDamage(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue)
{
    if (pEntry->nAbsorbPctStatId == -1)
    {
        return nValue;
    }

    int nAbsorbPct = STATLIST_UnitGetStatValue(pContext->pDefender, pEntry->nAbsorbPctStatId, 0);
    if (nAbsorbPct >= 40)
    {
        nAbsorbPct = 40;
    }

    if (nAbsorbPct > 0)
    {
        const int nAbsorbed = DATATBLS_ApplyRatio(nValue, nAbsorbPct, 100);
        pContext->pDamage->dwAbsLife += nAbsorbed;
        nValue -= nAbsorbed;
    }

    int nAbsorb = STATLIST_UnitGetStatValue(pContext->pDefender, pEntry->nAbsorbStatId, 0) << 8;
    if (nAbsorb > 0)
    {
        if (nAbsorb >= nValue)
        {
            nAbsorb = nValue;
        }

        pContext->pDamage->dwAbsLife += nAbsorb;
        nValue -= nAbsorb;
    }

    return nValue;
}

// build: context sub_0057BF10_Shim
// calling-convention shim (not game code)
int __fastcall sub_0057BF10_Shim(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue)
{
    return sub_0057BF10_AbsorbDamage(pContext, pEntry, nValue);
}

static unsigned char s_nHitClassCounter_0088CAD0; // 0x0088CAD0

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

static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF0))
    {
        pDamage->dwHitClass = SUNITDMG_GetHitClass(pDamage, pDamage->dwHitClass);
    }
}

static __forceinline int UNIT_GetType(D2UnitStrc* pUnit)
{
 return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x0057CEE0
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
                    StartModeID(pGame, pUnit, pSkill, 0x0D, UNIT_GetType(pAttacker), !pAttacker ? -1 : pAttacker->dwUnitId, 0);
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
                    StartModeID(pGame, pUnit, pSkill, 0x0D, UNIT_GetType(pAttacker), !pAttacker ? -1 : pAttacker->dwUnitId, 0);
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
                StartModeID(pGame, pUnit, 0, 0, UNIT_GetType(pAttacker), !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x08)
        {
            StartModeID(pGame, pUnit, 0, 0x13, UNIT_GetType(pAttacker), !pAttacker ? -1 : pAttacker->dwUnitId, 0);
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
            if (pDamage->wResultFlags & 0x4000) goto Blocked;
            if (pUnit->dwClassId == 0xF3) goto Blocked;
            if (pUnit->dwClassId == 0x14D) goto Blocked;
            if (pUnit->dwClassId == 0x2C1) goto Blocked;
            if (!sub_0046C140_TestMonModeFlag(pUnit->dwClassId, 6))
            {
            Blocked:
                MONSTER_SetAiState(pUnit, 0x13);
                return;
            }
            MONSTERMODE_GetModeChangeInfo(pUnit, 6, &modeChange);
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

// 0x0057DCA0
static int sub_0057DCA0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
{
    int i;
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
    int nBest = 0;
    for (i = 0; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0)
        {
            nBest = nValue;
        }
        else if (pLeftItem && ITEMSIsA(pLeftItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
        else if (pRightItem && ITEMSIsA(pRightItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
    }

    return nBest;
}

int __fastcall sub_0057DCA0_Emit(int nArg, D2UnitStrc* pUnit)
{
    int nValue = sub_0057DCA0_GetWieldedTypeStatMax(pUnit);
    return nValue > 0 ? nValue : nArg;
}

// build: context SEED_RollRandomNumber
static __forceinline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0057DD60
static int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid)
{
    int nResult = 0;
    if (pDefender && pDefender->dwUnitType == 0)
    {
        if (pDefender->dwAnimMode == 3 || pDefender->dwAnimMode == 2)
        {
            const int nEvade = STATLIST_UnitGetStatValue(pDefender, 340, 0);
            if (nEvade > 0)
            {
                const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nEvade, nRand, "evades");
                if (nRand < nEvade)
                {
                    nResult = 8;
                }
            }
            return nResult;
        }

        const int nWeaponBlock = sub_0057DCA0_GetWieldedTypeStatMax(pDefender);
        if (nWeaponBlock > 0)
        {
            int nWeaponClassId;
            COMPOSIT_GetWeaponClassId(pDefender, pDefender->pInventory, &nWeaponClassId, -1, 1);
            if (nWeaponClassId == 13)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nWeaponBlock, nRand, "block");
                if (nRand < nWeaponBlock)
                {
                    return 16;
                }
            }
        }
        if (!bAvoid)
        {
            const int nDodge = STATLIST_UnitGetStatValue(pDefender, 338, 0);
            if (nDodge > 0)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nDodge, nRand, "dodges");
                if (nRand < nDodge)
                {
                    return 4;
                }
            }
        }
        else
        {
            const int nAvoid = STATLIST_UnitGetStatValue(pDefender, 339, 0);
            if (nAvoid > 0)
            {
                const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nAvoid, nRand, "avoids");
                if (nRand < nAvoid)
                {
                    return 2;
                }
            }
        }
    }
    else
    {
        const int bMoving = pDefender && (pDefender->dwAnimMode == 15 || pDefender->dwAnimMode == 2);
        if (!bMoving)
        {
            const int nWeaponBlock = sub_0057DCA0_GetWieldedTypeStatMax(pDefender);
            if (nWeaponBlock > 0)
            {
                int nWeaponClassId;
                COMPOSIT_GetWeaponClassId(pDefender, pDefender->pInventory, &nWeaponClassId, -1, 1);
                if (nWeaponClassId == 13)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nWeaponBlock, nRand, "block");
                    if (nRand < nWeaponBlock)
                    {
                        return 16;
                    }
                }
            }
            if (!bAvoid)
            {
                const int nDodge = STATLIST_UnitGetStatValue(pDefender, 338, 0);
                if (nDodge > 0)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nDodge, nRand, "dodges");
                    if (nRand < nDodge)
                    {
                        return 4;
                    }
                }
            }
            else
            {
                const int nAvoid = STATLIST_UnitGetStatValue(pDefender, 339, 0);
                if (nAvoid > 0)
                {
                    const int nRand = SEED_RollLimitedRandomNumber(&pDefender->pSeed, 100);
                    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nAvoid, nRand, "avoids");
                    if (nRand < nAvoid)
                    {
                        return 2;
                    }
                }
            }
        }
        else
        {
            const int nEvade = STATLIST_UnitGetStatValue(pDefender, 340, 0);
            if (nEvade > 0)
            {
                const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nEvade, nRand, "evades");
                if (nRand < nEvade)
                {
                    nResult = 8;
                }
            }
            return nResult;
        }
    }

    return 0;
}

// 0x0057DFB0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock)
{
    if (!bBlock) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    int nBlockChance = UNITS_GetBlockRate(pDefender, pGame->bExpansion);
    if (nBlockChance <= 0) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    if (pDefender && pDefender->dwUnitType == 0 && UNITS_IsInMovingMode(pDefender) && pDefender->dwAnimMode != 2)
        nBlockChance /= 3;
    unsigned __int64 nSeed = pDefender->pSeed.nHighSeed + 0x6AC690C5ui64 * pDefender->pSeed.nLowSeed;
    pDefender->pSeed.nHighSeed = (unsigned int)(nSeed >> 32);
    pDefender->pSeed.nLowSeed = (unsigned int)nSeed;
    const int nRand = (unsigned int)nSeed % 100;
    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nBlockChance, nRand, "blocks");
    if (nRand >= nBlockChance) return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    return 1;
}

// 0x0057E090
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, DAMAGECALLBACK pfCallback, int a10)
{
    D2DamageStrc damage;
    D2UnitFindArgStrc unitFindArg;
    D2UnitFindDataStrc unitFindData;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOwnerOwner;
    int nFlags;
    int i;
    int bResult;

    bResult = 0;
    pRoom = UNITS_GetRoom(pUnit);
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);

    nFlags = a10;
    if (!a10)
    {
        nFlags = 0x583;
    }

    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nFlags = nFlags;
    unitFindArg.nSize = nSize;
    unitFindArg.nY = nY;
    unitFindArg.nX = nX;

    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    pOwner = SUNIT_GetOwner(pGame, pUnit);
    pOwnerOwner = pOwner ? SUNIT_GetOwner(pGame, pOwner) : 0;
    if (!pOwner)
    {
        UNITFINDS_FreeUnitFindData(&unitFindData);
        return 0;
    }

    for (i = 0; i < unitFindData.nIndex; ++i)
    {
        if ((pOwnerOwner != unitFindData.pUnitsArray[i] || a8) && (pOwner != unitFindData.pUnitsArray[i] || a7)
            && SUNIT_AreUnitsHostile(pGame, pOwner, unitFindData.pUnitsArray[i])
            && D2Common_11026(nX, nY, unitFindData.pUnitsArray[i], 0x805))
        {
            damage = *pDamage;
            if (pfCallback)
            {
                D2_ASSERT(!IsBadCodePtr(pfCallback), 0xDA6);

                if (pfCallback(pGame, pUnit, unitFindData.pUnitsArray[i]))
                {
                    MISSMODE_SetDamageFlags(pGame, pUnit, unitFindData.pUnitsArray[i], &damage);
                    bResult = 1;
                }
            }
            else
            {
                MISSMODE_SetDamageFlags(pGame, pUnit, unitFindData.pUnitsArray[i], &damage);
                bResult = 1;
            }
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
    return bResult;
}
