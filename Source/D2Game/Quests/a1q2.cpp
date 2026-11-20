#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#define LEVEL_ROGUEENCAMPMENT 1
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDBEFORE 15
#define QUESTSTATEFLAG_A1Q2 2
#define A1Q2_INITNO 4
#define A1Q2_SEQID 4
#define LINE_SEQ_DEBUG 0x230
#define LINE_SEQ_ASSERT 0x23B
#define LINE_INIT_ALLOC 0x27F
struct D2NPCMessageTableStrc;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest2Strc;



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


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    QUESTCALLBACK pCallback[15];
    void* pNPCMessages;
    int eFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590830
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2Act1Quest2Strc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char bBloodravenKilled;
    unsigned char bKashyaActivated;
    int unk0x04;
    int nBloodravenGUID;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern char gpAct1Q2NpcMessages[]; // 0x00736CE8
void __fastcall ACT1Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590980
void __fastcall ACT1Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590B10
void __fastcall ACT1Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590920
void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590C10
void __fastcall sub_00590EC0_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590EC0
void __fastcall ACT1Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590FA0
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591080
bool __fastcall ACT1Q2_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT1Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

// 0x00590FA0
void __fastcall ACT1Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == LEVEL_BURIALGROUNDS && pQuestData->bNotIntro == 1)
    {
        bool bStateUpdated = false;
        if (pQuestData->fState < 3)
        {
            QUESTS_StateDebug(pQuestData, 3, gszA1Q2SourceFile, 489);
            pQuestData->bStatusFlags = 0;
            bStateUpdated = true;
        }

        if (pQuestData->fLastState == 1 || !pQuestData->fLastState)
        {
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
            bStateUpdated = true;
        }

        if (bStateUpdated)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
            return;
        }
    }

    if (nOldLevel != LEVEL_ROGUEENCAMPMENT)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return;
        }
    }

    QUESTS_StateDebug(pQuestData, 3, gszA1Q2SourceFile, 519);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
}

// 0x005910F0
bool __fastcall ACT1Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, gszA1Q2SourceFile, LINE_SEQ_DEBUG);
        return true;
    }

    if (pQuestData->fState != QSTATE_5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SEQ_ASSERT);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00591180
void __fastcall ACT1Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = QSTATE_2;
        pQuestData->fState = QSTATE_3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = QSTATE_3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = QSTATE_2;
        pQuestData->fLastState = 1;
    }
}

// 0x00591210
void __fastcall ACT1Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = sub_00590EC0_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q2_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q2_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q2_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q2_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q2_SeqCallback;
    pQuestData->pNPCMessages = gpAct1Q2NpcMessages;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q2;
    pQuestData->bActive = 1;

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest2Strc), gszA1Q2SourceFile, LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = A1Q2_INITNO;
    pQuestData->nSeqId = A1Q2_SEQID;
    pQuestData->pfActiveFilter = ACT1Q2_ActiveFilterCallback;

    pQuestDataEx->unk0x01 = 0;
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->bKashyaActivated = 0;
    pQuestDataEx->bBloodravenKilled = 0;
    pQuestDataEx->nBloodravenGUID = 0;

    pQuestData->fState = 0;
}

#include "gen/data/Source/D2Game/Quests/a1q2.inc"
