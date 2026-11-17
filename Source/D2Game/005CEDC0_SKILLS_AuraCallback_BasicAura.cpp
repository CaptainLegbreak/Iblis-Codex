struct D2GameStrc;
struct D2UnitStrc;
struct D2StatListStrc;
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);
struct D2CurseStrc {
    D2UnitStrc* pUnit; D2UnitStrc* pTarget;
    int nSkill, nSkillLevel, nDuration, nStat, nStatValue, nState;
    StatListRemoveCallback pStateRemoveCallback;
};
struct D2BasicAuraParamStrc {
    int nAuraState, nSkillId, nSkillLevel, nDuration;
    int nAuraStat[6], nAuraStatCalcValue[6];
    int field_40; D2StatListStrc* pStatList;
    int nPassiveState; StatListRemoveCallback pStateRemoveCallback;
};
struct D2AuraCallbackStrc { D2GameStrc* pGame; D2UnitStrc* pOwner; int nCounter; D2BasicAuraParamStrc* pArgs; };
struct D2ItemStatCostTxt { unsigned short wStatId, pad2; unsigned char nItemStatFlags[4]; char pad8[0x2A]; unsigned short wMaxStat; };
struct D2DataTablesStrc { char pad0[0xBD4]; int nItemStatCostTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005CEC50
int __stdcall sub_005CEC90_ShortenPoisonAndCurses(D2GameStrc* pGame, D2UnitStrc* pUnit, int nPercent); // 0x005CEC90
int __fastcall sub_6FD0B3D0(D2UnitStrc* pUnit, int nStatId, int nResist); // 0x005C3540
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
// 0x005CEDC0
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2CurseStrc curse = {};
    D2BasicAuraParamStrc* pArgs = pAuraCallback->pArgs;
    curse.pTarget = pUnit;
    curse.pUnit = pAuraCallback->pOwner;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = -1;
    curse.nStatValue = 0;
    curse.nState = pArgs->nAuraState;
    if (pArgs->pStateRemoveCallback)
        curse.pStateRemoveCallback = pArgs->pStateRemoveCallback;
    else if (pAuraCallback->pOwner == pUnit)
        curse.pStateRemoveCallback = SKILLS_CurseStateCallback_BasicAura;
    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList) return 0;
    pArgs->pStatList = pStatList;
    int* pAuraStat = pArgs->nAuraStat;
    for (int i = 0; i < 6; ++i, ++pAuraStat)
    {
        if (!pAuraStat[6]) continue;
        int nStat = *pAuraStat;
        if (nStat <= 0 || nStat >= sgptDataTables->nItemStatCostTxtRecordCount) continue;
        if (nStat == 110)
        {
            if (sub_005CEC90_ShortenPoisonAndCurses(pAuraCallback->pGame, pUnit, pAuraStat[6]))
                ++pArgs->field_40;
            continue;
        }
        int nValue = sub_6FD0B3D0(pUnit, nStat, pAuraStat[6]);
        if (!nValue) continue;
        D2ItemStatCostTxt* pRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStat);
        if (!pRecord) continue;
        if (!(pRecord->nItemStatFlags[0] & gdwBitMasks[4]))
        {
            if (STATLIST_GetStatValue(pStatList, nStat, 0) != nValue)
                STATES_ToggleGfxStateFlag(pUnit, curse.nState, 1);
            switch (nStat)
            {
            case 67:
            case 68:
            {
                int nColdEffect = SUNITDMG_GetColdEffect(SUNIT_GetGameFromUnit(pUnit), pUnit);
                if (nValue < nColdEffect) nValue = nColdEffect;
                break;
            }
            }
            STATLIST_SetStat(pStatList, nStat, nValue, 0);
            if (nStat == 68) STATLIST_SetStat(pStatList, 69, nValue, 0);
            ++pArgs->field_40;
        }
        else
        {
            int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            nValue += nOldValue;
            int nMaxStat = pRecord->wMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                int nMax = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nValue >= nMax) nValue = nMax;
            }
            if (nValue != nOldValue)
            {
                STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
                ++pArgs->field_40;
            }
        }
    }
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\SkilPal.cpp", 413);
    STATLIST_SetStat(pStatList, 350, pArgs->nSkillId, 0);
    STATLIST_SetStat(pStatList, 351, pArgs->nSkillLevel, 0);
    if (pArgs->nPassiveState > 0)
    {
        D2StatListStrc* pPassive = STATLIST_GetStatListFromUnitAndState(pUnit, pArgs->nPassiveState);
        if (pPassive)
        {
            D2Common_10474(pUnit, pPassive);
            STATLIST_FreeStatList(pPassive);
            STATES_ToggleGfxStateFlag(pUnit, pArgs->nPassiveState, 1);
        }
    }
    return 1;
}
