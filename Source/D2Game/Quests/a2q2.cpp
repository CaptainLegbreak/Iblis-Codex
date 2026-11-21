#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

enum
{
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0

bool __fastcall ACT2Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005996C0

void __fastcall ACT2Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005997F0

void __fastcall ACT2Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00599910

void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00599A30

void __fastcall sub_0059E850(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E850

bool __fastcall ACT2Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E630

int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall ACT2Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

#define QUESTSTATEFLAG_A2Q2 10

#define QUEST_A2Q2_HORADRICSTAFF 9

#define QFLAG_REWARDGRANTED 0

#define QFLAG_LEAVETOWN 3

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00599750
int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 0))
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pGame, pUnit, ' fsm') || ITEMS_FindQuestItem(pGame, pUnit, ' tsh'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}

// 0x005997C0
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' xob'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}

// 0x00599A00
void __fastcall ACT2Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel == LEVEL_LUTGHOLEIN)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}

// 0x00599510
static int __stdcall sub_00599510(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDNOW))
    {
        return 1;
    }

    return 0;
}

// 0x00599570
static int sub_00599570_ACT2Q2_CycleStatusIfDone(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (sub_00599510(pGame, pPlayer))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, QUEST_A2Q2_HORADRICSTAFF);
    }

    return 0;
}

// 0x00599A30
void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nItemId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bLeftTown = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);

    pQuestData->dwFlags &= 0xFFFFFF00;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pPlayer);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (pQuestData->nActNo == DRLG_GetActNoFromLevelId(nLevelId))
    {
        sub_00599510(pQuestArg->pGame, pQuestArg->pPlayer);
    }

    if (pItemsTxtRecord->dwCode == ' 1rt' && !bLeftTown)
    {
        pQuestData->fLastState = 1;
        sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        return;
    }

    if (pItemsTxtRecord->dwCode == ' piv')
    {
        if (bLeftTown)
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        return;
    }

    if (pItemsTxtRecord->dwCode == ' xob')
    {
        if (!bLeftTown)
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        return;
    }

    if (pItemsTxtRecord->dwCode == ' fsm')
    {
        if (!bLeftTown)
        {
            pQuestData->fLastState = 6;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 2;
            sub_00599570_ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
    }
}

// 0x00599B30
void __fastcall ACT2Q2_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nItemId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);

    if (pItemsTxtRecord->dwCode == ' piv' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 4))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 4);
    }

    if (pItemsTxtRecord->dwCode == ' xob' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 6))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 6);
    }

    if (pItemsTxtRecord->dwCode == ' fsm' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 5))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 5);
    }
}

// 0x0059E970
void __fastcall ACT2Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' fsm'))
    {
        ++pQuestDataEx->nBaseStaffs;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' piv'))
    {
        ++pQuestDataEx->nAmulets;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' xob'))
    {
        ++pQuestDataEx->nHoradricCubes;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' tsh'))
    {
        ++pQuestDataEx->nCubedStaffs;
    }

    if (!pQuestDataEx->bStaffMissingDetected || pQuestDataEx->nCubedStaffs <= 0 && (!pQuestDataEx->nHoradricCubes || !pQuestDataEx->nAmulets || !pQuestDataEx->nBaseStaffs))
    {
        return;
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData13 || !pQuestData13->bNotIntro)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx13 = (D2Act2Quest6Strc*)pQuestData13->pQuestDataEx;
    if (pQuestDataEx13->bStaffItemsRemoved != 1)
    {
        pQuestDataEx13->bHoradricStaffIsMissing = 0;
    }
}

// 0x0059EA20
void __fastcall ACT2Q2_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
    switch ((unsigned int)ITEMS_GetBaseCode(pQuestArg->pTarget))
    {
    case ' xob':
        --pQuestDataEx->nHoradricCubes;
        break;
    case ' tsh':
        --pQuestDataEx->nCubedStaffs;
        break;
    case ' fsm':
        --pQuestDataEx->nBaseStaffs;
        break;
    case ' piv':
        --pQuestDataEx->nAmulets;
        break;
    default:
        break;
    }

    if (pQuestDataEx->bStaffMissingDetected || pQuestDataEx->nCubedStaffs)
    {
        return;
    }

    if (!pQuestDataEx->bCubeDropped || pQuestDataEx->nHoradricCubes)
    {
        D2QuestDataStrc* pQuestData10;
        if (pQuestDataEx->nAmulets
            || (pQuestData10 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q3_TAINTEDSUN)) == 0
            || !((D2Act2Quest3Strc*)pQuestData10->pQuestDataEx)->bAltarDestroyed)
        {
            if (!pQuestDataEx->bHoradricScrollDropped || pQuestDataEx->nBaseStaffs)
            {
                return;
            }
        }
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData13 && pQuestData13->bNotIntro)
    {
        D2Act2Quest6Strc* pQuestDataEx13 = (D2Act2Quest6Strc*)pQuestData13->pQuestDataEx;
        if (pQuestDataEx13->bStaffItemsRemoved != 1)
        {
            if (pQuestData13->pGame->nGameType == 3)
            {
                pQuestDataEx13->bHoradricStaffIsMissing = 1;
                pQuestDataEx13->nQuestStatus = 8;
                pQuestDataEx->bStaffMissingDetected = 1;
                return;
            }
            pQuestDataEx13->bHoradricStaffIsMissing = 1;
            pQuestDataEx13->nQuestStatus = 9;
        }
    }
    pQuestDataEx->bStaffMissingDetected = 1;
}

// 0x0059EB00
void __fastcall ACT2Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct2Q2NpcMessages;
    pQuestData->bActive = 1;

    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q2.cpp", 1005, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q2;
    pQuestData->pfStatusFilter = ACT2Q2_StatusFilterCallback;
    pQuestData->nInitNo = 0;
    pQuestData->pfActiveFilter = ACT2Q2_ActiveFilterCallback;
    pQuestData->pCallback[3] = ACT2Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT2Q2_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT2Q2_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[4] = ACT2Q2_Callback04_ItemPickedUp;
    pQuestData->pCallback[5] = ACT2Q2_Callback05_ItemDropped;
    pQuestData->pCallback[8] = sub_00599A20_ACT2Q2_Callback08_Empty;
    pQuestData->pCallback[13] = sub_0059E850;
    pQuestData->pCallback[14] = ACT2Q2_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT2Q2_Callback09_PlayerDroppedWithQuestItem;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest2Strc));
    pQuestData->fLastState = 13;
}

#include "gen/data/Source/D2Game/Quests/a2q2.inc"
