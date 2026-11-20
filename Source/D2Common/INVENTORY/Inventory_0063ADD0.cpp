#include "D2Common.h"
#include "D2Structs.h"
#include "D2Structs.h"
#define INVENTORY_SIGNATURE 0x1020304
#define NUM_BODYLOC 13
#define ITEMTYPE_WEAPON 0x2D
#define ITEMTYPE_MISSILE_POTION 0x26
struct D2InventoryStrc;
struct D2ItemDataStrc;
struct Inventory;
struct ItemRecord;
struct AppearanceRecord;
struct ItemData;
struct ItemLink;
struct D2InventoryGridStrc;
struct D2InventoryGridInfoStrc;
struct D2ItemExtraDataStrc;
struct AppearanceSix;
struct CodeEntry;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
__declspec(noinline) static D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc*, int, D2InventoryGridInfoStrc*);
void __stdcall DATATBLS_GetInventoryGridInfo(int, int, D2InventoryGridInfoStrc*); // 0x0065C1F0


int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

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

extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo; // 0x007447B4
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0
int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId); // 0x0063C600
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
static __declspec(noinline) BOOL __stdcall sub_0063A8A0_CheckGridCellsFree(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight);
static __declspec(noinline) BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId); // 0x0063AFD0
static __declspec(noinline) BOOL __stdcall INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B490
static __declspec(noinline) BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B620
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

struct AppearanceSix
{
    u8 f_0;
    u8 f_1;
    u8 field2;
    u8 field3;
    u8 f_4;
    u8 field5;
};

struct CodeEntry
{
    u32 code;
    s32 type;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern CodeEntry gTable_0096CC68[]; // 0x0096CC68
s32 __fastcall sub_00451F60_ClassId(Unit*); // 0x00451F60
u8 __stdcall sub_00627D40_Page(Unit*); // 0x00627D40
u8 __stdcall sub_00628660_BodySlot(Unit*); // 0x00628660
s32 __stdcall sub_00629B50_IsType(s32, s32); // 0x00629B50
s32 __stdcall sub_0062C100_Transform(Unit*, Unit*, u8*, s32); // 0x0062C100
ItemRecord* __stdcall sub_006335F0_ItemRecord(s32); // 0x006335F0
ItemRecord* __stdcall sub_00633640_RecordByCode(u32, s32*); // 0x00633640
Unit* __stdcall sub_0063C050_BodyItem(Inventory*, s32); // 0x0063C050
u32 __stdcall sub_0064F380_WeaponCode(Unit*, Inventory*, s32*, s32, s32); // 0x0064F380
s32 __stdcall sub_0064F420_UsesAppearance(s32); // 0x0064F420
s32 __stdcall sub_0064F500_AppearanceIndex(s32, AppearanceSix*); // 0x0064F500
AppearanceRecord* __stdcall sub_0065B620_AppearanceRecord(s32); // 0x0065B620

// 0x0063ADD0
D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    void** const pInventoryMemPool = &pInventory->pMemPool;
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
                pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridHeight * pInventoryGrid->nGridWidth, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC1, 0);
                unsigned int nSize = pInventoryGrid->nGridWidth;
                nSize *= pInventoryGrid->nGridHeight;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
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

        pInventory->pGrids = (D2InventoryGridStrc*)sub_0040B4B0(*pInventoryMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, LINE_GRID_REALLOC, 0);
        memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
        pInventory->nGridCount = nInventoryGrid + 1;

        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
        pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
        pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridHeight * pInventoryGrid->nGridWidth, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC2, 0);
        unsigned int nSize = pInventoryGrid->nGridWidth;
                nSize *= pInventoryGrid->nGridHeight;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
    }

    return pInventoryGrid;
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

// 0x0063B210
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

    D2UnitStrc* pOwner = pInventory->pOwner;
    if (!pOwner)
    {
        return TRUE;
    }

    int nItemType;
    if (!pItem || (nItemType = pItem->dwUnitType) != UNIT_ITEM)
    {
        return FALSE;
    }

    if ((!pOwner ? 6 : pOwner->dwUnitType) != nItemType)
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

