#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2MonStatsTxt
{
    unsigned char unk_000[0x32];
    short nVelocity;
    unsigned char unk_034[0x1A8 - 0x34];
};
struct D2DataTablesStrc
{
    unsigned char unk_000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    unsigned char unk_A7C[4];
    int nMonStatsTxtRecordCount;
};
struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005A1910
void __fastcall sub_005A1910_ApplyVelocity(D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nVelocity > 0)
        {
            const int nValue = 0x800 / pMonStatsTxtRecord->nVelocity - 0x80;
            STATLIST_AddUnitStat(pUnit, 0x43, D2_MIN(D2_MAX(nValue, 10), 100), 0);
        }
    }
}
