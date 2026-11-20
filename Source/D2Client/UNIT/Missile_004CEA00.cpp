#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"





struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2MissilesTxt
{
    char unk0x00[0x1E];
    short nLastRandomMissile;
    char unk0x20[0x18];
    int dwParam[5];
    int dwCltParam[5];
    char unk0x60[0x144];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                                  // 0x0045C3E0
D2ActiveRoomStrc* __fastcall sub_00463740(D2ActiveRoomStrc* pRoom, int nX, int nY);                         // 0x00463740
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                                             // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);                            // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5);                 // 0x004DA200
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nArg4, int nArg5);                  // 0x0064D910

// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumber
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

// build: context MISSILE_RollInRange
static __forceinline int MISSILE_RollInRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin < nMax)
    {
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }

    return nMin;
}

// build: context SKILLS_GetMissilesTxtRecord
static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// build: context UNITS_GetUnitXPosition
inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context UNITS_GetUnitYPosition
inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004CEA00
void __fastcall sub_004CEA00_SpawnMissileInRadius(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nRadius)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (!UNITS_GetRoom(pUnit))
    {
        return;
    }

    if (pMissilesTxtRecord->nLastRandomMissile > nMissile)
    {
        nMissile = MISSILE_RollInRange(&pUnit->pSeed, nMissile, pMissilesTxtRecord->nLastRandomMissile);
        pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
        if (!pMissilesTxtRecord)
        {
            return;
        }
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pUnit);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pUnit);

    const int nRadiusSq = nRadius * nRadius;
    int nTries = 0;
    while (nTries < 4)
    {
        ++nTries;

        int nX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        int nY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        if (nX * nX + nY * nY > nRadiusSq)
        {
            continue;
        }

        nX += UNITS_GetUnitXPosition(pUnit);
        nY += UNITS_GetUnitYPosition(pUnit);

        D2ActiveRoomStrc* pRoom = sub_00463740(UNITS_GetRoom(pUnit), nX, nY);
        if (!pRoom || COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, 0, 1))
        {
            continue;
        }

        tMissileParams.nX = nX;
        tMissileParams.nY = nY;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA000_ResetGfxMotion(pMissile);
            if (nRadius == 6)
            {
                sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 2 * pMissilesTxtRecord->dwCltParam[3]);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 2 * -pMissilesTxtRecord->dwCltParam[4], 1);
            }
            else
            {
                sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[3]);
                sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[4], 1);
            }
            return;
        }
    }
}
