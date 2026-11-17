struct D2UnitStrc;
struct D2SkillStrc
{
    char unk0x00[40];
    int nSkillLevel;
};

struct D2SkillsTxt
{
    char unk0x00[12];
    signed char nCharClass;
    char unk0x0D[328 - 12 - 1];
    int dwParam[8];
    char unk0x168[372 - 328 - 32];
    short wReqLevel;
    char unk0x176[572 - 372 - 2];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    int* nClassSkillCount;
    int nHighestClassSkillCount;
    short* nClassSkillList;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00644710
int __stdcall SKILLS_GetRequiredLevel(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0x7FFFFFFF;
    }

    return pSkillsTxtRecord->wReqLevel;
}

// 0x00644750
int __stdcall SKILLS_GetRequiredLevelBasedOnCurrent(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0x7FFFFFFF;
    }

    int nRequiredLevel = pSkillsTxtRecord->wReqLevel;
    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
    if (pSkill)
    {
        nRequiredLevel += pSkill->nSkillLevel;
    }

    return nRequiredLevel;
}

// 0x00645040
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (pSkillsTxtRecord && pSkillsTxtRecord->nCharClass >= 0)
    {
        return pSkillsTxtRecord->nCharClass;
    }

    return 7;
}

// 0x00645B20
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax)
{
    int nValue = nParam + (nMax - nParam) * (110 * nLevel / (nLevel + 6)) / 100;

    if (nValue > nMax)
    {
        nValue = nMax;
    }

    return nValue;
}

// 0x00645B70
int __stdcall D2Common_11034(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[0], pSkillsTxtRecord->dwParam[1]);
}

// 0x00645BC0
int __stdcall D2Common_11035(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[2], pSkillsTxtRecord->dwParam[3]);
}

// 0x00645C10
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[4], pSkillsTxtRecord->dwParam[5]);
}

// 0x006460F0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition)
{
    if (nClassId >= 0 && nClassId < 7)
    {
        if (nPosition >= 0 && nPosition < sgptDataTables->nClassSkillCount[nClassId])
        {
            return sgptDataTables->nClassSkillList[nPosition + nClassId * sgptDataTables->nHighestClassSkillCount];
        }

        return -1;
    }

    return -1;
}

// 0x00646140
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId)
{
    if (nClassId >= 0 && nClassId < 7)
    {
        return sgptDataTables->nClassSkillCount[nClassId];
    }

    return 0;
}
