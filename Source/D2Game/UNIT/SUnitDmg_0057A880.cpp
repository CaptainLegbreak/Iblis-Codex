#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#define STAT_ITEM_UNDEADDAMAGE_PERCENT 122
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_DAMAGE_VS_MONTYPE 180
#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define OBJMODE_OPENED 2
#define MONSTATSFLAGINDEX_KILLABLE 15
#define MONSTATS2FLAGINDEX_OBJCOL 18
#define MONSTER_BARRICADEDOOR1 432
#define MONSTER_BARRICADEDOOR2 433
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2DifficultyLevelsTxt;
struct D2SkillsTxt;
struct D2ModeChangeStrc;
struct D2DamageHitClassMappingStrc;



struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    char unk0x1C[0x0C];
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
    unsigned char unk_65[0x3];
};

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0


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


typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
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
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30
void __fastcall sub_6FCF8DD0(D2UnitStrc* pUnit); // 0x005D6410
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, unsigned int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x00625310
int __stdcall STATLIST_GetExpireFrame(D2StatListStrc* pStatList); // 0x00625330
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



struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char nDirection;
    unsigned char unk0x15;
    unsigned char unk0x16;
    unsigned char unk0x17;
    int unk0x18;
    int unk0x1C;
};

extern "C" const D2DamageHitClassMappingStrc gsDamageHitClassMapping_006E16D8[8]; // 0x006E16D8
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A54F0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
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
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
// 0x0057CE30
static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass); // 0x0057CE30
// 0x0057CEC0
static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage); // 0x0057CEC0


void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall sub_6FC7D470(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x005751A0
void __fastcall sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame); // 0x005A4EF0
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0053F720
void __stdcall sub_0066A220_Stub(D2UnitStrc* pPlayer, int nMonsterId); // 0x0066A220
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker); // 0x00543A30
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20

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

// calling-convention shim (not game code)
void __stdcall sub_A08_EmitDamageHelpers(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a, int b, int c, int d, int e, int f)
{
    pDamage->dwPhysDamage = sub_0057A8E0_AddStatDamage(a, b, c, d, pDamage->dwPhysDamage, f, pAttacker);
    pDamage->dwFireDamage = sub_0057A8E0_AddStatDamage(b, c, d, e, pDamage->dwFireDamage, a, pAttacker);
    pDamage->dwEnDmgPct = sub_0057A880_AddRolledDamage(pAttacker, a, b, c, pDamage->dwEnDmgPct, d);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pAttacker, pDefender);
    sub_0057B660_AddUndeadDamagePercent(pDamage, pDefender, pAttacker);
}

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

// build: context SUNITDMG_ExecuteMissileDamage
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

// 0x0057CEA0
static __forceinline void sub_0057CEA0_ApplyHitClass(D2DamageStrc* pDamage, D2UnitStrc* pAttacker)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF))
    {
        pDamage->dwHitClass |= UNITS_GetHitClass(pAttacker);
    }
}

void __fastcall sub_M109_Emit_0057CEA0(D2UnitStrc* pAttacker, D2DamageStrc* pDamage)
{
    sub_0057CEA0_ApplyHitClass(pDamage, pAttacker);
    UNITS_GetHitClass((D2UnitStrc*)pDamage);
}
