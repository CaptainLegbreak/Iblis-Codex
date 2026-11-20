#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0




struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);


struct D2Act2Quest1Strc
{
    unsigned char bRadamentKilled;
    unsigned char pad0x01[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bAtmaActivated;
    unsigned char unk0x09;
    unsigned char bStatusTimerStarted;
    unsigned char pad0x0B;
    int nSkillBookDropCount;
    unsigned char bRewardPending;
    unsigned char pad0x11[3];
};

enum
{
    QUESTSTATEFLAG_A2Q1 = 9,
    LEVEL_LUTGHOLEIN = 40,
};
extern char gpAct2Q1NpcMessages[];                                                                          // 0x00739218
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
bool __fastcall ACT2Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598910
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00598980
void __fastcall ACT2Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00598990
void __fastcall sub_00598A70(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00598A70
void __fastcall ACT2Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00598C40
void __fastcall ACT2Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00599020
bool __fastcall sub_005991C0_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x005991C0

void __fastcall ACT2Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00599130
void __fastcall ACT2Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != LEVEL_LUTGHOLEIN)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 551);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x00599230
void __fastcall ACT2Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0) == 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 5) == 1 && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssa'))
        {
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 15);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 5);
        }
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q1, 13);
        pQuestData->bNotIntro = 0;
        pQuestData->fState = 0;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 15) == 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1) == 1)
        {
            ((D2Act2Quest1Strc*)pQuestData->pQuestDataEx)->bRewardPending = 1;
        }
        pQuestData->fState = 0;
        pQuestData->bNotIntro = 0;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 4) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00599340
void __fastcall ACT2Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    pQuestData->pCallback[3] = ACT2Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT2Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT2Q1_Callback00_NpcActivate;
    pQuestData->pCallback[11] = sub_00598A70;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[2] = ACT2Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT2Q1_Callback13_PlayerStartedGame;
    pQuestData->nSeqId = 13;
    pQuestData->pfSeqFilter = sub_005991C0_SeqCallback;
    pQuestData->pNPCMessages = gpAct2Q1NpcMessages;

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 670, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q1;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q1_ActiveFilterCallback;

    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest1Strc));
    pQuestDataEx->pRoom = 0;
    pQuestDataEx->bRadamentKilled = 0;
}

#include "gen/data/Source/D2Game/Quests/a2q1_00599130.inc"
