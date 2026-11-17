struct D2DataTablesStrc
{
    char unk0x00[2688];
    int nMonStatsTxtRecordCount;
};
struct D2SkillStrc;
struct D2SkillListStrc;
struct D2PlayerDataStrc;
struct D2StatListStrc
{
    char unk0x00[16];
    unsigned int dwFlags;
    char unk0x14[8];
    D2SkillStrc* pSkill;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[12];
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[68];
    D2StatListStrc* pStatListEx;
    char unk0x60[72];
    D2SkillListStrc* pSkills;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __fastcall SKILLS_SetUsedSkillInSkillList(D2SkillListStrc* pSkillList, D2SkillStrc* pUsedSkill);       // 0x00643990
extern struct D2DataTablesStrc* sgptDataTables;                                                             // 0x00744304

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define PCLASS_BARBARIAN 4
#define PCLASS_ASSASSIN 6
#define MONSTER_SHADOWWARRIOR 0x1A1
#define MONSTER_SHADOWMASTER 0x1A2
#define STAT_HITPOINTS 6
#define STAT_LEVEL 0x0C
#define TRUE 1
#define FALSE 0

// 0x00620210
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill)
{
    D2_ASSERT(pUnit, 1619);
    SKILLS_SetUsedSkillInSkillList(pUnit->pSkills, pUsedSkill);
}

// 0x00621F20
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit)
{
    const int nHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    if (const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8)
    {
        return (100 * nHp) / nMaxHp;
    }

    return 0;
}

// 0x006221A0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4020);

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4022);

    return pUnit->pPlayerData;
}

// 0x00622E70
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit)
{
    return 10000 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
}

// 0x006235A0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nClassId)
        {
        case PCLASS_BARBARIAN:
        case PCLASS_ASSASSIN:
            return TRUE;
        }
        return FALSE;

    case UNIT_MONSTER:
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nClassId)
            {
            case MONSTER_SHADOWWARRIOR:
            case MONSTER_SHADOWMASTER:
                return TRUE;
            }
        }
        return FALSE;
    }

    return FALSE;
}
