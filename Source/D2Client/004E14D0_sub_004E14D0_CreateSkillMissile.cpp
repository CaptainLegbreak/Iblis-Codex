struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2StaticPathStrc
{
    char unk0x00[0xC];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissileA;
    short wCltMissileB;
    char unk0x0EE[0x26];
    unsigned int dwCltCalc1;
    char unk0x118[0x20];
    unsigned int dwCltCalc2;
    char unk0x13C[0x100];
};

struct D2MissilesTxt
{
    char unk0x000[0x3C];
    int nRange;
    char unk0x040[0x5A];
    unsigned char nVel;
    char unk0x09B[0xDD];
    unsigned char nAnimLen;
    char unk0x179[0x2B];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

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

enum D2C_UnitTypes
{
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg);                                  // 0x00621780
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __fastcall sub_004E1970(D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit);                                   // 0x004E1970
extern const int gaMissileVelocityPair_006DBAA0[];                                                          // 0x006DBAA0
extern const int gaMissileVelocityCharged_006DBB38[];                                                       // 0x006DBB38

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

static int __stdcall sub_004E1400_SetMissileFrames(D2UnitStrc* pUnit, int nSkillLevel, D2UnitStrc* pMissile, int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        return 0;
    }

    int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc2, nSkillId, nSkillLevel);
    if (nFrames <= 0)
    {
        nFrames = pMissilesTxt->nRange + nSkillLevel - 1;
    }

    nFrames = nFrames > 1 ? (nFrames < 0xFF ? nFrames : 0xFF) : 1;

    PATH_SetNewDistance(pMissile->pDynamicPath, nFrames);
    sub_00621780_SetMissileArg(pMissile, (pMissilesTxt->nAnimLen << 8) / nFrames);
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);
    return 1;
}

// 0x004E14D0
static D2UnitStrc* __stdcall sub_004E14D0_CreateSkillMissile(const int* pVelocityTable, int nTargetX, int nTargetY, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x25;
    tMissile.pOwner = pUnit;
    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) > 0)
    {
        tMissile.dwFlags = 0x4025;
    }

    tMissile.nMissile = nMissileId;
    tMissile.nX = CLIENTS_GetUnitX(pUnit);
    tMissile.nY = CLIENTS_GetUnitY(pUnit);
    tMissile.nTargetX = nTargetX;
    tMissile.nTargetY = nTargetY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;

    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxt)
    {
        return 0;
    }

    tMissile.nVelocity = pMissilesTxt->nVel + pVelocityTable[SEED_RollLimitedRandomNumber(&pUnit->pSeed, 5)];
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissile);
    if (!pMissile)
    {
        return 0;
    }

    sub_004E1400_SetMissileFrames(pUnit, nSkillLevel, pMissile, nSkillId);
    return pMissile;
}

// 0x004E1620
int __fastcall sub_004E1620_SkillCltDoMissilePair(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissileA = pSkillsTxt->wCltMissileA;
    if (nMissileA < 0 || nMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    for (int nCount = 2; nCount; --nCount)
    {
        int nMissile = nMissileA;
        if (nMissileB > 0 && (SEED_RollRandomNumber(&pUnit->pSeed) & 1))
        {
            nMissile = nMissileB;
        }

        sub_004E14D0_CreateSkillMissile(gaMissileVelocityPair_006DBAA0, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    }

    return 1;
}

// 0x004E1A20
int __fastcall sub_004E1A20_SkillCltDoChargedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc1, nSkillId, nSkillLevel);
    const int nParam = SKILLS_GetParam1(pSkill) + 1;
    if (nParam < nMax)
    {
        SKILLS_SetParam1(pSkill, nParam);
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    sub_004E14D0_CreateSkillMissile(gaMissileVelocityCharged_006DBB38, nX, nY, nSkillId, nSkillLevel, pUnit, nMissile);
    sub_004E1970(pSkillsTxt, pUnit);
    return 1;
}

#include "gen/data/Source/D2Client/004E14D0_sub_004E14D0_CreateSkillMissile.inc"
