#include "D2Game.h"

#define UNIT_MONSTER 1
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define MONMODE_GETHIT 3
#define MONMODE_DEAD 12
#define MONMODE_SEQUENCE 14
#define STATE_UNINTERRUPTABLE 54
#define PATHTYPE_ASTAR 1
#define PATHTYPE_TOWARD 2
#define PATHTYPE_STRAIGHT 7
#define PATHTYPE_LEAP 9
#define PATHTYPE_TOWARD_FINISH 13
#define UNITFLAG_DOUPDATE 0x1
#define UNITFLAG_MONMODEISCHANGING 0x80000
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MonVelocityParamStrc;
struct D2MonsterDataStrc;
struct D2MonStats2Txt;
struct D2MonModeInfoTableStrc;
struct D2ModeChangeStrc;
struct D2MonModeCallbackTableStrc;
struct D2MonStatsTxt;
struct D2SuperUniquesTxt;
struct D2DifficultyLevelsTxt;

struct D2MonVelocityParamStrc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned short unk0x02;
    struct D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nVelocityPercent;
    int nTargetTimer;
    int f_18;
    int f_1C;
    unsigned char nNewDistOverride;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    D2MonVelocityParamStrc* pAiParam;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x1E];
    unsigned char nActionFrame;
    unsigned char unk_4F[0x55];
    D2HoverTextStrc* pHoverText;
    int unk0xA8[7];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x1D02];
    int dwPathTypesCount[17];
    int nTotalPathTypesCount;
};

struct D2MonStats2Txt
{
    char unk0x000[0x104];
    unsigned char nModeEventFlags[4];
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char nDirection;
    unsigned char nPathType;
    unsigned short unk0x16;
    int nVelocityPercent;
    unsigned char nNewDist;
    char unk0x1D[3];
};

typedef int (__fastcall* MonModeStartFunc)(D2GameStrc*, D2ModeChangeStrc*);

struct D2MonModeCallbackTableStrc
{
    MonModeStartFunc pfStart;
    void* pfUpdate;
    void* pfEnd;
    int bScheduleEvents;
};

struct D2MonStatsTxt
{
    char unk0x00[0x86];
    unsigned short wTreasureClass[3][4];
    unsigned char nTCQuestId;
    unsigned char nTCQuestCP;
    char unk0xA0[0x108];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MonModeInfoTableStrc gtMonsterModeEventPolicies[]; // 0x006E23D0
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall sub_006217C0(D2UnitStrc* pUnit); // 0x006217C0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance); // 0x006490E0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc* pUnit); // 0x005533D0
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990
void __fastcall SUNIT_ScheduleAnimationEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005539B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int bUninterruptable); // 0x005544B0
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554CA0
void __fastcall sub_0056FAF0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FAF0
void __fastcall sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FC50
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4350
void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4360
void __fastcall MONSTERMODE_UpdateModeAttackStats(D2UnitStrc* pUnit, int nMode); // 0x005A4F50
void __fastcall sub_005A5490(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005A5490
int __fastcall sub_005A6D50(D2GameStrc* pGame, D2UnitStrc* pUnit, int bModeEvent); // 0x005A6D50
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange); // 0x005A73E0
const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode); // 0x005A78A0
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit); // 0x0058F6C0
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

struct D2SuperUniquesTxt
{
    char unk0x00[0x2C];
    unsigned short wTC[3];
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x10];
    int dwMonsterSkillBonus;
};

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall sub_6FC52110(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055AFA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A03A0
void __stdcall sub_005A6B70_MissileFollowUp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x005A6B70
void __fastcall sub_005A8030(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A8030
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

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

// 0x005A6290
static int __stdcall MONSTERMODE_ComputePath(int nPathType, D2MonVelocityParamStrc* pAiParam, D2UnitStrc* pUnit, unsigned char nNewDist)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    PATH_SetNewDistance(pPath, nNewDist);

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pPath);
    const int nX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    if (pTarget != pAiParam->pTarget || nX != pAiParam->nX || nY != pAiParam->nY)
    {
        pAiParam->pTarget = pTarget;
        pAiParam->nX = nX;
        pAiParam->nY = nY;
        pAiParam->unk0x00 = 0;
        pAiParam->unk0x01 = 0;
    }

    PATH_SetType(pPath, nPathType);
    D2Common_10142(pPath, pUnit, 0);

    if (PATH_GetNumberOfPathPoints(pPath))
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        pAiParam->unk0x00 = 0;
        pAiParam->unk0x01 = 0;
        return nPathType;
    }

    switch (nPathType)
    {
    case PATHTYPE_TOWARD:
    case PATHTYPE_STRAIGHT:
    case PATHTYPE_LEAP:
    case PATHTYPE_TOWARD_FINISH:
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        PATH_SetType(pPath, PATHTYPE_WALL_FOLLOW);
        D2Common_10142(pPath, pUnit, 0);
        return PATHTYPE_WALL_FOLLOW;
    }

    return nPathType;
}

