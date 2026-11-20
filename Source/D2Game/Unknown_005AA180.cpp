#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

struct D2StaticPathStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;



D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0



struct D2MissilesTxt
{
    char unk00[0x24];
    short wHitSubMissile[4];
    unsigned char unk_2C[0xC];
    int dwParam[2];
    unsigned char unk_40[0xC];
    int dwHitPar[3];
    char unk58[0x30];
    unsigned int dwHitCalc;
    unsigned char unk_8C[0xA];
    short wRange;
    short wLevRange;
    unsigned char unk_9A[0xE];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char unkAE[0xF6];
};

struct D2SkillsTxt
{
    char pad0x000[0x50];
    int dwAuraFilter;
    char pad0x054[0x0C];
    int dwAuraLenCalc;
    int dwAuraRangeCalc;
    char pad0x068[0x1A];
    short nState;
    char pad0x084[0xB4];
    unsigned int dwCalc[4];
    char unk148[0xF4];
};


struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk08[26];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall MISSILE_GetSkill(D2UnitStrc*); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc*, D2UnitStrc*, unsigned int, int, int); // 0x0064B7C0
void __fastcall sub_005A9530_CreateHitSubmissiles(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005A9530
int __fastcall MISSMODE_GetDamageValue(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x005A8C70
int __fastcall sub_0056BAD0_ApplyAreaDamage(D2GameStrc*, D2UnitStrc*, int, int, int, D2DamageStrc*, unsigned int); // 0x0056BAD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A380

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nRange, unsigned int nAuraFilter, int nUnitId, int a8); // 0x0056BD10
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
int __fastcall sub_004EFC20_GetSkillParam2(int); // 0x004EFC20
int __fastcall sub_004EFCB0_GetSummonLevel(int, int); // 0x004EFCB0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int, int); // 0x004CC7C0
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int); // 0x005DDD00

// 0x005AA180
int __fastcall sub_005AA180_CheckOwnerState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pExpectedOwner)
{
    int nResult = 2;
    if (!pExpectedOwner)
        return nResult;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner && pExpectedOwner == pOwner)
    {
        if (STATES_CheckState(pOwner, 13))
            nResult = 0;
    }
    return nResult;
}

static D2MissilesTxt* GetMissilesTxt(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

static D2SkillsTxt* SkillsRecordFor(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AA250
int __fastcall sub_005AA250_ApplyHitExplosion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return 1;
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SkillsRecordFor(nSkillId);
    if (!pSkillsTxtRecord) return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pMissilesTxtRecord->wHitSubMissile[0] >= 0)
    {
        STATLIST_SetUnitStat(pMissile, 0x38, 0, 0);
        STATLIST_SetUnitStat(pMissile, 0x86, 0, 0);
        int nCount = pMissilesTxtRecord->dwHitPar[0];
        if (nCount <= 0)
        {
            nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
            if (nCount < 1) nCount = 1;
        }
        const int nValue = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwHitCalc, !pMissile ? -1 : pMissile->dwClassId, nLevel);
        sub_005A9530_CreateHitSubmissiles(pGame, pMissile, nCount, pMissilesTxtRecord->wHitSubMissile[0], nValue);
    }
    int nRange = pMissilesTxtRecord->dwHitPar[1];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        if (nRange < 1) nRange = 1;
    }
    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_0056BAD0_ApplyAreaDamage(pGame, SUNIT_GetOwner(pGame, pMissile), GetX(pMissile), GetY(pMissile), nRange, &damage, 0);
    return 3;
}

static __forceinline D2MissilesTxt* MISSILE_GetMissilesTxtRecord_Inline(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return 0;
    }

    const int nMissileId = pMissile->dwClassId;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AA460
