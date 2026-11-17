struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                   // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                               // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                              // 0x0063DFA0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);        // 0x005678A0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);    // 0x006280A0
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);   // 0x00562590

// 0x005BE180
static int sub_005BE180_INVENTORY_ContainsItem(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pInvItem = INVENTORY_GetFirstItem(pUnit->pInventory); pInvItem; pInvItem = INVENTORY_GetNextItem(pInvItem))
    {
        if (INVENTORY_UnitIsItem(pInvItem) == pTarget)
        {
            return 1;
        }
    }

    return 0;
}

// 0x005BE230
int __fastcall SKILLITEM_pSpell01_IdentifyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pTarget, 0x10, 147, ".\\SKILLS\\SkillItem.cpp"))
    {
        return 0;
    }

    if (!sub_005BE180_INVENTORY_ContainsItem(pTarget, pUnit))
    {
        return 0;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pUnit, pTarget);
    return 1;
}
