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

int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage);                          // 0x00644B70

// 0x00644C90
static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    int nPercentage = 0;

    switch (nElemType)
    {
    case 1:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 329, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 2:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 330, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 4:
    case 12:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 331, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 5:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 332, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    default:
        break;
    }

    return 0;
}

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
