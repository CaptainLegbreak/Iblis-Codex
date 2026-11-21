#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2Drlg.h"

struct D2StaticPathStrc;

struct D2MissilesTxt;

union D2SeedStrc;

struct D2MissileStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const int gnUnk_0072A33C[]; // 0x0072A33C

void __fastcall sub_004CDDB0(D2UnitStrc* pUnit, const int* pArg, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDDB0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40

D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nArg1, int nArg2, int nMissile);              // 0x004CE320

void __fastcall sub_004CE4B0_InitMotion(D2UnitStrc* pMissile);                                              // 0x004CE4B0

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

struct D2UnitStrc;

D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile);                                             // 0x0064A3B0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed);                                             // 0x00650E40

unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50

void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0

void __fastcall sub_004DA340(D2UnitStrc* pMissile); // 0x004DA340

extern "C" const char gszMissileFile_006DAEF4[]; // 0x006DAEF4

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

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

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
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

// 0x004D0920
int __fastcall sub_004D0920_HitCollisionBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    if (!COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), 3, 1))
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            sub_004CDDB0(pMissile, gnUnk_0072A33C, 3, pMissilesTxtRecord->dwParam[0], 0x19, 0x4B);
        }
    }

    return 1;
}

// 0x004D0FF0
int __fastcall sub_004D0FF0_HitCreateSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (!pUnit)
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0]);
        return 1;
    }

    return 0;
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D3630
void __fastcall sub_004D3630_CltDoCommon2(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
        {
            sub_004CD390_CltDoDefault(pMissile);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = pOwner;
        tParams.nX = nX;
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        D2MissilesTxt* pSubMissileTxtRecord = SKILLS_GetMissilesTxtRecord(tParams.nMissile);
        if (!pSubMissileTxtRecord)
        {
            sub_004CD390_CltDoDefault(pMissile);
            return;
        }

        const short nRange = pSubMissileTxtRecord->wRange;
        if (nRange)
        {
            tParams.dwFlags = 0x8021;
            tParams.nRange = nRange;
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] >= 0)
        {
            if (pMissilesTxtRecord->wCltSubMissile[2] >= 0)
            {
                switch (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 3))
                {
                case 0:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                    break;
                case 1:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[2];
                    break;
                }
            }
            else if (!SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2))
            {
                tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            }
        }

        const int nChance = pMissilesTxtRecord->dwCltParam[0];
        if (!nChance || SEED_RollLimitedRandomNumber(&pMissile->pSeed, nChance))
            tParams.dwFlags |= 0x4000;

        tParams.nTargetX = CLIENTS_GetUnitX(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            const int nPrecisionX = UNITS_GetPrecisionX(pMissile);
            const int nPrecisionY = UNITS_GetPrecisionY(pMissile);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetPrecisionX(pPath, nPrecisionX);
            PATH_SetPrecisionY(pPath, nPrecisionY);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}


// 0x004D4BB0
void __fastcall sub_004D4BB0_CltDoObjectSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nParam = pMissilesTxtRecord->dwCltParam[0];
    const int nEnd = nParam + 0x7D;
    if (nFrames < pMissilesTxtRecord->wRange - nParam && nFrames > nParam && pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        D2UnitStrc* pNew = sub_004CE320(pMissile, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->wCltSubMissile[0]);
        if (pNew)
        {
            sub_004CE4B0_InitMotion(pNew);
        }
    }

    if (nFrames < nEnd && nFrames > nParam)
    {
        D2UnitStrc* pUnit = UNITS_GetRoom(pMissile)->pUnitFirst;
        do
        {
            if (!pUnit)
                break;
            if (pUnit->dwUnitType == UNIT_OBJECT && (unsigned int)pUnit->dwClassId >= 0x11 && (unsigned int)pUnit->dwClassId < 0x16)
            {
                if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
                {
                    const int nLevel = MISSILE_GetLevel(pMissile);
                    D2UnitStrc* pNew = (D2UnitStrc*)sub_004CDB40_SubmitRequest(pOwner, pMissilesTxtRecord->wCltSubMissile[0], CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), MISSILE_GetSkill(pMissile), nLevel);
                    if (pNew)
                    {
                        sub_004CE4B0_InitMotion(pNew);
                    }
                }

                if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && !(nFrames % 8))
                {
                    int nTargetId = MISSILE_GetTargetX(pMissile);
                    D2UnitStrc* pTarget = nTargetId ? sub_00463990(nTargetId, 2) : 0;
                    if (!pTarget)
                    {
                        MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                    }
                    else
                    {
                        D2MissileStrc tMissile;
                        memset(&tMissile, 0, sizeof(tMissile));
                        tMissile.dwFlags = 0x421;
                        tMissile.pOwner = pOwner;
                        tMissile.nX = CLIENTS_GetUnitX(pUnit);
                        tMissile.nY = CLIENTS_GetUnitY(pUnit);
                        tMissile.nSkill = MISSILE_GetSkill(pMissile);
                        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
                        tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
                        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
                        sub_004CD540_CreateMissile(&tMissile);
                        if (!SEED_RollLimitedRandomNumber(&pTarget->pSeed, 4))
                        {
                            MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                        }
                    }
                }
            }
            pUnit = pUnit->ptRoomNext;
        } while (pUnit);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// build: context SKILLS_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D5C10
