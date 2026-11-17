struct D2InventoryStrc;
struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[96 - 4];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    char unk0x0C[420 - 4 - 8];
    unsigned char nToHitShift;
    unsigned char nSrcDam;
    char unk0x1A6[2];
    int dwMinDam;
    int dwMaxDam;
    int dwMinLvlDam[5];
    int dwMaxLvlDam[5];
    unsigned int dwDmgSymPerCalc;
    char unk0x1DC[572 - 420 - 0x38];
};

struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625EF0
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);                           // 0x00644B70
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00647BC0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
    {
        int nDamage;
        if (pUnit && pUnit->dwUnitType == 0)
        {
            nDamage = STATLIST_UnitGetStatValue(pUnit, 2, 0) + STATLIST_UnitGetStatValue(pUnit, 0, 0) - 20;
        }
        else
        {
            nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        }

        if (nDamage < 1)
        {
            nDamage = 1;
        }

        return nDamage / 4 << 8;
    }

    int nDamage = 0;
    if (pSkillsTxtRecord->nSrcDam && a4)
    {
        D2UnitStrc* pItem = D2Common_10434(pUnit, 0);
        int nWeaponDamage;
        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
                nWeaponDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
            else
                nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 21, 0);
        }
        else
        {
            nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 21, 0);
        }
        nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
    }

    nDamage += pSkillsTxtRecord->dwMinDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMinLvlDam);

    if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);
        if (nBonus)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
        }
    }

    return nDamage << pSkillsTxtRecord->nToHitShift;
}
