struct D2DynamicPathStrc;
struct D2GfxLightStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x34];
    D2GfxLightStrc* pLight;
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
    int unk0x38[5];
    int nParam4C;
    int unk0x50[3];
};

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2SkillsTxt
{
    char unk0x000[0x150];
    int nParam150;
    int nParam154;
    char unk0x158[0xE4];
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gaRing5OffsetX_006DB0EC[];                                                                 // 0x006DB0EC
extern const int gaRing5OffsetY_006DB0D8[];                                                                 // 0x006DB0D8
extern const int gaRing18OffsetX_006DB090[];                                                                // 0x006DB090
extern const int gaRing18OffsetY_006DB048[];                                                                // 0x006DB048

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004742D0_ResetLightSize(D2GfxLightStrc* pLight, int nRadius);                           // 0x004742D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                                         // 0x0064A210
int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                                         // 0x0064A280

// calling-convention shim (not game code)
__declspec(noinline) D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams)
{
    return sub_004639D0_GetOwnerUnit(pMissileParams->pOwner);
}

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

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int SKILLS_GetLevelBasedParam(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return (nLevel - 1) * pSkillsTxtRecord->nParam154 + pSkillsTxtRecord->nParam150;
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

// 0x004CF9B0
int __fastcall sub_004CF9B0_CltHitRingSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    if (!DATATBLS_GetSkillsTxtRecord(nSkill))
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x4001;
    tMissile.nSkill = nSkill;
    tMissile.nSkillLevel = nLevel;
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        const int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        for (int i = 0; i < nCount; ++i)
        {
            tMissile.nX = nX + gaRing5OffsetX_006DB0EC[i % 5];
            tMissile.nY = nY + gaRing5OffsetY_006DB0D8[i % 5];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        tMissile.dwFlags = 0x8001;
        tMissile.nParam4C = SKILLS_GetLevelBasedParam(nSkill, nLevel);
        tMissile.nX = nX;
        tMissile.nY = nY;
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
        if (pNew && pNew->pLight)
        {
            sub_004742D0_ResetLightSize(pNew->pLight, 0xC);
        }
    }

    tMissile.dwFlags = 0xC001;
    int nIndex = 0;
    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        nIndex = pMissilesTxtRecord->dwCltHitPar[1];
        for (int i = 0; i < nIndex; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX_006DB090[i % 18];
            tMissile.nY = nY + gaRing18OffsetY_006DB048[i % 18];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[3] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[3];
        const int nEnd = nIndex + pMissilesTxtRecord->dwCltHitPar[2];
        for (int i = nIndex; i < nEnd; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX_006DB090[i % 18];
            tMissile.nY = nY + gaRing18OffsetY_006DB048[i % 18];
            sub_004CD540_CreateMissile(&tMissile);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/004CF9B0_sub_004CF9B0_CltHitRingSubMissiles.inc"
