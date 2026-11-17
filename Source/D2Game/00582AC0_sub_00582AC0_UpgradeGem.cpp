extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x78];
    unsigned short wItemFormat;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2InventoryStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x38];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

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
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};
struct D2ItemsTxt
{
    char unk0x000[0xBC];
    unsigned int dwUpgradeCode;
};
struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pLastItem); // 0x0063CD80
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevel);                                 // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nCell);                                   // 0x00628320
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

__declspec(noinline) static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer);

// 0x00582AC0
static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int bResult = 0;
    D2CoordStrc tCoords;
    UNITS_GetCoords(pPlayer, &tCoords);

    D2CoordStrc tFreeCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pPlayer), &tCoords, &tFreeCoords, 1, 1);
    if (pRoom)
    {
        D2ItemDropStrc tItemDrop;
        memset(&tItemDrop, 0, sizeof(tItemDrop));
        tItemDrop.pUnit = 0;
        tItemDrop.pSeed = 0;
        tItemDrop.wItemFormat = pGame->wItemFormat;
        tItemDrop.nId = nItemId;
        tItemDrop.nX = tFreeCoords.nX;
        tItemDrop.pGame = pGame;
        tItemDrop.nSpawnType = 3;
        tItemDrop.nY = tFreeCoords.nY;
        tItemDrop.pRoom = pRoom;
        tItemDrop.wUnitInitFlags = 1;
        tItemDrop.nQuality = 2;
        tItemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
        D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &tItemDrop, 0);
        STATLIST_SetUnitStat(pNewItem, 0x46, 1, 0);
        UNITROOM_RefreshUnit(pNewItem);
        if (pNewItem)
        {
            pNewItem->dwFlags |= 1;
        }

        bResult = 1;
        if (pItem)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
            ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
            D2GAME_UpdateClientItem_6FC3E9D0(SUNIT_GetClientFromPlayer(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x80F), pPlayer, pItem, (unsigned int)nFlags);
            D2GAME_RemoveItem_6FC471F0(pGame, pPlayer, pItem, 0);
        }

    }

    return bResult;
}

// 0x00582C40
void __fastcall sub_00582C40_OperateGemShrine(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2InventoryStrc* pInventory = pOp->pPlayer->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, 0);
    int bUpgraded = 0;
    while (pItem)
    {
        if (bUpgraded)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord->dwUpgradeCode != ' non')
        {
            const int nItemId = DATATBLS_GetItemIdFromItemCode(pItemsTxtRecord->dwUpgradeCode);
            D2_ASSERT(nItemId != -1, 0x823);
            if (sub_00582AC0_UpgradeGem(pItem, nItemId, pOp->pGame, pOp->pPlayer))
            {
                bUpgraded = 1;
                pItem = 0;
            }
        }

        pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, pItem);
    }

    if (bUpgraded)
    {
        return;
    }

    D2SeedStrc* pSeed = &pOp->pPlayer->pSeed;
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;

    unsigned int dwCode;
    switch ((unsigned int)lSeed % 6)
    {
    case 0: dwCode = ' wcg'; break;
    case 1: dwCode = ' rcg'; break;
    case 2: dwCode = ' gcg'; break;
    case 3: dwCode = ' bcg'; break;
    case 4: dwCode = ' ycg'; break;
    default: dwCode = ' vcg'; break;
    }

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    D2_ASSERT(nItemId != -1, 0x84C);
    sub_00582AC0_UpgradeGem(0, nItemId, pOp->pGame, pOp->pPlayer);
}
