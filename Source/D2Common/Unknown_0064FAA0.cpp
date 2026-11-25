#include "D2Common.h"

#include "D2Structs.h"

#include "D2Path.h"




// 0x0064FAA0
static inline void PATHMISC_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pNewRoom)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->pPreviousRoom = pPath->pRoom;
    if (pPath->pRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    pPath->dwFlags |= 2;
    pPath->pRoom = pNewRoom;
    if (pNewRoom)
    {
        UNITROOM_AddUnitToRoom(pUnit, pNewRoom);
        UNITROOM_RefreshUnit(pUnit);
    }
}

void __stdcall sub_M130_Emit_0064FAA0(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pRoom)
{
    PATHMISC_SetRoom(pPath, pRoom);
}

#include "gen/data/Source/D2Common/Unknown_0064FAA0.inc"
