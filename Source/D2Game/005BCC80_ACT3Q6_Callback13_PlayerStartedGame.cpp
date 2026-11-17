struct D2MapAIPathPositionStrc;
struct D2BitBufferStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;
struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
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

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, int nStatus);
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
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted;
    unsigned char bHellGatePortalInitialized;
    unsigned char bMephistoBridgeInitialized;
    unsigned char bOrmusActivated;
    int nHellGatePortalGUID;
    int nMephistoBridgeGUID;
    int nHellGatePortalObjectMode;
    int nMephistoBridgeObjectMode;
    int nSoulStonesDropped;
    unsigned char bSoulStoneDropped;
    unsigned char pad0x19[3];
    int nSoulstonesToDrop;
    unsigned char bNatalyaSpawned;
    unsigned char pad0x21[3];
    D2MapAIStrc* pNatalyaMapAI;
    unsigned char unused0x28[4];
    int nNatalyaGUID;
    unsigned char bNatalyaMapAIChanged;
    unsigned char pad0x31[3];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720

#define QUESTSTATEFLAG_A3Q6 22
#define QUESTSTATEFLAG_A3COMPLETED 23
#define QFLAG_PRIMARYGOALDONE 13
#define OBJMODE_OPENED 2

// 0x005BCC80
void __fastcall ACT3Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 11) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3COMPLETED, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);
        ((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nHellGatePortalObjectMode = OBJMODE_OPENED;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 9) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 4;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 8) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 7) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 6) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 4;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 5) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 4) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 3) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 2) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 2;
    }
}
