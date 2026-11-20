#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define EVENTTYPE_MONUMOD 7
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;






struct D2MonStatsTxt
{
    char unk0x000[0x62];
    short wAiParam3[3];
    char unk0x068[0xA6];
    short nElMinD;
    char unk0x110[0x10];
    short nElMaxD;
    char unk0x122[0x1A8 - 0x122];
};


struct D2DamageStrc
{
    char unk0x00[0x10];
    int dwFireDamage;
    char unk0x14[0x5C];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090

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

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nX;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nY;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005A3D20
void __fastcall MONSTERUNIQUE_ApplyCorpseFireDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit);
    const int nFireDamage = (ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonStatsTxtRecord->nElMaxD - pMonStatsTxtRecord->nElMinD) + pMonStatsTxtRecord->nElMinD) << 8;
    const int nSize = pMonStatsTxtRecord->wAiParam3[pGame->nDifficulty] * STATLIST_UnitGetStatValue(pUnit, 12, 0);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFireDamage = nFireDamage;

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pUnit, nX, nY, nSize, &damage, 0, 0, 0, 0);
}

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
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == 1) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nUMods;
}

// build: context MONSTERUNIQUE_CheckMonTypeFlag
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == 1) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

// 0x005A4270
static void __stdcall MONSTERUNIQUE_ExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pMissile, int nCallbackIndex, D2UnitStrc* pUnit)
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
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 0, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 1, pUnit);
}

// 0x005A4370
void __fastcall sub_005A4370(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 2, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 3, pUnit);
}

void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 4, pUnit);
}

void __fastcall sub_005A43B0_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pUnit->dwUnitType == 1 && pMissile)
    {
        MONSTERUNIQUE_ExecuteUModCallbacks(pGame, pMissile, 5, pUnit);
    }
}