// 0x0063A8A0
static BOOL __stdcall sub_0063A8A0_CheckGridCellsFree(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
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

static __forceinline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// build: context INVENTORY_PlaceItemInGrid
static BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId)
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

    if (UNITS_GetAnimModeInline(pItem) == IMODE_ONGROUND && UNITS_GetRoom(pItem))
    {
        if (sub_00463720_TestUnitFlagEx(pItem, UNITFLAGEX_SERVERUNIT))
        {
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? UNIT_INVALID : pItem->dwUnitType, !pItem ? D2UnitInvalidGUID : pItem->dwUnitId);
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
        ITEMS_SetOwnerId(pItem, !pInventory->pOwner ? D2UnitInvalidGUID : pInventory->pOwner->dwUnitId);
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

// 0x0063B300
static BOOL __stdcall INVENTORY_CanItemBePlacedAtPos(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (nItemWidth + nX > pInventoryGrid->nGridWidth || nItemHeight + nY > pInventoryGrid->nGridHeight)
    {
        return FALSE;
    }

    return sub_0063A8A0_CheckGridCellsFree(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
}

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

// build: context INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight
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

// build: context INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight
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

// build: context INVENTORY_GetFreePosition
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

// 0x0063B950
BOOL __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, BOOL bUnused, unsigned char nPage, const char* szFile, int nLine)
{
    int nX;
    int nY;
    if (!pInventory)
    {
        return FALSE;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM)
    {
        if (!INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, nPage))
        {
            return FALSE;
        }

        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nX, nY, nPage + INVGRID_INVENTORY, nInventoryRecordId);
    }

    return FALSE;
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

// build: context INVENTORY_GetBackPackItemByType
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
        if (ITEMSIsA(pItem, nItemType))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

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

// 0x0063D1D0
void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
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
    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc != BODYLOC_RARM && nBodyLoc != BODYLOC_LARM)
    {
        return;
    }
    if (!ITEMS_CanBeEquipped(pItem))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
        return;
    }
    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    if (!ITEMSIsA(pWeapon, ITEMTYPE_WEAPON))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    if (ITEMSIsA(pWeapon, ITEMTYPE_MISSILE_POTION))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
}

// 0x0063D690
static __declspec(noinline) void __cdecl sub_0063D690_CopySix(AppearanceSix* output, Unit* item)
{
    if (item)
    {
        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
        D2_ASSERT(record, 0x121E);
        output->f_0 = FIELD(u8, record, 0x116);
        output->f_1 = FIELD(u8, record, 0x117);
        output->field2 = FIELD(u8, record, 0x118);
        output->field3 = FIELD(u8, record, 0x119);
        output->f_4 = FIELD(u8, record, 0x11A);
        output->field5 = FIELD(u8, record, 0x11B);
    }
    else
    {
        memset(output, 0, sizeof(AppearanceSix));
    }
}

// 0x0063D900
static __declspec(noinline) s32 __cdecl sub_0063D900_FindCode(u32 second, u32 first)
{
    sub_0063D710_InitCodes();
    for (u32 index = 1; index < 0xFF; ++index)
    {
        const u32 code = gTable_0096CC68[index].code;
        if (code == first || code == second)
        {
            return index;
        }
    }
    return 0;
}

// 0x0063D930
static __declspec(noinline) void __stdcall sub_0063D930_WeaponSlots(u8* firstOutput, u8* secondOutput, Unit* hItem, Unit* unit)
{
    D2_ASSERT(unit, 0x13B3);
    D2_ASSERT(hItem, 0x13B4);
    const u8 page = sub_00627D40_Page(hItem);
    if (page == 4 || page == 5)
    {
        Inventory* inventory = FIELD(Inventory*, unit, 0x60);
        s32 mode;
        const u32 weapon = sub_0064F380_WeaponCode(unit, inventory, &mode, -1, 1);
        const u8 slot = sub_00628660_BodySlot(hItem);
        if (weapon == 0x20776278)
        {
            if (slot == 5 || slot == 6)
            {
                if (inventory)
                {
                    Unit* equipped = sub_0063C050_BodyItem(inventory, 5);
                    if (equipped)
                    {
                        s32 equippedId = FIELD(s32, equipped, 4);
                        ItemRecord* record = sub_006335F0_ItemRecord(equippedId);
                        D2_ASSERT(record, 0x13CF);
                        const u32 c80 = FIELD(u32, record, 0x80);
 const u32 c90 = FIELD(u32, record, 0x90);
 const s32 code = sub_0063D900_FindCode(c80, c90);
                        if (code <= 0)
                        {
                            firstOutput[6] = 0xFF;
                            secondOutput[6] = 0xFF;
                        }
                        else
                        {
                            firstOutput[6] = (u8)code;
                        }
                    }
                }
            }
        }
        else if (weapon == 0x20776F62)
        {
            if (slot == 6)
            {
                s32 recordIndex;
                ItemRecord* record = sub_00633640_RecordByCode(0x2074696C, &recordIndex);
                if (record)
                {
                    const u32 c80 = FIELD(u32, record, 0x80);
 const u32 c90 = FIELD(u32, record, 0x90);
 const s32 code = sub_0063D900_FindCode(c80, c90);
                    if (!code)
                    {
                        firstOutput[5] = 0xFF;
                        secondOutput[5] = 0xFF;
                    }
                    else
                    {
                        firstOutput[5] = (u8)code;
                    }
                }
            }
        }
    }
}

