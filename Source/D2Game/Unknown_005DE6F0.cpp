#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

enum
{
    MONMODE_WALK = 2,
};
struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};




struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct UnkAiStrc1
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
// build: context CLIENTS_GetUnitX
__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

// build: context CLIENTS_GetUnitY
__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x005DE6F0
int __fastcall AITACTICS_WalkAroundTargetWithScaledDistance(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nScale)
{
    const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    if (nDistance)
    {
        const int nXOffset = nScale * (CLIENTS_GetUnitX(pUnit) - nTargetX) / nDistance;
        const int nY = CLIENTS_GetUnitY(pUnit);

        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
        modeChange.nX = nTargetX + nXOffset;
        const int nYOffset = nScale * (nY - nTargetY) / nDistance;
        modeChange.nY = nTargetY + nYOffset;
        return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }

    return 0;
}
