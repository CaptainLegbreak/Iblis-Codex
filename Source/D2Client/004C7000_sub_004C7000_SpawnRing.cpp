struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern const int gaRingTargetY_006DABC0[64];                                                                // 0x006DABC0
extern const int gaRingTargetX_006DACC0[64];                                                                // 0x006DACC0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
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

// 0x004C7000
static void __stdcall sub_004C7000_SpawnRing(D2MissileStrc* pAltParams, D2MissileStrc* pParams)
{
    if (pAltParams)
    {
        for (int i = 0; i < 64; ++i)
        {
            if (SEED_RollRandomNumber(&pParams->pOwner->tSeed) % 6)
            {
                pParams->nTargetX = gaRingTargetX_006DACC0[i];
                pParams->nTargetY = gaRingTargetY_006DABC0[i];
                sub_004CD540_CreateMissile(pParams);
            }
            else
            {
                pAltParams->nTargetX = gaRingTargetX_006DACC0[i];
                pAltParams->nTargetY = gaRingTargetY_006DABC0[i];
                sub_004CD540_CreateMissile(pAltParams);
            }
        }
    }
    else
    {
        for (int i = 0; i < 64; ++i)
        {
            pParams->nTargetX = gaRingTargetX_006DACC0[i];
            pParams->nTargetY = gaRingTargetY_006DABC0[i];
            if (pParams->nMissile == 0xB0)
                pParams->dwFlags ^= 0x4000;
            sub_004CD540_CreateMissile(pParams);
        }
    }
}

// 0x004C70D0
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nAltMissile,
    int nSkill, int nSkillLevel, int nVelocity)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = UNITS_GetUnitXPosition(pUnit);
    tParams.nY = UNITS_GetUnitYPosition(pUnit);
    tParams.nMissile = nMissile;
    tParams.pOwner = pOwner;
    tParams.nSkill = nSkill;
    tParams.nSkillLevel = nSkillLevel;
    if (nVelocity)
    {
        tParams.dwFlags |= 4;
        tParams.nVelocity = nVelocity;
    }
    if (nAltMissile == -1)
    {
        sub_004C7000_SpawnRing(0, &tParams);
        return;
    }
    D2MissileStrc tAltParams = tParams;
    tAltParams.nMissile = nAltMissile;
    sub_004C7000_SpawnRing(&tAltParams, &tParams);
}

#include "gen/data/Source/D2Client/004C7000_sub_004C7000_SpawnRing.inc"
