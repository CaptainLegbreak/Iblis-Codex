#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2SeedStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2StaticPathStrc;



struct D2MissilesTxt
{
    char pad00[0x18];
    short wSubMissile;
    char pad1A[0x1E];
    int dwParam[5];
    char pad4C[0x4A];
    short nRange;
    char pad98[0x10C];
};

struct D2SkillsTxt
{
    char pad00[0x138];
    unsigned int dwCalc[2];
    char pad140[0xFC];
};

struct D2DataTablesStrc
{
    char pad00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unusedB68;
    int nMissilesTxtRecordCount;
    char padB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
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
    int unknown38[9];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc*); // 0x0064A3B0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __fastcall SEED_InitSeed(D2SeedStrc*, int); // 0x00650E40
int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc*, int, int, unsigned short); // 0x0064CB30
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc*, D2UnitStrc*); // 0x005AE1F0
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
int __stdcall MISSILE_GetTargetX(D2UnitStrc*); // 0x0064A730

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10

static D2MissilesTxt* GetMissileRecord(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

static D2SkillsTxt* GetSkillRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

// 0x005A9820
static __declspec(noinline) D2UnitStrc* __stdcall sub_005A9820_SpawnNearby(
    D2GameStrc* pGame, int nRange, int nMissileId, unsigned short nMask, D2UnitStrc* pMissile, int nRate)
{
    D2MissileStrc params;
    if (!nRate)
        return 0;
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate)
        return 0;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return 0;
    if (!UNITS_GetRoom(pMissile))
        return 0;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    int nSeed = CLIENTS_GetUnitX(pMissile);
    nSeed += sub_0064A3B0_GetElapsedFrames(pMissile);
    SEED_InitSeed(pSeed, nSeed);
    memset(&params, 0, sizeof(params));
    params.dwFlags = 3;
    params.pOwner = pOwner;
    params.nSkill = MISSILE_GetSkill(pMissile);
    params.nSkillLevel = MISSILE_GetLevel(pMissile);
    params.nMissile = nMissileId;
    --nRange;
    int nSpan = 2 * nRange;
    int nXOffset = ITEMS_RollLimitedRandomNumber(pSeed, nSpan) - nRange;
    int nYOffset = ITEMS_RollLimitedRandomNumber(pSeed, nSpan) - nRange;
    params.nX = CLIENTS_GetUnitX(pMissile) + nXOffset;
    params.nY = CLIENTS_GetUnitY(pMissile) + nYOffset;
    if (COLLISION_CheckMask(UNITS_GetRoom(pMissile), params.nX, params.nY, nMask))
        return 0;
    return MISSILES_CreateMissileFromParams(pGame, &params);
}

// @ref 0x005AE8A0
int __fastcall sub_005AE8A0_SpawnByLevel(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord && pRecord->wSubMissile < 0)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nDivisor = pRecord->dwParam[2];
    if (nDivisor < 1)
        nDivisor = 1;
    int nQuotient = nLevel / nDivisor;
    int nExtra = 2;
    if (nQuotient >= 2)
        nExtra = nQuotient;
    int nRange = pRecord->dwParam[0] + nExtra;
    int nRate = pRecord->dwParam[1] - nQuotient;
    if (nRate < 3)
        nRate = 3;
    sub_005A9820_SpawnNearby(pGame, nRange, pRecord->wSubMissile, 5, pMissile, nRate);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEA60
int __fastcall sub_005AEA60_SpawnBySkill(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord && pRecord->wSubMissile < 0)
        return 2;
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = GetSkillRecord(nSkill);
    if (!pSkill)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[0], nSkill, nLevel);
    int nRate = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[1], nSkill, nLevel);
    sub_005A9820_SpawnNearby(pGame, nRange, pRecord->wSubMissile, 5, pMissile, nRate);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF240
int __fastcall sub_005AF240_SpawnDuringFrames(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord)
        return 2;
    int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    if (pRecord->wSubMissile > 0 && nRemaining < pRecord->nRange - pRecord->dwParam[0] && nRemaining > pRecord->dwParam[0])
        sub_005A9820_SpawnNearby(pGame, pRecord->dwParam[2], pRecord->wSubMissile, 5, pMissile, pRecord->dwParam[1]);
    if (pRecord->dwParam[3] >= 0 && !MISSILE_GetTargetX(pMissile) && nRemaining <= pRecord->dwParam[4] + pRecord->dwParam[0])
        sub_005A9930_CreateAtMissile(pGame, pMissile, pRecord->dwParam[3]);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF880
int __fastcall sub_005AF880_SpawnBySkillMask(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord || !pRecord->wSubMissile)
        return 2;
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = GetSkillRecord(nSkill);
    if (!pSkill)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[0], nSkill, nLevel);
    int nRate = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[1], nSkill, nLevel);
    sub_005A9820_SpawnNearby(pGame, nRange, pRecord->wSubMissile, 0x45, pMissile, nRate);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x005A99E0
static void sub_005A99E0_MISSMODE_PlacePathAtOwner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (pOwner && pPath)
    {
        sub_00650BE0_PlaceUnit(pPath, pMissile, UNITS_GetRoom(pOwner), UNITS_GetXPositionInline(pOwner), UNITS_GetYPositionInline(pOwner));
    }
}

// 0x005AF540
int __fastcall MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
        return 2;
    }

    sub_005A99E0_MISSMODE_PlacePathAtOwner(pGame, pMissile);
    MISSILE_SetCurrentFrame(pMissile, 10);
    MISSMODE_HandleMissileCollision(pGame, pMissile);
    return 1;
}
