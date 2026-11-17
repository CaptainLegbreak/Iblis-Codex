struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x10];
    unsigned int dwHitCalc;
    char unk0x08C[0x0A];
    short wRange;
    short wLevRange;
    char unk0x09A[0x10A];
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2CltHitPatternStrc
{
    int nCount;
    int aIndex[4];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gaCltHitOffsetX_006DAFC8[8];                                                               // 0x006DAFC8
extern const int gaCltHitOffsetY_006DAFE8[8];                                                               // 0x006DAFE8
extern const D2CltHitPatternStrc gaCltHitPatterns_006DB008[3];                                              // 0x006DB008
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                               // 0x0064A280
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                               // 0x0064A210
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __fastcall sub_004CDDB0(D2UnitStrc* pUnit, const int* pArg, int nArg1, int nArg2, int nArg3, int nArg4);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
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
        return pUnit->pStaticPath->nXPos;

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
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004CF500
int __fastcall sub_004CF500_CltHitSpawnSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int aSubMissiles[3];
    int nCount = 0;
    for (nCount = 0; nCount < 3; ++nCount)
    {
        const short nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[nCount];
        if (nSubMissile < 0)
        {
            break;
        }
        aSubMissiles[nCount] = nSubMissile;
    }

    if (nCount <= 0)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[0];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nMissileId = pMissile->dwClassId;
    int nRange = MISSILE_EvaluateMissileFormula(pMissile, sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwHitCalc, nMissileId, nLevel);
    if (nRange <= 0)
    {
        nRange = pMissilesTxtRecord->wRange + pMissilesTxtRecord->wLevRange * (nLevel - 1);
    }

    sub_004CDDB0(pMissile, aSubMissiles, nCount, nParam, nRange, pMissilesTxtRecord->dwCltHitPar[1]);
    return 1;
}

// 0x004CF640
int __fastcall sub_004CF640_CltHitPatternSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    const unsigned int nPattern = SEED_RollRandomNumber(&pMissile->tSeed) % 3;
    const int nOffset = SEED_RollRandomNumber(&pMissile->tSeed) & 7;
    for (int i = 0; i < gaCltHitPatterns_006DB008[nPattern].nCount; ++i)
    {
        const int nIndex = (gaCltHitPatterns_006DB008[nPattern].aIndex[i] + nOffset) & 7;
        D2UnitStrc* pSubMissile = sub_004CDBA0_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2Common_10216(pSubMissile->pDynamicPath, gaCltHitOffsetX_006DAFC8[nIndex] + nX, gaCltHitOffsetY_006DAFE8[nIndex] + nY, 0);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/004CF500_sub_004CF500_CltHitSpawnSubMissiles.inc"
