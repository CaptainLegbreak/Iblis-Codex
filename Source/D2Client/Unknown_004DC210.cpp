#include "D2Client.h"
#include "D2Structs.h"


typedef int (__fastcall* D2CltUnitEventFn)(int nType, D2UnitStrc* pUnit, int a3, int a4, int nParam1, int nParam2);

// 0x004DC210
int __fastcall sub_004DC210_RunCltUnitEvents(int nType, D2UnitStrc* pUnit, int a3, int a4)
{
    if (!pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        if (pEvent->nType == nType)
        {
            nResult = ((D2CltUnitEventFn)pEvent->nParam3)(nType, pUnit, a3, a4, pEvent->nParam1, pEvent->nParam2);
        }
        pEvent = pNext;
    }
    return nResult;
}
