struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2TCExShortStrc;
struct D2BitBufferStrc;
struct D2SeedStrc;
struct D2TradeItemStrc;

struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};

struct D2PlayerTradeStrc
{
    int nSaveLength;
    unsigned char* pSaveData;
    D2TradeItemStrc* pItemTrade;
    int nGoldInTrade;
    int nGoldInTradeOtherPlayer;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    int dwTradeState;
    int unk0x54;
    int dwAcceptTradeTick;
    D2PlayerTradeStrc* pTrade;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2ItemDataStrc* pItemData;
        D2PlayerDataStrc* pPlayerData;
    };
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x2];
    int bExpansion;
    char f_74[0x34];
    unsigned int dwGameFrame;
    char unk0xAC[0x24];
    int pGameSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2MonStatsTxt
{
    char unk0x00[0xC];
    unsigned char nMonStatsFlags[4];
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2HirelingTxt
{
    char unk0x00[0x114];
    unsigned short wNameFirst;
};

struct D2SaveHeaderStrc
{
    unsigned char unk0x00[0xAF];
    unsigned char MercSaveData[4];
    unsigned char f_B3[4];
    unsigned char wMercName[2];
    unsigned char wMercHirelingId[2];
    unsigned char nMercExperience[4];
};

typedef int D2CorpseStrc;

#define MONSTATSFLAGINDEX_NORATIO 2
#define MONSTATSFLAGINDEX_BOSS 6

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                             // 0x00451F80
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit);                        // 0x005378E0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit);           // 0x0053D2E0
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);                                 // 0x0053FF00
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);              // 0x00543DB0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed);                                              // 0x00552DF0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);                     // 0x00553180
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin);                    // 0x00553380
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00558A10
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
void __fastcall D2GAME_DropTC_6FC51360(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, D2TCExShortStrc* pTCTxtRecord, int nQuality, int nLvl, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055A6D0
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);                            // 0x0055C270
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem);                          // 0x0055C6E0
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);   // 0x0055DBC0
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX);               // 0x0055EDC0
void __fastcall sub_6FC4B830(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FA40
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit);                                        // 0x00566BF0
void __fastcall sub_6FC90AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x005678F0
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID);               // 0x00574BD0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName);                                  // 0x006220F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                      // 0x00622E70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
int __stdcall sub_0062A360(D2UnitStrc* pUnit, D2UnitStrc* pItem);                                           // 0x0062A360
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem);                                            // 0x0062BAD0
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);         // 0x0063C110
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot);     // 0x0063C4F0
void __stdcall sub_0063C550_Return(D2InventoryStrc* pInventory, int nX);                                    // 0x0063C550
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory);                                        // 0x0063E0B0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromIdAndLevel(unsigned short wTCId, int nLvl); // 0x00654E00
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0
int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0

// 0x00555DA0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms)
{
    const int nX = pCoords->nX + 2;
    const int nY = pCoords->nY + 3;

    if (D2GAME_GetRoom_6FC52070(pRoom, nX, nY))
    {
        pReturnCoords->nX = nX;
        pReturnCoords->nY = nY;
    }
    else
    {
        pReturnCoords->nX = pCoords->nX;
        pReturnCoords->nY = pCoords->nY;
    }

    return COLLISION_GetFreeCoordinatesWithField(pRoom, pReturnCoords, pCoords, nUnitSize, 0x3E01, 0x801, bAllowNeighborRooms);
}

// 0x00558AA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (!pRoom)
    {
        return;
    }

    UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
    UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
    UNITROOM_AddUnitToRoom(pItem, pRoom);

    if (pItem)
    {
        pItem->dwFlags |= 0x1002;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    ITEMS_SetInvPage(pItem, 0xFF);

    if (pItem)
    {
        pItem->dwFlags |= 0x2000000;
    }

    pItem->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(pGame, pItem);

    if (pUnit)
    {
        QUESTS_ItemDropped(pGame, pUnit, pItem);
    }
}

