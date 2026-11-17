struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2CubeInputItem
{
    unsigned short wInputFlags;
    unsigned short wItem;
    unsigned short wItemID;
    unsigned char nQuality;
    unsigned char nQuantity;
};

struct D2CubeMainTxt
{
    unsigned char nEnabled;
    unsigned char nLadder;
    unsigned char nMinDiff;
    unsigned char nClass;
    unsigned char nOp;
    char unk0x05[0x03];
    int nParam;
    int nValue;
    unsigned char nNumInputs;
    char unk0x11;
    unsigned short wVersion;
    D2CubeInputItem pInputItem[7];
    unsigned short wOutItemFlags;
    char unk0x4E[0x06];
    unsigned char nOutType;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    unsigned int dwNormCode;
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    char unk0x90[0x66];
    unsigned short wVersion;
    char unk0xF8[0x32];
    unsigned char nQuest;
    unsigned char nQuestDiffCheck;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
};

struct D2DataTablesStrc
{
    char unk0x00[0x94];
    void* pItemsLinker;
    char unk0x98[0xB3C];
    int nItemStatCostTxtRecordCount;
};

struct D2CubeItemStrc
{
    D2UnitStrc* pItem;
    int nClassId;
    int nItemLevel;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0
int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit);                                        // 0x00625290
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625560
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem);                                                        // 0x006281E0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                // 0x00628590
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                // 0x006299B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem);                                                          // 0x0062A8D0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall FOG_GetLinkIndex(void* pLink, unsigned int dwCode, int bLogError);                            // 0x006BD130

