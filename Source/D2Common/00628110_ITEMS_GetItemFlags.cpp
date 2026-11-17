struct D2ItemDataStrc
{
    char unk0x00[0x18];
    unsigned int dwItemFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2ItemDataStrc* pItemData;
};

// 0x00628110
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}
