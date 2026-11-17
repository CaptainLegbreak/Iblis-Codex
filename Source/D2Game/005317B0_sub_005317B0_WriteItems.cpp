struct D2InventoryStrc;
struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; };

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory); // 0x00531750
static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    if (!pInventory)
        return 0;
    if (INVENTORY_GetCursorItem(pInventory))
        nCount = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pIsItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pIsItem)
            ++nCount;
    }
    return (unsigned short)nCount;
}

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0
#define WRITE_ITEM(pItem) { const int nSize = D2GAME_SAVE_SerializeItem_6FC89AD0(pGame, pUnit, pItem, pData, nBufferSize - (pData - pBuffer), a4, a5, a6); if (nSize < 0) return -1; pData += nSize; if (!nSize && nItems > 0) --nItems; }
#define PREPARE_ITEM(pItem) (ITEMS_SerializeItemToBitstream(pItem, tempBuffer, sizeof(tempBuffer), 1, 1, 0))
// 0x005317B0
int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int a4, int a5, int a6)
{
    unsigned char tempBuffer[8192];
    unsigned char* pBuffer = pData;
    if (nBufferSize < 2) return 0;
    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    unsigned short nItems = sub_00531750_CountInventoryItems(pInventory);
    if (nBufferSize < pData - pBuffer + 2) return pData - pBuffer;
    unsigned short* pItemCount = (unsigned short*)pData;
    *pItemCount = nItems;
    pData += 2;
    if (pInventory)
    {
        D2UnitStrc* pLeft = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        D2UnitStrc* pCursor = INVENTORY_GetCursorItem(pInventory);
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                if (PREPARE_ITEM(pRight) < 0) return -1;
                if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
            }
            else
            {
                if (PREPARE_ITEM(pOther) < 0) return -1;
                if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            }
        }
        else
        {
            if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
        }
        if (pCursor && pCursor->dwUnitType == 4 && PREPARE_ITEM(pCursor) < 0) return -1;
        D2UnitStrc* pListItem = INVENTORY_GetFirstItem(pInventory);
        while (pListItem)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pListItem);
            unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (INVENTORY_GetItemNodePage(pListItem) != 3 || (nBodyLoc != 4 && nBodyLoc != 5))
            {
                WRITE_ITEM(pItem);
            }
            pListItem = INVENTORY_GetNextItem(pListItem);
        }
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                WRITE_ITEM(pRight);
                if (pOther) { WRITE_ITEM(pOther); }
            }
            else
            {
                WRITE_ITEM(pOther);
                if (pRight) { WRITE_ITEM(pRight); }
            }
        }
        else
        {
            if (pRight) { WRITE_ITEM(pRight); }
            if (pOther) { WRITE_ITEM(pOther); }
        }
        if (pCursor && pCursor->dwUnitType == 4) { WRITE_ITEM(pCursor); }
        *pItemCount = nItems;
    }
    return pData - pBuffer;
}
