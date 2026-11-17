#include "D2Common.h"

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
#define UNIT_INVALID 6
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_SET 5
#define STAT_ITEM_CHARGED_SKILL 204
#define UNIT_MONSTER 1
#define IMODE_EQUIP 1
#define PCLASS_INVALID 7
#define STAT_STRENGTH 0
#define STAT_DEXTERITY 2
#define STAT_LEVEL 12
#define STAT_QUANTITY 70
#define STAT_ITEM_REQ_PERCENT 91
#define ITEMTYPE_BOOK 18
#define MONSTER_ACT5HIRE1 560
#define MONSTER_ACT5HIRE2 561
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ETHEREAL 0x400000

struct D2InventoryStrc;
struct D2ItemsTxt;
struct D2ItemDataStrc;
struct D2WeaponClassCodeStrc;
struct D2StatStrc;
struct D2SetItemsTxt;

struct D2ItemsTxt
{
    char unk0x00[192];
    unsigned int dwWeapClass;
    unsigned char unk_C4[0x46];
    unsigned short wReqStr;
    unsigned short wReqDex;
    unsigned char unk_10E[0x10];
    short wType[2];
    char unk0x122[15];
    unsigned char nAutoBelt;
    unsigned char unk_132[0x5];
    unsigned char nHasInv;
    unsigned char unk_138[0x5];
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
    int dwQualityNo;
    unsigned char unk_04[0x8];
    int dwOwnerGUID;
    char unk0x10[8];
    unsigned int dwItemFlags;
    int dwRealmData[2];
    char unk0x24[4];
    unsigned int dwFileIndex;
    char unk0x2C[4];
    unsigned short wItemFormat;
    unsigned char unk_32[0x2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[12];
    D2ItemDataStrc* pItemData;
    char unk0x18[0x60 - 0x18];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x00[3064];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
    int nItemTypesIndex;
    unsigned int* pItemTypesEquivalenceLUTs;
    unsigned char unk_C08[0x10];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

struct D2WeaponClassCodeStrc
{
    unsigned int dwCode;
    int nWeaponClassId;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern D2WeaponClassCodeStrc gWeaponClassTable[]; // 0x007446A0
extern unsigned int gnWeaponClassTableCount; // 0x007446E0
int __stdcall ITEMS_CheckItemTypeId(const D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId); // 0x00629D40
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C560

struct D2StatStrc
{
    int nLayer_StatId;
    int nValue;
};

struct D2SetItemsTxt
{
    char unk0x00[0x2E];
    short nSetItems;
    char unk0x30[0x1B8 - 0x30];
};

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __fastcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062B5B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

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

#include "gen/data/Source/D2Common/ITEMS/Items_00628480.inc"

inline int ITEMS_GetItemQualityInline(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
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

// 0x0062A840
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills)
{
    D2StatStrc pStat[64];

    if (pHasChargedSkills)
    {
        *pHasChargedSkills = 1;
    }

    int bResult = 0;
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    if (nStats > 0)
    {
        bResult = 1;

        if (pHasChargedSkills)
        {
            for (int i = 0; i < nStats; ++i)
            {
                if ((pStat[i].nValue & 0xFF) < (pStat[i].nValue >> 8))
                {
                    *pHasChargedSkills = 0;
                    break;
                }
            }
        }
    }

    return bResult;
}

// 0x0062B3A0
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem)
{
    if (D2SetItemsTxt* pSetItemsTxtRecord = ITEMS_GetSetItemsTxtRecordFromItem(pItem))
    {
        return pSetItemsTxtRecord->nSetItems;
    }

    return -1;
}

inline int ITEMS_CheckIfSocketableByItemIdInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }
    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
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

// 0x0062B450
static void __stdcall sub_0062B450_GetSocketedStatBonus(int nStatId, int* pValue, D2UnitStrc* pItem)
{
    *pValue = 0;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (ITEMS_CheckIfSocketableByItemIdInl(pItem->dwClassId))
        {
                D2InventoryStrc* pInventory = pItem->pInventory;
            for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
            {
                D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
                if (sub_00451F70_GetUnitMode(pItem) == IMODE_EQUIP)
                {
                    *pValue += STATLIST_UnitGetStatValue(pSocketed, nStatId, 0);
                }
            }
        }
    }
}

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel)
{
    if (pStrength)
    {
        *pStrength = FALSE;
    }
    if (pDexterity)
    {
        *pDexterity = 0;
    }
    if (pLevel)
    {
        *pLevel = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2ItemsTxt* pItemsTxtRecord = nType == UNIT_ITEM ? DATATBLS_GetItemsTxtRecord(pItem->dwClassId) : 0;
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int bStrReqMet = TRUE;
    int bDexReqMet = TRUE;
    int bLevelReqMet = TRUE;
    const int bIdentified = ITEMS_CheckItemFlagInl(pItem, IFLAG_IDENTIFIED);
    const int nBaseReqStr = pItemsTxtRecord->wReqStr;
    const int nBaseReqDex = pItemsTxtRecord->wReqDex;

    int nReqStrBonus = 0;
    int nReqDexBonus = 0;
    if (const int nReqPctBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_REQ_PERCENT, 0))
    {
        nReqStrBonus = DATATBLS_ApplyRatio(nBaseReqStr, nReqPctBonus, 100);
        nReqDexBonus = DATATBLS_ApplyRatio(nBaseReqDex, nReqPctBonus, 100);
    }

    if (ITEMS_CheckItemFlagInl(pItem, IFLAG_ETHEREAL))
    {
        nReqStrBonus -= 10;
        nReqDexBonus -= 10;
    }

    const int nStrength = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    if (nStrength <= 0)
    {
        bStrReqMet = 0;
    }
    else
    {
        const int nReqStr = nBaseReqStr + nReqStrBonus;
        if (nStrength < nReqStr)
        {
            bStrReqMet = 0;
        }
        else if (bEquipping && STATLIST_GetOwner(pItem, 0))
        {
            int nSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_STRENGTH, &nSocketBonus, pItem);
            const int nAdjusted = nStrength - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bStrReqMet = 0;
            }
            else if (nAdjusted < nReqStr)
            {
                bStrReqMet = 0;
            }
        }
    }

    const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
    if (nDexterity <= 0)
    {
        bDexReqMet = 0;
    }
    else
    {
        const int nReqDex = nBaseReqDex + nReqDexBonus;
        if (nDexterity < nReqDex)
        {
            bDexReqMet = 0;
        }
        else if (bEquipping)
        {
            int nSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_DEXTERITY, &nSocketBonus, pItem);
            const int nAdjusted = nDexterity - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bDexReqMet = 0;
            }
            if (nAdjusted < nReqDex)
            {
                bDexReqMet = 0;
            }
        }
    }

    const int nLevelReq = ITEMS_GetLevelRequirement(pItem, pUnit);
    if (nLevelReq != -1 && STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) < nLevelReq)
    {
        bLevelReqMet = 0;
    }

    if (pStrength)
    {
        *pStrength = bStrReqMet;
    }
    if (pDexterity)
    {
        *pDexterity = bDexReqMet;
    }
    if (pLevel)
    {
        *pLevel = bLevelReqMet;
    }

    if (bStrReqMet && bDexReqMet && bLevelReqMet && bIdentified)
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) <= 0)
        {
            return 0;
        }

        const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
        if (nClass == PCLASS_INVALID)
        {
            return 1;
        }

        if (!pUnit)
        {
            return 0;
        }

        const int nUnitType = pUnit->dwUnitType;
        if (nUnitType == UNIT_MONSTER && nClass == PCLASS_BARBARIAN)
        {
            const int nMonsterId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
            if (nMonsterId >= MONSTER_ACT5HIRE1 && nMonsterId <= MONSTER_ACT5HIRE2)
            {
                return 1;
            }
        }

        if (nUnitType == UNIT_PLAYER && nClass == pUnit->dwClassId)
        {
            return 1;
        }
    }

    return 0;
}
