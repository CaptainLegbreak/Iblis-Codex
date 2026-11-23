#include "D2LevelIds.h"

#include "D2Client.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2GameTypes.h"

#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2StaticPathStrc;

union D2SeedStrc;

struct D2MissileStrc;

struct D2MissilesTxt;

struct D2SkillsTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall sub_0064A210(D2UnitStrc* pUnit); // 0x0064A210

int __stdcall sub_0064A280(D2UnitStrc* pUnit); // 0x0064A280

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

D2UnitStrc* __fastcall WARDENCLIENT_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A400

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

struct D2GfxLightStrc;

extern const int gaRing5OffsetX[]; // 0x006DB0EC

extern const int gaRing5OffsetY[]; // 0x006DB0D8

extern const int gaRing18OffsetX[]; // 0x006DB090

extern const int gaRing18OffsetY[]; // 0x006DB048

void __fastcall DLIGHTMAP_ResetLightSize(D2GfxLightStrc* pLight, int nRadius); // 0x004742D0

int __fastcall GFXUTIL_SubmitMissileRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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

// calling-convention shim (not game code)
__declspec(noinline) D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams)
{
    return CUNIT_GetOwnerUnit(pMissileParams->pOwner);
}

static D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int SKILLS_GetLevelBasedParam(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return (nLevel - 1) * pSkillsTxtRecord->dwParam[3] + pSkillsTxtRecord->dwParam[2];
}

// 0x004CF9B0
int __fastcall sub_004CF9B0_CltHitRingSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    if (!DATATBLS_GetSkillsTxtRecord(nSkill))
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x4001;
    tMissile.nSkill = nSkill;
    tMissile.nSkillLevel = nLevel;
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        const int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        for (int i = 0; i < nCount; ++i)
        {
            tMissile.nX = nX + gaRing5OffsetX[i % 5];
            tMissile.nY = nY + gaRing5OffsetY[i % 5];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        tMissile.dwFlags = 0x8001;
        tMissile.nRange = SKILLS_GetLevelBasedParam(nSkill, nLevel);
        tMissile.nX = nX;
        tMissile.nY = nY;
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
        if (pNew && pNew->pLight)
        {
            DLIGHTMAP_ResetLightSize(pNew->pLight, 0xC);
        }
    }

    tMissile.dwFlags = 0xC001;
    int nIndex = 0;
    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        nIndex = pMissilesTxtRecord->dwCltHitPar[1];
        for (int i = 0; i < nIndex; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX[i % 18];
            tMissile.nY = nY + gaRing18OffsetY[i % 18];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[3] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[3];
        const int nEnd = nIndex + pMissilesTxtRecord->dwCltHitPar[2];
        for (int i = nIndex; i < nEnd; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX[i % 18];
            tMissile.nY = nY + gaRing18OffsetY[i % 18];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    return 1;
}
