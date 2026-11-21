#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2GameAux.h"
#include "D2ItemsWorld.h"

struct D2StaticPathStrc;

struct D2MissilesTxt;

struct D2SkillsTxt;

struct D2HitFunc22ParamStrc;

struct D2AuraCallbackStrc;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

struct D2HitFunc22ParamStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkillId;
    int nLevel;
    int nParam;
    int nHitSubMissile;
};

typedef int(__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __fastcall sub_004F4110_GetSkillParam5(int nSkillId); // 0x004F4110

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget); // 0x005AB2A0

void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730

int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath); // 0x006505C0

typedef int (__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);

typedef void (__fastcall* MISSILESRVDMGFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern MISSILESRVHITFN gpfMissileSrvHitFn[]; // 0x0073C840

extern MISSILESRVDMGFN gpfMissileSrvDmgFn_0073C960[]; // 0x0073C960

void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD730

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0

int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30

void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);             // 0x00554DE0

int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900

D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops); // 0x005A9370

int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70

void __fastcall sub_005A8F20_SetElementalLength(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength); // 0x005A8F20

int __fastcall MISSMODE_SrvHit44_ExplodingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x005A9E10

int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep); // 0x005AB700

void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30

int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define STAT_HITPOINTS 6

#define EVENTTYPE_REMOVESTATE 12

enum D2C_Q05MissModeConstants
{
    EVENTTYPE_ENDANIM = 1,
};

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);      // 0x00644F20

void __fastcall sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nFrame, int nSkillId, int nSkillLevel); // 0x005C7DB0

int __fastcall MISSMODE_FistOfTheHeavensDelay_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget); // 0x005AB630

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780

static void __fastcall sub_005ADCD0_ApplyDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005ADCD0

static int sub_005ADA40_CheckMissileMode(int nMissileMode, D2UnitStrc* pUnit);

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

// 0x005A9720
void __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops)
{
    if (!sub_006505C0_TestPathFlag8(pOrigin->pDynamicPath))
    {
        return;
    }

    D2MissileStrc missileParams = {};

    missileParams.dwFlags = 5;
    if (nRange > 0)
    {
        missileParams.nRange = nRange;
        missileParams.dwFlags = 0x8005;
    }

    if (nLoops > 0)
    {
        missileParams.nLoops = nLoops;
        missileParams.dwFlags |= 8;
    }

    missileParams.pOwner = SUNIT_GetOwner(pGame, pOrigin);
    if (!missileParams.pOwner)
    {
        return;
    }

    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPositionInline(pOrigin);
    missileParams.nY = UNITS_GetYPositionInline(pOrigin);
    missileParams.nSkill = MISSILE_GetSkill(pOrigin);
    const int nLevel = MISSILE_GetLevel(pOrigin);
    missileParams.nLoops = 2 * (nLevel - 1);
    missileParams.nSkillLevel = nLevel;

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// build: symbol ?xOffsets@?L@??sub_005ABC40@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2938
// build: symbol ?xOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2738
// build: symbol ?yOffsets@?L@??sub_005ABC40@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2838
// build: symbol ?yOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2638
// 0x005A9A70
int __fastcall MISSMODE_SrvHit01_Fireball_ExplodingArrow_FreezingArrowExplosion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_6FD10200(pGame, pOwner, nX, nY, nParam, &damage, 0);
    return 1;
}

// 0x005A9BF0
int __fastcall MISSMODE_SrvHit24_PantherPotOrange(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_6FD10200(pGame, pOwner, nX, nY, nParam, &damage, 0);
    return 1;
}

// 0x005A9D80
int __fastcall MISSMODE_SrvHit02_PlagueJavelin_PoisonPotion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 3;
    }

    D2UnitStrc* pOrigin = pUnit;
    if (!pUnit)
    {
        pOrigin = pMissile;
    }

    MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, SUNIT_GetOwner(pGame, pMissile), pOrigin, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1], pMissilesTxtRecord->dwHitPar[2]);
    return 3;
}

