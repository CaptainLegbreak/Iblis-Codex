#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#define UNIT_MONSTER 1

#define MONTYPEFLAG_CHAMPION 4

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0

void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530

void __fastcall sub_0046B680_SpawnMissileTrio(D2UnitStrc* pUnit);                                           // 0x0046B680

void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall sub_0046B850_SpawnMissileAtObject182(D2UnitStrc* pUnit);                                                            // 0x0046B850

void __fastcall sub_0046B9A0_SpawnMissileTrio2(D2UnitStrc* pUnit);                                          // 0x0046B9A0

void __fastcall sub_0046BA50_SpawnMissile(D2UnitStrc* pUnit);                                               // 0x0046BA50

void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90

void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10

void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90

void __fastcall sub_0046BC10_HintAndMissile(D2UnitStrc* pUnit);                                             // 0x0046BC10

int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70

void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

static inline unsigned __int64 SEED_RollLocalSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004ACC70
void __fastcall sub_004ACC70_InitMonsterLight(D2UnitStrc* pUnit, int nUnused, int bInit)
{
    if (!bInit)
    {
        return;
    }

    sub_00464930_FreeLight(pUnit);

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
        pLight = sub_00474160_MakeLightEntry(pUnit, 0, 7, 0xFF, nRed, nGreen, nBlue);
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }

        pLight = sub_00474160_MakeLightEntry(pUnit, 0, 7, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, sub_00474350_GetLightSize(pLight));
}

// 0x004AD2F0
void __fastcall sub_004AD2F0_UnitClassEvent(D2UnitStrc* pUnit, int nUnused, int nUnused2)
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
            sub_0046BA50_SpawnMissile(pUnit);
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
            sub_0046B9A0_SpawnMissileTrio2(pUnit);
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
            sub_0046BC10_HintAndMissile(pUnit);
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
            sub_0046B680_SpawnMissileTrio(pUnit);
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
