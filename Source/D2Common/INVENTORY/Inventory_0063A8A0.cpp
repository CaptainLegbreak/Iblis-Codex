#include "D2Common.h"

#define TRUE 1
#define FALSE 0
#define INVENTORY_SIGNATURE 0x1020304
#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define IMODE_ONGROUND 3
#define UNITFLAGEX_SERVERUNIT 0x4000000
#define INVGRID_BODYLOC 0
#define INVGRID_BELT 1
#define INVGRID_INVENTORY 2
#define NUM_BODYLOC 13
#define BELT_SLOTS 16
#define D2UnitInvalidGUID -1
#define UNIT_INVALID 6
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define NUM_GRID_BODYLOCS 11
#define WEAPONCLASS_1HS 2
#define WEAPONCLASS_1HT 3
#define WEAPONCLASS_HT1 12
#define COMPOSIT_RIGHTHAND 5
#define COMPOSIT_LEFTHAND 6
#define BELT_COLUMNS 4
#define BODYLOC_BELT 8
#define BELT_DEFAULT_TYPE 2
#define LINE_GETDIMENSIONS 2855
#define ITEMTYPE_BOOK 18
#define STAT_QUANTITY 70
#define INVENTORY_GRID_X_LIMIT 11
#define ITEMCODE_ISC 0x20637369
#define ITEMCODE_TSC 0x20637374
#define BODYLOC_TORSO 3
#define ITEMTYPE_ARMOR 3
#define ITEMTYPE_WEAPON 45

struct D2InventoryStrc;
struct D2InventoryNodeStrc;
struct D2ItemsTxt;
struct D2ItemExtraDataStrc;
struct D2ItemDataStrc;
struct D2InventoryGridStrc;
struct D2InventoryGridInfoStrc;
struct D2CorpseStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2InvRectStrc;
struct D2BeltsTxt;
struct D2Block1;

typedef int BOOL;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
    unsigned char nNodePos;
    unsigned char nNodePosOther;
    unsigned short unk0x0E;
    D2UnitStrc* pPreviousGridItem;
    D2UnitStrc* pNextGridItem;
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
    char unk0x18[0x2C - 0x14 - 4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    D2InventoryNodeStrc* pFirstNode;
    D2InventoryNodeStrc* pLastNode;
    D2CorpseStrc* pFirstCorpse;
    D2CorpseStrc* pLastCorpse;
    int nCorpseCount;
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo; // 0x007447B4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0
int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId); // 0x0063C600
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0
static __declspec(noinline) BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId); // 0x0063AFD0
static __declspec(noinline) unsigned char __stdcall INVENTORY_GetPlacementWeight(D2InventoryGridStrc* pInventoryGrid, int nXPos, int nYPos, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B340

struct D2CorpseStrc
{
    unsigned int unk0x00;
    unsigned int dwUnitId;
    unsigned int unk0x08;
    D2CorpseStrc* pNextCorpse;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_CheckWeaponClass(D2UnitStrc* pItem, int nWeaponClass); // 0x00628950
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pUnit); // 0x00629FE0
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pUnit); // 0x00628660
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

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

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2BeltsTxt
{
    unsigned char nIndex;
    unsigned char pad0x01[3];
    unsigned char nBoxes;
    unsigned char pad0x05[3];
    D2InvRectStrc beltBoxes[16];
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x131 - 0x80 - 4];
    unsigned char nAutoBelt;
};

struct D2Block1 { int n[6]; };

int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit); // 0x00621ED0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x00628A40
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0
void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord); // 0x00660CB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

inline D2UnitStrc* INVENTORY_UnitIsItemInline(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM) ? pItem : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraTyped(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM && pItem->pItemData)
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

// 0x0063A7E0
static __declspec(noinline) D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

