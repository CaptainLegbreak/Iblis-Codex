#define EXTRA_OFFSET 0x5C
#define SIZE_LINE 0x199
#define INVENTORY_SIGNATURE 0x01020304

struct D2UnitStrc;
struct D2InventoryStrc;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
    signed char nNodePos;
    unsigned char nNodePosOther;
    unsigned char pad0E[2];
    D2UnitStrc* pPreviousGridItem;
    D2UnitStrc* pNextGridItem;
};

struct D2ItemDataStrc
{
    unsigned char pad00[EXTRA_OFFSET];
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
};

struct D2InventoryPairStrc
{
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
};

struct D2InventoryGridStrc
{
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    unsigned char nGridWidth;
    unsigned char pad09[3];
    D2UnitStrc** ppItems;
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemoryPool;
    D2UnitStrc* pOwner;
    D2InventoryPairStrc items;
    D2InventoryGridStrc* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
    D2UnitStrc* pCursorItem;
    int dwOwnerGuid;
    int dwItemCount;
};

extern "C" int __fastcall sub_0045ADF0_GetX(D2UnitStrc* pItem); // 0x0045ADF0
extern "C" int __fastcall sub_0045AE20_GetY(D2UnitStrc* pItem); // 0x0045AE20
extern "C" void __stdcall sub_006286C0_GetSize(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szSource, int nLine); // 0x006286C0
extern "C" void __stdcall sub_00629ED0_SetItemCell(D2UnitStrc* pItem, int nCell); // 0x00629ED0
extern "C" void __stdcall sub_006277F0_RemoveOwnerStat(D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x006277F0
extern "C" const char gszInventorySource_006EA918; // 0x006EA918

static __forceinline D2ItemExtraDataStrc* sub_0063A7E0(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }
    return 0;
}

static __declspec(noinline) void __cdecl sub_0063A810_UnlinkPair(D2InventoryPairStrc* pPair, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousItem)
    {
        if (pPair->pFirstItem == pItem)
        {
            pPair->pFirstItem = pExtra->pNextItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = sub_0063A7E0(pExtra->pPreviousItem);
        if (pPrevious)
        {
            pPrevious->pNextItem = pExtra->pNextItem;
        }
    }
    if (!pExtra->pNextItem)
    {
        if (pPair->pLastItem == pItem)
        {
            pPair->pLastItem = pExtra->pPreviousItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = sub_0063A7E0(pExtra->pNextItem);
        if (pNext)
        {
            pNext->pPreviousItem = pExtra->pPreviousItem;
        }
    }
    pExtra->pNextItem = 0;
    pExtra->pPreviousItem = 0;
}

static __declspec(noinline) void __stdcall sub_0063A970_UnlinkGrid(D2InventoryGridStrc* pGrid, int bMultiCell, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousGridItem)
    {
        if (pGrid->pFirstItem == pItem)
        {
            pGrid->pFirstItem = pExtra->pNextGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = sub_0063A7E0(pExtra->pPreviousGridItem);
        if (pPrevious)
        {
            pPrevious->pNextGridItem = pExtra->pNextGridItem;
        }
    }
    if (!pExtra->pNextGridItem)
    {
        if (pGrid->pLastItem == pItem)
        {
            pGrid->pLastItem = pExtra->pPreviousGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = sub_0063A7E0(pExtra->pNextGridItem);
        if (pNext)
        {
            pNext->pPreviousGridItem = pExtra->pPreviousGridItem;
        }
    }
    if (pGrid->ppItems)
    {
        if (bMultiCell)
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            unsigned char nWidth;
            unsigned char nHeight;
            sub_006286C0_GetSize(pItem, &nWidth, &nHeight, &gszInventorySource_006EA918, SIZE_LINE);
            for (int nRow = nY; nRow < nY + nHeight; ++nRow)
            {
                D2UnitStrc** ppRow = pGrid->ppItems + nRow * pGrid->nGridWidth;
                for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
                {
                    ppRow[nColumn] = 0;
                }
            }
        }
        else
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            pGrid->ppItems[nX + nY * pGrid->nGridWidth] = 0;
        }
    }
    pExtra->pNextGridItem = 0;
    pExtra->pPreviousGridItem = 0;
    pExtra->nNodePos = 0;
}

// 0x0063AAF0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType == 4)
    {
        D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
        if (!pExtra)
        {
            return 0;
        }
        D2InventoryStrc* pInventory = pExtra->pParentInv;
        if (!pInventory)
        {
            return 0;
        }
        if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        {
            return 0;
        }
        if (pExtra->nNodePos > 0)
        {
            const int nGrid = pExtra->nNodePos - 1;
            if (pInventory->nGridCount > nGrid)
            {
                sub_0063A970_UnlinkGrid(&pInventory->pGrids[nGrid], nGrid >= 1, pItem);
            }
        }
        if (pInventory->pCursorItem == pItem)
        {
            pInventory->pCursorItem = 0;
        }
        else
        {
            sub_0063A810_UnlinkPair(&pInventory->items, pItem);
            --pInventory->dwItemCount;
        }
        pExtra->pParentInv = 0;
        pExtra->nNodePos = 0;
        pExtra->nNodePosOther = 0;
        sub_00629ED0_SetItemCell(pItem, -1);
        if (pInventory->pOwner)
        {
            sub_006277F0_RemoveOwnerStat(pInventory->pOwner, pItem);
        }
        if (pInventory->dwLeftItemGUID == (!pItem ? -1 : pItem->dwUnitId))
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}
