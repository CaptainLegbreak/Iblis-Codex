#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"





struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};


#define QUESTSTATEFLAG_A2Q2 10
#define QUEST_A2Q2_HORADRICSTAFF 9
#define QFLAG_REWARDGRANTED 0
#define QFLAG_LEAVETOWN 3
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                          // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);             // 0x0065C310
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                               // 0x006335F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0

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
