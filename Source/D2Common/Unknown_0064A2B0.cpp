#include "D2StatIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Skills.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2MissileDataStrc;
struct D2MissilesTxt;

struct D2MissileDataStrc
{
    unsigned int unk0x00;
    short nStreamMissile;
    short nStreamRange;
    short nActivateFrame;
    short nSkill;
    short nLevel;
    short nTotalFrames;
    short nCurrentFrame;
    unsigned short unk0x12;
    unsigned int fFlags;
    int nOwnerType;
    int dwOwnerGUID;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
static int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit);
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0


extern void* gpfnMissileCalcFunctions[]; // 0x00745828
extern int gnMissileCalcFunctionCount; // 0x00745848
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData); // 0x0064B6E0

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit) return 6;
    return pUnit->dwUnitType;
}

static inline unsigned int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0xFFFFFFFFu;
    return pUnit->dwUnitId;
}

// 0x0064A5F0
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nActivateFrame = D2_MIN(D2_MAX(nActivateFrame, -32768), 32767);
        pMissile->pMissileData->nActivateFrame = nActivateFrame;
    }
}

// 0x0064A690
void __stdcall MISSILE_SetAnimSpeed(D2UnitStrc* pMissile, int nAnimSpeed)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        pMissile->wAnimSpeed = D2_MIN(D2_MAX(nAnimSpeed, -32768), 32767);
    }
}

// 0x0064ABA0
static int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit)
{
    int nMastery;
    switch (nElement)
    {
    case 1:
        nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 2:
        nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 4:
    case 12:
        nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 5:
        nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    }
    return 0;
}

void __fastcall sub_0064ABA0_EmitAddMasteryBonus(int* pMinMax, int nElement, D2UnitStrc* pUnit)
{
    pMinMax[0] += sub_0064ABA0_GetElementMasteryBonus(pMinMax[0], nElement, pUnit);
    pMinMax[1] += sub_0064ABA0_GetElementMasteryBonus(pMinMax[1], nElement, pUnit);
}

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}


#include "gen/data/Source/D2Common/Unknown_0064A2B0.inc"
