struct D2StatListStrc;
struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[72 - 4];
    int dwFrameCountPrecise;
};

struct D2SkillsTxt
{
    char unk0x00[20];
    signed char nRange;
    char unk0x15[328 - 20 - 1];
    int dwParam[8];
    char unk0x168[392 - 328 - 32];
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    char unk0x18E[572 - 392 - 6];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
};

struct D2DataTablesStrc
{
    char unk0x00[380];
    short* pTransformStates;
    short nTransformStates;
    char unk0x182[2968 - 380 - 6];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit);                                                // 0x0064F460
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0062A710
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

#define SKILLS_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00645460
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    if (!pSkill->pSkillsTxt)
    {
        return 0;
    }

    int nRange = pSkill->pSkillsTxt->nRange;
    if (nRange != 3)
    {
        return nRange;
    }

    nRange = (COMPOSIT_IsWeaponBowOrXBow(pUnit) != 0) + 1;
    if (pUnit && pUnit->dwUnitType == 0 && nRange != 1 && STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return 1;
    }

    return nRange;
}

// 0x006459F0
int __stdcall sub_006459F0(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    SKILLS_ASSERT(pSkillsTxtRecord, 4108);

    int nMana = ((pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift) >> 8;
    if (nMana < 0)
    {
        nMana = 0;
    }

    return nMana;
}

// 0x00646020
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit)
{
    if (!STATES_IsUnitShapeShifted(pUnit))
    {
        return 0;
    }

    for (int i = 0; i < sgptDataTables->nTransformStates; ++i)
    {
        short nState = sgptDataTables->pTransformStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            STATES_ToggleState(pUnit, nState, 0);
        }
    }

    return 1;
}

// 0x006461D0
int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
    if (!STATES_CheckState(pUnit, 42))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 42);
    if (!pStatList)
    {
        return 0;
    }

    int nDamagePercent = STATLIST_GetStatValue(pStatList, 25, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    int nParam;
    if (!pSkillsTxtRecord)
    {
        nParam = 0;
    }
    else
    {
        nParam = pSkillsTxtRecord->dwParam[0];
    }

    return nDamagePercent * nParam / 8;
}
