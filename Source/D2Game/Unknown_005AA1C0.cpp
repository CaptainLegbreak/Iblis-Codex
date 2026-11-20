#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define MONMODE_NEUTRAL 1
struct D2MissilesTxt;
struct D2StaticPathStrc;


struct D2MissilesTxt
{
    char unk0x00[0x38];
    int dwParam[2];
    unsigned char unk_40[0xC];
    int dwHitPar[3];
    unsigned char unk_58[0x3E];
    short wRange;
    short wLevRange;
    char unk0x9A[0x10A];
};

typedef char D2MissilesTxt_size_check[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600



int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005AA1C0
int __fastcall sub_005AA1C0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;

    pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwHitPar[0] >= 0 && pMissilesTxtRecord->dwHitPar[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nSpawnMode = MONMODE_NEUTRAL;
        if (pMissilesTxtRecord->dwHitPar[1] >= 0 && pMissilesTxtRecord->dwHitPar[1] < 16)
        {
            nSpawnMode = pMissilesTxtRecord->dwHitPar[1];
        }

        D2GAME_SpawnPresetMonster_6FC66560(pGame, UNITS_GetRoom(pMissile), pMissilesTxtRecord->dwHitPar[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), nSpawnMode);
    }

    return 1;
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

    const int v9 = D2Common_10201(pMissile->pDynamicPath);
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
