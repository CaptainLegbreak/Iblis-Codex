#include "D2Game.h"
#include "D2Structs.h"

struct D2StaticPathStrc { char unk_00[0x0C]; int nX; int nY; };
struct D2GameStrc { char unk_00[0xA8]; int dwGameFrame; };
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc*); // 0x00649180
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D910
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int, int); // 0x0046C140
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, int); // 0x005DE200
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

static __forceinline void AITACTICS_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    EVENT_SetEvent(pGame, pUnit, 2, nFrames + pGame->dwGameFrame, 0, 0);
}

// build: context CLIENTS_GetUnitX
__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

// build: context CLIENTS_GetUnitY
__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DE9D0
D2UnitStrc* __fastcall sub_005DE9D0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiControl, pDistance, pCombat);
    if (pTarget)
        return pTarget;
    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nX = CLIENTS_GetUnitX(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), nX, nY, nCollisionPattern, 0x40) && sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return 0;
    }
    AITACTICS_IdleInline(pGame, pUnit, 20);
    return 0;
}
