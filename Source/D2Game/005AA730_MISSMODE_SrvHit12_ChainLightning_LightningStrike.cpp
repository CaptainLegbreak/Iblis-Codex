struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
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
    char pad0x058[0x50];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char pad0x0AE[0xD8];
    unsigned char nCollideKill;
    char pad0x187[0x1D];
};

struct D2SkillsTxt
{
    char pad0x000[0x50];
    int dwAuraFilter;
    char pad0x054[0x0C];
    int dwAuraLenCalc;
    int dwAuraRangeCalc;
    char pad0x068[0x1A];
    short wAuraTargetState;
    char pad0x084[0xB4];
    int dwCalc[4];
    char pad0x148[0xF4];
};

struct D2DataTablesStrc
{
    char pad0x000[0xC4];
    int nStatesTxtRecordCount;
    char pad0x0C8[0xA9C];
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
typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecord(int nSkillId);                                            // 0x0045C4B0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nRange, unsigned int nAuraFilter, int nUnitId, int a8); // 0x0056BD10
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005AA730
int __fastcall MISSMODE_SrvHit12_ChainLightning_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pPrevious;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 3;
    }

    if (!pUnit)
    {
        return 3;
    }

    const int nParam = MISSILE_GetTargetX(pMissile);
    if (nParam <= 1)
    {
        return 3;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 3;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    pPrevious = pUnit;
    pUnit = SKILLS_FindNextAuraTarget(pGame, pOwner, nX, nY, nRange, 0x88583, !pUnit ? -1 : pUnit->dwUnitId, 0);
    if (!pUnit)
    {
        return 3;
    }

    if (pUnit == pPrevious)
    {
        return 3;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pOwner;
    missileParams.pTarget = pUnit;
    missileParams.nMissile = pMissile->dwClassId;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pSubMissile)
    {
        MISSILE_SetTargetX(pSubMissile, nParam - 1);
    }

    return 3;
}
