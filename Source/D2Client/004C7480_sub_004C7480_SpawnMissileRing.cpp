struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
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
    int unk0x38[7];
    void (__fastcall* pInitFunc)(D2UnitStrc*, int);
    int pInitArgs;
};

void __fastcall sub_004C7470_SetMissileDirection(D2UnitStrc* pMissile, int nDirection);                    // 0x004C7470
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

// 0x004C7480
void __fastcall sub_004C7480_SpawnMissileRing(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nRange, int nCount)
{
    int nDirection = SEED_RollRandomNumber(&pUnit->pSeed) & 3;
    const int nX = pMissileParams->nX;
    const int nY = pMissileParams->nY;
    for (int i = 0; i < nCount; ++i)
    {
        int nOffsetX;
        int nOffsetY;
        switch (nDirection)
        {
        case 0:
            nOffsetX = -16;
            nOffsetY = -16;
            break;
        case 1:
            nOffsetX = -16;
            nOffsetY = 16;
            break;
        case 2:
            nOffsetX = 16;
            nOffsetY = 16;
            break;
        case 3:
            nOffsetX = 16;
            nOffsetY = -16;
            break;
        default:
            nOffsetX = 0;
            nOffsetY = 0;
            break;
        }

        nDirection = (nDirection + 1) % 4;
        pMissileParams->nX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) - nRange + nX;
        pMissileParams->nY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) - nRange + nY;
        pMissileParams->nTargetX = pMissileParams->nX + nOffsetX;
        pMissileParams->nTargetY = pMissileParams->nY + nOffsetY;
        pMissileParams->pInitFunc = sub_004C7470_SetMissileDirection;
        pMissileParams->pInitArgs = nDirection << 4;
        sub_004CD540_CreateMissile(pMissileParams);
    }
}
