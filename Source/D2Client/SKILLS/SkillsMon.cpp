#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
struct D2UnitStrc;

struct D2StaticPathStrc;
struct D2GfxLightStrc;
struct D2SkillDescTxt;





typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

static const int gnRingOffsetX_006DBB68[64] =                                                               // 0x006DBB68
{
    30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
    0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
    -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
    0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
};

static const int gnRingOffsetY_006DBC68[64] =                                                               // 0x006DBC68
{
    0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
    30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
    0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
    -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
};

extern "C" unsigned int __cdecl sub_0044DA90_GetTick();                                                     // 0x0044DA90
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                      // 0x004648F0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290
void __fastcall sub_00476A80_SetTimedState(int nParam0, int nTime1, int nTime2, int nTime3);                     // 0x00476A80
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                         // 0x004A89D0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY);                                          // 0x004C53D0
void __fastcall sub_004C7480_SpawnMissileRing(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nArg1, int nArg2); // 0x004C7480
int __fastcall sub_004C7B20(D2UnitStrc* pUnit, int nMissile);                        // 0x004C7B20
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __fastcall sub_004E1C80_CltMissileInitDiabWall(D2UnitStrc* pMissile, int nArg);                                   // 0x004E1C80
D2UnitStrc* __fastcall sub_004E31C0_CltDo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);               // 0x004E31C0
void __fastcall sub_004EA010_SkillDescLine(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nArg3, int nArg4, int nArg5, int nArg6); // 0x004EA010
void __fastcall sub_004F2440_OnStateRemove(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);       // 0x004F2440
int __fastcall sub_004F3A60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nParam1, int nParam2, int nParam3); // 0x004F3A60
int __fastcall sub_004F3CE0_CreateSkillMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nParam1, int nParam2, int nParam3); // 0x004F3CE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit);                                              // 0x00623C60
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0
void __stdcall MISSILE_SetStreamMissile(D2UnitStrc* pMissile, int nStreamMissile);                          // 0x0064A4E0
void __stdcall MISSILE_SetStreamRange(D2UnitStrc* pMissile, short nStreamRange);                            // 0x0064A540
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline int SKILLS_GetSkillParamInline(int nSkillId, int nIndex)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    return !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[nIndex];
}

// build: context sub_004E1B10_FireAtTarget
int __fastcall sub_004E1B10_FireAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount || !&sgptDataTables->pMissilesTxt[nMissile])
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        tMissileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nSkillLevel);
    }
    return 1;
}

// 0x004E1D30
int __fastcall sub_004E1D30_FireVolley(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pInitFunc = sub_004E1C80_CltMissileInitDiabWall;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nInitArg = i;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
    return 1;
}

// 0x004E1E50
int __fastcall sub_004E1E50_ChargeFrames(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (nFrame > pSkillsTxtRecord->dwParam[3])
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pPath);
    if (pTarget && sub_00641530(pTarget, pUnit) <= 1)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[2])
    {
        int nVelocity = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) << 8;
        if (nVelocity <= 0x100)
        {
            nVelocity = 0x100;
        }

        const int nRate = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nVelocity, nRate, 100), ".\\SKILLS\\SkillsMon.cpp", 0x466);
        PATH_SetType(pPath, 1);
        D2Common_10142(pPath, pUnit, 0);
        SKILLS_SetFlags(pSkill, 1);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[3])
    {
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[4] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[5]);
    }
    return 1;
}

// 0x004E21D0
int __fastcall sub_004E21D0_MissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!sub_004648F0_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    const int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 3;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.dwFlags |= 4;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nVelocity = nVelocity;
    for (int i = 0; i < 64; ++i)
    {
        tMissileParams.nTargetX = gnRingOffsetX_006DBB68[i];
        tMissileParams.nTargetY = gnRingOffsetY_006DBC68[i];
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA690_ReplaceMotionFlag1With8(pMissile);
            sub_004DA6E0_SetMotionFlag20(pMissile, 0);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -6, 1);
            sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, 0, 0);
            sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 0x78);
        }
    }
    return 1;
}

// 0x004E2410
int __fastcall sub_004E2410_RepeatOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_00463990(SKILLS_GetParam2(pSkill), SKILLS_GetParam3(pSkill));
    if (!pTarget)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    const int nCount = SKILLS_GetParam1(pSkill) - 1;
    if (nCount <= 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nCount);
    UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[0]);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    return 1;
}

