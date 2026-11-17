extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2MapAIStrc
{
    int unk0x00;
    void* pPosition;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
        int nOldLevel;
    };
    union
    {
        unsigned short nMessageIndex;
        int nNewLevel;
    };
};

struct D2QuestDataStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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

struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[5];
    unsigned short unused0x0A;
    unsigned short nCurrentMonolithNo;
    unsigned char pad0x0E[2];
    int nMonolithGUIDs[5];
    int unused0x24;
    int nInvisibleObjectGUID;
    short nCairnStoneInteractions;
    unsigned char pad0x2E[2];
    int nInifussTreeGUID;
    int nCainGibbetGUID;
    int nDecipheredScrollGUID;
    int nPlayerGUID;
    int nCairnStoneAlphaGUID;
    unsigned char bOpenPortalTimerActive;
    unsigned char bPortalToTristramOpened;
    unsigned char bTimerActive;
    unsigned char bInifussTreeInitialized;
    unsigned char bCageModeChanged;
    unsigned char bInvisbleObjectInitialized;
    unsigned char bMonolithStonesOrdered;
    unsigned char unk0x4B;
    unsigned char unk0x4C;
    unsigned char bActivateCairnStones;
    unsigned char bDecipheredScrollAcquired;
    unsigned char bOperatedWithLastCairnStone;
    unsigned char unk0x50;
    unsigned char bCainInTownSpawned;
    unsigned char unk0x52;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    unsigned char bCairnStonesActive[5];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    unsigned char unk0x65[0x4F];
    D2QuestGUIDStrc pQuestGUID;
    D2QuestGUIDStrc tPlayerGUIDs;
};

extern char gpAct1Q4NpcMessages[];                                                                          // 0x00737668
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005921B0
void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00592250
void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00592580
void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592B90
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80
void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592CF0
void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00592E20
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E60
bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00592FB0
bool __fastcall ACT1Q4_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x00593D70
void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00593E70
void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00596DE0
void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00597030

// 0x005971B0
void __fastcall ACT1Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[3] = ACT1Q4_Callback03_ChangedLevel;
    pQuestData->pfCallback[4] = ACT1Q4_Callback04_ItemPickedUp;
    pQuestData->pfCallback[6] = ACT1Q4_Callback06_ResetInifussTree;
    pQuestData->pfCallback[14] = ACT1Q4_Callback14_PlayerJoinedGame;
    pQuestData->pfCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pfCallback[8] = ACT1Q4_Callback08_MonsterKilled;
    pQuestData->pNPCMessages = gpAct1Q4NpcMessages;
    pQuestData->nQuestFilter = 4;
    pQuestData->fLastState = 0;
    pQuestData->bActive = 1;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 6;
    pQuestData->pfActiveFilter = ACT1Q4_ActiveFilterCallback;
    pQuestData->pfCallback[0] = ACT1Q4_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT1Q4_Callback11_ScrollMessage;
    pQuestData->pfCallback[10] = ACT1Q4_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[2] = ACT1Q4_Callback02_NpcDeactivate;
    pQuestData->pfCallback[13] = ACT1Q4_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q4_SeqCallback;
    pQuestData->nSeqId = 3;

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 2399, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest4Strc));

    pQuestDataEx->nCurrentMonolithNo = 0;
    pQuestDataEx->bMonolithStonesOrdered = 0;
    pQuestDataEx->bDecipheredScrollAcquired = 0;
    pQuestDataEx->unk0x4B = 0;
    pQuestDataEx->nCairnStoneInteractions = 0;
    pQuestDataEx->nInvisibleObjectGUID = 0;
    pQuestDataEx->bInvisbleObjectInitialized = 0;
    pQuestDataEx->nInifussTreeGUID = 0;
    pQuestDataEx->nDecipheredScrollGUID = 0;
    pQuestDataEx->bInifussTreeInitialized = 0;
    pQuestDataEx->bTimerActive = 0;
    pQuestDataEx->unk0x58 = 0;
    pQuestDataEx->nCainGibbetObjectMode = 0;
    pQuestDataEx->unk0x50 = 0;
    pQuestDataEx->bCairnStonesActive[0] = 0;
    pQuestDataEx->bCairnStonesActive[1] = 0;
    pQuestDataEx->bCairnStonesActive[2] = 0;
    pQuestDataEx->bCairnStonesActive[3] = 0;
    pQuestDataEx->bCairnStonesActive[4] = 0;
    pQuestDataEx->bCainInTownSpawned = 0;
    pQuestDataEx->unk0x52 = 0;
    pQuestDataEx->bCainRemovedFromTristram = 0;
    pQuestDataEx->bCainNotCreated = 0;
    pQuestDataEx->bAkaraIntroActivated = 0;
    pQuestDataEx->bAkaraActivatedForScroll = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pQuestGUID);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/005971B0_ACT1Q4_InitQuestData.inc"