// build: context sub_0063DA70_ItemSlots
static __declspec(noinline) void __stdcall sub_0063DA70_ItemSlots(Unit* unit, u8* firstOutput, u8* secondOutput, Unit* item)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory)
    {
        Unit* firstHand = sub_0063C050_BodyItem(inventory, 5);
        Unit* secondHand = sub_0063C050_BodyItem(inventory, 6);
        ItemRecord* record = sub_006335F0_ItemRecord(item ? FIELD(s32, item, 4) : -1);
        D2_ASSERT(record, 0x140C);
        u8 slot = sub_00628660_BodySlot(item);
        const u32 c80 = FIELD(u32, record, 0x80);
 const u32 c90 = FIELD(u32, record, 0x90);
 const s32 code = sub_0063D900_FindCode(c80, c90);
        if (!code)
        {
            if (slot < 0x10)
            {
                firstOutput[slot] = 0xFF;
                secondOutput[slot] = 0xFF;
            }
        }
        else
        {
            if (item == firstHand)
            {
                slot = 5;
            }
            else if (item == secondHand)
            {
                slot = 6;
            }
            else if (slot >= 0x10)
            {
                return;
            }
            firstOutput[slot] = (u8)code;
            sub_0063D930_WeaponSlots(firstOutput, secondOutput, item, unit);
            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
            {
                secondOutput[slot] = 0xFF;
            }
            else
            {
                ++secondOutput[slot];
            }
        }
    }
}

// build: context sub_0063E510_InventoryAppearance
void __stdcall sub_0063E510_InventoryAppearance(Unit* unit, u8* firstOutput, u8* secondOutput)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory && FIELD(u32, inventory, 0) == 0x01020304)
    {
        Unit* item = FIELD(Unit*, inventory, 0x0C);
        while (item)
        {
            if (FIELD(u32, item, 0) == 4 && FIELD(s32, item, 0x10) == 1)
            {
                ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
                D2_ASSERT(record, 0x1446);
                const u8 page = sub_00627D40_Page(item);
                if (page != 1 && page != 4 && page != 5)
                {
                    if (page == 3)
                    {
                        AppearanceSix appearance;
                        sub_0063D690_CopySix(&appearance, item);
                        for (u32 slot = 0; slot < 0x10; ++slot)
                        {
                            if (sub_0064F420_UsesAppearance(slot))
                            {
                                AppearanceRecord* appearanceRecord = sub_0065B620_AppearanceRecord(sub_0064F500_AppearanceIndex(slot, &appearance));
                                if (sub_00451F60_ClassId(item) > 0)
                                {
                                    const u32 appearanceCode = FIELD(u32, appearanceRecord, 0x20);
                                    const s32 code = sub_0063D900_FindCode(appearanceCode, appearanceCode);
                                    if (code)
                                    {
                                        if (slot < 0x10)
                                        {
                                            firstOutput[slot] = (u8)code;
                                            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
                                            {
                                                secondOutput[slot] = 0xFF;
                                            }
                                            else
                                            {
                                                ++secondOutput[slot];
                                            }
                                        }
                                        continue;
                                    }
                                }
                                if (slot < 0x10)
                                {
                                    firstOutput[slot] = 0xFF;
                                    secondOutput[slot] = 0xFF;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (!sub_00629B50_IsType(FIELD(short, record, 0x11E), 0x4B))
                    {
                        sub_0063DA70_ItemSlots(unit, firstOutput, secondOutput, item);
                    }
                }
            }
            if (FIELD(u32, item, 0) != 4)
            {
                break;
            }
            ItemData* data = FIELD(ItemData*, item, 0x14);
            if (!data)
            {
                break;
            }
            ItemLink* link = (ItemLink*)((u8*)data + 0x5C);
            if (!link)
            {
                break;
            }
            item = FIELD(Unit*, link, 8);
        }
    }
}
