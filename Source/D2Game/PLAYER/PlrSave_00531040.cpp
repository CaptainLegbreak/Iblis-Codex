// build: base-profile

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
extern "C" void __cdecl _chkstk(); // 0x006831B0
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

struct D2GameStrc;
struct D2InventoryStrc;
struct D2SeedStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

#pragma pack(push, 1)
struct D2SavedItemStrc
{
    unsigned char nBodyLoc;
    unsigned char nSocketedItems;
    int nItemLevel;
    int nItemId;
    unsigned char nSpawnType;
    unsigned char nItemQuality;
    int nQuantity;
    int nMinDurability;
    int nMaxDurability;
    int nX;
    int nY;
    int nItemIndex;
    unsigned int nItemFlags;
    unsigned int nSeed;
    unsigned int nItemSeed;
    unsigned char nInvPage;
    unsigned char nEarLevel;
    char szName[16];
    unsigned short nItemFormat;
    unsigned int nItemCode;
};
#pragma pack(pop)

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    unsigned int nMinDur;
    unsigned int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    unsigned char nEarLvl;
    char unk0x51[3];
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

struct D2ItemKeyStrc
{
    unsigned int nCode;
    int nIndex;
    int nLevel;
    unsigned int nSeed;
    unsigned int nItemSeed;
};

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);             // 0x00543D80
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);   // 0x0063BDB0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData);               // 0x00532F30
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, int nBodyLoc, int bSkipRequirementCheck, int* pResult); // 0x005606B0
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, int nX, int a5, int* pResult); // 0x0055E9B0
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);                    // 0x0055FB10
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00530F40
static __declspec(noinline) D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem)
{
    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));

    itemDrop.wItemFormat = pSavedItem->nItemFormat;
    itemDrop.nItemLvl = pSavedItem->nItemLevel;
    itemDrop.nId = pSavedItem->nItemId;
    itemDrop.nSpawnType = pSavedItem->nSpawnType;
    itemDrop.nX = pSavedItem->nX;
    itemDrop.nY = pSavedItem->nY;
    itemDrop.nQuality = pSavedItem->nItemQuality;
    itemDrop.nQuantity = pSavedItem->nQuantity;
    itemDrop.nMinDur = pSavedItem->nMinDurability;
    itemDrop.nMaxDur = pSavedItem->nMaxDurability;
    itemDrop.dwSeed = pSavedItem->nSeed;
    itemDrop.pGame = pGame;
    itemDrop.pRoom = 0;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.dwItemSeed = pSavedItem->nItemSeed;
    itemDrop.dwFlags1 = pSavedItem->nItemFlags;
    itemDrop.bForce = 1;
    itemDrop.nItemIndex = pSavedItem->nItemIndex;

    strcpy(itemDrop.szName, pSavedItem->szName);

    itemDrop.nEarLvl = pSavedItem->nEarLevel;

    D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    if (!pItem)
        return 0;

    ITEMS_SetFileIndex(pItem, pSavedItem->nItemIndex);
    ITEMS_SetInvPage(pItem, pSavedItem->nInvPage);
    return pItem;
}

// 0x00531040
int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount)
{
    if (pSocketedItemCount)
    {
        *pSocketedItemCount = 0;
    }

    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
    {
        return 12;
    }

    switch (pItem->dwAnimMode)
    {
    case 0:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\PLAYER\\PlrSave.cpp", 0xE1);
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 0xEA, pGame, pPlayer, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 1, 0))
        {
            return 12;
        }

        break;
    }
    case 1:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!ITEMMODE_EquipCursorItem(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nBodyLoc, 1, &nUnused))
        {
            return 12;
        }

        break;
    }
    case 2:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        UNITS_SetXForStaticUnit(pItem, pSavedItem->nX);
        UNITS_SetYForStaticUnit(pItem, pSavedItem->nY);
        int nUnused;
        if (!sub_6FC48940(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nX, 0, &nUnused))
        {
            return 12;
        }

        break;
    }
    case 4:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        INVENTORY_SetCursorItem(pPlayer->pInventory, pItem);
        if (!sub_6FC4B9D0(pGame, pPlayer, pItem))
        {
            return 12;
        }

        break;
    }
    case 6:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!*ppItem || !D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
        {
            return 12;
        }

        break;
    }
    default:
        return 12;
    }

    if (pSavedItem->nSocketedItems > 0)
    {
        *ppItem = pItem;
    }

    if (pSocketedItemCount)
    {
        *pSocketedItemCount = pSavedItem->nSocketedItems;
    }

    return 0;
}

