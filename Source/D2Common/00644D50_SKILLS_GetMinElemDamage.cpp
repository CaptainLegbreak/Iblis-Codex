struct D2UnitStrc;
struct D2SkillsTxt
{
    char unk0x00[408];
    int dwToHit;
    int dwLevToHit;
    unsigned int dwToHitCalc;
    unsigned char nToHitShift;
    char unk0x1A5[476 - 420 - 1];
    unsigned char nEType;
    char unk0x1DD[3];
    int dwEMin;
    int dwEMax;
    int dwEMinLev[5];
    int dwEMaxLev[5];
    unsigned int dwEDmgSymPerCalc;
    int dwELen;
    int dwELevLen[3];
    unsigned int dwELenSymPerCalc;
    char unk0x228[572 - 532 - 20];
};

struct D2DataTablesStrc
{
    char unk0x00[64];
    char* pSkillsCode;
    unsigned int nSkillsCodeSize;
    char unk0x48[2968 - 64 - 8];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
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
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

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

// @ref 0x00646CA0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
}

// @ref 0x006449F0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
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
        unsigned int nCalc = pSkillsTxtRecord->dwToHitCalc;
        if (nCalc != -1)
        {
            return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
        }

        return pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit;
    }
}

// @ref 0x00644B70
// 0x00644B70
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
    if (nLevel > 1 && pLevelDamage)
    {
        if (nLevel > 28)
        {
            return 7 * *pLevelDamage + pLevelDamage[4] * (nLevel - 28) + 6 * (pLevelDamage[2] + pLevelDamage[3]) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 22)
        {
            return 7 * *pLevelDamage + pLevelDamage[3] * (nLevel - 22) + 6 * pLevelDamage[2] + 8 * pLevelDamage[1];
        }
        else if (nLevel > 16)
        {
            return 7 * *pLevelDamage + pLevelDamage[2] * (nLevel - 16) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 8)
        {
            return 7 * *pLevelDamage + pLevelDamage[1] * (nLevel - 8);
        }
        else
        {
            return *pLevelDamage * (nLevel - 1);
        }
    }

    return 0;
}

inline int SKILLS_ApplyMasteryInl(D2UnitStrc* pUnit, int nStatId, int nSrcDamage)
{
    int nPercentage = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
    if (!nPercentage)
    {
        return 0;
    }

    return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
}

static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage); // 0x00644C90
// @ref 0x00644C90

// build: context SKILLS_CalculateMasteryBonus
static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{

    switch (nElemType)
    {
    case 1:
        return SKILLS_ApplyMasteryInl(pUnit, 329, nSrcDamage);
    case 2:
        return SKILLS_ApplyMasteryInl(pUnit, 330, nSrcDamage);
    case 4:
    case 12:
        return SKILLS_ApplyMasteryInl(pUnit, 331, nSrcDamage);
    case 5:
        return SKILLS_ApplyMasteryInl(pUnit, 332, nSrcDamage);
    }

    return 0;
}

// 0x00644D50
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
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
        int nDamage = (pSkillsTxtRecord->dwEMin + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMinLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1 && (nDamage > 256 || pSkillsTxtRecord->dwEMinLev[0]))
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (a4 && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}

// 0x00644E40
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
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
        int nDamage = (pSkillsTxtRecord->dwEMax + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMaxLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1)
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (a4 && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}
