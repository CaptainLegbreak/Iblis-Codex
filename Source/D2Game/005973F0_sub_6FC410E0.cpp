extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2InventoryNodeStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x64];
    unsigned int dwFlagEx;
};

#define UNIT_ITEM 4
#define UNITFLAGEX_HASINV 0x00000001
#define UNITFLAGEX_ISVENDORITEM 0x00000004
#define UNITFLAGEX_ITEMINIT 0x00000010
#define IFLAG_NEWITEM 0x00000001
#define IFLAG_BROKEN 0x00000100
#define IFLAG_REPAIRED 0x00000200
#define IFLAG_UNK2 0x00040000
#define IMODE_STORED 0
#define IMODE_EQUIP 1
#define IMODE_INBELT 2

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090
void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0B0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0D0
void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0F0
void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D110
void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D2C0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D350
void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D420
void __fastcall sub_6FC3EFC0(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int a4, int a5); // 0x0053D440
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D4B0
void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EC20
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EDB0
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EE10
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nFlags); // 0x0053EED0
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a3); // 0x0053EEF0
void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0053EF10
void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, char a3); // 0x0053EF30
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00554D00
void __fastcall D2GAME_ITEMS_UpdateInventoryItems_6FC45050(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x0055F4F0
int __fastcall D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int a4); // 0x00579360
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0
int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, int nFlag);                                        // 0x00628140
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory);                   // 0x0063CBB0
D2InventoryNodeStrc* __stdcall INVENTORY_GetNextNode(D2InventoryNodeStrc* pNode);                          // 0x0063CD20
int __stdcall INVENTORY_GetItemGUIDFromNode(D2InventoryNodeStrc* pNode);                                   // 0x0063CD40
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                               // 0x0063EE90

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x005973F0
static int sub_6FC410E0(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pUnused, D2ClientStrc* pClient)
{
    D2UnitStrc* pClientPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pClientPlayer);

    if (pItem)
    {
        if (UNIT_HasFlagEx(pItem, UNITFLAGEX_ISVENDORITEM))
        {
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(pGame, pClientPlayer, pInteractUnit, pItem, 0))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(pClient, pPlayer, pItem, 56);
            }
            return 1;
        }

        if (UNIT_HasFlagEx(pItem, UNITFLAGEX_ITEMINIT))
        {
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(pGame, pClientPlayer, pInteractUnit, pItem, 1))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(pClient, pPlayer, pItem, 57);
            }
            return 1;
        }
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x80000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 2) || ITEMS_CheckItemCMDFlag(pItem, 0x80)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 4) && pPlayer == pClientPlayer)
    {
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 8) || ITEMS_CheckItemCMDFlag(pItem, 0x200))
    {
        D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10000))
    {
        D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10))
    {
        D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x20))
    {
        D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 0x400) || ITEMS_CheckItemCMDFlag(pItem, 0x2000)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x800) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x1000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(pClient, pPlayer, pItem);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x200000))
    {
        D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x4000))
    {
        D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x8000))
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 183, ".\\INVENTORY\\InvMode.cpp"))
    {
        if (pPlayer != pClientPlayer && (!pItem || pItem->dwAnimMode != 1))
        {
            return 0;
        }
        sub_6FC3EFC0(pClient, pPlayer, pItem, IFLAG_BROKEN, ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 193, ".\\INVENTORY\\InvMode.cpp"));
        return 1;
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_REPAIRED, 197, ".\\INVENTORY\\InvMode.cpp"))
    {
        if (pPlayer == pClientPlayer || pItem && pItem->dwAnimMode == 1)
        {
            sub_6FC3EFC0(pClient, pPlayer, pItem, IFLAG_REPAIRED, ITEMS_CheckItemFlag(pItem, IFLAG_REPAIRED, 207, ".\\INVENTORY\\InvMode.cpp"));
            return 1;
        }
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_NEWITEM, 211, ".\\INVENTORY\\InvMode.cpp"))
    {
        const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;

        if (pPlayer != pClientPlayer && (nAnimMode == IMODE_STORED || nAnimMode == IMODE_INBELT))
        {
            return 0;
        }

        if (nAnimMode != IMODE_STORED && nAnimMode != IMODE_EQUIP && nAnimMode != IMODE_INBELT)
        {
            return 0;
        }

        if (pPlayer != pClientPlayer || !ITEMS_CheckItemFlag(pItem, IFLAG_UNK2, 227, ".\\INVENTORY\\InvMode.cpp"))
        {
            D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(pClient, pPlayer, pItem, 0);
            return 1;
        }
    }

    return 0;
}

// 0x00597890
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 244);

    if (pInventoryArg)
    {
        pInventory = pInventoryArg;
    }

    D2InventoryNodeStrc* pNode = INVENTORY_GetTradeInventory(pInventory);
    if (!pNode)
    {
        return;
    }

    do
    {
        D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(pNode));
        if (pItem)
        {
            sub_6FC410E0(pUnit, pItem, 0, pClient);

            if (UNIT_HasFlagEx(pItem, UNITFLAGEX_HASINV))
            {
                D2_ASSERT(pItem->pInventory, 264);

                for (D2InventoryNodeStrc* i = INVENTORY_GetTradeInventory(pItem->pInventory); i; i = INVENTORY_GetNextNode(i))
                {
                    D2UnitStrc* pNestedItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(i));
                    if (pNestedItem)
                    {
                        sub_6FC410E0(pUnit, pItem, pNestedItem, pClient);
                    }
                }
            }
        }

        pNode = INVENTORY_GetNextNode(pNode);
    }
    while (pNode);

    if (MONSTERS_GetHirelingTypeId(pUnit))
    {
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pUnit, 0, 1);
        sub_0055F4F0(pGame, pUnit, 1);
    }
}
