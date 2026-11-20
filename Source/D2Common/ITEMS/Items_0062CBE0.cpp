#include "D2Common.h"
#include "D2Structs.h"


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
};


struct D2ItemsTxt
{
    char unk0x000[0xD0];
    int dwMaxAc;
    char unk0x0D4[0x04];
    int dwSpeed;
    char unk0x0DC[0x22];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
    char unk0x104[0x0D];
    unsigned char nBlock;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits[2];
    char pad0x1B[0x01];
    int dwSaveAdd[2];
    int dwSaveParamBits[2];
    char unk0x2C[0x144 - 0x2C];
};

struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB94];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xBCC - 0xBA4];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[4];
    int nItemStatCostTxtRecordCount;
    char unk0xBD8[0xC28 - 0xBD8];
    int nUniqueItemsTxtRecordCount;
    char unk0xC2C[0xC6C - 0xC2C];
    int nStuff;
    int nShiftedStuff;
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

struct D2SetItemsTxt
{
    short wSetItemId;
    char unk0x02[0x28 - 0x02];
    unsigned int dwItemCode;
};

struct D2SetsTxt
{
    char unk0x000[0x0C];
    int nSetItems;
    char unk0x010[0x110 - 0x010];
    D2SetItemsTxt* pSetItem[6];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
void* __fastcall sub_004DC0B0_GetNextRosterInfo(D2UnitStrc* pUnit);                                         // 0x004DC0B0
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006252D0(D2StatListStrc* pStatList, int nState);                                       // 0x006252D0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);     // 0x00625D00
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __fastcall sub_00627AF0_HasSkillDesc(int nSkillId);                                                     // 0x00627AF0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);                    // 0x00627EF0
void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);                    // 0x00627FB0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix);                           // 0x00628010
void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix);                                   // 0x00628070
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
void __stdcall sub_00629EA0(D2UnitStrc* pItem, int nRealmData0, int nRealmData1);                         // 0x00629EA0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat);                          // 0x0062A6C0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);                                                          // 0x0062A8D0
static void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109); // 0x0062AC80
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
void __stdcall sub_0062BE00_SetSockets(D2UnitStrc* pItem, int nSockets);                                    // 0x0062BE00
static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat);                               // 0x0062C9F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables();                                          // 0x00633ED0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __stdcall D2Common_10844_ITEMMODS_First(int nValue, int* pSkillId, int* pSkillValue);                  // 0x0065C7A0
void __stdcall D2Common_10846(int nValue, int* p1, int* p2, int* p3, int* p4);                              // 0x0065C7D0
void __stdcall D2Common_10845(int nValue, int* pSkillId, int* pSkillLevel, int* pChance);                   // 0x0065CB10
void __stdcall sub_0065CB60_DecodeAddSkillTab(int nValue, int* pClass, int* pTab, int* pLevel);             // 0x0065CB60

#define IFLAG_IDENTIFIED 0x10
#define IFLAG_ISEAR 0x10000

static __declspec(noinline) void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109)
{
    int nParamBits = pItemStatCostTxtRecord->dwSaveParamBits[n109];
    int nSaveBits = pItemStatCostTxtRecord->nSaveBits[n109];
    int nSaveAdd = pItemStatCostTxtRecord->dwSaveAdd[n109];
    int nParam = 0;

    switch (nStatId)
    {
    case 23:
        if (dwVersion <= 89)
            nSaveBits = 5;
        break;
    case 24:
        if (dwVersion <= 89)
            nSaveBits = 6;
        break;
    case 74:
        if (dwVersion <= 89)
        {
            nSaveBits = 5;
            nSaveAdd = 10;
        }
        break;
    case 79:
        if (dwVersion <= 89)
        {
            nSaveBits = 8;
            nSaveAdd = 20;
        }
        break;
    case 80:
        if (dwVersion <= 89)
        {
            nSaveBits = 7;
            nSaveAdd = 20;
        }
        break;
    case 93:
    case 96:
    case 99:
    case 102:
    case 105:
        if (dwVersion <= 87)
            nSaveBits = 6;
        break;
    case 92:
    case 94:
        if (dwVersion < 93)
            nStatId = 93;
        break;
    case 95:
    case 97:
        if (dwVersion < 93)
            nStatId = 96;
        break;
    case 98:
    case 100:
        if (dwVersion < 93)
            nStatId = 99;
        break;
    case 101:
    case 103:
        if (dwVersion < 93)
            nStatId = 102;
        break;
    case 104:
    case 106:
        if (dwVersion < 93)
            nStatId = 105;
        break;
    default:
        break;
    }

    if (nParamBits > 0)
        nParam = (unsigned short)sub_00411020_ReadBits(pBuffer, nParamBits);

    const unsigned int nValue = sub_00411020_ReadBits(pBuffer, nSaveBits);
    STATLIST_SetStatIfListIsValid(pStatList, nStatId, (nValue - nSaveAdd) << pItemStatCostTxtRecord->nValShift, nParam);
}

