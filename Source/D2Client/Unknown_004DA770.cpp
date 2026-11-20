#include "D2Structs.h"
#include "D2UnitData.h"


// 0x004DA770
unsigned char __fastcall sub_004DA770_GetMonComponentIndex(D2UnitStrc* pUnit, unsigned char nComponent)
{
    if (pUnit && pUnit->dwUnitType == 1 && nComponent < 16 && pUnit->pMonsterData)
        return pUnit->pMonsterData->nComponent[nComponent];
    return 0;
}
