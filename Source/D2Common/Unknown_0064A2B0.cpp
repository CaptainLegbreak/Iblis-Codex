#include "D2StatIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2MissileDataStrc;
struct D2MissilesTxt;
struct D2MissileCalcStrc;

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
static __declspec(noinline) int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit);
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    int nMissileId;
    int nMissileLevel;
};

extern void* gpMissileCalcFunctions_00745828[]; // 0x00745828
extern int gnMissileCalcFunctions_00745848; // 0x00745848
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData); // 0x0064B6E0

// 0x0064A2B0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nTotalFrames = D2_MIN(D2_MAX(nTotalFrames, -32768), 32767);
        pMissile->pMissileData->nTotalFrames = nTotalFrames;
    }
}

// 0x0064A330
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nCurrentFrame = D2_MIN(D2_MAX(nCurrentFrame, -32768), 32767);
        pMissile->pMissileData->nCurrentFrame = nCurrentFrame;
    }
}

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit) return 6;
    return pUnit->dwUnitType;
}

static __forceinline unsigned int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0xFFFFFFFFu;
    return pUnit->dwUnitId;
}

// 0x0064A470
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pMissile && pUnit && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pData = pMissile->pMissileData;
            if (pData && pData->nOwnerType == GetUnitType(pUnit) && pData->dwOwnerGUID == GetUnitId(pUnit))
            {
                return 1;
            }
        }
    }

    return 0;
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

// 0x0064B340
int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel)
{
    int nResult;
    {
    if (pMissile && pMissile->dwUnitType != UNIT_MISSILE)
    {
        nResult = 0;
        goto Done;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (!pMissilesTxtRecord)
    {
        nResult = 0;
        goto Done;
    }

    switch (nParamId)
    {
    case 0: nResult = pMissilesTxtRecord->dwParam[0];
    goto Done;
    case 1: nResult = pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 2: nResult = pMissilesTxtRecord->dwParam[2];
    goto Done;
    case 3: nResult = pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 4: nResult = pMissilesTxtRecord->dwParam[4];
    goto Done;
    case 5: nResult = pMissilesTxtRecord->dwCltParam[0];
    goto Done;
    case 6: nResult = pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 7: nResult = pMissilesTxtRecord->dwCltParam[2];
    goto Done;
    case 8: nResult = pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 9: nResult = pMissilesTxtRecord->dwCltParam[4];
    goto Done;
    case 10: nResult = pMissilesTxtRecord->dwHitPar[0];
    goto Done;
    case 11: nResult = pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 12: nResult = pMissilesTxtRecord->dwHitPar[2];
    goto Done;
    case 13: nResult = pMissilesTxtRecord->dwCltHitPar[0];
    goto Done;
    case 14: nResult = pMissilesTxtRecord->dwCltHitPar[1];
    goto Done;
    case 15: nResult = pMissilesTxtRecord->dwCltHitPar[2];
    goto Done;
    case 16: nResult = pMissilesTxtRecord->dwDmgParam[0];
    goto Done;
    case 17: nResult = pMissilesTxtRecord->dwDmgParam[1];
    goto Done;
    case 18: nResult = nLevel;
    goto Done;
    case 19: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 20: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 21: nResult = sub_0064B2A0_GetMissileElementLength(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 22: nResult = MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 23: nResult = MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 24: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 25: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel) >> 8;
    goto Done;
    case 26: nResult = MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 27: nResult = MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel);
    goto Done;
    case 28: nResult = pMissilesTxtRecord->wLevRange * nLevel + pMissilesTxtRecord->wRange;
    goto Done;
    case 29: nResult = pMissilesTxtRecord->dwParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwParam[1];
    goto Done;
    case 30: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[1]);
    goto Done;
    case 31: nResult = pMissilesTxtRecord->dwParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwParam[3];
    goto Done;
    case 32: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwParam[2], pMissilesTxtRecord->dwParam[3]);
    goto Done;
    case 33: nResult = pMissilesTxtRecord->dwCltParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[1];
    goto Done;
    case 34: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1]);
    goto Done;
    case 35: nResult = pMissilesTxtRecord->dwCltParam[2] + (nLevel - 1) * pMissilesTxtRecord->dwCltParam[3];
    goto Done;
    case 36: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[3]);
    goto Done;
    case 37: nResult = pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];
    goto Done;
    case 38: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1]);
    goto Done;
    case 39: nResult = pMissilesTxtRecord->dwCltHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];
    goto Done;
    case 40: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);
    goto Done;
    case 41: nResult = pMissilesTxtRecord->dwDmgParam[0] + (nLevel - 1) * pMissilesTxtRecord->dwDmgParam[1];
    goto Done;
    case 42: nResult = D2Common_11033(nLevel, pMissilesTxtRecord->dwDmgParam[0], pMissilesTxtRecord->dwDmgParam[1]);
    goto Done;
    }

    nResult = 0;
    }
Done:
    return nResult;
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

// build: context MISSILE_GetLevel
static unsigned int MISSILE_GetLevel(D2UnitStrc* pMissile)
{
    D2MissileDataStrc* pMissileData = sub_0044BE50(pMissile) == 3 ? pMissile->pMissileData : 0;
    if (!pMissileData)
    {
        return 0;
    }

    return pMissileData->nLevel;
}

// 0x0064B7C0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel)
{
    D2MissileCalcStrc pMissileCalc;
    if (pMissile)
    {
        const int nType = sub_0044BE50(pMissile);
        if (nType != 3)
        {
            return 0;
        }

        if (nMissileId < 0)
        {
            nMissileId = pMissile->dwClassId;
        }

        if (nLevel < 0)
        {
            nLevel = MISSILE_GetLevel(pMissile);
        }
    }

    if (!sgptDataTables->pMissCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nMissCodeSize)
    {
        return 0;
    }

    pMissileCalc.pMissile = pMissile;
    pMissileCalc.pOwner = pOwner;
    pMissileCalc.nMissileId = nMissileId;
    pMissileCalc.nMissileLevel = nLevel;

    return DATATBLS_CalcEvaluateExpression((char*)sgptDataTables->pMissCode + nCalc, sgptDataTables->nMissCodeSize - nCalc, MISSILE_GetCalcParamValue, gpMissileCalcFunctions_00745828, gnMissileCalcFunctions_00745848, &pMissileCalc);
}

#include "gen/data/Source/D2Common/Unknown_0064A2B0.inc"
