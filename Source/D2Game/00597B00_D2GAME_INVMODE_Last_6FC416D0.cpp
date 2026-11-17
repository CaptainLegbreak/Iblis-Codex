extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
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
#define IFLAG_SWITCHOUT 0x00000080

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc* pGame, D2UnitStrc* pItem);                   // 0x005979B0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0
int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, int nFlag);                                        // 0x00628140
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory);                   // 0x0063CBB0
void __stdcall INVENTORY_FreeTradeInventory(D2InventoryStrc* pInventory);                                   // 0x0063CBD0
D2InventoryNodeStrc* __stdcall INVENTORY_GetNextNode(D2InventoryNodeStrc* pNode);                          // 0x0063CD20
int __stdcall INVENTORY_GetItemGUIDFromNode(D2InventoryNodeStrc* pNode);                                   // 0x0063CD40

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00597B00
void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    UNITS_RefreshInventory(pUnit, 0);

    for (D2InventoryNodeStrc* pInventoryNode = INVENTORY_GetTradeInventory(pInventory); pInventoryNode; pInventoryNode = INVENTORY_GetNextNode(pInventoryNode))
    {
        D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(pInventoryNode));
        if (pItem)
        {
            if (ITEMS_CheckItemCMDFlag(pItem, 0x10) || ITEMS_CheckItemCMDFlag(pItem, 0x4000))
            {
                ITEMS_SetBodyLocation(pItem, 0);
            }

            if (ITEMS_CheckItemCMDFlag(pItem, 0x20) && ITEMS_CheckItemFlag(pItem, IFLAG_SWITCHOUT, 384, ".\\INVENTORY\\InvMode.cpp"))
            {
                ITEMS_SetBodyLocation(pItem, 0);
            }

            D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pItem);

            if (UNIT_HasFlagEx(pItem, UNITFLAGEX_HASINV))
            {
                UNITS_RefreshInventory(pItem, 0);

                D2InventoryStrc* pItemInventory = pItem->pInventory;
                D2_ASSERT(pItemInventory, 420);

                for (D2InventoryNodeStrc* i = INVENTORY_GetTradeInventory(pItemInventory); i; i = INVENTORY_GetNextNode(i))
                {
                    D2UnitStrc* pNestedItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(i));
                    if (pNestedItem)
                    {
                        D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pNestedItem);
                    }
                }

                INVENTORY_FreeTradeInventory(pItemInventory);
            }

            if (ITEMS_CheckItemCMDFlag(pItem, 1))
            {
                ITEMS_RemoveFromAllPlayers(pGame, pItem);
            }
        }
    }

    INVENTORY_FreeTradeInventory(pInventory);
}
