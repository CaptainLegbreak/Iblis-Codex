#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define EVENTTYPE_MONUMOD 7
struct D2MonsterDataStrc;
union D2SeedStrc;
struct D2MonStatsTxt;


struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned char nTypeFlag;
    char unk0x17[5];
    unsigned char nUMods[9];
};



typedef void(__fastcall* MONUMODFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

extern MONUMODFUNC gpfUModCallbacks_0073C0B8[][6]; // 0x0073C0B8
D2UnitStrc* __fastcall sub_6FC6A150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag); // 0x005A0180




enum D2C_J10MonModeConstants
{
    HITCLASS_CRITICAL = 0x10,
    OVERLAY_CRITICAL = 54,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall SUNITDMG_SetHitClass(D2DamageStrc* pDamage, unsigned int nHitClass); // 0x00554650
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

void __fastcall MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);
void __fastcall sub_6FC6E730(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

// 0x005A4200
void __fastcall MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        sub_6FC6A150(pGame, pUnit, MONSTER_PAINWORM1, MONMODE_NEUTRAL, 1, 0);
        STATES_ToggleState(pUnit, STATE_CORPSE_NODRAW, 1);
    }
}

// 0x005A4230
void __fastcall sub_6FC6E730(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 75, 0, 0);
}

// 0x005A0120
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nUMods;
}

// build: context MONSTERUNIQUE_CheckMonTypeFlag
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

// 0x005A4270
static void __stdcall sub_005A4270_ExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pMissile, int nCallbackIndex, D2UnitStrc* pUnit)
{
    const int bUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x08);

    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods || *pUMods == 0)
    {
        return;
    }

    if (nCallbackIndex != 5)
    {
        for (int i = 0; i < 9; ++i)
        {
            MONUMODFUNC pUModFunc = gpfUModCallbacks_0073C0B8[pUMods[i]][nCallbackIndex];
            if (pUModFunc)
            {
                pUModFunc(pGame, pUnit, pUMods[i], bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            MONUMODFUNC pUModFunc = gpfUModCallbacks_0073C0B8[pUMods[i]][nCallbackIndex];
            if (pUModFunc)
            {
                pUModFunc(pGame, pMissile, pUMods[i], bUnique);
            }
        }
    }
}

void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 0, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 1, pUnit);
}

// 0x005A4370
void __fastcall sub_005A4370(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 2, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 3, pUnit);
}

void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 4, pUnit);
}

void __fastcall sub_005A43B0_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pMissile)
    {
        sub_005A4270_ExecuteUModCallbacks(pGame, pMissile, 5, pUnit);
    }
}

#include "gen/data/Source/D2Game/Unknown_005A4200.inc"

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005A5560
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nCrit && (unsigned char)(SEED_RollRandomNumber(&pAttacker->pSeed) % 100) < pMonStatsTxtRecord->nCrit)
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->dwFireDamage *= 2;
            pDamage->dwLtngDamage *= 2;
            pDamage->dwMagDamage *= 2;
            pDamage->dwColdDamage *= 2;
            pDamage->dwPoisDamage *= 2;

            if (pDefender && !SUNITDMG_SetHitClass(pDamage, HITCLASS_CRITICAL))
            {
                UNITS_SetOverlay(pDefender, OVERLAY_CRITICAL, 0);
            }
        }
    }
}
