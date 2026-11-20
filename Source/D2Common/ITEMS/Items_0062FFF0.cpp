#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2InventoryStrc;



struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x18 - 0x04];
    unsigned int dwItemFlags;
    int dwRealmData[2];
    char unk0x24[0x2C - 0x24];
    int dwItemLevel;
    unsigned short wItemFormat;
    unsigned short wRarePrefix;
    unsigned short wRareSuffix;
    unsigned short wAutoAffix;
    unsigned short wMagicPrefix[3];
    unsigned short wMagicSuffix[3];
    unsigned char nBodyLoc;
    char nInvPage;
    char unk0x46[2];
    unsigned char nEarLvl;
    unsigned char nInvGfxIdx;
    char szPlayerName[16];
};


struct D2ItemsTxt
{
    char unk0x00[0x137];
    unsigned char nHasInv;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits;
    char unk0x1A[2];
    int dwSaveAdd;
    char unk0x20[4];
    int dwSaveParamBits;
    char unk0x28[0x144 - 0x28];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[4];
    int nItemStatCostTxtRecordCount;
};

struct D2RunesTxt
{
    char unk0x00[0x82];
    unsigned short wStringId;
};

struct D2MagicAffixTxt
{
    char unk0x00[0x90];
};

struct D2MagicAffixDataTbl
{
    int nMagicAffixTxtRecordCount;
    D2MagicAffixTxt* pMagicAffixTxt;
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo);                               // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80
unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0
unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                // 0x00628590
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem);                                              // 0x006287D0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1);                   // 0x00629E40
static int __stdcall sub_0062A900_GetSocketedItemCount(D2UnitStrc* pItem);                                  // 0x0062A900
static void __stdcall ITEMS_WriteBitsToBitstream(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits); // 0x0062AF50
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem);                             // 0x0062BED0
unsigned char __stdcall sub_0062E8D0_HasAltInvGfx(D2UnitStrc* pItem);                                       // 0x0062E8D0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables();                                          // 0x00633ED0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

#define ITEMQUAL_SUPERIOR 3
#define ITEMQUAL_RARE 6
#define ITEMQUAL_UNIQUE 7
#define ITEMQUAL_CRAFT 8
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ISEAR 0x10000

static __forceinline void ITEMS_WriteBitsCoreInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

static __forceinline void ITEMS_WriteBitsRevInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    ITEMS_WriteBitsCoreInl(pBuffer, nData, nBits);
}
#define ITEMS_WriteBitsInl(nBits, nData, pBuffer) ITEMS_WriteBitsRevInl(pBuffer, nData, nBits)

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

static __forceinline unsigned int ITEMS_GetItemFlagsInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->dwItemFlags : 0;
}

static __forceinline unsigned int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

static __forceinline int ITEMS_GetItemQualityInl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem))
    {
        return pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static __forceinline D2ItemDataStrc* ITEMS_GetItemDataTypedInl(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (nUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

static __forceinline int ITEMS_GetItemQualityTypedInl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataTypedInl(pItem))
    {
        return pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static __forceinline void ITEMS_SetItemQualityInl(D2UnitStrc* pItem, int nQuality)
{
    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->dwQualityNo = nQuality;
    }
}

static __forceinline int ITEMS_GetItemLevelInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 1;
        }

        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }
    return 1;
}

static __forceinline unsigned char ITEMS_GetBodyLocationInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nBodyLoc;
    }
    return 0;
}

static __forceinline unsigned char ITEMS_GetInvPageInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 0xFF;
        }
        return pItemData->nInvPage;
    }
    return 0xFF;
}

static __forceinline unsigned char ITEMS_GetInvGfxIndexInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvGfxIdx;
    }
    return 0;
}

static __forceinline unsigned short ITEMS_GetAutoAffixInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wAutoAffix;
    }
    return 0;
}

static __forceinline unsigned short ITEMS_GetMagicPrefixInl(D2UnitStrc* pItem, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            return pItemData->wMagicPrefix[nIndex];
        }
    }
    return 0;
}

static __forceinline unsigned short ITEMS_GetMagicSuffixInl(D2UnitStrc* pItem, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            return pItemData->wMagicSuffix[nIndex];
        }
    }
    return 0;
}

static __forceinline unsigned char ITEMS_GetEarLevelInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 1;
        }
        return pItemData->nEarLvl;
    }
    return 1;
}

