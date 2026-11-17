struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[2];
    unsigned char nFlags[8];
    char unk0x0C[0x176 - 0x0C];
    short wReqStr;
    short wReqDex;
    short wReqInt;
    short wReqVit;
    char unk0x17E[0x23C - 0x17E];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x34 - 0x08];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xA8 - 0x14];
    D2SkillListStrc* pSkills;
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short wMonStatsEx;
    char unk0x1A[0x32 - 0x1A];
    short nVelocity;
    char unk0x34[0x1A8 - 0x34];
};

struct D2MonStats2Txt
{
    char unk0x00[0xF0];
    unsigned char nModeFlags[4];
    char unk0xF4[0x134 - 0xF4];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xA90 - 0xA84];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[4];
    int nMonStats2TxtRecordCount;
    char unk0xA9C[0xB98 - 0xA9C];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern const int gnShapeShiftedModeTable[];                                                                 // 0x006EB348
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit);                                              // 0x00620150
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
int __stdcall SKILLS_GetRequiredLevelBasedOnCurrent(D2UnitStrc* pUnit, int nSkillId);                       // 0x00644750

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_STRENGTH 0
#define STAT_ENERGY 1
#define STAT_DEXTERITY 2
#define STAT_VITALITY 3
#define STAT_LEVEL 12
#define SKILLSFLAGINDEX_INGAME 10
#define MONSTATS2FLAGINDEX_CORPSESEL 7
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define MONMODE_WALK 2
#define MONMODE_GETHIT 3
#define MONMODE_ATTACK1 4
#define MONMODE_ATTACK2 5
#define MONMODE_BLOCK 6
#define MONMODE_CAST 7
#define MONMODE_SKILL1 8
#define MONMODE_SKILL2 9
#define MONMODE_SKILL3 10
#define MONMODE_SKILL4 11
#define MONMODE_DEAD 12
#define MONMODE_RUN 15

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId_Inl
inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00643BC0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    D2_ASSERT(pSkillsTxtRecord, 0x668);

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    int bSkillFound = 0;
    if (pSkill)
    {
        while (pSkill)
        {
            if (bSkillFound)
            {
                break;
            }

            if (pSkill->pSkillsTxt == pSkillsTxtRecord && pSkill->nOwnerGUID == nOwnerGUID)
            {
                bSkillFound = 1;
            }
            else
            {
                pSkill = pSkill->pNextSkill;
            }
        }

        if (bSkillFound)
        {
            pUnit->pSkills->pLeftSkill = pSkill;
        }
    }
}

// 0x00643C50
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    D2_ASSERT(pSkillsTxtRecord, 0x67F);

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    int bSkillFound = 0;
    if (pSkill)
    {
        while (pSkill)
        {
            if (bSkillFound)
            {
                break;
            }

            if (pSkill->pSkillsTxt == pSkillsTxtRecord && pSkill->nOwnerGUID == nOwnerGUID)
            {
                bSkillFound = 1;
            }
            else
            {
                pSkill = pSkill->pNextSkill;
            }
        }

        if (bSkillFound)
        {
            pUnit->pSkills->pRightSkill = pSkill;
        }
    }
}

// 0x00644920
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INGAME >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INGAME & 7]))
    {
        return 0;
    }

    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nUnitLevel)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqStr > STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqDex > STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqInt > STATLIST_UnitGetStatValue(pUnit, STAT_ENERGY, 0))
    {
        return 0;
    }

    return pSkillsTxtRecord->wReqVit <= STATLIST_UnitGetStatValue(pUnit, STAT_VITALITY, 0);
}

// 0x00645190
int __stdcall D2Common_11014_ConvertShapeShiftedMode(int nArrayIndex, int nMonsterId)
{
    int nMode = gnShapeShiftedModeTable[nArrayIndex];

    while (1)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
        const unsigned int nModeFlag = pMonStats2TxtRecord ? (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7]) : 0;
        if (nModeFlag)
        {
            return nMode;
        }

        switch (nMode)
        {
        case MONMODE_NEUTRAL:
            return nMode;
        case MONMODE_RUN:
            nMode = MONMODE_WALK;
            continue;
        case MONMODE_SKILL2:
        case MONMODE_SKILL3:
        case MONMODE_SKILL4:
            nMode = MONMODE_SKILL1;
            continue;
        case MONMODE_ATTACK2:
        case MONMODE_CAST:
            nMode = MONMODE_ATTACK1;
            continue;
        case MONMODE_BLOCK:
            nMode = MONMODE_GETHIT;
            continue;
        default:
            nMode = MONMODE_NEUTRAL;
            continue;
        }
    }
}

// 0x00645510
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2)
{
    int nClassId;
    int bCorpseSelectable = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && (pUnit->dwAnimMode == MONMODE_DEAD || a2 && pUnit->dwAnimMode == MONMODE_DEATH) && !STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        nClassId = pUnit->dwClassId;
        bCorpseSelectable = sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_CORPSESEL);
    }

    if (!bCorpseSelectable)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    return pMonStatsTxtRecord->nVelocity != 0;
}

// 0x006455E0
int __stdcall sub_006455E0_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

// 0x00645680
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

#include "gen/data/Source/D2Common/00643BC0_SKILLS_SetLeftActiveSkill.inc"
