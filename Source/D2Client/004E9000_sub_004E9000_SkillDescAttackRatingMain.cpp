struct D2StatListStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};
struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x02];
    unsigned char nFlags[8];
    char unk0x0C[0x48];
    short wAuraStat[6];
    char unk0x60[0x126];
    short wMinMana;
    short nManaShift;
    short wMana;
    short wLevelMana;
    char unk0x18E[0x06];
    short wSkillDesc;
    char unk0x196[0x0F];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit);                                        // 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A3E0
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

static int __stdcall sub_004E8EC0_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill); // 0x004E8EC0

static __declspec(noinline) int __stdcall sub_004E8EC0_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue2 = 0;
    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == 38)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);
    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pValue2 = 3;
        }
    }
    *pValue1 += *pValue1 * nBonus / 100;

    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

int __fastcall sub_004E8FE0_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem)
{
    return sub_004E8EC0_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

// 0x004E9000
void __fastcall sub_004E9000_SkillDescAttackRatingMain(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    D2UnitStrc* pItem = 0;
    if (pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    *pValue1 = 0;
    *pValue2 = 0;
    sub_004E8EC0_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}
