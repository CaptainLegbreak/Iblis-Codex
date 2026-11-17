struct D2UnitStrc;

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x06];
    int dwGameType;
};

struct D2MonLvlTxt
{
    int nValues[10][3];
};

struct D2DataTablesStrc
{
    char pad0x000[0xB70];
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
};

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

enum D2C_Y09SummonConstants
{
    STAT_LEVEL = 12,
    STAT_TOHIT = 19,
    STAT_ARMORCLASS = 31,
    MONLVL_AC = 0,
    MONLVL_TH = 2,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C49E0
int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel)
{
    int nPetLevel = nPetLevelArg;
    if (nPetLevelArg <= 0)
    {
        const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        nPetLevel = nSkillLevel + 3 * nUnitLevel / 4;
        nPetLevel = D2_MIN(D2_MAX(nPetLevel, 1), nUnitLevel);
    }

    if (nPetLevel)
    {
        STATLIST_SetUnitStat(pPet, STAT_LEVEL, nPetLevel, 0);
    }

    if (nPetLevel >= sgptDataTables->nMonLvlTxtRecordCount - 1)
    {
        nPetLevel = sgptDataTables->nMonLvlTxtRecordCount - 1;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nPetLevel);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    STATLIST_AddUnitStat(pPet, STAT_ARMORCLASS, pMonLvlTxtRecord->nValues[MONLVL_AC + nGameType][nDifficulty], 0);
    STATLIST_AddUnitStat(pPet, STAT_TOHIT, pMonLvlTxtRecord->nValues[MONLVL_TH + nGameType][nDifficulty], 0);
    return 1;
}
