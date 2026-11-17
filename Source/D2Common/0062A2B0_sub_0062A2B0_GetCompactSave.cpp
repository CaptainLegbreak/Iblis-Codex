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
};

struct D2ItemsTxt
{
    char unk0x000[0x143];
    unsigned char nCompactSave;
    unsigned char nSkipName;
    unsigned char nNameable;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                           // 0x00628700
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                                        // 0x00628110

// 0x0062A2B0
static int sub_0062A2B0_GetCompactSave(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x12E0);
    return pItemsTxtRecord->nCompactSave;
}

int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x67D);

    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (!(nUnitType == 4 && ITEMS_GetItemTypeFromItemId(pItem->dwClassId) == 4)
        && !(pItem->dwUnitType == 4 && pItem->pItemData && (pItem->pItemData->dwItemFlags & 0x1000))
        && ITEMS_GetItemType(pItem) != 7
        && ITEMS_GetItemType(pItem) != 5
        && ITEMS_GetItemType(pItem) != 6
        && !ITEMS_CheckItemFlag(pItem, 0x100, 0x12F7, ".\\ITEMS\\Items.cpp")
        && !(ITEMS_GetItemFlags(pItem) & 0x1000000)
        && !sub_0062A2B0_GetCompactSave(pItem))
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->nNameable != 0;
    }
    return 0;
}