// 0x0055AFA0
void __fastcall sub_6FC52110(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems)
{
    int nLevel = 0;
    if (pGame->bExpansion && pGame->nDifficulty > 0 && pMonster && pMonster->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
        if (pMonStatsTxtRecord && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7]) && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7]))
        {
            nLevel = STATLIST_UnitGetStatValue(pMonster, 0xC, 0);
        }
    }

    D2TCExShortStrc* pTCRecord = DATATBLS_GetTreasureClassExRecordFromIdAndLevel(nTCId, nLevel);
    if (pTCRecord)
    {
        D2GAME_DropTC_6FC51360(pGame, pMonster, pPlayer, pTCRecord, nQuality, nItemLevel, a7, ppItems, pnItemsDropped, nMaxItems);
    }
}

// 0x0055B030
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    D2UnitStrc* pGoldPiles[32];
    int nCount;
    sub_0055A090_DropGoldPiles(pGame, pUnit, nValue, pGoldPiles, &nCount, 32);
}

// 0x0055B060
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    const unsigned int nGoldLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const unsigned int nGold = STATLIST_UnitGetStatValue(pUnit, 14, 0);
    if (nGold == nGoldLimit)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nValue);
    }
    else if (nGold + nValue > nGoldLimit)
    {
        PLRTRADE_AddGold(pUnit, 14, nGoldLimit - nGold);
        ITEMS_DropGoldPile(pGame, pUnit, nValue + nGold - nGoldLimit);
    }
    else
    {
        PLRTRADE_AddGold(pUnit, 14, nValue);
    }
}

// 0x0055EB30
int __fastcall sub_6FC48D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5)
{
    D2_ASSERT(pGame, 0x128A);
    D2_ASSERT(pUnit, 0x128B);

    *a5 = 0;

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1290);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != 4 || pCursorItem->dwAnimMode != 4 || !ITEMS_CheckIfBeltable(pCursorItem))
    {
        return 0;
    }

    D2UnitStrc* pBeltItem = SUNIT_GetServerUnit(pGame, 4, nBeltItemGUID);
    if (!pBeltItem || pBeltItem->dwUnitType != 4)
    {
        return 0;
    }

    const int nBeltItemMode = pBeltItem ? pBeltItem->dwAnimMode : 0;
    if (nBeltItemMode != 2)
    {
        *a5 = 1;
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pBeltItem);
    D2_ASSERT(pRemove, 0x12B8);
    D2_ASSERT(pBeltItem == pRemove, 0x12B9);

    sub_0063C550_Return(pInventory, UNITS_GetXPosition(pBeltItem));
    INVENTORY_SetCursorItem(pInventory, pBeltItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pBeltItem);

    pBeltItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pBeltItem, pUnit, 0, 1);
    UNITS_ChangeAnimMode(pBeltItem, 4);
    ITEMS_SetItemCMDFlag(pBeltItem, 0x1000, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pBeltItem);
    if (INVENTORY_PlaceItemInBeltSlot(pInventory, pCursorItem, UNITS_GetXPosition(pBeltItem)))
    {
        UNITS_SetXForStaticUnit(pCursorItem, UNITS_GetXPosition(pBeltItem));
        UNITS_SetYForStaticUnit(pCursorItem, 0);
        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 2))
        {
            sub_0055C270_OnItemToBelt(pUnit, pCursorItem);

            pCursorItem->dwFlags &= ~2;

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 2);
            ITEMS_SetInvPage(pCursorItem, 0xFF);
            ITEMS_SetItemCMDFlag(pCursorItem, 0x1000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);
            sub_0055DBC0(pGame, pUnit, 0);
            return 1;
        }

        D2_ASSERT(0, 0x12D4);
    }

    D2_ASSERT(0, 0x12D8);
}

// 0x0055EEA0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pItem || INVENTORY_GetCursorItem(pInventory) != pItem)
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\ITEMS\\ItemMode.cpp", 0x139A);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    return 1;
}

