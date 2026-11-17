struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[4];
    int dwParam[4];
    char unk0x158[0xE4];
};
typedef char chk_D2SkillsTxt_size[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit);                                                            // 0x006455E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall sub_005A8000_ModeChangeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused); // 0x005A8000

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D8780
int __fastcall sub_005D8780_SrvDoStageRoll(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11019(pTarget))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, 0x76))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 0x76, 1);
    UNITROOM_RefreshUnit(pTarget);

    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) >= nChance)
    {
        return 0;
    }

    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
    int nStage = 1;
    int nLow = 0;
    int nHigh = 0;
    for (int i = 0; i < 4; ++i)
    {
        nHigh += pSkillsTxtRecord->dwParam[i];
        if (nRoll >= nLow && nRoll < nHigh)
        {
            nStage = i + 1;
        }
        nLow += pSkillsTxtRecord->dwParam[i];
    }

    sub_005A8000_ModeChangeTarget(pGame, pTarget, pUnit, nStage);
    return 1;
}
