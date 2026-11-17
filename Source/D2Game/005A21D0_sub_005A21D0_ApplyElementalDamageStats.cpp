#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StatListStrc;

enum D2C_H16ElemConstants
{
    UNIT_MONSTER = 1,
    UNIT_MISSILE = 3,
    MONLVL_DM = 6,
    STAT_LEVEL = 12,
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x06];
    int dwGameType;
};

struct D2MissilesTxt
{
    char pad0x000[0x04];
    unsigned char nMissileFlags[4];
    char pad0x008[0x19C];
};

struct D2MonLvlTxt
{
    int nValues[10][3];
};

struct D2MonUModTxt
{
    char pad0x00[0x1C];
    int dwConstants;
};

struct D2DataTablesStrc
{
    char pad0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
    char pad0xB78[0xD8];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern const int gnUniqueElementalStats_006E21B8[5][3];                                                     // 0x006E21B8

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

static __forceinline D2MissilesTxt* MONUNIQUE_GetMissilesTxtRecord_Inline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static __forceinline D2MonLvlTxt* MONUNIQUE_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
        return &sgptDataTables->pMonLvlTxt[nLevel];
    return 0;
}

static __forceinline int MONUNIQUE_GetMonUModConstant_Inline(int nIndex)
{
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonUModTxtRecordCount)
        return 0;
    D2MonUModTxt* pRecord = &sgptDataTables->pMonUModTxt[nIndex];
    if (!pRecord)
        return (int)pRecord;
    return pRecord->dwConstants;
}

static __forceinline unsigned int MONUNIQUE_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005A21D0
static void __stdcall sub_005A21D0_ApplyElementalDamageStats(D2UnitStrc* pUnit, int nMinDamageStatId, int nMaxDamageStatId, int nLengthStatId, D2GameStrc* pGame)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = MONUNIQUE_GetMissilesTxtRecord_Inline(pUnit->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[1] & gdwBitMasks[5])
            return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = MONUNIQUE_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
        return;

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    const int nMinDamage = MONUNIQUE_GetMonUModConstant_Inline(28) * nDamage / 100;
    const int nMaxDamage = MONUNIQUE_GetMonUModConstant_Inline(31) * nDamage / 100;

    D2StatListStrc* pStatList = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
        STATLIST_SetStat(pStatList, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetStat(pStatList, nMaxDamageStatId, nMaxDamage, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pUnit, nMinDamageStatId, nMinDamage, 0);
        STATLIST_SetUnitStat(pUnit, nMaxDamageStatId, nMaxDamage, 0);
    }

    if (nLengthStatId == -1)
        return;

    const int nLength = STATLIST_UnitGetStatValue(pUnit, nLengthStatId, 0) + 40;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetStat(pStatList, nLengthStatId, nLength, 0);
    else
        STATLIST_SetUnitStat(pUnit, nLengthStatId, nLength, 0);
}

void __fastcall MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
        return;

    const unsigned int nRand = MONUNIQUE_RollSeed_Inline(&pUnit->pSeed) % 5;
    sub_005A21D0_ApplyElementalDamageStats(pUnit, gnUniqueElementalStats_006E21B8[nRand][0], gnUniqueElementalStats_006E21B8[nRand][1], gnUniqueElementalStats_006E21B8[nRand][2], pGame);
}