// 0x0055F850
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    ITEMS_SetItemFlag(pItem, 0x100, 1);
    sub_0063D2B0_DetachItem(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == 1)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }

    sub_0055DBC0(pGame, pUnit, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    STATLIST_SetUnitStat(pItem, 0x48, 0, 0);

    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x191E), pItem, 1, 0x48, 0, 0);
    ITEMS_UpdateSets(pUnit, pItem, 1, 1);
    SUNIT_AttachSound(pUnit, 9, pUnit);
}

// 0x0055FB10
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x19A0);
    D2_ASSERT(pItem, 0x19A1);

    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x100000, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

// 0x0055FCC0
void __fastcall sub_6FC4BA50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory);
    while (pNode)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pNode);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        D2_ASSERT(pItem, 0x19FD);

        if (INVENTORY_GetItemNodePage(pNode) == 3 || INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit))
        {
            sub_0062A360(pUnit, pItem);
            sub_0063D2B0_DetachItem(pInventory, pItem);
            D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemove, 0x1A0F);
            D2_ASSERT(pItem == pRemove, 0x1A10);

            if (INVENTORY_GetItemNodePage(pNode) == 3)
            {
                sub_0063BE30(pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));
            }

            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
            sub_0055DBC0(pGame, pUnit, 0);
        }

        pNode = pNext;
    }

    INVENTORY_RemoveAllItems(pInventory);
}

// 0x0055FDE0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    sub_0055DBC0(pGame, pUnit, 0);
    if (a3)
    {
        UNITS_RefreshInventory(pUnit, 1);
    }
}

// 0x00562250
int __fastcall sub_6FC48B40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4)
{
    D2_ASSERT(pGame, 0x1249);
    D2_ASSERT(pUnit, 0x124A);

    *a4 = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x124F);

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *a4 = 1;
        return 0;
    }

    if (pItem->dwUnitType != 4)
    {
        return 0;
    }

    if (pItem->dwAnimMode != 2)
    {
        *a4 = 1;
        return 0;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x126D);

    const int nX = UNITS_GetXPosition(pItem);
    INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    sub_0063C550_Return(pInventory, nX);
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_0055C6E0_OnItemToCursor(pUnit, pItem);

    pItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x800, 1);
    UNITS_RefreshInventory(pUnit, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    sub_0055EDC0(pGame, pUnit, nX);
    return 1;
}

// 0x00566CC0
void __fastcall sub_6FC90C20(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x880);

    for (int i = 1; i < 13; ++i)
    {
        sub_0063BE30(pPlayer->pInventory, i);
    }

    D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
    D2_ASSERT(pTrade, 0x888);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 9, 0);

    int nUnused;
    sub_005337F0_ReadItems(pGame, pPlayer, pTrade->pSaveData, 0x60, 0x2000, 0, &nUnused);

    const int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    const int nMode = pPlayer->dwAnimMode;
    if (nGold > 0 && nMode != 0 && nMode != 17)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nGold);
        PLRTRADE_AddGold(pPlayer, 14, pTrade->nGoldInTradeOtherPlayer);
    }
}

