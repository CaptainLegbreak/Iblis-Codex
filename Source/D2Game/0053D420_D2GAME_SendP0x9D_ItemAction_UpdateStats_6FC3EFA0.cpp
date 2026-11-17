struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0
void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053EAE0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem);                                               // 0x006282F0
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask);                            // 0x006287A0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

#define ITEMACTION_ADDTOGROUND 0
#define ITEMACTION_GROUNDTOCURSOR 1
#define ITEMACTION_PUTINCONTAINER 4
#define ITEMACTION_ADDQUANTITY 10
#define ITEMACTION_ADDTOSHOP 11
#define ITEMACTION_REMOVEFROMSHOP 12
#define ITEMACTION_SWAPINCONTAINER 13
#define ITEMACTION_PUTINBELT 14
#define ITEMACTION_REMOVEFROMBELT 15
#define ITEMACTION_SWAPINBELT 16
#define ITEMACTION_TOCURSOR 18
#define ITEMACTION_ITEMINSOCKET 19
#define ITEMACTION_UPDATESTATS 21
#define ITEMACTION_UNKNOWN0x16 22
#define IFLAG_DELETED 0x00000008
#define IFLAG_IDENTIFIED 0x00000010
#define IFLAG_QUANTITY 0x00000020

// 0x0053D420
void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UPDATESTATS, dwFlags, 0);
}

// 0x0053D4B0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x16, dwFlags, 0);
}

// 0x0053EA50
int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags)
{
    if (ITEMS_CheckIfSocketable(pItem) && !sub_006287A0_TestFlags(nFlags, IFLAG_QUANTITY) && pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            ITEMS_SetOrRemoveFlag(&nFlags, IFLAG_DELETED, 1);
            D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pItem, pSocketed, ITEMACTION_ITEMINSOCKET, nFlags, 0);
        }
        return 1;
    }
    return 0;
}

// 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDTOGROUND, dwFlag, 0);
}

// 0x0053EC20
void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2002) == pClient, 2002);

    UNITS_SetXForStaticUnit(pItem, 0);
    UNITS_SetYForStaticUnit(pItem, 0);
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_GROUNDTOCURSOR, a4, 0);
}

// 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2031) == pClient, 2031);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_PUTINCONTAINER, a4, 0);
}

// 0x0053EDB0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2121) == pClient, 2121);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDQUANTITY, a4, 0);
}

// 0x0053EE10
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2131) == pClient, 2131);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_SWAPINCONTAINER, a4, 0);
}

// 0x0053EE70
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2140) == pClient, 2140);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_PUTINBELT, a4, 0);
}

// 0x0053EED0
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_REMOVEFROMBELT, dwFlag, 0);
}

// 0x0053EEF0
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a3)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_SWAPINBELT, a3, 0);
}

// 0x0053EF10
void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_TOCURSOR, 0, 0);
}

// 0x0053EF30
void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char a3)
{
    switch (a3)
    {
    case 56:
    {
        int bIdentified = 0;
        if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem) && !ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2498, ".\\GAME\\SCmd.cpp"))
        {
            bIdentified = 1;
        }
        D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDTOSHOP, 0, bIdentified);
        break;
    }
    case 57:
    {
        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
        D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_REMOVEFROMSHOP, 0, 0);
        ITEMS_SetInvPage(pItem, nPage);
        break;
    }
    }
}
