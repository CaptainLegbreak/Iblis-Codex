struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x14];
    unsigned int dwItemFlags;
    char unk0x1C[0x0C];
    int dwFileIndex;
    char unk0x2C[0x19];
    unsigned char nInvPage;
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

struct D2SetItemsTxt
{
    char unk0x00[0x2E];
    short nSetItems;
    char unk0x30[0x1B8 - 0x30];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pPlayer, int bEquipping, int* a4, int* a5, int* a6); // 0x0062EAF0

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_SET 5
#define IFLAG_BROKEN 0x00000100
#define IFLAG_NOEQUIP 0x00004000
#define ITEMTYPE_CHARM 13
#define INVPAGE_INVENTORY 0
#define PCLASS_AMAZON 0
#define PCLASS_SORCERESS 1
#define PCLASS_NECROMANCER 2
#define PCLASS_PALADIN 3
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_ASSASSIN 6
#define TRUE 1
#define FALSE 0

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQualityInline(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

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

inline int ITEMS_CanBeEquippedInline(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}

// 0x0062A490
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemQualityInline(pItem) == ITEMQUAL_SET)
    {
        const int nFileIndex = ITEMS_GetFileIndex(pItem);
        if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
        {
            return &sgptDataTables->pSetItemsTxt[nFileIndex];
        }
    }

    return 0;
}

// 0x0062A620
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue)
{
    int nResult = nValue;

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        switch (pPlayer->dwClassId)
        {
        case PCLASS_SORCERESS:
        case PCLASS_NECROMANCER:
        case PCLASS_DRUID:
            nResult = 2 * nValue;
            break;
        case PCLASS_AMAZON:
        case PCLASS_PALADIN:
        case PCLASS_ASSASSIN:
            nResult = nValue + (nValue >> 1);
            break;
        }
    }

    return nResult;
}

// 0x0062FF70
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (!ITEMS_CanBeEquippedInline(pItem))
        return FALSE;

    if (!ITEMS_CheckItemTypeId(pItem, ITEMTYPE_CHARM))
        return FALSE;

    D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem);
    if (!pItemData)
        return FALSE;

    if (pItemData->nInvPage != INVPAGE_INVENTORY)
        return FALSE;

    return ITEMS_CheckRequirements(pItem, pPlayer, FALSE, 0, 0, 0) != 0;
}
