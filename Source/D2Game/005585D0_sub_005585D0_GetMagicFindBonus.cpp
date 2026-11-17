#define UNIT_MONSTER 1
#define STAT_ITEM_MAGICBONUS 80

struct D2UnitStrc
{
    int dwUnitType;
};

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

// 0x005585D0
static int sub_005585D0_GetMagicFindBonus(D2UnitStrc* pPlayer)
{
    if (pPlayer && (unsigned int)pPlayer->dwUnitType <= UNIT_MONSTER)
    {
        int nMagicBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, STAT_ITEM_MAGICBONUS, 0);
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nMagicBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_MAGICBONUS, 0);
        }
        return nMagicBonus;
    }
    return 0;
}

int sub_B05_Emit_005585D0(int nBase, int nDiv, D2UnitStrc* pPlayer, int* pOut)
{
    nBase -= nDiv;
    const int nMagicBonus = sub_005585D0_GetMagicFindBonus(pPlayer);
    if (nMagicBonus && nMagicBonus <= -100)
    {
        return 0;
    }
    *pOut = nBase / nDiv;
    return nMagicBonus + 100;
}
