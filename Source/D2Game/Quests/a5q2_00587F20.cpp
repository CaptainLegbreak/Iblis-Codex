#include "D2Game.h"

#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_I 0
#define ACT_III 2
#define QUESTSTATEFLAG_A1Q1 1
#define nullptr 0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest1Strc;
struct D2ObjInitFnStrc;
struct D2Act5Quest2Strc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x6D - 0x20];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned short dwClassId;
    unsigned short unk0x06;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xC4 - 0x14];
    unsigned int dwFlags;
    char unk0xC8[0xE8 - 0xC8];
    D2UnitStrc* pRoomNext;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    union
    {
        unsigned int dwFlags;
        unsigned char bStatusFlags;
    };
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

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

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs);
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate);
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate);
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);

struct D2Act1Quest1Strc
{
    D2QuestGUIDStrc pQuestGUID;
    char unk0x84[0x03];
    unsigned char bTimerActive;
};

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef int (__stdcall* FARPROC)();

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    void* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

struct D2Act5Quest2Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    unsigned char bQualKehkActivated;
    char unk0x85[0xA8 - 0x85];
    int nKilledWussies;
    int nFreedWussies;
    int nWussieGUIDs[3][5];
    int nPortalGUIDs[3];
    unsigned char bPortalSpawned[3];
    unsigned char pad0xFB;
    int nPortalUpdateInvocations[3];
    unsigned char unk0x108[3];
    unsigned char bChangeToSpecialObjectMode[3];
    unsigned char unk0x10E[6];
    int unk0x114[3];
    int nFreedWussieUnitGUIDs[15];
    int nWussiesInRangeToDoor;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct5Q2NpcMessages[]; // 0x00733940
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587A30
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587A90
void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587B00
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587D30
void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587E60
void __fastcall ACT5Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587F20
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587F60
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0
bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00588340
void __fastcall ACT5Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00588040
void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

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

int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 35, pUnit);
    }

    return 0;
}

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

// 0x00587F20
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

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

// 0x00588200
void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    switch (pQuestArg->nNewLevel)
    {
    case 111:
    case 112:
        if (!pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            break;
        }

        bool bWasStarted = false;
        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 632);
            bWasStarted = true;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, nullptr, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pfCallback[2] = nullptr;
        }
        else if (!bWasStarted)
        {
            return;
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, nullptr, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        return;
    }

    if (nOldLevel == 109)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 660);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, nullptr, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        if (pQuestData->fLastState || !pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            return;
        }

        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, nullptr, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pfCallback[2] = nullptr;
    }
}

// 0x005883E0
bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }

        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 717);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00588450
void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, 36, 4);
}

// 0x00588470
void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->nQuestFilter, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00588510
void __fastcall ACT5Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[10] = ACT5Q2_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[3] = ACT5Q2_Callback03_ChangedLevel;
    pQuestData->pfCallback[8] = ACT5Q2_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT5Q2_Callback00_NpcActivate;
    pQuestData->pfCallback[2] = ACT5Q2_Callback02_NpcDeactivate;
    pQuestData->pfCallback[11] = ACT5Q2_Callback11_ScrollMessage;
    pQuestData->pfCallback[13] = ACT5Q2_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[14] = ACT5Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = 36;
    pQuestData->pfStatusFilter = nullptr;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q2_SeqCallback;
    pQuestData->nSeqId = 33;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest2Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x005887A0
int __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q2_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x005887F0
int __fastcall ACT5Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        SUNIT_AttachSound(pUnit, 81, pUnit);
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a5q2_00587F20.inc"
