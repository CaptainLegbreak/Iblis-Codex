#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"




struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuest, int nState); // 0x00544720
void __stdcall shim_1(void* p1, void* p2);

// build: context sub_0059A570_StartDarknessForPlayer
static __declspec(noinline) void __stdcall sub_0059A570_StartDarknessForPlayer(D2QuestDataStrc* pQuestData, D2UnitStrc* pPlayer)
{

    pQuestData->fState = 1;
    shim_1(0, &pPlayer);
}

// 0x0059A5D0
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(!pQuestArg ? 0 : pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 11, 13);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 2) != 1)
    {
        return;
    }

    sub_0059A570_StartDarknessForPlayer(pQuestData, pQuestArg->pPlayer);

    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 4))
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 3))
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 2;
    }
    else
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 1;
    }
}
