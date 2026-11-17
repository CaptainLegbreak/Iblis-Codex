struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
    char unk0xC8[0x8];
    int dwNodeIndex;
};

struct D2SkillsTxt
{
    char unk0x000[0x54];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    char unk0x082[0x16];
    short wPassiveStat[5];
    char unk0x0A2[0x2];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x6];
    unsigned char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x20];
    short wSumUMod;
    char unk0x0E6[0x62];
    int dwParam;
    char unk0x14C[0xF0];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
    char unk0xBD8[0x18];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D6CF0
static void __stdcall sub_005D6CF0_SetSummonStats(D2GameStrc* pGame, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2UnitStrc* pPet)
{
    if (nSkillLevel <= 1)
    {
        return;
    }

    D2SkillsTxt* pSkillsRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pSkillsRecord ? 0 : pSkillsRecord->dwParam;
    int nHp = STATLIST_GetMaxLifeFromUnit(pPet);
    nHp += DATATBLS_ApplyRatio(nHp, (nSkillLevel - 1) * nParam, 100);
    STATLIST_SetUnitStat(pPet, 7, nHp, 0);
    STATLIST_SetUnitStat(pPet, 6, nHp, 0);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pPet ? 6 : pPet->dwUnitType, !pPet ? -1 : pPet->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pPet, pStatList, 1);

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->wPassiveStat[i] >= 0 && pSkillsTxtRecord->wPassiveStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->wPassiveStat[i], nValue, 0);
        }
    }

    if (pSkillsTxtRecord->wSumUMod > 0 && pSkillsTxtRecord->wSumUMod < 43)
    {
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, pSkillsTxtRecord->wSumUMod, 1);
    }
}

D2UnitStrc* __fastcall sub_M98_Emit_005D6CF0(D2GameStrc* pGame, D2UnitStrc* pPet, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, int nExtra)
{
    sub_005D6CF0_SetSummonStats(pGame, pSkillsTxtRecord, nSkillId, nSkillLevel + nExtra, pPet);
    return pPet;
}
