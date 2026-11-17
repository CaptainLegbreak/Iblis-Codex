struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
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

struct D2InventoryNodeStrc
{
    int nItemId;
    D2InventoryNodeStrc* pNext;
};

struct D2CorpseStrc
{
    unsigned int unk0x00;
    unsigned int dwUnitId;
    unsigned int unk0x08;
    D2CorpseStrc* pNextCorpse;
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

extern "C" const char gszInventorySourceFile_006EA918[];                                                    // 0x006EA918
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem);                                                     // 0x0063AAF0
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == 0x01020304) ? pInventory : 0;
}

// 0x0063AC40
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        if (pInventory->pCursorItem)
        {
            INVENTORY_RemoveItem(pInventory->pCursorItem);
        }

        for (D2UnitStrc* pItem = pInventory->pFirstItem; pItem; pItem = pInventory->pFirstItem)
        {
            INVENTORY_RemoveItem(pItem);
        }

        for (int i = 0; i < pInventory->nGridCount; ++i)
        {
            D2InventoryGridStrc* pGrid = &pInventory->pGrids[i];
            if (pGrid->ppItems)
            {
                FOG_FreePool(pInventory->pMemPool, pGrid->ppItems, gszInventorySourceFile_006EA918, 0x261, 0);
            }
        }

        if (pInventory->pGrids)
        {
            FOG_FreePool(pInventory->pMemPool, pInventory->pGrids, gszInventorySourceFile_006EA918, 0x267, 0);
        }

        if (pInventory->pOwner)
        {
            pInventory->pOwner->pInventory = 0;
        }

        D2InventoryNodeStrc* pNextNode = 0;
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNextNode)
        {
            pNextNode = pNode->pNext;
            FOG_FreePool(pInventory->pMemPool, pNode, gszInventorySourceFile_006EA918, 0x273, 0);
        }

        D2CorpseStrc* pNextCorpse = 0;
        for (D2CorpseStrc* pCorpse = pInventory->pFirstCorpse; pCorpse; pCorpse = pNextCorpse)
        {
            pNextCorpse = pCorpse->pNextCorpse;
            FOG_FreePool(pInventory->pMemPool, pCorpse, gszInventorySourceFile_006EA918, 0x27B, 0);
        }

        FOG_FreePool(pInventory->pMemPool, pInventory, gszInventorySourceFile_006EA918, 0x27F, 0);
    }
}
