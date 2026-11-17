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
    int unk0x04[7];
    D2SeedStrc tSeed;
    int unk0x28[1];
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004D2190
static void __stdcall sub_004D2190_SpawnRandomBolt(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int aOffsetX[4] = { 1, 0, -1, 0 };
    int aOffsetY[4] = { 0, 1, 0, -1 };

    const unsigned int nZ = SEED_RollRandomNumber(&pMissile->tSeed) % 125;
    const int nDirection = SEED_RollRandomNumber(&pMissile->tSeed) & 3;
    const int nUnitX = UNITS_GetUnitXPosition(pMissile);
    const int nUnitY = UNITS_GetUnitYPosition(pMissile);
    const int nX = nUnitX + aOffsetX[nDirection];
    const int nY = nUnitY + aOffsetY[nDirection];
    const int nDiffY = nY - nUnitY;
    const int nDiffX = nX - nUnitX;

    int nMissile;
    switch (SEED_RollRandomNumber(&pMissile->tSeed) % 30)
    {
    case 0:
        nMissile = 0x260;
        break;
    case 1:
        nMissile = 0x261;
        break;
    case 2:
        nMissile = 0x262;
        break;
    case 3:
        nMissile = 0x263;
        break;
    default:
        nMissile = 0x25F;
        break;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissile;
    tParams.nX = nX;
    tParams.nY = nY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nTargetX = nDiffY;
    tParams.nTargetY = -nDiffX;

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, nZ);
        MISSILE_SetTargetX(pNewMissile, UNITS_GetUnitXPosition(pMissile));
        MISSILE_SetTargetY(pNewMissile, UNITS_GetUnitYPosition(pMissile));
    }
}

// 0x004D2400
static void __stdcall sub_004D2400_SpawnRandomShard(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.pOwner = pOwner;

    int nTargetX = 20 - SEED_RollRandomNumber(&pMissile->tSeed) % 40;
    tParams.dwFlags = 2;
    tParams.pOrigin = pMissile;
    tParams.nTargetX = nTargetX;
    const int nTargetY = 20 - SEED_RollRandomNumber(&pMissile->tSeed) % 40;
    tParams.nTargetY = nTargetY;
    tParams.nMissile = 0x11D;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (!nTargetX && !nTargetY)
    {
        nTargetX = SEED_RollRandomNumber(&pMissile->tSeed) % 19 + 1;
        tParams.nTargetX = nTargetX;
    }

    D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&tParams);
    if (pNewMissile)
    {
        MISSILE_SetTargetX(pNewMissile, nTargetX);
        MISSILE_SetTargetY(pNewMissile, nTargetY);
        sub_004DA1D0_SetMotionVectorA(pNewMissile, 0, 0, -10);
    }
}

// 0x004D7710
void __fastcall sub_004D7710_CltDoSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pOwner)
    {
        sub_004D2190_SpawnRandomBolt(pOwner, pMissile);
        sub_004D2190_SpawnRandomBolt(pOwner, pMissile);

        if (nFrames > 60 && !(nFrames % 20))
        {
            sub_004D2400_SpawnRandomShard(pOwner, pMissile);
        }

        if (nFrames == 25)
        {
            int nY = UNITS_GetUnitYPosition(pMissile);
            int nX = UNITS_GetUnitXPosition(pMissile);
            sub_004CDB40_SubmitRequest(pOwner, 0x26A, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nY = UNITS_GetUnitYPosition(pMissile);
            nX = UNITS_GetUnitXPosition(pMissile);
            sub_004CDB40_SubmitRequest(pOwner, 0x269, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
