struct D2InventoryStrc;

struct D2ItemDataStrc
{
    char unk0x00[0x18];
    unsigned int dwItemFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2ItemDataStrc* pItemData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
    char unk0x64[0x64];
    unsigned int dwFlagEx;
};

struct D2ItemsTxt
{
    char unk0x00[0x12A];
    unsigned char nQuest;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                  // 0x00628700
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                // 0x006299B0
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId);                                                       // 0x00629C80
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

inline int ITEMS_GetItemType_Inl(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (nUnitType != 4)
    {
        return 0;
    }

    return ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

inline unsigned int ITEMS_CheckItemFlag_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline int UNITS_IsExpansion_Inl(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx >> 25) & 1;
    }

    return 0;
}

// 0x0062A270
static int sub_0062A270_HasSocketedItem(D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    for (D2UnitStrc* pSocket = INVENTORY_GetFirstItem(pInventory); pSocket; pSocket = INVENTORY_GetNextItem(pSocket))
    {
        if (INVENTORY_UnitIsItem(pSocket))
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall ITEMS_IsImbueable(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType_Inl(pItem) == 4 || ITEMS_CheckItemFlag_Inl(pItem, 0x1000))
    {
        return 0;
    }

    const int nItemId = pItem->dwClassId;
    if (!ITEMS_CheckBitField1Flag1(nItemId))
    {
        return 0;
    }

    if (!UNITS_IsExpansion_Inl(pItem) && ITEMS_CheckIfThrowable(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(nItemId)->nQuest && ITEMS_GetBaseCode(pItem) != ' gel')
    {
        return 0;
    }

    if (sub_0062A270_HasSocketedItem(pItem))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pItem, 0x800, 4807, ".\\ITEMS\\Items.cpp"))
    {
        return 0;
    }

    const int nQuality = ITEMS_GetItemQuality(pItem);
    if (nQuality == 5 || nQuality == 4 || nQuality == 6 || nQuality == 8 || nQuality == 7 || nQuality == 9)
    {
        return 0;
    }

    return 1;
}

// 0x0062C770
int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType_Inl(pItem) != 4 && !ITEMS_CheckItemFlag_Inl(pItem, 0x1000))
    {
        const int nItemId = pItem->dwClassId;
        if (!DATATBLS_GetItemsTxtRecord(nItemId)->nQuest || ITEMS_GetBaseCode(pItem) == ' gel')
        {
            if (!ITEMS_CheckItemFlag_Inl(pItem, 0x100) && !sub_0062A270_HasSocketedItem(pItem) && !ITEMS_CheckItemFlag(pItem, 0x800, 4907, ".\\ITEMS\\Items.cpp"))
            {
                if (ITEMS_GetMaxSockets(pItem))
                {
                    return !ITEMS_GetSockets(pItem);
                }
            }
        }
    }

    return 0;
}
