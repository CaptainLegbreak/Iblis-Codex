extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BitBufferStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
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
    char unk0x06[0x6];
    int dwUnitId;
};

struct D2QuestGUIDStrc
{
    int nGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char unk0x82[2];
};

struct D2Act1Quest2Strc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char bBloodravenKilled;
    unsigned char bKashyaActivated;
    int unk0x04;
    int nBloodravenGUID;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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
    char pad0x0E[0x2];
    int nSeqId;
    unsigned char nFlags;
    unsigned char unk0x15[0x3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char pad0xE4[0x4];
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
    char pad0x10[0x4];
    union
    {
        int nOldLevel;
        struct
        {
            unsigned short nNPCNo;
            unsigned short unk0x16;
            unsigned short nMessageIndex;
            unsigned short unk0x1A;
        };
    };
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430

extern "C" const char gszA1Q2SourceFile[];                                                                  // 0x006E1B98
extern char gpAct1Q2NpcMessages[];                                                                          // 0x00736CE8
void __fastcall ACT1Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00590980
void __fastcall ACT1Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00590B10
void __fastcall ACT1Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00590920
void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590C10
void __fastcall ACT1Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00590EC0
void __fastcall ACT1Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00590FA0
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591080
bool __fastcall ACT1Q2_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT1Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_PLAYERLEAVESGAME 10
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTEVENT_PLAYERSTARTEDGAME 13

#define QUESTEVENT_MONSTERKILLED 8

#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDBEFORE 15
#define QUESTSTATEFLAG_A1Q2 2
#define QSTATE_2 2
#define QSTATE_3 3
#define QSTATE_5 5
#define A1Q2_INITNO 4
#define A1Q2_SEQID 4
#define LINE_SEQ_DEBUG 0x230
#define LINE_SEQ_ASSERT 0x23B
#define LINE_INIT_ALLOC 0x27F
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
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
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
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q2_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT1Q2_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q2_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q2_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q2_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q2_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q2_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q2_SeqCallback;
    pQuestData->pNPCMessages = gpAct1Q2NpcMessages;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A1Q2;
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

#include "gen/data/Source/D2Game/005910F0_ACT1Q2_SeqCallback.inc"
