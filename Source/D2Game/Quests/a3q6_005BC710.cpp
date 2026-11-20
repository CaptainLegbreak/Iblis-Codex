#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#define QFLAG_PRIMARYGOALDONE 13
#define UNIT_MONSTER 1
#define MONSTER_NATALYA 297
struct D2MapAIPathPositionStrc;
struct D2Act3Quest5Strc;
struct D2ObjInitFnStrc;
struct D2Act3Quest6Strc;


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
    QUESTCALLBACK pCallback[15];
    void* pNPCMessages;
    int eFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    unsigned char bMonstersSpawned;
    unsigned char pad0x06[2];
    int bQuest1RewardGranted;
    unsigned char bOrbSmashed;
    unsigned char bFlailDropped;
    unsigned char bCubeDropped;
    unsigned char pad0x0F;
    int nMonsterGUIDs[6];
    unsigned char bCompellingOrbSpawned;
    unsigned char pad0x29[3];
    int nCompellingOrbGUID;
    int nSpawnCount;
    int nMonstersLeftToKill;
};

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTITERATE pfIterate, bool bIterate);
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestState, int nFlag); // 0x00544760
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, void* pData, QUESTITERATE pfnCallback);
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
bool __fastcall ACT3Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BBFE0
void __fastcall ACT3Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC270
void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC3C0
void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC5A0
void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC710
void __fastcall ACT3Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC8B0
bool __fastcall ACT3Q6_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005BCC60
void __fastcall ACT3Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BCC80
extern "C" char gpAct3Q6NpcMessages[]; // 0x00740EF8

// 0x005BC710
void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x005BB550
void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q5_TRAVINCAL);
    if (!pQuestData || !pQuestData->bNotIntro)
        return;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMonstersSpawned = 1;
    if (pQuestDataEx->nSpawnCount >= 6)
        return;

    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nSpawnCount; ++i)
    {
        if (pQuestDataEx->nMonsterGUIDs[i] == nUnitId)
            return;
    }

    pQuestDataEx->nMonsterGUIDs[pQuestDataEx->nSpawnCount] = nUnitId;
    ++pQuestDataEx->nSpawnCount;
    pQuestDataEx->nMonstersLeftToKill = pQuestDataEx->nSpawnCount;

    if (pQuestData->fState <= 1)
    {
        if (pQuestData->fLastState != 1)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        if (pQuestData->fLastState != 3)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }

    if (QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q1, QFLAG_PRIMARYGOALDONE) == 1)
        QUESTS_StateDebug(pQuestData, 4, gszAct3Q5SourceFile, 630);
    else
        QUESTS_StateDebug(pQuestData, 5, gszAct3Q5SourceFile, 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BCDC0
void __fastcall ACT3Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pCallback[8] = ACT3Q6_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT3Q6_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q6_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q6_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = ACT3Q6_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q6_SeqCallback;
    pQuestData->fState = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A3Q6;
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

#include "gen/data/Source/D2Game/Quests/a3q6_005BC710.inc"
