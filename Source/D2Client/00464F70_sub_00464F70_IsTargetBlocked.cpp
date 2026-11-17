struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x23C - 0x0C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150
int __fastcall sub_0047A520(int nUnitId1, int nUnitId2);                                                    // 0x0047A520

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

static __forceinline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int SKILLCLT_HasFlag26(D2SkillStrc* pSkill, int nLine)
{
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\CUnit.cpp", nLine));
        if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00464F70
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int bLeft = 0;
    if (pUnit && pTarget)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
        if (!nUnitType || !pTarget->dwUnitType || pTarget->dwUnitType == 1)
        {
            D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
            if (pLeftSkill)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\CUnit.cpp", 2943));
                if (pSkillsTxtRecord && BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26))
                {
                    bLeft = 1;
                }
            }
            if (SKILLCLT_HasFlag26(UNITS_GetRightSkill(pUnit), 2952) || bLeft)
            {
                int nTargetId = pTarget->dwUnitId;
                if (pTarget->dwUnitType != 1 || (nTargetId = sub_00479150_FindRosterIndex(nTargetId)) != -1)
                {
                    return sub_0047A520(pUnit->dwUnitId, nTargetId) != 0;
                }
            }
        }
    }
    return 0;
}
