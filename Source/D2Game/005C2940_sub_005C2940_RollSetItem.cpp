struct D2SeedStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x000[0x80];
    unsigned int dwCode;
};

struct D2SetItemsTxt
{
    char unk0x000[0x22];
    unsigned short wVersion;
    char unk0x024[0x04];
    unsigned int szItemCode;
    short nSetId;
    short nSetItems;
    short wLvl;
    short wLvlReq;
    unsigned int dwRarity;
    char unk0x038[0x180];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

struct D2ItemDropStrc
{
    char unk0x00[0x40];
    int nItemIndex;
    char unk0x44[0x3C];
    unsigned int dwFlags2;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem);                                            // 0x005C2740
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem);                                                        // 0x006281E0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, void* pProperty, int nArg2, int nArg5); // 0x0065FEC0

static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    for (int i = 0; i < sgptDataTables->nSetItemsTxtRecordCount; ++i)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = &sgptDataTables->pSetItemsTxt[i];
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->szItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if (pItemDrop->nItemIndex && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
    }

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                break;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        if (nCounter < 0 || nCounter >= nLegibleSets)
        {
            return 0;
        }

        nFileIndex = rarityData[2 * nCounter];
    }

    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    sub_0065FEC0_ItemApplyProps(4, 0, pItem, 0, 0, 0);
    return 1;
}

// 0x005C2940
int __fastcall sub_005C2940_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C25C0_RollSetItemRecord(pItemDrop, pItem);
    }

    return sub_005C2740_RollLegacySetItem(pItem);
}
