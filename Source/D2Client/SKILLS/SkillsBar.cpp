#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2CharStatsTxt;




enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_INTOWN = 8,
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __fastcall sub_004C7950(D2UnitStrc* pUnit); // 0x004C7950
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
static int __stdcall sub_004C8350_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY); // 0x004C8350
static int __stdcall sub_004C80D0_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY); // 0x004C80D0


void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId); // 0x004833E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath); // 0x00650590
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int nArg); // 0x00649F70
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg); // 0x004CA4C0
int __fastcall sub_004C85B0_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004C85B0
void __fastcall sub_004C8670_SetLobVelocity(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004C8670
int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY); // 0x00645CA0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
int __fastcall sub_004C7630(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004C7630

__forceinline int UNITS_GetXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int UNITS_GetYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static int __stdcall sub_004C8350_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    D2ActiveRoomStrc* pTarget = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pTarget)
        return 0;
    if (!(pSkillsTxt->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pTarget))
        return 0;
    return 1;
}

static int __stdcall sub_004C80D0_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    if (!sub_004C52E0_GetTargetPosition((D2UnitStrc*)&pUnit, &nSkillLevel, (int*)&pX))
        return 0;
    return sub_004C52E0_GetTargetPosition((D2UnitStrc*)pSkillsTxt, (int*)&pY, (int*)&pUnit);
}

// 0x004C83C0
int __fastcall sub_004C83C0_SkillCltStartPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (STATES_CheckState(pUnit, 0x36))
            return 0;
        if (SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillsBar.cpp", 442) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
            return 0;
    }

    const int bMonster = (!pUnit ? 6 : pUnit->dwUnitType) == 1;
    int nX;
    int nY;
    if (bMonster)
    {
        D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
        if (!pTarget)
        {
            if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
                return 0;
            SKILLS_SetParam4(pSkill, -1);
        }
        else
        {
            nX = CLIENTS_GetUnitX(pTarget);
            nY = CLIENTS_GetUnitY(pTarget);
            nX = 2 * nX - CLIENTS_GetUnitX(pUnit);
            nY = 2 * nY - CLIENTS_GetUnitY(pUnit);
        }

        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
            return 0;
        nX = tCoord.nX;
        nY = tCoord.nY;
    }
    else
    {
        if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
            return 0;
        if (!sub_004C8350_CanTargetRoom(nSkillId, pUnit, nX, nY))
            return 0;
        if (!sub_004C80D0_AdjustTargetPosition(nSkillId, pUnit, nSkillLevel, &nX, &nY))
            return 0;
    }

    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    if (bMonster)
    {
        D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }
    SKILLS_SetFlags(pSkill, 0x1080);
    sub_004C7950(pUnit);
    return 1;
}

// 0x004C85B0
int __fastcall sub_004C85B0_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0x1101);
    PATH_SetMoveTestCollisionMask(pDynamicPath, 0);
    PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, nX, nY);
    PATH_SetType(pDynamicPath, 9);

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int nClassId = pUnit->dwClassId;
    int nVelocity;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nVelocity = pMonStatsTxtRecord->nRun << 8;
    }
    else
    {
        nVelocity = sub_004833E0_GetCharStatsTxtRecord(nClassId)->nRunSpeed << 8;
    }

    PATH_SetVelocity(pDynamicPath, nVelocity, gszSkillsBarSourceFile_006DAE58, 567);
    D2Common_10142(pDynamicPath, pUnit, 0);
    return 1;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
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
        PATH_SetUnitDeadCollision(pUnit, 0);
}

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

// build: context sub_004C8B80_ResetLeapCollision
void __fastcall sub_004C8B80_ResetLeapCollision(D2UnitStrc* pUnit)
{
    const int nFootprint = PATH_GetFootprintCollisionMask(pUnit->pDynamicPath);
    const int nMask = pUnit->dwUnitType == UNIT_MONSTER ? 0x100 : 0x80;
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
                sub_004B9A00(sub_004CA4C0(pUnit, UNITS_GetHitClass(pUnit)), pUnit, 0, 0, 0);
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

// 0x004C8D90
int __fastcall sub_004C8D90_SkillCltStartLeap(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (STATES_CheckState(pUnit, 0x36))
            return 0;

        if (SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsBarSourceFile_006DAE58, 930) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
            return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    int nX = 0;
    int nY = 0;
    if (!SKILLS_CheckIfCanLeapTo(pUnit, pTarget, &nX, &nY))
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            return sub_004C7630(pUnit, pTarget);

        if (!pUnit || pUnit->dwUnitType != 1)
            sub_004CB9C0_Request(pUnit, 0x13);

        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, nPattern, 0x80);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }
    SKILLS_SetFlags(pSkill, 0x1080);
    sub_004C7950(pUnit);
    return 1;
}
