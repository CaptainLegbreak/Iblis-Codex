struct D2InventoryStrc;
struct D2SkillStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { char unk00[0x20]; D2SeedStrc pSeed; char unk28[0x38]; D2InventoryStrc* pInventory; };
D2UnitStrc* __fastcall sub_00535BC0_GetWeapon(D2UnitStrc*); // 0x00535BC0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc*, D2InventoryStrc*); // 0x0063D340
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc*, int, int); // 0x00625500
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc*); // 0x00629860
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc*); // 0x006298A0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc*, D2UnitStrc*, D2SkillStrc*, int); // 0x00645830
int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
// 0x0057B420
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam)
{
    if (bGetStats)
    {
        if (!pItem) pItem = sub_00535BC0_GetWeapon(pUnit);
        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
            {
                nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
                nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x18, 0);
            }
            else
            {
                nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
                nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            }
        }
        else
        {
            nMinDmg = STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
            if (nMinDmg <= 0) nMinDmg = 1;
            nMaxDmg = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            if (nMaxDmg <= 1) nMaxDmg = 2;
        }
        nMinDmg <<= 8;
        nMaxDmg <<= 8;
    }
    const int nBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x6F, 0) << 8;
    nMinDmg += nBonus;
    nMaxDmg += nBonus;
    if (nMinDmg < 1) nMinDmg = 256;
    if (nMaxDmg <= nMinDmg) nMaxDmg = nMinDmg + 256;
    nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
    if (pItem)
    {
        int nFactor = sub_00629860_GetStrengthFactor(pItem);
        if (nFactor) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
        nFactor = sub_006298A0_GetDexterityFactor(pItem);
        if (nFactor) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
        nDamagePercent += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, 0, 1);
    }
    else if (bGetStats) nDamagePercent += STATLIST_UnitGetStatValue(pUnit, 0, 0);
    if (nDamagePercent <= -90) nDamagePercent = -90;
    int nResult = nDamage;
    if (nMaxDmg > 0)
    {
        const int nMin = nMinDmg + DATATBLS_ApplyRatio(nMinDmg, nMinPercent + nDamagePercent, 100);
        const int nMax = nMaxDmg + DATATBLS_ApplyRatio(nMaxDmg, nMaxPercent + nDamagePercent, 100);
        nResult = nMin + nDamage;
        if (nMax > nMin) nResult += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin);
    }
    nResult = nResult < 0 ? 0 : nResult;
    if (nSrcDam != 0x80) return DATATBLS_ApplyRatio(nResult, nSrcDam, 0x80);
    return nResult;
}
