struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MonStatsTxt
{
    char unk0x000[0xA8];
    short wSkillDamage;
    char unk0x0AA[0xFE];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x11C];
    int nSkillsTxtRecordCount;
};

struct D2MonSkillInfoStrc
{
    int nMinDamage;
    int nMaxDamage;
    int nToHit;
};

#define UNIT_MONSTER 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId);                             // 0x00644AA0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0056E000
static void __stdcall sub_0056E000_FillMonSkillInfo(D2UnitStrc* pOwner, int nSkillId, D2MonSkillInfoStrc* pMonSkillInfo)
{
    const int nSkillLevel = SKILLS_GetHighestSkillLevelById(pOwner, nSkillId);
    pMonSkillInfo->nMinDamage = SKILLS_GetMinPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nMaxDamage = SKILLS_GetMaxPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nToHit = SKILLS_GetToHitFactor(pOwner, nSkillId, nSkillLevel);
}

// 0x0056E050
void __fastcall sub_6FD14D20(D2UnitStrc* pUnit, int nUnused, D2MonSkillInfoStrc* pMonSkillInfo)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSkillDamage > 0 && pMonStatsTxtRecord->wSkillDamage <= sgptDataTables->nSkillsTxtRecordCount)
            {
                sub_0056E000_FillMonSkillInfo(pOwner, pMonStatsTxtRecord->wSkillDamage, pMonSkillInfo);
            }
        }
    }
}
