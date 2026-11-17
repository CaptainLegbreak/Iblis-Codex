struct D2DynamicPathStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
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

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char pad0x000[0x4C];
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
    char pad0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char pad0xB9C[0x04];
    int nSkillsTxtRecordCount;
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

#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_LEVEL 12
#define MISSILE_LIGHTUNIQUE 195
#define MONTYPEFLAG_LIGHTNINGUNIQUE 0x100

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
void __fastcall SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int nArg);                             // 0x005C9290
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

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