// 0x005679E0
void __fastcall sub_6FC91050(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState)
{
    UNITS_RefreshInventory(pPlayer1, 1);
    UNITS_RefreshInventory(pPlayer2, 1);

    if (pPlayer1)
    {
        pPlayer1->dwFlagEx |= 0x800000;
    }

    if (pPlayer2)
    {
        pPlayer2->dwFlagEx |= 0x800000;
    }

    SUNIT_ResetInteractInfo(pPlayer1);
    SUNIT_ResetInteractInfo(pPlayer2);

    sub_6FC90AE0(pGame, pPlayer1, 1);
    sub_6FC90AE0(pGame, pPlayer2, 1);

    PLRTRADE_Free(pGame, pPlayer1);
    PLRTRADE_Free(pGame, pPlayer2);

    pPlayerData1->dwTradeState = nTradeState;
    pPlayerData2->dwTradeState = 9;

    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x969), 0xC);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x96A), 0xC);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer1, 0xD, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer2, 0xD, 0);

    EVENT_SetEvent(pGame, pPlayer1, 0xD, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pPlayer2, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568640
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int nUnitType;
    int nUnitGUID;
    if (!SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        return;
    }

    SUNIT_ResetInteractInfo(pPlayer);

    if (!SUNIT_GetInteractInfo(pOtherPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (nUnitGUID != nPlayerGUID)
    {
        return;
    }

    UNITS_GetPlayerData(pPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);

    sub_6FC90AE0(pGame, pPlayer, 0);
    sub_6FC90AE0(pGame, pOtherPlayer, 1);

    PLRTRADE_Free(pGame, pPlayer);
    PLRTRADE_Free(pGame, pOtherPlayer);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC2F), 0xC);
    SUNIT_ResetInteractInfo(pOtherPlayer);

    UNITS_GetPlayerData(pOtherPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568DC0
unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID)
{
    if (nGUID == -1)
    {
        return 0;
    }

    if (!pPlayer->pInventory)
    {
        return 0;
    }

    int nIdx = 1;
    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory);
    while (pNode)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pNode);
        pNode = INVENTORY_GetNextItem(pNode);
        if ((!pCheckedItem ? -1 : pCheckedItem->dwUnitId) == nGUID)
        {
            D2_ASSERT(nIdx < 0x7FFF, 0x185);
            return nIdx;
        }

        ++nIdx;
    }

    return 0;
}

// 0x00568E60
void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader)
{
    D2UnitStrc* pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, pHireling->dwUnitId);
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, 0xC, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    *(unsigned int*)pSaveHeader->f_B3 = pPetInfo->nSeed;
    *(unsigned short*)pSaveHeader->wMercName = pPetInfo->wName;
    *(unsigned short*)pSaveHeader->wMercHirelingId = pPetInfo->nHirelingId;
    *(unsigned int*)pSaveHeader->nMercExperience = STATLIST_UnitGetStatValue(pHireling, 0xD, 0);
    *(unsigned int*)pSaveHeader->MercSaveData = 0;
    *(unsigned short*)pSaveHeader->wMercName -= pHirelingTxtRecord->wNameFirst;

    if (SUNIT_IsDead(pHireling))
    {
        *(unsigned int*)pSaveHeader->MercSaveData |= 0x10000;
    }
}

// 0x00569A00
int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a5, int a6)
{
    unsigned char* pData = *ppSection;
    int bHasIronGolem = 0;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    *(unsigned short*)pData = 'fk';
    pData += 2;

    D2UnitStrc* pIronGolem = sub_6FC7E8B0(pGame, pPlayer, 3, 1);
    D2UnitStrc* pGolemItem = 0;
    D2UnitStrc* pFirst;
    if (pIronGolem && pIronGolem->dwClassId == 0x123 && SKILLS_GetSkill(pPlayer, 0x5A, -1) && pIronGolem->pInventory
        && (pFirst = INVENTORY_GetFirstItem(pIronGolem->pInventory)) != 0 && (pGolemItem = INVENTORY_UnitIsItem(pFirst)) != 0)
    {
        bHasIronGolem = 1;
    }

    unsigned char* pFlag = pData;
    *pData = bHasIronGolem;
    ++pData;
    if (bHasIronGolem)
    {
        const int nLength = D2GAME_SAVE_SerializeItem_6FC89AD0(pGame, pPlayer, pGolemItem, pData, pEnd - pData, 0, a5, a6);
        if (nLength <= 0)
        {
            *pFlag = 0;
        }

        pData += nLength;
    }

    *ppSection = pData;
    return 0;
}

// 0x00569F20
void __fastcall sub_00569F20_InitPlayerFromClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, 1);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->pTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    pPlayerData->unk0x54 = 0;
}
