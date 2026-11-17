struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x24];
    int dwFileIndex;
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

struct D2StatStrc
{
    int nLayer_StatId;
    int nValue;
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
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_SET 5
#define STAT_ITEM_CHARGED_SKILL 204

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

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
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

// 0x0062A840
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills)
{
    D2StatStrc pStat[64];

    if (pHasChargedSkills)
    {
        *pHasChargedSkills = 1;
    }

    int bResult = 0;
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    if (nStats > 0)
    {
        bResult = 1;

        if (pHasChargedSkills)
        {
            for (int i = 0; i < nStats; ++i)
            {
                if ((pStat[i].nValue & 0xFF) < (pStat[i].nValue >> 8))
                {
                    *pHasChargedSkills = 0;
                    break;
                }
            }
        }
    }

    return bResult;
}

// 0x0062B3A0
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem)
{
    if (D2SetItemsTxt* pSetItemsTxtRecord = ITEMS_GetSetItemsTxtRecordFromItem(pItem))
    {
        return pSetItemsTxtRecord->nSetItems;
    }

    return -1;
}
