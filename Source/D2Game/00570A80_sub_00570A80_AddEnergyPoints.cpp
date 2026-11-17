struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2CharStatsTxt
{
    char unk0x00[0x30];
    unsigned char nStr;
    unsigned char nDex;
    unsigned char nInt;
    unsigned char nVit;
    char unk0x34[0x12];
    unsigned char nLifePerVitality;
    unsigned char nStaminaPerVitality;
    unsigned char nManaPerMagic;
    char unk0x49[0x7B];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00570A80
static void sub_00570A80_AddEnergyPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, 4, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, 1, nPoints, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, 8, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            }
            STATLIST_AddUnitStat(pUnit, 9, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            const int nMaxMana = STATLIST_UnitGetStatValue(pUnit, 9, 0);
            if (STATLIST_UnitGetStatValue(pUnit, 8, 0) > nMaxMana)
            {
                STATLIST_SetUnitStat(pUnit, 8, nMaxMana, 0);
            }
        }
    }
}

// 0x00570B60
static void sub_00570B60_AddVitalityPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, 4, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, 3, nPoints, 0);
            STATLIST_AddUnitStat(pUnit, 7, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, 6, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            }
            const int nMaxHp = STATLIST_UnitGetStatValue(pUnit, 7, 0);
            if (STATLIST_UnitGetStatValue(pUnit, 6, 0) > nMaxHp)
            {
                STATLIST_SetUnitStat(pUnit, 6, nMaxHp, 0);
            }
            STATLIST_AddUnitStat(pUnit, 11, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, 10, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            }
            const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, 11, 0);
            if (STATLIST_UnitGetStatValue(pUnit, 10, 0) > nMaxStamina)
            {
                STATLIST_SetUnitStat(pUnit, 10, nMaxStamina, 0);
            }
        }
    }
}

// 0x00570C80
void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }
    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }
    int nDiff = pCharStatsTxtRecord->nStr - STATLIST_GetUnitBaseStat(pUnit, 0, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pUnit, 4, -nDiff, 0);
        STATLIST_AddUnitStat(pUnit, 0, nDiff, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
    sub_00570A80_AddEnergyPoints(pUnit, pCharStatsTxtRecord->nInt - STATLIST_GetUnitBaseStat(pUnit, 1, 0));
    nDiff = pCharStatsTxtRecord->nDex - STATLIST_GetUnitBaseStat(pUnit, 2, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pUnit, 4, -nDiff, 0);
        STATLIST_AddUnitStat(pUnit, 2, nDiff, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
    sub_00570B60_AddVitalityPoints(pUnit, pCharStatsTxtRecord->nVit - STATLIST_GetUnitBaseStat(pUnit, 3, 0));
}

// 0x00570D60
int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId)
{
    if (!STATLIST_UnitGetStatValue(pUnit, 4, 0))
    {
        return 0;
    }
    switch (nStatId)
    {
    case 0:
        STATLIST_AddUnitStat(pUnit, 4, -1, 0);
        STATLIST_AddUnitStat(pUnit, 0, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 1:
        sub_00570A80_AddEnergyPoints(pUnit, 1);
        return 1;
    case 2:
        STATLIST_AddUnitStat(pUnit, 4, -1, 0);
        STATLIST_AddUnitStat(pUnit, 2, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 3:
        sub_00570B60_AddVitalityPoints(pUnit, 1);
        return 1;
    }
    return 0;
}
