struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);    // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char a3, int a4, int a5, unsigned short a6); // 0x0053D220
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);              // 0x00621050
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCF0
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571600
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                 // 0x0063CD60
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer);                                  // 0x0062FF70
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);    // 0x0055DBC0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, int nFlag);                                         // 0x00628140
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380

#define UNIT_PLAYER 0
#define UNIT_ITEM 4
#define IMODE_STORED 0
#define UNITFLAG_TARGETABLE 0x2
#define IFLAG_NEWITEM 0x1
#define IFLAG_TARGETING 0x4
#define IFLAG_IDENTIFIED 0x10
#define IFLAG_NOEQUIP 0x4000
#define INVPAGE_NULL 0xFF

// 0x0055BF50
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_CheckItemFlag(pInvItem, IFLAG_TARGETING, 0x1D6, ".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(pInvItem, IFLAG_TARGETING, 0);
            if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == UNIT_PLAYER)
            {
                D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1DA), pInvItem, 0xFF, 1, 0, 0xFFFF);
            }
        }
    }
}

// 0x0055DF10
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket)
{
    D2_ASSERT(pGame, 0xF6F);
    D2_ASSERT(pUnit, 0xF70);

    if (pItem)
    {
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemove, 0xF76);
    D2_ASSERT(pItem == pRemove, 0xF77);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF7B, pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nRecordId, 0, nPage);
    ITEMS_SetInvPage(pItem, INVPAGE_NULL);

    if (bSendPacket)
    {
        sub_00571600(pItem, SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF7E));
    }

    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

// 0x0055F240
int __fastcall sub_0055F240_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

// 0x0055F590
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_CheckIfSocketable(pItem) && pItem->pInventory && INVENTORY_GetItemCount(pItem->pInventory) > 0)
    {
        return 1;
    }

    return 0;
}

// 0x0055FE00
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);

    if (pItem && pItem->dwAnimMode != IMODE_STORED)
    {
        return;
    }

    if (!ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        return;
    }

    D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pPlayer, 0);
    sub_0055DBC0(pGame, pPlayer, 0);
    UNITS_RefreshInventory(pPlayer, 1);
}
