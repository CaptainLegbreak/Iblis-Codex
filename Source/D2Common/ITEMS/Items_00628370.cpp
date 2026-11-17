#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_ITEM 4
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2ItemDataStrc;
struct D2ItemsTxt;
struct D2ItemStatCostTxt;

struct D2ItemDataStrc
{
    char unk0x00[0x4A];
    char szPlayerName[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[3];
    D2ItemDataStrc* pItemData;
};

struct D2ItemsTxt
{
    char unk0x000[0x80];
    int dwCode;
    unsigned int dwNormCode;
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    unsigned char unk_90[0x40];
    int dwMaxAc;
    unsigned int dwGambleCost;
    int dwSpeed;
    unsigned int dwBitField1;
    unsigned int dwCost;
    unsigned int dwMinStack;
    unsigned int dwMaxStack;
    char unk0xEC[0xFD - 0xEC];
    unsigned char nLevel;
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
    unsigned char unk_104[0x1A];
    short wType[2];
    unsigned char unk_122[0x2];
};

struct D2DataTablesStrc
{
    char unk0x00[3064];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
    int nItemTypesIndex;
    unsigned int* pItemTypesEquivalenceLUTs;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId); // 0x00628700
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem); // 0x006287D0
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits[2];
    char pad0x1B[0x01];
    int dwSaveAdd[2];
    int dwSaveParamBits[2];
};
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

struct D2ItemTypesTxt
{
    char unk0x00[10];
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    char unk0x0C[4];
    unsigned char nThrowable;
    char unk0x11[1];
    unsigned char nReEquip;
    char unk0x13[1];
    unsigned char nMagic;
    unsigned char nRare;
    unsigned char nNormal;
    char unk0x17[2];
    unsigned char nBeltable;
    char unk0x1A[5];
    unsigned char nStaffMods;
    char unk0x20[1];
    unsigned char nClass;
    unsigned char nStorePage;
    unsigned char nVarInvGfx;
    char szInvGfx[6][32];
};

extern char* gpszDefaultString; // 0x007446E4
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

// 0x00628370
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName)
{
    if (!pItem || pItem->dwUnitType != 4)
    {
        return;
    }

    D2ItemDataStrc* pItemData = pItem->pItemData;
    if (!pItemData)
    {
        return;
    }

    strcpy(pItemData->szPlayerName, szName);
}