// 0x00531390
static __declspec(noinline) int __stdcall PLRSAVE_CreateAndPlaceLegacyCorpseItem(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount, D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
        return 13;

    switch (pItem->dwAnimMode)
    {
    case 0:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 0x1C2, pGame, pUnit, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 0, 0))
            return 13;
        break;
    }
    case 1:
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
        if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
            return 13;

        int nPage = 3;
        if (nBodyLoc == 11 || nBodyLoc == 12)
            nPage = 4;

        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
            return 13;

        ITEMS_SetBodyLocation(pItem, nBodyLoc);
        pItem->dwFlags &= 0xFFFFFFFDu;
        UNITS_ChangeAnimMode(pItem, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        ITEMS_SetItemCMDFlag(pItem, 8, 1);
        pItem->dwFlags &= 0xFDFFFFFFu;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
        break;
    }
    case 6:
    {
        if (!*ppItem)
            return 13;

        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
            return 13;
        break;
    }
    default:
        return 13;
    }

    if (pSavedItem->nSocketedItems > 0)
        *ppItem = pItem;

    *pSocketedItemCount = pSavedItem->nSocketedItems;
    return 0;
}

// 0x00533350
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    D2ItemKeyStrc keys[0x400];
    struct D2ReadStateStrc { int* pSize; int nUnused; } state;
    D2ReadStateStrc* pState = &state;
    unsigned short nTotal16;
    pState->pSize = pSize;

    if (*(unsigned short*)pSection != 0x4D4A)
        return 14;

    unsigned char* pData = pSection + 2;
    nTotal16 = *(unsigned short*)pData;
    pData += 2;
    int nTotalSize = 4;
    nSize -= 4;
    int nKeys = 0;
    for (unsigned int j = 0; j < nTotal16; ++j)
    {
        D2SavedItemStrc savedItem;
        memset(&savedItem, 0, sizeof(savedItem));
        if (*(unsigned short*)pData != 0x4D4A)
            return 14;

        pData += 2;
        int nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
        nSize -= nDataSize + 2;
        pData += nDataSize;
        nTotalSize += nDataSize + 2;

        for (int k = 0; k < nKeys; ++k)
        {
            if (savedItem.nItemCode == keys[k].nCode && savedItem.nItemIndex == keys[k].nIndex && savedItem.nItemLevel == keys[k].nLevel
                && savedItem.nSeed == keys[k].nSeed && savedItem.nItemSeed == keys[k].nItemSeed)
            {
                for (int s = 0; s < savedItem.nSocketedItems; ++s)
                {
                    memset(&savedItem, 0, sizeof(savedItem));
                    if (*(unsigned short*)pData != 0x4D4A)
                        return 14;

                    pData += 2;
                    nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                    nSize -= nDataSize + 2;
                    pData += nDataSize;
                    nTotalSize += nDataSize + 2;
                }
                goto next_item;
            }

            keys[nKeys].nCode = savedItem.nItemCode;
            keys[nKeys].nIndex = savedItem.nItemIndex;
            keys[nKeys].nLevel = savedItem.nItemLevel;
            keys[nKeys].nSeed = savedItem.nSeed;
            keys[nKeys].nItemSeed = savedItem.nItemSeed;
            ++nKeys;
        }

        {
            int nCount = 0;
            D2UnitStrc* pItem = 0;
            if (bCorpseItems)
            {
                const int nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &nCount, pPlayer);
                if (nResult)
                    return nResult;
            }
            else
            {
                if (PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &nCount))
                    continue;
            }

            for (int i = 0; i < nCount; ++i)
            {
                memset(&savedItem, 0, sizeof(savedItem));
                if (*(unsigned short*)pData != 0x4D4A)
                    return 14;

                pData += 2;
                nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                nSize -= nDataSize + 2;
                pData += nDataSize;
                nTotalSize += nDataSize + 2;

                int nResult;
                if (bCorpseItems)
                    nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &pState->nUnused, pPlayer);
                else
                    nResult = PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &pState->nUnused);

                if (nResult)
                    return nResult;
            }
        }
next_item:
        ;
    }

    *pState->pSize = nTotalSize;
    return 0;
}
