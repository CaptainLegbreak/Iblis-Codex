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

// 0x004ACD70
void __fastcall MONUNIQUE_AssignTeleportSkill(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, SKILL_MONTELEPORT, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
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

// 0x004AD2F0
void __fastcall MONUNIQUE_HandleUnitClassEvent(D2UnitStrc* pUnit, int nUnused, int nUnused2)
{
    if (!pUnit)
    {
        return;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x9C:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnAndarielDeath(pUnit);
        }
        break;

    case 0x2D:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B710_SpawnMissileAtObject173(pUnit);
        }
        break;

    case 0xE5:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BA90_PlayerRequestAtUnit15B(pUnit);
        }
        break;

    case 0xD3:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BB90_PlayerRequestAtUnit16B(pUnit);
        }
        break;

    case 0xF2:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMephistoDeath(pUnit);
        }
        break;

    case 0xF3:
        if (pUnit->dwAnimMode == 0)
        {
            UI_SetTimerUnitId(pUnit);
        }
        break;

    case 0x100:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnIzualDeath(pUnit);
        }
        break;

    case 0x16E:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B850_SpawnMissileAtObject182(pUnit);
        }
        break;

    case 0x11C:
        if (pUnit->dwAnimMode == 0x0E)
        {
            sub_0046BB10_PlayerRequestAtUnit161(pUnit);
        }
        break;

    case 0x10B:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnBrDeathControl(pUnit);
        }
        break;

    case 0x1DF:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B3C0_UnitRequest25A(pUnit);
        }
        break;

    case 0x220:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BC90_RequestAtMonster220(pUnit);
        }
        break;

    case 0x21C:
    case 0x21D:
    case 0x21E:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B530_SpawnMissileAtObject(pUnit);
        }
        break;
    }
}

#include "gen/data/Source/D2Client/UNIT/MonUnique.inc"