// 0x00628A40
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    static int s_nHealthPotionCodes_00744684[] = { 0x20317068, 0x20327068, 0x20337068, 0x20347068, 0x20357068 };  // 0x00744684
    extern unsigned int s_nHealthPotionCodeCount_00744698; // 0x00744698
    static int s_nManaPotionCodes_0074466C[] = { 0x2031706D, 0x2032706D, 0x2033706D, 0x2034706D, 0x2035706D };    // 0x0074466C
    extern unsigned int s_nManaPotionCodeCount_00744680; // 0x00744680
    static int s_nRejuvPotionCodes_00744660[] = { 0x206C7672, 0x20737672 };                                       // 0x00744660
    extern unsigned int s_nRejuvPotionCodeCount_00744668; // 0x00744668

    if (pItem1 && pItem2)
    {
        const int nClassId1 = pItem1->dwClassId;
        const int nClassId2 = pItem2->dwClassId;
        if (nClassId1 == nClassId2)
        {
            return 1;
        }

        {
        D2ItemsTxt* pItemsTxtRecord1 = DATATBLS_GetItemsTxtRecord(nClassId1);
        D2ItemsTxt* pItemsTxtRecord2 = DATATBLS_GetItemsTxtRecord(nClassId2);
        int bPotion1;
        int bPotion2;

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nHealthPotionCodeCount_00744698; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nHealthPotionCodes_00744684[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nHealthPotionCodes_00744684[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nManaPotionCodeCount_00744680; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nManaPotionCodes_0074466C[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nManaPotionCodes_0074466C[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nRejuvPotionCodeCount_00744668; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nRejuvPotionCodes_00744660[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nRejuvPotionCodes_00744660[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }
        }
        return 0;
    }

    return 0;
}

// 0x00629BB0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType)
{
    if (!pItem)
    {
        return 0;
    }

    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    const int nClassId = pItem->dwClassId;
    const int nType = ITEMS_GetItemTypeFromItemId(nClassId);
    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nItemsTxtClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemsTxtClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[1] > 0 && pItemsTxtRecord->wType[1] < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[pItemsTxtRecord->wType[1] * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

#include "gen/data/Source/D2Common/ITEMS/Items_00628370.inc"

// 0x00629370
static __declspec(noinline) int __stdcall sub_00629370_GetGambleCost(int nLevel, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(ITEMS_GetNormalCode(pItem)));
    D2_ASSERT(pItemsTxtRecord, 2842);

    const unsigned int dwUberCode = pItemsTxtRecord->dwUberCode;
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUberItemId = 0;
    int nUltraItemId = 0;
    int nUberChance = 0;
    int nUltraChance = 0;
    int nUberCost = 0;
    int nUltraCost = 0;

    if (pItemsTxtRecord->dwCode == ' nir' || pItemsTxtRecord->dwCode == ' uma')
    {
        return pItemsTxtRecord->dwGambleCost;
    }

    const int nStack = pItemsTxtRecord->dwMaxStack + pItemsTxtRecord->dwMinStack;
    int nCount = nStack / 2;
    if (nCount < 1)
    {
        nCount = 1;
    }

    const int nBaseCost = nCount * pItemsTxtRecord->dwCost;
    const int nItemLevel = pItemsTxtRecord->nLevel;

    if (dwUberCode && pItemsTxtRecord->dwUberCode != '   0')
    {
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            nUberChance = 100 * (nLevel - pUberItemsTxtRecord->nLevel) / 2 + 1;
            if (nUberChance < 0)
            {
                nUberChance = 0;
            }
            nUberCost = pUberItemsTxtRecord->dwCost;
        }
    }

    if (dwUltraCode && pItemsTxtRecord->dwUltraCode != '   0')
    {
        D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
        if (pUltraItemsTxtRecord)
        {
            nUltraChance = 100 * (nLevel - pUltraItemsTxtRecord->nLevel) / 4 + 1;
            if (nUltraChance < 0)
            {
                nUltraChance = 0;
            }
            nUltraCost = pUltraItemsTxtRecord->dwCost;
        }
    }

    const int nBase = (nUberChance * nUberCost + nUltraChance * nUltraCost + nBaseCost * (10000 - nUltraChance - nUberChance)) / 10000;
    if (nLevel <= 5)
    {
        nLevel = 5;
    }

    return ((2 * nLevel + 1) / 3 + 20) * (nBase + (250 * (nLevel + ((nItemLevel - 45) < 0 ? 0 : (nItemLevel - 45)) - nItemLevel / 2)) / 3) / 15;
}

int __stdcall sub_M231_Emit_00629370(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    return sub_00629370_GetGambleCost(STATLIST_UnitGetStatValue(pPlayer, 12, 0), pItem);
}

// 0x0062AC80
static void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109)
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
    STATLIST_SetStat(pStatList, nStatId, (nValue - nSaveAdd) << pItemStatCostTxtRecord->nValShift, nParam);
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitReadStat(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, int nStatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, int n109, unsigned int dwVersion)
{
    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, n109);
}

// 0x0062C9F0
static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat)
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

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitSetDefenseOrDamage(D2UnitStrc* pItem, int nOther)
{
    ITEMS_SetDefenseOrDamage(pItem, 17);
    STATLIST_SetUnitStat(pItem, nOther, 0, 0);
    ITEMS_SetDefenseOrDamage(pItem, 18);
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x0062BA80
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nThrowable;
        }
    }

    return 0;
}

// 0x0062BAD0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nBeltable;
        }
    }

    return 0;
}

// 0x0062BBD0
int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nStaffMods;
        }
    }

    return 7;
}

// 0x0062C060
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nClass < 7;
        }
    }

    return 0;
}

// 0x0062C0B0
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nClass < 7)
        {
            return pItemTypesTxtRecord->nClass;
        }
    }

    return 7;
}

// 0x0062E830
unsigned int __stdcall ITEMS_GetReEquip(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nReEquip;
        }
    }

    return 0;
}

// 0x0062E880
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nStorePage != 0xFF)
        {
            return pItemTypesTxtRecord->nStorePage;
        }
    }

    return 0xFF;
}

// 0x0062E8D0
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nVarInvGfx;
        }
    }

    return 0;
}

// 0x0062E920
char* __stdcall ITEMS_GetVarInvGfxString(D2UnitStrc* pItem, int nId)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            nId = D2_MIN(D2_MAX(nId, 0), pItemTypesTxtRecord->nVarInvGfx - 1);

            return pItemTypesTxtRecord->szInvGfx[nId];
        }
    }

    return gpszDefaultString;
}

// 0x0062E990
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nRare;
        }
    }

    return 0;
}

// 0x0062E9E0
int __stdcall ITEMS_CanBeMagic(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nMagic;
        }
    }

    return 0;
}

// 0x0062EA30
int __stdcall ITEMS_CanBeNormal(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nNormal;
        }
    }

    return 1;
}

// 0x0062EA80
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pItemTypesTxtRecord)
        {
            *pBodyLoc1 = 0;
            *pBodyLoc2 = 0;
            return;
        }

        *pBodyLoc1 = pItemTypesTxtRecord->nBodyLoc1;
        *pBodyLoc2 = pItemTypesTxtRecord->nBodyLoc2;
        return;
    }

    *pBodyLoc1 = 0;
    *pBodyLoc2 = 0;
}
