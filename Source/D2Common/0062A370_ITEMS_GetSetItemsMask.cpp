#define UNIT_ITEM 4
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_SET 5

struct D2InventoryStrc;

struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x14];
    unsigned int dwItemFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2SetItemsTxt
{
    char unk0x00[0x2C];
    short nSetId;
    unsigned char nSetItemMask;
    char unk0x2F[0x189];
};

struct D2SetsTxt;

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId);                                            // 0x00483410
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
extern "C" const char gszItemsSourceFile_006E1150[];                                                        // 0x006E1150

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

__declspec(noinline) int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem) // 0x00627E70
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

__declspec(noinline) unsigned int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile) // 0x006280A0
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// 0x0062A370
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem)
{
    if (!pPlayer || !pSetItem || *(volatile int*)&pSetItem->dwUnitType != UNIT_ITEM || !pSetItem->pItemData)
    {
        return 0;
    }
    switch (*(volatile int*)&pSetItem->pItemData->dwQualityNo)
    {
    case ITEMQUAL_SET:
        break;
    default:
        return 0;
    }
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pSetItem));
    if (!pSetItemsTxtRecord)
    {
        return 0;
    }
    if (!sub_00483410_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId))
    {
        return 0;
    }

    unsigned int nMask = 0;
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        if (INVENTORY_GetItemNodePage(pNode) == 3)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if (pItem && pItem->dwUnitType == UNIT_ITEM && (bDontIgnoreInputItem || pItem != pSetItem)
                && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET
                && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x144E, gszItemsSourceFile_006E1150)
                && !ITEMS_CheckItemFlag(pItem, 0x100, 0x144F, gszItemsSourceFile_006E1150))
            {
                D2SetItemsTxt* pRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pRecord && pRecord->nSetId == pSetItemsTxtRecord->nSetId)
                {
                    nMask |= 1 << pRecord->nSetItemMask;
                }
            }
        }
    }

    return nMask;
}
