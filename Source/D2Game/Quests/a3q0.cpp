#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6ED0

void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6F20

void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6FD0

extern char gpAct3Q0NpcMessages[]; // 0x0073EAA0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B6F90

bool __fastcall ACT3Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B6FA0

// 0x005B7010
void __fastcall ACT3Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT3Q0_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT3Q0_Callback00_NpcActivate;
    pQuestData->pCallback[13] = ACT3Q0_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct3Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;

    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest0Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q0.cpp", 148, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest0Strc));

    pQuestData->eFilter = 16;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q0_ActiveFilterCallback;
}

