struct D2DynamicPathStrc;

enum D2C_P08MissHitConstants
{
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

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

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char pad0x000[0x24];
    short wHitSubMissile[4];
    char pad0x02C[0x20];
    int dwHitPar[3];
    char pad0x058[0x14C];
};

struct D2SkillsTxt
{
    char pad0x000[0x50];
    int dwAuraFilter;
    char pad0x054[0x0C];
    int dwAuraLenCalc;
    int dwAuraRangeCalc;
    char pad0x068[0xD0];
    int dwCalc[4];
    char pad0x148[0xF4];
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

struct D2HitFunc22ParamStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkillId;
    int nLevel;
    int nParam;
    int nHitSubMissile;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

typedef int(__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                     // 0x0045C4B0
int __fastcall sub_004E6C70(int nSkillId);                                                   // 0x004E6C70
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                            // 0x004E6CA0
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId);                                                   // 0x004F4110
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall sub_6FD14260(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams);              // 0x0056D4E0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget); // 0x005AB2A0
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x005AC040
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0

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
