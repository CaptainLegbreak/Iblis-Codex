#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2SkillIds.h"

#define UNIT_MONSTER 1

#define MONTYPEFLAG_CHAMPION 4

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0

void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530

void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit);                                           // 0x0046B680

void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall sub_0046B850_SpawnMissileAtObject182(D2UnitStrc* pUnit);                                                            // 0x0046B850

void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit);                                          // 0x0046B9A0

void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit);                                               // 0x0046BA50

void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90

void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10

void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90

void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit);                                             // 0x0046BC10

int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70

void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

typedef void (__fastcall* UMODCALLBACK)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern const int gaUModList[4];                                                                     // 0x006DA4C8

extern UMODCALLBACK gpfnUModCallbacks[];                                                            // 0x00724D78

static inline unsigned __int64 SEED_RollLocalSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

// 0x004ACC70
void __fastcall MONUNIQUE_InitUModLight(D2UnitStrc* pUnit, int nUnused, int bInit)
{
    if (!bInit)
    {
        return;
    }

    CUNIT_FreeLight(pUnit);

    D2GfxLightStrc* pLight;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        D2SeedStrc seed;
        seed.nHighSeed = (unsigned int)(lSeed >> 32);
        seed.nLowSeed = (unsigned int)lSeed;
        const int nBlue = (int)lSeed;
        const int nGreen = (int)SEED_RollLocalSeed(&seed);
        const int nRed = (int)SEED_RollLocalSeed(&seed);
        pUnit->pSeed = seed;
        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, nRed, nGreen, nBlue);
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }

        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, DLIGHTMAP_GetLightSize(pLight));
}

// 0x004ACD50
void __fastcall sub_004ACD50_ClearMonsterField18(D2UnitStrc* unit, void* unused, int unusedStack)
{
    if (GetUnitType(unit) == 1)
    {
        D2MonsterDataStrc* data = unit->pMonsterData;
        if (data)
            data->dwDurielFlag = 0;
    }
}


// 0x004ACD70
void __fastcall MONUNIQUE_AssignTeleportSkill(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, SKILL_MONTELEPORT, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
    }
}

// 0x004ACDB0
int __fastcall sub_004ACDB0_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0);
            STATLIST_SetUnitStat(pUnit, STAT_ARMORCLASS, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, STAT_FIRERESIST, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTRESIST, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, STAT_COLDRESIST, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, STAT_POISONRESIST, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAGICRESIST, 0);

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
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, nDamageResist + 50, 0);
        }
    }
}

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

// build: context MONSTERS_CheckMonTypeFlag
static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

// 0x004AD020
void __fastcall MONUNIQUE_ApplyUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
    {
        unsigned char* pUMods = pMonsterData->nMonUmod;
        if (pUMods && *pUMods)
        {
        const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);

        for (int j = 0; j < 4; ++j)
        {
            const int nUMod = gaUModList[j];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }

        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }
        }
    }
}


#include "gen/data/Source/D2Client/UNIT/MonUnique.inc"
