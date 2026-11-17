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
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x9C];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[2];
    char unk0x140[0xFC];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

enum D2C_J10SkillMonstConstants
{
    STAT_HITPOINTS = 6,
    UNITFLAG_SKSRVDOFUNC = 0x00000040,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005CC840
int __fastcall SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nMaxRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nMax = D2_MIN(D2_MAX(nMaxRaw, 0), 100);

    const int nMinRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMin = D2_MIN(D2_MAX(nMinRaw, 0), nMax);

    const int nPercentage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin) + nMin;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget);
    int nNewHp = DATATBLS_ApplyRatio(nMaxHp, nPercentage, 100) + STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    nNewHp = D2_MIN(D2_MAX(nNewHp, 1), nMaxHp);
    STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
    return 1;
}
