#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"





extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath);                                   // 0x00650590
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __stdcall sub_00649F70(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649F70
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit);                                                  // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);               // 0x004654C0
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __fastcall sub_00623C20(D2UnitStrc* pUnit);                                                             // 0x00623C20
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg);                                                   // 0x004CA4C0
int __fastcall sub_004C85B0_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                             // 0x004C85B0
void __fastcall sub_004C8670_SetLobVelocity(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                        // 0x004C8670

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_MONSTER 1
#define UNIT_INVALID 6

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int MONSTERS_GetBaseIdInline(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        int nClassId = pUnit->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline(nClassId);
        if (pMonStatsTxtRecord)
        {
            nClassId = pMonStatsTxtRecord->nBaseId;
        }
        return nClassId;
    }
    return -1;
}

// 0x004C8750
static void __stdcall sub_004C8750_LeapBounceFromTarget(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
        return;

    D2UnitStrc* pTarget = sub_00463990(SKILLS_GetParam4(pSkill), SKILLS_GetParam3(pSkill));
    if (!pTarget)
        return;

    SKILLS_SetFlags(pSkill, 1);
    UNITS_SetAnimationFrame(pUnit, 12);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
    PATH_RecacheRoomIfNeeded(pPath);
    PATH_SetNewDistance(pPath, 5);
    PATH_SetStepNum(pPath, 1);
    PATH_SetTargetUnit(pPath, 0);

    nX = 3 * nX - 2 * CLIENTS_GetUnitXInline(pTarget);
    nY = 3 * nY - 2 * CLIENTS_GetUnitYInline(pTarget);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        PATH_SetType(pPath, 11);
        D2COMMON_10190_PATH_SetDistance(pPath, 5);
        D2Common_10142(pPath, pUnit, 0);
    }
}

// 0x004C8890
static void __stdcall sub_004C8890_EndLeapPath(D2UnitStrc* pUnit, int nX, int nY)
{
    int nUnitType;
    if (!pUnit)
        nUnitType = UNIT_INVALID;
    else
        nUnitType = pUnit->dwUnitType;

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pPath || !pRoom)
        return;

    if (nUnitType == UNIT_MONSTER)
    {
        if (nX && nY)
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
        PATH_SetFootprintCollisionMask(pPath, 0x100);
        PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
        PATH_SetType(pPath, 2);
    }
    else
    {
        if (nX && nY)
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
        PATH_SetFootprintCollisionMask(pPath, 0x80);
        PATH_SetMoveTestCollisionMask(pPath, 0x1C09);
        PATH_SetType(pPath, 7);
    }

    if (sub_00464820_IsDeadOrDying(pUnit))
        sub_00649F70(pUnit, 0);
}

// build: context sub_004C8970_UpdateLeap
static int __stdcall sub_004C8970_UpdateLeap(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bOverlay)
{
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nMotion = sub_004DA150_GetMotionAZ(pUnit);
    int nUnitType = UNIT_INVALID;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    const int bMonster = nUnitType == UNIT_MONSTER;

    int nBaseId = -1;
    if (bMonster)
        nBaseId = MONSTERS_GetBaseIdInline(pUnit);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
        nBaseId = -1;

    if (nMotion && (CLIENTS_GetUnitXInline(pUnit) != nX || CLIENTS_GetUnitYInline(pUnit) != nY))
    {
        if (bMonster)
        {
            int nFrame = 0;
            if (nBaseId == MONSTER_SANDLEAPER1)
                nFrame = 8;
            else if (nBaseId == MONSTER_ANCIENTBARB1)
                nFrame = UNITS_GetDistanceToCoordinates(pUnit, nX, nY) < 2 ? 12 : 10;

            UNITS_SetAnimationFrame(pUnit, nFrame);
            pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
            return 0;
        }

        UNITS_SetAnimationFrame(pUnit, 10);
        pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
        return 0;
    }

    sub_004C8890_EndLeapPath(pUnit, nX, nY);
    sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, 0);
    if (bOverlay)
        sub_00470390(pUnit, 0x50, 2, 0, 0, 0, 0, 0);

    sub_004B9A00(sub_004CAEB0(pUnit, 1), pUnit, 0, 0, 0);

    if (bMonster)
    {
        if (nBaseId == MONSTER_SANDLEAPER1)
            sub_004C8750_LeapBounceFromTarget(pUnit, pSkill, nX, nY);
        return 1;
    }

    sub_004B9A00(0x9D5, pUnit, 0, 0, 0);
    return 1;
}

// 0x004C8B80
void __fastcall sub_004C8B80_ResetLeapCollision(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* const pPath = pUnit->pDynamicPath;
    const int nFootprint = PATH_GetFootprintCollisionMask(pPath);
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    const int nMask = nUnitType == UNIT_MONSTER ? 0x100 : 0x80;
    if (nFootprint == nMask)
        return;

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    const int nX = pSkill ? SKILLS_GetParam1(pSkill) : CLIENTS_GetUnitXInline(pUnit);
    const int nY = pSkill ? SKILLS_GetParam2(pSkill) : CLIENTS_GetUnitYInline(pUnit);
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nMask);
    sub_004654C0_SetUnitPosition(pUnit, nX, nY, 0);
    sub_004C8890_EndLeapPath(pUnit, nX, nY);
}

// 0x004C8C60
int __fastcall sub_004C8C60_SkillCltDoLeap(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 0x100)
    {
        if (!sub_004C8970_UpdateLeap(pUnit, pSkill, 1) && !(nFlags & 2))
            return 0;
    }

    if (nFlags & 2)
    {
        sub_004C8890_EndLeapPath(pUnit, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
        SKILLS_SetFlags(pSkill, 0);
        return 1;
    }

    if (nFlags & 0x80)
    {
        sub_004C85B0_SetRunPath(pUnit, pSkill);
        sub_004C8670_SetLobVelocity(pUnit, pSkill);
        return 1;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        SKILLS_SetFlags(pSkill, 0x1000);

    return 1;
}

// 0x004C8ED0
int __fastcall sub_004C8ED0_SkillCltDoLeapAttack(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    int nResult = 0;
    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 0x100)
    {
        if (!sub_004C8970_UpdateLeap(pUnit, pSkill, 1))
        {
            if (!(nFlags & 2))
                return 0;
        }
        else
        {
            const int nTargetType = SKILLS_GetParam3(pSkill);
            const int nTargetId = SKILLS_GetParam4(pSkill);
            D2UnitStrc* pTarget = 0;
            if (nTargetType != UNIT_INVALID)
                pTarget = sub_00463990(nTargetId, nTargetType);
            if (!pTarget)
                pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 0, -1, 0);

            if (pTarget)
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
                sub_00465BF0(pUnit, 0);
                sub_004B9A00(sub_004CA4C0(pUnit, sub_00623C20(pUnit)), pUnit, 0, 0, 0);
                nResult = 1;
            }
            else
            {
                pUnit->dwFrameCountPrecise = 0x400;
            }
        }
    }

    if (nFlags & 2)
    {
        sub_004C8890_EndLeapPath(pUnit, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
        SKILLS_SetFlags(pSkill, 0);
        return 1;
    }

    if (nFlags & 0x80)
    {
        sub_004C85B0_SetRunPath(pUnit, pSkill);
        sub_004C8670_SetLobVelocity(pUnit, pSkill);
        return 1;
    }

    SKILLS_SetFlags(pSkill, 0x1000);
    return nResult;
}
