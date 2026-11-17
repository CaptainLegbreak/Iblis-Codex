struct D2UnitStrc;
struct D2SkillsTxt
{
    char unk0x00[152];
    short nPassiveStat[5];
    char unk0xA2[164 - 152 - 2 * 5];
    unsigned int dwPassiveCalc[5];
    char unk0xB8[572 - 164 - 4 * 5];
};

struct D2DataTablesStrc
{
    char unk0x00[2968];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00647E00
int __stdcall D2Common_11032(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nType)
{
    unsigned short nThrowStatId = 0;
    unsigned short nMeleeStatId = 0;
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        switch (nType)
        {
        case 0:
            nMeleeStatId = 342;
            nThrowStatId = 345;
            break;
        case 1:
            nMeleeStatId = 343;
            nThrowStatId = 346;
            break;
        case 2:
            nMeleeStatId = 344;
            nThrowStatId = 347;
            break;
        default:
            return 0;
        }

        int i = 0;
        for (i = 0; i < 5; ++i)
        {
            if (pSkillsTxtRecord->nPassiveStat[i] == nMeleeStatId || pSkillsTxtRecord->nPassiveStat[i] == nThrowStatId)
            {
                break;
            }
        }

        if (i >= 5)
        {
            return 0;
        }

        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
    }
}
