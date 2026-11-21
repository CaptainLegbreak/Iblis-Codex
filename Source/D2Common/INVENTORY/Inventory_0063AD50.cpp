#include "D2Common.h"
#include "D2Structs.h"
#include "D2Structs.h"
#include "D2ItemsWorld.h"

#define INVENTORY_SIGNATURE 0x1020304
#define ITEMTYPE_WEAPON 0x2D

struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2ItemDataStrc;
struct D2ItemExtraDataStrc;
struct D2InventoryNodeStrc;
struct D2InventoryGridStrc;
struct D2InventoryGridInfoStrc;






typedef int BOOL;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_CheckWeaponClass(D2UnitStrc* pItem, int nWeaponClass); // 0x00628950
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pExtraData;
    }

    return 0;
}

// 0x0063AD50
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return pItemExtraData->pParentInv == pInventory;
}

// 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstItem;
}

// 0x0063B2E0
D2UnitStrc* __stdcall INVENTORY_GetLastItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pLastItem;
}

// 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pCursorItem;
}

// 0x0063CBB0
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstNode;
}

// 0x0063CC30
int __stdcall INVENTORY_CheckForItemInTradeInventory(D2InventoryStrc* pInventory, int nItemId)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNode->pNext)
        {
            if (pNode->nItemId == nItemId)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0063CD60
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->dwItemCount;
}

// 0x0063D190
void __fastcall sub_0063D190_SetLeftItemGUID(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet)
{
    if (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE && pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const int nItemGUID = pItem->dwUnitId;
        if (bSet)
        {
            pInventory->dwLeftItemGUID = nItemGUID;
        }
        else if (pInventory->dwLeftItemGUID == nItemGUID)
        {
            pInventory->dwLeftItemGUID = D2UnitInvalidGUID;
        }
    }
}

// 0x0063D430
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerGuid)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        pInventory->dwOwnerGuid = nOwnerGuid;
    }
}

// 0x0063D450
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return D2UnitInvalidGUID;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return D2UnitInvalidGUID;
    }

    return pInventory->dwOwnerGuid;
}

// 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstCorpse;
}

// 0x0063D5F0
int __stdcall INVENTORY_GetCorpseCount(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->nCorpseCount;
}

// 0x0063E000
int __stdcall INVENTORY_GetItemGUID(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    return pItem->dwUnitId;
}

static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    D2InventoryGridStrc* pInventoryGrid;
    if (nInventoryGrid < pInventory->nGridCount)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }

            return pInventoryGrid;
        }

        if (!pInventoryGrid->ppItems)
        {
            pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
            pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
            pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 721, 0);
            memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
        }

        if (pInventoryGrid->nGridWidth != pInventoryGridInfo->nGridX || pInventoryGrid->nGridHeight != pInventoryGridInfo->nGridY)
        {
            return 0;
        }

        return pInventoryGrid;
    }

    if (!pInventoryGridInfo)
    {
        return 0;
    }

    pInventory->pGrids = (D2InventoryGridStrc*)FOG_ReallocPool(pInventory->pMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, 740, 0);
    memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
    pInventory->nGridCount = nInventoryGrid + 1;

    pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
    pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
    pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
    pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 747, 0);
    memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
    return pInventoryGrid;
}

static __forceinline D2UnitStrc* GetBodyItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (!pInventory || pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pGrid)
        return 0;
    return pGrid->ppItems[nBodyLoc];
}

// 0x0063BEF0
D2UnitStrc* __stdcall sub_0063BEF0_GetLeftWeapon(D2InventoryStrc* pInventory)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    if (pInventory->dwLeftItemGUID == -1)
        return 0;
    D2UnitStrc* pItem = GetBodyItem(pInventory, BODYLOC_LARM);
    if (pItem && sub_00629BB0_CheckItemType(pItem, 45) && (!pItem ? -1 : pItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pItem;
    pItem = GetBodyItem(pInventory, BODYLOC_RARM);
    if (pItem && sub_00629BB0_CheckItemType(pItem, 45) && (!pItem ? -1 : pItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pItem;
    return 0;
}

inline void INVENTORY_SetLeftItemGUIDInline(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet)
{
    if (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE && pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const int nItemGUID = pItem ? pItem->dwUnitId : D2UnitInvalidGUID;
        if (bSet)
        {
            pInventory->dwLeftItemGUID = nItemGUID;
        }
        else if (pInventory->dwLeftItemGUID == nItemGUID)
        {
            pInventory->dwLeftItemGUID = D2UnitInvalidGUID;
        }
    }
}

// 0x0063D2B0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return;
    }
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM)
    {
        return;
    }
    if (!ITEMSIsA(pItem, ITEMTYPE_WEAPON))
    {
        return;
    }
    INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    D2UnitStrc* pWeapon = 0;
    if (nBodyLoc == BODYLOC_RARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    }
    else if (nBodyLoc == BODYLOC_LARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    else
    {
        return;
    }
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pWeapon, 1);
    }
}

// 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return pItemExtraData->pNextItem;
}

// 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return pItem;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nUnitType == UNIT_ITEM ? pItem : 0;
}

// 0x0063E020
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return (char)pItemExtraData->nNodePosOther;
}

// 0x0063E070
D2UnitStrc* __stdcall INVENTORY_IsItemInInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (pInventory)
    {
        const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
        if (nUnitType == UNIT_ITEM)
        {
            if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem))
            {
                return pInventory == pItemExtraData->pParentInv ? pItem : 0;
            }
        }
    }

    return 0;
}
