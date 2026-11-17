struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    short nNextInClass;
    char unk0x006[0x1A2];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
};

struct D2TimerArg2Strc
{
    int nUnitGUID;
    D2TimerArg2Strc* pNext;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    unsigned int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x0054DA60
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return -1;
    }

    int nClassId = pMonStatsTxtRecord->nBaseId;
    for (int i = 0; i < nNoInChain; ++i)
    {
        nClassId = pMonStatsTxtRecord->nNextInClass;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            break;
        }
    }

    return nClassId;
}

// 0x0054F520
D2TimerArgStrc* __fastcall sub_0054F520_AllocTimerArg(D2GameStrc* pGame)
{
    D2TimerArgStrc* pTimerArg = (D2TimerArgStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArgStrc), ".\\OBJECTS\\Objects.cpp", 0x1B8, 0);
    memset(pTimerArg, 0, sizeof(D2TimerArgStrc));
    pTimerArg->dwUnitId = -1;

    D2TimerArg2Strc* pArg = (D2TimerArg2Strc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArg2Strc), ".\\OBJECTS\\Objects.cpp", 0x1BC, 0);
    pArg->nUnitGUID = -1;
    pArg->pNext = 0;
    pTimerArg->unk0x00 = pArg;
    return pTimerArg;
}
