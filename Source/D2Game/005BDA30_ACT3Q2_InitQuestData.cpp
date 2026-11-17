struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2QuestArgStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
};

struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

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

struct D2Act3Quest2Strc
{
    char unk0x00[0x08];
    int nSewerStairsObjectMode;
    char unk0x0C[0x2C - 0x0C];
    D2QuestGUIDStrc tPlayerGUIDs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern char gpAct3Q2NpcMessages[];                                                                          // 0x0073F1A0
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall sub_005B7FE0_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);         // 0x005B7FE0
void __fastcall ACT3Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005B7FF0
void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005B8060
bool __fastcall ACT3Q2_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x005B8150
void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005B8210
void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8470
bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BD500
void __fastcall ACT3Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005BD630
bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BD850

// 0x005BDA30
void __fastcall ACT3Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->bActive = 1;
    pQuestData->fLastState = 1;
    pQuestData->pNPCMessages = gpAct3Q2NpcMessages;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = 18;
    pQuestData->nInitNo = 0;
    pQuestData->pfStatusFilter = ACT3Q2_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q2_SeqCallback;
    pQuestData->nSeqId = 15;
    pQuestData->pfCallback[0] = ACT3Q2_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q2_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q2_Callback03_ChangedLevel;
    pQuestData->pfCallback[13] = ACT3Q2_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[10] = sub_005B7FE0_EmptyCallback;
    pQuestData->pfCallback[4] = ACT3Q2_Callback04_ItemPickedUp;

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 923, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest2Strc));
    pQuestDataEx->nSewerStairsObjectMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/005BDA30_ACT3Q2_InitQuestData.inc"
