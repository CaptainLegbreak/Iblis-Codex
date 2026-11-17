struct D2SetItemsTxt
{
    char unk0x00[46];
    short nSetItems;
    char unk0x30[392];
};
struct D2ItemDataStrc
{
    int dwQualityNo;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[12];
    D2ItemDataStrc* pItemData;
};
struct D2DataTablesStrc
{
    char unk0x00[3096];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer);                          // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStat, int nLayer);           // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __fastcall sub_0062B5B0(D2UnitStrc* pItem, D2UnitStrc* pUnit);                            // 0x0062B5B0

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define ITEMQUAL_SET 5
#define STAT_QUANTITY 0x46
#define STAT_ITEM_THROWABLE 0x7D
#define PCLASS_AMAZON 0
#define PCLASS_SORCERESS 1
#define PCLASS_NECROMANCER 2
#define PCLASS_PALADIN 3
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_ASSASSIN 6
#define TRUE 1
#define FALSE 0

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQualityInline(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

// 0x0062A310
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem)
{
    if (pItem)
    {
        if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
        {
            return TRUE;
        }

        if (STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0))
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 0, 0);
            return TRUE;
        }

        if (ITEMS_GetTotalMaxStack(pItem) <= 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062BA60
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    return sub_0062B5B0(pItem, pUnit);
}
