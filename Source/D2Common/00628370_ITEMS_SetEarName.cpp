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
    char unk0x084[0x9A];
    short wType[2];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBFC];
    int nItemTypesTxtRecordCount;
    int nItemTypesIndex;
    unsigned int* pItemTypesEquivalenceLUTs;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                  // 0x00628700

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

#include "gen/data/Source/D2Common/00628370_ITEMS_SetEarName.inc"
