struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0x04];
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __stdcall sub_0063A180_UpdateGfxFlagsWithMask(D2UnitStrc* pUnit, unsigned int* pMask);                // 0x0063A180

#define STATEMASK_PGSV 4

// 0x0063A2D0
void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc* pUnit)
{
    sub_0063A180_UpdateGfxFlagsWithMask(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}
