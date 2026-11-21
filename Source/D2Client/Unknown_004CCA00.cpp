#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
struct D2UnitStrc;

struct D2StaticPathStrc;
struct D2MissilesTxt;
union D2SeedStrc;
struct D2MissileStrc;
struct D2SkillsTxt;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00




extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_004C71F0(int nCount, D2MissileStrc* pMissileParams); // 0x004C71F0
void __fastcall sub_004CCCC0_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x004CCCC0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

static D2MissilesTxt* GetMissilesTxtRecord_Inline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

static D2MissilesTxt* GetUnitMissilesTxt_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return GetMissilesTxtRecord_Inline(pUnit->dwClassId);
}

static int GetUnitXPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CCA00
static void __stdcall sub_004CCA00_SteerMissile(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return;
    if (pTarget && sub_00464820_IsDeadOrDying(pTarget))
        pTarget = 0;
    const int nFrames = (MISSILE_GetLevel(pUnit) - 1) * pTxt->wLevRange + pTxt->wRange;
    MISSILE_SetTotalFrames(pUnit, nFrames);
    MISSILE_SetCurrentFrame(pUnit, nFrames);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDistance;
    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
        MISSILE_SetTargetX(pUnit, 5);
        nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
    }
    else
    {
        const unsigned int dwOffset = MISSILE_GetTargetY(pUnit);
        const short nOffsetX = (short)dwOffset;
        const short nOffsetY = (short)(dwOffset >> 16);
        const int nX = nOffsetX + GetUnitXPosition_Inline(pUnit);
        const int nY = nOffsetY + GetUnitYPosition_Inline(pUnit);
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        MISSILE_SetTargetX(pUnit, 6);
        nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    }
    if (nDistance < 0x19)
        D2Common_10142(pPath, pUnit, 0);
}

// 0x004CCB50
static int sub_004CCB50_SeekTarget(D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return 1;
    const int nRange = pTxt->dwParam[1];
    if (MISSILE_GetTargetX(pUnit) & 4)
        return 1;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
        return 1;
    sub_004CCA00_SteerMissile(sub_004C5EB0_FindDestination(pOwner, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nRange, 3, -1, 0), pUnit);
    return 0;
}

// 0x004CCBE0
int __fastcall sub_004CCBE0_UpdateGuidedMissile(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner || sub_00464820_IsDeadOrDying(pOwner))
        return 1;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        return 1;
    const int nFlags = MISSILE_GetTargetX(pUnit);
    if (!pTarget && (nFlags & 4))
        return 1;
    if (nFlags & 1)
    {
        if (pTarget && pTarget != PATH_GetTargetUnit(pPath))
            return 0;
    }
    else if (nFlags & 2)
    {
        if (sub_0064A380_GetRemainingFrames(pUnit) <= 0)
            return sub_004CCB50_SeekTarget(pUnit) != 0;
        return ((unsigned char)nFlags >> 2) & 1;
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

// 0x004CCD20
int __fastcall sub_004CCD20_CltHitSpiral(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
        return 1;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return 1;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = CLIENTS_GetUnitX(pMissile);
    tParams.nY = CLIENTS_GetUnitY(pMissile);
    tParams.pOwner = pOwner;
    tParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.pInitFunc = sub_004CCCC0_SubmissileInitFunc;
    int nCount = (MISSILE_GetLevel(pMissile) - 1) * pMissilesTxtRecord->dwCltHitPar[1] + pMissilesTxtRecord->dwCltHitPar[0];
    if (nCount <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
            return 1;
        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        if (nCount < 1)
            nCount = 1;
    }
    sub_004C71F0(nCount, &tParams);
    return 1;
}
