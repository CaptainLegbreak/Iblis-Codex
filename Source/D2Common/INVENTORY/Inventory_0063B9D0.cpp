#include "D2Common.h"

#define TRUE 1
#define FALSE 0
#define UNIT_INVALID 6
#define INVGRID_BODYLOC 0
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

struct D2InventoryStrc;
struct D2ItemExtraDataStrc;
struct D2ItemDataStrc;
struct D2InventoryGridStrc;
struct D2InventoryGridInfoStrc;
struct D2ItemsTxt;

typedef int BOOL;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
};

struct D2ItemDataStrc
{
    char unk0x00[0x5C];
    D2ItemExtraDataStrc pExtraData;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2InventoryGridStrc
{
    D2UnitStrc* pItem;
    D2UnitStrc* pLastItem;
    unsigned char nGridWidth;
    unsigned char nGridHeight;
    unsigned short unk0x0A;
    D2UnitStrc** ppItems;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short unk0x02;
    int nGridRect[5];
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    D2InventoryGridStrc* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
    D2UnitStrc* pCursorItem;
    int dwOwnerGuid;
    int dwItemCount;
    char unk0x2C[0x14];
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x0063E1C0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C

inline D2UnitStrc* INVENTORY_UnitIsItemInline(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4) ? pItem : 0;
}

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == 0x1020304) ? pInventory : 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4 && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pExtraData;
    }

    return 0;
}

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return 0;
    }

    return pInventory->pFirstItem;
}

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != 4)
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

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return pItem;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nUnitType == 4 ? pItem : 0;
}

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

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner)
{
    if (!pMemPool && pOwner)
    {
        pMemPool = pOwner->pMemoryPool;
    }

    D2InventoryStrc* pInventory = (D2InventoryStrc*)sub_0040B430(pMemPool, sizeof(D2InventoryStrc), gszInventorySourceFile_006EA918, 0x22D, 0);
    if (!pInventory)
    {
        return 0;
    }

    memset(pInventory, 0, sizeof(D2InventoryStrc));
    pInventory->dwSignature = 0x1020304;
    pInventory->pMemPool = pMemPool;
    pInventory->pOwner = pOwner;
    if (pOwner)
    {
        pOwner->pInventory = pInventory;
        pInventory->dwOwnerGuid = pOwner->dwUnitId;
    }

    return pInventory;
}

// 0x0063B9D0
BOOL __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryRecordId, D2UnitStrc** ppExchangeItem, unsigned int* pHoveredItems, unsigned char nPage)
{
    *pHoveredItems = 0;

    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return FALSE;
    }

    if (nPage == 0xFF)
    {
        return FALSE;
    }

    if (nXPos < 0 || nYPos < 0)
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, 0x656);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + 2, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    BOOL bFree = TRUE;
    for (int nY = nYPos; nY < nYPos + nHeight; ++nY)
    {
        if (nY >= pInventoryGrid->nGridHeight)
        {
            bFree = FALSE;
            break;
        }

        for (int nX = nXPos; nX < nXPos + nWidth; ++nX)
        {
            if (nX >= pInventoryGrid->nGridWidth)
            {
                bFree = FALSE;
                break;
            }

            D2UnitStrc* pCurrentItem = pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth];
            if (pCurrentItem)
            {
                bFree = FALSE;
                if (*ppExchangeItem == pCurrentItem)
                {
                    break;
                }

                *ppExchangeItem = pCurrentItem;
                ++*pHoveredItems;
            }
        }
    }

    return bFree;
}

