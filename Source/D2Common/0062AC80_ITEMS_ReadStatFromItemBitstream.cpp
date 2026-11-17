struct D2BitBufferStrc;
struct D2StatListStrc;
struct D2UnitStrc;

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits[2];
    char pad0x1B[0x01];
    int dwSaveAdd[2];
    int dwSaveParamBits[2];
};

struct D2ItemsTxt
{
    char unk0x000[0xD0];
    int dwMaxAc;
    char unk0x0D4[0x2A];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
};

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80

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
