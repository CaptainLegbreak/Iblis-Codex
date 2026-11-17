struct D2BitBufferStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2ItemDataStrc
{
    char unk0x00[0x18];
    unsigned int dwItemFlags;
    char unk0x1C[0x44 - 0x1C];
    unsigned char nBodyLoc;
    char nInvPage;
    char unk0x46[2];
    unsigned char nEarLvl;
    char unk0x49;
    char szPlayerName[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x10 - 0x08];
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
    char unk0x18[0x2C - 0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x60 - 0x30];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x12A];
    unsigned char nQuest;
    unsigned char nQuestDiffCheck;
    char unk0x12C[0x143 - 0x12C];
    unsigned char nCompactSave;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits;
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
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
extern D2DataTablesStrc* sgptDataTables;                                                                         // 0x00744304
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                        // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                                  // 0x00410EB0
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer);                                                  // 0x00411070
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                              // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                              // 0x0045AE20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                  // 0x00625480
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                     // 0x00628590
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                           // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                             // 0x00629DA0
void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1);                        // 0x00629E40
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                                 // 0x0062A670
void __stdcall ITEMS_SerializeItemComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bGamble);    // 0x0062FFF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                               // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                            // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                                       // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                                        // 0x0063DFD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                       // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                       // 0x00648900

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define IMODE_ONGROUND 3
#define IMODE_DROPPING 5
#define ITEMTYPE_GOLD 4
#define STAT_GOLD 14
#define STAT_QUESTITEMDIFFICULTY 356
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_SOCKETED 0x800
#define IFLAG_ISEAR 0x10000
#define IFLAG_INIT 0x80000
#define IFLAG_COMPACTSAVE 0x200000
#define IFLAG_ETHEREAL 0x400000
#define IFLAG_JUSTSAVED 0x800000
#define IFLAG_LOWQUALITY 0x2000000

// 0x0062AF50
void __fastcall ITEMS_WriteBitsToBitstream(int nBits, unsigned int nData, D2BitBufferStrc* pBuffer)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

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

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

inline unsigned int ITEMS_GetItemFlagsInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->dwItemFlags : 0;
}

inline unsigned char ITEMS_GetBodyLocationInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nBodyLoc;
    }
    return 0;
}

inline char ITEMS_GetInvPageInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvPage;
    }
    return -1;
}

inline unsigned char ITEMS_GetEarLevelInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nEarLvl;
    }
    return 1;
}

inline char* ITEMS_GetEarNameInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->szPlayerName : 0;
}

inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordInl(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static __forceinline int ITEMS_IsOnGroundForceInl(D2UnitStrc* pItem)
{
    if (pItem && (pItem->dwAnimMode == IMODE_ONGROUND || pItem->dwAnimMode == IMODE_DROPPING))
    {
        return 1;
    }
    return 0;
}

static __forceinline int ITEMS_GetQuestItemDifficultyValueForceInl(D2UnitStrc* pItem, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    return (STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) >> pItemStatCostTxtRecord->nValShift) + pItemStatCostTxtRecord->dwSaveAdd;
}

