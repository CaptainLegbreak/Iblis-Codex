struct D2DynamicPathStrc;
struct Obj00648690;
struct Unit0064A210;
struct Unit0064A280;
struct Unit0064A300;

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

extern "C" const char gszMissileSourceFile_006DAEF4[];                                                      // 0x006DAEF4
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __fastcall sub_004DA5B0_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0
extern "C" int __stdcall sub_0064A210(Unit0064A210* pUnit);                                               // 0x0064A210
extern "C" int __stdcall sub_0064A280(Unit0064A280* pUnit);                                               // 0x0064A280
extern "C" int __stdcall sub_0064A300(Unit0064A300* pUnit);                                               // 0x0064A300
extern "C" void __stdcall sub_00648690(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4);       // 0x00648690
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath);                                            // 0x006486C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

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

// 0x004D2760
int __fastcall sub_004D2760_CltDoEightWaySpawn(D2UnitStrc* pMissile)
{
    const int nXOffsets[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    const int nYOffsets[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x58, 0, 0, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));

    for (int i = 0; i < 8; ++i)
    {
        const int nPosX = nXOffsets[i] + nX;
        const int nPosY = nYOffsets[i] + nY;
        D2UnitStrc* pChild = sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x59, 0, 0, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));
        if (pChild)
        {
            D2Common_10216(pChild->pDynamicPath, nPosX, nPosY, 0);
        }

        D2UnitStrc* pNew = sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x1A1, nPosX, nPosY, sub_0064A280((Unit0064A280*)pMissile), sub_0064A210((Unit0064A210*)pMissile));
        if (pNew)
        {
            int nFrames = sub_0064A300((Unit0064A300*)pNew);
            nFrames -= SEED_RollLimitedRandomNumber(&pMissile->tSeed, nFrames / 2);
            MISSILE_SetTotalFrames(pNew, nFrames);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            sub_00648690((Obj00648690*)pPath, SEED_RollLimitedRandomNumber(&pMissile->tSeed, PATH_GetVelocity(pPath)), (int)gszMissileSourceFile_006DAEF4, 0x1A6B);
            sub_004DA5B0_SetBallistic(pNew, 0x1E, nFrames);
        }
    }

    return 1;
}
