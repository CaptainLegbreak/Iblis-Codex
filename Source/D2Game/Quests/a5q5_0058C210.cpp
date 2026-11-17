#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUESTSTATEFLAG_A5Q5 39
#define QUEST_A5Q5_ANCIENTS 35
#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_MONSTERKILLED 8
#define QUESTEVENT_PLAYERLEAVESGAME 10
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTEVENT_PLAYERSTARTEDGAME 13
#define QFLAG_REWARDGRANTED 0
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define STAT_LEVEL 12
struct D2PlayerDataStrc;
struct D2Act5Quest5Strc;
struct D2QuestGUIDStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    union
    {
        unsigned char nDifficulty;
        unsigned char difficulty;
    };
    unsigned char unk_6E[0x2];
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
    union
    {
        D2BitBufferStrc* pQuestData[3];
        D2BitBufferStrc* flags[3];
    };
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char activated;
    unsigned char unused0x02[2];
    unsigned char bTimerActive;
    unsigned char unused0x05[7];
    int portals;
    unsigned char active;
    unsigned char activatable;
    unsigned char pad0x12[2];
    int nAncientStatueGUID[3];
    int nAncientMonsterGUID[3];
    unsigned char bAncientMonsterSpawned[3];
    unsigned char pad0x2F;
    int modes[3];
    unsigned char bAncienStatueRespawned[3];
    unsigned char pad0x3F;
    int nAncientsSpawned;
    int nAncientsAlive;
    unsigned char unk0x48[2];
    unsigned char bQuestCompletedBefore;
    unsigned char unk0x4B[0x19];
};

struct D2QuestGUIDStrc
{
    char data[0x84];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    union
    {
        D2GameStrc* pGame;
        D2GameStrc* game;
    };
    unsigned char nActNo;
    union
    {
        unsigned char bNotIntro;
        unsigned char intro;
    };
    union
    {
        unsigned char bActive;
        unsigned char active;
    };
    union
    {
        unsigned char fLastState;
        unsigned char last;
    };
    union
    {
        unsigned char fState;
        unsigned char state;
    };
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int flags;
    union
    {
        D2Act5Quest5Strc* pQuestDataEx;
        D2Act5Quest5Strc* ex;
    };
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    union
    {
        int nQuestFilter;
        int filter;
    };
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
    union
    {
        D2UnitStrc* pPlayer;
        D2UnitStrc* player;
    };
    char pad10[4];
    unsigned short npc;
    char pad16[2];
    short message;
    unsigned char unk_1A[0x2];
};

extern int gpAct5Q5NpcMessages[]; // 0x00735100
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pUnit, int nQuestId, int a3); // 0x00545920
void __fastcall ACT5Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058BE80
void __fastcall ACT5Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C290
void __fastcall ACT5Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C440
void __fastcall ACT5Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C9A0
void __fastcall ACT5Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058CBA0
bool __fastcall ACT5Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058CCF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

typedef int (__fastcall *Iter)(D2GameStrc*,D2UnitStrc*,void*);

void __fastcall QUESTS_StateDebug(D2QuestDataStrc*,int,const char*,int); // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*,int,int,Iter,int); // 0x00544300
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc*,D2UnitStrc*,void*); // 0x0058BE20
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*,int,void*,Iter); // 0x005537D0
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc*,D2UnitStrc*,void*); // 0x0058C210
int __stdcall sub_0058BF40_ActivateAncientStatues(D2QuestDataStrc*,D2Act5Quest5Strc*); // 0x0058BF40
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*,int,int); // 0x0065C360
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520
extern const char gszA5Q5SourceFile[]; // 0x006E1ABC

// 0x0058C210
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) == 1 || STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x0058C750
void __fastcall ACT5Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x0058C780
int __fastcall ACT5Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A5Q5_ANCIENTS, 0);
    }

    return 0;
}

// 0x0058CD30
bool __fastcall ACT5Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 981);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x0058CDA0
void __fastcall ACT5Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
    {
        pQuestData->pQuestDataEx->bQuestCompletedBefore = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
}

// 0x0058CE30
void __fastcall ACT5Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT5Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT5Q5_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT5Q5_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT5Q5_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT5Q5_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT5Q5_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT5Q5_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct5Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 1053, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A5Q5;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q5_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q5_SeqCallback;
    pQuestData->nSeqId = 36;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest5Strc));
}

#include "gen/data/Source/D2Game/Quests/a5q5_0058C210.inc"

// 0x0058C290
void __fastcall ACT5Q5_Callback11_ScrollMessage(D2QuestDataStrc* q,D2QuestArgStrc* a)
{
 short msg=a->message;
 unsigned short npc=a->npc;
 D2Act5Quest5Strc* ex=q->ex;
 if(msg==20153){
  if(npc==515){
   if(!q->intro||q->state!=1)return;
   QUESTS_StateDebug(q,2,gszA5Q5SourceFile,413);
   if(q->last!=1){q->flags&=0xFFFFFF00;QUESTS_UnitIterate(q,1,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
   SUNIT_IterateUnitsOfType(q->game,0,0,ACT5Q5_UnitIterate_UpdateQuestStateFlags);
   ex->activated=1;return;
  }
 }else if(msg==20002){
  if(q->intro&&q->state<4&&q->last!=3){q->flags&=0xFFFFFF00;QUESTS_UnitIterate(q,3,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
  if(ex->portals>0)return;
  for(int i=0;i<3;++i)if(ex->modes[i])return;
  if(sub_0058BF40_ActivateAncientStatues(q,ex)){ex->active=1;ex->activatable=1;}
  return;
 }else if(msg==20169){
 D2GameStrc* game=q->game;
 D2BitBufferStrc* pQuestFlags=UNITS_GetPlayerData(!a ? 0 : a->player)->flags[game->difficulty];
 QUESTRECORD_SetQuestState(pQuestFlags,39,4);
 return;}
 switch(npc){
 case 511: if(msg==20167)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,5);break;
 case 520: if(msg==20165)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,6);break;
 case 512: if(msg==20166)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,7);break;
 case 513: if(msg==20168)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,8);break;
 case 515: if(msg==20164)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,9);break;
 }
}
