struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nTypeFlag;
    char unk0x18[0x04];
    unsigned char nMonUmod[10];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

struct D2MonUModTxt
{
    char unk0x00[0x08];
    unsigned char nChampion;
    char unk0x09[0x17];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC50];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

#define UNIT_MONSTER 1
#define MONTYPEFLAG_CHAMPION 4
#define MONSTERUNIQUE_UMOD_COUNT 9

static __forceinline D2MonUModTxt* sub_M433_GetMonUModTxtRecord(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pMonUModTxt[nUMod];
}

// 0x005A0280
int __fastcall sub_005A0280_GetChampionUMod(D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    D2MonsterDataStrc* pMonsterData = (nUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }

    if (!(pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        return 0;
    }

    for (int i = 0; i < MONSTERUNIQUE_UMOD_COUNT; ++i)
    {
        if (!pMonsterData->nMonUmod[i])
        {
            return 0;
        }

        D2MonUModTxt* pMonUModTxtRecord = sub_M433_GetMonUModTxtRecord(pMonsterData->nMonUmod[i]);
        if (!pMonUModTxtRecord)
        {
            return 0;
        }

        if (pMonUModTxtRecord->nChampion)
        {
            return pMonsterData->nMonUmod[i];
        }
    }

    return 0;
}
