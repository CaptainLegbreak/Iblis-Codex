extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2Act4Quest2Strc
{
    unsigned char bTalkedToTyrael;
    unsigned char bTimerCreated;
    unsigned char bNeedToSpawnDiablo;
    unsigned char unk0x03;
    unsigned char bNeedToEndGame;
    unsigned char bNeedToWarpPlayers;
    unsigned char bDiabloStartPointInitialized;
    unsigned char pad0x07;
    int nDiabloStartPointObjectGUID;
    unsigned char bSealActivated[5];
    unsigned char bDiabloSpawned;
    unsigned char unused0x12;
    unsigned char bSanctumCleared;
    unsigned char bDiabloKilled;
    unsigned char bClientsSaved;
    unsigned char pad0x16[2];
    unsigned int dwTickCount;
    int nPlayerCount;
    D2UnitStrc* unk0x20;
    D2CoordStrc pSealCoords[3];
    D2ActiveRoomStrc* pRoom;
    int nLastLastPortalObjectMode;
    unsigned char unk0x44;
    unsigned char bPortalToAct5Spawned;
    unsigned char pad0x46[2];
    int nBossesKilled;
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

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
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

#define QUEST_A4Q2_DIABLO 23
#define QUESTSTATEFLAG_A4Q2 26
#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_MONSTERKILLED 8
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTEVENT_PLAYERSTARTEDGAME 13
#define QUESTEVENT_PLAYERJOINEDGAME 14
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM5 9
#define QFLAG_COMPLETEDBEFORE 15
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2

extern int gpAct4Q2NpcMessages[];                                                                           // 0x0073DBB8

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
bool __fastcall ACT4Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B4450
bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData);                                           // 0x005B4530
void __fastcall ACT4Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005B4670
void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005B4790
void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005B4EA0
void __fastcall ACT4Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005B4F90
void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005B52E0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0

inline D2BitBufferStrc* ACT4Q2_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B5030
void __fastcall ACT4Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    if (!pGame->bExpansion)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }
}

// 0x005B5080
void __fastcall ACT4Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = ACT4Q2_GetQuestFlagsInline(pQuestArg->pGame, pQuestArg->pPlayer);

    if (pQuestArg->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B54C0
void __fastcall ACT4Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT4Q2_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT4Q2_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT4Q2_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT4Q2_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT4Q2_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT4Q2_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[QUESTEVENT_PLAYERJOINEDGAME] = ACT4Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct4Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A4Q2;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q2_ActiveFilterCallback;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1048, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q2_SeqCallback;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest2Strc));
}

// 0x005B5840
void __fastcall OBJECTS_InitFunction78_LastLastPortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A4Q2_DIABLO);
    if (!pQuestData)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nLastLastPortalObjectMode != OBJMODE_OPENED)
    {
        pQuestDataEx->nLastLastPortalObjectMode = OBJMODE_OPENED;
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

#include "gen/data/Source/D2Game/005B5030_ACT4Q2_Callback14_PlayerJoinedGame.inc"