// 0x0063A8A0
static __declspec(noinline) BOOL __stdcall sub_0063A8A0_CheckGridCellsFree(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int y = nY; y < nY + nItemHeight; ++y)
    {
        D2UnitStrc** ppRow = &pInventoryGrid->ppItems[y * pInventoryGrid->nGridWidth];
        for (int x = nX; x < nX + nItemWidth; ++x)
        {
            if (ppRow[x])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

// 0x0063A910
static __declspec(noinline) void __stdcall sub_0063A910_FillGridCells(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight, D2UnitStrc* pItem)
{
    for (int y = nY; y < nY + nItemHeight; ++y)
    {
        D2UnitStrc** ppRow = &pInventoryGrid->ppItems[y * pInventoryGrid->nGridWidth];
        for (int x = nX; x < nX + nItemWidth; ++x)
        {
            ppRow[x] = pItem;
        }
    }
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

// 0x0063AF20
static __declspec(noinline) void sub_0063AF20_LinkItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraTyped(pItem);
    if (!pItemExtraData)
    {
        return;
    }

    if (pInventory->pLastItem)
    {
        D2ItemExtraDataStrc* pLastItemExtraData = INVENTORY_GetItemExtraInline(pInventory->pLastItem);
        if (pLastItemExtraData)
        {
            pLastItemExtraData->pNextItem = pItem;
        }
    }
    else
    {
        pInventory->pFirstItem = pItem;
    }

    pItemExtraData->pPreviousItem = pInventory->pLastItem;
    pInventory->pLastItem = pItem;
    pItemExtraData->pParentInv = pInventory;
}

// 0x0063AF70
static __declspec(noinline) void __stdcall sub_0063AF70_LinkGridItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem)
{
    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraTyped(pItem);
    if (!pItemExtraData || pItemExtraData->pParentInv != pInventory)
    {
        return;
    }

    if (pInventoryGrid->pLastItem)
    {
        D2ItemExtraDataStrc* pLastItemExtraData = INVENTORY_GetItemExtraInline(pInventoryGrid->pLastItem);
        if (pLastItemExtraData)
        {
            pLastItemExtraData->pNextGridItem = pItem;
        }
    }
    else
    {
        pInventoryGrid->pItem = pItem;
    }

    pItemExtraData->pPreviousGridItem = pInventoryGrid->pLastItem;
    pInventoryGrid->pLastItem = pItem;
}

// build: context INVENTORY_PlaceItemInGrid
static __declspec(noinline) BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId)
{
    if (!pInventory || pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraInline(pItem);
    if (!pItemExtraData)
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, 869);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridStrc* pInventoryGrid;
    D2InventoryGridInfoStrc tInventoryGridInfo;
    if (nInventoryGrid >= INVGRID_INVENTORY)
    {
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
        if (nXPos < 0 || nXPos + nWidth > tInventoryGridInfo.nGridX || nYPos < 0 || nYPos + nHeight > tInventoryGridInfo.nGridY)
        {
            return FALSE;
        }

        pInventoryGrid = INVENTORY_GetGrid(pInventory, nInventoryGrid, &tInventoryGridInfo);
    }
    else
    {
        nWidth = 1;
        nHeight = 1;
        switch (nInventoryGrid)
        {
        case INVGRID_BODYLOC:
            pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
            break;

        case INVGRID_BELT:
            pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
            break;

        default:
            return FALSE;
        }
    }

    if (!pInventoryGrid)
    {
        return FALSE;
    }

    if (!sub_0063A8A0_CheckGridCellsFree(pInventoryGrid, nXPos, nYPos, nWidth, nHeight))
    {
        return FALSE;
    }

    const int nAnimMode = pItem ? pItem->dwAnimMode : 0;
    if (nAnimMode == IMODE_ONGROUND && UNITS_GetRoom(pItem))
    {
        if (sub_00463720_TestUnitFlagEx(pItem, UNITFLAGEX_SERVERUNIT))
        {
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), pItem->dwUnitType, pItem->dwUnitId);
        }

        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    INVENTORY_RemoveItem(pItem);
    sub_0063AF20_LinkItem(pInventory, pItem);
    sub_0063AF70_LinkGridItem(pInventory, pInventoryGrid, pItem);
    sub_0063A910_FillGridCells(pInventoryGrid, nXPos, nYPos, nWidth, nHeight, pItem);

    pItemExtraData->nNodePos = nInventoryGrid + 1;
    ++pInventory->dwItemCount;

    UNITS_SetXForStaticUnit(pItem, nXPos);
    UNITS_SetYForStaticUnit(pItem, nYPos);

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        ITEMS_SetOwnerId(pItem, pInventory->pOwner->dwUnitId);
    }
    else
    {
        ITEMS_SetOwnerId(pItem, D2UnitInvalidGUID);
    }

    if (nInventoryGrid >= INVGRID_INVENTORY)
    {
        ITEMS_SetInvPage(pItem, nInventoryGrid - INVGRID_INVENTORY);
    }

    switch (nInventoryGrid)
    {
    case INVGRID_BODYLOC:
        pItemExtraData->nNodePosOther = (nXPos >= 11) ? 4 : 3;
        break;

    case INVGRID_BELT:
        pItemExtraData->nNodePosOther = 2;
        break;

    default:
        pItemExtraData->nNodePosOther = 1;
        break;
    }

    return TRUE;
}

