#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);


typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct4Q3SourceFile[];
extern char gpAct4Q3NpcMessages[];
extern char gpAct4Q4NpcMessages[];
extern char gpAct3IntroNpcMessages[];

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex);
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate);
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);

int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B3E30
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

void __fastcall ACT4Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, gszAct4Q3SourceFile, 433);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}

void __fastcall ACT4Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) == 0x20686668)
    {
        --pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20686668))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pfActiveFilter = ACT4Q3_ActiveFilterCallback;
    pQuestData->pQuestDataEx = 0;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;
    pQuestData->pNPCMessages = gpAct4Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfSeqFilter = ACT4Q3_SeqCallback;
    pQuestData->nSeqId = 23;
    pQuestData->eFilter = 27;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT4Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT4Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT4Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[8] = ACT4Q3_Callback08_MonsterKilled;
    pQuestData->pCallback[4] = ACT4Q3_Callback04_ItemPickedUp;

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest3Strc), gszAct4Q3SourceFile, 856, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest3Strc));
}

void __fastcall ACT4Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 408)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 23);
        if (!pQuest || !((D2Act4Quest2Strc*)pQuest->pQuestDataEx)->bDiabloKilled)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 1);
        }
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 0);
    }
}

void __fastcall ACT4Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q4_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct4Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 33;
    pQuestData->pfStatusFilter = ACT4Q4_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q4_ActiveFilterCallback;
}

void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT3Intro_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct3IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 42;
    pQuestData->pfStatusFilter = ACT3Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Intro_ActiveFilterCallback;
}

void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 465 || nMessageIndex == 466)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 16, 0);
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return;
    }

    const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
    if (nClassId == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 0);
    }
}

void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}