// 0x005A63F0
static void __stdcall sub_005A63F0_UpdateModePath(D2GameStrc* pGame, D2UnitStrc* pUnit, int nVelocityPercent, D2MonVelocityParamStrc* pAiParam, int nPathType, unsigned char nNewDist)
{
    if (pAiParam->f_18)
    {
        nPathType = pAiParam->f_18;
    }

    if (pAiParam->f_1C)
    {
        nVelocityPercent = pAiParam->f_1C;
    }

    if (pAiParam->nNewDistOverride)
    {
        nNewDist = pAiParam->nNewDistOverride;
    }

    pAiParam->f_18 = 0;
    pAiParam->f_1C = 0;
    pAiParam->nNewDistOverride = 0;

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nTargetTimer = -1;
    int nNewPathType = 0;
    if (nPathType == 100)
    {
        nNewPathType = 0;
        nVelocityPercent = 0;
    }
    else
    {
        if (!nNewDist)
        {
            nNewDist = 5;
        }

        if (nPathType == 101)
        {
            nPathType = PATHTYPE_TOWARD_FINISH;
        }

        nNewPathType = MONSTERMODE_ComputePath(nPathType, pAiParam, pUnit, nNewDist);
        if (nNewPathType != PATHTYPE_ASTAR && PATH_GetTargetUnit(pPath))
        {
            nTargetTimer = 10;
        }
    }

    pAiParam->nTargetTimer = nTargetTimer;
    pAiParam->nVelocityPercent = nVelocityPercent;

    ++pGame->dwPathTypesCount[nNewPathType];
    if (nNewPathType)
    {
        ++pGame->nTotalPathTypesCount;
    }
}

