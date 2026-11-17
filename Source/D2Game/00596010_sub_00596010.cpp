extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    int nGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char unk0x82[2];
};

struct D2Act1Quest6Strc
{
    D2QuestGUIDStrc pGUID1;
    D2QuestGUIDStrc pGUID2;
    D2QuestGUIDStrc pGUID3;
    int nAndarielGUID;
    unsigned short unk0x190;
    unsigned short nTimerInvocations;
    unsigned char bAndarielKilled;
    unsigned char bCainActivated;
    unsigned char pad0x196[2];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

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
    D2Act1Quest6Strc* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
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
    int unk10;
    int oldLevel;
    int newLevel;
};

#define UNIT_MONSTER 1
#define QUEST_A1Q6_ANDARIEL 6
#define QUESTSTATEFLAG_A1Q6 6
#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_MONSTERKILLED 8
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTEVENT_PLAYERSTARTEDGAME 13
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15

extern int gpAct1Q6NpcMessages[];                                                                           // 0x007382E0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);            // 0x00545530
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pUnit, int nQuestId, int a3);                            // 0x00545920
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00595B20
void __fastcall ACT1Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00595B80
void __fastcall ACT1Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00595C60
void __fastcall ACT1Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00595E20
void __fastcall ACT1Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00596010
void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00596320
int __fastcall ACT1Q6_UnitIterate_CreatePortalToTown(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);   // 0x00596490
void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005965A0
bool __fastcall ACT1Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005967F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

void __fastcall sub_00544070(D2GameStrc*,const char*,const char*,int);  // 0x00544070
void __fastcall sub_00545310(D2QuestDataStrc*);  // 0x00545310
int __fastcall sub_00595BD0(D2GameStrc*,D2UnitStrc*,void*);  // 0x00595BD0
static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* game,D2UnitStrc* player)
{
 return UNITS_GetPlayerData(player)->pQuestData[game->nDifficulty];
}
// 0x00596010
void __fastcall sub_00596010(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
 const int oldLevel=arg->oldLevel;
 const int newLevel=arg->newLevel;
 if((unsigned)(newLevel-34)<=3 && q->bNotIntro) {
  bool changed=false;
  if(q->fState<3) {
   QUESTS_StateDebug(q,3,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",358);
   changed=true;
  }
  if(newLevel==37) {
   if(q->fLastState<2) {
    *(unsigned char*)&q->dwFlags=0;
    QUESTS_UnitIterate(q,2,0,ACT1Q6_UnitIterate_StatusCyclerEx,true);
    changed=true;
   }
  } else if(!q->fLastState) {
   *(unsigned char*)&q->dwFlags=0;
   QUESTS_UnitIterate(q,1,0,ACT1Q6_UnitIterate_StatusCyclerEx,false);
   changed=true;
  }
  if(changed) SUNIT_IterateUnitsOfType(q->pGame,0,0,sub_00595BD0);
  sub_00544070(arg->pGame,"started quest by jumping to level","d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",384);
  return;
 }
 if(q->fState==4 && newLevel==40) {
  QUESTS_StateDebug(q,5,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",391);
  return;
 }
 if(oldLevel==1) {
  sub_00545310(q);
  if(q->fState==2) {
   D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
   if(QUESTRECORD_GetQuestState(flags,q->nQuestFilter,0)!=1 && QUESTRECORD_GetQuestState(flags,q->nQuestFilter,1)!=1) {
    QUESTS_StateDebug(q,3,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",405);
    SUNIT_IterateUnitsOfType(q->pGame,0,0,sub_00595BD0);
   }
  }
 }
}
