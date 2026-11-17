struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short nMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x00[0x11C];
    unsigned char nLocalBlood;
    char unk0x11D[0x134 - 0x11D];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
};

struct D2ShiftRowsStrc
{
    unsigned char aRows[8][256];
};

struct D2PalShiftStrc
{
    int unk0x000;
    D2ShiftRowsStrc tBase;
    D2ShiftRowsStrc tBlood;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned char* gpBloodRemap_007BB384;                                                                // 0x007BB384
void __fastcall sub_00477060_EmitSink(D2PalShiftStrc* pShift);

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId
static inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

static __declspec(noinline) void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftStrc* pShift);

// 0x00477060
static void sub_00477060_BuildBloodShift(int nMonsterId, D2PalShiftStrc* pShift)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2TxtRecord || pMonStats2TxtRecord->nLocalBlood != 2)
    {
        return;
    }

    pShift->tBlood = pShift->tBase;

    const unsigned char* pRemap = gpBloodRemap_007BB384;
    for (int nRow = 0; nRow < 8; ++nRow)
    {
        const unsigned char* pSrc = pShift->tBase.aRows[nRow];
        unsigned char* pDst = pShift->tBlood.aRows[nRow];
        for (int i = 0; i < 256; ++i)
        {
            const unsigned char nIndex = pSrc[i];
            if (pRemap[nIndex])
            {
                pDst[i] = pRemap[nIndex];
            }
        }
    }
}

// build: context sub_00477060_Shim

// calling-convention shim (not game code)
void __fastcall sub_00477060_Shim(D2PalShiftStrc* pShift, int nMonsterId)
{
    sub_00477060_BuildBloodShift(nMonsterId, pShift);
    sub_00477060_EmitSink(pShift);
}
