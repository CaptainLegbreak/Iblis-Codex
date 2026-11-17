struct D2ItemsTxt
{
    char unk0x000[0x12A];
    unsigned char nQuest;
};

struct D2UniqueItemsTxt
{
    char unk0x000[0x2C];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC24];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

struct D2GameStrc
{
    char unk0x0000[0x1B24];
    unsigned int dwUniqueFlags[128];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIQUEITEMSFLAGINDEX_NOLIMIT 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __fastcall sub_005564D0_IsDroppedUnique(D2GameStrc* pGame, D2UnitStrc* pItem);                         // 0x005564D0

// 0x005564A0
static __declspec(noinline) unsigned int ITEMS_HasUniqueBeenDroppedAlready(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

inline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecord(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }

    return 0;
}

// 0x00556530
static int __stdcall ITEMS_CanUniqueItemBeDropped(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nFileIndex = ITEMS_GetFileIndex(pItem);
    D2UniqueItemsTxt* pUniqueItemsTxtRecord = ITEMS_GetUniqueItemsTxtRecord(nFileIndex);
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    if (pUniqueItemsTxtRecord->nUniqueItemFlags[0] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_NOLIMIT])
    {
        return 1;
    }

    if ((pItemsTxtRecord->nQuest || !sub_005564D0_IsDroppedUnique(pGame, pItem)) && nFileIndex <= 4096)
    {
        pGame->dwUniqueFlags[nFileIndex >> 5] |= gdwBitMasks[nFileIndex & 0x1F];
        return 1;
    }

    return 0;
}

int __fastcall sub_K11_Emit005564A0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_CanUniqueItemBeDropped(pGame, pItem))
    {
        return ITEMS_HasUniqueBeenDroppedAlready(pGame, ITEMS_GetFileIndex(pItem));
    }

    return 0;
}
