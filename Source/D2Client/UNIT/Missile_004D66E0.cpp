#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxt;







extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0
void __fastcall sub_004DA340(D2UnitStrc* pMissile); // 0x004DA340
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
extern "C" const char gszMissileFile_006DAEF4[]; // 0x006DAEF4
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

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

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
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