// 0x0062AF80
static void __stdcall ITEMS_SerializeItemCompact(int bServer, D2UnitStrc* pItem, D2BitBufferStrc* pBuffer)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 7244);

    ITEMS_WriteBitsToBitstream(10, ITEMS_GetItemFormat(pItem), pBuffer);
    ITEMS_WriteBitsToBitstream(3, !pItem ? 0 : pItem->dwAnimMode, pBuffer);

    if (!ITEMS_IsOnGroundForceInl(pItem))
    {
        ITEMS_WriteBitsToBitstream(4, ITEMS_GetBodyLocationInl(pItem), pBuffer);
        ITEMS_WriteBitsToBitstream(4, D2_MIN(D2_MAX(CLIENTS_GetUnitX(pItem), 0u), 15u), pBuffer);
        ITEMS_WriteBitsToBitstream(4, D2_MIN(D2_MAX(CLIENTS_GetUnitY(pItem), 0u), 15u), pBuffer);
        ITEMS_WriteBitsToBitstream(3, (char)(ITEMS_GetInvPageInl(pItem) + 1), pBuffer);
    }
    else
    {
        ITEMS_WriteBitsToBitstream(16, UNITS_GetXPositionForceInl(pItem), pBuffer);
        ITEMS_WriteBitsToBitstream(16, UNITS_GetYPositionForceInl(pItem), pBuffer);
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarNameInl(pItem);
        ITEMS_WriteBitsToBitstream(3, ITEMS_GetFileIndex(pItem), pBuffer);
        ITEMS_WriteBitsToBitstream(7, ITEMS_GetEarLevelInl(pItem), pBuffer);
        do
        {
            ITEMS_WriteBitsToBitstream(7, *szName, pBuffer);
        }
        while (*szName++);
    }
    else
    {
        ITEMS_WriteBitsToBitstream(32, ITEMS_GetBaseCode(pItem), pBuffer);

        if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_GOLD))
        {
            const int nGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
            ITEMS_WriteBitsToBitstream(1, nGold >= 4096, pBuffer);
            ITEMS_WriteBitsToBitstream((((nGold < 4096) - 1) & 20) + 12, nGold, pBuffer);
        }
    }

    if (pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(STAT_QUESTITEMDIFFICULTY);
        D2_ASSERT(pItemStatCostTxtRecord, 7290);

        const int nValue = ITEMS_GetQuestItemDifficultyValueForceInl(pItem, pItemStatCostTxtRecord);
        ITEMS_WriteBitsToBitstream(pItemStatCostTxtRecord->nSaveBits, nValue, pBuffer);
    }

    if (bServer)
    {
        int nRealmData0 = 0;
        int nRealmData1 = 0;
        ITEMS_GetRealmData(pItem, &nRealmData0, &nRealmData1);
        const int nRealm1 = nRealmData1;
        if (nRealm1)
        {
            ITEMS_WriteBitsToBitstream(1, 1, pBuffer);
            ITEMS_WriteBitsToBitstream(32, nRealmData0, pBuffer);
            ITEMS_WriteBitsToBitstream(32, nRealm1, pBuffer);
            ITEMS_WriteBitsToBitstream(32, 0, pBuffer);
        }
        else
        {
            ITEMS_WriteBitsToBitstream(1, 0, pBuffer);
        }
    }
}

int __fastcall ITEMS_SerializeItem(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bSaveItemInv, int bGamble)
{
    unsigned int nItemFlags = ITEMS_GetItemFlagsInl(pItem);
    nItemFlags = nItemFlags & ~IFLAG_INIT | IFLAG_JUSTSAVED;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 4832);

    if (pItemsTxtRecord->nCompactSave)
    {
        nItemFlags |= IFLAG_COMPACTSAVE;
    }

    if (bGamble)
    {
        nItemFlags = nItemFlags & ~IFLAG_ETHEREAL | IFLAG_LOWQUALITY;
    }

    if (bServer)
    {
        BITMANIP_Write(pBuffer, 'MJ', 16);
    }
    else if (!(nItemFlags & IFLAG_IDENTIFIED))
    {
        nItemFlags &= ~IFLAG_SOCKETED;
    }
    BITMANIP_Write(pBuffer, nItemFlags, 32);

    if (nItemFlags & IFLAG_COMPACTSAVE)
    {
        ITEMS_SerializeItemCompact(bServer, pItem, pBuffer);
    }
    else
    {
        ITEMS_SerializeItemComplete(pItem, pBuffer, bServer, bGamble);
    }

    if (!bGamble && bSaveItemInv && pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pChild = INVENTORY_UnitIsItem(i);
            BITMANIP_GoToNextByte(pBuffer);
            ITEMS_SerializeItem(pChild, pBuffer, bServer, bSaveItemInv, 0);
        }
    }

    return BITMANIP_GetSize(pBuffer);
}
