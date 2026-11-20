#include "D2Common.h"
#include "D2Structs.h"

#define UNIT_MONSTER 1


D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);    // 0x00625420

// 0x006259B0
int __stdcall sub_006259B0_GetStateStat(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    if (!pUnit->pStatListEx)
        return 0;
    if (pUnit->dwUnitType <= UNIT_MONSTER)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x69);
        if (!pStatList)
            return 0;
        return STATLIST_GetTotalStatValue(pStatList, 0xAC, 0);
    }
    return 2;
}
