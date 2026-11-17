#include "D2Common.h"

typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2UnitStrc { int nType; int nClassId; int pMemoryPool; int nUnitId; };

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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo;                                                   // 0x0074479C

#define INVENTORY_SIGNATURE 0x1020304
#define INVGRID_BODYLOC 0
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0063ADD0

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

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE) ? pInventory : 0;
}

static __forceinline D2UnitStrc* GetBodyItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && (unsigned int)nBodyLoc <= 12)
    {
        D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pGrid)
        {
            return pGrid->ppItems[nBodyLoc];
        }
    }
    return 0;
}

// 0x0063BF90
D2UnitStrc* __stdcall sub_0063BF90_GetSecondaryWeapon(D2InventoryStrc* pInventory)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    if (pInventory->dwLeftItemGUID == -1)
        return 0;

    D2UnitStrc* pItem = GetBodyItem(pInventory, BODYLOC_LARM);
    D2UnitStrc* pLeftItem;
    if (pItem)
    {
        pLeftItem = pItem;
        if (!sub_00629BB0_CheckItemType(pItem, 45))
            pLeftItem = 0;
    }
    else
    {
        pLeftItem = 0;
    }

    D2UnitStrc* pRightItem = GetBodyItem(pInventory, BODYLOC_RARM);
    if (!pRightItem || !sub_00629BB0_CheckItemType(pRightItem, 45))
        pRightItem = 0;

    if (pLeftItem && (!pLeftItem ? -1 : pLeftItem->nUnitId) == pInventory->dwLeftItemGUID)
        return pRightItem;
    if (pRightItem && (!pRightItem ? -1 : pRightItem->nUnitId) == pInventory->dwLeftItemGUID)
        return pLeftItem;
    return 0;
}
