struct D2ItemsTxt
{
    char unk0x00[192];
    unsigned int dwWeapClass;
    char unk0xC4[90];
    short wType[2];
    char unk0x122[15];
    unsigned char nAutoBelt;
    char unk0x132[11];
    unsigned char n1or2Handed;
    char unk0x13E[106];
};
struct D2ItemTypesTxt
{
    char unk0x00[14];
    short wQuiver;
    unsigned char nThrowable;
    char unk0x11[16];
    unsigned char nClass;
    char unk0x22[194];
};
struct D2ItemDataStrc
{
    char unk0x00[12];
    int dwOwnerGUID;
    char unk0x10[8];
    unsigned int dwItemFlags;
    int dwRealmData[2];
    char unk0x24[4];
    unsigned int dwFileIndex;
    char unk0x2C[4];
    unsigned short wItemFormat;
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
    char unk0x00[3064];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
    int nItemTypesIndex;
    unsigned int* pItemTypesEquivalenceLUTs;
};
struct D2InventoryStrc;

struct D2WeaponClassCodeStrc
{
    unsigned int dwCode;
    int nWeaponClassId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
extern D2WeaponClassCodeStrc gWeaponClassTable[];                                                           // 0x007446A0
extern unsigned int gnWeaponClassTableCount;                                                                // 0x007446E0
int __stdcall ITEMS_CheckItemTypeId(const D2UnitStrc* pItem, int nItemType);                                // 0x00629BB0
int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId);                                                    // 0x00629D40
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pItem);             // 0x0063C560

#define UNIT_ITEM 4
#define UNIT_PLAYER 0
#define PCLASS_BARBARIAN 4
#define IFLAG_NOSELL 0x00001000
#define ITEMTYPE_SOCKET_FILLER 0x35
#define NUMBER_OF_PLAYERCLASSES 7
#define WEAPONCLASS_HTH 0
#define TRUE 1
#define FALSE 0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

inline int ITEMS_CheckTypeEquivalenceFromLUT(unsigned int* pEquivalenceLUT, int nItemType)
{
    return pEquivalenceLUT[nItemType >> 5] & gdwBitMasks[nItemType & 0x1F];
}

inline unsigned int* ITEMS_TypeEquivalenceLUT(int nItemTypeLUT)
{
    return &sgptDataTables->pItemTypesEquivalenceLUTs[nItemTypeLUT * sgptDataTables->nItemTypesIndex];
}

// 0x00628480
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wQuiver;
}

// 0x006287B0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet)
{
    if (bSet)
    {
        *pFlags |= nFlag;
    }
    else
    {
        *pFlags &= ~nFlag;
    }
}

// 0x00628860
int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->nThrowable;
}

// 0x00629B50
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2)
{
    if (nItemType1 >= 0 && nItemType1 < sgptDataTables->nItemTypesTxtRecordCount && nItemType2 >= 0 && nItemType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return ITEMS_CheckTypeEquivalenceFromLUT(ITEMS_TypeEquivalenceLUT(nItemType1), nItemType2);
    }

    return FALSE;
}

// 0x00629DF0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex)
{
    D2_ASSERT(pItem, 4220);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4221);
    D2_ASSERT(pItem->pItemData, 4223);
    pItem->pItemData->dwFileIndex = dwFileIndex;
}

// 0x00629E40
void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            *pRealmData0 = 0;
            *pRealmData1 = 0;
            return;
        }

        *pRealmData0 = pItemData->dwRealmData[0];
        *pRealmData1 = pItemData->dwRealmData[1];
        return;
    }

    *pRealmData0 = 0;
    *pRealmData1 = 0;
}

// 0x00629ED0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID)
{
    D2_ASSERT(pItem, 4284);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4285);
    D2_ASSERT(pItem->pItemData, 4287);
    pItem->pItemData->dwOwnerGUID = nOwnerGUID;
}

// 0x00629F20
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4295);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4296);
    D2_ASSERT(pItem->pItemData, 4298);
    return pItem->pItemData->dwOwnerGUID;
}

// 0x00629F70
int __stdcall ITEMS_IsClassValidByItemId(int nItemId)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = 0;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 1677);

    pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(pItemsTxtRecord->wType[0]);
    if (!pItemTypesTxtRecord)
    {
        return FALSE;
    }

    return pItemTypesTxtRecord->nClass < NUMBER_OF_PLAYERCLASSES;
}

// 0x00629FE0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem)
{
    int nItemId = 0;
    if (!pItem)
    {
        nItemId = -1;
    }
    else
    {
        nItemId = pItem->dwClassId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 4421);

    unsigned int nCounter = 0;
    while (nCounter < gnWeaponClassTableCount)
    {
        if (pItemsTxtRecord->dwWeapClass == gWeaponClassTable[nCounter].dwCode)
        {
            return (unsigned short)gWeaponClassTable[nCounter].nWeaponClassId;
        }

        ++nCounter;
    }

    return WEAPONCLASS_HTH;
}

// 0x0062A130
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem)
{
    if (!pItem || !ITEMS_CheckItemFlag(pItem, IFLAG_NOSELL))
    {
        if (ITEMS_IsNotQuestItemByItemId(!pItem ? -1 : pItem->dwClassId))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A1E0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4507);
    D2_ASSERT(pPlayer, 4509);

    if (pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->dwClassId == PCLASS_BARBARIAN)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 4517);

        if (pItemsTxtRecord->n1or2Handed)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A670
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 5380);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5381);
    D2_ASSERT(pItem->pItemData, 5383);
    return pItem->pItemData->wItemFormat;
}

// 0x0062A6C0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat)
{
    D2_ASSERT(pItem, 5391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5392);
    D2_ASSERT(pItem->pItemData, 5394);
    pItem->pItemData->wItemFormat = nItemFormat;
}

// 0x0062BEB0
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem)
{
    return ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SOCKET_FILLER);
}

#include "gen/data/Source/D2Common/00628480_ITEMS_GetQuiverTypeFromItemType.inc"
