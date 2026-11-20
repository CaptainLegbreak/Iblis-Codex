#include "D2Structs.h"
#include "D2ItemsWorld.h"
#ifdef MOVED_TEST
#define ITEM_GAP 20
#else
#define ITEM_GAP 16
#endif
inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

// 0x006282A0
unsigned char __stdcall sub_006282A0_GetCellOverlap(D2UnitStrc* pItem) {
 if(D2ItemDataStrc* pItemData=ITEMS_GetItemData(pItem)) return pItemData->nCellOverlap;
 return 0xFF;
}
