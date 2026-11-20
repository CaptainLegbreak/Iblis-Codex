#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define STAT_HITPOINTS 6
#define STAT_MANA 8
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2StaticPathStrc;



struct D2MissilesTxt
{
    char unk0x00[0x18];
    short wSubMissile[3];
    char unk0x1E[0x18];
    short wProgOverlay;
    int dwParam[5];
    char unk0x4C[0x34];
    unsigned int dwSrvCalc;
    char unk0x84[0x24];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char unk0xAE[0xF6];
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    char unk0x054[0x10];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0xD0];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A380
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
D2UnitStrc* __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops); // 0x005A9720
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath); // 0x006505C0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x00553490
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __fastcall sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel); // 0x0056D810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40


typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10
int __fastcall MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

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

// 0x005AFEC0
int __fastcall MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
    {
        int nMana = STATLIST_UnitGetStatValue(pOwner, STAT_MANA, 0) >> 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pOwner) >> 8;
        if (nMana < nMaxMana)
        {
            nMana += DATATBLS_ApplyRatio(nMaxMana, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
            if (nMana >= nMaxMana)
            {
                nMana = nMaxMana;
            }

            STATLIST_SetUnitStat(pOwner, STAT_MANA, nMana << 8, 0);

            if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
            {
                UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

// 0x005B04A0
int __fastcall MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCounter = 0;
    do
    {
        if (pMissilesTxtRecord->wSubMissile[nCounter] < 0 || pMissilesTxtRecord->dwParam[nCounter + 1] <= 0)
        {
            break;
        }

        ++nCounter;
    }
    while (nCounter < 3);

    if (nCounter <= 0)
    {
        return 2;
    }

    if (nFrames < pMissilesTxtRecord->dwParam[0])
    {
        return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
    }

    SEED_InitLowSeed(&pMissile->pSeed, CLIENTS_GetUnitXInline(pMissile));

    const int nIndex = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nCounter);
    if (nFrames % pMissilesTxtRecord->dwParam[nIndex + 1])
    {
        return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wSubMissile[nIndex];

    D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pSubMissile)
    {
        MISSMODE_SrvDmgHitHandler(pGame, pSubMissile, 0, 1);
    }

    return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
}
