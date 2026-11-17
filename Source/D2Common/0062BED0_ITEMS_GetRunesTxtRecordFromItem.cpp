struct D2InventoryStrc;

struct D2ItemDataStrc
{
    int dwQualityNo;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2ItemDataStrc* pItemData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x000[0x12A];
    unsigned char nQuest;
};

struct D2RunesTxt
{
    char szName[64];
    char szRuneName[64];
    unsigned char bComplete;
    unsigned char bServer;
    unsigned short wStringId;
    unsigned short unk0x84;
    short wIType[6];
    short wEType[3];
    int nRune[6];
    char unk0xB0[0x70];
};

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount;
    D2RunesTxt* pRunesTxt;
};

typedef char check_D2RunesTxt_size[sizeof(D2RunesTxt) == 0x120 ? 1 : -1];

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                // 0x006299B0
D2RuneDataTbl* __stdcall DATATBLS_GetRuneDataTables();                                                      // 0x00639CB0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

static int ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && pItem->pItemData)
    {
        switch (pItem->pItemData->dwQualityNo)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwClassId;
    }
    return -1;
}

static __forceinline int ITEMS_IsOfType(D2UnitStrc* pItem, int nItemType)
{
    return ITEMS_CheckItemTypeId(pItem, nItemType);
}

// 0x0062BED0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem)
{
    int nRuneItemIds[6];

    if (!pItem)
    {
        return 0;
    }

    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem))->nQuest)
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pSocketFiller = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pSocketFiller)
    {
        return 0;
    }

    int nSocketedItems = 0;
    while (pSocketFiller)
    {
        D2UnitStrc* pRune = INVENTORY_UnitIsItem(pSocketFiller);
        if (!pRune)
        {
            return 0;
        }

        nRuneItemIds[nSocketedItems++] = pRune->dwClassId;
        pSocketFiller = INVENTORY_GetNextItem(pSocketFiller);
    }

    const int nSockets = ITEMS_GetSockets(pItem);
    if (nSockets != nSocketedItems)
    {
        return 0;
    }

    D2RuneDataTbl* pRuneDataTbl = DATATBLS_GetRuneDataTables();
    if (!pRuneDataTbl)
    {
        return 0;
    }

    for (int i = 0; i < pRuneDataTbl->nRunesTxtRecordCount; ++i)
    {
        D2RunesTxt* pRunesTxtRecord = &pRuneDataTbl->pRunesTxt[i];
        if (pRunesTxtRecord->bComplete)
        {
            int nRuneCounter = 0;
            bool bMatch = true;

            while (nRuneCounter < 6 && pRunesTxtRecord->nRune[nRuneCounter] > 0)
            {
                if (nSocketedItems < nRuneCounter || nRuneItemIds[nRuneCounter] != pRunesTxtRecord->nRune[nRuneCounter])
                {
                    bMatch = false;
                    break;
                }

                ++nRuneCounter;
            }

            if (bMatch && nRuneCounter >= nSockets)
            {
                bool isItemTypeIgnored = false;
                for (int nETypeCounter = 0; nETypeCounter < 3 && pRunesTxtRecord->wEType[nETypeCounter]; ++nETypeCounter)
                {
                    if (ITEMS_CheckItemTypeId(pItem, pRunesTxtRecord->wEType[nETypeCounter]))
                    {
                        isItemTypeIgnored = true;
                        break;
                    }
                }

                if (!isItemTypeIgnored)
                {
                    for (int nITypeCounter = 0; nITypeCounter < 6 && pRunesTxtRecord->wIType[nITypeCounter]; ++nITypeCounter)
                    {
                        if (ITEMS_CheckItemTypeId(pItem, pRunesTxtRecord->wIType[nITypeCounter]))
                        {
                            return pRunesTxtRecord;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
