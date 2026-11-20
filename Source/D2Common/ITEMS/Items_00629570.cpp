#include "D2Common.h"
#include "D2Structs.h"
#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define IFLAG_ETHEREAL 0x00400000
#define STAT_MINDAMAGE 21
#define STAT_MAXDAMAGE 22
#define STAT_SECONDARY_MINDAMAGE 23
#define STAT_SECONDARY_MAXDAMAGE 24
#define STAT_ITEM_THROW_MINDAMAGE 159
#define STAT_ITEM_THROW_MAXDAMAGE 160
#define ITEMS_QUALITY_INLINE(p) (((p) && (p)->dwUnitType == UNIT_ITEM && (p)->pItemData) ? (p)->pItemData->dwQualityNo : ITEMQUAL_NORMAL)

struct D2ItemsTxt;
struct D2ItemDataStrc;
struct D2SetItemsTxt;
struct D2SeedStrc;

struct D2ItemsTxt
{
    char unk0x00[128];
    unsigned int dwCode;
    char unk0x84[4];
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    char unk0x90[84];
    unsigned int dwMinStack;
    unsigned int dwMaxStack;
    unsigned int dwSpawnStack;
    char unk0xF0[46];
    short wType[2];
    char unk0x122[8];
    unsigned char nQuest;
    char unk0x12B[14];
    unsigned char nTransmogrify;
    char unk0x13A[4];
    unsigned char nGemApplyType;
    char unk0x13F[105];
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
struct D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90

struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x14];
    unsigned int dwItemFlags;
    char unk0x1C[0x0C];
    int dwFileIndex;
    char unk0x2C[0x19];
    unsigned char nInvPage;
    unsigned char unk_46[0x2];
};

struct D2SetItemsTxt
{
    char unk0x00[0x2E];
    short nSetItems;
    char unk0x30[0x1B8 - 0x30];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC18];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pPlayer, int bEquipping, int* a4, int* a5, int* a6); // 0x0062EAF0


int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0
__declspec(noinline) int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);

// 0x00629570
int __stdcall ITEMS_GetMaxStack(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3407);

    return pItemsTxtRecord->dwMaxStack;
}

// 0x00629620
int __stdcall ITEMS_GetSpawnStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3436);

    return pItemsTxtRecord->dwSpawnStack;
}

// 0x006296B0
int __stdcall ITEMS_GetMinStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3466);

    return pItemsTxtRecord->dwMinStack;
}

// 0x00629A00
int __stdcall ITEMS_GetGemApplyTypeFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3880);

    return pItemsTxtRecord->nGemApplyType;
}

// 0x0062A060
unsigned int __stdcall ITEMS_GetTransmogrifyFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4437);

    return pItemsTxtRecord->nTransmogrify != 0;
}

// 0x0062B4D0
int __stdcall ITEMS_GetQuestFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    if (!ITEMS_CheckItemTypeIdByItemId(nItemId, 50) && !ITEMS_CheckItemTypeIdByItemId(nItemId, 45))
    {
        return 0;
    }

    if (pItemsTxtRecord->dwUberCode != pItemsTxtRecord->dwCode && pItemsTxtRecord->dwUltraCode != pItemsTxtRecord->dwCode)
    {
        return 0;
    }

    struct D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pRecord, 1677);
    if (pRecord->wType[0] == 38)
    {
        return 0;
    }

    return !pItemsTxtRecord->nQuest;
}

// 0x006295B0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3418);
    D2_ASSERT(pItem->dwUnitType == 4, 3419);

    int nMaxStack = ITEMS_GetMaxStack(pItem->dwClassId) + STATLIST_UnitGetStatValue(pItem, 254, 0);
    if (nMaxStack >= 511)
    {
        nMaxStack = 511;
    }

    return nMaxStack;
}

// 0x00629660
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3451);
    D2_ASSERT(pItem->dwUnitType == 4, 3452);

    return ITEMS_GetSpawnStackFromItemId(pItem->dwClassId);
}

// 0x006296F0
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3475);
    D2_ASSERT(pItem->dwUnitType == 4, 3476);

    return ITEMS_GetMinStackFromItemId(pItem->dwClassId);
}

// 0x00629A40
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3901);
    D2_ASSERT(pItem->dwUnitType == 4, 3902);

    return ITEMS_GetGemApplyTypeFromItemId(pItem->dwClassId);
}

// 0x0062A0A0
unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4450);
    D2_ASSERT(pItem->dwUnitType == 4, 4451);

    return ITEMS_GetTransmogrifyFromItemId(pItem->dwClassId);
}

// 0x0062B560
int __stdcall ITEMS_GetQuest(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1932);
    D2_ASSERT(pItem->dwUnitType == 4, 1933);

    return ITEMS_GetQuestFromItemId(pItem->dwClassId);
}

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

    return ITEMQUAL_NORMAL;
}

inline D2ItemDataStrc* ITEMS_GetItemDataByType(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return (nType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_CheckItemFlagInline(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
        return pItemData->dwItemFlags & dwFlag;

    return 0;
}

inline int ITEMS_CanBeEquippedInline(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}

// 0x0062A490
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemQualityInline(pItem) == ITEMQUAL_SET)
    {
        const int nFileIndex = ITEMS_GetFileIndex(pItem);
        if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
        {
            return &sgptDataTables->pSetItemsTxt[nFileIndex];
        }
    }

    return 0;
}

// 0x0062A620
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue)
{
    int nResult = nValue;

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        switch (pPlayer->dwClassId)
        {
        case PCLASS_SORCERESS:
        case PCLASS_NECROMANCER:
        case PCLASS_DRUID:
            nResult = 2 * nValue;
            break;
        case PCLASS_AMAZON:
        case PCLASS_PALADIN:
        case PCLASS_ASSASSIN:
            nResult = nValue + (nValue >> 1);
            break;
        }
    }

    return nResult;
}

// 0x0062FF70
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (!ITEMS_CanBeEquippedInline(pItem))
        return FALSE;

    if (!ITEMS_CheckItemTypeId(pItem, ITEMTYPE_CHARM))
        return FALSE;

    D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem);
    if (!pItemData)
        return FALSE;

    if (pItemData->nInvPage != INVPAGE_INVENTORY)
        return FALSE;

    return ITEMS_CheckRequirements(pItem, pPlayer, FALSE, 0, 0, 0) != 0;
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

// 0x0062A8D0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & IFLAG_ETHEREAL;
    }

    return 0;
}

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