// 0x005A9F90
int __fastcall MISSMODE_SrvHit03_ExplosivePotion_BombOnGround(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return MISSMODE_SrvHit44_ExplodingJavelin(pGame, pMissile, 0);
    }

    return 0;
}

// 0x005AA8B0
int __fastcall MISSMODE_SrvHit13_GlacialSpike_HellMeteorDown(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nLength = pMissilesTxtRecord->dwHitPar[1];
    if (nLength <= 0)
    {
        nLength = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);

    if (nLength > 0)
    {
        sub_005A8F20_SetElementalLength(pGame, pMissile, pUnit, &damage, nLength);
    }

    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

    if (sub_6FD10200(pGame, SUNIT_GetOwner(pGame, pMissile), nX, nY, nRange, &damage, 0))
    {
        return 1;
    }

    return 3;
}

// 0x005AAD40
int __fastcall MISSMODE_SrvHit15_SpiderGooLay(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pOwner;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    return 0;
}

// 0x005AAE10
int __fastcall MISSMODE_SrvHit16_SpiderGoo_VinesTrail_VinesWither(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nLength + pGame->dwGameFrame, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nLength + pGame->dwGameFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nLength + pGame->dwGameFrame, 0, 0);
    return 0;
}

// 0x005AB0B0
int __fastcall MISSMODE_SrvHit18_Shout_BattleCommand_BattleOrders(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pUnit && SUNIT_AreUnitsAligned(pGame, pOwner, pUnit))
    {
        SKILLS_ApplyWarcryStats(pGame, pUnit, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    return 0;
}

// 0x005AB110
int __fastcall MISSMODE_SrvHit19_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    const int nTimeout = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nTimeout, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nTimeout);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nTimeout, 0, 0);
    return 3;
}

// 0x005AB370
int __fastcall MISSMODE_SrvHit20_LightningFury(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwHitPar[0];
    if (nAuraRange <= 0)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nAuraRange < 1)
        {
            nAuraRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (!nAuraFilter)
    {
        nAuraFilter = 0xA783;
    }

    D2HitFunc22ParamStrc params;
    params.pOwner = pOwner;
    params.pOrigin = pMissile;
    params.nSkillId = nSkillId;
    params.nLevel = nLevel;
    params.nParam = nParam;
    params.nHitSubMissile = pMissilesTxtRecord->wHitSubMissile[0];

    sub_6FD0FE80(pGame, pOwner, nX, nY, nAuraRange, nAuraFilter, MISSMODE_LightningFury_AuraCallback, &params, 1, ".\\MISSILES\\MissMode.cpp", 3779);
    return 3;
}

// 0x005AB500
int __fastcall MISSMODE_SrvHit21_BattleCry(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (nAuraFilter)
    {
        nAuraFilter = 0xA783;
    }

    if (!sub_6FD0FA00(pOwner, pUnit, nAuraFilter))
    {
        return 1;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = 0;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (pStatList)
    {
        sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    }

    return 0;
}

// 0x005AB820
int __fastcall MISSMODE_SrvHit25_PantherPotGreen(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        pUnit = pMissile;
    }

    int nHitPar = pMissilesTxtRecord->dwHitPar[0];
    if (nHitPar < 1)
    {
        nHitPar = 1;
    }

    MISSMODE_CreatePantherPotGreenSubmissiles(pGame, pOwner, pUnit, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nHitPar);
    return 3;
}

// 0x005ABA10
int __fastcall MISSMODE_SrvHit28_GrimWardScare(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!SUNIT_GetOwner(pGame, pMissile))
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 1;
    }

    D2UnitStrc* pSubMissile = SUNIT_GetServerUnit(pGame, UNIT_MISSILE, MISSILE_GetTargetX(pMissile));
    if (!pSubMissile)
    {
        return 1;
    }

    const int nDistance = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nLevel);
    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitX(pSubMissile), CLIENTS_GetUnitY(pSubMissile), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) < nDistance * nDistance)
    {
        AIUTIL_ApplyTerrorCurseState(pGame, pSubMissile, pUnit, nSkillId, sub_004E6C70(nSkillId), sub_004F4110_GetSkillParam5(nSkillId));
    }

    return 1;
}

