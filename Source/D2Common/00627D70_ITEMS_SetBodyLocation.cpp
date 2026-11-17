struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ItemDataStrc
{
    unsigned int dwQualityNo;
    D2SeedStrc pSeed;
    int dwOwnerGUID;
    unsigned int dwInitSeed;
    unsigned int dwCommandFlags;
    unsigned int dwItemFlags;
    char unk0x1C[16];
    int dwItemLevel;
    char unk0x30[2];
    unsigned short wRarePrefix;
    unsigned short wRareSuffix;
    unsigned short wAutoAffix;
    unsigned short wMagicPrefix[3];
    unsigned short wMagicSuffix[3];
    unsigned char nBodyLoc;
    unsigned char nInvPage;
    unsigned char nCellOverlap;
    unsigned char nItemCell;
    unsigned char nEarLvl;
    unsigned char nInvGfxIdx;
    char szPlayerName[16];
    char unk0x5A[26];
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[16];
    D2ItemDataStrc* pItemData;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define UNIT_ITEM 4
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

// 0x00627D70
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nBodyLoc = nBodyLoc;
    }
}

// 0x00627D90
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pSeed;
    }

    return 0;
}

// 0x00627E20
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed)
{
    D2_ASSERT(pItem, 391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 392);
    D2_ASSERT(pItem->pItemData, 395);
    pItem->pItemData->dwInitSeed = nSeed;
}

// 0x00628280
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvPage = nPage;
    }
}

// 0x006282D0
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, int nCellOverlap)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nCellOverlap = nCellOverlap;
    }
}

// 0x006282F0
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nItemCell;
    }

    return 0xFF;
}

// 0x00628320
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, int nItemCell)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nItemCell = nItemCell;
    }
}

// 0x00628340
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->szPlayerName;
    }

    return 0;
}

// 0x006283A0
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nEarLvl;
    }

    return 1;
}

// 0x006283D0
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nEarLvl = nLevel;
    }
}

// 0x006283F0
unsigned char __stdcall ITEMS_GetVarGfxIndex(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nInvGfxIdx;
    }

    return 0;
}

// 0x00628420
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvGfxIdx = nIndex;
    }
}
