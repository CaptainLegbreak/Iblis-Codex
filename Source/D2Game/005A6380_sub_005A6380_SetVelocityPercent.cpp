struct D2StatListStrc;
struct D2SkillStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2MonStats2Txt
{
    char unk0x000[0x104];
    unsigned char nModeEventFlags[4];
};

struct D2MonModeInfoTableStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

struct D2MonVelocityParamStrc
{
    int unk0x00[4];
    int nVelocityPercent;
};

#define UNIT_MONSTER 1
#define MONMODE_NEUTRAL 1
#define STAT_VELOCITYPERCENT 67

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2MonModeInfoTableStrc gtMonsterModeEventPolicies[];                                                 // 0x006E23D0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
int __fastcall MONSTER_GetAiState(D2UnitStrc* pMonster);                                                    // 0x005734E0
void __fastcall MONSTER_SetAiState(D2UnitStrc* pMonster, int nAiState);                                     // 0x005734C0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);                  // 0x005A73E0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50

// 0x005A6380
static void sub_005A6380_SetVelocityPercent(D2MonVelocityParamStrc* pParam, D2UnitStrc* pUnit)
{
    const int nVelocityPercent = pParam->nVelocityPercent;
    if (!nVelocityPercent)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x4000);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x4004, 0, UNIT_MONSTER, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    sub_006270B0(pStatList, STAT_VELOCITYPERCENT, nVelocityPercent, 0);
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\MONSTER\\MonsterMode.cpp", 269);
}

// 0x005A68E0
static void sub_005A68E0_SetAiStateForMode(int nMode, D2UnitStrc* pMonster)
{
    const int nAiState = MONSTER_GetAiState(pMonster);
    if (nAiState >= 16)
    {
        nMode = nAiState - 16;
    }
    else if (nAiState == 13 && nMode == 3)
    {
        nMode = nAiState;
    }

    MONSTER_SetAiState(pMonster, nMode);
}

// 0x005A6B10
static int sub_005A6B10_IsModeEventEnabled(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || nMode >= 16)
    {
        return 0;
    }

    const D2MonModeInfoTableStrc* pMonModeInfoTableRecord = &gtMonsterModeEventPolicies[nMode];
    if (pMonModeInfoTableRecord->unk0x00)
    {
        return 1;
    }

    if (!pMonModeInfoTableRecord->unk0x04 && pMonModeInfoTableRecord->unk0x08)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            return pMonStats2TxtRecord->nModeEventFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
        }
    }

    return 0;
}

// 0x005A7B30
static int __stdcall sub_005A7B30_TryStartNeutral(D2GameStrc* pGame, int nMode, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);
    if (nMode && nMode != 12 && SUNIT_IsDead(pUnit))
    {
        return 1;
    }

    D2ModeChangeStrc tModeChange = {};
    tModeChange.pUnit = pUnit;
    tModeChange.nMode = MONMODE_NEUTRAL;
    MONSTERMODE_StartNeutral(pGame, &tModeChange);
    return 0;
}

// 0x005A7E60
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(nMode < 16, 1976);
    UNITS_SetUsedSkill(pUnit, 0);
    memset(pModeChange, 0, sizeof(D2ModeChangeStrc));
    pModeChange->nMode = nMode;
    pModeChange->pUnit = pUnit;
    int nEventFlag = 100;
    if (sub_005A6B10_IsModeEventEnabled(pUnit, nMode))
    {
        nEventFlag = 101;
    }

    pModeChange->nEventFlag = nEventFlag;
}

// calling-convention shim (not game code)
void __stdcall sub_A08_EmitModeHelpers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonVelocityParamStrc* pParam, int a, int b)
{
    sub_005A68E0_SetAiStateForMode(a, pUnit);
    if (sub_005A7B30_TryStartNeutral(pGame, b, pUnit))
    {
        sub_005A6380_SetVelocityPercent(pParam, pUnit);
    }
    sub_005A68E0_SetAiStateForMode(b, pParam->unk0x00[0] ? pUnit : 0);
    sub_005A6380_SetVelocityPercent(pParam + 1, pUnit);
    sub_005A7B30_TryStartNeutral(pGame, a, pUnit);
}

#include "gen/data/Source/D2Game/005A6380_sub_005A6380_SetVelocityPercent.inc"
