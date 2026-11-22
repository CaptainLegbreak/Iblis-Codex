#include "D2MissileIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2TxtTables.h"

#define MONTYPEFLAG_LIGHTNINGUNIQUE 0x100
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;
union D2SeedStrc;
struct D2MonLvlTxt;
struct D2MonUModTxt;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

enum D2C_H16ElemConstants
{
    MONLVL_DM = 6,
    STAT_LEVEL = 12,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
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

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005A29A0
void __fastcall MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    static const int nYOffsets[] = { -1, 0, 1, 0 };                                                       // 0x006E2178
    static const int nXOffsets[] = { 0, 1, 0, -1 };                                                       // 0x006E2188

    if (!bUnique)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    const int nLastFrame = !pMonsterData ? 0 : pMonsterData->dwDurielFlag;

    int nFrameDiff = pGame->dwGameFrame - nLastFrame;
    if (nFrameDiff < 0)
    {
        nFrameDiff = -nFrameDiff;
    }

    if (nFrameDiff < 10)
    {
        pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~MONTYPEFLAG_LIGHTNINGUNIQUE;
        }
        return;
    }

    pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwDurielFlag = pGame->dwGameFrame;
    }

    pMonsterData = MONSTERUNIQUE_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nTypeFlag |= MONTYPEFLAG_LIGHTNINGUNIQUE;
    }

    int nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) / 2;
    if (nSkillLevel < 1)
    {
        nSkillLevel = 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetXPositionInline(pUnit);
    missileParams.nY = UNITS_GetYPositionInline(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = MISSILE_LIGHTUNIQUE;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    const int nBaseX = UNITS_GetXPositionInline(pUnit);
    const int nBaseY = UNITS_GetYPositionInline(pUnit);
    for (int i = 0; i < 4; ++i)
    {
        const int nX = nBaseX + nXOffsets[i];
        const int nY = nBaseY + nYOffsets[i];
        for (int j = 0; j < 2; ++j)
        {
            missileParams.nInitArg = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}
