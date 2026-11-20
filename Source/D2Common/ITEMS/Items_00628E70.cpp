#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
struct D2UnitStrc;

#define ITEMS_ADD_BONUS_COSTS(nMult, nAdd, nValue, nBuyDiv)                                        \
    if (*pSellCost * (nValue) > 0xFFFF && (nMult))                                          \
    {                                                                                       \
        nSell += *pSellCost * (nValue) / 1024 * (nMult) + (nAdd);                           \
        nBuy += *pBuyCost * (nValue) / (nBuyDiv) * (nMult) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nValue) / 1024 * (nMult) + (nAdd);                             \
    }                                                                                       \
    else                                                                                    \
    {                                                                                       \
        nSell += (nMult) * *pSellCost * (nValue) / 1024 + (nAdd);                           \
        nBuy += *pBuyCost * (nMult) * (nValue) / (nBuyDiv) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nMult) * (nValue) / 1024 + (nAdd);                             \
    }
#define IFLAG_NEWITEM 0x00080000
#define IFLAG_ISEAR 0x00010000
#define IFLAG_COMPACTSAVE 0x00200000
#define IFLAG_UNK_GAMBLE 0x02000000
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ETHEREAL 0x400000
struct D2InventoryStrc;
struct D2StatStrc;
struct D2SkillsTxt;
struct D2ItemStatCostTxt;
struct D2TimeModStrc;
union D2SeedStrc;
struct D2ItemDataStrc;
struct D2ItemsTxt;
struct D2RunesTxt;
struct D2RuneDataTbl;
struct D2StatesTxt;
struct D2MagicAffixTxt;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2GemsTxt;


struct D2SkillsTxt
{
    char unk0x00[0x234];
    int nCostMult;
    int nCostAdd;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x10];
    int dwMultiply;
    int dwAdd;
    unsigned char nValShift;
    unsigned char nSaveBits2;
    char unk0x1A[2];
    int dwSaveAdd;
    unsigned char unk_20[0x10];
    unsigned char nEncode;
    char unk0x31[0x144 - 0x31];
};


struct D2TimeModStrc
{
    int nPeriodOfDay;
    int nMin;
    int nMax;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304



int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pStatBuffer, int nBufferSize); // 0x00625C30
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2ItemDataStrc
{
    int dwQualityNo;
    char unk0x04[0x18 - 0x04];
    unsigned int dwItemFlags;
    char unk0x1C[0x2C - 0x1C];
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
    unsigned char unk_5A[0x2];
};

struct D2ItemsTxt
{
    char unk0x00[0xF0];
    int dwGemOffset;
    unsigned char unk_F4[0x36];
    unsigned char nQuantity;
    unsigned char nStackable;
    unsigned char unk_12C[0xB];
    unsigned char nHasInv;
    char unk0x138[0x09];
    unsigned char nTransform;
    unsigned char nInvTrans;
    unsigned char unk_143[0x1];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __stdcall sub_00629EA0(D2UnitStrc* pItem, int nFirst, int nSecond); // 0x00629EA0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat); // 0x0062A6C0
int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion); // 0x0062CBE0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
static __declspec(noinline) int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion);

struct D2RunesTxt
{
    char szName[64];
    char szRuneName[64];
    unsigned char bComplete;
    unsigned char bServer;
    unsigned short wStringId;
    unsigned short unk0x84;
    short wIType[6];
    short wEType[3];
    int nRune[6];
    char unk0xB0[0x70];
};


typedef char check_D2RunesTxt_size[sizeof(D2RunesTxt) == 0x120 ? 1 : -1];

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0
D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables(); // 0x00639CB0

struct D2StatesTxt
{
    char unk0x00[0x2A];
    short wItemType;
    unsigned char nItemTrans;
    char unk0x2D[0x0F];
};

struct D2MagicAffixTxt
{
    char unk0x00[0x56];
    unsigned char nTransformColor;
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x38];
    char nChrTransform;
    char nInvTransform;
};

