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
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
};

void __fastcall D2GAME_STORES_FillGamble_6FCCA9F0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pUnit, D2NpcRecordStrc* pNpcRecord); // 0x00578790

// 0x00578AE0
void __fastcall sub_00578AE0_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord)
{
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    int bHasGamble = 0;
    for (D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble; pNpcGamble; pNpcGamble = pNpcGamble->pNext)
    {
        if (pNpcGamble->dwGUID == nPlayerGUID)
        {
            bHasGamble = 1;
        }
    }

    if (!bHasGamble)
    {
        D2GAME_STORES_FillGamble_6FCCA9F0(pGame, pNpc, pPlayer, pNpcRecord);
    }
}
