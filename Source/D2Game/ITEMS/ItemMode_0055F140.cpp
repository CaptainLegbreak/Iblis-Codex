#include "D2Game.h"
#include "D2Structs.h"
struct D2ClientStrc;
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct BeltRect;
struct BeltRecord;


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
extern "C" char __stdcall sub_00628250(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

struct StaticPath
{
    U8 pad00[12];
    int x;
    int y;
};

struct Unit
{
    int type;
    int classId;
    U8 pad08[4];
    int id;
    int mode;
    U8 pad14[24];
    StaticPath* path;
    U8 pad30[48];
    void* inventory;
    U8 pad64[96];
    U32 flags;
};

struct Game
{
    U8 pad00[112];
    int expansion;
};
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
Unit* __fastcall sub_00552F60_Find(Game*, int, int); // 0x00552F60
void* __fastcall sub_005531C0_Client(Unit*, const char*, int); // 0x005531C0
void* __fastcall sub_00555DA0_FreeSpot(void*, Point*, Point*, int, U8); // 0x00555DA0
void __fastcall sub_00558AA0_Drop(Game*, Unit*, Unit*, void*, int, int); // 0x00558AA0
void __fastcall sub_0055BF50_Check(Unit*, const char*, int); // 0x0055BF50
void __fastcall sub_0055C270_Update(Unit*, Unit*); // 0x0055C270
void __fastcall sub_0055C2C0_Apply(Game*, Unit*, Unit*, int); // 0x0055C2C0
void __fastcall sub_0055DBC0_Refresh(Game*, Unit*, int); // 0x0055DBC0
int __fastcall sub_0055F590_CheckItem(Unit*, const char*, int); // 0x0055F590
void __fastcall sub_00568770_Special(Game*, Unit*, Unit*); // 0x00568770
extern "C" int __stdcall sub_00621050_Grid(Unit*, U8, int); // 0x00621050
extern "C" int __stdcall sub_006280A0_TestFlag(Unit*, U32, int, const char*); // 0x006280A0
extern "C" void __stdcall sub_006280D0_SetFlag(Unit*, U32, int); // 0x006280D0
extern "C" void __stdcall sub_00628170_CommandFlag(Unit*, U32, int); // 0x00628170
extern "C" U8 __stdcall sub_00628250_Page(Unit*); // 0x00628250
extern "C" void __stdcall sub_00628280_SetPage(Unit*, U8); // 0x00628280
extern "C" void __stdcall sub_00628320_SavePage(Unit*, U8); // 0x00628320
extern "C" void __stdcall sub_006287B0_Flags(U32*, U32, int); // 0x006287B0
extern "C" int __stdcall sub_0063B950_Place(void*, Unit*, int, int, U8, const char*, int); // 0x0063B950
extern "C" void __stdcall sub_0063BCF0_Trace(const char*, int, void*, int, int, int, int, U8); // 0x0063BCF0

struct BeltRect { int left, right, top, bottom; };

struct BeltRecord { char unknown00[4]; U8 nBoxes; U8 reserved5; unsigned short reserved6; BeltRect boxes[16]; };

extern "C" void __stdcall sub_00660CB0_Record(int, int, BeltRecord*); // 0x00660CB0
extern "C" int __stdcall UNITS_GetBeltType(Unit*); // 0x00621ED0
extern "C" Unit* __stdcall sub_0063C7F0_Belt(void*, int); // 0x0063C7F0
extern "C" void __stdcall sub_0063C550_Return(void*, int); // 0x0063C550
void __fastcall sub_0053EED0_RemoveBelt(void*, Unit*, Unit*, U32); // 0x0053EED0
void __fastcall sub_0055C6E0_OnItemToCursor(Unit*, Unit*); // 0x0055C6E0
void __fastcall sub_0055C730_UpdateProperties(Game*, Unit*, Unit*, int, int); // 0x0055C730

static void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

// 0x0055F140
int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* ptGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(ptGame, 0x15F3);
    D2_ASSERT(hUnit, 0x15F4);

    sub_0055BF50_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x15F7);

    D2InventoryStrc* pInventory = hUnit->pInventory;
    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMSIsA(pItem, 0x29) && !sub_00628250(pItem))
        {
            if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) - 1 > 0)
            {
                STATLIST_AddUnitStat(pItem, 0x46, -1, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1605), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, 0x46, 0), 0);
            }
            else
            {
                sub_0055E000_RemoveItemAndNotify(ptGame, hUnit, pItem);
            }

            return 1;
        }
    }

    return 0;
}

static int __stdcall sub_0055F5D0_HasSameAffixes(D2UnitStrc* pBook, D2UnitStrc* pItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        if (ITEMS_GetPrefixId(pBook, i) != ITEMS_GetPrefixId(pItem, i))
        {
            return 0;
        }

        if (ITEMS_GetSuffixId(pBook, i) != ITEMS_GetSuffixId(pItem, i))
        {
            return 0;
        }
    }

    return ITEMS_GetAutoAffix(pBook) == ITEMS_GetAutoAffix(pItem);
}

