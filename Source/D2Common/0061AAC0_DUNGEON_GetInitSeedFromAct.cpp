struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct D2DrlgActStrc
{
    char unk0x00[0xC];
    int dwInitSeed;
};

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2UniqueNameTxt
{
    unsigned short wStringId;
};

enum D2C_J11CalcConstants
{
    UNIT_ITEM = 4,
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C3E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90

D2UniqueNameTxt* gpUniqueNameTxtTables_0096D488[4];                                                         // 0x0096D488
int gnUniqueNameTxtRecordCounts_0096D498[4];                                                                // 0x0096D498

#define gpUniquePrefixTxt (gpUniqueNameTxtTables_0096D488[1])
#define gpUniqueSuffixTxt (gpUniqueNameTxtTables_0096D488[2])
#define gpUniqueAppellationTxt (gpUniqueNameTxtTables_0096D488[3])
#define gnUniquePrefixTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[1])
#define gnUniqueSuffixTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[2])
#define gnUniqueAppellationTxtRecordCount (gnUniqueNameTxtRecordCounts_0096D498[3])
Unicode gwszDataTablesDefault;                                                                              // 0x0096D4B4

// 0x0061AAC0
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct)
{
    if (!pAct)
    {
        return 0;
    }
    return pAct->dwInitSeed;
}

// 0x00627B70
int __fastcall sub_6FD98220(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (!pItemCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pItemCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x00643700
int __fastcall sub_00643700_SkillCalcGetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pSkillCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x0064B720
int __fastcall MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2UnitStrc* pMissile = (D2UnitStrc*)pUserData;
    if (!pMissile)
    {
        return 0;
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin + 1);
}

// 0x00650E50
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed)
{
    return pSeed->nLowSeed;
}

// 0x00653ED0
const Unicode* __fastcall DATATBLS_RollRandomUniquePrefixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniquePrefixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniquePrefixTxtRecordCount);
        if (gpUniquePrefixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniquePrefixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F10
const Unicode* __fastcall DATATBLS_RollRandomUniqueSuffixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueSuffixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueSuffixTxtRecordCount);
        if (gpUniqueSuffixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueSuffixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F50
const Unicode* __fastcall DATATBLS_RollRandomUniqueAppellationString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueAppellationTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueAppellationTxtRecordCount);
        if (gpUniqueAppellationTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueAppellationTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x0065E9E0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
        if (nMin >= nMax)
        {
            return nMin;
        }
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nMax - nMin + 1);
}
