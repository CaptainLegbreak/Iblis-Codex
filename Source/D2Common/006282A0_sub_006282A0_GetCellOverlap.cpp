#ifdef MOVED_TEST
#define ITEM_GAP 20
#else
#define ITEM_GAP 16
#endif
#define UNIT_ITEM 4
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
    char unk0x1C[ITEM_GAP];
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
inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

// 0x006282A0
unsigned char __stdcall sub_006282A0_GetCellOverlap(D2UnitStrc* pItem) {
 if(D2ItemDataStrc* pItemData=ITEMS_GetItemData(pItem)) return pItemData->nCellOverlap;
 return 0xFF;
}
