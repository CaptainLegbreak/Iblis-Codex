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
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x34];
    int nAiValue;
    int nAiState;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONSTATSFLAGINDEX_SWITCHAI 16

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline unsigned int MONSTERS_CheckMonStatsFlag(D2MonStatsTxt* pMonStatsTxtRecord, int nFlag)
{
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573040
static int sub_00573040_AiSwitchAllowed(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        if (MONSTERS_CheckMonStatsFlag(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId), MONSTATSFLAGINDEX_SWITCHAI))
        {
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_00573090_ApplyAiMode(D2UnitStrc* pUnit, int nState, int nValue)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && nState < 5 && sub_00573040_AiSwitchAllowed(pUnit))
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nAiState = nState;
            pMonsterData->nAiValue = nValue;
            return 1;
        }
    }
    return 0;
}
