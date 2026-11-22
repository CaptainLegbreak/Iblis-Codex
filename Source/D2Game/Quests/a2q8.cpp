#include "D2MonsterIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3C0

void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3F0

extern char gpAct2Q8NpcMessages[];                                                                          // 0x0073BD58

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

enum
{
    QUESTSTATEFLAG_A2Q8 = 31,
};

bool __fastcall ACT2Q8_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E4A0

bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E4B0

// 0x0059E530
void __fastcall ACT2Q8_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q8_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q8_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct2Q8NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    D2Act2Quest8Strc* pQuestDataEx = (D2Act2Quest8Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest8Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q8.cpp", 150, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->unk0x01 = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q8;
    pQuestData->pfStatusFilter = ACT2Q8_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q8_ActiveFilterCallback;
}

