#include "D2Game.h"
#include "D2Structs.h"

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define UNIT_MONSTER 1
#define SKILLSFLAGINDEX_INTOWN 8
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2PathPointStrc;
struct D2SkillsTxt;
struct D2LevelsTxt;
struct D2SummonArgStrc;
struct D2ModeChangeStrc;


struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};


extern int gnChargedBoltTurnEvery_00741B0C; // 0x00741B0C
extern int gnChargedBoltTurnBase_00741B10; // 0x00741B10
extern const int gnDirectionOffsetY_006E328C[]; // 0x006E328C
extern const int gnDirectionOffsetX_006E32AC[]; // 0x006E32AC
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0
void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints); // 0x00648790
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pPath, D2PathPointStrc** ppPathPoints); // 0x006487D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, int nDistance); // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nFrame); // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[20];
    unsigned int dwHitClass;
    int unk0x64[3];
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0xB2];
    char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    unsigned char unk_C4[0x74];
    unsigned int dwCalc[4];
    int dwParam[4];
    char unk0x158[0x4D];
    unsigned char nSrcDam;
    char unk0x1A6[0x96];
};

struct D2LevelsTxt
{
    char unk0x00[0x4];
    unsigned char nTeleport;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0x114];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x4C];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647D00
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall sub_0056E210(D2UnitStrc* pUnit, int nArg); // 0x0056E210
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

D2UnitStrc* __fastcall sub_0059FA30_CreateMissile(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

static __forceinline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        nX = pUnit->pStaticPath->nX;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        nY = pUnit->pStaticPath->nY;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x005D4680
void __fastcall SKILLS_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    sub_00648E70_SetDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    int nStep = nRoll % 3 + *(volatile int*)&gnChargedBoltTurnBase_00741B10;
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection & 63);
        nX += gnDirectionOffsetX_006E32AC[nIndex];
        nY += gnDirectionOffsetY_006E328C[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnChargedBoltTurnEvery_00741B0C))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumber(pSeed) % 3 + *(volatile int*)&gnChargedBoltTurnBase_00741B10;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

#include "gen/data/Source/D2Game/SKILLS/SkillAss_005D4680.inc"

static __forceinline D2SkillsTxt* GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int GetSkillParamByLevel_Inline(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

static __forceinline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor <= (nMultiplier >> 4))
        {
            return nValue * (nMultiplier / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x005D54B0
static void __stdcall sub_005D54B0_KickDamage(D2GameStrc* pGame, D2DamageStrc* pDamage, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    sub_005D3AC0(pUnit, pDamage);
    pDamage->dwHitFlags |= 3;

    int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    nMinDamage += ApplyRatio_Inline(nMinDamage, pDamage->dwEnDmgPct, 100);
    nMaxDamage += ApplyRatio_Inline(nMaxDamage, pDamage->dwEnDmgPct, 100);

    int nMinKickDamage = 0;
    int nMaxKickDamage = 0;
    int nDamagePercent = pDamage->dwEnDmgPct;
    SKILLS_CalculateKickDamage(pUnit, &nMinKickDamage, &nMaxKickDamage, &nDamagePercent);

    nMinKickDamage <<= 8;
    nMaxKickDamage <<= 8;
    nMinKickDamage += ApplyRatio_Inline(nMinKickDamage, nDamagePercent, 100);
    nMaxKickDamage += ApplyRatio_Inline(nMaxKickDamage, nDamagePercent, 100);
    nMinKickDamage += nMinDamage;
    nMaxKickDamage += nMaxDamage;
    const int nRange = nMaxKickDamage - nMinKickDamage;
    unsigned int nRoll;
    SEED_ROLL_LIMITED_INLINE(&pUnit->pSeed, nRange, nRoll);
    pDamage->dwPhysDamage += nRoll + nMinKickDamage;

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pSecondaryWeapon = 0;
    if (pMainWeapon)
    {
        const int nBodyLoc = ITEMS_GetBodyLocation(pMainWeapon);
        pSecondaryWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, (nBodyLoc == 4) ? 5 : 4);
    }

    if (ITEMS_CheckItemTypeId(pMainWeapon, 0x2D) && ITEMS_CanBeEquipped(pMainWeapon) && STATLIST_GetOwner(pMainWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 0);
    }
    else
    {
        pMainWeapon = 0;
    }

    if (pSecondaryWeapon && pSecondaryWeapon != pMainWeapon && ITEMS_CheckItemTypeId(pSecondaryWeapon, 0x2D) && ITEMS_CanBeEquipped(pSecondaryWeapon) && STATLIST_GetOwner(pSecondaryWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
    }

    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, pDamage, 1, 0x80);
    sub_6FCF5870(pUnit, pDamage);

    if (pMainWeapon)
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 1);
    }
}

