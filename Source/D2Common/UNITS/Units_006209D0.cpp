#include "D2Common.h"
#include "D2Structs.h"
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define COLLIDE_WALL 0x1
#define COLLIDE_MISSILE_BARRIER 0x4
#define COLLIDE_ITEM 0x200
#define COLLIDE_OBJECT 0x400
#define COLLIDE_MASK_DOOR_BLOCK_VIS 0x806
#define OBJSUBCLASS_TOWNPORTAL 0x4
#define STAT_TOHIT 0x13
#define STAT_DEXTERITY 0x2
#define STAT_HITPOINTS 0x6
#define STAT_MANA 0x8
#define STAT_LEVEL 0xC
#define DEX_BASE 7
#define DEX_MUL 5
struct D2MonStats2Txt;
struct D2ObjectsTxt;
struct D2ObjectDataStrc;
struct D2CharStatsTxt;

struct D2MonStats2Txt
{
    char unk0x00[12];
    unsigned char nOverlayHeight;
};

struct D2ObjectsTxt
{
    char unk0x00[314];
    unsigned char nIsDoor;
    unsigned char nBlocksVis;
    char unk0x13C[43];
    unsigned char nSubClass;
    char unk0x168[78];
    unsigned char nBlockMissile;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};

struct D2CharStatsTxt
{
    char unk0x00[60];
    int dwToHitFactor;
    char unk0x40[132];
};

struct D2DataTablesStrc
{
    char unk0x00[3012];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath); // 0x00648C10
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

// 0x006209D0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2062);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
        if (pUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            if (pUnit->pObjectData->pObjectTxt->nBlocksVis)
            {
                return COLLIDE_MASK_DOOR_BLOCK_VIS;
            }
            else if (pUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_DOOR | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }
        else
        {
            if (pUnit->pObjectData->pObjectTxt->nSubClass & OBJSUBCLASS_TOWNPORTAL)
            {
                return COLLIDE_CORPSE;
            }
            else if (pUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_OBJECT | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }

    case UNIT_ITEM:
        return COLLIDE_ITEM;

    case UNIT_TILE:
        return COLLIDE_WALL;

    default:
        return PATH_GetFootprintCollisionMask(pUnit->pDynamicPath);
    }
}

// 0x006223A0
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit)
{
    switch (!pUnit ? UNIT_INVALID : pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return 1;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return 0;
        }

        return pMonStats2TxtRecord->nOverlayHeight - 1;
    }
    }

    return 0;
}

// 0x00622DE0
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit)
{
    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);

    unsigned int nShiftedLifeDifference = 0;
    unsigned int nShiftedManaDifference = 0;

    if (nMaxLife > nLife)
    {
        nShiftedLifeDifference = (nMaxLife - nLife) >> 8;
    }

    if (nMaxMana > nMana)
    {
        nShiftedManaDifference = (nMaxMana - nMana) >> 8;
    }

    if (nShiftedLifeDifference || nShiftedManaDifference)
    {
        return (nShiftedLifeDifference + nShiftedManaDifference) * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) >> 2;
    }

    return 0;
}

// 0x006217C0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3457);

    if (pUnit->pAnimSeq)
    {
        return pUnit->dwFrameCountPrecise <= 0;
    }
    else
    {
        return pUnit->nSeqCurrentFramePrecise + pUnit->wAnimSpeed >= pUnit->dwFrameCountPrecise;
    }
}
