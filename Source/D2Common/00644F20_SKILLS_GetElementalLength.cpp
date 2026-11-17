typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

struct D2SkillsTxt
{
    char unk0x000[0x010];
    signed char nAnim;
    signed char nMonAnim;
    char unk0x012[0x214 - 0x012];
    int dwELen;
    int dwELevLen[3];
    unsigned int dwELenSymPerCalc;
    char unk0x228[0x23C - 0x228];
};

struct D2DataTablesStrc
{
    char unk0x000[0x040];
    char* pSkillsCode;
    unsigned int nSkillsCodeSize;
    char unk0x048[0xB98 - 0x048];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    int dwSkillMode;
    char unk0x0C[0x28 - 0x0C];
    int nSkillLevel;
    char unk0x2C[0x34 - 0x2C];
    int nOwnerGUID;
    char unk0x38[0x40 - 0x38];
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xA8 - 0x08];
    D2SkillListStrc* pSkills;
};

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern void* gpSkillsCalcFunctions[];                                                                       // 0x00745774
extern int gnSkillsCalcFunctions;                                                                           // 0x007457AC
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __fastcall sub_00646BE0(int nParamId, void* pUserData);                                  // 0x00646BE0
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0
int __stdcall SKILLS_GetPassiveState(int nSkillId);                                                         // 0x00643690
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId);                                        // 0x00646D60
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

__forceinline int SKILLS_EvaluateSkillFormulaInl(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillsCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillsCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillsCode[nCalc], sgptDataTables->nSkillsCodeSize - nCalc, sub_00646BE0, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00644F20
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    int nLevelLength = 0;

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    if (nSkillLevel > 16)
    {
        nLevelLength = (nSkillLevel - 16) * pSkillsTxtRecord->dwELevLen[2] + 8 * pSkillsTxtRecord->dwELevLen[1] + 7 * pSkillsTxtRecord->dwELevLen[0];
    }
    else if (nSkillLevel > 8)
    {
        nLevelLength = (nSkillLevel - 8) * pSkillsTxtRecord->dwELevLen[1] + 7 * pSkillsTxtRecord->dwELevLen[0];
    }
    else
    {
        nLevelLength = (nSkillLevel - 1) * pSkillsTxtRecord->dwELevLen[0];
    }

    int nLength = pSkillsTxtRecord->dwELen + nLevelLength;

    if (pSkillsTxtRecord->dwELenSymPerCalc != -1)
    {
        const int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwELenSymPerCalc, nSkillId, nSkillLevel);
        if (nBonus)
        {
            nLength += DATATBLS_ApplyRatio(nLength, nBonus, 100);
        }
    }

    return nLength;
}

// 0x00647110
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
    if (nPassiveState)
    {
        STATES_ToggleState(pUnit, nPassiveState, 1);
    }

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    while (pSkill && (pSkill->pSkillsTxt != pSkillsTxtRecord || pSkill->nOwnerGUID != -1))
    {
        pSkill = pSkill->pNextSkill;
    }

    if (!pSkill)
    {
        D2SkillListStrc* pSkillList = pUnit->pSkills;
        if (!pSkillList)
        {
            return 0;
        }

        pSkill = (D2SkillStrc*)sub_0040B430(pSkillList->pMemPool, sizeof(D2SkillStrc), ".\\SKILLS\\Skills.cpp", 1337, 0);
        memset(pSkill, 0x00, sizeof(D2SkillStrc));
        pSkill->pSkillsTxt = pSkillsTxtRecord;

        if (pUnit->dwUnitType == 1)
        {
            pSkill->dwSkillMode = pSkillsTxtRecord->nMonAnim;
        }
        else if (pUnit->dwUnitType == 0 && pUnit->dwClassId == 6 && nSkillId == 5)
        {
            pSkill->dwSkillMode = 16;
        }
        else
        {
            pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        }

        pSkill->nSkillLevel = 1;
        pSkill->nOwnerGUID = -1;
        pSkill->pNextSkill = 0;

        D2SkillStrc* pPreviousSkill = pSkillList->pFirstSkill;
        if (pPreviousSkill)
        {
            while (pPreviousSkill->pNextSkill)
            {
                pPreviousSkill = pPreviousSkill->pNextSkill;
            }
            pPreviousSkill->pNextSkill = pSkill;
        }
        else
        {
            pSkillList->pFirstSkill = pSkill;
        }

        SKILLS_RefreshSkill(pUnit, nSkillId);
        return pSkill;
    }

    const int nSkillLevel = pSkill->nSkillLevel;
    if (nSkillLevel < sub_004AA8B0_GetSkillMaxLevel(nSkillId) || pUnit->dwUnitType == 1)
    {
        pSkill->nSkillLevel = nSkillLevel + 1;
    }

    SKILLS_RefreshSkill(pUnit, nSkillId);
    return pSkill;
}
