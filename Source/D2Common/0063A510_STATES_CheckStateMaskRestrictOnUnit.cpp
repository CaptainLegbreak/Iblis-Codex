struct D2UnitStrc;
struct D2SkillStrc;

#define STATEMASK_RESTRICT 17
#define STATEMASK_ARMRED 25

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x4];
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit);                           // 0x00625BB0

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

// 0x0063A510
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RESTRICT]);
}

// 0x0063A5F0
int __stdcall STATES_CheckStateMaskArmRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMRED]);
}
