struct D2ItemDataStrc
{
    char unk0x00[0x18];
    unsigned int dwItemFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x14 - 0x08];
    D2ItemDataStrc* pItemData;
};

struct D2ItemTypesTxt
{
    char unk0x00[8];
    unsigned char nRepair;
};

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ETHEREAL 0x400000

D2ItemTypesTxt* __fastcall sub_00555C90_GetItemTypesTxtRecord(int nItemType); // 0x00555C90
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
static int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem); // 0x0062E5D0

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nType == UNIT_ITEM ? pItem->pItemData : 0;
}

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// calling-convention shim (not game code)
static __declspec(noinline) int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem)
{
    if (ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem))
    {
        return 1;
    }
    return 0;
}

// 0x0062E660
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem)
{
    if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 0, 0) || ITEMS_CheckItemFlag(pItem, IFLAG_ETHEREAL, 0, 0))
    {
        return 0;
    }

    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
    {
        return 1;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_00555C90_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
    if (!pItemTypesTxtRecord || !pItemTypesTxtRecord->nRepair)
    {
        return 0;
    }

    if (sub_0062E5D0_IsQuantityRepairable(pItem))
    {
        return 1;
    }

    return ITEMS_HasDurability(pItem) != 0;
}