static __declspec(noinline) void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat)
{
    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (!pItemsTxtRecord)
        return;

    switch (nStat)
    {
    case 16:
    case 31:
        if (ITEMS_CheckItemTypeId(pItem, 50) && pItemsTxtRecord->dwMaxAc)
        {
            int nArmor = STATLIST_GetUnitBaseStat(pItem, 31, 0) + 1;
            if (nArmor <= pItemsTxtRecord->dwMaxAc)
                nArmor = pItemsTxtRecord->dwMaxAc + 1;
            STATLIST_SetUnitStat(pItem, 31, nArmor, 0);
        }
        break;
    case 17:
    case 22:
        if (ITEMS_CheckItemTypeId(pItem, 45))
        {
            const int nMax = STATLIST_GetUnitBaseStat(pItem, 22, 0);
            if (pItemsTxtRecord->nMaxDam && nMax < pItemsTxtRecord->nMaxDam)
                STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
            const int nMax2 = STATLIST_GetUnitBaseStat(pItem, 24, 0);
            if (pItemsTxtRecord->n2HandMaxDam && nMax2 < pItemsTxtRecord->n2HandMaxDam)
                STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
            const int nMaxMis = STATLIST_GetUnitBaseStat(pItem, 160, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMaxMisDam && nMaxMis < pItemsTxtRecord->nMaxMisDam)
                STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
        }
        break;
    case 18:
    case 21:
        if (ITEMS_CheckItemTypeId(pItem, 45))
        {
            const int nMin = STATLIST_GetUnitBaseStat(pItem, 21, 0);
            if (pItemsTxtRecord->nMinDam && nMin < pItemsTxtRecord->nMinDam)
                STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
            const int nMin2 = STATLIST_GetUnitBaseStat(pItem, 23, 0);
            if (pItemsTxtRecord->n2HandMinDam && nMin2 < pItemsTxtRecord->n2HandMinDam)
                STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
            const int nMinMis = STATLIST_GetUnitBaseStat(pItem, 159, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMinMisDam && nMinMis < pItemsTxtRecord->nMinMisDam)
                STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        }
        break;
    default:
        break;
    }
}

static __forceinline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecordInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

__declspec(noinline) int __fastcall sub_00627AF0_HasSkillDesc(int nSkillId)
{
    if (D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInl(nSkillId))
    {
        int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return 1;
    }
    return 0;
}

static __forceinline void ITEMS_SetBodyLocInl(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nBodyLoc = nBodyLoc;
    }
}

static __forceinline void ITEMS_SetInvPageInl(D2UnitStrc* pItem, char nInvPage)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nInvPage = nInvPage;
    }
}

static __forceinline void ITEMS_SetItemLevelInl(D2UnitStrc* pItem, int nItemLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        if (nItemLevel < 1)
        {
            nItemLevel = 1;
        }
        pItem->pItemData->dwItemLevel = nItemLevel;
    }
}