void __fastcall sub_004D5C10_CltDo_Volcano(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwCltParam[1];
    if (nAuraRange <= 0)
    {
        const int nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        nAuraRange = (nCalc >= 1) ? nCalc : 1;
    }

    int nFrames = pMissilesTxtRecord->dwCltParam[0];
    if (nFrames <= 0)
    {
        nFrames = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrames < 1)
        {
            nFrames = 1;
        }
    }

    const int nRemainingFrames = MISSILE_GetRemainingFrames(pMissile);
    if (nRemainingFrames > pMissilesTxtRecord->dwCltParam[2] && nRemainingFrames < pMissilesTxtRecord->dwCltParam[3] && !(nRemainingFrames % nFrames))
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed, MISSILE_GetTargetX(pMissile));
        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        nX += CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile) + SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
        sub_004CDC30(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, nX, nY, MISSILE_GetSkill(pMissile), nLevel, pMissilesTxtRecord->dwCltParam[4]);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

// 0x004D66E0
void __fastcall sub_004D66E0_CltDoFallingSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(0x17B);
    sub_004D1300_SpawnScattered(10, 0x17C, pMissile);
    if (nRemaining < pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[0] && nRemaining > pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[1])
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        if (pOwner)
        {
            const int nTargetX = CLIENTS_GetUnitX(pOwner) + SEED_RollLimitedRandomNumber(pSeed, 10) - 5;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.nTargetX = nTargetX;
            tParams.dwFlags = 0x20;
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nTargetY = SEED_RollLimitedRandomNumber(pSeed, 10) - 5 + CLIENTS_GetUnitY(pOwner);
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = 0x17E;
            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
            if (pNew)
            {
                int nRoll = SEED_RollLimitedRandomNumber(pSeed, 3);
                nRoll += 3;
                sub_004DA250(pNew, 0, 0, -nRoll, 1);
                sub_004DA5B0_SetBallistic(pNew, 0, 0xF);
                sub_004DA340(pNew);
            }
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D7E00
void __fastcall sub_004D7E00_CltDoStateTarget(D2UnitStrc* pMissile)
{
    D2UnitStrc* pStateUnit;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    const int nState = MISSILE_GetTargetY(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    unsigned int const tArg1 = MISSILE_GetTargetX(pMissile);
    pStateUnit = sub_004639B0_FindServerSideUnit(tArg1, 3);
    if (pStateUnit)
    {
        const int nNewState = MISSILE_GetTargetX(pStateUnit);
        if (nState != nNewState && nNewState >= 2 && !SEED_RollLimitedRandomNumber(pSeed, 25))
        {
            MISSILE_SetTargetY(pMissile, nNewState);
            switch (nNewState)
            {
            case 2:
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19DB);
                D2COMMON_10170_PathSetTargetPos(pPath, 0x3B1F, 0x170C);
                D2Common_10142(pPath, pMissile, 0);
                break;
            }
        }
        else if (nState == 0)
        {
            if (!(SEED_RollRandomNumber(pSeed) % 10))
            {
                MISSILE_SetTargetY(pMissile, 1);
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19E6);
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 1, 1);
                    sub_004D30C0_CltDoCommon(pMissile);
                    return;
                }
            }
        }
        else if (nState == 1)
        {
            int nDX = CLIENTS_GetUnitX(pMissile) - CLIENTS_GetUnitX(pStateUnit);
            int nDY = CLIENTS_GetUnitY(pMissile) - CLIENTS_GetUnitY(pStateUnit);
            if (pMissile->dwUnitId & 2)
            {
                nDX = -nDX;
                nDY = -nDY;
            }
            if (nDX || nDY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDY, CLIENTS_GetUnitY(pMissile) + nDX);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D0920.inc"
