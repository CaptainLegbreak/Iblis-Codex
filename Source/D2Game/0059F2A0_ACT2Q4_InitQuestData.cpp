struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2Act2Quest4Strc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char bDrognanActivated;
    unsigned char pad0x05[0x48 - 0x05];
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
    unsigned int dwFlags;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern char gpAct2Q4NpcMessages[];                                                                          // 0x0073A638

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
bool __fastcall ACT2Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059ACA0
void __fastcall ACT2Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059AD40
void __fastcall ACT2Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0059AE60
void __fastcall ACT2Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0059AF50
void __fastcall ACT2Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0059B1C0
bool __fastcall ACT2Q4_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x0059B500
void __fastcall ACT2Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059B530
void __fastcall ACT2Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x0059F0C0

// 0x0059F2A0
void __fastcall ACT2Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct2Q4NpcMessages;
    pQuestData->pfCallback[0] = ACT2Q4_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT2Q4_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT2Q4_Callback03_ChangedLevel;
    pQuestData->pfCallback[10] = ACT2Q4_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[2] = ACT2Q4_Callback02_NpcDeactivate;
    pQuestData->pfCallback[13] = ACT2Q4_Callback13_PlayerStartedGame;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->pQuestDataEx = FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 989, 0);
    pQuestData->nQuestFilter = 12;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 5;
    pQuestData->pfActiveFilter = ACT2Q4_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT2Q4_SeqCallback;
    pQuestData->nSeqId = 13;
    QUESTS_ResetPlayerGUIDCount(&pQuestData->tPlayerGUIDs);

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest4Strc));
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->unk0x01 = 0;
    pQuestDataEx->unk0x02 = 0;
    pQuestDataEx->unk0x03 = 0;
    pQuestDataEx->bDrognanActivated = 0;
}

#include "gen/data/Source/D2Game/0059F2A0_ACT2Q4_InitQuestData.inc"
