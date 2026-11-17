struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    unsigned int* pStateMasks;
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STATEMASK_PLRSTAYDEATH 13
#define STATEMASK_MONSTAYDEATH 14

// 0x0063A4A0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nUnitType == UNIT_MONSTER)
        {
            return sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
        else
        {
            return sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}
