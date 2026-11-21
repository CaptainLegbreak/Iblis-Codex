#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
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

extern const int gaRingOffsetY_006DAF88[8];                                                                 // 0x006DAF88

extern const int gaRingOffsetX_006DAFA8[8];                                                                 // 0x006DAFA8

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

int __fastcall sub_004C7700(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nParam0, int nMissile, int nSkill, int nSkillLevel, int nParam1, int nFlag); // 0x004CEF50

void __stdcall sub_004DA2F0_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1);                   // 0x004DA2F0

void __fastcall sub_004DA340(D2UnitStrc* pMissile);                                                         // 0x004DA340

void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile);                                          // 0x004E2ED0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

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

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

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

// 0x004CCE40
int __fastcall sub_004CCE40_HitSpiralGrid(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwCltHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 3;
    tMissileParams.nX = CLIENTS_GetUnitX(pMissile);
    tMissileParams.nY = CLIENTS_GetUnitY(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[1])
    {
        tMissileParams.pInitFunc = (MissileInitFunc)sub_004E2ED0_VolleyCallback;
    }
    sub_004C71F0(pMissilesTxtRecord->dwCltHitPar[0], &tMissileParams);
    return 1;
}

// 0x004CF150
int __fastcall sub_004CF150_HitRing(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    int nStep = pMissilesTxtRecord->dwCltHitPar[0];
    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 8; i += nStep)
    {
        tMissileParams.nTargetX = gaRingOffsetX_006DAFA8[i];
        tMissileParams.nTargetY = gaRingOffsetY_006DAF88[i];
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pSubMissile)
        {
            MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DAFA8[i]);
            MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DAF88[i]);
        }
    }
    return 1;
}

// 0x004D06F0
int __fastcall sub_004D06F0_HitSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, nSkill, nSkillLevel);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        sub_004CEF50_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[1], nSkill, nSkillLevel, pMissilesTxtRecord->dwCltHitPar[1], 1);
    }

    if (pUnit)
    {
        sub_00470390(pUnit, 0x97, 2, 0, 0, 0, 0, 0);
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        sub_00470390(pOwner, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
    }
    return 1;
}

// 0x004D0A80
int __fastcall sub_004D0A80_HitBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    int nCount = pMissilesTxtRecord->dwCltHitPar[0] + (nSkillLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];
    if (nCount <= 0)
    {
        const int nSkill = MISSILE_GetSkill(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkill, nSkillLevel);
        if (nCount < 1)
        {
            nCount = 1;
        }
    }

    sub_004C7700(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], nCount, nCount / 4, MISSILE_GetSkill(pMissile), nSkillLevel);
    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004D0EB0
int __fastcall sub_004D0EB0_HitLob(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
    tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
    tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);

    D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pSubMissile)
    {
        return 1;
    }

    sub_004DA2F0_SetMotionParams(pSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);
    sub_004DA5B0_SetBallistic(pSubMissile, 0, pMissilesTxtRecord->dwCltHitPar[2]);
    sub_004DA340(pSubMissile);
    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004CCE40.inc"
