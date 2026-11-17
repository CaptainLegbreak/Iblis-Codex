struct D2UnitStrc;
struct D2StatListStrc;
struct D2UnitEventStrc;
struct D2GameStrc { char unk00[0x1c]; void* pMemoryPool; };
struct D2SkillsTxt {
    int unk00; unsigned int dwFlags; char unk08[0x4c];
    short wAuraStat[6]; unsigned int dwAuraLenCalc; unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6]; short nAuraState; short unk82;
    short wAuraEvent[3]; short wAuraEventFunc[3]; char unk90[8];
    short wPassiveStat[5]; short unkA2; unsigned int dwPassiveCalc[5];
    char unkB8[0xc]; short wSumSkill[5]; short unkCE; unsigned int dwSumSkCalc[5];
    short wSumUMod; short wSumOverlay; char unkE8[0x50]; unsigned int dwCalc0;
    char unk13C[0x100];
};
struct D2ItemStatCostTxt { char unk00[0x48]; short wItemEvent[2]; short wItemEventFunc[2]; char unk50[0xf4]; };
struct D2DataTablesStrc {
    char unk000[0xc4]; int nStatesTxtRecordCount; char unk0C8[0xad0];
    D2SkillsTxt* pSkillsTxt; void* pSkillsLinker; int nSkillsTxtRecordCount;
    char unkBA4[0x1c]; int nOverlayTxtRecordCount; char unkBC4[8];
    D2ItemStatCostTxt* pItemStatCostTxt; void* pItemStatCostLinker; int nItemStatCostTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc*, D2UnitStrc*, int, int, int, int, int, int); // 0x0056E740
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*, D2UnitStrc*, int, int); // 0x005A4850
void __fastcall SUNITEVENT_Unregister(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C0B50
D2UnitEventStrc* __fastcall SUNITEVENT_GetEvent(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005C0BE0
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005D6B60
void __stdcall UNITS_SetOverlay(D2UnitStrc*, int, int); // 0x00621E40
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
inline D2ItemStatCostTxt* GetItemStatCost(int nStat) {
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}
static __forceinline int ApplyRatio(int nValue, int nMultiplier, int nDivisor) {
    if (!nDivisor) return 0;
    if (nValue > 0x100000) {
        if ((nValue & ~15) < nDivisor * 16) return (int)(nValue * (__int64)nMultiplier / nDivisor);
        return (nValue / nDivisor) * nMultiplier;
    }
    if (nMultiplier > 0x10000) {
        if ((nMultiplier & ~15) < nDivisor * 16) return (int)(nValue * (__int64)nMultiplier / nDivisor);
        return (nMultiplier / nDivisor) * nValue;
    }
    return nValue * nMultiplier / nDivisor;
}
#define MAXIMUM(a,b) ((a) > (b) ? (a) : (b))
// 0x005C4470
int __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel)
{
    D2SkillsTxt* pSkill = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId) return 0;
    for (int i = 0; i < 5; ++i) {
        if (pSkill->wPassiveStat[i] >= 0 && pSkill->wPassiveStat[i] < sgptDataTables->nItemStatCostTxtRecordCount) {
            int nStat = pSkill->wPassiveStat[i];
            D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
            if (pCost) {
                int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwPassiveCalc[i], nSkillId, nSkillLevel);
                STATLIST_AddUnitStat(pPet, nStat, nValue, 0);
                if (pCost->wItemEvent[0] > 0 && !SUNITEVENT_GetEvent(pGame, pPet, 2, sub_00451F50_GetUnitGUID(pPet), nStat)) {
                    sub_6FD156A0(pGame, pPet, pCost->wItemEvent[0], nStat << 16, 0, pCost->wItemEventFunc[0], 2, sub_00451F50_GetUnitGUID(pPet));
                    const short nSecondEvent = pCost->wItemEvent[1];
                    if (nSecondEvent > 0) sub_6FD156A0(pGame, pPet, nSecondEvent, nStat << 16, 0, pCost->wItemEventFunc[1], 2, sub_00451F50_GetUnitGUID(pPet));
                }
            }
        }
    }
    D2StatListStrc* pList = 0;
    for (int i = 0; i < 6; ++i) {
        if (pSkill->wAuraStat[i] >= 0 && pSkill->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount) {
            int nStat = pSkill->wAuraStat[i];
            D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
            if (pCost) {
                int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwAuraStatCalc[i], nSkillId, nSkillLevel);
                if (nValue) {
                    if (!pList) {
                        pList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, sub_0044BE50_GetUnitTypeOrInvalid(pPet), sub_00451F50_GetUnitGUID(pPet));
                        if (!pList) return 0;
                        D2COMMON_10475_PostStatToStatList(pPet, pList, 1);
                    }
                    STATLIST_SetStat(pList, nStat, nValue, 0);
                    if (pCost->wItemEvent[0] > 0 && !SUNITEVENT_GetEvent(pGame, pPet, 2, sub_00451F50_GetUnitGUID(pPet), nStat)) {
                        sub_6FD156A0(pGame, pPet, pCost->wItemEvent[0], nStat << 16, 0, pCost->wItemEventFunc[0], 2, sub_00451F50_GetUnitGUID(pPet));
                        const short nSecondEvent = pCost->wItemEvent[1];
                    if (nSecondEvent > 0) sub_6FD156A0(pGame, pPet, nSecondEvent, nStat << 16, 0, pCost->wItemEventFunc[1], 2, sub_00451F50_GetUnitGUID(pPet));
                    }
                }
            }
        }
    }
    if (pSkill->nAuraState > 0 && pSkill->nAuraState <= sgptDataTables->nStatesTxtRecordCount) {
        STATES_ToggleState(pPet, pSkill->nAuraState, 1);
        if (pList) STATLIST_SetState(pList, pSkill->nAuraState);
    }
    int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwCalc0, nSkillId, nSkillLevel);
    int nLife = STATLIST_GetMaxLifeFromUnit(pPet);
    nLife += ApplyRatio(nLife, nPercent, 100);
    STATLIST_SetUnitStat(pPet, 7, nLife, 0);
    STATLIST_SetUnitStat(pPet, 6, nLife, 0);
    for (int i = 0; i < 5; ++i) {
        if (pSkill->wSumSkill[i] > 0 && pSkill->wSumSkill[i] < sgptDataTables->nSkillsTxtRecordCount) {
            int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwSumSkCalc[i], nSkillId, nSkillLevel);
            if (nLevel > 0) {
                D2SkillsTxt* pSumSkill = SKILLS_GetSkillsTxtRecord(pSkill->wSumSkill[i]);
                if (pSumSkill) {
                    D2GAME_SetSkills_6FD14C60(pPet, pSkill->wSumSkill[i], nLevel, 0);
                    if ((unsigned char)pSumSkill->dwFlags & (unsigned char)gdwBitMasks[5]) D2GAME_AssignSkill_6FD13800(pPet, 0, pSkill->wSumSkill[i], -1);
                }
            }
        }
    }
    if (pSkill->wAuraEvent[0] >= 0) {
        SUNITEVENT_Unregister(pGame, pPet, 1, pSkill->nAuraState);
        for (int i = 0; i < 3 && pSkill->wAuraEvent[i] >= 0; ++i) {
            sub_6FD156A0(pGame, pPet, pSkill->wAuraEvent[i], nSkillId, nSkillLevel, pSkill->wAuraEventFunc[i], 1, pSkill->nAuraState);
        }
    }
    if (pSkill->wSumUMod > 0 && pSkill->wSumUMod < 43) D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, pSkill->wSumUMod, 1);
    if (pSkill->wSumOverlay > 0 && pSkill->wSumOverlay < sgptDataTables->nOverlayTxtRecordCount) UNITS_SetOverlay(pPet, pSkill->wSumOverlay, 0);
    int nLevel = nItemLevel;
    if (!nLevel) {
        int nOwnerLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
        nLevel = 3 * nSkillLevel;
        nLevel = MAXIMUM(nLevel, 1) < nOwnerLevel ? MAXIMUM(nLevel, 1) : nOwnerLevel;
    }
    SKILLS_EquipMonsterFromTable(pGame, pUnit, pPet, nSkillId, nSkillLevel, nLevel, 0);
    return 1;
}