// 0x004E2530
int __fastcall sub_004E2530_SpreadTwoMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2021;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = nSkillId;
    sub_004C7480_SpawnMissileRing(pUnit, &tMissileParams, 2, 1);

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nMissile = nMissileB;
        sub_004C7480_SpawnMissileRing(pUnit, &tMissileParams, 4, 5);
    }
    return 1;
}

// 0x004E26C0
int __fastcall sub_004E26C0_StreamAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nStreamMissile = pSkillsTxtRecord->wCltMissileB;
    if (nStreamMissile < 0 || nStreamMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nStreamRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nTargetX;
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nY = nTargetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = 0xBF;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetStreamMissile(pMissile, nStreamMissile);
    MISSILE_SetStreamRange(pMissile, nStreamRange);
    return 1;
}

// 0x004E3590
int __fastcall sub_004E3590_FlankTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    const int nSubMissile = pMissilesTxtRecord->wSubMissile[0];
    if (nSubMissile < 0 || nSubMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    if (!sub_004C7B20(pUnit, nMissile))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    const int nDx = CLIENTS_GetUnitX(pUnit) - nX;
    const int nDy = CLIENTS_GetUnitY(pUnit) - nY;
    tMissileParams.nTargetX = nX - nDy;
    tMissileParams.nTargetY = nY + nDx;
    sub_004CD540_CreateMissile(&tMissileParams);
    tMissileParams.nTargetX = nX + nDy;
    tMissileParams.nTargetY = nY - nDx;
    sub_004CD540_CreateMissile(&tMissileParams);
    tMissileParams.nTargetX = 0;
    tMissileParams.nTargetY = 0;
    tMissileParams.dwFlags = 1;
    tMissileParams.nMissile = nSubMissile;
    sub_004CD540_CreateMissile(&tMissileParams);
    return 1;
}

// 0x004E39A0
int __fastcall sub_004E39A0_CheckTargetRoom(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }
    return 1;
}

// 0x004EC040
void __fastcall sub_004EC040_DescIfRecord(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (pArg && pSkillsTxtRecord && sub_004A89D0_SkillDescRec(pSkillsTxtRecord->nSkillId))
    {
        sub_004EA010_SkillDescLine(pUnit, pArg, pSkillsTxtRecord, nArg3, nArg4, nArg5, nArg6);
    }
}

// 0x004F0350
int __fastcall sub_004F0350_RequestMissile(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004CDB40_SubmitRequest(pUnit, nMissile, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, nArg);
    }
    return 1;
}

// 0x004F0710
int __fastcall sub_004F0710_SetParamTimes(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nParam0 = SKILLS_GetSkillParamInline(nSkillId, 0);
    const int nTime1 = SKILLS_GetSkillParamInline(nSkillId, 1) * 1000 / 25;
    const int nTime2 = SKILLS_GetSkillParamInline(nSkillId, 2) * 1000 / 25;
    const int nTime3 = SKILLS_GetSkillParamInline(nSkillId, 3) * 1000 / 25;
    sub_00476A80_SetTimedState(nParam0, nTime1, nTime2, nTime3);
    return 1;
}

// 0x004F0AB0
int __fastcall sub_004F0AB0_StartTimedState(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nArg);
    if (nDelay < 1)
    {
        nDelay = 1;
    }

    SKILLS_SetParam1(pSkill, sub_0044DA90_GetTick() + nDelay);
    if (!STATES_CheckState(pUnit, 0xC))
    {
        STATES_ToggleState(pUnit, 0xC, 1);
    }
    return 1;
}

// 0x004F0B50
int __fastcall sub_004F0B50_TimedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (sub_0044DA90_GetTick() > SKILLS_GetParam1(pSkill))
    {
        STATES_ToggleState(pUnit, 0xC, 0);
        return 0;
    }

    D2UnitStrc* pMissile = sub_004E31C0_CltDo(pUnit, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    sub_004DA000_ResetGfxMotion(pMissile);
    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    sub_004DA6E0_SetMotionFlag20(pMissile, 1);
    if (pUnit)
    {
        pUnit->dwFlags &= ~0x40;
    }
    return 1;
}