// 0x0055F640
D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity)
{
    if (!ITEMSIsA(pItem, 0x16))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        pCurrent = INVENTORY_GetNextItem(pCurrent);
        if (!pBook)
        {
            continue;
        }

        if (ITEMS_GetItemType(pBook) != 0x12)
        {
            continue;
        }

        if (ITEMS_GetInvPage(pBook))
        {
            continue;
        }

        if (!sub_0055F5D0_HasSameAffixes(pBook, pItem))
        {
            continue;
        }

        int nQuantity = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
        if (nQuantity < 0)
        {
            nQuantity = 0;
        }

        const int nMaxStack = ITEMS_GetTotalMaxStack(pBook);
        if (nQuantity >= nMaxStack)
        {
            continue;
        }

        *pFreeQuantity = nMaxStack - nQuantity;
        return pBook;
    }

    return 0;
}

static __forceinline int PlaceIntoInventory(Game* game, Unit* player, int itemId, int line)
{
        if (!game) return 0;
        {
            sub_0055BF50_Check(player, ".\\ITEMS\\ItemMode.cpp", 0x87B);
            Unit* placed = sub_00552F60_Find(game, 4, itemId);
            if (!placed || placed->type != 4 || placed->mode != 4) return 0;
            {
                U8 targetPage = sub_00628250_Page(placed);
                void* targetInventory = player->inventory;
                if (!targetInventory) return 0;
                int special = 0;
                int clearCursor = 1;
                int targetGrid = sub_00621050_Grid(player, targetPage, game->expansion);
                if (player->type == 0) {
                    switch (targetPage) {
                    case 1: clearCursor = 0; break;
                    case 2: special = 1; break;
                    }
                }
                if (!sub_0063B950_Place(targetInventory, placed, targetGrid, 0, targetPage, ".\\ITEMS\\ItemMode.cpp", line)) return 0;
                if (!sub_0063B210_Add(targetInventory, placed, 1)) return 0;
                if (sub_00628250_Page(placed) != 4) sub_0055C270_Update(player, placed);
                placed->flags &= -3;
                if (sub_0062FF70_Check(placed, player)) sub_0055C2C0_Apply(game, placed, player, 0);
                if (clearCursor) sub_0063C180_Cursor(targetInventory, 0);
                sub_00624690_Mode(placed, 0);
                sub_00628170_CommandFlag(placed, 2, 1);
                if (sub_0055F590_CheckItem(placed, ".\\ITEMS\\ItemMode.cpp", 0x8EA)) sub_006280D0_SetFlag(placed, 1, 1);
                if (sub_006280A0_TestFlag(placed, 0x4000, 0x8EE, ".\\ITEMS\\ItemMode.cpp")) sub_006280D0_SetFlag(placed, 0x4000, 0);
                sub_00621000_SetFlag(player, 1);
                sub_0063CC70_Refresh(targetInventory, placed);
                if (special == 1) sub_00568770_Special(game, player, placed);
                if (sub_0062FF70_Check(placed, player)) {
                    sub_0055DBC0_Refresh(game, player, 0);
                    sub_00621000_SetFlag(player, 1);
                }
                return 1;
            }
        }
}

// 0x005608C0
void __fastcall sub_005608C0_DowngradeBelt(Game* game, Unit* player, Unit* belt)
{
    void* hInventory = player->inventory;
    D2_ASSERT(hInventory, 0xC0C);
    BeltRecord record;
    if (belt) sub_00660CB0_Record(UNITS_GetBeltType(belt), 0, &record);
    else sub_00660CB0_Record(2, 0, &record);
    for (int index = 0; index < 16; ++index) {
        Unit* hItem = sub_0063C7F0_Belt(hInventory, index);
        if (index < record.nBoxes || !hItem) continue;
        U32 flags = 0;
        sub_006287B0_Flags(&flags, 32, 1);
        sub_0053EED0_RemoveBelt(sub_005531C0_Client(player, ".\\ITEMS\\ItemMode.cpp", 0xC1F), player, hItem, flags);
        Unit* removed = sub_0063AD90_Remove(hInventory, hItem);
        D2_ASSERT(removed, 0xC22);
        D2_ASSERT(hItem == removed, 0xC23);
        int x;
        switch (hItem->type) {
        case 2: case 4: case 5: x = hItem->path->x; break;
        default: x = hItem->path ? sub_006488C0_X(hItem->path) : 0; break;
        }
        sub_0063C550_Return(hInventory, x);
        sub_00624690_Mode(removed, 4);
        sub_0055C6E0_OnItemToCursor(player, hItem);
        sub_00628280_SetPage(hItem, 0);
        if (PlaceIntoInventory(game, player, hItem->id, 0xC29)) continue;
        {
            Point playerPosition;
            Point dropPosition;
            sub_00620870_Position(player, &playerPosition);
            void* room = sub_00555DA0_FreeSpot(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
            if (room) {
                sub_0055C730_UpdateProperties(game, hItem, player, 0, 1);
                sub_00558AA0_Drop(game, player, hItem, room, dropPosition.x, dropPosition.y);
            }
        }
    }
}
