#include "D2Game.h"
#include "D2Structs.h"


struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};


D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath);                                     // 0x00648C10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

#define SKILLITEM_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)

// 0x005FD850
int __fastcall SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nMask = PATH_GetFootprintCollisionMask(pUnit->pDynamicPath);
    for (int i = 0; i < 10; ++i)
    {
        unsigned __int64 lSeed;
        const int nX = nUnitX + SKILLITEM_ROLL_SEED(pSeed, lSeed) % 40 - 20;
        const int nY = nUnitY + SKILLITEM_ROLL_SEED(pSeed, lSeed) % 40 - 20;
        if (!COLLISION_CheckMaskWithPattern(pRoom, nX, nY, nCollisionPattern, nMask))
        {
            D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
            return 1;
        }
    }

    return 0;
}
