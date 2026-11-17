struct D2StatListStrc;
struct D2SkillListStrc;
struct D2SkillStrc;
struct D2UnitFindDataStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x98];
    D2SkillListStrc* pSkills;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2MissileStrc
{
    char unk0x00[0x1C];
    int nTargetX;
    int nTargetY;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x04[0x2E];
    short nVelocity;
    char unk0x34[0x174];
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    char unk0x41[0x83];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x140];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnSignX_006E1510[4];                                                                       // 0x006E1510
extern const int gnSignY_006E14E4[4];                                                                       // 0x006E14E4
extern const int gnOffset1_006E14F4[7];                                                                     // 0x006E14F4
extern const int gnOffset2_006E14C8[7];                                                                     // 0x006E14C8
extern const int gnXOffsets_006E14A8[8];                                                                    // 0x006E14A8
extern const int gnYOffsets_006E1488[8];                                                                    // 0x006E1488
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit);                                              // 0x00646F20
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575900
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetPassiveState(int nSkillId);                                                         // 0x00643690
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId);                                        // 0x00646D60
void __fastcall sub_00553B10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);                               // 0x00553B10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall sub_005DD480(D2UnitStrc* pUnit, int nArg);                                                   // 0x005DD480
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit);                                                       // 0x00622870
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit);                                            // 0x0058F260
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit);                                                // 0x0058F160

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_ATTACKRATE 68

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClassId];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }

    return nMonsterId;
}

// 0x0056C2A0
void __fastcall SKILLS_FreeUnitSearch(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData)
{
    UNITFINDS_FreeUnitFindData(pUnitFindData);
    FOG_FreeServerMemory(pGame->pMemoryPool, pUnitFindData, ".\\SKILLS\\Skills.cpp", 0x465, 0);
}

// 0x0056D4E0
void __fastcall SKILLS_CreateMissilePattern(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nMissiles - 1) / 5 <= 7, 0xF0D);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    MISSILES_CreateMissileFromParams(pGame, pMissileParams);

    int nSubMissiles = nMissiles - 1;
    for (int j = 0; j < 7 && nSubMissiles; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (nSubMissiles <= 0)
            {
                break;
            }

            pMissileParams->nTargetX = gnOffset1_006E14F4[j] * gnSignX_006E1510[i];
            pMissileParams->nTargetY = gnOffset2_006E14C8[j] * gnSignY_006E14E4[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);

            pMissileParams->nTargetX = gnOffset2_006E14C8[j] * gnSignX_006E1510[i];
            pMissileParams->nTargetY = gnOffset1_006E14F4[j] * gnSignY_006E14E4[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);
            nSubMissiles -= 2;
        }

        pMissileParams->nTargetX = gnXOffsets_006E14A8[j];
        pMissileParams->nTargetY = gnYOffsets_006E1488[j];
        MISSILES_CreateMissileFromParams(pGame, pMissileParams);
        nSubMissiles -= 1;
    }
}

// 0x0056DE40
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit)
{
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
    }
}

// 0x0056DFA0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* i = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); i; i = SKILLS_GetNextSkill(i))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(i, ".\\SKILLS\\Skills.cpp", 0x1153);
            const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
            if (nPassiveState > 0)
            {
                STATES_ToggleState(pUnit, nPassiveState, 1);
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }
    }
}

// 0x0056E210
void __fastcall sub_0056E210(D2UnitStrc* pUnit, int nArg)
{
    sub_00553B10(SUNIT_GetGameFromUnit(pUnit), pUnit, nArg);
}

// 0x0056E2F0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == 0x1EC && STATES_CheckState(pUnit, 0x8F))
        {
            return 0;
        }
    }

    return sub_005DD480(pUnit, nAiSpecialState) != 0;
}

// 0x0056E510
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x0056E520
void __fastcall SKILLS_ApplyAttackRateModifier(D2UnitStrc* pUnit, int nAttackRate)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_ATTACKRATE, nAttackRate, 0);
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\Skills.cpp", 0x12AB);
    }
}

// 0x0056E580
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_MONSTER)
    {
        if (pOwner == pUnit)
        {
            AIGENERAL_DetachOwnedMinions(pUnit);
        }
        else
        {
            AIGENERAL_FreeMinionList(pUnit);
        }
    }
}

// 0x0056E5B0
int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord(pUnit->dwClassId);
            if (pCharStatsTxtRecord)
            {
                return pCharStatsTxtRecord->nWalkSpeed << 8;
            }
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                return pMonStatsTxtRecord->nVelocity << 8;
            }
        }
    }

    return 0x600;
}

#include "gen/data/Source/D2Game/0056C2A0_SKILLS_FreeUnitSearch.inc"
