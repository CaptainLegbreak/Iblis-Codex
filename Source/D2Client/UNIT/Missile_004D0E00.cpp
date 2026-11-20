#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"





struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[3];
    char unk0x032[0x3A];
    int dwCltHitPar[2];
    char unk0x074[0x130];
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

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

static __forceinline int sub_CanHitUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    return sub_004638A0_CheckMonStats2Flag(nClassId, 0xB);
}

// 0x004D0E00
int __fastcall sub_004D0E00_CltHitBurstSub(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (sub_CanHitUnit(pHitUnit))
    {
        if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
        {
            sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }

        sub_004D0B90_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[1], pMissilesTxtRecord->wCltHitSubMissile[2], pMissile);
        return 1;
    }

    return 0;
}
