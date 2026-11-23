#include "D2Client.h"
#include "D2Structs.h"

#define D2ABS(x) ((x) < 0 ? -(x) : (x))


void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260
int __fastcall GFXUTIL_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY); // 0x004DBF20
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
extern D2DrlgActStrc* gpAct; // 0x007A0634
void __fastcall sub_004785D0_SendShortShort(char nHeader, short nArg1, short nArg2); // 0x004785D0
void __fastcall AUTOMAP_UpdatePathAndMove(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463180
int __stdcall D2Common_10230(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C60

inline int UNITS_GetFlag21Inl(D2UnitStrc* pUnit)
{
    return (pUnit->dwFlags >> 21) & 1;
}

// 0x004804A0
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    return D2Common_10142(pPath, pUnit, UNITS_GetFlag21Inl(pUnit));
}

__forceinline int CLIENT_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}