struct D2SetItemsTxt
{
    char unk0x00[0x40];
    char nChrTransform;
    char nInvTransform;
};

struct D2GemsTxt
{
    char unk0x00[0x2F];
    unsigned char nTransform;
};

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerId); // 0x00629EA0

struct D2ItemTypesTxt
{
    char unk0x00[8];
    unsigned char nRepair;
};
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
static int sub_0062E5D0_IsQuantityRepairable(D2UnitStrc* pItem); // 0x0062E5D0

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x00628E70
void __fastcall ITEMS_CalculateAdditionalCostsForBonusStats(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor)
{
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    D2StatStrc pStat[511];
    D2TimeModStrc tTimeMod;
    int nStatId = 0;
    int nValue = 0;
    int nStats = 0;
    int nBuy = 0;
    int nSell = 0;
    struct
    {
        int i;
        int nRep;
    } tLoop;
    tLoop.nRep = 0;

    nStats = STATLIST_GetFullStatsDataFromUnit(pItem, pStat, 511);
    for (tLoop.i = 0; tLoop.i < nStats; ++tLoop.i)
    {
        nStatId = pStat[tLoop.i].nStat;
        nValue = STATLIST_GetUnitStatBonus(pItem, nStatId, pStat[tLoop.i].nLayer);
        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            if (pItemStatCostTxtRecord)
            {
                if (pItemStatCostTxtRecord->nValShift)
                    nValue >>= pItemStatCostTxtRecord->nValShift;

                switch (pItemStatCostTxtRecord->nEncode)
                {
                case 1:
                {
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pStat[tLoop.i].nLayer);
                    if (pSkillsTxtRecord)
                    {
                        ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nValue, 4096);
                    }
                    break;
                }
                case 2:
                case 3:
                {
                    const int nLayer = pStat[tLoop.i].nLayer;
                    const int nSkillId = nLayer >> sgptDataTables->nStuff;
                    const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
                    ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nLevel, 4096);
                    break;
                }
                case 4:
                {
                    ITEMMODS_GetByTimeAdjustment(nValue, 0, 0, &tTimeMod.nPeriodOfDay, &tTimeMod.nMin, &tTimeMod.nMax);
                    const int nAverage = (tTimeMod.nMax + tTimeMod.nMin) / 2;
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nAverage, 1024);
                    break;
                }
                default:
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nValue, 1024);
                    break;
                }
            }
        }
    }

    *pSellCost += nSell / nDivisor;
    *pBuyCost += nBuy / nDivisor;
    *pRepCost += tLoop.nRep / nDivisor;
}

inline void ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            if (bSet)
                pItemData->dwItemFlags |= dwFlag;
            else
                pItemData->dwItemFlags &= ~dwFlag;
        }
    }
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

inline void ITEMS_SetItemFlags(D2UnitStrc* pItem, unsigned int dwFlags)
{
    if (pItem)
    {
        switch (pItem->dwUnitType)
        {
        case UNIT_ITEM:
            if (pItem->pItemData)
                pItem->pItemData->dwItemFlags = dwFlags;
            break;
        }
    }
}

inline unsigned int ITEMS_GetItemFlags(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

inline void ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemLevel = nItemLevel;
}

inline void ITEMS_SetMagicPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicPrefix[nIndex] = nPrefix;
}

inline void ITEMS_SetMagicSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicSuffix[nIndex] = nSuffix;
}

inline void ITEMS_SetRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRarePrefix = nPrefix;
}

inline void ITEMS_SetRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRareSuffix = nSuffix;
}

inline void ITEMS_SetBodyLoc(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nBodyLoc = nBodyLoc;
}

inline void ITEMS_SetInvPage(D2UnitStrc* pItem, char nInvPage)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nInvPage = nInvPage;
}

inline void ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nEarLvl = nLevel;
}

inline char* ITEMS_GetEarName(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->szPlayerName;
    return 0;
}

static __forceinline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

