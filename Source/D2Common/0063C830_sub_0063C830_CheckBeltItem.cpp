struct D2InventoryStrc;
struct D2UnitStrc;

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
};

extern "C" const char gszInventorySourceFile_006EA918[]; // 0x006EA918
extern "C" void* __cdecl memset(void* destination, int value, unsigned int count); // 0x00681EF0
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo; // 0x007447B4
void* __fastcall sub_0040B430(void* pool, int size, const char* file, int line, int flags); // 0x0040B430
void* __fastcall sub_0040B4B0(void* pool, void* memory, int size, const char* file, int line, int flags); // 0x0040B4B0
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info); // 0x0063ADD0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* item); // 0x0062BAD0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* item, unsigned char* width, unsigned char* height, const char* file, int line); // 0x006286C0
struct D2ItemsTxt { unsigned char unk_000[0x11D]; unsigned char flag_11D; unsigned char unk_11E[0x12]; unsigned char flag_130; };
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int itemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* inventory, int slot); // 0x0063C7F0

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

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* inventory)
{
    return (inventory && inventory->dwSignature == 0x01020304) ? inventory : 0;
}

// 0x0063C830
int __stdcall sub_0063C830_CheckBeltItem(D2InventoryStrc* inventory, D2UnitStrc* item, int slot, D2UnitStrc** previous)
{
    if (!inventory)
        return 0;
    if (inventory->dwSignature != 0x01020304)
        return 0;
    D2InventoryGridStrc* grid = INVENTORY_GetGrid(inventory, 1, &gBeltInventoryGridInfo);
    if (!grid)
        return 0;
    if (!item || item->dwUnitType != 4 || !ITEMS_CheckIfBeltable(item))
        return 0;
    unsigned char width;
    unsigned char height;
    ITEMS_GetDimensions(item, &width, &height, gszInventorySourceFile_006EA918, 0xBC9);
    if (width != 1 || height != 1)
        return 0;
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
    if (!record || record->flag_11D != 1 || record->flag_130 != 1)
        return 0;
    *previous = INVENTORY_GetItemFromBeltSlot(inventory, slot);
    return 1;
}

D2InventoryGridStrc* __stdcall EmitInventoryGridCaller(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info)
{
    return INVENTORY_GetGrid(inventory, index, info);
}