// 0x0063E100
static __declspec(noinline) BOOL INVENTORY_CopyUnitItemsToTradeInventory(D2InventoryStrc* pTradeInventory, D2UnitStrc* pUnit)
{
    if (!pTradeInventory)
    {
        return FALSE;
    }

    if (pTradeInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, 0, 1);
    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pTradeInventoryGrid = INVENTORY_GetGrid(pTradeInventory, 2, &tInventoryGridInfo);
    if (pTradeInventoryGrid && INVENTORY_GetPtrIfValid(pUnit->pInventory))
    {
        D2InventoryGridStrc* pUnitInventoryGrid = INVENTORY_GetGrid(pUnit->pInventory, 2, &tInventoryGridInfo);
        if (pUnitInventoryGrid && pUnitInventoryGrid->nGridWidth > 0 && pUnitInventoryGrid->nGridHeight > 0
            && pUnitInventoryGrid->nGridWidth == pTradeInventoryGrid->nGridWidth && pUnitInventoryGrid->nGridHeight == pTradeInventoryGrid->nGridHeight
            && pUnitInventoryGrid->ppItems && pTradeInventoryGrid->ppItems)
        {
            memcpy(pTradeInventoryGrid->ppItems, pUnitInventoryGrid->ppItems, sizeof(D2UnitStrc*) * pUnitInventoryGrid->nGridWidth * pUnitInventoryGrid->nGridHeight);
            return 1;
        }
    }

    return FALSE;
}

// build: context INVENTORY_CanItemBePlacedInInventory
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory)
{
    int nX;
    int nY;
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, 0, TRUE);
        D2InventoryGridInfoStrc tInventoryGridInfo;
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, 2, &tInventoryGridInfo);
        if (pInventoryGrid && INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, 0))
        {
            unsigned char nHeight;
            unsigned char nWidth;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, 0x16D5);

            if (nWidth && nHeight && nX >= 0 && nX + nWidth <= pInventoryGrid->nGridWidth && nY >= 0 && nY + nHeight <= pInventoryGrid->nGridHeight)
            {
                for (int y = nY; y < nY + nHeight; ++y)
                {
                    for (int x = nX; x < nX + nWidth; ++x)
                    {
                        pInventoryGrid->ppItems[x + y * pInventoryGrid->nGridWidth] = (D2UnitStrc*)-1;
                    }
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063E2E0
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInTradeInventory(D2UnitStrc* pPlayer2, D2InventoryStrc* pTradeInventory, D2UnitStrc* pPlayer1)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrentItem = INVENTORY_UnitIsItem(pItem);
        D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCurrentItem) == 2 && !INVENTORY_CanItemBePlacedInInventory(pPlayer2, pCurrentItem, pTradeInventory))
        {
            return FALSE;
        }

        pItem = pNextItem;
    }

    return 1;
}

// 0x0063E370
BOOL __stdcall INVENTORY_CanItemsBeTraded(void* pMemPool, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int* pTradeState)
{
    BOOL bResult = FALSE;
    D2InventoryStrc* pTradeInventory1 = INVENTORY_AllocInventory(pMemPool, 0);
    D2InventoryStrc* pTradeInventory2 = INVENTORY_AllocInventory(pMemPool, 0);

    if (pTradeInventory1 && pTradeInventory2 && INVENTORY_CopyUnitItemsToTradeInventory(pTradeInventory1, pPlayer1) && INVENTORY_CopyUnitItemsToTradeInventory(pTradeInventory2, pPlayer2))
    {
        if (!INVENTORY_CanItemBePlacedInTradeInventory(pPlayer2, pTradeInventory2, pPlayer1))
        {
            if (pTradeState)
            {
                *pTradeState = 0;
            }
        }
        else if (!INVENTORY_CanItemBePlacedInTradeInventory(pPlayer1, pTradeInventory1, pPlayer2))
        {
            if (pTradeState)
            {
                *pTradeState = 1;
            }
        }
        else
        {
            bResult = 1;
        }
    }

    INVENTORY_FreeInventory(pTradeInventory1);
    INVENTORY_FreeInventory(pTradeInventory2);
    return bResult;
}

inline BOOL INVENTORY_ValidateBodyLoc(int nBodyLoc)
{
    return nBodyLoc >= 0 && nBodyLoc < 13;
}

// 0x0063E490
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc)
{
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        return;
    }

    const BOOL bDualWield = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    if (*ppItem || !INVENTORY_ValidateBodyLoc(nBodyLoc))
    {
        return;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return;
    }

    if (nBodyLoc == BODYLOC_RARM)
    {
        if (bDualWield)
        {
            *ppItem = pInventoryGrid->ppItems[BODYLOC_LARM];
        }
    }
    else if (nBodyLoc == BODYLOC_LARM)
    {
        if (bDualWield)
        {
            *ppItem = pInventoryGrid->ppItems[BODYLOC_RARM];
        }
    }
}
