struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
};

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

struct D2MonStatsTxt
{
    char unk0x000[0x1C];
    short wMonType;
    char unk0x01E[0x18A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1BC];
    int nMonTypeTxtRecordCount;
    unsigned int* pMonTypeNest;
    int nMonTypeIndex;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_DAMAGE_VS_MONTYPE 180

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0

static __forceinline D2MonStatsTxt* U01_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* U01_GetUnitMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return U01_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

static __forceinline int U01_MonTypeMatches(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 0x1F];
    }

    return 0;
}

// 0x0057B6A0
static void __stdcall sub_0057B6A0_AddMonTypeDamagePercent(D2UnitStrc* pAttacker, D2DamageStrc* pDamage, D2UnitStrc* pDefender)
{
    const int nType = pDefender ? pDefender->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStats = U01_GetUnitMonStatsTxtRecord(pDefender);
        if (pMonStats && pMonStats->wMonType > 0)
        {
            D2StatStrc tStats[128];
            const int nMonType = pMonStats->wMonType;
            const int nStats = STATLIST_CopyStats(pAttacker, STAT_DAMAGE_VS_MONTYPE, tStats, 128);
            for (int i = 0; i < nStats; ++i)
            {
                if (U01_MonTypeMatches(tStats[i].nLayer, nMonType))
                {
                    pDamage->dwEnDmgPct += tStats[i].nValue;
                }
            }
        }
    }
}

// calling-convention shim (not game code)
void __stdcall sub_U01_EmitMonTypeDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    sub_0057B6A0_AddMonTypeDamagePercent(pAttacker, pDamage, pDefender);
    sub_0057B6A0_AddMonTypeDamagePercent(pDefender, pDamage, pAttacker);
}
