struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2MonUModTxt
{
    char unk0x00[0x1C];
    int dwConstant;
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x34];
    int dwChampionDmgBonus;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1CC];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall sub_00463860_GetMonsterId(D2UnitStrc* pUnit);                                                // 0x00463860
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

static __forceinline int sub_A17E0_GetUModConstant(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nUMod];
    if (!pMonUModTxtRecord)
    {
        return 0;
    }
    return pMonUModTxtRecord->dwConstant;
}

// 0x005A17E0
void __fastcall sub_005A17E0_UModDamageBonus(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    int nDamage;
    int nToHit;
    if (bUnique)
    {
        nDamage = sub_A17E0_GetUModConstant(15);
        nToHit = sub_A17E0_GetUModConstant(13);
    }
    else
    {
        nDamage = sub_A17E0_GetUModConstant(14);
        nToHit = sub_A17E0_GetUModConstant(12);
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = nDamage * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;
        nToHit = nToHit * pDifficultyLevelsTxtRecord->dwChampionDmgBonus / 100;

        const int nMonsterId = sub_00463860_GetMonsterId(pUnit);
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount && nMonsterId == 0x76)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, 0x19, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, 0x77, nToHit, 0);
}
