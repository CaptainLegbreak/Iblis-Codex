#include "D2Client.h"

#define MAX(a, b) ((a) < (b) ? (b) : (a))
struct D2StaticPathStrc;
struct D2SeedStrc;
struct D2MissileStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    unsigned char unk_10[0x10];
    D2SeedStrc tSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

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
    int unk0x38[5];
    int nOffset;
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_0064A210(D2UnitStrc* pUnit); // 0x0064A210
int __stdcall sub_0064A280(D2UnitStrc* pUnit); // 0x0064A280

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[4];
    short wProgSound;
    short wProgOverlay;
    unsigned char unk_38[0x20];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2SkillsTxt
{
    char unk0x000[0x64];
    unsigned int dwAuraRangeCalc;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
D2UnitStrc* __fastcall sub_004C5EB0_ScanFind(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A400
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
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

static int __stdcall sub_004CC800_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

// 0x004CDDB0
void __fastcall sub_004CDDB0(D2UnitStrc* pUnit, const int* pMissiles, int nMissiles, int nRange, int nOffset, int nChance)
{
    if (!UNITS_GetRoom(pUnit))
    {
        return;
    }

    int i = 0;
    int j = 0;
    D2SeedStrc* pSeed = &pUnit->tSeed;
    if (!pSeed)
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    if (nOffset)
    {
        tParams.dwFlags = 0x8001;
    }
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    tParams.nSkill = sub_0064A280(pUnit);
    tParams.nSkillLevel = sub_0064A210(pUnit);

    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);
    const int nRangeSq = nRange * nRange;
    for (i = -nRange; i <= nRange; ++i)
    {
        for (j = -nRange; j <= nRange; ++j)
        {
            if (!sub_004CC800_CheckDistanceAndLineOfSight(nRangeSq, nX + i, nY + j, UNITS_GetRoom(pUnit), i, j))
            {
                continue;
            }

            D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pUnit), nX + i, nY + j);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
            {
                continue;
            }

            if (nOffset)
            {
                tParams.nOffset = SEED_RollRandomNumber(pSeed) % 25 + nOffset - 12;
            }
            tParams.nX = nX + i;
            tParams.nY = nY + j;
            tParams.nMissile = pMissiles[SEED_RollLimitedRandomNumber(pSeed, nMissiles)];
            const int nRoll = SEED_RollRandomNumber(pSeed) % 100;
            if (nRoll < nChance)
            {
                sub_004CD540_CreateMissile(&tParams);
            }
        }
    }
}

static D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}

// 0x004CF800
int __fastcall sub_004CF800_HitChain(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pPrevious;
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    if (pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        sub_00470390(pUnit, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
    }

    const int nParam = MISSILE_GetTargetX(pMissile);
    if (nParam <= 1)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        const int nSkillId = sub_0064A280(pMissile);
        const int nLevel = sub_0064A210(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    pPrevious = pUnit;
    pUnit = sub_004C5EB0_ScanFind(pOwner, nX, nY, nRange, 0x88583, !pUnit ? -1 : pUnit->dwUnitId, 0);
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit == pPrevious)
    {
        return 1;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pOwner;
    tMissileParams.pTarget = pUnit;
    tMissileParams.nMissile = pMissile->dwClassId;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nTargetX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nTargetY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = sub_0064A280(pMissile);
    tMissileParams.nSkillLevel = sub_0064A210(pMissile);

    D2UnitStrc* pChain = sub_004CD540_CreateMissile(&tMissileParams);
    if (pChain)
    {
        MISSILE_SetTargetX(pChain, nParam - 1);
        MISSILE_SetOwner(pChain, pPrevious);
    }

    return 1;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline void RotateOffsets(int* pX,int* pY)
{
    const int nOldX=*pX;
    const int nNegY=-*pY;
    __assume(nNegY != (-2147483647 - 1));
    *pX=(nNegY+nOldX)/2;
    *pY=(nOldX+*pY)/2;
}

// 0x004D47F0
void __fastcall sub_004D47F0_CltDoPeriodicRetarget(D2UnitStrc* pMissile)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nPeriod = MAX(pMissilesTxtRecord->dwCltParam[1], 1);

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pMissilesTxtRecord->dwCltParam[0] && !(nFrames % nPeriod))
    {
        nOffsetX = MISSILE_GetTargetX(pMissile);
        nOffsetY = MISSILE_GetTargetY(pMissile);
        RotateOffsets(&nOffsetX,&nOffsetY);
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nOffsetX);
        MISSILE_SetTargetY(pMissile, nOffsetY);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