static __forceinline void ITEMS_SetItemQualityInl(D2UnitStrc* pItem, int nQuality)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->dwQualityNo = nQuality;
    }
}

static __forceinline int ITEMS_GetItemQualityInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static __forceinline void ITEMS_SetInvGfxIndexInl(D2UnitStrc* pItem, unsigned char nInvGfxIdx)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nInvGfxIdx = nInvGfxIdx;
    }
}

static __forceinline void ITEMS_SetAutoAffixInl(D2UnitStrc* pItem, unsigned short nAutoAffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wAutoAffix = nAutoAffix;
    }
}

static __forceinline void ITEMS_SetMagicPrefixInl(D2UnitStrc* pItem, int nIndex, int nPrefix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wMagicPrefix[nIndex] = nPrefix;
    }
}

static __forceinline void ITEMS_SetMagicSuffixInl(D2UnitStrc* pItem, int nIndex, int nSuffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wMagicSuffix[nIndex] = nSuffix;
    }
}

static __forceinline void ITEMS_SetEarLevelInl(D2UnitStrc* pItem, unsigned char nEarLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nEarLvl = nEarLevel;
    }
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

static __forceinline char* ITEMS_GetEarNameInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->szPlayerName : 0;
}

static __forceinline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetRecF3(int nStatId)
{
    if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordInl(int nStatId)
{
    if (nStatId < sgptDataTables->nItemStatCostTxtRecordCount && nStatId >= 0)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static __forceinline unsigned int BITMANIP_ReadInl(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

// 0x0062CBE0
static int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion)
{
    int bError = 0;
    int nStatLists;
    int nSetItemMask;
    int nTabLevel;
    int nSkillValue;
    unsigned int dwCode;
    int v237, v238, nSkillId, v240, v241, v242, v243, v244, v245, v246, v247, v248, v249, v250, v251, v252;
    int nLastStatId;
    D2ItemStatCostTxt* pItemStatCostTxtRecord;
    D2ItemsTxt* pItemsTxtRecord;
    D2StatListStrc* pStatList;
    char* szName;
    char szChar;
    int nValue;
    int nBits;
    int nStatId;

    ITEMS_SetItemFormat(pItem, BITMANIP_ReadInl(pBuffer, 10));

    const int nAnimMode = BITMANIP_ReadInl(pBuffer, 3);
    if (nAnimMode != IMODE_ONGROUND && nAnimMode != IMODE_DROPPING)
    {
        ITEMS_SetBodyLocInl(pItem, BITMANIP_ReadInl(pBuffer, 4));
        UNITS_SetXForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 4));
        UNITS_SetYForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 4));
        ITEMS_SetInvPageInl(pItem, BITMANIP_ReadInl(pBuffer, 3) - 1);
    }
    else
    {
        UNITS_SetXForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 16));
        UNITS_SetYForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 16));
    }

    UNITS_ChangeAnimMode(pItem, nAnimMode);

    dwCode = BITMANIP_ReadInl(pBuffer, 32);
    const int nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nClassId >= 0 && pItem)
    {
        pItem->dwClassId = nClassId;
    }

    if (bGamble)
    {
        ITEMS_SetItemLevelInl(pItem, 1);
        ITEMS_SetItemQualityInl(pItem, ITEMQUAL_INFERIOR);
        return 1;
    }

    const int nSocketedItems = BITMANIP_ReadInl(pBuffer, 3);
    if (pSocketedItems)
    {
        *pSocketedItems = nSocketedItems;
    }

    if (bCheckForHeader)
    {
        pItem->dwInitSeed = BITMANIP_ReadInl(pBuffer, 32);
        SEED_InitLowSeed(&pItem->pSeed, pItem->dwInitSeed);
    }

    int nItemLevel = BITMANIP_ReadInl(pBuffer, 7);
    if (nItemLevel < 0)
    {
        nItemLevel = 1;
    }
    ITEMS_SetItemLevelInl(pItem, nItemLevel);

    ITEMS_SetItemQualityInl(pItem, BITMANIP_ReadInl(pBuffer, 4));

    if (BITMANIP_ReadInl(pBuffer, 1))
    {
        ITEMS_SetInvGfxIndexInl(pItem, BITMANIP_ReadInl(pBuffer, 3));
    }

    D2MagicAffixDataTbl* pMagicAffixDataTbl = DATATBLS_GetMagicAffixDataTables();
    int nMagicPrefixOffset = pMagicAffixDataTbl->pMagicPrefix - pMagicAffixDataTbl->pMagicAffixTxt;
    int nAutoMagicOffset = pMagicAffixDataTbl->pAutoMagic - pMagicAffixDataTbl->pMagicAffixTxt;

    switch (dwVersion)
    {
    case 72:
    case 73:
    case 80:
    case 81:
    case 82:
        nMagicPrefixOffset -= 661;
        nAutoMagicOffset -= 1262;
        break;
    case 83:
    case 84:
        nMagicPrefixOffset -= 674;
        nAutoMagicOffset -= 1265;
        break;
    case 85:
    case 86:
    case 87:
        nMagicPrefixOffset -= 675;
        nAutoMagicOffset -= 1266;
        break;
    case 88:
        nMagicPrefixOffset -= 729;
        nAutoMagicOffset -= 1440;
        break;
    default:
        break;
    }

    if (BITMANIP_ReadInl(pBuffer, 1))
    {
        unsigned short nAutoAffix = BITMANIP_ReadInl(pBuffer, 11);
        if (dwVersion <= 88)
        {
            nAutoAffix = 0;
        }
        else
        {
            if (dwVersion <= 89)
            {
                ++nAutoAffix;
            }

            if (nAutoAffix > 0)
            {
                nAutoAffix += nAutoMagicOffset;
            }
        }
        ITEMS_SetAutoAffixInl(pItem, nAutoAffix);
    }
    else
    {
        ITEMS_SetAutoAffixInl(pItem, 0);
    }

    switch (ITEMS_GetItemQualityInl(pItem))
    {
    case 1:
    case 3:
        ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 3));
        break;

    case 2:
        if (ITEMS_CheckItemTypeId(pItem, 13))
        {
            if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
            {
                if (BITMANIP_ReadInl(pBuffer, 1))
                {
                    unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
                    if (nPrefix > 0)
                    {
                        nPrefix += nMagicPrefixOffset;
                    }
                    sub_00627EF0(pItem, nPrefix, 0);
                }
                else
                {
                    sub_00627FB0(pItem, BITMANIP_ReadInl(pBuffer, 11), 0);
                }
            }
        }

        if (ITEMS_CheckItemTypeId(pItem, 40) && !ITEMS_CheckItemTypeId(pItem, 7))
        {
            ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 10));
        }

        if (ITEMS_CheckItemTypeId(pItem, 22) || ITEMS_CheckItemTypeId(pItem, 18))
        {
            sub_00627FB0(pItem, BITMANIP_ReadInl(pBuffer, 5), 0);
        }
        break;

    case 6:
    case 8:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_AssignRarePrefix(pItem, BITMANIP_ReadInl(pBuffer, 8));
            sub_00628070(pItem, BITMANIP_ReadInl(pBuffer, 8));
        }

        for (int i = 0; i < 3; ++i)
        {
            if (BITMANIP_ReadInl(pBuffer, 1))
            {
                unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
                if (dwVersion <= 89)
                {
                    ++nPrefix;
                }

                if (nPrefix > 0)
                {
                    nPrefix += nMagicPrefixOffset;
                }
                ITEMS_SetMagicPrefixInl(pItem, i, nPrefix);
            }
            else
            {
                ITEMS_SetMagicPrefixInl(pItem, i, 0);
            }

            if (BITMANIP_ReadInl(pBuffer, 1))
            {
                unsigned short nSuffix = BITMANIP_ReadInl(pBuffer, 11);
                if (dwVersion <= 89)
                {
                    ++nSuffix;
                }
                ITEMS_SetMagicSuffixInl(pItem, i, nSuffix);
            }
            else
            {
                ITEMS_SetMagicSuffixInl(pItem, i, 0);
            }
        }
        break;

    case 9:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_AssignRarePrefix(pItem, BITMANIP_ReadInl(pBuffer, 8));
            sub_00628070(pItem, BITMANIP_ReadInl(pBuffer, 8));
        }
        break;

    case 4:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
            if (nPrefix > 0)
            {
                nPrefix += nMagicPrefixOffset;
            }
            sub_00627EF0(pItem, nPrefix, 0);

            unsigned short nSuffix = BITMANIP_ReadInl(pBuffer, 11);
            sub_00627FB0(pItem, nSuffix, 0);
        }
        break;

    case 7:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            int nFileIndex = BITMANIP_ReadInl(pBuffer, 12);
            if (nFileIndex < 0)
            {
                nFileIndex = -1;
            }
            if (nFileIndex >= sgptDataTables->nUniqueItemsTxtRecordCount)
            {
                nFileIndex = -1;
            }
            ITEMS_SetFileIndex(pItem, nFileIndex);
        }
        break;

    case 5:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            const int nSetRecordId = BITMANIP_ReadInl(pBuffer, 12);
            if (dwVersion <= 92)
            {
                D2SetsTxt* pSetsTxtRecord = sub_00483410_GetSetsTxtRecord(nSetRecordId);
                if (pSetsTxtRecord)
                {
                    int nIndex = -1;
                    for (int i = 0; i < pSetsTxtRecord->nSetItems; ++i)
                    {
                        if (pSetsTxtRecord->pSetItem[i]->dwItemCode == dwCode)
                        {
                            nIndex = i;
                            break;
                        }
                    }

                    if (nIndex < 0)
                    {
                        bError = 1;
                    }
                    else
                    {
                        ITEMS_SetFileIndex(pItem, pSetsTxtRecord->pSetItem[nIndex]->wSetItemId);
                    }
                }
                else
                {
                    bError = 1;
                }
            }
            else
            {
                D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(nSetRecordId);
                if (pSetItemsTxtRecord)
                {
                    ITEMS_SetFileIndex(pItem, pSetItemsTxtRecord->wSetItemId);
                }
                else
                {
                    bError = 1;
                }
            }
        }
        break;

    default:
        bError = 1;
        break;
    }

    int bRuneword = 0;
    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_RUNEWORD)
    {
        bRuneword = 1;
        ITEMS_SetMagicPrefixInl(pItem, 0, BITMANIP_ReadInl(pBuffer, 16));
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_ISEAR)
    {
        szName = ITEMS_GetEarNameInl(pItem);
        ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 3));
        ITEMS_SetEarLevelInl(pItem, BITMANIP_ReadInl(pBuffer, 7));
        do
        {
            szChar = (char)BITMANIP_ReadInl(pBuffer, 7);
            *szName++ = szChar;
        }
        while (szChar);
    }
    else if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_PERSONALIZED)
    {
        szName = ITEMS_GetEarNameInl(pItem);
        do
        {
            szChar = (char)BITMANIP_ReadInl(pBuffer, 7);
            *szName++ = szChar;
        }
        while (szChar);
    }

    if (bCheckForHeader && dwVersion > 86 && BITMANIP_ReadInl(pBuffer, 1))
    {
        const int nRealmData0 = BITMANIP_ReadInl(pBuffer, 32);
        const int nRealmData1 = BITMANIP_ReadInl(pBuffer, 32);
        if (dwVersion > 93)
        {
            BITMANIP_ReadInl(pBuffer, 32);
        }
        sub_00629EA0(pItem, nRealmData0, nRealmData1);
    }

    int b109 = 0;
    if (dwVersion < 93)
    {
        b109 = 1;
    }

    if (ITEMS_CheckItemTypeId(pItem, 50))
    {
        pItemStatCostTxtRecord = ITEMS_GetRecF3(31);
        nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
        STATLIST_SetUnitStat(pItem, 31, nValue, 0);

        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pItem));
        D2_ASSERT(pItemsTxtRecord, 6326);

        STATLIST_SetUnitStat(pItem, 20, pItemsTxtRecord->nBlock, 0);
        STATLIST_SetUnitStat(pItem, 67, -pItemsTxtRecord->dwSpeed, 0);

        pItemStatCostTxtRecord = ITEMS_GetRecF3(73);
        nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
        STATLIST_SetUnitStat(pItem, 73, nValue, 0);

        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetRecF3(72);
            nBits = pItemStatCostTxtRecord->nSaveBits[b109];
            if (dwVersion <= 95)
            {
                nBits = 8;
            }

            nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
            STATLIST_SetUnitStat(pItem, 72, nValue, 0);
        }
    }
    else if (ITEMS_CheckItemTypeId(pItem, 45))
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pItem));
        D2_ASSERT(pItemsTxtRecord, 6349);

        STATLIST_SetUnitStat(pItem, 68, -pItemsTxtRecord->dwSpeed, 0);

        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_INFERIOR)
        {
            if (pItemsTxtRecord->nMaxDam)
            {
                nValue = 3 * pItemsTxtRecord->nMaxDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 22, nValue, 0);
            }

            if (pItemsTxtRecord->nMinDam)
            {
                nValue = 3 * pItemsTxtRecord->nMinDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 21, nValue, 0);
            }

            if (pItemsTxtRecord->n2HandMaxDam)
            {
                nValue = 3 * pItemsTxtRecord->n2HandMaxDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 24, nValue, 0);
            }

            if (pItemsTxtRecord->n2HandMinDam)
            {
                nValue = 3 * pItemsTxtRecord->n2HandMinDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 23, nValue, 0);
            }

            if (pItemsTxtRecord->nMaxMisDam)
            {
                nValue = 3 * pItemsTxtRecord->nMinMisDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 159, nValue, 0);

                nValue = 3 * pItemsTxtRecord->nMaxMisDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 160, nValue, 0);
            }
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
            STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
            STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
            STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);

            if (pItemsTxtRecord->nMaxMisDam)
            {
                STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
                STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
            }
        }

        if (ITEMS_IsEthereal(pItem))
        {
            STATLIST_SetUnitStat(pItem, 21, 3 * STATLIST_GetUnitBaseStat(pItem, 21, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 22, 3 * STATLIST_GetUnitBaseStat(pItem, 22, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 23, 3 * STATLIST_GetUnitBaseStat(pItem, 23, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 24, 3 * STATLIST_GetUnitBaseStat(pItem, 24, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 159, 3 * STATLIST_GetUnitBaseStat(pItem, 159, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 160, 3 * STATLIST_GetUnitBaseStat(pItem, 160, 0) / 2, 0);
        }

        pItemStatCostTxtRecord = ITEMS_GetRecF3(73);
        nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
        STATLIST_SetUnitStat(pItem, 73, nValue, 0);

        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetRecF3(72);
            nBits = pItemStatCostTxtRecord->nSaveBits[b109];
            if (dwVersion <= 95)
            {
                nBits = 8;
            }

            nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
            STATLIST_SetUnitStat(pItem, 72, nValue, 0);
        }
    }
    else if (ITEMS_CheckItemTypeId(pItem, 4))
    {
        if (BITMANIP_ReadInl(pBuffer, 1))
        {
            STATLIST_SetUnitStat(pItem, 14, BITMANIP_ReadInl(pBuffer, 32), 0);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 14, BITMANIP_ReadInl(pBuffer, 12), 0);
        }
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (dwVersion <= 80)
        {
            STATLIST_SetUnitStat(pItem, 70, BITMANIP_ReadInl(pBuffer, 8), 0);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 70, BITMANIP_ReadInl(pBuffer, 9), 0);
        }
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_SOCKETED)
    {
        pItemStatCostTxtRecord = ITEMS_GetRecF3(194);
        sub_0062BE00_SetSockets(pItem, BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]));
    }

    if (bCheckForHeader || ITEMS_GetItemFlagsInl(pItem) & IFLAG_IDENTIFIED)
    {

    nStatLists = 0;
    nSetItemMask = 0;
    if (dwVersion > 84 && ITEMS_GetItemQualityInl(pItem) == ITEMQUAL_SET)
    {
        nStatLists = 5;
        nSetItemMask = BITMANIP_ReadInl(pBuffer, 5);
    }

    if (bRuneword)
    {
        ++nStatLists;
    }

    for (int nCounter = -1; nCounter < nStatLists; ++nCounter)
    {
        int nState;
        int nFlag;
        if (nCounter < 0)
        {
            nState = 0;
            nFlag = 0x40;
        }
        else if (bRuneword && nCounter == nStatLists - 1)
        {
            nState = 171;
            nFlag = 0x40;
        }
        else if (nSetItemMask & (1 << nCounter))
        {
            nState = gnItemSetStates_006E90B8[nCounter];
            nFlag = 0x2040;
        }
        else
        {
            continue;
        }

        pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, nState, nFlag);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetNextRosterInfo(pItem), nFlag, 0, UNIT_ITEM, sub_00451F50_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            sub_006252D0(pStatList, nState);
        }

        nLastStatId = -1;
        nStatId = BITMANIP_ReadInl(pBuffer, 9);
        if (nStatId != 511)
        {
        do
        {
            if (!nStatId && !nLastStatId)
            {
                bError = 1;
                break;
            }

            nLastStatId = nStatId;

            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(nStatId);
            if (!pItemStatCostTxtRecord)
            {
                break;
            }

            switch (nStatId)
            {
            case 0:
            case 2:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, nStatId, nValue, 0);
                break;

            case 3:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 3, nValue, 0);

                if (dwVersion <= 85)
                {
                    pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(7);
                    nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                    STATLIST_SetStatIfListIsValid(pStatList, 7, nValue << 8, 0);
                }
                break;

            case 1:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 1, nValue, 0);

                if (dwVersion <= 85)
                {
                    pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(9);
                    nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                    STATLIST_SetStatIfListIsValid(pStatList, 9, nValue, 0);
                }
                break;

            case 17:
                ITEMS_SetDefenseOrDamage(pItem, 17);

                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 17, nValue, 0);

                ITEMS_SetDefenseOrDamage(pItem, 18);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(18);
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 18, nValue, 0);
                break;

            case 48:
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 6;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 48, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(49);
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 49, nValue, 0);
                break;

            case 50:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 50, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(51);
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 51, nValue, 0);
                break;

            case 52:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 52, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(53);
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 53, nValue, 0);
                break;

            case 54:
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 54, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(55);
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 55, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(56);
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 56, nValue, 0);
                break;

            case 57:
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 57, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(58);
                nBits = pItemStatCostTxtRecord->nSaveBits[b109];
                if (dwVersion <= 81)
                {
                    nBits = 8;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 58, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(59);
                nValue = BITMANIP_ReadInl(pBuffer, pItemStatCostTxtRecord->nSaveBits[b109]) - pItemStatCostTxtRecord->dwSaveAdd[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 59, nValue, 0);
                STATLIST_SetStatIfListIsValid(pStatList, 326, 1, 0);
                break;

            case 134:
                if (dwVersion <= 89)
                {
                    BITMANIP_ReadInl(pBuffer, 16);
                    STATLIST_SetStatIfListIsValid(pStatList, 134, 1, 0);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 134, dwVersion, b109);
                }
                break;

            case 83:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 0);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 83, dwVersion, b109);
                }
                break;

            case 84:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 3);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 84, dwVersion, b109);
                }
                break;

            case 85:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 2);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 85, dwVersion, b109);
                }
                break;

            case 86:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 1);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 86, dwVersion, b109);
                }
                break;

            case 87:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 4);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 87, dwVersion, b109);
                }
                break;

            case 179:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 5);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 179, dwVersion, b109);
                }
                break;

            case 180:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    sub_006270B0(pStatList, 83, nValue, 6);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 180, dwVersion, b109);
                }
                break;

            case 188:
            case 189:
            case 190:
            case 191:
            case 192:
            case 193:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 10);
                    sub_0065CB60_DecodeAddSkillTab(nValue, &v238, &v237, &nTabLevel);
                    if (nTabLevel > 7)
                    {
                        nTabLevel = 7;
                    }
                    sub_006270B0(pStatList, 188, nTabLevel, v237 + 8 * v238);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 126:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 4);
                    sub_006270B0(pStatList, 126, nValue, 1);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 126, dwVersion, b109);
                }
                break;

            case 107:
            case 108:
            case 109:
            case 181:
            case 182:
            case 183:
            case 184:
            case 185:
            case 186:
            case 187:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 14);
                    D2Common_10844_ITEMMODS_First(nValue, &nSkillId, &nSkillValue);

                    int nMax = 7;
                    D2ItemStatCostTxt* pSingleSkillTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(107);
                    if (pSingleSkillTxtRecord)
                    {
                        nMax = (1 << pSingleSkillTxtRecord->nSaveBits[0]) - 1;
                    }

                    if (nSkillValue > 0 && nSkillValue <= nMax)
                    {
                        if (sub_00627AF0_HasSkillDesc(nSkillId))
                        {
                            sub_006270B0(pStatList, 107, nSkillValue, nSkillId);
                        }
                    }
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 195:
            case 196:
            case 197:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v241, &v240, &v242);
                    sub_006270B0(pStatList, 195, v242, (v240 & 0x3F) + ((unsigned short)v241 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 198:
            case 199:
            case 200:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v244, &v243, &v245);
                    sub_006270B0(pStatList, 198, v245, (v243 & 0x3F) + ((unsigned short)v244 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 201:
            case 202:
            case 203:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v247, &v246, &v248);
                    sub_006270B0(pStatList, 201, v248, (v246 & 0x3F) + ((unsigned short)v247 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 204:
            case 205:
            case 206:
            case 207:
            case 208:
            case 209:
            case 210:
            case 211:
            case 212:
            case 213:
                if (dwVersion <= 92)
                {
                    if (dwVersion <= 73)
                    {
                        nValue = BITMANIP_ReadInl(pBuffer, 29);
                    }
                    else
                    {
                        nValue = BITMANIP_ReadInl(pBuffer, 30);
                    }
                    D2Common_10846(nValue, &v249, &v250, &v251, &v252);
                    sub_006270B0(pStatList, 204, (v251 & 0xFF) + (v252 << 8), (v250 & (unsigned short)sgptDataTables->nShiftedStuff) + ((unsigned short)v249 << sgptDataTables->nStuff));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            default:
                ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                break;
            }
        }
        while ((nStatId = BITMANIP_ReadInl(pBuffer, 9)) != 511);
        }

        if (dwVersion <= 92)
        {
            const int nValue = STATLIST_GetStatValue(pStatList, 83, 0);
            if (nValue > 0)
            {
                if (nValue == STATLIST_GetStatValue(pStatList, 83, 1) && nValue == STATLIST_GetStatValue(pStatList, 83, 2)
                    && nValue == STATLIST_GetStatValue(pStatList, 83, 3) && nValue == STATLIST_GetStatValue(pStatList, 83, 4))
                {
                    for (int i = 0; i < 7; ++i)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, 83, 0, i);
                    }

                    STATLIST_SetStatIfListIsValid(pStatList, 127, nValue, 0);
                }
            }
        }
    }

    }

    return 2 * (bError == 0) - 1;
}

// calling-convention shim (not game code)
int __stdcall ITEMS_DecodeItemBitstreamCompleteCaller(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion)
{
    return ITEMS_DecodeItemBitstreamComplete(pItem, pBuffer, bCheckForHeader, bGamble, pSocketedItems, dwVersion) > 0;
}