static __forceinline char* ITEMS_GetEarNameInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->szPlayerName : 0;
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordConstInl(int nStatId)
{
    if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordInl(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static __forceinline unsigned short ITEMS_GetRunewordStringIdInl(D2UnitStrc* pItem)
{
    const D2RunesTxt* pRunesTxtRecord = ITEMS_GetRunesTxtRecordFromItem(pItem);
    return pRunesTxtRecord ? pRunesTxtRecord->wStringId : 0xFFFF;
}

__declspec(noinline) unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem))
    {
        return pItemData->wMagicPrefix[nPrefixNo];
    }

    return 0;
}

__declspec(noinline) unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem))
    {
        return pItemData->wMagicSuffix[nSuffixNo];
    }

    return 0;
}

__declspec(noinline) unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wRarePrefix;
    }
    return 0;
}

__declspec(noinline) unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wRareSuffix;
    }
    return 0;
}

__declspec(noinline) unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

__declspec(noinline) void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1)
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

static __declspec(noinline) int __stdcall sub_0062A900_GetSocketedItemCount(D2UnitStrc* pItem)
{
    int nCount = 0;

    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pItem->pInventory;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    if (!pItemsTxtRecord || !pItemsTxtRecord->nHasInv || !pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pChild = INVENTORY_GetFirstItem(pInventory); pChild; pChild = INVENTORY_GetNextItem(pChild))
    {
        ++nCount;
    }

    return nCount;
}

static __declspec(noinline) void __stdcall ITEMS_WriteBitsToBitstream(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

static __forceinline void ITEMS_WriteBitsCallInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    ITEMS_WriteBitsToBitstream(pBuffer, nData, nBits);
}
#define ITEMS_WriteBitsCall(nBits, nData, pBuffer) ITEMS_WriteBitsCallInl(pBuffer, nData, nBits)

static __forceinline unsigned short ITEMS_GetItemFormatInl(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 5380);
    const int nUnitType = pItem ? pItem->dwUnitType : 6;
    D2_ASSERT(nUnitType == UNIT_ITEM, 5381);
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    D2_ASSERT(pItemData, 5383);
    return pItemData->wItemFormat;
}

