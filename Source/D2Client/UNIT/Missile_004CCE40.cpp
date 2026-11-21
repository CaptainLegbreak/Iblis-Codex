#include "D2MissileIds.h"
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

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

struct D2RequestStrc;

struct D2MissileScanArgStrc;

struct D2SpawnOffsetMissileView;

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    D2UnitStrc* pOtherUnit;
    int unk0x0C;
    int nArg0;
    int nArg1;
    int nArg2;
    int nArg5;
    int nArg6;
    int nArg7;
    int unk0x28;
    int nArg3;
    int nArg4;
    int unk0x34[8];
    void* pfCallback;
    int nIndex;
};

int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

void __fastcall sub_004E2ED0_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset); // 0x004E2ED0

int __stdcall sub_006488C0_PathGetX(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall sub_00648900_PathGetY(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear); // 0x00649030

struct D2MissileScanArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pMissile;
    int nSkillId;
    int nSkillLevel;
    int f_10;
    int f_14;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType);

int __fastcall sub_004CFFA0_HitScanCallback(void* pArg, D2UnitStrc* pUnit);

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);

extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);

struct D2SpawnOffsetMissileView
{
    void __thiscall sub_004D16C0_SpawnOffsetMissile(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x004D16C0
};

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
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
}

// 0x004CDBA0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x20;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nArg5;
    tRequest.nArg6 = nArg6;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004CDC30
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (!nRange)
    {
        nRange = 30;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x521;
    tRequest.pUnit = pOwner;
    tRequest.nArg1 = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    tRequest.nArg2 = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg7 = nRange;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004CDD10
D2UnitStrc* __fastcall sub_004CDD10_SubmitTargetRequest(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pOwner, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x420;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
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

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004D0060
int __fastcall sub_004D0060_HitScanArea(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!sub_00463990(sub_0064A780_targetValue(pMissile), sub_0064A730_GetMissileTargetStatus(pMissile)))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (nFlags)
    {
        nFlags = 0xA683;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.f_14 = pMissilesTxtRecord->wCltHitSubMissile[0];
    sub_004C5C40_ScanArea(pOwner, nX, nY, nRange, nFlags, sub_004CFFA0_HitScanCallback, &tArg, 0);
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

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x004D1300
static void __stdcall sub_004D1300_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile)
{
    const int nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    const int nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nTargetX = UNITS_GetUnitXPosition(pMissile) + nOffsetX;
    tParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + nOffsetY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tParams);
}


// 0x004D65E0
void __fastcall sub_004D65E0_CltDoOffsetMissileTimer(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    int nCounter = MISSILE_GetTargetY(pMissile);
    if (!nCounter)
    {
        const int nUnitId = MISSILE_GetTargetX(pMissile);
        ((D2SpawnOffsetMissileView*)nUnitId)->sub_004D16C0_SpawnOffsetMissile(pMissile, pOwner);
        nCounter = (unsigned int)SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10;
    }

    --nCounter;
    MISSILE_SetTargetY(pMissile, nCounter);
    sub_004D30C0_CltDoCommon(pMissile);
}

void __fastcall sub_004D66E0_CltDoFallingSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(MISSILE_IZUAL_CONTROL);
    sub_004D1300_SpawnScattered(10, MISSILE_IZUAL_MIST_LOOP, pMissile);
    if (nRemaining < pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[0] && nRemaining > pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[1])
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            const int nRollX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 10);
            const int nTargetX = nRollX + CLIENTS_GetUnitX(pOwner) - 5;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.nTargetX = nTargetX;
            tParams.dwFlags = 0x20;
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nTargetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 10) - 5 + CLIENTS_GetUnitY(pOwner);
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = MISSILE_IZUAL_LIGHTNING;
            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
            if (pNew)
            {
                sub_004DA250(pNew, 0, 0, -(int)(SEED_RollLimitedRandomNumber(&pMissile->pSeed, 3) + 3), 1);
                sub_004DA5B0_SetBallistic(pNew, 0, 0xF);
                sub_004DA340(pNew);
            }
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

static void __stdcall sub_004D19D0_SpawnRing(int nTargetUnitId, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_HFFRAGMENT1);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x8102;
    tParams.nMissile = MISSILE_HFFRAGMENT1;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    for (int i = 0; i < 14; ++i)
    {
        const int nX = aOffsetX[i];
        const int nY = aOffsetY[i];
        tParams.nTargetX = nX;
        tParams.nTargetY = nY;
        const int nAbsX = nX < 0 ? -nX : nX;
        const int nAbsY = nY < 0 ? -nY : nY;
        const int nDistance = (nX >= nY ? nAbsX + 2 * nAbsY : nAbsY + 2 * nAbsX) >> 1;
        tParams.nRange = pMissilesTxtRecord->wRange * nDistance / 6;
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, nTargetUnitId);
            MISSILE_SetTargetY(pNew, SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10);
        }
    }
}

// 0x004D6680
void __fastcall sub_004D6680_CltDoObjectRing(D2UnitStrc* pMissile)
{
    const int nTargetUnitId = MISSILE_GetTargetX(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!sub_00463990(nTargetUnitId, 2))
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    if (nFrames == 10)
    {
        sub_004D19D0_SpawnRing(nTargetUnitId, pMissile);
        sub_00476A80_StartTiming(nFrames - 6, nFrames + 0x46, 0x50, 0x190);
    }
    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004F16F0
int __fastcall sub_004F16F0_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nArg0, int nArg3, int nArg4, int nMissileArg, int bFirst, int bClearPathFlag)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (bFirst)
    {
        --nCount;
        D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nArg0, nArg3, nArg4);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x21;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = UNITS_GetXPositionInline(pUnit);
    tRequest.nArg2 = UNITS_GetYPositionInline(pUnit);
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    tRequest.pfCallback = sub_004E2ED0_InitCappedChargedPath;
    if (bClearPathFlag)
    {
        tRequest.nType |= 0x2000;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tRequest.nIndex = i;
        D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004CCE40.inc"
