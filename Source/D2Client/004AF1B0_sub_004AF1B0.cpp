struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x004[0x52];
    short wAiParam[8][3];
    char unk0x086[0x1A8 - 0x86];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
void __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nMissile, int nX, int nY, int a5, int a6); // 0x004CDBA0
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed);                                          // 0x00650E40

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int GetBaseId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004AF1B0
void __stdcall sub_004AF1B0(D2UnitStrc* pUnit, int nMissile, int nX, int nY)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nBaseId = GetBaseId(pUnit->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != 63)
    {
        return;
    }
    else
    {

        D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return;
        }

        int nOffsetX = 5;
        int nOffsetY = 5;
        D2SeedStrc tSeed;
        SEED_InitSeed(&tSeed);
        SEED_InitLowSeed(&tSeed, 'SEIS');
        tSeed.nHighSeed = pUnit->dwUnitId;

        for (int nCount = pMonStatsTxtRecord->wAiParam[2][sub_0044DCD0_GetDifficulty()]; nCount > 0; --nCount)
        {
            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX + nOffsetX, nY + nOffsetY, 0, 1);
        }
    }
}