// 0x005A75C0
int __fastcall sub_005A75C0_StartModeWithPath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (sub_005A6B10_IsModeEventEnabled(pUnit, pModeChange->nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!PATH_GetNumberOfPathPoints(pPath))
        {
            const int nBaseId = sub_00463860(pUnit);
            if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == 110)
            {
                D2Common_10142(pPath, pUnit, 0);
                SUNIT_SetCombatMode(pGame, pUnit, pModeChange->nMode);
                return 1;
            }

            return 0;
        }

        D2Common_10142(pPath, pUnit, 0);
    }

    SUNIT_SetCombatMode(pGame, pUnit, pModeChange->nMode);
    if (UNITS_GetUsedSkill(pUnit))
    {
        sub_0056FAF0(pGame, pUnit);
    }

    return 1;
}

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int bClearUsedSkill)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nMode = pModeChange->nMode;

    D2_ASSERT(!STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE), 1875);

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        SUNIT_SetUninterruptable(pUnit, 0);
        if (SUNIT_IsDead(pUnit))
        {
            return 1;
        }
    }

    if (!SUNIT_IsDead(pUnit))
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
    }

    if (pUnit->dwAnimMode != MONMODE_NEUTRAL)
    {
        sub_005A68E0_SetAiStateForMode(pUnit->dwAnimMode, pUnit);
    }

    D2MonVelocityParamStrc* pAiParam = 0;
    if (nMode != MONMODE_GETHIT)
    {
        if (pModeChange->pTargetUnit)
        {
            PATH_SetTargetUnit(pPath, pModeChange->pTargetUnit);
        }
        else
        {
            D2COMMON_10170_PathSetTargetPos(pPath, pModeChange->nX, pModeChange->nY);
        }

        PATH_SetDistance(pPath, 20);

        pAiParam = (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pAiParam : 0;
        sub_005A63F0_UpdateModePath(pGame, pUnit, pModeChange->nVelocityPercent, pAiParam, pModeChange->nPathType, pModeChange->nNewDist);
        MONSTERMODE_UpdateModeAttackStats(pUnit, nMode);
        MONSTERUNIQUE_ExecuteUModModeStartCallbacks(pGame, pUnit);
    }

    const D2MonModeCallbackTableStrc* pTargetRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nMode);
    if (!pTargetRecord || !pTargetRecord->pfStart)
    {
        sub_005A7B30_TryStartNeutral(pGame, nMode, pUnit);
        return 0;
    }

    const int nResult = pTargetRecord->pfStart(pGame, pModeChange);
    if (!nResult)
    {
        UNITS_SetUsedSkill(pUnit, 0);
        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD && SUNIT_IsDead(pUnit))
        {
            return 1;
        }

        MONSTERMODE_StartNeutral(pGame, pModeChange);
    }

    pUnit->dwFlags |= UNITFLAG_MONMODEISCHANGING;
    SUNIT_InitializeAnimation(pUnit);

    if (pAiParam)
    {
        sub_005A6380_SetVelocityPercent(pAiParam, pUnit);
    }

    MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(pGame, pUnit);

    const int nCurrentAnimMode = pUnit->dwAnimMode;
    if (bClearUsedSkill && nMode == nCurrentAnimMode)
    {
        UNITS_SetUsedSkill(pUnit, 0);
    }

    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pUnit);

    const D2MonModeCallbackTableStrc* pCurrentRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nCurrentAnimMode);
    if (!pCurrentRecord)
    {
        sub_005A7B30_TryStartNeutral(pGame, nMode, pUnit);
        return 0;
    }

    if (pCurrentRecord->bScheduleEvents)
    {
        if (sub_005A6B10_IsModeEventEnabled(pUnit, nCurrentAnimMode))
        {
            SUNIT_ResetRecurringModeChangeEvent(pGame, pUnit);
        }
        else
        {
            SUNIT_ScheduleAnimationEvents(pGame, pUnit);
        }
    }

    if (nCurrentAnimMode == MONMODE_GETHIT)
    {
        PATH_SetType(pPath, 0);
        PATH_SetNewDistance(pPath, 0);
    }

    return nResult;
}

inline D2MonStatsTxt* GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nId = pUnit->dwClassId;
        if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nId];
        }
    }
    return 0;
}

// 0x005A6520
static void __stdcall sub_6FC63E80(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 0x100;
    }

    AIGENERAL_UpdateMinionList(pUnit);
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit);
    sub_005B1A90(pGame, pUnit);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFF7FF3;
    }

    D2Common_10469(pUnit);
    STATES_UpdateStayDeathFlags(pUnit, MONSTERS_IsBoss(pMonStatsTxtRecord, pUnit));
    if (STATES_CheckStateMaskHideOnUnit(pUnit) && pUnit)
    {
        pUnit->dwFlags &= ~2;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 0x13))
    {
        PATH_SetUnitDeadCollision(pUnit, 1);
    }

    sub_006488A0_SetDirection(pPath, nDirection);
    MONSTER_DeleteEvents(pGame, pUnit);
}

// 0x005A7390
int __fastcall sub_005A7390_MONSTERMODE_EndDeath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_6FC63E80(pModeChange->nDirection, pGame, pUnit);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 12);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, 0);
    return 1;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A6600
