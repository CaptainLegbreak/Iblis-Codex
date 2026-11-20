#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"





D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

#define UNIT_PLAYER 0
#define STAT_GOLD 14
#define STAT_QUESTITEMDIFFICULTY 356
#define GOLD_PILE_MAX 2000000000

static __forceinline void D2GAME_SetStatOrResetGold_Inline(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00558110
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && dwItemCode == ITEMS_GetBaseCode(pCursorItem))
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCursorItem->dwClassId);
        if (!pItemsTxtRecord || !pItemsTxtRecord->nQuest || pGame->nDifficulty <= STATLIST_UnitGetStatValue(pCursorItem, STAT_QUESTITEMDIFFICULTY, 0))
        {
            return pCursorItem;
        }
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckItem = INVENTORY_UnitIsItem(pItem);
        if (dwItemCode == ITEMS_GetBaseCode(pCheckItem) && ITEMS_GetInvPage(pCheckItem) != INVPAGE_EQUIP)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pCheckItem ? -1 : pCheckItem->dwClassId);
            if (!pItemsTxtRecord || !pItemsTxtRecord->nQuest || !pItemsTxtRecord->nQuestDiffCheck || pGame->nDifficulty <= STATLIST_UnitGetStatValue(pCheckItem, STAT_QUESTITEMDIFFICULTY, 0))
            {
                return pCheckItem;
            }
        }
    }

    return 0;
}

// 0x0055A090
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount)
{
    *pCount = 0;

    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(' dlg', &nItemId))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    unsigned int nDropped = 0;
    const unsigned int nTotal = nAmount;
    while (nDropped < nTotal)
    {
        if (*pCount >= nMaxCount)
        {
            return;
        }

        const unsigned int nPile = nAmount > GOLD_PILE_MAX ? GOLD_PILE_MAX : nAmount;
        nDropped += nPile;
        nAmount -= nPile;

        D2CoordStrc tCoord;
        UNITS_GetCoords(pUnit, &tCoord);

        const int nX = tCoord.nX + 2;
        const int nY = tCoord.nY + 3;
        D2CoordStrc tSpawn;
        if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
        {
            tSpawn.nX = nX;
            tSpawn.nY = nY;
        }
        else
        {
            tSpawn = tCoord;
        }

        pRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &tSpawn, &tCoord, 1, 0x3E01, 0x801, 0);
        if (!pRoom)
        {
            return;
        }

        D2UnitStrc* pGold = D2GAME_CreateItemUnit_6FC501A0(pUnit, nItemId, pGame, 4, 2, 1, 1, 1, 0, 0, 0);
        if (pGold)
        {
            D2GAME_SetStatOrResetGold_Inline(pGold, STAT_GOLD, nPile);
            D2GAME_DropItem_6FC52260(pGame, pUnit, pGold, pRoom, tSpawn.nX, tSpawn.nY);
            ppGold[*pCount] = pGold;
            *pCount += 1;
        }
    }
}
