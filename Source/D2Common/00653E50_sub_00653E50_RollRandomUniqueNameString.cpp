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

struct Unicode
{
    unsigned short wChar;
};

struct D2UniqueNameTxt
{
    unsigned short wStringId;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C3E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern D2UniqueNameTxt* gpUniqueNameTxtTables_0096D488[4];                                                  // 0x0096D488
extern int gnUniqueNameTxtRecordCounts_0096D498[4];                                                         // 0x0096D498
extern Unicode gwszDataTablesDefault;                                                                       // 0x0096D4B4

// 0x00653E50
const Unicode* __fastcall sub_00653E50_RollRandomUniqueNameString(D2UnitStrc* pUnit, int nTable)
{
    if (pUnit && gnUniqueNameTxtRecordCounts_0096D498[nTable] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts_0096D498[nTable]);
        if (gpUniqueNameTxtTables_0096D488[nTable][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables_0096D488[nTable][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653E90
const Unicode* __fastcall DATATBLS_RollRandomUniqueTitleString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueNameTxtRecordCounts_0096D498[0] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts_0096D498[0]);
        if (gpUniqueNameTxtTables_0096D488[0][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables_0096D488[0][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}
