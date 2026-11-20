#include "D2Common.h"
#include "D2Structs.h"
#include "D2Structs.h"

typedef int BOOL;
#define INVENTORY_SIGNATURE 0x1020304
#define ITEMTYPE_WEAPON 45

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

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0xC];
    D2CoordStrc tGameCoords;
};





struct D2ItemsTxt;
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo;                                                   // 0x0074479C
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo;                                                      // 0x007447B4
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0

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

static __forceinline unsigned int INVENTORY_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0

// build: context INVENTORY_GetGrid
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

    pInventory->pGrids = (D2InventoryGridStrc*)sub_0040B4B0(pInventory->pMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, 740, 0);
    memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
    pInventory->nGridCount = nInventoryGrid + 1;

    pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
    pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
    pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
    pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 747, 0);
    memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
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

// 0x0063C7F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
        if (pInventoryGrid && nSlotId >= 0 && nSlotId < BELT_SLOTS)
        {
            return pInventoryGrid->ppItems[nSlotId];
        }
    }

    return 0;
}

// 0x0063C9B0
BOOL __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, BOOL* pIsLeftHandItem)
{
    if (!pInventory)
    {
        return FALSE;
    }

    *pIsLeftHandItem = FALSE;

    D2UnitStrc* pLeftHandItem = INVENTORY_GetLeftHandWeapon(pInventory);

    D2UnitStrc* pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_RARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_WEAPON))
    {
        *ppItem = pItem;
        *pBodyLoc = BODYLOC_RARM;

        if (pItem == pLeftHandItem)
        {
            *pIsLeftHandItem = TRUE;
        }

        return TRUE;
    }

    pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_LARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_WEAPON))
    {
        *ppItem = pItem;
        *pBodyLoc = BODYLOC_LARM;

        if (pItem == pLeftHandItem)
        {
            *pIsLeftHandItem = TRUE;
        }

        return TRUE;
    }

    *ppItem = 0;
    return FALSE;
}

// 0x0063CAB0
BOOL __stdcall INVENTORY_HasBodyArmorEquipped(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pInventoryGrid)
        {
            D2UnitStrc* pItem = pInventoryGrid->ppItems[BODYLOC_TORSO];
            if (pItem && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_ARMOR))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

// build: context INVENTORY_GetEquippedItemByType
D2UnitStrc* __stdcall INVENTORY_GetEquippedItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem)
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
        if (ITEMS_CheckItemTypeId(pItem, nItemType) && INVENTORY_GetUnitXInline(pItem) < INVENTORY_GRID_X_LIMIT)
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}
