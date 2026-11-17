struct D2UnitStrc;

struct D2SkillsTxt
{
    char unk0x000[0x80];
    short nAuraState;
    char unk0x082[0x8E];
    short wCltOverlayA;
    short wCltOverlayB;
    char unk0x114[0x128];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F1640
int __fastcall sub_004F1640_AuraStateOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltOverlayA < 0 || pSkillsTxtRecord->wCltOverlayA >= sgptDataTables->nOverlayTxtRecordCount)
    {
        return 0;
    }

    int nOverlay = pSkillsTxtRecord->wCltOverlayA;
    if (pSkillsTxtRecord->wCltOverlayB >= 0 && pSkillsTxtRecord->wCltOverlayB < sgptDataTables->nOverlayTxtRecordCount
        && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        nOverlay = pSkillsTxtRecord->wCltOverlayB;
    }

    sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    return 1;
}
