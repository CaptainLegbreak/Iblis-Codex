#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_LEVEL 12
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonStatsInitStrc;
struct D2MonsterDataStrc;
struct Unit005A4EE0;
struct StatValue;




struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x06];
    int dwGameType;
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0x122];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

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
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
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
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag); // 0x005A0180

struct Unit005A4EE0 { int nType; };

struct StatValue { int value; };

enum { RANGE_OVERRIDE = 0 };

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
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

// 0x005A3EF0
void __fastcall MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordFromUnit(pUnit);
    const int nDifficulty = pGame->nDifficulty;
    const int nColdLength = pMonStatsTxtRecord->wAiParam[0][nDifficulty];

    int nGameType;
    if (pGame->nGameType || pGame->dwGameType)
    {
        nGameType = 1;
    }
    else
    {
        nGameType = 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(!pUnit ? -1 : pUnit->dwClassId, nGameType, nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 8, &monStatsInit);

    const int nDamage = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, monStatsInit.nA1MaxD - monStatsInit.nA1MinD) + monStatsInit.nA1MinD) << 8;

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 8;
    damage.dwPhysDamage = nDamage;

    D2UnitStrc* pMissile;
    if (nColdLength == 1)
    {
        damage.dwFireDamage = nDamage;
        pMissile = sub_6FD11420(pGame, MISSILE_SUICIDEFIREEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }
    else if (nColdLength >= 2)
    {
        damage.dwColdDamage = nDamage;
        damage.dwColdLen = nColdLength;
        pMissile = sub_6FD11420(pGame, MISSILE_SUICIDEICEEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, MISSILE_SUICIDECORPSEEXPLODE, pUnit, 0, 1, 0, 0, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1);
    }

    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    if (pMissile)
    {
        SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, pMonStatsTxtRecord->wAiParam[3][pGame->nDifficulty], &damage, 0, 0, 0, 0x581);
    }
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

// 0x005A4350
void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 0, pUnit);
}

// 0x005A4360
void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 1, pUnit);
}

void __fastcall sub_005A4370(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 2, pUnit);
}

// 0x005A4390
void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 3, pUnit);
}

// 0x005A43A0
void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_005A4270_ExecuteUModCallbacks(pGame, 0, 4, pUnit);
}

// 0x005A43B0
void __fastcall sub_005A43B0_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pUnit->dwUnitType == 1 && pMissile)
    {
        sub_005A4270_ExecuteUModCallbacks(pGame, pMissile, 5, pUnit);
    }
}

// 0x005A4EE0
extern "C" __declspec(dllexport) int __fastcall sub_005A4EE0(Unit005A4EE0* pUnit) {
    if (pUnit) {
        int nType = pUnit->nType;
        if (nType == 1) {
            return nType;
        }
    }
    return 0;
}

// 0x005A5470
unsigned short __fastcall sub_005A5470(Game* game,Unit* attacker,Unit* defender,StatValue stat,int ignoredRange)
{
    return sub_0057EC10(game,attacker,defender,stat.value,RANGE_OVERRIDE);
}
