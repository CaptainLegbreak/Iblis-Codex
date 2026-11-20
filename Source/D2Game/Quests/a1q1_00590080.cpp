#include "D2Game.h"
#include "D2Structs.h"

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};
struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};
struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};
struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pfCallback[16];
    int nQuestFilter;
};
struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_III 2

struct D2Act1Quest1Strc
{
    D2QuestGUIDStrc pQuestGUID;
    char unk0x84[0x03];
    unsigned char bTimerActive;
};

#define QUESTSTATEFLAG_A1Q1 1

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058FBE0
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

// 0x00590080
int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_COMPLETEDNOW);
    QUESTS_SendLogUpdateEx(pUnit, 1, 0);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
    return 0;
}

// 0x005900E0
int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 35, pUnit);
    }

    return 0;
}

// 0x00590120
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == ACT_I)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING);
    }
}

// 0x00590190
int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005901F0
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

// 0x00590230
bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 4)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerActive = 0;
    return 1;
}

// 0x00590690
void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}
