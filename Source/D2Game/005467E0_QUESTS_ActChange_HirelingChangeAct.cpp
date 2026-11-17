extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();

struct D2ClientStrc;
struct D2InventoryStrc;
struct D2BitBufferStrc;
struct D2PlrIntroStrc;
struct D2TextHeaderStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x8];
    int dwAnimMode;
    char pad0x14[0x4C];
    D2InventoryStrc* pInventory;
};

struct T005438E0;

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
    int bExpansion;
    char pad0x74[0x1080];
    T005438E0* pQuestControl;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char pad0x1C[0x30];
    int bBusy;
    char pad0x50[0x10];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

struct D2QuestDataStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

struct D2QuestDataStrc
{
    int nQuestNo;
    char pad0x04[0x5];
    unsigned char bNotIntro;
    char pad0x0A[0x96];
    QUESTCALLBACK pfCallback[15];
    char pad0xDC[0x18];
    D2QuestDataStrc* pPrev;
};

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
};

#pragma pack(push, 1)
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};
#pragma pack(pop)

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell);                               // 0x00628320
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                  // 0x0063C150
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId);                         // 0x00572420
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue);                   // 0x0053D940
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x00597310
void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame, D2UnitStrc* pObject);                              // 0x005BCFD0
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern int gpAct1_NPCIds_007318B0[6];                                                                       // 0x007318B0
extern int gpAct2_NPCIds_007318C8[11];                                                                      // 0x007318C8
extern int gpAct3_NPCIds_007318F4[7];                                                                       // 0x007318F4
extern int gpAct5_NPCIds_00731910[7];                                                                       // 0x00731910

// build: symbol ?QUESTS_DeleteItemEx@@YGXPAUD2InventoryStrc@@PAUD2GameStrc@@PAUD2UnitStrc@@2@Z 0x005440A0
static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0x534);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;
    switch (nAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, nFlags);
        D2GAME_RemoveItem_6FC471F0(pGame, pPlayer, pItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pItem);
        int a5;
        sub_6FC45B30(pGame, pPlayer, nBodyLoc, 1, &a5);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        break;
    }
}

// 0x00544160
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode)
{
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, dwCode);
    if (pItem)
    {
        QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
    }
}

static void sub_00544FA0_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 6; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct1_NPCIds_007318B0[i]);
        break;
    }
    case 1:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 11; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct2_NPCIds_007318C8[i]);
        break;
    }
    case 2:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct3_NPCIds_007318F4[i]);
        break;
    }
    case 4:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct5_NPCIds_00731910[i]);
        break;
    }
    }
}

static __forceinline D2QuestDataStrc* QUESTS_GetQuestDataInl_B08(D2GameStrc* pGame, int nId)
{
    if (!pGame->pQuestControl)
    {
        return 0;
    }
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
        {
            return pQuestData;
        }
    }
    return 0;
}

// 0x005467E0
void __fastcall QUESTS_ActChange_HirelingChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pVendor, unsigned int dwDestLvl, unsigned int nUnused)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    const int nVendorType = pVendor ? pVendor->dwUnitType : 6;
    if (nVendorType != 1)
    {
        return;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    switch (pVendor->dwClassId)
    {
    case 0x9B:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 7, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 13);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xAD3);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 2);
            }
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 0);
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 13) == 1 && QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestDataInl_B08(pGame, 6);
            if (pQuestData && pQuestData->bNotIntro)
            {
                D2QuestArgStrc tArgs;
                tArgs.pGame = pGame;
                tArgs.nEvent = 3;
                tArgs.nOldLevel = 1;
                tArgs.nNewLevel = 40;
                tArgs.pPlayer = pUnit;
                if (pQuestData->pfCallback[3])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfCallback[3]), 0xAEE);
                    pQuestData->pfCallback[3](pQuestData, &tArgs);
                }
            }
        }

        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case 0xD2:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 15, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 10, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);
                QUESTS_DeleteItem(pGame, pUnit, ' fsm');
                QUESTS_DeleteItem(pGame, pUnit, ' piv');
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 15, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 15, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xB0F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 3);
            }
        }
        break;

    case 0x16F:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0) && pGame->bExpansion)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, 0xB1F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GSPacketSrv5D packet5D = {};
                packet5D.nHeader = 0x5D;
                packet5D.nQuestId = 23;
                packet5D.nFlags = 2;
                sub_6FC3F380(pClient, &packet5D);
                sub_0053D940_SendPacket0x61(pClient, 5);
            }
        }
        break;
    }
}

// 0x00546AC0
void __fastcall QUESTS_HellPortalActChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nLevel, D2UnitStrc* pObject)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nLevel == 0x66)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x17, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x12, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 13);

                D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' yeq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rhq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rbq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 1fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 2fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 13);
            sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 2);
            D2BitBufferStrc* pPlayerFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            D2GAME_SendPacket0x28_6FC3F2F0(SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0xCA7), 0x28, 6, 0, pPlayerFlags, 0);
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 0xB56);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                sub_0053D940_SendPacket0x61(pClient, 4);
            }
        }
    }
    else
    {
        ACT3Q6_SetObjectModes(pGame, pObject);
    }
}
