#include "D2Game.h"
#define QFLAG_PRIMARYGOALDONE 13

struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2Act3Quest5Strc;
struct D2GameStrc;
struct D2PlayerDataStrc;
struct D2QuestArgStrc;
struct D2Act2Quest5Strc;
struct D2Act2Quest6Strc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

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
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    unsigned char bMonstersSpawned;
    unsigned char pad0x06[2];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
    unsigned char bFlailDropped;
    unsigned char bCubeDropped;
    unsigned char pad0x0F;
    int nMonsterGUIDs[6];
    unsigned char bCompellingOrbSpawned;
    unsigned char pad0x29[3];
    int nCompellingOrbGUID;
    int nSpawnCount;
    int nMonstersLeftToKill;
};

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestState, int nFlag);

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

void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, void* pData, QUESTITERATE pfnCallback); // 0x005537D0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2Act2Quest5Strc
{
    unsigned char bSummonerKilled;
    unsigned char unk0x01;
    unsigned short pad0x02;
    D2ActiveRoomStrc* pRoom;
    unsigned char bStatusTimerStarted;
    unsigned char unk0x09;
    unsigned short pad0x0A;
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    char unk0x01[0x07];
    unsigned char bInitJerhynActivated;
    unsigned char bTyraelActivated;
    unsigned char bEndJerhynActivated;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct2Q5NpcMessages[]; // 0x0073AF68
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
bool __fastcall ACT2Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059BB40
void __fastcall ACT2Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BBC0
void __fastcall ACT2Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BD70
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BE70
void __fastcall ACT2Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BF70
bool __fastcall ACT2Q5_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059BFD0
int __fastcall sub_0059C6C0_ACT2Q6_UpdateRewardFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused); // 0x0059C6C0
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C920

// 0x0059BF70
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q5_TRAVINCAL);
    if (!pQuestData || !pQuestData->bNotIntro)
        return;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMonstersSpawned = 1;
    if (pQuestDataEx->nSpawnCount >= 6)
        return;

    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nSpawnCount; ++i)
    {
        if (pQuestDataEx->nMonsterGUIDs[i] == nUnitId)
            return;
    }

    pQuestDataEx->nMonsterGUIDs[pQuestDataEx->nSpawnCount] = nUnitId;
    ++pQuestDataEx->nSpawnCount;
    pQuestDataEx->nMonstersLeftToKill = pQuestDataEx->nSpawnCount;

    if (pQuestData->fState <= 1)
    {
        if (pQuestData->fLastState != 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        if (pQuestData->fLastState != 3)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }

    if (QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q1, QFLAG_PRIMARYGOALDONE) == 1)
        QUESTS_StateDebug(pQuestData, 4, gszAct3Q5SourceFile, 630);
    else
        QUESTS_StateDebug(pQuestData, 5, gszAct3Q5SourceFile, 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x0059C020
void __fastcall sub_0059C020_ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 12))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 1)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 13, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 13, 1);
}

// 0x0059C0A0
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, sub_0059C020_ACT2Q5_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x0059C0F0
int __fastcall ACT2Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 13, 14);
        QUESTS_SendLogUpdateEx(pUnit, 12, 0);
    }

    return 0;
}

// 0x0059C150
void __fastcall ACT2Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "killed summoner for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x1BE);
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x1BF);

        D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bStatusTimerStarted)
        {
            pQuestDataEx->bStatusTimerStarted = 1;
            QUESTS_CreateTimer(pQuestData, ACT2Q5_Timer_StatusCycler, 3);
        }

        pQuestDataEx->unk0x09 = 0;
        pQuestDataEx->bSummonerKilled = 1;
        pQuestDataEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetPrimaryGoalDone);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetCompletionFlag);
    }

    QUESTS_TriggerFX(pQuestData->pGame, 7);
}

// 0x0059C200
void __fastcall ACT2Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro && pQuestArg->nNewLevel >= 40 && pQuestArg->nOldLevel == 40)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}

// 0x0059C220
void __fastcall ACT2Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 2) != 1)
    {
        return;
    }

    pQuestData->fLastState = 2;
    pQuestData->fState = 1;
}

// 0x0059C280
void __fastcall ACT2Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct2Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x212, 0);
    pQuestData->pfCallback[0] = ACT2Q5_Callback00_NpcActivate;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = 13;
    pQuestData->nInitNo = 2;
    pQuestData->pfActiveFilter = ACT2Q5_ActiveFilterCallback;
    pQuestData->pfCallback[3] = ACT2Q5_Callback03_ChangedLevel;
    pQuestData->pfCallback[11] = ACT2Q5_Callback11_ScrollMessage;
    pQuestData->pfCallback[10] = ACT2Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[13] = ACT2Q5_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[8] = ACT2Q5_Callback08_MonsterKilled;

    pQuestDataEx->bSummonerKilled = 0;
    pQuestDataEx->unk0x01 = 0;
    pQuestDataEx->bStatusTimerStarted = 0;
    pQuestDataEx->pRoom = 0;
}

// 0x0059C650
int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 13);
    }

    return 0;
}

// 0x0059C710
int __fastcall ACT2Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        SUNIT_AttachSound(pUnit, 54, pUnit);
    }

    return 0;
}

// 0x0059C760
void __fastcall ACT2Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if ((short)nNpcId == 251)
    {
        if (pQuestDataEx->bTyraelActivated == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTyraelActivated = 0;
            pQuestData->pfCallback[2] = 0;
        }
    }
    else if ((short)nNpcId == 201)
    {
        if (pQuestDataEx->bInitJerhynActivated == 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bInitJerhynActivated = 0;
        }
        else
        {
            if (pQuestDataEx->bEndJerhynActivated != 1)
            {
                return;
            }

            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 6, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bEndJerhynActivated = 0;
        }

        pQuestData->pfCallback[2] = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, (QUESTUNITITERATE)sub_0059C6C0_ACT2Q6_UpdateRewardFlags);
    }
}

// 0x0059C9A0
int __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x0059C9F0
int __fastcall ACT2Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 14);
        QUESTS_SendLogUpdateEx(pUnit, 13, 0);
    }

    return 0;
}

// 0x0059CEE0
bool __fastcall sub_0059CEE0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fLastState != 5 && pQuestData->fLastState != 4 && pQuestData->fLastState != 3)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->unk0x00 = 0;
    return true;
}

// 0x0059CF20
void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 13))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 5) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) == 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);
    }
}

// 0x0059CFB0
int __fastcall ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != 73)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 5))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_SetCustom1Flag, 0);
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a2q5.inc"