static __forceinline unsigned int BITMANIP_ReadInl(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

static __forceinline int ITEMS_ReadQuestItemDifficultyForceInl(D2BitBufferStrc* pBuffer, D2ItemStatCostTxt* pRecord)
{
    return (BITMANIP_ReadInl(pBuffer, pRecord->nSaveBits2) - pRecord->dwSaveAdd) << pRecord->nValShift;
}

// 0x0062A970
static int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion)
{
    ITEMS_SetItemFormat(pItem, (unsigned short)sub_00411020_ReadBits(pBuffer, 10));

    const int nAnimMode = sub_00411020_ReadBits(pBuffer, 3);
    if (nAnimMode == 3 || nAnimMode == 5)
    {
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
    }
    else
    {
        ITEMS_SetBodyLoc(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        ITEMS_SetInvPage(pItem, (char)(sub_00411020_ReadBits(pBuffer, 3) - 1));
    }
    UNITS_ChangeAnimMode(pItem, nAnimMode);

    if (ITEMS_GetItemFlags(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarName(pItem);
        ITEMS_SetFileIndex(pItem, sub_00411020_ReadBits(pBuffer, 3));
        ITEMS_SetEarLevel(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 7));
        do
        {
            *szName = (char)sub_00411020_ReadBits(pBuffer, 7);
        }
        while (*szName++);
    }
    else
    {
        const unsigned int dwCode = sub_00411020_ReadBits(pBuffer, 32);
        const int nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
        if (pItem)
            pItem->dwClassId = nClassId;

        if (ITEMSIsA(pItem, 4))
        {
            if (sub_00411020_ReadBits(pBuffer, 1))
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 32), 0);
            else
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 12), 0);
        }

        if (ITEMSIsA(pItem, 22))
        {
            if (dwCode == ' cst')
                ITEMS_SetMagicSuffix(pItem, 0, 0);
            else if (dwCode == ' csi')
                ITEMS_AssignSuffix(pItem, 1, 0);
        }
    }

    if (dwVersion > 0x5C)
    {
        int nItemId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
        if (!pItemsTxtRecord)
            return -1;

        if (pItemsTxtRecord->nQuantity && pItemsTxtRecord->nStackable)
        {
            D2ItemStatCostTxt* pRecord = DATATBLS_GetItemStatCostTxtRecord(356);
            if (!pRecord)
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1607);
                exit(-1);
            }
            const int nValue = ITEMS_ReadQuestItemDifficultyForceInl(pBuffer, pRecord);
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, 0x40, 0, 4, !pItem ? -1 : pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            }
            STATLIST_SetStat(pStatList, 356, nValue, 0);
        }
    }

    if (bCheckForHeader && dwVersion > 0x56 && sub_00411020_ReadBits(pBuffer, 1))
    {
        const int nFirst = sub_00411020_ReadBits(pBuffer, 32);
        sub_00629EA0(pItem, nFirst, sub_00411020_ReadBits(pBuffer, 32));
        if (dwVersion > 0x5D)
            sub_00411020_ReadBits(pBuffer, 32);
    }

    pItem->dwInitSeed = 0;
    SEED_InitLowSeed(&pItem->pSeed, 0);
    ITEMS_SetItemLevel(pItem, 1);
    if (pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwQualityNo = 2;
    return 1;
}

static int ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && pItem->pItemData)
    {
        switch (pItem->pItemData->dwQualityNo)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwClassId;
    }
    return -1;
}

static __forceinline int ITEMS_IsOfType(D2UnitStrc* pItem, int nItemType)
{
    return ITEMSIsA(pItem, nItemType);
}

