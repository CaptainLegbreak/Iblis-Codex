struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x5E];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    char unk0x080[0x24];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x08];
    unsigned int dwPetMax;
    char unk0x0C4[0x74];
    unsigned int dwCalc[4];
    int dwParam[8];
    char unk0x168[0x08];
    unsigned int dwSkPoints;
    char unk0x174[0x14];
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[0x23C - 0x18E];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[40 - 4 - 4];
    int nSkillLevel;
    char unk0x2C[52 - 40 - 4];
    int nOwnerGUID;
    char unk0x38[60 - 52 - 4];
    int bExcludeFromHighestLevelLookup;
};

struct D2SkillListStrc
{
    char unk0x00[4];
    D2SkillStrc* pFirstSkill;
};

struct D2UnitStrc
{
    char unk0x00[168];
    D2SkillListStrc* pSkills;
};

struct D2SkillDescTxt
{
    char unk0x00[0x3C];
    short wDescMissile[3];
};

struct D2MissilesTxt
{
    char unk0x000[0x96];
    short wRange;
    short wLevRange;
};

struct D2DataTablesStrc
{
    char unk0x000[0x40];
    char* pSkillsCode;
    unsigned int nSkillsCodeSize;
    char unk0x048[0xB98 - 0x48];
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

int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                            // 0x004E6CA0
int __stdcall D2Common_11034(int nSkillLevel, int nSkillId);                                                // 0x00645B70
int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel);                                 // 0x004CC7C0
int __stdcall D2Common_11035(int nSkillLevel, int nSkillId);                                                // 0x00645BC0
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel);                                  // 0x004EFCB0
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId);                    // 0x00645C10
int __fastcall sub_00643580_GetSkillParam7Formula(int nSkillId, int nSkillLevel);                           // 0x00643580
int __stdcall D2Common_11033(int nLevel, int nParam1, int nParam2);                                         // 0x00645B20
int __fastcall sub_004C9460_GetSkillParam1(int nSkillId);                                                   // 0x004C9460
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId);                                                   // 0x004EFC20
int __fastcall sub_004EFC50_GetSkillParam3(int nSkillId);                                                   // 0x004EFC50
int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId);                                                   // 0x004EFC80
int __fastcall sub_004E6C70(int nSkillId);                                                   // 0x004E6C70
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId);                                                   // 0x004F4110
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);          // 0x00644F20
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall D2Common_11032(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nType);                  // 0x00647E00
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                           // 0x0046ACE0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0
int __fastcall sub_00646BE0(int nParamId, void* pUserData);                                  // 0x00646BE0

// 0x00643810
static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    D2SkillStrc* pHighestLevelSkill = 0;
    for (; pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && !pSkill->bExcludeFromHighestLevelLookup && (!pHighestLevelSkill
            || pSkill->nOwnerGUID == -1 || pHighestLevelSkill->nOwnerGUID != -1 && pSkill->nSkillLevel > pHighestLevelSkill->nSkillLevel))
        {
            pHighestLevelSkill = pSkill;
        }
    }

    return pHighestLevelSkill;
}

// build: context DATATBLS_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// build: context SKILLS_EvaluateSkillFormula
static __forceinline int SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
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

// 0x00646460
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    int nIndex;
    int nMissileId;
    int nResult;
    const int nParam = (unsigned char)nParamId;
    switch (nParam)
    {
    case 0:
        nResult = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
        break;
    case 1:
        nResult = D2Common_11034(nSkillLevel, nSkillId);
        break;
    case 2:
        nResult = sub_004CC7C0_GetSkillMissileRange(nSkillId, nSkillLevel);
        break;
    case 3:
        nResult = D2Common_11035(nSkillLevel, nSkillId);
        break;
    case 4:
        nResult = sub_004EFCB0_GetSummonLevel(nSkillId, nSkillLevel);
        break;
    case 5:
        nResult = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nSkillId);
        break;
    case 6:
        nResult = sub_00643580_GetSkillParam7Formula(nSkillId, nSkillLevel);
        break;
    case 7:
        nResult = D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[6], pSkillsTxtRecord->dwParam[7]);
        break;
    case 8:
        nResult = sub_004C9460_GetSkillParam1(nSkillId);
        break;
    case 9:
        nResult = sub_004EFC20_GetSkillParam2(nSkillId);
        break;
    case 10:
        nResult = sub_004EFC50_GetSkillParam3(nSkillId);
        break;
    case 11:
        nResult = sub_004EFC80_FourthSkillParam(nSkillId);
        break;
    case 12:
        nResult = sub_004E6C70(nSkillId);
        break;
    case 13:
        nResult = sub_004F4110_GetSkillParam5(nSkillId);
        break;
    case 14:
        nResult = pSkillsTxtRecord->dwParam[6];
        break;
    case 15:
        nResult = pSkillsTxtRecord->dwParam[7];
        break;
    case 16:
        nResult = nSkillLevel;
        break;
    case 17:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 18:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 19:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 20:
        nResult = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
        break;
    case 21:
        if (nSkillLevel > 0)
        {
            nResult = ((pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 22:
        if (nSkillLevel > 0)
        {
            nResult = ((25 * (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) / 2) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 23:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 24:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 25:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 2);
        break;
    case 26:
    case 29:
    case 32:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 26) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 27:
    case 30:
    case 33:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 27) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 28:
    case 31:
    case 34:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 28) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = sub_0064B2A0_GetMissileElementLength(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 35:
    case 36:
    case 37:
    {
        pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        if (pSkillDescTxtRecord)
        {
            D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pSkillDescTxtRecord->wDescMissile[nParam - 35]);
            if (pMissilesTxtRecord)
            {
                nResult = pMissilesTxtRecord->wRange + nSkillLevel * pMissilesTxtRecord->wLevRange;
                break;
            }
        }
        nResult = 0;
        break;
    }
    case 38:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 39:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 40:
        if (pUnit)
        {
            nResult = STATLIST_UnitGetStatValue(pUnit, 12, 0);
            break;
        }
        nResult = 0;
        break;
    case 41:
        if (pUnit)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
            if (pSkill)
            {
                nResult = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                break;
            }
        }
        nResult = 0;
        break;
    case 42:
        if (nSkillLevel > 0)
        {
            nResult = (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
            break;
        }
        nResult = 0;
        break;
    case 43:
    case 45:
    case 47:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 43) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 44:
    case 46:
    case 48:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 44) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 49:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 50:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 51:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 52:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 53:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 54:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        break;
    case 55:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        break;
    case 56:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        break;
    case 57:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        break;
    case 58:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        break;
    case 59:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        break;
    case 60:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);
        break;
    case 61:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
        break;
    case 62:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[2], nSkillId, nSkillLevel);
        break;
    case 63:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[3], nSkillId, nSkillLevel);
        break;
    case 64:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[4], nSkillId, nSkillLevel);
        break;
    case 65:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[5], nSkillId, nSkillLevel);
        break;
    case 66:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[0], nSkillId, nSkillLevel);
        break;
    case 67:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
        break;
    case 68:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[2], nSkillId, nSkillLevel);
        break;
    case 69:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[3], nSkillId, nSkillLevel);
        break;
    case 70:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[4], nSkillId, nSkillLevel);
        break;
    case 71:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
        break;
    case 72:
        nResult = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        break;
    default:
        nResult = 0;
        break;
    }

    return nResult;
}
