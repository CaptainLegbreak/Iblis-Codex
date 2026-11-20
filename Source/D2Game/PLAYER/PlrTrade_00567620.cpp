#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"



struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    int dwTradeState;
    char unk0x54[0x08];
    void* pTrade;
};

struct D2ItemsTxt
{
    char unk0x000[0x80];
    unsigned int dwCode;
    char unk0x084[0xA6];
    unsigned char nQuest;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame);                                               // 0x005B5810
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask);                         // 0x00463720
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0

// 0x00566E20
static __declspec(noinline) int sub_00566E20_HasItemsInCube(D2UnitStrc* pPlayer)
{
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem)) == 3)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00567620
int __fastcall sub_00567620(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        if (nUnitType != 0)
        {
            return 1;
        }
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (pOtherPlayer)
        {
            D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
            if (!pPlayerData2->pTrade)
            {
                return 0;
            }
            if (ACT4Q2_HasDiabloBeenKilled(pGame))
            {
                return 0;
            }
            if (sub_00463720_TestUnitFlagEx(pPlayer, 0x800000) || sub_00463720_TestUnitFlagEx(pOtherPlayer, 0x800000))
            {
                return 0;
            }
            D2_ASSERT(pPlayerData1->pTrade, 0xD3C);
            int nResult = 1;
            if (pPlayerData1->dwTradeState == 4)
            {
                nResult = 0;
            }
            if (pItem && pItem->dwUnitType == 4)
            {
                int nClassId = pItem->dwClassId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                if (pItemsTxtRecord->nQuest)
                {
                    if (pItemsTxtRecord->dwCode == 0x20786F62)
                    {
                        if (sub_00566E20_HasItemsInCube(pPlayer))
                        {
                            nResult = 0;
                            PLRTRADE_SendEventPacketToPlayer(pPlayer, 0xA, 0);
                        }
                    }
                    if (ITEMS_FindQuestItem(pGame, pOtherPlayer, pItemsTxtRecord->dwCode))
                    {
                        nResult = 0;
                    }
                }
                else
                {
                    if (ITEMS_CheckItemFlag(pItem, 0x1000, 0xD58, ".\\PLAYER\\PlrTrade.cpp"))
                    {
                        nResult = 0;
                    }
                    else
                    {
                        ITEMS_GetItemQuality(pItem);
                    }
                }
            }
            if (pPlayer)
            {
                pPlayer->dwFlagEx |= 0x400000;
            }
            pPlayerData1->dwTradeState = 7;
            pPlayerData2->dwTradeState = 7;
            EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6E), 6);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6F), 6);
            return nResult;
        }
    }
    return pPlayerData1->dwTradeState <= 4;
}
