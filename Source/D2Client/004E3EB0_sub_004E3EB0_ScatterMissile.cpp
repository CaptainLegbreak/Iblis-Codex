struct D2SkillStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

struct D2SkillsTxt
{
    char unk0x000[0x0C];
    char nCharClass;
    char unk0x00D[0x09];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    char unk0x0EC[0x22];
    short wPrgSound;
    short wCltOverlayA;
    char unk0x112[0x02];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2MissilesTxt;

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E3EB0
int __fastcall sub_004E3EB0_ScatterMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nFrequency = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nFrequency <= 0)
    {
        return 0;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nSpread <= 0)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nRange <= 0)
    {
        return 0;
    }

    const int nCounter = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, nCounter + 1);
    if (!(nCounter % nFrequency))
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (!pSeed)
        {
            return 0;
        }

        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nX += CLIENTS_GetUnitX(pUnit);
        int nY = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nY += CLIENTS_GetUnitY(pUnit);
        sub_004CDC30(pUnit, nMissile, 0, 0, nX, nY, nSkillId, nSkillLevel, SEED_RollLimitedRandomNumber(pSeed, nRange));
    }

    return 1;
}
