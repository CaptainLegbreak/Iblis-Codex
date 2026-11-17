enum D2C_M11MeteorConstants
{
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    MONSTATS2FLAGINDEX_LARGE = 11,
};

struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};
struct D2MissilesTxt
{
    char unk0x00[0x24];
    short wHitSubMissile[4];
    char unk0x2C[0x20];
    int dwHitPar[2];
    char unk0x54[0x54];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char unk0xAE[0xF6];
};
struct D2SkillsTxt
{
    char unk0x00[0x64];
    unsigned int dwAuraRangeCalc;
    char unk0x68[0x1D4];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[26];
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
extern D2DataTablesStrc* sgptDataTables;                                                                      // 0x00744304
extern const int gnMeteorSubmissileOffsetsX_006E2550[18];                                                     // 0x006E2550
extern const int gnMeteorSubmissileOffsetsY_006E2598[18];                                                     // 0x006E2598
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                  // 0x00681EF0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00552FD0
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile);                                               // 0x0064A280
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                               // 0x0064A210
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);    // 0x0059FA30
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                    // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                    // 0x00648900
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                           // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                           // 0x0045AE20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel);                                   // 0x004CC7C0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                        // 0x0045C4B0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                    // 0x004638A0

static __forceinline D2MissilesTxt* MISSILE_GetMissilesTxtRecord_Inline(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return 0;
    }

    const int nMissileId = pMissile->dwClassId;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AAA90
static void __stdcall MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(D2GameStrc* pGame, int nMissileId, int nRange, int nStep, D2UnitStrc* pMissile)
{
    if (nMissileId < 0)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pMissile);
    const int nY = CLIENTS_GetUnitYInline(pMissile);

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    const int nSkill = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    if (nRange > 0)
    {
        missileParams.dwFlags = 0x8001;
        missileParams.nRange = nRange;
    }

    missileParams.nSkill = nSkill;
    missileParams.pOwner = pOwner;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 18; i += nStep)
    {
        missileParams.nX = nX + gnMeteorSubmissileOffsetsX_006E2550[i];
        missileParams.nY = nY + gnMeteorSubmissileOffsetsY_006E2598[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x005AC550
int __fastcall MISSMODE_SrvHit47_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int bValidTarget = 1;
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || !sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_LARGE)))
    {
        bValidTarget = 0;
    }

    if (bValidTarget)
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        int nResult = 1;

        D2DamageStrc damage = {};
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);

        int nRange = pMissilesTxtRecord->dwHitPar[0];
        if (nRange <= 0)
        {
            const int nSkillId = sub_0064A280(pMissile);
            const int nLevel = sub_0064A210(pMissile);
            D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
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

        damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
        damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

        if (!sub_6FD10200(pGame, pOwner, nX, nY, nRange, &damage, 0))
        {
            nResult = 3;
        }

        int nParam = pMissilesTxtRecord->dwHitPar[1];
        if (nParam < 1)
        {
            nParam = 1;
        }

        MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(pGame, pMissilesTxtRecord->wHitSubMissile[0], nRange, nParam, pMissile);
        return nResult;
    }

    return 2;
}
