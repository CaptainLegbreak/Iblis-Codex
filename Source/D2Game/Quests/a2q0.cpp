#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Game.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall ACT2Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00598640

void __fastcall ACT2Q0_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005987B0

void __fastcall ACT2Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005987D0

void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005986B0

extern "C" char gpAct2Q0NpcMessages[]; // 0x00738FC8

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00598770

bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598780

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

// 0x00598810
void __fastcall ACT2Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q0_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q0_Callback00_NpcActivate;
    pQuestData->pCallback[10] = ACT2Q0_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[13] = ACT2Q0_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct2Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 8;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q0_ActiveFilterCallback;

    D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest0Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q0.cpp", 172, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

