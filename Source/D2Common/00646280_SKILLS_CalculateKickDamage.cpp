struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0xFE];
    unsigned char nMinDam;
    unsigned char nMaxDam;
};

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem);                                          // 0x00629860
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem);                                         // 0x006298A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

// 0x00646280
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
    if (!pUnit)
    {
        return;
    }

    const int nKickDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x89, 0);
    *pMinDamage += nKickDamage;
    *pMaxDamage += nKickDamage;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    int nValue;
    D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pOtherHand = 0;
    if (pLeftHand)
    {
        nValue = ITEMS_GetBodyLocation(pLeftHand);
        pOtherHand = INVENTORY_GetItemFromBodyLoc(pInventory, (nValue == 4) + 4);
    }

    if (ITEMS_CheckItemTypeId(pLeftHand, 0x2D) && ITEMS_CanBeEquipped(pLeftHand) && STATLIST_GetOwner(pLeftHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 0);
    }
    else
    {
        pLeftHand = 0;
    }

    if (pOtherHand && pOtherHand != pLeftHand && ITEMS_CheckItemTypeId(pOtherHand, 0x2D) && ITEMS_CanBeEquipped(pOtherHand) && STATLIST_GetOwner(pOtherHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pOtherHand, 0);
    }

    D2UnitStrc* pBoots = INVENTORY_GetItemFromBodyLoc(pInventory, 9);
    if (pBoots && pBoots->dwUnitType == 4)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pBoots ? -1 : pBoots->dwClassId);
        if (pItemsTxtRecord)
        {
            int nMin = nKickDamage + pItemsTxtRecord->nMinDam;
            int nMax = nKickDamage + pItemsTxtRecord->nMaxDam;
            int nBonus = 0;
            nValue = sub_00629860_GetStrengthFactor(pBoots);
            if (nValue)
            {
                nBonus = DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, 0, 0), nValue, 100);
            }

            nValue = sub_006298A0_GetDexterityFactor(pBoots);
            if (nValue)
            {
                nBonus += DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, 2, 0), nValue, 100);
            }

            nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
            if (nBonus <= -90)
            {
                nBonus = -90;
            }

            const int nPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
            if (nMin >= nMax)
            {
                nMax = nMin;
            }

            *pDamagePercent += nPercent + nBonus;
            *pMinDamage += nMin;
            *pMaxDamage += nMax;
        }
    }

    if (pLeftHand)
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 1);
    }
}
