#include "D2MissileIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2SkillsTxt;





extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int a3); // 0x00649970
extern "C" int __stdcall sub_0064A3B0(D2UnitStrc* pUnit); // 0x0064A3B0
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pUnit); // 0x0064A730
extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pUnit); // 0x0064A780
extern "C" void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pPath, unsigned short wA, unsigned short wB); // 0x00648AD0



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __fastcall SKILLS_RotateUnitDirection(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9060

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004D8260
void __fastcall sub_004D8260_CltDoMissileSpray(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames - nFrames / 3 * 3 == 0)
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 20 - 10;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 20 - 10;
        const int nX = UNITS_GetUnitXPosition(pMissile) + (SEED_RollRandomNumber(&pMissile->pSeed) & 1) - 1;
        const int nY = UNITS_GetUnitYPosition(pMissile) + (SEED_RollRandomNumber(&pMissile->pSeed) & 1) - 1;

        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        tParams.nTargetX = nX + nOffsetX;
        tParams.nTargetY = nY + nOffsetY;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = MISSILE_ANCIENT_DEATH_CLOUD;
        MISSILE_CreateClientMissile(&tParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D8400
void __fastcall sub_004D8400_CltDoRotateTarget(D2UnitStrc* pMissile)
{
    if (!(sub_0064A3B0(pMissile) % 2))
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nDX = nX - sub_0064A730_GetMissileTargetStatus(pMissile);
        int nDY = nY - sub_0064A780_targetValue(pMissile);
        PATH_SetTargetPos(pPath, nX + nDY, nY - nDX);
        D2Common_10142(pPath, pMissile, 0);
    }
    MISSILE_CltDoCommon(pMissile);
}
