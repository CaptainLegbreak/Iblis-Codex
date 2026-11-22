#include "D2Client.h"
#include "D2Structs.h"

#define D2ABS(x) ((x) < 0 ? -(x) : (x))

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260
int __fastcall sub_004DBF20_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY); // 0x004DBF20
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
void __fastcall sub_004785D0_SendShortShort(char nHeader, short nArg1, short nArg2); // 0x004785D0
void __fastcall sub_00463180_UpdatePathAndMove(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463180
int __stdcall D2Common_10230(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C60

__forceinline int CLIENT_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x004804E0
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY)
{
    if (!nX || !nY)
    {
        return;
    }
    if (sub_00464820_IsDeadOrDying(pUnit))
    {
        return;
    }

    pUnit->nLastClickX = nX;
    pUnit->nLastClickY = nY;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int bWarp = 0;
    const int nCurX = CLIENTS_GetUnitX(pUnit);
    const int nCurY = CLIENTS_GetUnitY(pUnit);
    int nTolerance;
    switch (nMode)
    {
    case 1:
        nTolerance = 10;
        break;
    case 2:
        nTolerance = 0;
        break;
    default:
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            switch (CLIENT_GetAnimModeInline(pUnit))
            {
            case 1:
                nTolerance = 3;
                break;
            case 3:
                nTolerance = 7;
                break;
            default:
                nTolerance = 5;
                break;
            }
            nTolerance += (sub_0044CE60_GetPing() + 50) >> 7;
        }
        else
        {
            nTolerance = 15;
            if (pUnit->dwUnitType == UNIT_MONSTER)
            {
                switch (CLIENT_GetAnimModeInline(pUnit))
                {
                case 3:
                case 4:
                case 5:
                    nTolerance = 5;
                    break;
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    nTolerance = 7;
                    break;
                }
            }
        }
        break;
    }

    int nDiffX = nX - nCurX;
    if (D2ABS(nDiffX) > nTolerance)
    {
        bWarp = 1;
    }
    int nDiffY = nY - nCurY;
    if (D2ABS(nDiffY) > nTolerance)
    {
        bWarp = 1;
    }

    if (bWarp)
    {
        if (!nMode && nTargetX > 0)
        {
            const int nDistance = PATH_ComputeSquaredDistance(nCurX, nCurY, nX, nY);
            if (nDistance < 100 && PATH_ComputeSquaredDistance(nCurX, nCurY, nTargetX, nTargetY) < nDistance)
            {
                bWarp = 0;
            }
        }
    }

    if (!bWarp)
    {
        const int nPixelX = UNITS_GetClientCoordX(pUnit);
        const int nPixelY = UNITS_GetClientCoordY(pUnit);
        int nScreenX = nX;
        int nScreenY = nY;
        DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
        if (nX != nCurX && nY != nCurY && !sub_004DBF20_HitTestUnitCel(pUnit, nPixelX, nPixelY) && !sub_004DBF20_HitTestUnitCel(pUnit, nScreenX, nScreenY))
        {
            bWarp = 1;
        }
        if (!bWarp)
        {
            return;
        }
    }

    D2ActiveRoomStrc* pNewRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pNewRoom)
    {
        pNewRoom = DUNGEON_FindRoomBySubtileCoordinates(gpAct_007A0634, nX, nY);
        if (!pNewRoom)
        {
            return;
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        sub_004785D0_SendShortShort(0x5F, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        sub_00463180_UpdatePathAndMove(pUnit, pNewRoom, nX, nY);
    }
    else
    {
        D2Common_10230(pUnit->pDynamicPath, pUnit, pNewRoom, nX, nY);
    }
}

