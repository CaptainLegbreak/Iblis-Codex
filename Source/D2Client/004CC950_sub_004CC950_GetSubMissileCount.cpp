struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2MissilesTxt
{
    char unk0x000[0x1E];
    short wSubMissile1;
    short wSubMissile2;
    short wSubMissile3;
    char unk0x024[0x34];
    int nParam1;
    int nParam2;
    int nParam3;
    char unk0x064[0x32];
    short wRange;
    char unk0x098[0x10C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x4];
    int nMissilesTxtRecordCount;
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
void __fastcall sub_004CE850(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame, int nCount); // 0x004CE850
void __fastcall sub_00476A80_StartTiming(int nArg1, int nArg2, int nArg3, int nArg4);                        // 0x00476A80
void __fastcall sub_004CECC0(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame);           // 0x004CECC0

static __forceinline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumberInline
static __forceinline int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

// 0x004CC950
static int sub_004CC950_GetSubMissileCount(D2MissilesTxt* pMissilesTxt, int nFrame)
{
    if (nFrame < 30)
    {
        return 1;
    }

    if (nFrame < 85)
    {
        return (nFrame - 15) / 4;
    }

    const int nRange = pMissilesTxt->wRange;
    const int nStart = nRange - 50;
    if (nFrame < nStart)
    {
        return 12;
    }

    if (nFrame < nRange)
    {
        return 12 - (nFrame - nStart) / 4;
    }

    return 1;
}

static D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 2;
    tMissile.nMissile = nMissile;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);

    const int nMax = 2 * nSpread + 1;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    tMissile.nTargetX = SEED_RollLimitedRandomNumberInline(pSeed, nMax) - nSpread;
    tMissile.nTargetY = SEED_RollLimitedRandomNumberInline(pSeed, nMax) - nSpread;
    int nX = tMissile.nTargetX;
    const int nY = tMissile.nTargetY;
    if (!nX && !nY)
    {
        nX = SEED_RollLimitedRandomNumber(pSeed, nSpread - 1) + 1;
        tMissile.nTargetX = nX;
    }

    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
    if (pNew)
    {
        MISSILE_SetTargetX(pNew, nX);
        MISSILE_SetTargetY(pNew, nY);
    }

    return pNew;
}

// 0x004D5310
void __fastcall sub_004D5310_CltDoSubMissiles(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pMissilesTxt->wSubMissile1 > 0 && nFrame > 10)
    {
        sub_004CE850(pOwner, pMissile, pMissilesTxt->wSubMissile1, nFrame, sub_004CC950_GetSubMissileCount(pMissilesTxt, nFrame));
    }

    const int nPeriod = pMissilesTxt->nParam1 < 1 ? 1 : pMissilesTxt->nParam1;
    if (pMissilesTxt->wSubMissile2 > 0 && !(nFrame % nPeriod))
    {
        sub_004CE530_SpawnSubMissile(pOwner, pMissilesTxt->wSubMissile2, 0x14, pMissile);
    }

    const int nParam = pMissilesTxt->nParam2;
    if (nParam > 0 && nFrame == 90)
    {
        const int nA = nParam / 3;
        const int nTimeA = nA * 25000 / 25;
        const int nTimeB = (nParam - 2 * nA) * 25000 / 25;
        sub_00476A80_StartTiming(8, nTimeA, nTimeB, nTimeA);
    }

    if (pMissilesTxt->wSubMissile3 > 0 && (unsigned int)(nFrame - 0x74) <= 0xC6)
    {
        sub_004CECC0(pOwner, pMissile, pMissilesTxt->wSubMissile3, nFrame);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
