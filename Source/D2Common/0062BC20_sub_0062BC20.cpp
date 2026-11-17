#ifdef MOVED_TEST
#define UNIT_ITEM 6
#define LEVEL_LOW 27
#define LEVEL_HIGH 42
#else
#define UNIT_ITEM 4
#define LEVEL_LOW 25
#define LEVEL_HIGH 40
#endif
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ItemDataStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    int dwQualityNo;
    D2SeedStrc pSeed;
    int dwOwnerGUID;
    unsigned int dwInitSeed;
    unsigned int dwCommandFlags;
    unsigned int dwItemFlags;
    char unk0x1C[0x0C];
    int dwFileIndex;
    int dwItemLevel;
    unsigned short wItemFormat;
    unsigned short wRarePrefix;
    unsigned short wRareSuffix;
    unsigned short wAutoAffix;
    unsigned short wMagicPrefix[3];
    unsigned short wMagicSuffix[3];
    unsigned char nBodyLoc;
    unsigned char nInvPage;
};

struct D2UnitStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2ItemDataStrc* pItemData;
    char unk0x18[0xB0];
    unsigned int dwFlagEx;
};

struct D2ItemsTxt
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x00[128];
    unsigned int dwCode;
    unsigned int dwNormCode;
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    unsigned int dwAlternateGfx;
    char unk0x94[44];
    unsigned int dwWeapClass;
    unsigned int dwWeapClass2Hand;
    char unk0xC8[20];
    unsigned int dwBitField1;
    char unk0xE0[26];
    unsigned short wMissileType;
    char unk0xFC[1];
    unsigned char nLevel;
    char unk0xFE[6];
    unsigned char nRangeAdder;
    char unk0x105[1];
    short nStrBonus;
    short nDexBonus;
    char unk0x10A[5];
    unsigned char nInvWidth;
    unsigned char nInvHeight;
    char unk0x111[4];
    unsigned char nComponent;
    char unk0x116[6];
    unsigned char n2Handed;
    unsigned char nUseable;
    short wType[2];
    char unk0x122[7];
    unsigned char nUnique;
    unsigned char nQuest;
    char unk0x12B[7];
    unsigned char nStackable;
    char unk0x133[2];
    unsigned char nDurWarning;
    unsigned char nQuantityWarning;
    unsigned char nHasInv;
    unsigned char nGemSockets;
    char unk0x139[3];
    unsigned char nHitClass;
    char unk0x13D[107];
};

struct D2ItemTypesTxt
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    unsigned char nRepair;
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    short wShoots;
    short wQuiver;
    unsigned char nThrowable;
    unsigned char nReload;
    unsigned char nReEquip;
    unsigned char nAutoStack;
    char unk0x14[6];
    unsigned char nMaxSock1;
    unsigned char nMaxSock25;
    unsigned char nMaxSock40;
    char unk0x1D[0xC7];
};

struct D2DataTablesStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0x04];
    unsigned int* fStateMasks[40];
    char unk0x16C[0xA8C];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);  // 0x006335F0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);  // 0x0062B400
inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x006281E0
__declspec(noinline) int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }

    return 1;
}

inline unsigned char __stdcall ITEMS_GetAllowedGemSocketsFromItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nGemSockets;
}
// 0x0062BC20
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pType = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pType)
            return 0;
        int nSockets = ITEMS_GetAllowedGemSocketsFromItemId(pItem->dwClassId);
        int nLevel = ITEMS_GetItemLevel(pItem);
        int nTypeSockets;
        if (nLevel <= LEVEL_LOW)
            nTypeSockets = pType->nMaxSock1;
        else if (nLevel <= LEVEL_HIGH)
            nTypeSockets = pType->nMaxSock25;
        else
            nTypeSockets = pType->nMaxSock40;
        if (nSockets >= nTypeSockets)
            nSockets = nTypeSockets;
        return (unsigned char)nSockets;
    }
    return 0;
}