// 0x004F0CD0
int __fastcall sub_004F0CD0_RequestAtSkillPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    const int nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0 && nMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nMissileA, nX, nY, nSkillId, nSkillLevel);
        if (!pMissile)
        {
            return 0;
        }

        const short nSound = pSkillsTxtRecord->wPrgSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
        }
    }

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004CDB40_SubmitRequest(pUnit, nMissileB, nX, nY, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004F0E30
int __fastcall sub_004F0E30_MoveToSkillPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004CDB40_SubmitRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004F1120
int __fastcall sub_004F1120_MissileFromTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltMissileB < 0 || pSkillsTxtRecord->wCltMissileB >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    sub_004AF890(pTarget, 3, 0);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = pSkillsTxtRecord->wCltMissileB;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pOwner = pTarget;
    tMissileParams.pOrigin = pTarget;
    sub_004CD540_CreateMissile(&tMissileParams);
    return 1;
}

// 0x004F2450
int __fastcall sub_004F2450_StartStateList(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, 0xC))
    {
        const short nOverlay = pSkillsTxtRecord->wPrgOverlay;
        if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
        {
            sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
        }

        const short nSound = pSkillsTxtRecord->wPrgSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, 0, 0, 0, 0);
        }
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0xC);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x14, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            return 0;
        }

        SKILLS_SetParam1(pSkill, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, sub_004F2440_OnStateRemove);
        STATLIST_SetState(pStatList, 0xC);
        STATES_ToggleState(pUnit, 0xC, 1);
        return 1;
    }

    UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->nSeqInput - 1);
    pUnit->dwFrameCountPrecise = 0x800;
    D2COMMON_10476(pStatList, 7);
    return 1;
}

// 0x004F2790
int __fastcall sub_004F2790_StreamFromTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltMissileB < 0)
    {
        return 0;
    }

    const int nStreamRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetStreamMissile(pMissile, pSkillsTxtRecord->wCltMissileB);
        MISSILE_SetStreamRange(pMissile, nStreamRange);
    }
    return 1;
}

// 0x004F3530
int __fastcall sub_004F3530_LightAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRadius = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel) - 3;
    if (nRadius < 2)
    {
        nRadius = 2;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = 0xBF;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    sub_00464930_FreeLight(pMissile);
    D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pMissile, 1, 1, 0xFF, 0xFF, 0, 0);
    if (pLight)
    {
        sub_00474290(pLight, nRadius);
        pMissile->pLight = pLight;
    }

    MISSILE_SetStreamMissile(pMissile, nMissile);
    MISSILE_SetStreamRange(pMissile, nRadius);
    return 1;
}

// 0x004F3C80
int __fastcall sub_004F3C80_UseSkillParamsA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam1 = SKILLS_GetParam1(pSkill);
    const int nParam2 = SKILLS_GetParam2(pSkill);
    const int nParam3 = SKILLS_GetParam3(pSkill);
    return sub_004F3A60(pUnit, nSkillId, nSkillLevel, nParam1, nParam2, nParam3);
}

// 0x004F3E50
int __fastcall sub_004F3E50_UseSkillParamsB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam1 = SKILLS_GetParam1(pSkill);
    const int nParam2 = SKILLS_GetParam2(pSkill);
    const int nParam3 = SKILLS_GetParam3(pSkill);
    return sub_004F3CE0_CreateSkillMissiles(pUnit, nSkillId, nSkillLevel, nParam1, nParam2, nParam3);
}

// 0x004F3EB0
int __fastcall sub_004F3EB0_CheckTargetRoom(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }
    return 1;
}

// 0x004F4610
int __fastcall sub_004F4610_MissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1)
    {
        const short nMissileB = pSkillsTxtRecord->wCltMissileB;
        if (nMissileB >= 0)
        {
            nMissile = nMissileB;
        }
    }

    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    int nDx = nX - CLIENTS_GetUnitX(pUnit);
    int nDy = nY - CLIENTS_GetUnitY(pUnit);
    sub_004C5390_ScaleUpDirection(&nDx, &nDy);
    sub_004C53D0_ScaleDownDirection(&nDx, &nDy);
    nX -= nDx * nCount / 2;
    nY -= nDy * nCount / 2;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x820;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nActivateFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = nX;
        tMissileParams.nTargetY = nY;
        sub_004CD540_CreateMissile(&tMissileParams);
        nX += nDx;
        nY += nDy;
    }
    return 1;
}
