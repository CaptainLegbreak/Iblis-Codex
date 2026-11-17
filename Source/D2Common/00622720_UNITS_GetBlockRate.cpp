struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2CharStatsTxt
{
    char unk0x00[0x49];
    unsigned char nBlockFactor;
    char unk0x4A[0x7A];
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x140];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_TYPES = 6,
    STAT_DEXTERITY = 2,
    STAT_LEVEL = 12,
    STAT_TOBLOCK = 20,
    MONSTATSFLAGINDEX_NOSHLDBLOCK = 26,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

int __fastcall sub_006225F0_MonsterCanBlock(D2UnitStrc* pUnit);                                             // 0x006225F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);                // 0x0063C8F0

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES;
    }
    return pUnit->dwUnitType;
}

static __forceinline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int MONSTERS_HasNoShieldBlockFlagInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NOSHLDBLOCK >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NOSHLDBLOCK & 7];
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00622720
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int bExpansion)
{
    int nBlockChance = 0;

    switch (UNITS_GetUnitTypeInline(pUnit))
    {
    case UNIT_PLAYER:
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
            nBlockChance += DATATBLS_GetCharStatsTxtRecordInline(pUnit->dwClassId)->nBlockFactor;
            if (bExpansion)
            {
                const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
                int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
                if (nLevel <= 1)
                {
                    nLevel = 1;
                }
                nBlockChance = nBlockChance * (nDexterity - 15) / (2 * nLevel);
            }
        }
        break;

    case UNIT_MONSTER:
        if (MONSTERS_HasNoShieldBlockFlagInline(UNITS_GetClassIdInline(pUnit)) || sub_006225F0_MonsterCanBlock(pUnit))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
        }
        break;
    }

    if (nBlockChance < 75)
    {
        return nBlockChance;
    }
    return 75;
}
