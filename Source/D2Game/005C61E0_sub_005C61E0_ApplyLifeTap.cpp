#define D2_MAX(a, b) ((a) < (b) ? (b) : (a))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2GameStrc;
struct D2StatListStrc;
struct D2UnitStrc { int dwUnitType; };
struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
};
struct D2SkillsTxt
{
    char unk0x000[0x82];
    short wAuraTargetState;
    char unk0x084[0x88];
    short wSrvOverlay;
    char unk0x10E[0x2A];
    unsigned int dwCalc[4];
};
struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAF8];
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall sub_006252B0(D2StatListStrc* pStatList); // 0x006252B0
int __stdcall sub_00625250(D2StatListStrc* pStatList); // 0x00625250
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

// 0x005C61E0
int __fastcall sub_005C61E0_ApplyLifeTap(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }
    if (pAttacker->dwUnitType != 0 && pAttacker->dwUnitType != 1)
    {
        return 0;
    }
    if ((pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1) || SUNIT_IsDead(pUnit) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (nSkillLevel < 0)
    {
        nLevel = 1;
    }
    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || !STATES_CheckState(pAttacker, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        return 0;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, sub_00625250(pStatList), sub_006252B0(pStatList));
    const int nPercent = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    const int nLifeGain = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nLife <= 0 || nMaxLife <= 0)
    {
        return 0;
    }
    nLife += nLifeGain;
    nLife = D2_MIN(D2_MAX(nLife, 1), nMaxLife);
    STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wSrvOverlay, 0);
    }
    return 1;
}
