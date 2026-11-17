struct D2InventoryStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0xE0];
    int dwCost;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pUnit);                              // 0x0063DFD0

static __declspec(noinline) void __stdcall sub_006292F0_AddSocketablesCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost);

// 0x006292F0
static void __stdcall sub_006292F0_AddSocketablesCost(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost)
{
    int nSellCost = 0;
    int nBuyCost = 0;
    int nRepCost = 0;
    if (pItem->pInventory)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pItem->pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pSocketItem = INVENTORY_UnitIsItem(pSocketable);
            pSocketable = INVENTORY_GetNextItem(pSocketable);
            if (pSocketItem)
            {
                const int nClassId = pSocketItem->dwClassId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                const int nSocketableCost = pItemsTxtRecord->dwCost / 2;
                nSellCost += nSocketableCost;
                nBuyCost += nSocketableCost;
                nRepCost += nSocketableCost;
            }
        }
        *pSellCost += nSellCost;
        *pBuyCost += nBuyCost;
        *pRepCost += nRepCost;
    }
}

// build: context sub_006292F0_Shim
// calling-convention shim (not game code)
int __fastcall sub_006292F0_Shim(D2UnitStrc* pItem, int nDivisor)
{
    int nSellCost = nDivisor;
    int nBuyCost = nDivisor * 2;
    int nRepCost = nDivisor * 3;
    sub_006292F0_AddSocketablesCost(pItem, &nSellCost, &nBuyCost, &nRepCost);
    return nSellCost + nBuyCost + nRepCost;
}
