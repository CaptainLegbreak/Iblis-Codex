#include "D2MissileIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_LEVEL 12
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonStatsInitStrc;
struct D2MonsterDataStrc;
struct Unit005A4EE0;
struct StatValue;

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

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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