// 0x005ABB00
int __fastcall MISSMODE_SrvHit29_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (sub_0064A380_GetRemainingFrames(pMissile))
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABC40
int __fastcall sub_005ABC40(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABD70
int __fastcall MISSMODE_SrvHit31_FireHead(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    D2DamageStrc damage = {};
    const int nDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    const int nHeal = nDamage < 0 ? 0 : nDamage;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner);
    const int nHp = nHeal + STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    const int nNewHp = nHp < nMaxHp ? nHp : nMaxHp;
    STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nNewHp, 0);

    if (pMissilesTxtRecord->nCollideKill)
    {
        return 3;
    }

    return 2;
}

// 0x005ABEE0
int __fastcall MISSMODE_SrvHit35_OrbMist(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, MISSILE_GetTargetX(pMissile));
    if (!pObject)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    if (pRoom)
    {
        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    if (pObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pObject, 1);
        const int nClassId = pObject->dwClassId;
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (pObjectsTxtRecord)
        {
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_ENDANIM, pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
        }
    }

    return 1;
}

// 0x005ABF70
int __fastcall MISSMODE_SrvHit36_MissileInAir(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pUnit)
    {
        return 0;
    }

    D2UnitStrc* pHitSubMissile = D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    if (pHitSubMissile)
    {
        MISSILE_SetTargetX(pHitSubMissile, MISSILE_GetTargetX(pMissile));
    }

    return 1;
}

// 0x005AC0A0
int __fastcall MISSMODE_SrvHit38_CatapultChargedBall(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.pOwner = pOwner;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;

    int nCalc = pMissilesTxtRecord->dwHitPar[0] + pMissilesTxtRecord->dwHitPar[1] * (MISSILE_GetLevel(pMissile) - 1);
    if (nCalc <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nCalc < 1)
        {
            nCalc = 1;
        }
    }

    sub_6FD14260(pGame, nCalc, &missileParams);
    return 1;
}

// 0x005ACA50
int __fastcall MISSMODE_SrvHit53_RabiesContagion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nFrame = MISSILE_GetTargetX(pMissile) - pGame->dwGameFrame;
    if (nFrame < 10 || nFrame > SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1))
    {
        return 1;
    }

    sub_6FCFEDD0(pGame, pOwner, pUnit, nFrame, nSkillId, nLevel);
    return 2;
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005ADA40
static int sub_005ADA40_CheckMissileMode(int nMissileMode, D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    switch (nMissileMode)
    {
    case 0:
        return 0;
    case 1:
        if (nUnitType != 0)
            return 0;
        break;
    case 2:
        if (nUnitType != 1)
            return 0;
        break;
    case 3:
        return 1;
    }
    return 1;
}

static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if ((pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2]))
    {
        const int nPierce = STATLIST_UnitGetStatValue(pMissile, 0x148, 0);
        if (nPierce)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pMissile, 0x148, nPierce - 1, 0);
        }
    }
    return nResult;
}

static void __fastcall sub_005ADB00_SetJustHitState(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pTxt->nNextHit || !pUnit)
        return;

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pMissile);
    const int nDelay = pTxt->nNextDelay + pGame->dwGameFrame;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nDelay, pUnit->dwUnitType, pUnit->dwUnitId);
    if (!pStatList)
        return;

    EVENT_SetEvent(pGame, pUnit, 0xC, nDelay, 0, 0);
    STATLIST_SetState(pStatList, 0x56);
    STATLIST_SetStatRemoveCallback(pStatList, MISSMODE_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, 0x56, 1);
}

static void __fastcall sub_005ADCD0_ApplyDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    MISSMODE_SetDamageFlags(pGame, pMissile, pUnit, pDamage);
    if (pUnit && pUnit->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pUnit))
    {
        const int nDamageTargetAc = STATLIST_UnitGetStatValue(pMissile, 0x78, 0);
        if (nDamageTargetAc)
        {
            int nArmor = nDamageTargetAc + STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
            if (nArmor < 0)
                nArmor = 0;
            STATLIST_SetUnitStat(pUnit, 0x1F, nArmor, 0);
        }
    }
}

