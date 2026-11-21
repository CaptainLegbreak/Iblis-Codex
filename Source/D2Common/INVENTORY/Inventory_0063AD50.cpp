#include "D2Common.h"
#include "D2Structs.h"
#include "D2ItemsWorld.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2ClientTypes.h"

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

struct D2UnitStrc;

struct D2ItemsTxt;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40

BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x0063E1C0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);

#define WEAPONCLASS_HT1 12

#define COMPOSIT_RIGHTHAND 5

#define STAT_QUANTITY 70

#define ITEMCODE_ISC 0x20637369

#define ITEMCODE_TSC 0x20637374

struct D2BeltsTxt
{
    unsigned char nIndex;
    unsigned char pad0x01[3];
    unsigned char nBoxes;
    unsigned char pad0x05[3];
    D2InvRectStrc beltBoxes[16];
};

struct D2Block1 { int n[6]; };

void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);

extern D2InventoryGridInfoStrc gBeltInventoryGridInfo;                                                      // 0x007447B4

int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit);                                                         // 0x00621ED0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80

unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pUnit);

int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                             // 0x00628A40

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pUnit);

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock);                       // 0x0065C1F0

void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord);                 // 0x00660CB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);

#define NUM_BODYLOC 13

#define BODYLOC_LAST (13 - 1)

#define ITEMTYPE_ANY_SHIELD 51

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

inline D2UnitStrc* INVENTORY_UnitIsItemInline(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4) ? pItem : 0;
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

// 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    D2InventoryGridInfoStrc* pInventoryGridInfo = 0;
    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pInventory->pOwner, 0, 1);
        sub_0065C1F0(nInventoryRecordId, 0, (D2Block1*)&tInventoryGridInfo);
        pInventoryGridInfo = &tInventoryGridInfo;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, pInventoryGridInfo);
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

// 0x0063C3B0
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pScrolls, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    D2InventoryGridInfoStrc* pInventoryGridInfo = 0;
    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pInventory->pOwner, 0, 1);
        sub_0065C1F0(nInventoryRecordId, 0, (D2Block1*)&tInventoryGridInfo);
        pInventoryGridInfo = &tInventoryGridInfo;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, pInventoryGridInfo);
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
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && ITEMS_GetSuffixId(pItem, 0) == ITEMS_GetSuffixId(pScrolls, 0) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063C600
BOOL __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return FALSE;
    }

    if (!ITEMS_CheckIfBeltable(pItem))
    {
        return FALSE;
    }

    unsigned char nHeight;
    unsigned char nWidth;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, LINE_GETDIMENSIONS);
    if (nWidth != 1 || nHeight != 1)
    {
        return FALSE;
    }

    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_BELT);
    int nBeltType = BELT_DEFAULT_TYPE;
    if (pBelt)
    {
        nBeltType = UNITS_GetBeltType(pBelt);
    }

    D2BeltsTxt tBeltsTxtRecord;
    DATATBLS_GetBeltsTxtRecord(nBeltType, 0, &tBeltsTxtRecord);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
    if (pInventoryGrid)
    {
        for (int i = 0; i < BELT_COLUMNS; ++i)
        {
            D2UnitStrc* pBeltItem = pInventoryGrid->ppItems[i];
            if (pBeltItem && ITEMS_ComparePotionTypes(pItem, pBeltItem))
            {
                for (int nId = i; nId < tBeltsTxtRecord.nBoxes; nId += BELT_COLUMNS)
                {
                    if (!pInventoryGrid->ppItems[nId])
                    {
                        *pFreeSlotId = nId;
                        return TRUE;
                    }
                }
            }
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (!pItemsTxtRecord || !pItemsTxtRecord->nAutoBelt)
        {
            return FALSE;
        }

        for (int i = 0; i < BELT_COLUMNS; ++i)
        {
            if (!pInventoryGrid->ppItems[i])
            {
                *pFreeSlotId = i;
                return TRUE;
            }
        }
    }

    return FALSE;
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

// 0x0063CF30
D2UnitStrc* __stdcall INVENTORY_GetEquippedItemByCode(D2InventoryStrc* pInventory, int nItemCode, D2UnitStrc* pCheckItem)
{
    int nClassId;
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    if (!DATATBLS_GetItemRecordFromItemCode(nItemCode, &nClassId))
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
        if ((!pItem ? -1 : pItem->dwClassId) == nClassId)
        {
            if (INVENTORY_GetUnitXInline(pItem) < INVENTORY_GRID_X_LIMIT)
            {
                return pItem;
            }
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
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

#include "gen/data/Source/D2Common/INVENTORY/Inventory_0063AD50.inc"
