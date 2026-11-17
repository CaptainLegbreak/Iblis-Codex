struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2DynamicPathStrc;
struct D2GfxLightStrc;
struct D2StaticPathStrc { int unk0x00[3]; int nXPos; int nYPos; };
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc pSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    int unk0x30[13];
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
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};
struct D2CltRateStrc
{
    int nThreshold;
    int nRate;
    int nValue;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern const D2CltRateStrc gaCltRates_006DB890[4];                                                           // 0x006DB890
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                     // 0x00463990
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7);
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                   // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                   // 0x00648900
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pUnit);                                                  // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pUnit);                                                  // 0x0064A280
extern "C" int __stdcall sub_0064A380(D2UnitStrc* pUnit);                                                  // 0x0064A380
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                       // 0x0064A710
extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);

static __forceinline unsigned int SEED_RollUnitSeedInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
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

// 0x004D6D40
void __fastcall sub_004D6D40_CltDoRateJitterSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380(pMissile);

    int i = 0;
    for (i = 0; i < 4; ++i)
    {
        if (nRemaining > gaCltRates_006DB890[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRates_006DB890[i].nRate == 0)
    {
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nMissile = 0x15F;
        sub_0064A280(pMissile);
        missileParams.nSkill = sub_0064A280(pMissile);
        missileParams.nSkillLevel = sub_0064A210(pMissile);

        for (int j = 0; j < gaCltRates_006DB890[i].nValue; ++j)
        {
            int nOffsetX = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetX < 0 ? -nOffsetX : nOffsetX) < 2)
                nOffsetX = 5;

            int nOffsetY = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetY < 0 ? -nOffsetY : nOffsetY) < 2)
                nOffsetY = 5;

            missileParams.nX = nX + 2 * nOffsetX;
            missileParams.nY = nY + 2 * nOffsetY;
            D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pSubMissile)
                MISSILE_SetTargetX(pSubMissile, sub_00451F50_GetUnitGUID(pMissile));
        }
    }

    if (nRemaining < 0x19)
        MISSILE_SetTargetX(pMissile, 3);
    else if (nRemaining < 0x4B)
        MISSILE_SetTargetX(pMissile, 2);

    if (nRemaining <= 1)
    {
        D2UnitStrc* pTarget = sub_00463990(sub_0064A780_targetValue(pMissile), 2);
        if (pTarget)
        {
            sub_00470390(pTarget, 0xB6, 3, 0, 0, 0, 0, 0);
            if (!pTarget->pLight)
                pTarget->pLight = sub_00474160_MakeLightEntry(pTarget, 2, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

#include "gen/data/Source/D2Client/004D6D40_sub_004D6D40_CltDoRateJitterSpawn.inc"
