struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x92];
    short nPassiveState;
    char unk0x96[0x1A6];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x20];
    int nSkillLevel;
    char unk0x2C[0x08];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    char unk0x0C[0x9C];
    D2SkillListStrc* pSkills;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId);                                        // 0x00646D60
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId);                                    // 0x00647110
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x00643690
__declspec(noinline) int __stdcall SKILLS_GetPassiveState(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (pSkillsTxtRecord->nPassiveState <= 0)
    {
        return 0;
    }
    return pSkillsTxtRecord->nPassiveState;
}

// 0x00646FD0
static void __stdcall sub_00646FD0_RemoveSkill(int nSkillId, int bDecrementAndCheckSkillLevel, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return;
    }

    D2SkillStrc* pSkill = pSkillList->pFirstSkill;
    if (!pSkill)
    {
        return;
    }

    if (const int nState = SKILLS_GetPassiveState(nSkillId))
    {
        STATES_ToggleState(pUnit, nState, 0);
    }

    if (const D2SkillStrc* pLeftSkill = pSkillList->pLeftSkill)
    {
        if (nSkillId == pLeftSkill->pSkillsTxt->nSkillId && pLeftSkill->nOwnerGUID == -1)
        {
            SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
        }
    }

    if (const D2SkillStrc* pRightSkill = pSkillList->pRightSkill)
    {
        if (nSkillId == pRightSkill->pSkillsTxt->nSkillId && pRightSkill->nOwnerGUID == -1)
        {
            SKILLS_SetRightActiveSkill(pUnit, 0, -1);
        }
    }

    if (const D2SkillStrc* pUsedSkill = pSkillList->pUsedSkill)
    {
        if (nSkillId == pUsedSkill->pSkillsTxt->nSkillId && pUsedSkill->nOwnerGUID == -1)
        {
            pSkillList->pUsedSkill = 0;
        }
    }

    D2SkillStrc* pPreviousSkill = 0;
    do
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == -1)
        {
            if (!bDecrementAndCheckSkillLevel || --pSkill->nSkillLevel <= 0)
            {
                if (pPreviousSkill)
                {
                    pPreviousSkill->pNextSkill = pSkill->pNextSkill;
                }
                else
                {
                    pSkillList->pFirstSkill = pSkill->pNextSkill;
                }

                FOG_FreePool(pUnit->pMemoryPool, pSkill, ".\\SKILLS\\Skills.cpp", 0x4AC, 0);
            }

            SKILLS_RefreshSkill(pUnit, nSkillId);
            return;
        }

        pPreviousSkill = pSkill;
        pSkill = pSkill->pNextSkill;
    }
    while (pSkill);

    SKILLS_RefreshSkill(pUnit, nSkillId);
}

// 0x006470F0
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine)
{
    sub_00646FD0_RemoveSkill(nSkillId, 1, pUnit);
}

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine)
{
    D2SkillStrc* pSkill = 0;
    if (nSkillLevel)
    {
        pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (!pSkill)
        {
            pSkill = SKILLS_AddSkill(pUnit, nSkillId);
        }

        if (pSkill)
        {
            pSkill->nSkillLevel = nSkillLevel;
        }

        SKILLS_RefreshSkill(pUnit, nSkillId);
    }
    else
    {
        if (bRemove)
        {
            sub_00646FD0_RemoveSkill(nSkillId, 0, pUnit);
            SKILLS_RefreshSkill(pUnit, nSkillId);
        }
        else
        {
            pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
            if (!pSkill)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
                pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
            }

            if (pSkill)
            {
                pSkill->nSkillLevel = 0;
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }
    }
}
