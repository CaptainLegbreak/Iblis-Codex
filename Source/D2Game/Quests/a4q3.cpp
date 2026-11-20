#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A4Q3_HELLFORGE 24
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_CUSTOM1 5
struct D2PlayerDataStrc;
struct D2Act4Quest3Strc;
struct D2QuestGUIDStrc;
struct D2Act3Quest3Strc;
struct D2Act3Quest4Strc;
struct D2Act3Quest5Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C



struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
    char pad0x1C[0x30];
    int bBusy;
};

struct D2Act4Quest3Strc
{
    char pad0x00[0x02];
    unsigned char bCainActivated;
    char pad0x03[0x0D];
    int nHellforgeHammersInGame;
    int nPlayersInAct;
    int unused0x18;
    unsigned char bSoulstoneAcquired;
    unsigned char pad0x1D[3];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

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
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    D2TextHeaderStrc* pTextControl;
    unsigned short nMessageIndex;
    unsigned char unk_1A[0x2];
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pUnit, int nQuestId, int a3); // 0x00545920
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    char pad0x03[0x19];
    int nGidbinnsInGame;
    unsigned char bPlayerWithGidbinnDropped;
    char pad0x21[0x0B];
    int nAltarObjectMode;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
    unsigned char unk0x01;
    unsigned char unk0x02;
    char pad0x03[0x09];
    unsigned char unk0x0C;
    char pad0x0D[0x03];
    int nGoldenBirdsInGame;
    unsigned char bJadeFigurineDropped;
    unsigned char bPlayerDroppedWithItem;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    char pad0x05[0x07];
    unsigned char bOrbSmashed;
};
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall ACT3Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B9E70

// 0x005B59C0
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A4Q3_HELLFORGE);
    }

    return 0;
}

// 0x005B5A90
void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING)
        || !pQuestData->bNotIntro || pQuestData->fLastState == 13)
    {
        return;
    }

    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 135);
    }
}

// 0x005B5B00
void __fastcall ACT4Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_IV)
    {
        return;
    }

    QUESTS_DeleteItem(pGame, pUnit, ' hfh');
    QUESTS_DeleteItem(pGame, pUnit, ' ssm');
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, QUESTSTATEFLAG_A4Q3);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A4Q3_HELLFORGE);
    if (pQuestData)
    {
        ++((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->nPlayersInAct;
    }
}

// 0x005B5BB0
int __fastcall ACT4Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDNOW);
    QUESTS_SendLogUpdateEx(pUnit, QUEST_A4Q3_HELLFORGE, 0);
    return 0;
}

// 0x005B5F40
bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 341);
        return true;
    }

    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 349);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B5FC0
int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A4Q3_HELLFORGE);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        if (((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_CUSTOM1);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_STARTED);
        }
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x005B64E0
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' hfh'))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 15))
    {
        return;
    }

    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
    {
        pQuestData->fState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 5) == 1)
    {
        ((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired = 1;
        pQuestData->fLastState = 4;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
}

// 0x005B72B0
bool __fastcall ACT3Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 254)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 15))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' bbb'))
        {
            return true;
        }
    }

    return false;
}

// 0x005B8CC0
bool __fastcall ACT3Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 19, 13) ? 13 : 11;
        return true;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;

    *pStatus = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
    {
        *pStatus = 4;
        return true;
    }

    if (pQuestDataEx->bPlayerWithGidbinnDropped)
    {
        *pStatus = (pQuest->pGame->nGameType == 3) + 7;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 6))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 8))
        {
            *pStatus = 6;
        }
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 7))
        {
            *pStatus = 5;
        }
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 4))
    {
        *pStatus = (pQuestDataEx->bGidbinnDropped == 1) + 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 3))
    {
        *pStatus = 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 2))
    {
        *pStatus = 1;
    }

    return true;
}

// 0x005BA9E0
void __fastcall ACT3Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    bool bGoldAcquired = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
    {
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g'))
    {
        bGoldAcquired = true;
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (pQuestDataEx->nGoldenBirdsInGame != 1 || !pQuestData->bNotIntro || !pQuestDataEx->bPlayerDroppedWithItem)
    {
        return;
    }

    pQuestDataEx->bPlayerDroppedWithItem = 0;
    pQuestData->dwFlags &= 0xFFFFFF00;

    int nState = 1;
    if (bGoldAcquired)
    {
        nState = 3;
    }

    QUESTS_UnitIterate(pQuestData, nState, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
}

// 0x005BAB60
void __fastcall ACT3Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 852);

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro || !pQuestDataEx->unk0x02 || !pQuestDataEx->unk0x0C)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    if (pPlayer)
    {
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0))
        {
            return;
        }
    }

    pQuestArg->pTarget->dwDropItemCode = ' 43j';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestData->pfCallback[8] = 0;
        pQuestDataEx->unk0x0C = 0;
        pQuestDataEx->bJadeFigurineDropped = 1;
        ++pQuestDataEx->nGoldenBirdsInGame;
        if (pQuestData->fState < 1)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 879);
        }

        if (!pQuestData->fLastState)
        {
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->unk0x02 = 0;
            return;
        }
    }
    else
    {
        pQuestDataEx->unk0x01 = 1;
    }
    pQuestDataEx->unk0x02 = 0;
}

// 0x005BBE20
bool __fastcall sub_005BBE20(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    *pStatus = pQuest->fLastState;
    if (QUESTRECORD_GetQuestState(pFlags, 21, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 21, 13) ? 13 : 11;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 21, 4))
    {
        *pStatus = ((D2Act3Quest5Strc*)pQuest->pQuestDataEx)->bOrbSmashed ? 13 : 4;
    }

    if (!pQuest->bNotIntro)
    {
        *pStatus = 0;
    }

    return true;
}
