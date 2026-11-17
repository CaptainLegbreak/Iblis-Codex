struct D2MonStatsTxt { short nId; short nBaseId; char unk_04[0x1A4]; };
struct D2DataTablesStrc { char unk_000[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unk_A7C; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
// build: context GetMonStatsRecord
static __forceinline D2MonStatsTxt* GetMonStatsRecord(D2DataTablesStrc* pDataTables, int nClassId)
{
    D2MonStatsTxt* pRecord = 0;
    if (nClassId >= 0 && nClassId < pDataTables->nMonStatsTxtRecordCount)
    {
        pRecord = &pDataTables->pMonStatsTxt[nClassId];
    }
    return pRecord;
}

// 0x0054EC40
int __fastcall sub_0054EC40_IsSpecialBaseMonster(int nClassId)
{
    D2DataTablesStrc* pDataTables = sgptDataTables;
    if (nClassId < 0)
    {
        goto fail;
    }

    D2MonStatsTxt* pRecord = GetMonStatsRecord(pDataTables, nClassId);
    if (pRecord)
    {
        nClassId = pRecord->nBaseId;
    }

    if (nClassId < 0)
    {
        goto fail;
    }
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        goto fail;
    }
    if (nClassId == 19 || nClassId == 91)
    {
        return 1;
    }
fail:
    return 0;
}
