struct D2SkillStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    short nSkillId;
};

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit);                                        // 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A3E0

// 0x004E9160
static int __stdcall sub_004E9160_GetAttackRateValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == 38)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = 0;
    if (STATES_CheckState(pUnit, 78))
        nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);

    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 119, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    *pValue1 += *pValue1 * nBonus / 100;

    *pValue2 = 0;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

// 0x004E9590
void __fastcall sub_004E9590_SkillDescAttackRate(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    *pValue1 = 0;
    *pValue2 = 0;
    sub_004E9160_GetAttackRateValues(pUnit, 0, pValue1, pValue2, nLevel, pSkill);
}
