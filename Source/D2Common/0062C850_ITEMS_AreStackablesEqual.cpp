#define UNIT_ITEM 4
#define ITEMQUAL_NORMAL 2
#define IFLAG_ETHEREAL 0x00400000
#define STAT_MINDAMAGE 21
#define STAT_MAXDAMAGE 22
#define STAT_SECONDARY_MINDAMAGE 23
#define STAT_SECONDARY_MAXDAMAGE 24
#define STAT_ITEM_THROW_MINDAMAGE 159
#define STAT_ITEM_THROW_MAXDAMAGE 160

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ItemDataStrc
{
    int dwQualityNo;
    D2SeedStrc pSeed;
    int dwOwnerGUID;
    unsigned int dwInitSeed;
    unsigned int dwCommandFlags;
    unsigned int dwItemFlags;
    char unk0x1C[0x0C];
    int dwFileIndex;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2ItemDataStrc* pItemData;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x00625480
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                           // 0x006289F0
int __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                          // 0x006299B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

static __declspec(noinline) int sub_0062A2F0_IsPlainQuality(int nQuality)
{
    switch (nQuality)
    {
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    }
    return 1;
}

__declspec(noinline) int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);

// 0x0062A8D0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & IFLAG_ETHEREAL;
    }

    return 0;
}

#define ITEMS_QUALITY_INLINE(p) (((p) && (p)->dwUnitType == UNIT_ITEM && (p)->pItemData) ? (p)->pItemData->dwQualityNo : ITEMQUAL_NORMAL)

// 0x0062C850
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if ((!pItem1 ? -1 : pItem1->dwClassId) != (!pItem2 ? -1 : pItem2->dwClassId))
    {
        return 0;
    }

    if (ITEMS_QUALITY_INLINE(pItem1) != ITEMS_QUALITY_INLINE(pItem2))
    {
        return 0;
    }

    if (ITEMS_GetFileIndex(pItem1) != ITEMS_GetFileIndex(pItem2)
        || !ITEMS_CheckIfStackable(pItem1)
        || ITEMS_IsEthereal(pItem1) != ITEMS_IsEthereal(pItem2)
        || !sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem1))
        || !sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem2))
        || STATLIST_UnitGetStatValue(pItem1, STAT_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_MAXDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_SECONDARY_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_SECONDARY_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_SECONDARY_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_SECONDARY_MAXDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_ITEM_THROW_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_ITEM_THROW_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_ITEM_THROW_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_ITEM_THROW_MAXDAMAGE, 0)
        || (unsigned char)ITEMS_GetSockets(pItem1) > 0
        || (unsigned char)ITEMS_GetSockets(pItem2) > 0)
    {
        return 0;
    }

    return 1;
}
