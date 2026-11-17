struct D2InventoryStrc;
struct D2BitBufferStrc;

struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x14];
    unsigned int dwItemFlags;
    char unk0x1C[0x22];
    unsigned short wMagicSuffix[3];
    unsigned char nBodyLoc;
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
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x112];
    unsigned char nDurability;
    unsigned char nNoDurability;
    char unk0x114[0x0A];
    short wType[2];
    char unk0x122[0x12];
    unsigned char nSpellIcon;
};

struct D2BooksTxt
{
    unsigned short wStr;
    unsigned char nSpellIcon;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBFC];
    int nItemTypesTxtRecordCount;
    int nItemTypesIndex;
    unsigned int* pItemTypesEquivalenceLUTs;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                  // 0x00628700
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                               // 0x006374B0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem);                                                     // 0x0063AAF0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define STAT_ITEM_INDESCTRUCTIBLE 152
#define IFLAG_IDENTIFIED 0x00000010
#define NODEPAGE_STORAGE 1
#define NODEPAGE_EQUIP 3
#define INVPAGE_INVENTORY 0
#define INVPAGE_CUBE 3
#define INVPAGE_NULL 255
#define ITEMTYPE_BOOK 18
#define ITEMTYPE_SCROLL 22
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_TestItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline unsigned char ITEMS_GetInvPage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvPage;
    }

    return INVPAGE_NULL;
}

// 0x00627D00
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        INVENTORY_RemoveItem(pItem);
        if (pItem->pItemData)
        {
            FOG_FreeServerMemory(pMemPool, pItem->pItemData, ".\\ITEMS\\Items.cpp", 266, 0);
        }
    }
}

// 0x00629930
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && !pItemsTxtRecord->nNoDurability && pItemsTxtRecord->nDurability > 0 && STATLIST_GetMaxDurabilityFromUnit(pItem))
        {
            return STATLIST_UnitGetStatValue(pItem, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0;
        }
    }

    return 0;
}

// 0x00629A90
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType)
{
    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nType = ITEMS_GetItemTypeFromItemId(nItemId);
    if (nType < 0 || nType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nType2 = pItemsTxtRecord->wType[1];
    if (nType2 && nType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[nType2 * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

// 0x0062A530
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nUnidItems = 0;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInventoryItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_TestItemFlag(pInventoryItem, IFLAG_IDENTIFIED))
        {
            continue;
        }

        const int nNodePage = INVENTORY_GetItemNodePage(pItem);
        if (nNodePage == NODEPAGE_STORAGE)
        {
            if (ITEMS_GetInvPage(pInventoryItem) == INVPAGE_INVENTORY || ITEMS_GetInvPage(pInventoryItem) == INVPAGE_CUBE)
            {
                ++nUnidItems;
            }
        }
        else if (nNodePage == NODEPAGE_EQUIP)
        {
            ++nUnidItems;
        }
    }

    return nUnidItems;
}

// 0x0062AF50
void __fastcall ITEMS_WriteBitsToBitstream(int nBits, unsigned int nData, D2BitBufferStrc* pBuffer)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

// 0x0062BB20
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3500);
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nType == UNIT_ITEM, 3501);

    unsigned char nSpellIcon = 0;
    if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SCROLL) || ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOOK))
    {
        unsigned short wBookId = 0;
        if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
        {
            wBookId = pItemData->wMagicSuffix[0];
        }
        else
        {
            wBookId = 0;
        }

        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(wBookId);
        if (!pBooksTxtRecord)
        {
            return -1;
        }

        nSpellIcon = pBooksTxtRecord->nSpellIcon;
    }
    else
    {
        const int nClassId = pItem->dwClassId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        D2_ASSERT(pItemsTxtRecord, 3512);
        nSpellIcon = pItemsTxtRecord->nSpellIcon;
    }

    return nSpellIcon;
}
