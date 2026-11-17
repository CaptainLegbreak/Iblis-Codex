struct D2StatListStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC0];
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);                // 0x0063C8F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall D2Common_10534(D2UnitStrc* pUnit);                                                           // 0x00625A00
int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused); // 0x00627810
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0

// 0x00621E40
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x80, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        D2Common_10534(pUnit);
        D2Common_10531_SetStatInStatListLayer0(pStatList, 0xB2, (unsigned short)nOverlay, nUnused);
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x006223F0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit)
{
    int nDefense = STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
    nDefense += STATLIST_UnitGetStatValue(pUnit, 2, 0) / 4;
    int nArmorPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0xAB, 0);
    nArmorPercent += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x10, 0);

    if (STATES_CheckState(pUnit, 0x65))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x65);
        if (pStatList)
        {
            const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
            const int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
            if (nSkillId > 0 && nSkillLevel > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord)
                {
                    D2UnitStrc* pShieldItem = 0;
                    INVENTORY_GetEquippedShield(pUnit->pInventory, &pShieldItem);
                    if (pShieldItem)
                    {
                        nArmorPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                    }
                }
            }
        }
    }

    if (nDefense > 0)
    {
        nDefense += nDefense * nArmorPercent / 100;
    }
    else
    {
        nDefense += nDefense * nArmorPercent / -100;
    }

    const int nArmorOverridePercent = STATLIST_UnitGetStatValue(pUnit, 0xB6, 0);
    if (nArmorOverridePercent)
    {
        nDefense += DATATBLS_ApplyRatio(nDefense, nArmorOverridePercent, 100);
    }
    return nDefense;
}

// 0x00622830
D2UnitStrc* __stdcall UNITS_GetEquippedWeaponFromMonster(D2UnitStrc* pMonster)
{
    D2UnitStrc* pItem;
    int bIsLeftHandItem;
    int nBodyLoc;

    const int nType = pMonster ? pMonster->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (!pMonster->pInventory)
    {
        return 0;
    }

    return INVENTORY_GetEquippedWeapon(pMonster->pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem) ? pItem : 0;
}
