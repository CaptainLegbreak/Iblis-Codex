#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D2D70(D2UnitStrc* pMissile, int nArg1, int nArg2); // 0x004D2D70
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

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

// build: context SEED_RollRandomNumber
// build: context SEED_RollLimitedRandomNumber
// build: context SKILLS_GetMissilesTxtRecord
inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004D0B90
static void __stdcall sub_004D0B90_SpawnHitBurst(int nCount, int nVelocity, int nGate, int nRingMissile, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    D2MissileStrc tParams;
    if (nGate >= 0)
    {
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x524;
        tParams.pOwner = pOwner;
        tParams.pOrigin = pMissile;
        tParams.nMissile = 0x1C8;
        tParams.nVelocity = nVelocity;
        tParams.nSkill = nSkill;
        tParams.nSkillLevel = nLevel;
        const int nSpread = 2 * nCount;
        for (int i = 0; i < nCount; ++i)
        {
            const int nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nX;
            const int nTargetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nY;
            if (UNITS_GetDistanceToCoordinates(pMissile, nTargetX, nTargetY) > 3)
            {
                tParams.nTargetX = nTargetX;
                tParams.nTargetY = nTargetY;
                sub_004CD540_CreateMissile(&tParams);
            }
        }
    }
    if (nRingMissile >= 0)
    {
        for (int i = 0; i < 18; ++i)
        {
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 1;
            tParams.pOwner = pOwner;
            tParams.nX = gaHitRingX_006DB540[i] + nX;
            tParams.nY = gaHitRingY_006DB588[i] + nY;
            tParams.nSkill = nSkill;
            tParams.nSkillLevel = nLevel;
            tParams.nMissile = nRingMissile;
            sub_004CD540_CreateMissile(&tParams);
        }
    }
}

// 0x004D0DB0
int __fastcall sub_004D0DB0_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[0], pMissilesTxtRecord->wCltHitSubMissile[1], pMissile);
    return 1;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return SKILLS_GetMissilesTxtRecordChecked(pUnit->dwClassId);
}

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x004D6130
void __fastcall sub_004D6130_CltDoRandomSubMissile3(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCount = 0;
    do
    {
        if (pMissilesTxtRecord->wCltSubMissile[nCount] < 0 || pMissilesTxtRecord->dwCltParam[nCount + 1] <= 0)
        {
            break;
        }

        ++nCount;
    }
    while (nCount < 3);

    if (nCount <= 0)
    {
        sub_004D2D70(pMissile, 0, 0);
        return;
    }

    if (nFrames < pMissilesTxtRecord->dwCltParam[0])
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    SEED_InitLowSeed(&pMissile->pSeed, UNITS_GetXPositionForceInl(pMissile));

    const int nIndex = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, nCount);
    if (nFrames % pMissilesTxtRecord->dwCltParam[nIndex + 1])
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2MissileStrc tMissile = {};
    tMissile.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[nIndex];
    tMissile.nSkillLevel = nSkillLevel;

    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
    if (pNew)
    {
        sub_004D2D70(pNew, 0, 1);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
