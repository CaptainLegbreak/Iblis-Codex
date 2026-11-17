struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x4];
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit);                           // 0x00625BB0

#define STATEMASK_AURA 1
#define STATEMASK_PGSV 4
#define STATEMASK_HIDE 2
#define STATEMASK_ACTIVE 5
#define STATEMASK_REMHIT 6
#define STATEMASK_DAMBLUE 7
#define STATEMASK_DAMRED 8
#define STATEMASK_ATTBLUE 9
#define STATEMASK_ATTRED 10
#define STATEMASK_ARMBLUE 19
#define STATEMASK_RFBLUE 20
#define STATEMASK_RCBLUE 21
#define STATEMASK_RLBLUE 22
#define STATEMASK_RPBLUE 23
#define STATEMASK_RFRED 26
#define STATEMASK_RCRED 27
#define STATEMASK_RLRED 28
#define STATEMASK_RPRED 29
#define STATEMASK_EXP 30
#define STATEMASK_SHATTER 31
#define STATEMASK_LIFE 32
#define STATEMASK_UDEAD 33
#define STATEMASK_GREEN 34

static __declspec(noinline) int sub_0063A130_CheckStateMaskOnUnit(D2UnitStrc* pUnit, const unsigned int* pStateMask)
{
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
    if (!pStatFlags)
    {
        return 0;
    }

    for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
    {
        if (pStatFlags[i] & pStateMask[i])
        {
            return 1;
        }
    }

    return 0;
}

// 0x0063A250
int __stdcall STATES_CheckStateMaskAuraOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_AURA]);
}

// 0x0063A2B0
int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}

// 0x0063A320
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_HIDE]);
}

// 0x0063A340
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ACTIVE]);
}

// 0x0063A360
int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_REMHIT]);
}

// 0x0063A380
int __stdcall sub_0063A380(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMBLUE]);
}

// 0x0063A3A0
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMRED]);
}

// 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTBLUE]);
}

// 0x0063A3E0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTRED]);
}

// 0x0063A550
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMBLUE]);
}

// 0x0063A570
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFBLUE]);
}

// 0x0063A590
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCBLUE]);
}

// 0x0063A5B0
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLBLUE]);
}

// 0x0063A5D0
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPBLUE]);
}

// 0x0063A610
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFRED]);
}

// 0x0063A630
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCRED]);
}

// 0x0063A650
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLRED]);
}

// 0x0063A670
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPRED]);
}

// 0x0063A690
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_EXP]);
}

// 0x0063A6F0
int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_SHATTER]);
}

// 0x0063A750
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_LIFE]);
}

// 0x0063A770
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_UDEAD]);
}

// 0x0063A790
int __stdcall STATES_CheckStateMaskGreenOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_GREEN]);
}

// 0x0063A7B0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask)
{
    if (pUnit && nStateMask >= 0 && nStateMask < 40)
    {
        return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[nStateMask]);
    }

    return 0;
}
