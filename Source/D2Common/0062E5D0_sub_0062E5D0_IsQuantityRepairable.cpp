struct D2InventoryStrc;
struct D2GameStrc;
struct D2BitBufferStrc;
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
    char unk0x18[0x60 - 0x18];
    D2InventoryStrc* pInventory;
};
struct D2ItemTypesTxt
{
    char unk0x00[8];
    unsigned char nRepair;
    char unk0x09[0xE4 - 0x09];
};
struct D2DataTablesStrc
{
    char unk0x00[0xBF8];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern D2DataTablesStrc* sgptDataTables;                                                                         // 0x00744304
D2ItemTypesTxt* __fastcall sub_00555C90_GetItemTypesTxtRecord(int nItemType);                                // 0x00555C90
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                             // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                              // 0x00625E00
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                  // 0x00628700
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                         // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                         // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                            // 0x00629930
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills);                                   // 0x0062A840
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);                                                               // 0x0062A8D0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                              // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                         // 0x0062BA80
int __fastcall sub_0062EFB0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062EFB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);                        // 0x0063BDE0

#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ETHEREAL 0x400000
#define STAT_QUANTITY 70
#define STAT_DURABILITY 72
#define NUM_BODYLOC 13

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecordInl(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }
    return 0;
}

inline int ITEMS_GetItemTypeInl(D2UnitStrc* pItem)
{
    return !pItem || pItem->dwUnitType != UNIT_ITEM ? 0 : ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return (nType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int nFlag)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & nFlag;
    }
    return 0;
}

// 0x0062E5D0
static int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    int nItemType;
    if (pItem->dwUnitType != UNIT_ITEM)
    {
        nItemType = 0;
    }
    else
    {
        nItemType = ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecordInl(nItemType);
    if (pItemTypesTxtRecord && pItemTypesTxtRecord->nRepair && ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem) && !ITEMS_IsEthereal(pItem))
    {
        return 1;
    }
    return 0;
}

int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660

// build: context ITEMS_IsRepairable
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (!pItemData || !(pItemData->dwItemFlags & IFLAG_IDENTIFIED))
    {
        return 0;
    }

    D2ItemDataStrc* pItemData2 = ITEMS_GetItemDataInl(pItem);
    if (pItemData2 && (pItemData2->dwItemFlags & IFLAG_ETHEREAL))
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

// 0x0062FE60
int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*))
{
    if (!pUnit)
    {
        return 0;
    }

    int nTotal = 0;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    for (int i = 0; i < NUM_BODYLOC; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
        {
            continue;
        }

        int bRepair = 0;
        if (ITEMS_IsRepairable(pItem) && ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
            if (nMaxDurability && nDurability != nMaxDurability)
            {
                bRepair = 1;
            }
        }

        if (sub_0062E5D0_IsQuantityRepairable(pItem))
        {
            const int nMaxQuantity = ITEMS_GetTotalMaxStack(pItem);
            if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < nMaxQuantity)
            {
                bRepair = 1;
            }
        }

        int bHasChargedSkills = 0;
        if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills || bRepair)
        {
            nTotal += sub_0062EFB0_GetRepairCost(pUnit, pItem, nDifficulty, pQuestFlags, nNpcId, 3);
            if (pfCallback)
            {
                pfCallback(pGame, pItem, pUnit);
            }
        }
    }

    return nTotal;
}