int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision)
{
    D2MissilesTxt* pTxt = 0;
    if (pMissile)
    {
        pTxt = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nHitResult = 2;
    int nPierceFlags = 3;
    if (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[1])
    {
        nHitResult = 0;
    }

    if (pUnit)
    {
        if ((pTxt->nNextHit && STATES_CheckState(pUnit, 0x56)) || MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        {
            return 1;
        }

        MISSILE_SetOwner(pMissile, pUnit);
        if (!sub_005ADA40_CheckMissileMode(!pMissile ? 0 : pMissile->dwMissileMode, pUnit))
        {
            return 1;
        }

        if (pOwner && !SUNIT_AreUnitsHostile(pGame, pOwner, pUnit) && !pTxt->nCollideFriend)
        {
            return 1;
        }
    }

    if (pOwner && pUnit && (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2])
        && (STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0)))
    {
        nPierceFlags = sub_005ADA80_GetPierceFlags(pMissile);
    }

    if (pTxt->nCollideKill)
    {
        nHitResult |= 1;
    }

    if (pUnit)
    {
        if (pTxt->nToHit)
        {
            int nToHit = 0;
            if (pMissile)
            {
                nToHit = STATLIST_UnitGetStatValue(pMissile, 0x13, 0);
            }

            if (!SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1))
            {
                sub_005ADB00_SetJustHitState(pMissile, pUnit);
                SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
                if (pTxt->nAlwaysExplode)
                {
                    const short nHitFunc = pTxt->wSrvHitFunc;
                    if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
                    {
                        if (gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit) & 4)
                        {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
    }
    else if (!bForceCollision && !pTxt->nAlwaysExplode)
    {
        if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
        {
            return 1;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
        }
        return 2;
    }

    if (nPierceFlags & 2)
    {
        sub_005ADB00_SetJustHitState(pMissile, pUnit);
        SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
        const short nHitFunc = pTxt->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            nHitResult = gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit);
            if (nHitResult & 4)
            {
                return 1;
            }
        }
    }

    if (pUnit && (nHitResult & 2))
    {
        D2DamageStrc tDamage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
        const short nDmgFunc = pTxt->wSrvDmgFunc;
        if (nDmgFunc > 0 && nDmgFunc < gnMissileSrvDmgFnCount_0073C95C)
        {
            gpfMissileSrvDmgFn_0073C960[nDmgFunc](pGame, pMissile, pUnit, &tDamage);
        }
        sub_005ADCD0_ApplyDamageFlags(pGame, pMissile, pUnit, &tDamage);
    }

    if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (pRoom)
    {
        COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
    }
    return 2;
}

static D2SkillsTxt* MISSMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005ADD20
int __fastcall sub_005ADD20(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (pMissile)
    {
        pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    }

    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);

    D2SkillsTxt* pSkillsTxtRecord = MISSMODE_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    pUnit = SUNIT_GetServerUnit(pGame, MISSILE_GetTargetX(pMissile), MISSILE_GetTargetY(pMissile));
    if (!pUnit)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwHitPar[0];
    if (nAuraRange <= 0)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nAuraRange < 1)
        {
            nAuraRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    D2DamageStrc tDamage;
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
    sub_005ADCD0_ApplyDamageFlags(pGame, pMissile, pUnit, &tDamage);

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (!nAuraFilter)
    {
        nAuraFilter = 0xA683;
    }

    D2HitFunc22ParamStrc params;
    params.pOwner = pOwner;
    params.pOrigin = pMissile;
    params.nSkillId = nSkillId;
    params.nLevel = nLevel;
    params.nHitSubMissile = pMissilesTxtRecord->wHitSubMissile[0];
    params.nParam = nParam;

    sub_6FD0FE80(pGame, pOwner, nX, nY, nAuraRange, nAuraFilter, MISSMODE_FistOfTheHeavensDelay_AuraCallback, &params, 0, ".\\MISSILES\\MissMode.cpp", 0xF65);
    return 1;
}
