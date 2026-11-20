#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"



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



typedef int (__fastcall* MonModeStartFunc)(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);
typedef int (__fastcall* MonModeUnitFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit);

struct D2MonModeCallbackTableStrc
{
    MonModeStartFunc pfnStart;
    MonModeUnitFunc pfnUpdate;
    MonModeUnitFunc pfnEnd;
    int bFlag;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                        // 0x00553570
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);                                        // 0x00554CA0
int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pUnit, int nMode);                                                    // 0x0063E8D0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648780
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                               // 0x0046C140
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00573780
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClassId, int nMode);          // 0x00574370
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, void* pDamage); // 0x005C0C30
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                 // 0x00552FD0
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit);                                           // 0x0056FAF0
const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode); // 0x005A78A0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                               // 0x00620210
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                              // 0x005541B0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);                   // 0x005A73E0
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit);                                            // 0x00573120

#define UNITEVENT_DEATH 13
#define EVENTTYPE_AITHINK 2
#define MONMODE_DEATH 0
#define MONMODE_NEUTRAL 1
#define MONMODE_WALK 2
#define MONMODE_GETHIT 3
#define MONMODE_BLOCK 6
#define MONMODE_SKILL3 10
#define MONMODE_SKILL4 11
#define MONMODE_DEAD 12
#define MONMODE_SEQUENCE 14
#define MONMODE_RUN 15

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005A72B0
void __fastcall sub_6FC641D0(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    if (pAttacker)
    {
        SUNIT_SetCombatMode(pGame, pAttacker, MONMODE_DEAD);
        SUNITEVENT_Trigger(pGame, UNITEVENT_DEATH, pAttacker, 0, 0);
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord)
        {
            switch (pMonStatsTxtRecord->nSplEndDeath)
            {
            case 1:
                if (pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] <= sgptDataTables->nMonStatsTxtRecordCount)
                {
                    MONSTER_Reinitialize(pGame, pAttacker, pMonStatsTxtRecord->wMinion[0], 1);
                    MONSTER_UpdateAiCallbackEvent(pGame, pAttacker);
                }
                break;
            case 2:
            {
                D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
                if (pOwner)
                {
                    SUNITDMG_KillMonster(pGame, pOwner, 0, 1);
                }
                break;
            }
            }
        }
    }
}

// 0x005A7350
int __fastcall sub_6FC64280(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!MONSTERS_IsSandLeaper(pUnit, 0))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_DEAD);
        return 1;
    }
    sub_6FCBC930(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_DEAD);
    }
    return 1;
}

// 0x005A7490
int __fastcall sub_6FC643D0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    SUNIT_SetCombatMode(pGame, pModeChange->pUnit, MONMODE_SKILL3);
    return 1;
}

// 0x005A74A0
int __fastcall sub_6FC643E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_6FCBC930(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SKILL4);
    }
    return 1;
}

// 0x005A74E0
int __fastcall sub_6FC64410(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SKILL4);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 15, 0, 0);
    return 1;
}

// 0x005A7520
int __fastcall sub_6FC64450(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!PATH_GetNumberOfPathPoints(pUnit->pDynamicPath))
    {
        return 0;
    }
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_WALK);
    return 1;
}

// 0x005A7550
int __fastcall sub_6FC644E0(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!PATH_GetNumberOfPathPoints(pUnit->pDynamicPath))
    {
        return 0;
    }
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_RUN);
    return 1;
}

// 0x005A7580
int __fastcall sub_6FC64540(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit)
    {
        if (pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
        {
            if (!sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_GETHIT))
            {
                return 0;
            }
            SUNIT_SetCombatMode(pGame, pUnit, MONMODE_GETHIT);
        }
    }
    return 1;
}

// 0x005A77C0
int __fastcall sub_6FC64B50(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    SUNIT_SetCombatMode(pGame, pModeChange->pUnit, MONMODE_BLOCK);
    return 1;
}

// 0x005A7870
int __fastcall sub_6FC64E60(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SEQUENCE);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFBF;
    }
    return SKILLS_StartUsedSkill(pGame, pUnit);
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

// 0x005A7BA0
void __fastcall sub_005A7BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const D2MonModeCallbackTableStrc* pMonModeCallbackTableRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nAnimMode);
    if (!pMonModeCallbackTableRecord)
    {
        sub_005A7B30_TryStartNeutral(pGame, nAnimMode, pUnit);
        return;
    }
    if (!pMonModeCallbackTableRecord->pfnUpdate)
    {
        sub_005A7B30_TryStartNeutral(pGame, nAnimMode, pUnit);
        return;
    }
    pMonModeCallbackTableRecord->pfnUpdate(pGame, pUnit);
}

// 0x005A7BE0
void __fastcall sub_005A7BE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const D2MonModeCallbackTableStrc* pMonModeCallbackTableRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nAnimMode);
    if (!pMonModeCallbackTableRecord)
    {
        sub_005A7B30_TryStartNeutral(pGame, nAnimMode, pUnit);
        return;
    }
    if (!pMonModeCallbackTableRecord->pfnEnd)
    {
        sub_005A7B30_TryStartNeutral(pGame, nAnimMode, pUnit);
        return;
    }
    pMonModeCallbackTableRecord->pfnEnd(pGame, pUnit);
}

// 0x005A7EF0
void __fastcall D2GAME_MONSTERS_AiFunction13_6FC65890(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x005A7F70
void __fastcall sub_005A7F70(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    sub_00573120_ClearMonsterPair(pUnit);
}
