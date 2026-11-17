struct D2ActiveRoomStrc;
struct D2MapAIPathPositionStrc;
struct D2BitBufferStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};
struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};
struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C[2];
    int nX;
    int nY;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                       // 0x0058F000
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);               // 0x00666120

bool __fastcall ACT3Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BBFE0
void __fastcall ACT3Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x005BC270
void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x005BC3C0
void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BC5A0
void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC710
void __fastcall ACT3Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BC8B0
bool __fastcall ACT3Q6_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x005BCC60
void __fastcall ACT3Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BCC80
extern "C" char gpAct3Q6NpcMessages[];                                                                       // 0x00740EF8

#define QUESTSTATEFLAG_A3Q6 22
#define QFLAG_PRIMARYGOALDONE 13
#define QUEST_A3Q6_MEPHISTO 20
#define UNIT_MONSTER 1
#define MONSTER_NATALYA 297

// 0x005BCDC0
void __fastcall ACT3Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pNPCMessages = gpAct3Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfCallback[8] = ACT3Q6_Callback08_MonsterKilled;
    pQuestData->pfCallback[0] = ACT3Q6_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Q6_Callback11_ScrollMessage;
    pQuestData->pfCallback[3] = ACT3Q6_Callback03_ChangedLevel;
    pQuestData->pfCallback[13] = ACT3Q6_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[10] = ACT3Q6_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q6_SeqCallback;
    pQuestData->fState = 0;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A3Q6;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT3Q6_ActiveFilterCallback;

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 896, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest6Strc));
}

// 0x005BCE80
void __fastcall OBJECTS_InitFunction52_NatalyaStart(D2ObjInitFnStrc* pOp)
{
    if (QUESTS_GetGlobalState(pOp->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO)->pQuestDataEx;

    if (pQuestDataEx->bNatalyaSpawned)
    {
        D2UnitStrc* pNatalya = SUNIT_GetServerUnit(pOp->pGame, UNIT_MONSTER, pQuestDataEx->nNatalyaGUID);
        if (pNatalya && pNatalya->dwClassId == MONSTER_NATALYA)
        {
            return;
        }
    }

    D2UnitStrc* pNatalya = D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_NATALYA, 1, -1, 0);
    if (!pNatalya)
    {
        pNatalya = D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_NATALYA, 1, 3, 0);
    }

    if (!pNatalya)
    {
        pQuestDataEx->bNatalyaSpawned = 0;
        return;
    }

    pQuestDataEx->bNatalyaSpawned = 1;
    pQuestDataEx->nNatalyaGUID = !pNatalya ? -1 : pNatalya->dwUnitId;

    if (pNatalya && pQuestDataEx->pNatalyaMapAI && pQuestDataEx->pNatalyaMapAI->pPosition && !pQuestDataEx->bNatalyaMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNatalyaMapAI, AIGENERAL_GetMapAiFromUnit(pNatalya));
        pQuestDataEx->bNatalyaMapAIChanged = 1;
    }
}

#include "gen/data/Source/D2Game/005BCDC0_ACT3Q6_InitQuestData.inc"
