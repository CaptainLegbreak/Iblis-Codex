struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x000[0x124];
    short wDropSound;
    short wUseSound;
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x84];
    short wDropSound;
    short wUseSound;
    char unk0x88[0x14C - 0x88];
};

struct D2SetItemsTxt
{
    char unk0x00[0x82];
    short wDropSound;
    short wUseSound;
    char unk0x86[0x1B8 - 0x86];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x04];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

#define ITEMQUAL_SET 5
#define ITEMQUAL_UNIQUE 7

// 0x004C17F0
static int sub_004C17F0_GetItemUseSound(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wDropSound > 0)
        nSound = pItemsTxtRecord->wUseSound;

    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2UniqueItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount) ? &sgptDataTables->pUniqueItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2SetItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }

    return nSound;
}

// 0x004C1E20
int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem)
{
    return sub_004C17F0_GetItemUseSound(pItem);
}
