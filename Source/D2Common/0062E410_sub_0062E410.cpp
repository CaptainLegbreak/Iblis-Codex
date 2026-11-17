struct D2ItemTypesTxt
{
    char unk0x00[9];
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    char unk0x0C[216];
};
struct D2ItemDataStrc
{
    char unk0x00[24];
    unsigned int dwItemFlags;
    char unk0x1C[41];
    unsigned char nInvPage;
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[16];
    D2ItemDataStrc* pItemData;
};
struct D2DataTablesStrc
{
    char unk0x00[3064];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall sub_0062AE20(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave, unsigned int dwVersion); // 0x0062AE20
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pPlayer, int bEquipping, int* a4, int* a5, int* a6); // 0x0062EAF0

#define UNIT_ITEM 4
#define IFLAG_BROKEN 0x00000100
#define IFLAG_NOEQUIP 0x00004000
#define ITEMTYPE_CHARM 13
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5
#define BODYLOC_SWRARM 11
#define BODYLOC_SWLARM 12
#define ITEMVERSION 0x60
#define TRUE 1
#define FALSE 0
#define INVPAGE_INVENTORY 0

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

// 0x0062E410
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave)
{
    return sub_0062AE20(pBitstream, nSize, bCheckForHeader, pItemSave, ITEMVERSION);
}

// 0x0062FDF0
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 || nBodyLoc2)
        {
            D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
            if (pItemTypesTxtRecord)
            {
                return pItemTypesTxtRecord->nBody;
            }
        }
    }

    return FALSE;
}