// 0x0062FFF0
static void __stdcall ITEMS_SerializeItemComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bGamble)
{
    D2StatStrc aStats[511];
    int anValues[511];
    int bInvalidQuality = 0;

    ITEMS_WriteBitsInl(10, ITEMS_GetItemFormatInl(pItem), pBuffer);
    ITEMS_WriteBitsInl(3, pItem->dwAnimMode, pBuffer);

    if (pItem->dwAnimMode != IMODE_ONGROUND && pItem->dwAnimMode != IMODE_DROPPING)
    {
        ITEMS_WriteBitsInl(4, ITEMS_GetBodyLocationInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(4, (((UNITS_GetXPositionForceInl(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitX(pItem) : 0u) < 15u) ? ((CLIENTS_GetUnitX(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitX(pItem) : 0u) : 15u, pBuffer);
        ITEMS_WriteBitsInl(4, (((UNITS_GetYPositionForceInl(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitY(pItem) : 0u) < 15u) ? ((CLIENTS_GetUnitY(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitY(pItem) : 0u) : 15u, pBuffer);
        ITEMS_WriteBitsInl(3, (char)(ITEMS_GetInvPageInl(pItem) + 1), pBuffer);
    }
    else
    {
        ITEMS_WriteBitsInl(16, UNITS_GetXPositionForceInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(16, UNITS_GetYPositionForceInl(pItem), pBuffer);
    }

    if (bGamble)
    {
        ITEMS_WriteBitsInl(32, ITEMS_GetNormalCode(pItem), pBuffer);
        return;
    }

    ITEMS_WriteBitsInl(32, ITEMS_GetBaseCode(pItem), pBuffer);
    ITEMS_WriteBitsInl(3, sub_0062A900_GetSocketedItemCount(pItem), pBuffer);

    if (bServer)
    {
        ITEMS_WriteBitsInl(32, pItem->dwInitSeed, pBuffer);
    }

    ITEMS_WriteBitsInl(7, D2_MIN(ITEMS_GetItemLevelInl(pItem), 99), pBuffer);
    ITEMS_WriteBitsInl(4, ITEMS_GetItemQualityInl(pItem), pBuffer);

    ITEMS_WriteBitsInl(1, sub_0062E8D0_HasAltInvGfx(pItem) != 0, pBuffer);
    if (sub_0062E8D0_HasAltInvGfx(pItem))
    {
        ITEMS_WriteBitsInl(3, ITEMS_GetInvGfxIndexInl(pItem), pBuffer);
    }

    D2MagicAffixDataTbl* pMagicAffixDataTbl = DATATBLS_GetMagicAffixDataTables();
    const int nPrefixOffset = pMagicAffixDataTbl->pMagicPrefix - pMagicAffixDataTbl->pMagicAffixTxt;
    const int nAutoAffixOffset = pMagicAffixDataTbl->pAutoMagic - pMagicAffixDataTbl->pMagicAffixTxt;

    unsigned short nAutoAffix = ITEMS_GetAutoAffixInl(pItem);
    if (nAutoAffix > nAutoAffixOffset)
    {
        nAutoAffix -= nAutoAffixOffset;
    }

    ITEMS_WriteBitsInl(1, nAutoAffix != 0, pBuffer);
    if (nAutoAffix)
    {
        ITEMS_WriteBitsInl(11, nAutoAffix, pBuffer);
    }

    switch (ITEMS_GetItemQualityTypedInl(pItem))
    {
    case ITEMQUAL_INFERIOR:
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        break;

    case ITEMQUAL_SUPERIOR:
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        break;

    case ITEMQUAL_RARE:
    case ITEMQUAL_CRAFT:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_WriteBitsInl(8, ITEMS_GetRarePrefixId(pItem), pBuffer);
            ITEMS_WriteBitsInl(8, ITEMS_GetRareSuffixId(pItem), pBuffer);
        }

        for (int i = 0; i < 3; ++i)
        {
            unsigned short nPrefix = ITEMS_GetMagicPrefixInl(pItem, i);
            if (nPrefix > nPrefixOffset)
            {
                nPrefix -= nPrefixOffset;
            }

            if (nPrefix)
            {
                ITEMS_WriteBitsInl(1, 1, pBuffer);
                ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
            }
            else
            {
                ITEMS_WriteBitsInl(1, 0, pBuffer);
            }

            const unsigned short nSuffix = ITEMS_GetMagicSuffixInl(pItem, i);
            if (nSuffix)
            {
                ITEMS_WriteBitsInl(1, 1, pBuffer);
                ITEMS_WriteBitsInl(11, nSuffix, pBuffer);
            }
            else
            {
                ITEMS_WriteBitsInl(1, 0, pBuffer);
            }
        }
        break;

    case ITEMQUAL_TEMPERED:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_WriteBitsInl(8, ITEMS_GetRarePrefixId(pItem), pBuffer);
            ITEMS_WriteBitsInl(8, ITEMS_GetRareSuffixId(pItem), pBuffer);
        }
        break;

    case ITEMQUAL_MAGIC:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            unsigned short nPrefix = ITEMS_GetPrefixId(pItem, 0);
            const unsigned short nSuffix = ITEMS_GetSuffixId(pItem, 0);
            if (nPrefix > nPrefixOffset)
            {
                nPrefix -= nPrefixOffset;
            }

            ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
            ITEMS_WriteBitsInl(11, nSuffix, pBuffer);
        }
        break;

    case ITEMQUAL_SET:
    case ITEMQUAL_UNIQUE:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            int nFileIndex = ITEMS_GetFileIndex(pItem);
            if (nFileIndex < 0)
            {
                nFileIndex = 0xFFF;
            }

            ITEMS_WriteBitsInl(12, nFileIndex, pBuffer);
        }
        break;

    default:
        if (ITEMS_GetItemQualityTypedInl(pItem) != ITEMQUAL_NORMAL)
        {
            ITEMS_SetItemQualityInl(pItem, ITEMQUAL_NORMAL);
            bInvalidQuality = 1;
        }

        if (ITEMS_CheckItemTypeId(pItem, 13))
        {
            if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
            {
                unsigned short nPrefix = ITEMS_GetMagicPrefixInl(pItem, 0);
                if (nPrefix > nPrefixOffset)
                {
                    nPrefix -= nPrefixOffset;
                }

                ITEMS_WriteBitsInl(1, nPrefix != 0, pBuffer);
                if (nPrefix)
                {
                    ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
                }
                else
                {
                    ITEMS_WriteBitsInl(11, ITEMS_GetSuffixId(pItem, 0), pBuffer);
                }
            }
        }

        if (ITEMS_CheckItemTypeId(pItem, 40) && !ITEMS_CheckItemTypeId(pItem, 7))
        {
            ITEMS_WriteBitsInl(10, ITEMS_GetFileIndex(pItem), pBuffer);
        }

        if (ITEMS_CheckItemTypeId(pItem, 22) || ITEMS_CheckItemTypeId(pItem, 18))
        {
            ITEMS_WriteBitsInl(5, ITEMS_GetMagicSuffixInl(pItem, 0), pBuffer);
        }
        break;
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_RUNEWORD)
    {
        ITEMS_WriteBitsInl(16, ITEMS_GetRunewordStringIdInl(pItem), pBuffer);
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarNameInl(pItem);
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        ITEMS_WriteBitsInl(7, ITEMS_GetEarLevelInl(pItem), pBuffer);
        do
        {
            ITEMS_WriteBitsInl(7, *szName, pBuffer);
        }
        while (*szName++);
    }
    else if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_PERSONALIZED)
    {
        char* szName = ITEMS_GetEarNameInl(pItem);
        do
        {
            ITEMS_WriteBitsInl(7, *szName, pBuffer);
        }
        while (*szName++);
    }

    if (bServer)
    {
        int nRealmData0 = 0;
        int nRealmData1 = 0;
        ITEMS_GetRealmData(pItem, &nRealmData0, &nRealmData1);
        const int nRealm1 = nRealmData1;
        if (nRealm1)
        {
            ITEMS_WriteBitsInl(1, 1, pBuffer);
            ITEMS_WriteBitsInl(32, nRealmData0, pBuffer);
            ITEMS_WriteBitsInl(32, nRealm1, pBuffer);
            ITEMS_WriteBitsInl(32, 0, pBuffer);
        }
        else
        {
            ITEMS_WriteBitsInl(1, 0, pBuffer);
        }
    }

    if (ITEMS_CheckItemTypeId(pItem, 50))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(31);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_GetUnitBaseStat(pItem, 31, 0) + pItemStatCostTxtRecord->dwSaveAdd, pBuffer);

        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(73);
        const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 73, 0);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nMaxDurability, pBuffer);
        if (nMaxDurability)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(72);
            ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_UnitGetStatValue(pItem, 72, 0) + pItemStatCostTxtRecord->dwSaveAdd, pBuffer);
        }
    }
    else if (ITEMS_CheckItemTypeId(pItem, 45))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(73);
        const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 73, 0);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nMaxDurability, pBuffer);
        if (nMaxDurability)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(72);
            ITEMS_WriteBitsToBitstream(pBuffer, STATLIST_UnitGetStatValue(pItem, 72, 0) + pItemStatCostTxtRecord->dwSaveAdd, pItemStatCostTxtRecord->nSaveBits);
        }
    }
    else if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_GOLD))
    {
        const int nGold = STATLIST_UnitGetStatValue(pItem, 14, 0);
        ITEMS_WriteBitsInl(1, nGold >= 4096, pBuffer);
        ITEMS_WriteBitsToBitstream(pBuffer, nGold, (((nGold < 4096) - 1) & 20) + 12);
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        ITEMS_WriteBitsInl(9, STATLIST_UnitGetStatValue(pItem, 70, 0), pBuffer);
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_SOCKETED)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(194);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_GetUnitBaseStat(pItem, 194, 0), pBuffer);
    }

    if (!bServer && !(ITEMS_GetItemFlagsInl(pItem) & IFLAG_IDENTIFIED))
    {
        return;
    }

    int nStatLists = 0;
    const int nItemType = pItem ? pItem->dwUnitType : 6;
    if (nItemType == UNIT_ITEM && ITEMS_GetItemQualityInl(pItem) == ITEMQUAL_SET)
    {
        int nSetMask = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStates_006E90B8[i], 0x2040)
                || STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStates_006E90B8[i], 0x40))
            {
                if (pBuffer)
                {
                    nSetMask += 1 << i;
                    nStatLists = i + 1;
                }
                else
                {
                    nSetMask += 1 << i;
                    nStatLists = i + 1;
                }
            }
        }

        ITEMS_WriteBitsInl(5, nSetMask, pBuffer);
    }

    int bRuneword = 0;
    if (ITEMS_CheckItemFlagInl(pItem, IFLAG_RUNEWORD))
    {
        ++nStatLists;
        bRuneword = 1;
    }

    for (int nIndex = -1; nIndex < nStatLists; ++nIndex)
    {
        D2StatListStrc* pStatList = 0;
        if (nIndex < 0)
        {
            pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        }
        else if (bRuneword && nIndex == nStatLists - 1)
        {
            pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, 171, 0x40);
        }
        else
        {
            pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStates_006E90B8[nIndex], 0x2040);
            if (!pStatList)
            {
                pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStates_006E90B8[nIndex], 0x40);
            }
        }

        if (pStatList && !bInvalidQuality)
        {
            memset(anValues, 0, sizeof(anValues));
            const int nStats = STATLIST_GetBaseStatsData(pStatList, aStats, 511);
            for (int i = 0; i < nStats; ++i)
            {
                const int nStatId = (unsigned int)aStats[i].nPackedValue >> 16;
                const unsigned short nLayer = (unsigned short)aStats[i].nPackedValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord;
                if (nStats > 1)
                {
                    if (nStatId < 0)
                    {
                        goto L_NO_RECORD;
                    }
                }
                else
                {
                    if (nStatId < 0)
                    {
                        goto L_NO_RECORD;
                    }
                }
                if (nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
                }
                else
                {
L_NO_RECORD:
                    pItemStatCostTxtRecord = 0;
                }
                if (!pItemStatCostTxtRecord->nSaveBits)
                {
                    continue;
                }

                const int nValue = aStats[i].nValue >> pItemStatCostTxtRecord->nValShift;
                if (!nValue || !(nValue - anValues[nStatId]))
                {
                    continue;
                }

                ITEMS_WriteBitsInl(9, nStatId, pBuffer);

                if (nStatId <= 48)
                {
                    if (nStatId != 48)
                    {
                        if (nStatId == 17)
                        {
                    ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(18);
                    anValues[18] = STATLIST_GetStatValue(pStatList, 18, 0);
                    ITEMS_WriteBitsInl(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[18], pBuffer);
                        }
                        else
                        {
                    if (pItemStatCostTxtRecord->dwSaveParamBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->dwSaveParamBits, nLayer, pBuffer);
                    }

                    if (pItemStatCostTxtRecord->nSaveBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    }
                        }
                    }
                    else
                    {
                    ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(49);
                    anValues[49] = STATLIST_GetStatValue(pStatList, 49, 0);
                    ITEMS_WriteBitsInl(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[49], pBuffer);
                    }
                }
                else
                {
                switch (nStatId)
                {
                case 50:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(51);
                    anValues[51] = STATLIST_GetStatValue(pStatList, 51, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[51], pBuffer);
                    break;
                }
                case 52:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(53);
                    anValues[53] = STATLIST_GetStatValue(pStatList, 53, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[53], pBuffer);
                    break;
                }
                case 54:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(55);
                    anValues[55] = STATLIST_GetStatValue(pStatList, 55, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[55], pBuffer);
                    pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(56);
                    anValues[56] = STATLIST_GetStatValue(pStatList, 56, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[56], pBuffer);
                    break;
                }
                case 57:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(58);
                    anValues[58] = STATLIST_GetStatValue(pStatList, 58, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[58], pBuffer);
                    pNextRecord = sub_0045C4F0_GetItemStatCostTxtRecord(59);
                    anValues[59] = STATLIST_GetStatValue(pStatList, 59, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[59], pBuffer);
                    break;
                }
                case 326:
                    break;

                default:
                    if (pItemStatCostTxtRecord->dwSaveParamBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->dwSaveParamBits, nLayer, pBuffer);
                    }

                    if (pItemStatCostTxtRecord->nSaveBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    }
                    break;
                }
                }

            }
        }

        if (nIndex < 0 || pStatList || bRuneword)
        {
            ITEMS_WriteBitsInl(9, 0x1FF, pBuffer);
        }
    }
}

// calling-convention shim (not game code)
void __stdcall ITEMS_SerializeItemCompleteCaller(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bGamble)
{
    ITEMS_SerializeItemComplete(pItem, pBuffer, bServer, bGamble);
}

#include "gen/data/Source/D2Common/ITEMS/Items_0062FFF0.inc"
