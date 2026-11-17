struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

#define INVPAGE_CUBE 3

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell);                               // 0x00628320
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0

// 0x00564F30
static int __stdcall sub_00564F30_RemoveCubeInputs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    int nCount = 0;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCheckedItem && ITEMS_GetInvPage(pCheckedItem) == INVPAGE_CUBE)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 32, 1);
            ITEMS_SetItemCell(pCheckedItem, INVPAGE_CUBE);
            D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pCheckedItem, nFlags);
            D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pCheckedItem, 0);
            nCount += 1;
        }
    }

    return nCount;
}

void __fastcall sub_K11_Emit00564F30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00564F30_RemoveCubeInputs(pGame, pUnit, SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrTrade.cpp", 1358));
}
