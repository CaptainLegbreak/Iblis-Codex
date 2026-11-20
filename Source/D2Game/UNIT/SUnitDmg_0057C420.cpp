#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2DifficultyLevelsTxt;



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
    char unk0x0C[0x08];
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
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057AD80
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30
void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0057B170
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4390
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30
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
static __declspec(noinline) void __stdcall SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, int nFreezeLength, D2UnitStrc* pDefender);
static __declspec(noinline) void __stdcall sub_0057C420_ApplyLeech(D2UnitStrc* pDefender, D2UnitStrc* pAttacker, D2GameStrc* pGame, D2DamageStrc* pDamage);

// build: context sub_I19_RollSeedInline
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

// 0x0057B230
static void __stdcall SUNITDMG_ApplyFreezeState(D2UnitStrc* pAttacker, int nFreezeLength, D2UnitStrc* pDefender)
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

    if ((!pDefender ? 6 : pDefender->dwUnitType) == 1)
    {
        const unsigned char v_nDifficulty_544 = pGame->nDifficulty;
        const int nFreezeDivisor = DATATBLS_GetDifficultyLevelsTxtRecord(v_nDifficulty_544)->dwMonsterFreezeDiv;
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

// build: context SUNITDMG_GetMonStatsTxtRecordFromUnit
static __forceinline D2MonStatsTxt* SUNITDMG_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonstatsTxt;
    }

    return 0;
}

// build: context sub_0057C420_GetConvertedUnitType
static __forceinline int sub_0057C420_GetConvertedUnitType(D2UnitStrc* pAttacker)
{
    const int nTypeValue = !pAttacker ? 6 : pAttacker->dwUnitType;
    int nUnitType = nTypeValue;
    const int nClassValue = !pAttacker ? -1 : pAttacker->dwClassId;
    int nClassId = nClassValue;
    const int nModeValue = !pAttacker ? 0 : pAttacker->dwAnimMode;
    int nAnimMode = nModeValue;
    D2COMMON_11013_ConvertMode(pAttacker, &nUnitType, &nClassId, &nAnimMode, ".\\UNIT\\SUnitDmg.cpp", 0x64C);
    return nUnitType;
}

// 0x0057C420
static void __stdcall sub_0057C420_ApplyLeech(D2UnitStrc* pDefender, D2UnitStrc* pAttacker, D2GameStrc* pGame, D2DamageStrc* pDamage)
{
    if (!pDamage->dwLifeLeech && !pDamage->dwManaLeech)
    {
        return;
    }

    int nDrain;
    const int nDefenderType = pDefender ? pDefender->dwUnitType : 6;
    if (nDefenderType != 1)
    {
        nDrain = 100;
    }
    else
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SUNITDMG_GetMonStatsTxtRecordFromUnit(pDefender);
        if (!pMonStatsTxtRecord)
        {
            return;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return;
        }
    }

    pDamage->dwLifeLeech *= 64;
    pDamage->dwManaLeech *= 64;

    if (pAttacker && pAttacker->dwUnitType == 0)
    {
        D2GameStrc* pAttackerGame = SUNIT_GetGameFromUnit(pAttacker);
        D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pAttackerGame->nDifficulty);
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
        if (sub_0057C420_GetConvertedUnitType(pAttacker))
        {
            const int nMana = STATLIST_UnitGetStatValue(pDefender, 8, 0);
            const int nStamina = STATLIST_UnitGetStatValue(pDefender, 10, 0);
            pDamage->dwLifeLeech /= 64;
            pDamage->dwManaLeech /= 64;
            int nTotalLeech = 0;
            nTotalLeech += ((pDamage->dwLifeLeech < pDamage->dwPhysDamage) ? pDamage->dwLifeLeech : pDamage->dwPhysDamage);
            nTotalLeech += ((pDamage->dwManaLeech < nMana) ? pDamage->dwManaLeech : nMana);
            nTotalLeech += ((pDamage->dwStamLeech < nStamina) ? pDamage->dwStamLeech : nStamina);
            if (nTotalLeech)
            {
                if (nDrain != 100)
                {
                    nTotalLeech = DATATBLS_ApplyRatio(nTotalLeech, nDrain, 100);
                }

                const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
                const int nHp = STATLIST_UnitGetStatValue(pAttacker, 6, 0);
                nTotalLeech = (nTotalLeech < nMaxHp - nHp) ? nTotalLeech : nMaxHp - nHp;
                if (nTotalLeech > 0)
                {
                    STATLIST_AddUnitStat(pAttacker, 6, nTotalLeech, 0);
                    UNITS_SetOverlay(pAttacker, 0x97, 0);
                }
            }
            return;
        }
    }

    int bManaLeeched = 0;
    const int nPhysDamage = pDamage->dwPhysDamage;
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
            if (!SEED_RollLimitedRandomNumber(&pAttacker->pSeed, 2))
            {
                UNITS_SetOverlay(pAttacker, 0x97, 0);
            }
            else
            {
                UNITS_SetOverlay(pAttacker, 0x98, 0);
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

// 0x0057C6C0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage)
{
    if (!sub_00554200(pGame, pAttacker, pDefender) && !(pDamage->dwHitFlags & 0x1000))
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

    sub_0057C420_ApplyLeech(pDefender, pAttacker, pGame, pDamage);

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
