#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

struct D2CorpseStrc;


#define UNIT_PLAYER 0

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                            // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse);                                     // 0x0063D610
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x005746D0
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                   // 0x005407A0
void __fastcall PLAYERLIST_FreePlayerLists(D2GameStrc* pGame, D2UnitStrc* pPlayer);                         // 0x0055B790
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0057C980
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00555AE0
void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                // 0x0053F580
void __fastcall sub_00534880_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer);                  // 0x00534880
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

// 0x00534970
static void sub_00534970(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pUnit)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (pRoom)
            {
                const int guid=(pUnit ? pUnit->dwUnitId : -1);
                DUNGEON_AllocDrlgDelete(pRoom, pUnit->dwUnitType, guid);
            }
            SUNIT_RemoveUnit(pGame, pUnit);
        }
    }
}

// @ref 0x005349D0
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    PLAYERPETS_FreePetsFromPlayerData(pGame, pPlayer);
    PARTY_LeaveParty(pGame, pPlayer);
    PLAYERLIST_FreePlayerLists(pGame, pPlayer);
    SUNITDMG_FreeAttackerCombatList(pGame, pPlayer);
    sub_00534970(pGame, pPlayer);
    SUNIT_RemoveAllItemsFromInventory(pGame, pPlayer);
    INVENTORY_FreeInventory(pPlayer->pInventory);
    ARENA_FreeArenaUnit(pGame, pPlayer);
    sub_00534880_FreePlayerDataExtras(pGame, pPlayer);
    UNITS_FreePlayerData(pGame->pMemoryPool, pPlayer);
    if (pPlayer->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pPlayer->pHoverText);
    }
    sub_6FC349F0(pGame, pPlayer);
}
