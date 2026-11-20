#include "D2Common.h"
#include "D2Structs.h"
#include "D2Structs.h"
#include "D2Txt.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
typedef int BOOL;
#define INVENTORY_SIGNATURE 0x1020304
#define NUM_BODYLOC 13
#define BODYLOC_LAST (13 - 1)
#define ITEMTYPE_ANY_SHIELD 51
#define STAT_QUANTITY 70
#define ITEMCODE_ISC ' csi'
#define ITEMCODE_TSC ' cst'

struct D2InventoryStrc;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    char unk0x04[0x10];
    D2UnitStrc* pNextGridItem;
};

struct D2ItemDataStrc
{
    char unk0x00[0x5C];
    D2ItemExtraDataStrc pExtraData;
};





extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo;                                                   // 0x0074479C
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo;                                                      // 0x007447B4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode);                           // 0x00621050
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                             // 0x00628A40
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

inline D2UnitStrc* INVENTORY_GetNextGridItemInline(D2UnitStrc* pItem)
{
    if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraInline(pItem))
    {
        return pItemExtraData->pNextGridItem;
    }

    return 0;
}

static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0

// build: context INVENTORY_GetGrid
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    D2InventoryGridStrc* pInventoryGrid;
    if (pInventory->nGridCount > nInventoryGrid)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }
        }
        else
        {
            if (!pInventoryGrid->ppItems)
            {
                pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
                pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
                pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC1, 0);
                memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
            }

            if (pInventoryGrid->nGridWidth != pInventoryGridInfo->nGridX || pInventoryGrid->nGridHeight != pInventoryGridInfo->nGridY)
            {
                return 0;
            }
        }
    }
    else
    {
        if (!pInventoryGridInfo)
        {
            return 0;
        }

        pInventory->pGrids = (D2InventoryGridStrc*)FOG_ReallocPool(pInventory->pMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, LINE_GRID_REALLOC, 0);
        memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
        pInventory->nGridCount = nInventoryGrid + 1;

        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
        pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
        pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC2, 0);
        memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
    }

    return pInventoryGrid;
}

static __forceinline D2UnitStrc* INVENTORY_GetBodyLocItemInline(D2InventoryStrc* pInventory, int nBodyLoc)
{
    D2UnitStrc* pItem;
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        pItem = 0;
    }
    else
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[nBodyLoc];
        }
    }

    return pItem;
}

// 0x0063C2F0
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if (ITEMS_AreStackablesEqual(pItem, pStackable) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063C8F0
BOOL __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (ppItem)
    {
        *ppItem = 0;
    }

    D2UnitStrc* pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_RARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_ANY_SHIELD))
    {
        if (ppItem)
        {
            *ppItem = pItem;
        }

        return TRUE;
    }

    pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_LARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_ANY_SHIELD))
    {
        if (ppItem)
        {
            *ppItem = pItem;
        }

        return TRUE;
    }

    return FALSE;
}

// 0x0063CB00
BOOL __stdcall INVENTORY_IsItemBodyLocFree(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc, int nInventoryRecordId)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && (unsigned int)nBodyLoc <= BODYLOC_LAST)
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pInventoryGrid)
        {
            D2UnitStrc* pBodyLocItem = pInventoryGrid->ppItems[nBodyLoc];
            if (pBodyLocItem && pItem)
            {
                int nFreeX;
                int nFreeY;
                return INVENTORY_GetFreePosition(pInventory, pBodyLocItem, nInventoryRecordId, &nFreeX, &nFreeY, 0) != 0;
            }
        }
    }

    return FALSE;
}

#include "gen/data/Source/D2Common/INVENTORY/Inventory_0063C2F0.inc"
