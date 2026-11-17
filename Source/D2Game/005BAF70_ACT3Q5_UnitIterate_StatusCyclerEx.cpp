typedef int (__stdcall* FARPROC)();
struct D2BitBufferStrc;
struct D2UnitStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
    char unk0xAC[0x10];
    void* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;

    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xD4];
    D2UnitStrc* pRoomNext;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

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

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2Act3Quest5Strc
{
    char unk0x00[0x05];
    unsigned char bMonstersSpawned;
    char unk0x06[0x4A];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern char gpAct3Q5NpcMessages[];                                                                          // 0x007408B8

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

bool __fastcall ACT3Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BAD60
void __fastcall ACT3Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005BAFD0
void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BB120
void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BB210
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB400
bool __fastcall ACT3Q5_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x005BB410
void __fastcall ACT3Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB480
void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BBC00

// 0x005BAF70
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 19);
    }

    return 0;
}

// 0x005BBEB0
void __fastcall ACT3Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct3Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfCallback[8] = ACT3Q5_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT3Q5_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q5_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q5_Callback03_ChangedLevel;
    pQuestData->pfCallback[13] = ACT3Q5_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q5_SeqCallback;
    pQuestData->nSeqId = 20;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = 21;
    pQuestData->pfActiveFilter = ACT3Q5_ActiveFilterCallback;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 1061, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
}

#include "gen/data/Source/D2Game/005BAF70_ACT3Q5_UnitIterate_StatusCyclerEx.inc"