// 0x0062BED0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem)
{
    int nRuneItemIds[6];

    if (!pItem)
    {
        return 0;
    }

    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem))->nQuantity)
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pSocketFiller = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pSocketFiller)
    {
        return 0;
    }

    int nSocketedItems = 0;
    while (pSocketFiller)
    {
        D2UnitStrc* pRune = INVENTORY_UnitIsItem(pSocketFiller);
        if (!pRune)
        {
            return 0;
        }

        nRuneItemIds[nSocketedItems++] = pRune->dwClassId;
        pSocketFiller = INVENTORY_GetNextItem(pSocketFiller);
    }

    const int nSockets = ITEMS_GetSockets(pItem);
    if (nSockets != nSocketedItems)
    {
        return 0;
    }

    D2RuneDataTbl* pRuneDataTbl = DATATBLS_GetRuneDataTables();
    if (!pRuneDataTbl)
    {
        return 0;
    }

    for (int i = 0; i < pRuneDataTbl->nRunesTxtRecordCount; ++i)
    {
        D2RunesTxt* pRunesTxtRecord = &pRuneDataTbl->pRunesTxt[i];
        if (pRunesTxtRecord->bComplete)
        {
            int nRuneCounter = 0;
            bool bMatch = true;

            while (nRuneCounter < 6 && pRunesTxtRecord->nRune[nRuneCounter] > 0)
            {
                if (nSocketedItems < nRuneCounter || nRuneItemIds[nRuneCounter] != pRunesTxtRecord->nRune[nRuneCounter])
                {
                    bMatch = false;
                    break;
                }

                ++nRuneCounter;
            }

            if (bMatch && nRuneCounter >= nSockets)
            {
                bool isItemTypeIgnored = false;
                for (int nETypeCounter = 0; nETypeCounter < 3 && pRunesTxtRecord->wEType[nETypeCounter]; ++nETypeCounter)
                {
                    if (ITEMSIsA(pItem, pRunesTxtRecord->wEType[nETypeCounter]))
                    {
                        isItemTypeIgnored = true;
                        break;
                    }
                }

                if (!isItemTypeIgnored)
                {
                    for (int nITypeCounter = 0; nITypeCounter < 6 && pRunesTxtRecord->wIType[nITypeCounter]; ++nITypeCounter)
                    {
                        if (ITEMSIsA(pItem, pRunesTxtRecord->wIType[nITypeCounter]))
                        {
                            return pRunesTxtRecord;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

inline int ITEMS_CheckIfSocketable_Inl(D2UnitStrc* pItem)
{
    if (pItem && (!pItem ? 6 : pItem->dwUnitType) == 4)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            return pItemsTxtRecord->nHasInv;
        }
    }

    return 0;
}

inline unsigned int ITEMS_CheckItemFlag_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData_Inl(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4 && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQuality_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

inline unsigned short ITEMS_GetPrefixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicPrefix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetSuffixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicSuffix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetAutoAffix_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord_Inl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x0062A250
static unsigned char sub_0062A250(int nTransform, int nColor)
{
    if (nTransform <= 0 || nTransform >= 9 || nColor < 0 || nColor >= 0x15)
    {
        return 0;
    }

    unsigned char nPacked = nColor & 0x1F;
    nPacked += nTransform << 5;
    return nPacked;
}

// 0x0062C100
unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pColor, int nTransType)
{
    D2MagicAffixTxt* pMagicAffixTxtRecord;
    int i;

    if (pItem)
    {
        if (pPlayer)
        {
            for (int i = 0; i < sgptDataTables->nColourStates; ++i)
            {
                const short nState = sgptDataTables->pColourStates[i];
                if (STATES_CheckState(pPlayer, nState))
                {
                    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord_Inl(nState);
                    if (pStatesTxtRecord && pStatesTxtRecord->nItemTrans < 0x15 && ITEMSIsA(pItem, pStatesTxtRecord->wItemType))
                    {
                        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_00451F60_UnitClassId(pItem)))
                        {
                            return sub_00600C20(pItemsTxtRecord->nTransform, pStatesTxtRecord->nItemTrans);
                        }
                    }
                }
            }
        }

        switch (ITEMS_GetItemQuality_Inl(pItem))
        {
        case 4:
        case 6:
            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);

            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);
            break;

        case 7:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            if (ITEMS_GetFileIndex(pItem) < 0)
            {
                return 0;
            }

            D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pUniqueItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pUniqueItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nUniqueColor = pUniqueItemsTxtRecord->nChrTransform;
                *pColor = sub_0062A250(pItemsTxtRecord->nTransform, nUniqueColor);
                int const nInventoryTransform = pItemsTxtRecord->nInvTrans;
                return sub_00600C20(nInventoryTransform, pUniqueItemsTxtRecord->nInvTransform);
            }

            if (pUniqueItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
        }
        case 5:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pSetItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pSetItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nTransform = pItemsTxtRecord->nTransform;
                int const nSetColor = pSetItemsTxtRecord->nChrTransform;
                *pColor = sub_0062A250(nTransform, nSetColor);
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pSetItemsTxtRecord->nInvTransform);
            }

            if (pSetItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
        }
        default:
            if (ITEMS_CheckIfSocketable_Inl(pItem) && sub_0062BC20(pItem) > 0 && ITEMS_CheckItemFlag_Inl(pItem, 0x800))
            {
                D2InventoryStrc* pInventory = pItem->pInventory;
                D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pInventory);
                if (pInventoryItem)
                {
                    pInventoryItem = INVENTORY_UnitIsItem(pInventoryItem);
                    if (pInventoryItem && ITEMSIsA(pInventoryItem, 0x14))
                    {
                        D2ItemsTxt* pGemItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pInventoryItem ? -1 : pInventoryItem->dwClassId);
                        D2_ASSERT(pGemItemsTxtRecord, 0x1271);

                        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pGemItemsTxtRecord->dwGemOffset);
                        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                        *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                        if (nTransType)
                        {
                            return sub_00600C20(pItemsTxtRecord->nInvTrans, pGemsTxtRecord->nTransform);
                        }

                        return sub_00600C20(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                    }
                }
            }
            break;
        }

        pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix_Inl(pItem));
        if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

            if (nTransType)
            {
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
            }

            return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
        }
    }

    return 0;
}

