#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

enum D2C_Y10AiTacticsConstants
{
    MONMODE_NEUTRAL = 1,
    MONMODE_WALK = 2,
    EVENTTYPE_AITHINK = 2,
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

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall sub_6FCCFDE0(D2GameStrc* pGame, D2UnitStrc* pNPC, D2UnitStrc* pPlayer, void* pCallbackArg); // 0x005DDE80
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DDF20
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc* pGame, D2UnitStrc* pUnit, int* bCloseToTarget)
{
    if (!UNITS_GetRoom(pUnit))
    {
        return 0;
    }

    UnkAiStrc1 tCallbackArg;
    tCallbackArg.pTarget = 0;
    tCallbackArg.nDistance = 0x7FFFFFFF;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &tCallbackArg, sub_6FCCFDE0, 2);

    if (!tCallbackArg.pTarget)
    {
        return pUnit;
    }

    if (tCallbackArg.nDistance < 4)
    {
        *bCloseToTarget = 1;
    }

    return tCallbackArg.pTarget;
}

// 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    modeChange.pTargetUnit = pTargetUnit;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE080
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }

    if (!pUnit || pUnit->dwAnimMode != MONMODE_NEUTRAL)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        modeChange.pTargetUnit = pUnit;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

// 0x005DE0F0
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

// 0x005DE490
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesNoStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode)
{
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 0);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DE4E0
int __fastcall AITACTICS_MoveInRadiusToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int a5, int a6)
{
    int nSign = 1;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance < a6)
    {
        nSign = -1;
    }

    const int nDelta = nDistance - a6;
    int nDiff = nDelta < 0 ? -nDelta : nDelta;
    if (nDiff > a5)
    {
        nDiff = a5;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    int nXOffset = 0;
    int nYOffset = 0;

    int nXDiff = nTargetX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    const int nYDelta = nTargetY - nY;
    const int nYDiff = nYDelta < 0 ? -nYDelta : nYDelta;

    int nSum = nYDiff + nXDiff;
    if (nSum < nDiff)
    {
        nSum = nDiff;
    }

    if (nSum > 0)
    {
        nXOffset = nDiff * nXDiff / nSum;
        nYOffset = nDiff * nYDiff / nSum;
        while (nXOffset + nYOffset < nDiff)
        {
            nXOffset += 1;
            nYOffset += 1;
        }
    }

    int nSignX = 0;
    int nSignY = 0;
    if (nTargetX > nX)
    {
        nSignX = 1;
    }
    if (nTargetX < nX)
    {
        nSignX = -1;
    }
    if (nTargetY > nY)
    {
        nSignY = 1;
    }
    if (nTargetY < nY)
    {
        nSignY = -1;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.nX = nX + nSign * nXOffset * nSignX;
    modeChange.nY = nY + nSign * nYOffset * nSignY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DECA0
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);

    if (pTarget)
    {
        modeChange.pTargetUnit = pTarget;
    }
    else
    {
        modeChange.nX = 0;
        modeChange.nY = 0;
    }

    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005DED90
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}