// 0x005D5880
static void __stdcall sub_005D5880_KickAttack(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecordArg, int nSkillLevel, int bKnockback, int nSkillId, D2UnitStrc* pUnit)
{
    D2DamageStrc damage;

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);

    if (damage.wResultFlags & 1)
    {
        if (bKnockback)
        {
            damage.wResultFlags |= 0x0C;
        }

        damage.dwEnDmgPct = GetSkillParamByLevel_Inline(nSkillId, nSkillLevel);

        sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    damage.dwHitClass = 1;

    unsigned char nSrcDam = pSkillsTxtRecordArg->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
}

// 0x005D5970
int __fastcall SKILLS_SrvSt24_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || !(pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId]))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0))
    {
        return 0;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) - 1;
    SKILLS_SetParam1(pSkill, nParam);
    sub_005D5880_KickAttack(pGame, pTargetUnit, pSkillsTxtRecord, nSkillLevel, nParam == 0, nSkillId, pUnit);
    return 1;
}

// 0x005D5A30
int __fastcall SKILLS_SrvDo042_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill) - 1;
    if (nParam < 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nParam);

    int bKnockback = 0;
    if (nParam <= 0)
    {
        int nChance = 100;
        const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        int nLevel = nSkillLevel + nTargetLevel - STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        nLevel = MIN(MAX(nLevel, 1), nSkillLevel);

        if (pTarget->dwUnitType == 0 || MONSTERS_GetHirelingTypeId(pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        }
        else if (MONSTERS_IsBoss(0, pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, 8))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }

        if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
        {
            bKnockback = 1;
        }
    }

    sub_005D5880_KickAttack(pGame, pTarget, pSkillsTxtRecord, nSkillLevel, bKnockback, nSkillId, pUnit);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    if (nParam > 0)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~0x40;
        }

        sub_0056E210(pUnit, 100);
    }

    return 1;
}

// 0x005D7850
int __fastcall SKILLS_SrvDo052_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom)
        {
            return 0;
        }

        pUnit->dwFlags &= ~0x40;

        int nX;
        int nY;
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (!pLevelsTxtRecord || pLevelsTxtRecord->nTeleport == 0 || (pLevelsTxtRecord->nTeleport == 2 && UNITS_TestCollisionByCoordinates(pUnit, nX, nY, 0x804)))
        {
            return 0;
        }

        sub_6FCBDFE0(pGame, pUnit, 0, nX, nY, 0, 0);
        return 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
        sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// build: context SEED_RollRandomNumberInline
static __forceinline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context SEED_RollLimitedRandomNumberInline
static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0045C3E0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInline(pSeed, nMax);
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
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
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005D5BF0
int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMissileId, int nCount, int nRange, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    SEED_InitLowSeed(&pUnit->pSeed, nX);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x420;
    tMissile.pOrigin = pUnit;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissileId;

    if (nCount <= 1 || nRange < 2)
    {
        tMissile.nTargetX = nX;
        tMissile.nTargetY = nY;
        sub_0059FA30_CreateMissile(pGame, &tMissile);
        return 1;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissile.nTargetX = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) + nX - nRange;
        tMissile.nTargetY = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) + nY - nRange;
        if (PATH_ComputeSquaredDistance(UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), tMissile.nTargetX, tMissile.nTargetY) >= 4)
        {
            sub_0059FA30_CreateMissile(pGame, &tMissile);
        }
    }

    return 1;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetUnitType_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x005D5E10
D2UnitStrc* __fastcall sub_005D5E10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nSpawnMode;
    const int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    int nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    const int nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    if (!nX || !nY)
    {
        nX = UNITS_GetXPositionInline(pUnit);
        nY = UNITS_GetYPositionInline(pUnit);
    }

    while (UNITS_GetUnitType_Inline(pUnit) == UNIT_MONSTER)
    {
        pUnit = AIGENERAL_GetMinionOwner(pUnit);
        if (!pUnit)
        {
            return 0;
        }
    }

    if ((!nX || !nY) && !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nMonsterId;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nAiSpecialState = 0;
    summonArg.dwFlags = 1;
    summonArg.pOwner = pUnit;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = nX;
    summonArg.pPosition.nY = nY;
    summonArg.nPetMax = nPetMax;

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    sub_6FCBDD30(pPet, 2, 1);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pPet, nSpawnMode, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    return pPet;
}

// build: context GetSkillParam3ById_Inline
static __forceinline int GetSkillParam3ById_Inline(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x005D7090
int __fastcall SKILLS_SrvSt27_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_6FD15470(pUnit, GetSkillParam3ById_Inline(nSkillId));

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (!(damage.wResultFlags & 1))
    {
        return 0;
    }

    sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}
