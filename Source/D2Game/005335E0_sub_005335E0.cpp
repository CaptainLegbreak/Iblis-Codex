struct D2GameStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc
{
    char unk00[12];
    int nX;
    int nY;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk08;
    int dwUnitId;
    int dwAnimMode;
    char unk14[24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk30[48];
    D2InventoryStrc* pInventory;
    char unk64[96];
    unsigned int dwFlags;
};

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __stdcall sub_00628170_SetItemCommandFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent); // 0x00531520
__declspec(noinline)

static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    switch (!pItem ? 0 : pItem->dwAnimMode)
    {
    case 6:
        if (pParent)
        {
            UNITS_ChangeAnimMode(pItem, 4);
            const int nParentGUID = pParent->dwUnitId;
            const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
            int bPlaced;
            if (D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, nItemGUID, nParentGUID, &bPlaced, 0, 1, 0, 0))
                break;
        }
    default:
        return 13;
    case 1:
        {
            D2InventoryStrc* pInventory = pPlayer->pInventory;
            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
                return 13;
            int nPage = 3;
            if (nBodyLoc == 11 || nBodyLoc == 12)
                nPage = 4;
            if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
                return 13;
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            if (pItem)
                pItem->dwFlags &= ~2u;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            sub_00628170_SetItemCommandFlag(pItem, 8, 1);
            if (pItem)
                pItem->dwFlags &= ~0x02000000u;
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pPlayer, 1);
            QUESTS_ItemPickedUp(pGame, pPlayer, pItem);
            return 0;
        }
    case 0:
        {
            UNITS_ChangeAnimMode(pItem, 4);
            int nY;
            switch (pItem->dwUnitType)
            {
            case 2:
            case 4:
            case 5:
                nY = pItem->pStaticPath->nY;
                break;
            default:
                nY = pItem->pDynamicPath ? PATH_GetYPosition(pItem->pDynamicPath) : 0;
                break;
            }
            int nX;
            switch (pItem->dwUnitType)
            {
            case 2:
            case 4:
            case 5:
                nX = pItem->pStaticPath->nX;
                break;
            default:
                nX = pItem->pDynamicPath ? PATH_GetXPosition(pItem->pDynamicPath) : 0;
                break;
            }
            const int nItemGUID = pItem->dwUnitId;
            if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 536, pGame, pPlayer, nItemGUID, nX, nY, 0, 0, 0))
                return 13;
            break;
        }
    }
    return 0;
}

struct D2ActiveRoomStrc;

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};

int __fastcall sub_00531210_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent); // 0x00531210
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int* pSize, unsigned int dwVersion); // 0x00558CB0
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00563470
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit); // 0x00564CB0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int dwVersion); // 0x0062AE20
const void* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0

// 0x005335E0
int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    unsigned char* pBegin = pSection;
    if (*(unsigned short*)pSection != 0x4D4A)
    {
        return 14;
    }

    pSection += 2;
    const int nItems = *(unsigned short*)pSection;
    pSection += 2;
    for (int i = 0; i < nItems; ++i)
    {
        D2ItemSaveStrc tItemSave;
        int nItemSize;
        int nResult = 0;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
        if (tItemSave.nClassId == -1)
        {
            return 14;
        }

        D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
        if (!pItem && nItemSize <= 0)
        {
            return 14;
        }

        pSection += nItemSize;
        if (pItem)
        {
            sub_00564CB0_Nop(pItem);
            if (bCorpseItems)
            {
                nResult = sub_00531520_PlaceSavedItem(pGame, pPlayer, pItem, 0);
            }
            else
            {
                nResult = sub_00531210_PlaceSavedItem(pGame, pPlayer, pItem, 0);
            }
        }

        const int nSockets = tItemSave.nItemFileIndex;
        D2UnitStrc* pParent = pItem;
        if (nResult)
        {
            if (pItem)
            {
                SUNIT_RemoveUnit(pGame, pItem);
            }
            pParent = 0;
        }

        for (int j = 0; j < nSockets; ++j)
        {
            ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
            D2UnitStrc* pSocketed = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
            if (!pSocketed && nItemSize <= 0)
            {
                return 14;
            }

            pSection += nItemSize;
            if (!pParent)
            {
                if (pSocketed)
                {
                    SUNIT_RemoveUnit(pGame, pSocketed);
                }
            }
            else if (pSocketed)
            {
                sub_00564CB0_Nop(pSocketed);
                if (bCorpseItems)
                {
                    sub_00531520_PlaceSavedItem(pGame, pPlayer, pSocketed, pParent);
                }
                else
                {
                    sub_00531210_PlaceSavedItem(pGame, pPlayer, pSocketed, pParent);
                }
            }
        }

        if (pParent && (ITEMS_GetItemFlags(pParent) & 0x4000000) && !ITEMS_GetRunesTxtRecordFromItem(pParent))
        {
            ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParent);
        }
    }

    if (pSize)
    {
        *pSize = pSection - pBegin;
    }

    return 0;
}
