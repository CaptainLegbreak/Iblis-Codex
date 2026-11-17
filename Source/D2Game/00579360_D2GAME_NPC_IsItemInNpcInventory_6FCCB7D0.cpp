struct D2GameStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory;
    int dwGUID;
    D2NpcGambleStrc* pNext;
};

struct D2NpcRecordStrc
{
    int nNPC;
    void* pInventory;
    D2NpcGambleStrc* pGamble;
};

struct D2NpcVendorChainStrc
{
    int nPlayerGUID;
    unsigned char field_4;
};

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer); // 0x00536CB0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x00579360
int __fastcall D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int a4)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    if (pNpcRecord)
    {
        D2NpcVendorChainStrc* pNpcVendorChain = SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer);
        const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
        if (pNpcVendorChain && pNpcVendorChain->field_4)
        {
            if (!a4)
            {
                for (D2NpcGambleStrc* pGamble = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &a4)->pGamble; pGamble; pGamble = pGamble->pNext)
                {
                    if (pGamble->dwGUID == nPlayerGUID)
                    {
                        for (D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pGamble->pInventory); pInventoryItem; pInventoryItem = INVENTORY_GetNextItem(pInventoryItem))
                        {
                            if (INVENTORY_UnitIsItem(pInventoryItem) == pItem)
                            {
                                return 1;
                            }
                        }
                        break;
                    }
                }
                return 0;
            }
        }
        else if (!ITEMS_CheckItemFlag(pItem, 0x10, 4109, gszNpcSourceFile))
        {
            return 0;
        }
    }
    return 1;
}