inline void ITEMS_ClearItemFlags(D2UnitStrc* pItem)
{
    const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemFlags = 0;
}

// 0x0062E430
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail)
{
    D2BitBufferStrc tBuffer;
    int bGamble = 0;

    BITMANIP_Initialize(&tBuffer, pBitstream, nSize);
    if (bCheckForHeader && BITMANIP_ReadSigned(&tBuffer, 16) != 0x4D4A)
    {
        *pFail = 1;
        return 0;
    }

    *pFail = 0;

    unsigned int dwItemFlags = sub_00411020_ReadBits(&tBuffer, 32);
    if (dwItemFlags & IFLAG_UNK_GAMBLE)
    {
        bGamble = 1;
        dwItemFlags &= ~IFLAG_UNK_GAMBLE;
    }

    ITEMS_ClearItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwItemFlags, 1);
    ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 0);
    ITEMS_SetItemLevel(pItem, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 0);
    ITEMS_SetMagicSuffix(pItem, 0, 0);
    ITEMS_SetMagicPrefix(pItem, 0, 1);
    ITEMS_SetMagicSuffix(pItem, 0, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 2);
    ITEMS_SetMagicSuffix(pItem, 0, 2);
    ITEMS_SetRarePrefix(pItem, 0);
    ITEMS_SetRareSuffix(pItem, 0);

    if (dwItemFlags & IFLAG_COMPACTSAVE)
    {
        const int nResult = ITEMS_DecodeItemBitstreamCompact(pItem, &tBuffer, bCheckForHeader, dwVersion);
        if (pSocketedItemCount)
            *pSocketedItemCount = 0;
        if (nResult <= 0)
            *pFail = 1;
    }
    else
    {
        if (ITEMS_DecodeItemBitstreamComplete(pItem, &tBuffer, bCheckForHeader, bGamble, pSocketedItemCount, dwVersion) <= 0)
            *pFail = 1;
    }

    return BITMANIP_GetSize(&tBuffer);
}

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
