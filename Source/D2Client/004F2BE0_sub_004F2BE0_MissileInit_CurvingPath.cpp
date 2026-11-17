struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[7];
    D2SeedStrc tSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

extern int gnChargedBoltTurnEvery_0072D98C;                                                                 // 0x0072D98C
extern int gnChargedBoltTurnBase_0072D990;                                                                  // 0x0072D990
extern const int gnDirectionOffsetY_006DC1E8[];                                                             // 0x006DC1E8
extern const int gnDirectionOffsetX_006DC208[];                                                             // 0x006DC208

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints);                           // 0x00648790
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pPath, D2PathPointStrc** ppPathPoints);                 // 0x006487D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, int nDistance);                           // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nFrames);                                   // 0x0064A2B0
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile);                                                 // 0x0064A300
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nFrame);                                   // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40

static __forceinline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        nX = pUnit->pStaticPath->nX;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        nY = pUnit->pStaticPath->nY;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x004F2BE0
void __fastcall sub_004F2BE0_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->tSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    sub_00648E70_SetDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    int nStep = nRoll % 3 + *(volatile int*)&gnChargedBoltTurnBase_0072D990;
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection & 63);
        nX += gnDirectionOffsetX_006DC208[nIndex];
        nY += gnDirectionOffsetY_006DC1E8[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnChargedBoltTurnEvery_0072D98C))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumber(pSeed) % 3 + *(volatile int*)&gnChargedBoltTurnBase_0072D990;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

#include "gen/data/Source/D2Client/004F2BE0_sub_004F2BE0_MissileInit_CurvingPath.inc"
