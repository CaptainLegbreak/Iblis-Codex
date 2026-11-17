#define UNIT_ITEM 4
#define IFLAG_NEWITEM 0x00080000
#define IFLAG_ISEAR 0x00010000
#define IFLAG_COMPACTSAVE 0x00200000
#define IFLAG_UNK_GAMBLE 0x02000000

struct D2StatListStrc;

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
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
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x14 - 0x10];
    D2ItemDataStrc* pItemData;
    char unk0x18[0x20 - 0x18];
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
};

struct D2ItemsTxt
{
    char unk0x000[0x12A];
    unsigned char nQuantity;
    unsigned char nStackable;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nSaveBits;
    unsigned char nSaveBits2;
    char unk0x1A[2];
    int dwSaveAdd;
    char unk0x20[0x144 - 0x20];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[4];
    int nItemStatCostTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);                                     // 0x00411030
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);               // 0x00627FB0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerId);                                            // 0x00629EA0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat);                          // 0x0062A6C0
int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion); // 0x0062CBE0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

inline void ITEMS_ClearItemFlags(D2UnitStrc* pItem)
{
    const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemFlags = 0;
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

static __declspec(noinline) int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion); // 0x0062A970

// build: context ITEMS_DecodeItemBitstreamCompact
static __declspec(noinline) int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion)
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

        if (ITEMS_CheckItemTypeId(pItem, 4))
            STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, sub_00411020_ReadBits(pBuffer, 1) ? 32 : 12), 0);

        if (ITEMS_CheckItemTypeId(pItem, 22))
        {
            if (dwCode == ' cst')
                ITEMS_SetMagicSuffix(pItem, 0, 0);
            else if (dwCode == ' csi')
                ITEMS_AssignSuffix(pItem, 1, 0);
        }
    }

    if (dwVersion > 0x5C)
    {
        int nItemId = 0;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
        if (!pItemsTxtRecord)
            return -1;

        if (pItemsTxtRecord->nQuantity && pItemsTxtRecord->nStackable)
        {
            D2ItemStatCostTxt* pRecord = 0;
            if (sgptDataTables->nItemStatCostTxtRecordCount > 356)
                pRecord = &sgptDataTables->pItemStatCostTxt[356];
            if (!pRecord)
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1607);
                exit(-1);
            }
            const int nValue = (sub_00411020_ReadBits(pBuffer, pRecord->nSaveBits2) - pRecord->dwSaveAdd) << pRecord->nSaveBits;
            D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pItem ? pItem->pMemoryPool : 0, 0x40, 0, 4, pItem ? pItem->dwUnitId : -1);
                D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            }
            STATLIST_SetStat(pStatList, 356, nValue, 0);
        }
    }

    if (bCheckForHeader && dwVersion > 0x56 && sub_00411020_ReadBits(pBuffer, 1))
    {
        const int nOwner = sub_00411020_ReadBits(pBuffer, 32);
        ITEMS_SetOwnerId(pItem, nOwner);
        ITEMS_SetOwnerId(pItem, sub_00411020_ReadBits(pBuffer, 32));
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
