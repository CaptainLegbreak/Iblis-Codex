struct D2ActiveRoomStrc;
struct D2ClientStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2ItemsTxt
{
    char unk0x000[0xF6];
    unsigned short wVersion;
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
};

struct D2PlayerDataStrc
{
    char szName[16];
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

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned short wUnitInitFlags, int nMode, unsigned int a9); // 0x00555230
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit);                // 0x00558530
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit);                  // 0x00558580
void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue);               // 0x00530EA0
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag);                                         // 0x00538670
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem);                                           // 0x00627DF0
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed);                                        // 0x00627E20
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel);                                       // 0x00628220
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName);                                           // 0x00628370
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, int nLevel);                                            // 0x006283D0
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat);                          // 0x0062A6C0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets);                                           // 0x0062BCB0

// 0x00558D90
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed)
{
    if (!pGame->bExpansion)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItemDrop->nId);
        if (!pItemsTxtRecord)
        {
            return 0;
        }

        if (pItemsTxtRecord->wVersion >= 100)
        {
            return 0;
        }
    }

    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2_ASSERT(pItemDataTbl, 0x7F0);

    const int nItemId = pItemDrop->nId;
    if (nItemId < 0 || nItemId >= pItemDataTbl->nItemsTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_AllocUnitData(4, nItemId, pItemDrop->nX, pItemDrop->nY, pItemDrop->pGame, pItemDrop->pRoom, pItemDrop->wUnitInitFlags, pItemDrop->nSpawnType, 0);
    D2UnitStrc* pInitItem = pItem;
    D2_ASSERT(pItem, 0x809);

    ITEMS_SetItemFlag(pItem, 0x80000, 1);
    ITEMS_SetItemFormat(pItem, pItemDrop->wItemFormat);

    if (bUseSeed || pItemDrop->bForce)
    {
        pItem->dwInitSeed = pItemDrop->dwSeed;
        SEED_InitLowSeed(&pItem->pSeed, pItemDrop->dwSeed);
        ITEMS_SetItemStartSeed(pItem, pItemDrop->dwItemSeed);
        SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), pItemDrop->dwItemSeed);
    }

    if (pItemDrop->nItemLvl <= 0)
    {
        pItemDrop->nItemLvl = 1;
    }
    ITEMS_SetItemLevel(pItem, pItemDrop->nItemLvl);

    if (!pItemDrop->bForce)
    {
        ITEMS_SetItemFlag(pItem, 0x2000, 1);
    }

    ITEMS_SetInvPage(pItem, 0xFF);

    if (!D2GAME_InitItemStats_6FC4E520(pGame, &pInitItem, pItemDrop, 1))
    {
        SUNIT_RemoveUnit(pGame, pItem);
        return 0;
    }

    if (pItemDrop->bForce)
    {
        ITEMS_SetItemFlag(pItem, 0x10, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x10));
        ITEMS_SetItemFlag(pItem, 0x1000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x1000));

        if (!ITEMS_GetItemFormat(pItem) && !ITEMS_CheckItemTypeId(pItem, 3) && sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x800) && !sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 0x800))
        {
            if (ITEMS_GetMaxSockets(pItem))
            {
                ITEMS_AddSockets(pItem, ITEMS_GetItemStartSeed(pItem) % ITEMS_GetMaxSockets(pItem) + 1);
            }
            else
            {
                ITEMS_SetItemFlag(pItem, 0x800, 0);
            }
        }

        ITEMS_SetItemFlag(pItem, 0x800, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x800));
        ITEMS_SetItemFlag(pItem, 0x100, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x100));
        ITEMS_SetItemFlag(pItem, 0x20000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x20000));

        if (ITEMS_GetItemType(pItem) == 4)
        {
            D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 14, pItemDrop->nQuantity);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 0x46, pItemDrop->nQuantity, 0);
        }

        pItemDrop->nMaxDur = D2_MIN(pItemDrop->nMaxDur, 0xFF);
        pItemDrop->nMinDur = D2_MIN(pItemDrop->nMinDur, pItemDrop->nMaxDur);
        STATLIST_SetUnitStat(pItem, 0x48, pItemDrop->nMinDur, 0);
        STATLIST_SetUnitStat(pItem, 0x49, pItemDrop->nMaxDur, 0);
    }

    if (ITEMS_GetItemType(pItem) == 7)
    {
        if (pItemDrop->bForce)
        {
            ITEMS_SetEarName(pItem, pItemDrop->szName);
            ITEMS_SetEarLevel(pItem, pItemDrop->nEarLvl);
            ITEMS_SetItemFlag(pItem, 0x8000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x8000));
        }
        else
        {
            if (!pItemDrop->pUnit || pItemDrop->pUnit->dwUnitType != 0)
            {
                SUNIT_RemoveUnit(pGame, pItem);
                return 0;
            }

            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pItemDrop->pUnit);
            if (!pPlayerData)
            {
                SUNIT_RemoveUnit(pGame, pItem);
                return 0;
            }

            ITEMS_SetEarName(pItem, pPlayerData->szName);
            ITEMS_SetEarLevel(pItem, STATLIST_UnitGetStatValue(pItemDrop->pUnit, 12, 0));

            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pItemDrop->pUnit, ".\\ITEMS\\Items.cpp", 0x880);
            if (pClient)
            {
                ITEMS_SetItemFlag(pItem, 0x8000, CLIENTS_CheckFlag(pClient, 4));
            }
        }
    }

    if (sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 0x1000000))
    {
        if (pItemDrop->bForce)
        {
            ITEMS_SetEarName(pItem, pItemDrop->szName);
        }
        else
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pItemDrop->pUnit);
            D2_ASSERT(pPlayerData, 0x892);
            ITEMS_SetEarName(pItem, pPlayerData->szName);
        }
    }

    ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
    ITEMS_ScheduleQuantityReplenishment(pGame, pItem);

    return pItem;
}
