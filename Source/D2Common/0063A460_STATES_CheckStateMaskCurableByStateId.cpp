struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    unsigned int* pStateMasks;
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

#define STATEMASK_CURABLE 12
#define STATEMASK_EXP 30
#define STATEMASK_SHATTER 31

__forceinline int __fastcall STATES_CheckStateMaskByStateId(int nState, int nStateMask)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[nStateMask][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A460
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_CURABLE);
}

// 0x0063A6B0
int __stdcall STATES_CheckStateMaskExpByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_EXP);
}

// 0x0063A710
int __stdcall STATES_CheckStateMaskShatterByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_SHATTER);
}
