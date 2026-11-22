#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);       // 0x005A7C20

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                            // 0x006427F0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                         // 0x0061A1B0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster);                                     // 0x005736A0

void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                         // 0x00624690

struct D2AiParamStrc;

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00555AE0

void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0057C980

void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl);                   // 0x0058F810

void __fastcall D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);        // 0x005A64D0

void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract);     // 0x00572BC0

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nParam); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nParam1, int nParam2); // 0x005417D0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005735A0
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5)
{
    int nAnimMode;
    D2MonStatsTxt* pMonStatsTxtRecord;
    if (!pMonster)
    {
        nAnimMode = 0;
        pMonStatsTxtRecord = 0;
    }
    else
    {
        nAnimMode = pMonster->dwAnimMode;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pMonster->dwClassId);
    }

    PATH_SetVelocity(pMonster->pDynamicPath, pMonStatsTxtRecord->nVelocity << 8, ".\\MONSTER\\Monster.cpp", 383);
    UnitUpdateAnimRateAndVel(pMonster, ".\\MONSTER\\Monster.cpp", 384);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pMonster, nAnimMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

static inline int sub_E09_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x005736A0
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pMonster);

    if (!pMonster || !sub_E09_CheckMonStatsFlag(pMonster->dwClassId, 9))
    {
        SUNIT_RemoveAllItemsFromInventory(pGame, pMonster);
        INVENTORY_FreeInventory(pMonster->pInventory);
    }

    if (pMonster->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pMonster->pHoverText);
    }

    if (pMonster->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        if (pMonsterData)
        {
            AIGENERAL_FreeAiControl(pGame, pMonsterData->pAiControl);
            D2GAME_MONSTERMODE_FreeParams_6FC63020(pGame, pMonsterData->pAiParam);
            MONSTERAI_FreeMonsterInteract(pGame, pMonsterData->pMonInteract);
        }
    }

    EVENT_FreeUnitTimers(pGame, pMonster);
}

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2ComponentVariantStrc;

struct D2MonRegDataStrc;

static inline int GetValidMonsterClass(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return nClassId;
    return -1;
}

// 0x00573780
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (!pUnit) return;
    if (pUnit->dwAnimMode == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
    }
    else if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        return;
    }
    switch (GetValidMonsterClass(sub_00463860(pUnit)))
    {
    case 110:
    case 118:
    case 136:
    case 247:
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
        break;
    }
}

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

#pragma intrinsic(memset)


struct D2PlayerCountBonusStrc
{
    int nHp;
    int nExperience;
    int nMonsterSkillBonus;
    int nDifficulty;
    int nPlayerCount;
};

struct D2ActiveRoomStrc;

extern const int gnHpBonusTable[9];

extern const int gnExperienceBonusTable[9];

int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame);                                                    // 0x00535790

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30

#define UNIT_MONSTER 1

#define BONUS_TABLE_SIZE 9

#define HP_BONUS_STEP 50

#define HP_BONUS_BASE 2

#define XP_BONUS_BASE 130

#define MONALIGN_EVIL 0

__declspec(noinline) int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

// build: context MONSTER_GetHpBonus
__declspec(noinline) int __fastcall MONSTER_GetHpBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnHpBonusTable[nPlayerCount];
    }

    return (nPlayerCount - HP_BONUS_BASE) * HP_BONUS_STEP;
}

__declspec(noinline) int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount); // 0x00573910

// build: context MONSTER_GetExperienceBonus
__declspec(noinline) int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnExperienceBonusTable[nPlayerCount];
    }

    return 2 * (5 * nPlayerCount + XP_BONUS_BASE);
}

static inline D2MonsterDataStrc* MONSTER_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573930
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster)
{
    if (!pPlayerCountBonus)
    {
        return;
    }

    memset(pPlayerCountBonus, 0x00, sizeof(*pPlayerCountBonus));
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterDataInline(pMonster);
    if (!pMonsterData)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = (D2MonStatsTxt*)pMonsterData->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nAlign == MONALIGN_EVIL)
    {
        int nPlayerCount = PLAYER_GetPlayerCount(pGame);
        if (nPlayerCount < 1)
        {
            nPlayerCount = 1;
        }
        pPlayerCountBonus->nHp = MONSTER_GetHpBonus(nPlayerCount);
        pPlayerCountBonus->nExperience = MONSTER_GetExperienceBonus(nPlayerCount);
        pPlayerCountBonus->nPlayerCount = nPlayerCount;
    }
    else
    {
        pPlayerCountBonus->nPlayerCount = 1;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pGame->nDifficulty >= 3)
    {
        pGame->nDifficulty = 2;
    }

    pPlayerCountBonus->nMonsterSkillBonus = pDifficultyLevelsTxtRecord->dwMonsterSkillBonus;
    pPlayerCountBonus->nDifficulty = pGame->nDifficulty;
}

// 0x00573C00
void __fastcall MONSTER_ResetMonsterModesInLevel(D2GameStrc* pGame, int nClassId1, int nClassId2, int nLevelId)
{
    D2DrlgActStrc* pAct = pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)];
    if (!pAct)
    {
        return;
    }

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nLevelId && DUNGEON_GetLevelIdFromRoom(pRoom) != nLevelId)
        {
            continue;
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
        {
            pNext = pUnit->ptRoomNext;
            if (pUnit->dwUnitType == UNIT_MONSTER && (pUnit->dwClassId == nClassId1 || pUnit->dwClassId == nClassId2) && !SUNIT_IsDead(pUnit) && !STATLIST_GetUnitAlignment(pUnit))
            {
                D2ModeChangeStrc modeChange;
                MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            }
        }
    }
}

// 0x00574370
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClassId, int nMode)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (!(pMonStatsTxtRecord->nMonStatsFlags[25 >> 3] & gdwBitMasks[25 & 7]))
        {
            return 0;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nUnitGUID = pUnit->dwUnitId;
        MONSTER_Free(pGame, pUnit);

        pUnit->dwClassId = nClassId;
        MONSTER_Initialize(pGame, pRoom, pUnit, nUnitGUID);
        UNITS_ChangeAnimMode(pUnit, nMode);
        return 1;
    }

    return 0;
}