// build: context INVENTORY_PlaceItemInSocket
BOOL __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    if (!pInventory->pOwner)
    {
        return TRUE;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM)
    {
        return FALSE;
    }

    if (pInventory->pOwner->dwUnitType != nType)
    {
        return TRUE;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return FALSE;
    }

    INVENTORY_RemoveItem(pItem);
    sub_0063AF20_LinkItem(pInventory, pItem);

    UNITS_SetXForStaticUnit(pItem, pInventory->dwItemCount);
    UNITS_SetYForStaticUnit(pItem, 0);

    pItemExtraData->nNodePos = 0;
    pItemExtraData->nNodePosOther = 1;
    ++pInventory->dwItemCount;

    ITEMS_SetOwnerId(pItem, D2UnitInvalidGUID);
    return TRUE;
}

// 0x0063B300
static BOOL __stdcall INVENTORY_CanItemBePlacedAtPos(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (nItemWidth + nX > pInventoryGrid->nGridWidth || nItemHeight + nY > pInventoryGrid->nGridHeight)
    {
        return FALSE;
    }

    return sub_0063A8A0_CheckGridCellsFree(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
}

// build: context INVENTORY_GetPlacementWeight
static __declspec(noinline) unsigned char __stdcall INVENTORY_GetPlacementWeight(D2InventoryGridStrc* pInventoryGrid, int nXPos, int nYPos, unsigned char nItemWidth, unsigned char nItemHeight)
{
    int nResult = 0;

    if (nXPos > 0)
    {
        const int nLeftX = nXPos - 1;
        for (int y = nYPos; y < nYPos + nItemHeight; ++y)
        {
            if (pInventoryGrid->ppItems[nLeftX + y * pInventoryGrid->nGridWidth])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult = nItemHeight;
    }

    const int nRightX = nXPos + nItemWidth;
    if (nRightX < pInventoryGrid->nGridWidth)
    {
        for (int y = nYPos; y < nYPos + nItemHeight; ++y)
        {
            if (pInventoryGrid->ppItems[nRightX + y * pInventoryGrid->nGridWidth])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemHeight;
    }

    if (nYPos > 0)
    {
        for (int x = nXPos; x < nRightX; ++x)
        {
            if (pInventoryGrid->ppItems[x + (nYPos - 1) * pInventoryGrid->nGridWidth])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemWidth;
    }

    if (nYPos + nItemHeight < pInventoryGrid->nGridHeight)
    {
        for (int x = nXPos; x < nRightX; ++x)
        {
            if (pInventoryGrid->ppItems[x + (nYPos + nItemHeight) * pInventoryGrid->nGridWidth])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemWidth;
    }

    if (nResult >= 2 * (nItemHeight + nItemWidth))
    {
        nResult = 255;
    }

    return nResult;
}

// 0x0063B490
static __declspec(noinline) BOOL __stdcall INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    unsigned char nMax = 0;
    for (int nX = pInventoryGrid->nGridWidth - 1; nX >= 0; --nX)
    {
        for (int nY = pInventoryGrid->nGridHeight - 1; nY >= 0; --nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                const unsigned char nWeight = INVENTORY_GetPlacementWeight(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
                if (nWeight > nMax)
                {
                    nMax = nWeight;
                    *pFreeX = nX;
                    *pFreeY = nY;

                    if (nWeight == 255)
                    {
                        return TRUE;
                    }
                }
            }
        }
    }

    return nMax > 0;
}

// 0x0063B540
static __declspec(noinline) BOOL __stdcall sub_0063B540_FindFreePositionRightToLeft(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int nX = pInventoryGrid->nGridWidth - 1; nX >= 0; --nX)
    {
        for (int nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                *pFreeX = nX;
                *pFreeY = nY;
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063B5E0
static __declspec(noinline) BOOL __stdcall sub_0063B5E0_FindFreePositionHeight1(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return sub_0063B540_FindFreePositionRightToLeft(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B620
static __declspec(noinline) BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    int nX;
    int nY;
    unsigned char nMax = 0;
    for (nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
    {
        for (nX = 0; nX < pInventoryGrid->nGridWidth; ++nX)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                const unsigned char nWeight = INVENTORY_GetPlacementWeight(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
                if (nWeight > nMax)
                {
                    nMax = nWeight;
                    *pFreeX = nX;
                    *pFreeY = nY;

                    if (nWeight == 255)
                    {
                        return TRUE;
                    }
                }
            }
        }
    }

    return nMax > 0;
}

// 0x0063B6E0
static __declspec(noinline) BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int nX = 0; nX < pInventoryGrid->nGridWidth; ++nX)
    {
        for (int nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                *pFreeX = nX;
                *pFreeY = nY;
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063B790
static __declspec(noinline) BOOL __stdcall sub_0063B790_FindFreePositionHeight3(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B7D0
static __declspec(noinline) BOOL __stdcall sub_0063B7D0_FindFreePosition2x2(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B810
static __declspec(noinline) BOOL __stdcall sub_0063B810_FindFreePositionOther(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B850
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM || !INVENTORY_GetItemExtraInline(pItem))
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, 1452);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + INVGRID_INVENTORY, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    if (nHeight == 1)
    {
        return sub_0063B5E0_FindFreePositionHeight1(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    if (nHeight == 3 && nWidth <= 2)
    {
        return sub_0063B790_FindFreePositionHeight3(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    if (nHeight == 2 && nWidth == 2)
    {
        return sub_0063B7D0_FindFreePosition2x2(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    return sub_0063B810_FindFreePositionOther(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
}

// build: context INVENTORY_PlaceItemAtFreePosition
BOOL __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, BOOL bUnused, unsigned char nPage, const char* szFile, int nLine)
{
    int nX;
    int nY;
    if (!pInventory)
    {
        return FALSE;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return FALSE;
    }

    if (!INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, nPage))
    {
        return FALSE;
    }

    return INVENTORY_PlaceItemInGrid(pInventory, pItem, nX, nY, nPage + INVGRID_INVENTORY, nInventoryRecordId);
}

// 0x0063BCC0
BOOL __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryRecordId, BOOL bUnused, unsigned char nPage)
{
    if (!pInventory)
    {
        return FALSE;
    }

    return INVENTORY_PlaceItemInGrid(pInventory, pItem, nXPos, nYPos, nPage + INVGRID_INVENTORY, nInventoryRecordId);
}

// 0x0063BDB0
BOOL __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc)
{
    if (pInventory && nBodyLoc >= 0 && nBodyLoc < NUM_BODYLOC)
    {
        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nBodyLoc, 0, INVGRID_BODYLOC, 0);
    }

    return FALSE;
}

// 0x0063C4C0
static __declspec(noinline) BOOL sub_0063C4C0_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot)
{
    if (pInventory && INVENTORY_UnitIsItemInline(pItem) && nSlot >= 0 && nSlot < BELT_SLOTS)
    {
        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nSlot, 0, INVGRID_BELT, 0);
    }

    return FALSE;
}

// 0x0063C4F0
BOOL __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot)
{
    if (INVENTORY_UnitIsItemInline(pItem) && ITEMS_CheckIfBeltable(pItem))
    {
        unsigned char nHeight;
        unsigned char nWidth;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile_006EA918, 2731);
        if (nWidth == 1 && nHeight == 1)
        {
            return sub_0063C4C0_PlaceItemInBeltSlot(pInventory, pItem, nSlot);
        }
    }

    return FALSE;
}

// 0x0063C790
BOOL __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    int nFreeSlot = 0;
    if (!INVENTORY_GetFreeBeltSlot(pInventory, pItem, &nFreeSlot) || !pInventory || !INVENTORY_UnitIsItemInline(pItem))
    {
        return FALSE;
    }

    if (nFreeSlot < 0)
    {
        return FALSE;
    }

    if (nFreeSlot >= BELT_SLOTS)
    {
        return FALSE;
    }

    return INVENTORY_PlaceItemInGrid(pInventory, pItem, nFreeSlot, 0, INVGRID_BELT, 0);
}

// 0x0063CD80
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem)
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
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
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
        for (;;)
        {
            if (!pItem)
            {
                return 0;
            }

            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }

        D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
        pItem = pItemExtraData ? pItemExtraData->pNextGridItem : 0;
    }

    while (pItem)
    {
        if (ITEMS_CheckItemTypeId(pItem, nItemType))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063BCF0
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage)
{
}

// 0x0063D470
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int a3, int a4)
{
    if (!pInventory)
        return;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return;

    D2CorpseStrc* pLastCorpse = pInventory->pLastCorpse;
    D2CorpseStrc* pCorpse = (D2CorpseStrc*)FOG_AllocPool(pInventory->pMemPool, sizeof(D2CorpseStrc), gszInventorySourceFile_006EA918, 0xFEA, 0);
    pCorpse->unk0x00 = a4;
    pCorpse->dwUnitId = nUnitId;
    pCorpse->unk0x08 = a3;
    pCorpse->pNextCorpse = 0;

    pInventory->pLastCorpse = pCorpse;
    if (!pInventory->pFirstCorpse)
        pInventory->pFirstCorpse = pCorpse;
    else
        pLastCorpse->pNextCorpse = pCorpse;

    if (pCorpse->unk0x00)
        ++pInventory->nCorpseCount;
}

// 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage)
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
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + INVGRID_INVENTORY, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    if (nGridX >= 0 && nGridX <= pInventoryGrid->nGridWidth && nGridY >= 0 && nGridY <= pInventoryGrid->nGridHeight)
    {
        D2UnitStrc* pItem = pInventoryGrid->ppItems[nGridX + nGridY * pInventoryGrid->nGridWidth];
        if (pItem)
        {
            *pX = CLIENTS_GetUnitX(pItem);
            *pY = CLIENTS_GetUnitY(pItem);
            return pItem;
        }
    }

    return 0;
}

// 0x0063BE40
BOOL __stdcall INVENTORY_CheckEquipmentForWeaponByClass(D2InventoryStrc* pInventory, int nWeaponClass)
{
    if (!pInventory)
    {
        return FALSE;
    }

    D2UnitStrc* pItem;
    D2InventoryGridStrc* pInventoryGrid;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        pItem = 0;
    }
    else
    {
        pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[BODYLOC_LARM];
        }
    }

    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckWeaponClass(pItem, nWeaponClass))
    {
        return TRUE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        pItem = 0;
    }
    else
    {
        pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[BODYLOC_RARM];
        }
    }

    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckWeaponClass(pItem, nWeaponClass))
    {
        return TRUE;
    }

    return FALSE;
}

