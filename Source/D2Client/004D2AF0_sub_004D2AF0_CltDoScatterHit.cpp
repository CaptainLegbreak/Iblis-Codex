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
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwMissileFlags;
    unsigned short wCltDoFunc;
    unsigned short wCltHitFunc;
    unsigned short wSrvDoFunc;
    unsigned short wSrvHitFunc;
    unsigned short wSrvDmgFunc;
    unsigned short wTravelSound;
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wCltSubMissile[3];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgSound;
    unsigned short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x1E];
    short wRange;
    char unk0x98[0x10C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return SKILLS_GetMissilesTxtRecordChecked(pUnit->dwClassId);
}

// 0x004D2AF0
int __fastcall sub_004D2AF0_CltDoScatterHit(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSeed = UNITS_GetXPosition(pMissile);
    SEED_InitLowSeed(&pMissile->tSeed, nSeed);
    const int nRange = pMissilesTxtRecord->dwCltHitPar[0] < 1 ? 1 : pMissilesTxtRecord->dwCltHitPar[0];
    const int nX = UNITS_GetXPosition(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);
    const int nTargetX = nX - nRange + SEED_RollLimitedRandomNumber(&pMissile->tSeed, 2 * nRange + 1);
    const int nTargetY = nY - nRange + SEED_RollLimitedRandomNumber(&pMissile->tSeed, 2 * nRange + 1);

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x20;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tParams.nTargetX = nTargetX;
    tParams.nTargetY = nTargetY;
    sub_004CD540_CreateMissile(&tParams);
    return 1;
}
