struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2BitBufferStrc;

struct D2ItemsTxt
{
    char unk0x000[0x80];
    unsigned int dwCode;
    char unk0x084[0xA6];
    unsigned char nQuest;
};

struct D2UniqueItemsTxt
{
    short wId;
    char unk0x002[0x2A];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC24];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2QuestItemPairStrc
{
    int nQuestFlag;
    unsigned char nItemQuest;
    char unk0x05[3];
};

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define ITEMQUAL_UNIQUE 7
#define UNIQUEITEMSFLAGINDEX_CARRY1 2
#define QUESTSTATEFLAG_A1Q4 4
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q2 10
#define QUESTSTATEFLAG_A3Q3 19
#define QUESTSTATEFLAG_A3Q4 20
#define QUESTSTATEFLAG_A5Q3 37
#define QFLAG_REWARDGRANTED 0
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2QuestItemPairStrc gQuestItemPairs_00731FEC[4];                                                     // 0x00731FEC

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UniqueItemsTxt* __fastcall sub_00483470(int nUniqueItemId);                           // 0x00483470
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);   // 0x00543520
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                              // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse);                                     // 0x0063D610
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

int __fastcall sub_0055CA00_MatchFieldPair(D2ItemsTxt* pRecord1, D2ItemsTxt* pRecord2, int nValue1, int nValue2)
{
    if (pRecord1->dwCode == nValue1 && pRecord2->dwCode == nValue2)
    {
        return 1;
    }

    if (pRecord1->dwCode == nValue2 && pRecord2->dwCode == nValue1)
    {
        return 1;
    }

    return 0;
}

static __forceinline int ITEMS_IsItemInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_ITEM;
}

static __forceinline D2UniqueItemsTxt* DATATBLS_GetUniqueItemsTxtRecordInline(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }
    return 0;
}

static __declspec(noinline) int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem);

static __forceinline unsigned char GetQuestIndex(const D2ItemsTxt* pRecord)
{
    unsigned char nQuest = 0;
    if (pRecord)
    {
        nQuest = pRecord->nQuest;
    }
    return nQuest;
}

// 0x0055CA40
static int __stdcall sub_6FC428F0(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem)
{
    int nUniqueId = -1;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7])
        {
            nUniqueId = pUniqueItemsTxtRecord->wId;
        }
    }

    while (pPreviousItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pPreviousItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pPreviousItem);
        if (pCheckedItem == pItem)
        {
            break;
        }

        if (!ITEMS_IsItemInline(pCheckedItem))
        {
            pPreviousItem = pNext;
            continue;
        }

        if (nUniqueId >= 0 && ITEMS_GetInvPage(pCheckedItem) != 1 && ITEMS_GetItemQuality(pCheckedItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pCheckedItem) == nUniqueId)
        {
            return 1;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCheckedItem->dwClassId);
        if (pItemsTxtRecord->nQuest && ITEMS_GetInvPage(pCheckedItem) != 1 && GetQuestIndex(pItemsTxtRecord) == pItemsTxtRecordArg->nQuest)
        {
            if (pItemsTxtRecordArg->dwCode == pItemsTxtRecord->dwCode
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 43j', ' 43g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' skb', ' dkb')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 33d', ' 33g')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' fsm')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' piv')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' 1fq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rhq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' yeq')
                || sub_0055CA00_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rbq'))
            {
                return 1;
            }
        }

        pPreviousItem = pNext;
    }

    return 0;
}

int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pPreviousItem = INVENTORY_GetFirstItem(pInventory);
    if (!pInventory)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7] && sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
        {
            return 0;
        }
    }

    if (!pItemsTxtRecord->nQuest)
    {
        return 1;
    }

    const unsigned int nItemCode = pItemsTxtRecord->dwCode;
    if (nItemCode == ' ssa')
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 43j')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED))
        {
            return 0;
        }
    }
    else if (nItemCode == ' zyx')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 33g')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 2rt')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }
    }

    const int nQuest = pItemsTxtRecord->nQuest;
    if (nQuest - 1 == QUESTSTATEFLAG_A2Q1)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' xob')
        {
            return 0;
        }
    }
    else if (nQuest - 1 == QUESTSTATEFLAG_A1Q4)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' gel')
        {
            return 0;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            if (pItemsTxtRecord->nQuest == gQuestItemPairs_00731FEC[i].nItemQuest)
            {
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
                if (QUESTRECORD_GetQuestState(pQuestFlags, gQuestItemPairs_00731FEC[i].nQuestFlag, QFLAG_REWARDGRANTED))
                {
                    return 0;
                }
            }
        }
    }

    if (sub_6FC428F0(pItem, pItemsTxtRecord, pPreviousItem))
    {
        return 0;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pUnit->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pPlayer && pPlayer->pInventory)
        {
            D2UnitStrc* pFirstItem = INVENTORY_GetFirstItem(pPlayer->pInventory);
            if (pFirstItem && sub_6FC428F0(pItem, pItemsTxtRecord, pFirstItem))
            {
                return 0;
            }
        }
    }

    return 1;
}
