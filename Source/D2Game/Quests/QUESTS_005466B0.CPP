#include "D2Game.h"

struct D2ItemsTxt;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};
struct D2CoordStrc
{
    int nX;
    int nY;
};

void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId); // 0x00558200
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall sub_00628280_SetItemValue(D2UnitStrc* pItem, int nValue); // 0x00628280
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

// 0x005466B0
D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable)
{
    int nItemId;
    if (DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId))
    {
        int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
        if (nLevel)
            nItemLevel = nLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pPlayer, nItemId, pGame, 4, nQuality, 0, 1, nItemLevel, 0, 0, 0);
        if (!pItem)
            return 0;

        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability > 0)
            STATLIST_SetUnitStat(pItem, 0x48, nMaxDurability, 0);

        sub_00628280_SetItemValue(pItem, 0);

        if (D2GAME_PlaceItem_6FC44410(".\\QUESTS\\QUESTS.CPP", 0x9CF, pGame, pPlayer, (!pItem ? -1 : pItem->dwUnitId), 0, 0, 1, 1, 0))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x9D2, ".\\QUESTS\\QUESTS.CPP"))
                D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
            return pItem;
        }

        if (bDroppable)
        {
            D2CoordStrc tCoord;
            UNITS_GetCoords(pPlayer, &tCoord);
            D2ActiveRoomStrc* pRoom;
            QUESTS_GetFreePosition(UNITS_GetRoom(pPlayer), &tCoord, 1, 0x3E01, &pRoom, 5, 100);
            D2GAME_DropItem_6FC52260(pGame, 0, pItem, pRoom, tCoord.nX, tCoord.nY);
            return pItem;
        }

        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
    return 0;
}