// 0x0063C050
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nComponent)
{
    int nInventoryGrid = INVGRID_BODYLOC;
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nInventoryGrid, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    {
        D2UnitStrc* pLeftHandItem = INVENTORY_GetLeftHandWeapon(pInventory);

        for (int i = 0; i < NUM_GRID_BODYLOCS; ++i)
        {
            D2UnitStrc* pItem = pInventoryGrid->ppItems[i];
            if (pItem)
            {
                const int nWeaponClass = ITEMS_GetWeaponClassId(pInventoryGrid->ppItems[i]);
                if (nWeaponClass == WEAPONCLASS_1HS || nWeaponClass == WEAPONCLASS_1HT || nWeaponClass == WEAPONCLASS_HT1)
                {
                    if (nComponent == COMPOSIT_LEFTHAND)
                    {
                        if (pItem != pLeftHandItem)
                        {
                            return pItem;
                        }
                    }
                    else if (nComponent == COMPOSIT_RIGHTHAND && pItem == pLeftHandItem)
                    {
                        return pItem;
                    }
                }
                else
                {
                    if (ITEMS_GetComponent(pItem) == nComponent)
                    {
                        return pItem;
                    }
                }
            }
        }
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

// 0x0063C560
BOOL __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pPotion)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nUnitType = pPotion ? pPotion->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return FALSE;
    }

    const int nClassId = pPotion->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord || pItemsTxtRecord->dwCode == ITEMCODE_ISC || pItemsTxtRecord->dwCode == ITEMCODE_TSC)
    {
        return FALSE;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    for (int i = 0; i < BELT_COLUMNS; ++i)
    {
        D2UnitStrc* pBeltItem = pInventoryGrid->ppItems[i];
        if (pBeltItem && ITEMS_ComparePotionTypes(pPotion, pBeltItem))
        {
            return TRUE;
        }
    }

    return FALSE;
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

// 0x0063CE60
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

// 0x0063D010
D2UnitStrc* __stdcall sub_0063D010_GetInventoryItemByCode(D2InventoryStrc* pInventory, int nItemCode, D2UnitStrc* pCheckItem)
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

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, &gBodyLocInventoryGridInfo);
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

// 0x0063E060
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}