void __stdcall sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a7, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(pUnit, 404);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 406);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    DRLG_GetActNoFromLevelId(nLevelId);

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    D2_ASSERT(pMonStatsTxtRecord, 410);

    const int nDifficulty = pGame->nDifficulty;
    int nTCId;
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(pUnit, nLevelId);
    const int nSuperUniqueId = MONSTERUNIQUE_GetSuperUniqueBossHcIdx(pGame, pUnit);
    if (nSuperUniqueId != -1)
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUniqueId);
        if (!pSuperUniquesTxtRecord)
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pSuperUniquesTxtRecord->wTC[nDifficulty];
        }
    }
    else
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][1];
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 8))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][0];
        }
    }

    if (pMonStatsTxtRecord->nTCQuestId > 0 && pMonStatsTxtRecord->wTreasureClass[nDifficulty][3] > 0 && pModeChange)
    {
        D2UnitStrc* pTarget = pModeChange->pTargetUnit;
        if (pTarget)
        {
            if (pTarget->dwUnitType != 0)
            {
                D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (STATES_CheckStateMaskExpOnUnit(pTarget))
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x800);
                    if (pStatList)
                    {
                        const int nOwnerType = STATLIST_GetOwnerType(pStatList);
                        const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
                        pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
                    }
                }

                if (pOwner)
                {
                    pTarget = pOwner;
                }
            }

            if (pTarget && pTarget->dwUnitType == 0)
            {
                D2BitBufferStrc* pQuestFlags = sub_00543520(pGame, pTarget);
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 15) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 1) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, pMonStatsTxtRecord->nTCQuestCP) != 1)
                {
                    nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][3];
                }
            }
        }
    }

    sub_6FC52110(pGame, pUnit, pModeChange->pTargetUnit, nTCId, 0, nItemLevel, a7, 0, 0, 0);
}

// 0x005A6D50
int __fastcall sub_005A6D50_CreateMonsterMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nMissileId = D2Common_11050(pUnit, nParam);
    if (nMissileId < 0)
    {
        return 0;
    }

    int nSkillLevel = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterSkillBonus + 1;
    if (UNIT_HasFlag(pUnit, 0x200))
    {
        nSkillLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    }

    if (sub_6FD11420(pGame, nMissileId, pUnit, 0, nSkillLevel, 0, 0, 0, 0, 1))
    {
        sub_005A6B70_MissileFollowUp(pGame, pUnit, nMissileId);
    }

    return 1;
}

// 0x005A8670
int __fastcall sub_6FC64E90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (sub_006217C0(pUnit))
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    int bCheck = 1;
    if (nSkillFlags & 1)
    {
        sub_6FCBC7E0(pGame, pUnit);

        if (sub_6FCBC930(pGame, pUnit) == 2)
        {
            SKILLS_SetFlags(pSkill, nSkillFlags | 2);
            sub_6FD13410(pGame, pUnit);
            bCheck = 0;
        }
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame == 4 || bCheck && !UNIT_HasFlag(pUnit, 0x40) && (nActionFrame == 1 || nActionFrame == 2))
    {
        sub_6FD13410(pGame, pUnit);
    }

    UNITS_StopSequence(pUnit);

    return 1;
}

// 0x005A74D0
void __fastcall sub_005A74D0_MonMode10End(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
}

static int sub_C04_IsAtSkillFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == MONMODE_SEQUENCE)
    {
        return (pUnit->dwFlags >> 6) & 1;
    }

    if (pUnit->nActionFrame == 1)
    {
        return 1;
    }

    return 0;
}

// 0x005A7670
int __fastcall sub_005A7670_UpdateModeSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        const int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 1)
        {
            sub_6FCBC7E0(pGame, pUnit);
            if (sub_6FCBC930(pGame, pUnit) == 2)
            {
                SKILLS_SetFlags(pSkill, nFlags | 2);
                sub_6FD13410(pGame, pUnit);
                if (sub_C04_IsAtSkillFrame(pUnit))
                {
                    sub_6FD13410(pGame, pUnit);
                }

                UNITS_StopSequence(pUnit);
                return 1;
            }
        }

        sub_6FD13410(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        return 1;
    }

    const int bModeEvent = sub_005A6B10_IsModeEventEnabled(pUnit, !pUnit ? 0 : pUnit->dwAnimMode);
    if (bModeEvent)
    {
        sub_6FCBC930(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        if (sub_006217C0(pUnit))
        {
            return 2;
        }

        if (!sub_C04_IsAtSkillFrame(pUnit))
        {
            return 1;
        }
    }

    if (!sub_005A6D50(pGame, pUnit, bModeEvent))
    {
        sub_005A5490(pUnit, pGame);
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }
    }

    return 1;
}

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

    pModeChange->nPathType = nEventFlag;
}
