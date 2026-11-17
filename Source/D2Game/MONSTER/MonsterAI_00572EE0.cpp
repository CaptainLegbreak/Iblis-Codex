#include "D2Game.h"

struct D2InteractionStrc
{
    D2UnitStrc* pUnit;
    int nState;
    D2InteractionStrc* pNext;
};
struct D2InteractionListStrc
{
    D2InteractionStrc* pFirst;
};
struct D2MonsterDataStrc
{
    char unk_00[0x30];
    D2InteractionListStrc* pInteractions;
};
struct D2UnitStrc
{
    int dwUnitType;
    char dwClassId[0x10];
    D2MonsterDataStrc* pMonsterData;
};
static __forceinline int GetUnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }
static __forceinline D2InteractionListStrc* GetInteractions(D2UnitStrc* pUnit)
{
    if (GetUnitType(pUnit) == 1)
    {
        D2MonsterDataStrc* pData = pUnit->pMonsterData;
        return !pData ? 0 : pData->pInteractions;
    }
    return 0;
}
// 0x00572EE0
int __fastcall sub_00572EE0_IsInteractionReady(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2InteractionListStrc* pList = GetInteractions(pUnit);
    D2InteractionStrc* pEntry = pList->pFirst;
    while (pEntry)
    {
        if (pEntry->pUnit == pTarget)
            return pEntry->nState == 2;
        pEntry = pEntry->pNext;
    }
    return 0;
}
