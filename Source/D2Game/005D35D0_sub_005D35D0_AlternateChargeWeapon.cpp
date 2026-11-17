struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc
{
    char unk0x00[0x38];
    int nSeqFrame;
    char unk0x3C[0x24];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490

// 0x005D35D0
int __fastcall sub_005D35D0_AlternateChargeWeapon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pRight == pLeft || !pRight || !pLeft || !ITEMS_CanBeEquipped(pRight) || !ITEMS_CanBeEquipped(pLeft) || !ITEMS_CheckItemTypeId(pRight, 45) || !ITEMS_CheckItemTypeId(pLeft, 45))
        {
            pUnit->dwFlags |= 0x40;
            SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
            return 1;
        }
    }
    const int nFrame = pUnit->nSeqFrame >> 8;
    if (nFrame % 2 == 0)
    {
        pUnit->dwFlags &= ~0x40;
        SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
        return 1;
    }

    pUnit->dwFlags |= 0x40;
    SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
    return 1;
}
