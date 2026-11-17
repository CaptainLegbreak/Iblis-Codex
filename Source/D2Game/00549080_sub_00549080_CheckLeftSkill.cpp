struct D2SkillStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

// 0x00549080
static __forceinline int sub_00549080_CheckLeftSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetLeftSkill(pUnit) ? 0 : 3;
}

// 0x005490A0
static __forceinline int sub_005490A0_CheckRightSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetRightSkill(pUnit) ? 0 : 3;
}

// 0x005490C0
static __forceinline int sub_005490C0_CheckName(const char* szName)
{
    if (!szName[0xFF])
    {
        return SStrChr(szName, -1) ? 2 : 0;
    }
    return 2;
}

// 0x00549290
static __forceinline int sub_00549290_CheckRange1To10(int nValue)
{
    return (unsigned int)(nValue - 1) > 9 ? 2 : 0;
}

// 0x005492A0
static __forceinline int sub_005492A0_CheckBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc) ? 0 : 1;
}

// 0x005494E0
static __forceinline int sub_005494E0_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }
    return SKILLS_GetSkillLevel(pUnit, pSkill, 1) ? 0 : 3;
}

int __stdcall sub_M114_Emit_00549080(D2UnitStrc* pUnit, const char* szName, int a, int b)
{
    return sub_00549080_CheckLeftSkill(pUnit) + sub_005490A0_CheckRightSkill(pUnit) + sub_005490C0_CheckName(szName)
        + sub_00549290_CheckRange1To10(a) + sub_005492A0_CheckBodyLocFree(pUnit, b) + sub_005494E0_CheckSkillLevel(pUnit, a, b);
}
