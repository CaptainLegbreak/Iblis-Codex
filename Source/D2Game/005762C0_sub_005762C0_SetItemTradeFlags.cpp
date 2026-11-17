struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

#define UNIT_MONSTER 1
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_GOLD 14
#define STATE_FREEZE 1
#define STATE_POISON 2
#define IFLAG_NEWITEM 0x00000001
#define IFLAG_IDENTIFIED 0x00000010

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0
void __fastcall D2GAME_SendPacket0x2A_6FC3F3B0(D2ClientStrc* pClient, unsigned char nHeader, int nCode, int nGold, int nUnitGUID, int a6); // 0x0053D740
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);                    // 0x0055F590
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);   // 0x00562590
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);           // 0x00574EC0
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost);                   // 0x00576D90
void __fastcall sub_6FCC7FA0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int wName);           // 0x005770E0
int __fastcall sub_6FCC88B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int nItemGUID, int nItemMode, int nTransactionType, int nCost, int bMultibuy); // 0x00577830
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit);                                         // 0x00578C20
void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg); // 0x00578CA0
void __fastcall sub_6FCC84D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet);                     // 0x00579AA0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
unsigned int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                      // 0x00625D10
unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                      // 0x00625D60
unsigned int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                   // 0x00625DB0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pPlayer);                                                  // 0x0062A530
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling);                                  // 0x006637B0

static __forceinline D2BitBufferStrc* sub_00578460_GetQuestRecord(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005762C0
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pUnused, int bAdd, int nUnused)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);
    if (bAdd)
    {
        if (pItem)
        {
            pItem->dwFlagEx |= 4;
        }

        if (sub_0055F590_CheckItem(pItem, gszNpcSourceFile, 233))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);
        }

        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pItem);
    }
}

// 0x00577F30
int __fastcall D2GAME_NPC_BuyItemHandler_6FCC92A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy)
{
    D2_ASSERT(pGame, 2372);

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        return sub_6FCC88B0(pGame, pPlayer, pNpc, nItemId, nItemMode, nTransactionType, nCost, bMultibuy);
    }

    D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2380), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    return 1;
}

// 0x00577FE0
void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int a4)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        sub_6FCC7FA0(pGame, pPlayer, pNpc, a4);
    }
    else
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2477), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    }
}

// 0x00578460
void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcGUID);
    if (!pNpc || pInteractUnit != pNpc)
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2669), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch (pNpc->dwClassId)
    {
    case 244:
    case 245:
    case 246:
    case 265:
    case 520:
    {
        const int nUnidentifiedItems = ITEMS_GetNoOfUnidItems(pPlayer);
        if (!nUnidentifiedItems)
        {
            D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2689), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
            return;
        }

        if (QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 0) != 1
            && QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 1) != 1)
        {
            if (!sub_00576D90_SpendGold(pGame, pPlayer, 100 * nUnidentifiedItems))
            {
                D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2704), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
                return;
            }
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory); pNode; pNode = pNext)
        {
            pNext = INVENTORY_GetNextItem(pNode);
            const int nPage = INVENTORY_GetItemNodePage(pNode);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if ((nPage == 1 && (ITEMS_GetInvPage(pItem) == 0 || ITEMS_GetInvPage(pItem) == 3)) || nPage == 3)
            {
                if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2721, gszNpcSourceFile))
                {
                    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
                }
            }
        }

        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2730), 0x2A, 3, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        break;
    }
    default:
        break;
    }
}

// 0x00578D30
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    if (SUNIT_GetInteractUnit(pGame, pUnit) != pNpc)
    {
        return;
    }

    int bPlaySound = 0;

    const unsigned int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_HITPOINTS, nMaxHp, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_MANA, nMaxMana, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_STAMINA, nMaxStamina, pUnit);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_FREEZE);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        bPlaySound = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        bPlaySound = 1;
    }

    PLAYERPETS_IteratePets(pGame, pUnit, SUNITNPC_PetIterate_Heal, &bPlaySound);

    if (bPlaySound == 1)
    {
        SUNIT_AttachSound(pNpc, 10, 0);
    }
}

// 0x00579C00
void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (!pNpc || pInteractUnit != pNpc)
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2397), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch (pNpc->dwClassId)
    {
    case 150:
    case 198:
    case 252:
    case 367:
    case 515:
        break;
    default:
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2412), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2UnitStrc* pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2419), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    if (!sub_00576D90_SpendGold(pGame, pPlayer, MONSTERS_GetHirelingResurrectionCost(pHireling)))
    {
        D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2452), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    pHireling->dwFlags &= 0xFFFEFFFF;
    UNITS_ChangeAnimMode(pHireling, 1);
    STATLIST_SetUnitStat(pHireling, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pHireling), 0);
    sub_6FCC84D0(pGame, pPlayer, pHireling);
    D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2461), 0xFFFF, 0);
    const int nHirelingGUID = pHireling->dwUnitId;
    D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 2462), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), nHirelingGUID, 0);
}
