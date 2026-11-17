struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2SkillStrc;
struct D2SkillsTxt { unsigned char unk_00[7]; unsigned char nFlags; };
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* unit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* unit); // 0x006201D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* skill, const char* file, int line); // 0x00643CE0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int id); // 0x0045C4B0
int __fastcall sub_00479150_FindRosterIndex(int unitId); // 0x00479150
extern const unsigned char gnSkillMask_006CE26C; // 0x006CE26C

static inline int sub_00464EC0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_00464EC0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00464EC0
int __fastcall sub_00464EC0_CheckSkillOwner(D2UnitStrc* unit, D2UnitStrc* target)
{
    int enabled = 0;
    if (unit && target && (sub_00464EC0_GetUnitType(unit) == 0 || target->dwUnitType == 1))
    {
        D2SkillStrc* skill = UNITS_GetLeftSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB4A));
            if (record && (record->nFlags & gnSkillMask_006CE26C))
                enabled = 1;
        }
        skill = UNITS_GetRightSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB55));
            if (record && (record->nFlags & gnSkillMask_006CE26C))
                enabled = 1;
        }
        if (enabled)
        {
            const int nRosterId = sub_00479150_FindRosterIndex(target->dwUnitId);
            return nRosterId == sub_00464EC0_GetUnitId(unit);
        }
    }
    return 0;
}
