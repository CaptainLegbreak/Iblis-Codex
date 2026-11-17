struct D2InventoryStrc;
struct D2UnitStrc;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
    char nNodePos;
    char nNodePosOther;
    unsigned short unk0x0E;
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

struct D2InventoryNodeStrc
{
    int nItemId;
    D2InventoryNodeStrc* pNext;
};

struct D2CorpseStrc;

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    void* pGrids;
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

#define INVENTORY_SIGNATURE 0x1020304
#define UNIT_ITEM 4
#define D2UnitInvalidGUID -1

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