static void __stdcall sub_005AA460_MISSMODE_GuidedRetarget(D2UnitStrc* pTarget, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (pTarget && SUNIT_IsDead(pTarget))
    {
        pTarget = 0;
    }

    const int nFrames = pMissilesTxtRecord->wRange + pMissilesTxtRecord->wLevRange * (MISSILE_GetLevel(pMissile) - 1);
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);

    int nDistance;
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
        MISSILE_SetTargetX(pMissile, 5);
        nDistance = sub_006416D0_UnitEdgeDistance(pMissile, pTarget);
    }
    else
    {
        const unsigned int nParam = MISSILE_GetTargetY(pMissile);
        const unsigned int nParamHigh = nParam >> 16;
        const int nX = CLIENTS_GetUnitXInline(pMissile) + (short)nParam;
        const int nY = CLIENTS_GetUnitYInline(pMissile) + (short)nParamHigh;
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        MISSILE_SetTargetX(pMissile, 6);
        nDistance = UNITS_GetDistanceToCoordinates(pMissile, nX, nY);
    }

    if (nDistance < 25)
    {
        D2Common_10142(pPath, pMissile, 0);
    }
}

// 0x005AA5B0
static int __stdcall sub_005AA5B0_MISSMODE_GuidedFindTarget(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nParam = pMissilesTxtRecord->dwParam[1];
    if (MISSILE_GetTargetX(pMissile) & 4)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    sub_005AA460_MISSMODE_GuidedRetarget(sub_6FD107F0(pGame, pOwner, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), nParam, 3, -1, 0), pMissile);
    return 0;
}

// 0x005AA650
int __fastcall MISSMODE_SrvHit10_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        return 1;
    }

    const int v8 = MISSILE_GetTargetX(pMissile);
    if (!pUnit && v8 & 4)
    {
        return 1;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    const unsigned short v9 = D2Common_10201(pPath);
    if (!pUnit && v9 & 4)
    {
        return 1;
    }

    if (v8 & 1)
    {
        if (pUnit && pUnit != SUNIT_GetTargetUnit(pGame, pMissile))
        {
            return 4;
        }

        return 3;
    }

    if (v8 & 2)
    {
        if (sub_0064A380_GetRemainingFrames(pMissile) <= 0)
        {
            return sub_005AA5B0_MISSMODE_GuidedFindTarget(pGame, pMissile) ? 1 : 4;
        }

        return (v8 & 4) ? 3 : 4;
    }

    return 3;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005AA730
int __fastcall MISSMODE_SrvHit12_ChainLightning_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pPrevious;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 3;
    }

    if (!pUnit)
    {
        return 3;
    }

    const int nParam = MISSILE_GetTargetX(pMissile);
    if (nParam <= 1)
    {
        return 3;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 3;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    pPrevious = pUnit;
    pUnit = SKILLS_FindNextAuraTarget(pGame, pOwner, nX, nY, nRange, 0x88583, !pUnit ? -1 : pUnit->dwUnitId, 0);
    if (!pUnit)
    {
        return 3;
    }

    if (pUnit == pPrevious)
    {
        return 3;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pOwner;
    missileParams.pTarget = pUnit;
    missileParams.nMissile = pMissile->dwClassId;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pSubMissile)
    {
        MISSILE_SetTargetX(pSubMissile, nParam - 1);
    }

    return 3;
}

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pResult = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pResult = &sgptDataTables->pSkillsTxt[nSkillId];
    return pResult;
}

// 0x005AAFB0
int __fastcall sub_005AAFB0_ApplyTerrorMissileHit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pTarget)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxt = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    if (!pSkillsTxt)
        return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return 1;
    if (pTarget && (!pTarget ? 6 : pTarget->dwUnitType) == 1)
    {
        const short nState = pSkillsTxt->nState;
        if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
            return 1;
        if (!STATES_CheckState(pTarget, nState))
        {
            const int nMaxLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0) + nSkillLevel + sub_004EFC20_GetSkillParam2(nSkillId);
            if (nMaxLevel > STATLIST_UnitGetStatValue(pTarget, 12, 0))
                AIUTIL_ApplyTerrorCurseState(pGame, pOwner, pTarget, nSkillId, sub_004CC7C0_GetSkillMissileRange(nSkillId, nSkillLevel), sub_004EFCB0_GetSummonLevel(nSkillId, nSkillLevel));
        }
    }
    return 0;
}
