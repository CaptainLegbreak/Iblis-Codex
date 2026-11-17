struct D2InventoryStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    char pad00[0x60];
    D2InventoryStrc* pInventory;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x00625480
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo);                                // 0x00627EC0
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem);                                              // 0x00627F20
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0

static int __stdcall sub_0055F5D0_HasSameAffixes(D2UnitStrc* pBook, D2UnitStrc* pItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        if (ITEMS_GetPrefixId(pBook, i) != ITEMS_GetPrefixId(pItem, i))
        {
            return 0;
        }

        if (ITEMS_GetSuffixId(pBook, i) != ITEMS_GetSuffixId(pItem, i))
        {
            return 0;
        }
    }

    return ITEMS_GetAutoAffix(pBook) == ITEMS_GetAutoAffix(pItem);
}

// 0x0055F640
D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity)
{
    if (!ITEMS_CheckItemTypeId(pItem, 0x16))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        pCurrent = INVENTORY_GetNextItem(pCurrent);
        if (!pBook)
        {
            continue;
        }

        if (ITEMS_GetItemType(pBook) != 0x12)
        {
            continue;
        }

        if (ITEMS_GetInvPage(pBook))
        {
            continue;
        }

        if (!sub_0055F5D0_HasSameAffixes(pBook, pItem))
        {
            continue;
        }

        int nQuantity = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
        if (nQuantity < 0)
        {
            nQuantity = 0;
        }

        const int nMaxStack = ITEMS_GetTotalMaxStack(pBook);
        if (nQuantity >= nMaxStack)
        {
            continue;
        }

        *pFreeQuantity = nMaxStack - nQuantity;
        return pBook;
    }

    return 0;
}
