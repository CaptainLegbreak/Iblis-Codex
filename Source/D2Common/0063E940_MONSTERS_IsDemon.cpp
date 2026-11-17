struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    short nNextInClass;
    unsigned short wNameStr;
    unsigned short wDescStr;
    unsigned short unk0x0A;
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x10];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONSTATSFLAGINDEX_PRIMEEVIL 7
#define MONSTATSFLAGINDEX_LUNDEAD 11
#define MONSTATSFLAGINDEX_HUNDEAD 12
#define MONSTATSFLAGINDEX_DEMON 13
#define MONSTER_ROGUEHIRE 271
#define MONSTER_ACT2HIRE 338
#define MONSTER_ACT3HIRE 359
#define MONSTER_ACT5HIRE1 560
#define MONSTER_ACT5HIRE2 561

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0063E940
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_DEMON >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_DEMON & 7]) != 0;
}

// 0x0063E990
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_LUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_LUNDEAD & 7]
        || pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_HUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_HUNDEAD & 7];
}

// 0x0063EDC0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_PRIMEEVIL >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_PRIMEEVIL & 7];
}

// 0x0063EE90
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling)
{
    const unsigned int nUnitType = pHireling ? pHireling->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        switch (pHireling->dwClassId)
        {
        case MONSTER_ROGUEHIRE:
            return 1;

        case MONSTER_ACT2HIRE:
            return 2;

        case MONSTER_ACT3HIRE:
            return 3;

        case MONSTER_ACT5HIRE1:
        case MONSTER_ACT5HIRE2:
            return 4;

        default:
            break;
        }
    }

    return 0;
}
