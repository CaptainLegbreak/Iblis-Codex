#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Constants.h"
#include "D2ClientTypes.h"
#include "D2Structs.h"
struct D2DynamicPathStrc;
struct D2UnitStrc;

struct D2RoomStrc;
struct D2StaticPathStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
enum D2PlayerModes
{
    PLAYER_MODE_WALK = 2,
    PLAYER_MODE_RUN = 3,
    PLAYER_MODE_6 = 6,
};

int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __stdcall sub_00650C60_UpdatePath(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00650C60


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB); // 0x0063E510


D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc*); // 0x004648F0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall sub_00648A10_GetPathTargetY(D2DynamicPathStrc*); // 0x00648A10
void __fastcall PLAYER_ApplyUnitCommand(int, D2UnitStrc*, int*, int); // 0x00461250
D2UnitStrc* __stdcall sub_00643A00_GetRelatedUnit(D2UnitStrc*, int); // 0x00643A00
void __fastcall DLIGHTMAP_ReleaseLight(D2UnitStrc*); // 0x004743D0
void __stdcall sub_00620210_SetUnitAction(D2UnitStrc*, int); // 0x00620210
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc*); // 0x00648DC0
D2RoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall sub_0061AB00_IsTownRoom(D2RoomStrc*); // 0x0061AB00
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc*, int, int); // 0x004804A0
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc*, int); // 0x00480E70
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
void __fastcall UNITMODE_SetPosition(D2UnitStrc*, unsigned short, unsigned short, int, int, int); // 0x004804E0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall SKILLS_GetFlags(D2SkillStrc*); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc*, int); // 0x00644660
int __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
static void __stdcall PLAYER_SetModeAndSync(int, int, D2UnitStrc*); // 0x00460830
static void __stdcall PLAYER_ReleaseUsedSkill(int, D2UnitStrc*); // 0x004611F0

// 0x004630E0
int __fastcall sub_004630E0_GetPlayerTableA(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, pTable, aOther);
    return 1;
}

// 0x00463130
int __fastcall sub_00463130_GetPlayerTableB(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, aOther, pTable);
    return 1;
}

static void __stdcall PLAYER_SetModeAndSync(int bSync, int nState, D2UnitStrc* pUnit)
{
    UNITMODE_SetUnitMode(pUnit, nState);
    if (!bSync) return;
    if (pUnit != sub_00463DE0_GetPlayerUnit()) return;
    int nX, nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: nX = pUnit->pStaticPath->nXPos; break;
    default: nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; break;
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: nY = pUnit->pStaticPath->nYPos; break;
    default: nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; break;
    }
    if (nX && nY) UNITMODE_SetPosition(pUnit, nX, nY, 0, 0, 0);
}

static void __stdcall PLAYER_ReleaseUsedSkill(int bKeep, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return;
    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        SKILLS_SetFlags(pSkill, nFlags | 2);
        SKILLS_DoUsedSkill(pUnit);
        return;
    }
    if (bKeep) return;
    const int bFlag = pUnit ? (pUnit->dwFlags >> 6) & 1 : 0;
    if (!bFlag) SKILLS_DoUsedSkill(pUnit);
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* unit)
{
    int type = 6;
    if (unit) type = unit->dwUnitType;
    return type;
}

inline int UNITS_GetUnitIdInline(D2UnitStrc* unit)
{
    if (!unit)
        return -1;
    return unit->dwUnitId;
}

// 0x00463260
static void sub_00463260_UpdateStoredUnit(D2UnitStrc* unit)
{
    if (unit != sub_00463DE0_GetPlayerUnit())
        return;
    if (STATLIST_UnitGetStatValue(unit, STAT_STAMINA, 0))
        return;
    D2DynamicPathStrc* path = unit->pDynamicPath;
    int args[7] = {};
    D2UnitStrc* target = CUNIT_GetPathTargetUnit(unit);
    if (PATH_GetTargetUnit(path))
    {
        args[0] = UNITS_GetUnitTypeInline(target);
        args[1] = UNITS_GetUnitIdInline(target);
        PLAYER_ApplyUnitCommand(0, unit, args, 0);
        return;
    }
    args[0] = D2COMMON_10175_PathGetFirstPointX(path);
    args[1] = sub_00648A10_GetPathTargetY(path);
    D2UnitStrc* related = sub_00643A00_GetRelatedUnit(unit, 0);
    if (related)
        DLIGHTMAP_ReleaseLight(related);
    int const tArg1 = unit == sub_00463DD0_GetPlayerUnit();
    PLAYER_ReleaseUsedSkill(tArg1, unit);
    sub_00620210_SetUnitAction(unit, 0);
    path = unit->pDynamicPath;
    if ((unit ? unit->dwAnimMode : 0) == 19)
        return;
    else
    {

        PATH_ResetToPreviousType(path);
        int idle, move;
        if (sub_0061AB00_IsTownRoom(UNITS_GetRoom(unit)))
        {
            idle = 5;
            move = 6;
        }
        else
        {
            idle = 1;
            move = 2;
        }
        if (sub_004804A0_SetPathTargetPos(unit, args[0], args[1]))
            UNITMODE_SetUnitMode(unit, move);
        else
            PLAYER_SetModeAndSync(1, idle, unit);
    }
}

// calling-convention shim (not game code)
void __stdcall sub_00463260_Shim(D2UnitStrc* unit)
{
    sub_00463260_UpdateStoredUnit(unit);
}

// 0x00463180
void __fastcall AUTOMAP_UpdatePathAndMove(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3)
{
    int nMode = pUnit->dwAnimMode;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTargetUnit = 0;
    int bMove = 0;
    int nX = 0;
    int nY = 0;
    if (nMode >= PLAYER_MODE_WALK && (nMode <= PLAYER_MODE_RUN || nMode == PLAYER_MODE_6))
    {
        bMove = 1;
        pTargetUnit = CUNIT_GetPathTargetUnit(pUnit);
        if (!pTargetUnit)
        {
            ITEM_GetTargetPosition(pUnit, &nX, &nY);
        }
    }
    sub_00650C60_UpdatePath(pPath, pUnit, nArg1, nArg2, nArg3);
    if (bMove)
    {
        D2UnitTargetStrc tTarget;
        memset(&tTarget, 0, sizeof(tTarget));
        if (pTargetUnit)
        {
            tTarget.nParam1 = pTargetUnit->dwUnitType;
            tTarget.nParam2 = pTargetUnit->dwUnitId;
            PLAYER_ApplyUnitCommand(nMode == PLAYER_MODE_RUN ? 0x18 : 0, pUnit, &tTarget, 0);
        }
        else
        {
            tTarget.nParam1 = nX;
            tTarget.nParam2 = nY;
            PLAYER_ApplyUnitCommand(nMode == PLAYER_MODE_RUN ? 0x17 : 1, pUnit, &tTarget, 0);
        }
    }
}
