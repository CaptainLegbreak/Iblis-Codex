#include "D2Game.h"

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define MISSILE_LIGHTUNIQUE 195
#define MONTYPEFLAG_LIGHTNINGUNIQUE 0x100
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2StaticPathStrc;
struct D2MonsterDataStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2MonLvlTxt;
struct D2MonUModTxt;

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x06];
    int dwGameType;
    unsigned char unk_78[0x30];
    int dwGameFrame;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nTypeFlag;
    int dwDurielFlag;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char pad0x000[0x04];
    unsigned char nMissileFlags[4];
    unsigned char unk_08[0x44];
    int dwHitPar[3];
    char pad0x058[0x50];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char pad0x0AE[0xF6];
};

struct D2SkillsTxt
{
    char pad0x000[0x64];
    int dwAuraRangeCalc;
    char pad0x068[0x1D4];
};

struct D2DataTablesStrc
{
    char pad0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
    unsigned char unk_B78[0x20];
    D2SkillsTxt* pSkillsTxt;
    char pad0xB9C[0x04];
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0xAC];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[26];
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
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
    UNIT_MONSTER = 1,
    UNIT_MISSILE = 3,
    MONLVL_DM = 6,
    STAT_LEVEL = 12,
};

struct D2MonLvlTxt
{
    int nValues[10][3];
};

struct D2MonUModTxt
{
    char pad0x00[0x1C];
    int dwConstants;
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
            missileParams.pInitArgs = j;
            missileParams.nTargetX = nX;
            missileParams.nTargetY = nY;
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
}

// 0x005A9E10
int __fastcall MISSMODE_SrvHit44_ExplodingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (!nRange)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;

    if (sub_6FD10200(pGame, pOwner, nX, nY, nRange, &damage, 0))
    {
        return 1;
    }

    return 3;
}

static __forceinline D2MissilesTxt* MONUNIQUE_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static __forceinline D2MonLvlTxt* MONUNIQUE_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
        return &sgptDataTables->pMonLvlTxt[nLevel];
    return 0;
}

static __forceinline int MONUNIQUE_GetMonUModConstant_Inline(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nMonUModTxtRecordCount)
    {
        D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nIndex];
        if (pMonUModTxtRecord)
        {
            return pMonUModTxtRecord->dwConstants;
        }
    }
    return 0;
}

static __forceinline unsigned int MONUNIQUE_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static void __stdcall sub_005A21D0_ApplyElementalDamageStats(D2UnitStrc* pUnit, int nMinDamageStatId, int nMaxDamageStatId, int nLengthStatId, D2GameStrc* pGame)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = MONUNIQUE_GetMissilesTxtRecord_Inline(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[1] & gdwBitMasks[5])
            return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = MONUNIQUE_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
        return;

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    const int nMinDamage = MONUNIQUE_GetMonUModConstant_Inline(28) * nDamage / 100;
    const int nMaxDamage = MONUNIQUE_GetMonUModConstant_Inline(31) * nDamage / 100;

    D2StatListStrc* pStatList = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetStat(pStatList, nMaxDamageStatId, nMaxDamage, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, nMaxDamage, 0);
    }

    if (nLengthStatId == -1)
        return;

    const int nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetStat(pStatList, nLengthStatId, nLength, 0);
    else
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
}

// 0x005A3040
void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
        return;

    const unsigned int nRand = MONUNIQUE_RollSeed_Inline(&pUnit->pSeed) % 5;
    sub_005A21D0_ApplyElementalDamageStats(pUnit, gnUniqueElementalStats_006E21B8[nRand][0], gnUniqueElementalStats_006E21B8[nRand][1], gnUniqueElementalStats_006E21B8[nRand][2], pGame);
}

#include "gen/data/Source/D2Game/Unknown_005A29A0.inc"
