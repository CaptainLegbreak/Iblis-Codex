#include "D2Game.h"

struct D2StaticPathStrc;
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
    char unk0x28[0x4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};
struct D2StaticPathStrc
{
    char unk0x00[0xC];
    int nX;
    int nY;
};

enum D2C_M86WalkCloseToUnit
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    MONMODE_WALK = 2,
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

__forceinline int AI_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int AI_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DE200
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance)
{
    const int nTargetX = AI_GetUnitX(pUnit);
    const int nTargetY = AI_GetUnitY(pUnit);
    int nOffsetX;
    int nOffsetY;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetX = nMaxDistance;
        nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
    }
    else
    {
        nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, nMaxDistance);
        nOffsetY = nMaxDistance;
    }

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    if (AI_RollSeed(pSeed) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    return AITACTICS_MoveToTarget(pGame, pUnit, 0, MONMODE_WALK, nOffsetX + nTargetX, nOffsetY + nTargetY, 1, 0);
}
