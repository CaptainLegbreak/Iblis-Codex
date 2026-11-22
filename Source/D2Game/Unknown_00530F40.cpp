#include "D2Structs.h"
#include "D2ItemModes.h"
#pragma function(memset)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

struct D2GameStrc;
struct D2InventoryStrc;
union D2SeedStrc;
struct D2ActiveRoomStrc;

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

// build: symbol _gszPlrSaveSourceFile 0x006E09AC
extern "C" const char gszPlrSaveSourceFile[];
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory);
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9);
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData);
int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount);

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00530F40
static D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem)
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

static int __stdcall PLRSAVE_CreateAndPlaceLegacyCorpseItem(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount, D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
        return 13;

    switch (pItem->dwAnimMode)
    {
    case IMODE_STORED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(gszPlrSaveSourceFile, 0x1C2, pGame, pUnit, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 0, 0))
            return 13;
        break;
    }
    case IMODE_EQUIP:
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
    case IMODE_SOCKETED:
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

int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    D2ItemKeyStrc keys[0x400];

    if (*(unsigned short*)pSection != 0x4D4A)
        return 14;

    unsigned char* pData = pSection + 2;
    const unsigned short nTotal = *(unsigned short*)pData;
    pData += 2;
    int nTotalSize = 4;
    nSize -= 4;
    int nKeys = 0;
    for (unsigned int j = 0; j < nTotal; ++j)
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

                int nUnused;
                int nResult;
                if (bCorpseItems)
                    nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &nUnused, pPlayer);
                else
                    nResult = PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &nUnused);

                if (nResult)
                    return nResult;
            }
        }
next_item:
        ;
    }

    *pSize = nTotalSize;
    return 0;
}
