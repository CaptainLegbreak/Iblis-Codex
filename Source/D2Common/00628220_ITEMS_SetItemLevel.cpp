struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x14];
    unsigned int dwItemFlags;
    char unk0x1C[0x10];
    int dwItemLevel;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2ItemDataStrc* pItemData;
};

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define IFLAG_BROKEN 0x00000100
#define IFLAG_NOEQUIP 0x00004000
#define TRUE 1
#define FALSE 0

inline D2ItemDataStrc* ITEMS_GetItemDataByType(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return (nType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_CheckItemFlagInline(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
        return pItemData->dwItemFlags & dwFlag;

    return 0;
}

// 0x00628220
void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
    {
        if (nItemLevel < 1)
            nItemLevel = 1;
        pItemData->dwItemLevel = nItemLevel;
    }
}

// 0x0062A4E0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}
