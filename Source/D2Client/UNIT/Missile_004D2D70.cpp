#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2DynamicPathStrc;
struct D2StatListStrc;
struct D2GfxLightStrc;




typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);
typedef int (__fastcall* CLTHITFUNC)(D2UnitStrc* pMissile, D2UnitStrc* pTarget);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" unsigned char gbChargeMissileMask_006CE270;                                                     // 0x006CE270
extern int gnCltHitFuncCount_0072A504;                                                                      // 0x0072A504
extern CLTHITFUNC gpfCltHitFuncs_0072A508[];                                                                // 0x0072A508

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00
void __fastcall sub_00474470_ReleaseLight(D2GfxLightStrc* pLight);                                          // 0x00474470
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900
void __fastcall sub_004CD380_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004CD380
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nMissileId, int nArg3, int nArg4, int nSkill, int nLevel); // 0x004CDBA0
int __stdcall sub_004DA110_GetMotionAX(D2UnitStrc* pUnit);                                             // 0x004DA110
int __stdcall sub_004DA130_GetMotionAY(D2UnitStrc* pUnit);                                             // 0x004DA130
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit);                                                  // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA640_SetMotionFlag1(D2UnitStrc* pUnit);                                              // 0x004DA640
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690
int __fastcall sub_004DC210_RunCltUnitEvents(int nType, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nArg);   // 0x004DC210
D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* pUnit);                                           // 0x00621150
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3E0(D2UnitStrc* pMissile);                                                         // 0x0064A3E0
void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                                   // 0x0064A400
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                           // 0x0064A470

static int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile);                                            // 0x004CD310

static __forceinline int UNITS_TestFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (pUnit)
    {
        return (pUnit->dwFlags >> nBit) & 1;
    }
    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __declspec(noinline) int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile);

// 0x004CD310
static int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(sub_0064A3E0(pMissile));

    if (!(pMissilesTxtRecord->nMissileFlags[0] & gbChargeMissileMask_006CE270))
        return nResult;
    const int nValue = STATLIST_UnitGetStatValue(pMissile, STAT_PIERCE_IDX, 0);
    if (nValue)
    {
        nResult = 2;
        STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nValue - 1, 0);
    }

    return nResult;
}

// 0x004D2D70
D2UnitStrc* __fastcall sub_004D2D70_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg)
{
    const int nMissileId = pMissile ? pMissile->dwClassId : -1;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    const int nSubMissile = (short)pMissilesTxtRecord->wExplosionMissile;
    D2UnitStrc* pSubMissile;
    int nResult = 3;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    pSubMissile = 0;
    if (pMissile)
    {
        if (pTarget)
        {
            if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pTarget, STATE_JUSTHIT))
                return 0;

            if (MISSILE_CheckUnitIfOwner(pMissile, pTarget))
                return 0;

            MISSILE_SetOwner(pMissile, pTarget);
            if (!UNITS_TestFlagBit(pTarget, 2))
                return 0;

            if (pOwner && !sub_00465C60_CheckUnitPair(pOwner, pTarget) && !pMissilesTxtRecord->nCollideFriend)
                return 0;
        }

        if (pOwner && pTarget && (pMissilesTxtRecord->nMissileFlags[0] & gbChargeMissileMask_006CE270) && (unsigned int)pOwner->dwUnitType <= 1)
        {
            if (STATES_CheckState(pOwner, STATE_PIERCE) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0))
                nResult = sub_004CD310_UseMissileCharge(pMissile);
        }

        if ((pTarget || bArg || pMissilesTxtRecord->nAlwaysExplode) && (nResult & 2))
        {
            if (pMissilesTxtRecord->nNextHit && pTarget)
            {
                const int nId = pTarget->dwUnitId;
                const int nType = pTarget->dwUnitType;
                D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 2, pMissilesTxtRecord->nNextDelay, nType, nId);
                if (pStatList)
                {
                    STATLIST_SetState(pStatList, STATE_JUSTHIT);
                    STATLIST_SetStatRemoveCallback(pStatList, sub_004CD380_StatRemoveCallback_ToggleStateOff);
                    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
                    STATES_ToggleState(pTarget, 0x56, 1);
                }
            }

            sub_004DC210_RunCltUnitEvents(0, pTarget, pMissile, 0);

            const short nCltHitFunc = pMissilesTxtRecord->wCltHitFunc;
            if (nCltHitFunc > 0 && nCltHitFunc < gnCltHitFuncCount_0072A504 && gpfCltHitFuncs_0072A508[nCltHitFunc])
            {
                if (!gpfCltHitFuncs_0072A508[nCltHitFunc](pMissile, pTarget))
                    return 0;
            }

            const short nHitSound = pMissilesTxtRecord->wHitSound;
            if (nHitSound >= 0)
                sub_004B9A00(nHitSound, pMissile, 0, 0, 0);

            if ((short)pMissilesTxtRecord->wExplosionMissile >= 0 && nSubMissile != -1)
            {
                pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
                if (pSubMissile)
                {
                    sub_004DA1D0_SetMotionVectorA(pSubMissile, sub_004DA110_GetMotionAX(pMissile), sub_004DA130_GetMotionAY(pMissile), sub_004DA150_GetMotionAZ(pMissile));
                    sub_004DA640_SetMotionFlag1(pSubMissile);
                    sub_004DA690_ReplaceMotionFlag1With8(pSubMissile);
                    if (pSubMissile->dwClassId != 0x92)
                        D2COMMON_10160_PathUpdateDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
                    else
                        D2COMMON_10160_PathUpdateDirection(pSubMissile->pDynamicPath, (unsigned char)SEED_RollLimitedRandomNumber(&pSubMissile->pSeed, 0x40));
                }
            }
        }

        if (pTarget && !pMissilesTxtRecord->nCollideKill)
            return 0;

        const short nProgSfx = pMissilesTxtRecord->wTravelSound;
        if (nProgSfx >= 0)
        {
            void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pMissile, nProgSfx);
            if (pUnitSfx)
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pMissile, 0);
        }

        D2GfxLightStrc* pLight = UNITS_ResetLightMap(pMissile);
        if (pLight)
            sub_00474470_ReleaseLight(pLight);

        if (nResult & 1)
        {
            const int bFlag = UNITS_TestFlagBit(pMissile, 0x15);
            const int nUnitType = pMissile->dwUnitType;
            const int nUnitId = pMissile->dwUnitId;
            if (bFlag)
            {
                sub_00465F00_RemoveServerSideUnit(nUnitId, nUnitType);
            }
            else
            {
                sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
            }
        }

        return pSubMissile;
    }

    return 0;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D2D70.inc"