// 0x00565010
int __fastcall PLRTRADE_CheckCubeInput(D2GameStrc* pGame, D2InventoryStrc* pInventory, D2CubeMainTxt* pCubeMainTxt, int nInputIndex, D2CubeItemStrc* pCubeItem, int* pUsedItems)
{
    if (!pInventory)
    {
        return 0;
    }

    if (!(pCubeMainTxt->pInputItem[nInputIndex].wInputFlags & 3))
    {
        return 1;
    }

    int bNoStack = 1;
    int nItemCountWithStacks = 0;
    int nQuantity = pCubeMainTxt->pInputItem[nInputIndex].nQuantity;
    if (nQuantity <= 0)
    {
        nQuantity = 1;
    }

    D2ItemsTxt* pInputItemTxtRecord = 0;
    if ((pCubeMainTxt->pInputItem[nInputIndex].wInputFlags & 1) && pCubeMainTxt->pInputItem[nInputIndex].wItem != 0xFFFF)
    {
        pInputItemTxtRecord = DATATBLS_GetItemsTxtRecord(pCubeMainTxt->pInputItem[nInputIndex].wItem);
    }

    D2UnitStrc* pItem;
    D2ItemsTxt* pItemsTxtRecord;
    D2ItemStatCostTxt* pItemStatCostTxtRecord;
    int nStatId;
    int nValue;
    unsigned int dwItemCode;
    int nItemsInCube = 0;
    D2UnitStrc* pNext = INVENTORY_GetFirstItem(pInventory);
    while (pNext)
    {
        D2CubeMainTxt* pRecord = pCubeMainTxt;
        pItem = INVENTORY_UnitIsItem(pNext);
        pNext = INVENTORY_GetNextItem(pNext);
        if (!pItem || ITEMS_GetInvPage(pItem) != 3)
        {
            continue;
        }

        ++nItemsInCube;

        const int nItemClassId = pItem->dwClassId;
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemClassId);
        if (!pItemsTxtRecord)
        {
            continue;
        }

        dwItemCode = ITEMS_GetBaseCode(pItem);

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 1)
        {
            if (pRecord->pInputItem[nInputIndex].wItem != 0xFFFF)
            {
                if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x80)
                {
                    if (dwItemCode == pItemsTxtRecord->dwNormCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode)
                        {
                            continue;
                        }
                    }
                    else if (dwItemCode == pItemsTxtRecord->dwUberCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUberCode)
                        {
                            continue;
                        }
                    }
                    else if (dwItemCode == pItemsTxtRecord->dwUltraCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUberCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUltraCode)
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (pRecord->pInputItem[nInputIndex].wItem != (!pItem ? -1 : pItem->dwClassId))
                {
                    continue;
                }
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 2)
        {
            if (!ITEMS_CheckItemTypeId(pItem, pRecord->pInputItem[nInputIndex].wItem))
            {
                continue;
            }
        }

        if (pCubeMainTxt->pInputItem[nInputIndex].nQuality && ITEMS_GetItemQuality(pItem) != pCubeMainTxt->pInputItem[nInputIndex].nQuality)
        {
            if (pCubeMainTxt->pInputItem[nInputIndex].nQuality == 9)
            {
                STATLIST_GetFullStatsCountFromUnit(pItem);
            }
            continue;
        }

        if ((pRecord->pInputItem[nInputIndex].wInputFlags & 0x40) && ITEMS_GetFileIndex(pItem) != pRecord->pInputItem[nInputIndex].wItemID - 1)
        {
            continue;
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 4)
        {
            if (ITEMS_GetSockets(pItem) > 0)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 8)
        {
            if (ITEMS_GetSockets(pItem) <= 0)
            {
                continue;
            }
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x20)
        {
            if (ITEMS_IsEthereal(pItem))
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x10)
        {
            if (!ITEMS_IsEthereal(pItem))
            {
                continue;
            }
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x100)
        {
            if (dwItemCode != pItemsTxtRecord->dwNormCode)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x200)
        {
            if (dwItemCode != pItemsTxtRecord->dwUberCode)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x400)
        {
            if (dwItemCode != pItemsTxtRecord->dwUltraCode)
            {
                continue;
            }
        }

        if ((pRecord->pInputItem[nInputIndex].wInputFlags & 0x800) && (ITEMS_GetItemFlags(pItem) & 0x4000000))
        {
            continue;
        }

        if (pRecord->nOp == 28 && pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, 356, 0) < pGame->nDifficulty)
        {
            continue;
        }

        if (!nInputIndex && (pRecord->nOutType == 255 || pRecord->nOutType == 254) && (pRecord->wOutItemFlags & 2) && !ITEMS_GetMaxSockets(pItem))
        {
            continue;
        }

        if (nItemsInCube < 48 && pUsedItems[nItemsInCube - 1])
        {
            continue;
        }

        if (!nInputIndex)
        {
            if (pRecord->nOp)
            {
                switch (pRecord->nOp)
                {
                case 15:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 16:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 17:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 18:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 19:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 20:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 21:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 22:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 23:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 24:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 25:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 26:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 27:
                {
                    if (ITEMS_GetFileIndex(pItem) == pRecord->nValue)
                    {
                        continue;
                    }
                    break;
                }
                default:
                    break;
                }
            }

            for (int i = 0; i < 3; ++i)
            {
                pCubeItem[i].nItemLevel = ITEMS_GetItemLevel(pItem);

                if (pRecord->wOutItemFlags & 1)
                {
                    pCubeItem[i].pItem = pItem;
                }

                if (pRecord->nOutType == 255)
                {
                    pCubeItem[i].pItem = pItem;
                    pCubeItem[i].nClassId = sub_00451F60_UnitClassId(pItem);

                    if (pRecord->wOutItemFlags & 0x80)
                    {
                        if (pItemsTxtRecord->dwUberCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUberCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                    else if (pRecord->wOutItemFlags & 0x100)
                    {
                        if (pItemsTxtRecord->dwUltraCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUltraCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                }
                else if (pRecord->nOutType == 254)
                {
                    pCubeItem[i].pItem = pItem;
                    pCubeItem[i].nClassId = -1;

                    if (pRecord->wOutItemFlags & 0x80)
                    {
                        if (pItemsTxtRecord->dwUberCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUberCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                    else if (pRecord->wOutItemFlags & 0x100)
                    {
                        if (pItemsTxtRecord->dwUltraCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUltraCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (nItemsInCube < 48)
        {
            pUsedItems[nItemsInCube - 1] = 1;
        }

        ++nItemCountWithStacks;
        if (ITEMS_CheckIfStackable(pItem))
        {
            bNoStack = 0;
        }
    }

    if (!bNoStack)
    {
        return nItemCountWithStacks >= nQuantity;
    }

    return nItemCountWithStacks == nQuantity;
}
