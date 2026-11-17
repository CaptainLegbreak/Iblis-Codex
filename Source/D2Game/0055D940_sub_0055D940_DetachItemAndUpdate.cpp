struct D2GameStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

#define IMODE_EQUIP 1

void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730

// 0x0055D940
static void __stdcall sub_0055D940_DetachItemAndUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    sub_0063D2B0_DetachItem(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == IMODE_EQUIP)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }
}

void __fastcall sub_K11_Emit0055D940(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    sub_0055D940_DetachItemAndUpdate(pGame, pUnit, pItem);
    sub_0055D940_DetachItemAndUpdate(pGame, pItem, pUnit);
}
