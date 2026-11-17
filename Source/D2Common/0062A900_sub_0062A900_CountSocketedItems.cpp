struct D2InventoryStrc;
struct D2ItemsTxt
{
    char unk_000[0x137];
    unsigned char nHasInv;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk_08[0x58];
    D2InventoryStrc* pInventory;
};

enum { UNIT_ITEM = 4 };

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

static __forceinline int ITEMS_CheckIfSocketableByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }

    return 0;
}

static __forceinline int ITEMS_CheckIfSocketable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemId(pItem->dwClassId);
    }

    return 0;
}

static __declspec(noinline) int sub_0062A900_CountSocketedItems(D2UnitStrc* pItem);
// 0x0062A900
static int sub_0062A900_CountSocketedItems(D2UnitStrc* pItem)
{
    int nSocketedItems = 0;
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pInventoryItem)
    {
        return 0;
    }

    do
    {
        ++nSocketedItems;
        pInventoryItem = INVENTORY_GetNextItem(pInventoryItem);
    }
    while (pInventoryItem);

    return nSocketedItems;
}

// calling-convention shim (not game code)
int __fastcall sub_0062A900_Shim(D2UnitStrc* pItem)
{
    return sub_0062A900_CountSocketedItems(pItem) + 1;
}
