extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
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

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short unk0x0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char unk0xE4[0x04];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00;
    unsigned char bDarkenTimerCreated;
    unsigned char bRewarded;
    unsigned char bBlackened;
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    unsigned char unk0x06;
    unsigned char pad0x07;
    int nAltarMode;
    int nAltarGUID;
    D2ActiveRoomStrc* pRoom;
    D2QuestGUIDStrc tPlayerGUIDs;
    int nAltarLevelId;
    int unk0x9C;
};

enum
{
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern char gpAct2Q3NpcMessages[];                                                                          // 0x0073A188
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);                // 0x00544190
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00599FB0
bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059A1C0
void __fastcall ACT2Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x0059A270
bool __fastcall ACT2Q3_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x0059A480
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059A5D0
void __fastcall ACT2Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x0059EBE0
void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0059EE00

// 0x00599F50
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A2Q3_TAINTEDSUN);
    }

    return 0;
}

// 0x00599FE0
int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A2Q3_TAINTEDSUN, 0);
    }

    return 0;
}

// 0x0059EEA0
void __fastcall ACT2Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[0] = ACT2Q3_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT2Q3_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT2Q3_Callback03_ChangedLevel;
    pQuestData->pfCallback[10] = ACT2Q3_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[13] = ACT2Q3_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct2Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A2Q3;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q3_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT2Q3_SeqCallback;
    pQuestData->nSeqId = QUESTSTATEFLAG_A2Q3;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest3Strc));
    pQuestDataEx->nAltarMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/00599F50_ACT2Q3_UnitIterate_StatusCyclerEx.inc"
