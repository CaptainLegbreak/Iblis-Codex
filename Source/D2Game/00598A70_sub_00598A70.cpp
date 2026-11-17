#pragma function(memset)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    unsigned short nNPCNo;
    char unk0x16[0x02];
    unsigned short nMessageIndex;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char pad0D[3]; int nSeqId;

    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
    };
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char unk0xE4[0x04];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    bool (__fastcall* pfSeqFilter)(D2QuestDataStrc*);
};

struct D2Act2Quest0Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act2Quest1Strc
{
    char unk0x00[0x08];
    unsigned char bAtmaActivated;
    unsigned char unk0x09;
    unsigned char bStatusTimerStarted;
    unsigned char unk0x0B;
    int nSkillBookDropCount;
    unsigned char rewardPending;
};

extern "C" const char gszA2Q0SourceFile[];                                                                  // 0x006E1F2C
extern "C" char gpAct2IntroNpcMessages[];                                                                   // 0x00738D60
extern "C" char gpAct2Q0NpcMessages[];                                                                      // 0x00738FC8
void __fastcall ACT2Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005984C0
void __fastcall ACT2Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005983E0
bool __fastcall sub_005985B0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005985B0
bool __fastcall ACT2Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005985C0
void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x005986B0
bool __fastcall ACT2Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00598770
bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598780
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);                // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);              // 0x00545920
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(int (__stdcall*)());  // 0x006CC34C
extern "C" const char text_006E1F60[],text_006CC837[];  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
#define CHECK(p,line) if(!(p)){sub_00408A60(text_006CC837,sub_00408090(),line);sub_00681E09(-1);}
void __fastcall sub_00544350(D2QuestDataStrc*,int,const char*,int);  // 0x00544350
D2UnitStrc* __fastcall sub_005537D0(D2GameStrc*,int,void*,QUESTUNITITERATE);  // 0x005537D0
int __fastcall sub_005989E0(D2GameStrc*,D2UnitStrc*,void*);  // 0x005989E0
int __fastcall sub_005988B0(D2GameStrc*,D2UnitStrc*,void*);  // 0x005988B0
void __stdcall sub_0065C3A0(D2BitBufferStrc*,int,int);  // 0x0065C3A0
void __fastcall sub_00545780(D2GameStrc*,D2UnitStrc*,D2UnitStrc*);  // 0x00545780
// build: symbol _text_006E1F60 0x006E1F60
// 0x00598A70
void __fastcall sub_00598A70(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
 const unsigned short message=arg->nMessageIndex;
 const unsigned short npc=arg->nNPCNo;
 D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
 if(npc!=176) return;
 D2Act2Quest1Strc* ex=(D2Act2Quest1Strc*)q->pQuestDataEx;
 if(message==304) {
  ex->bAtmaActivated=1;
  sub_00544350(q,2,text_006E1F60,239);
  sub_005537D0(q->pGame,0,0,sub_005989E0);
 } else {
  if(message!=334) return;
  const int filter=q->nQuestFilter;
  if(!QUESTRECORD_GetQuestState(flags,filter,1)) return;
  if(QUESTRECORD_GetQuestState(flags,q->nQuestFilter,13)) {
   if(q->fState!=5) {
    q->nFlagsByte=0;
    QUESTS_UnitIterate(q,13,0,sub_005988B0,true);
    q->pfCallback[2]=0;
    sub_00544350(q,5,text_006E1F60,253);
    CHECK(!IsBadCodePtr((int (__stdcall*)())q->pfSeqFilter),254);
    q->pfSeqFilter(q);
   }
   if(!q->bNotIntro) QUESTS_SetGlobalState(q->pGame,9,13);
  } else if(ex->rewardPending) {
   D2QuestDataStrc* seq=QUESTS_GetQuestData(q->pGame,q->nSeqId);
   if(seq) {
    CHECK(!IsBadCodePtr((int (__stdcall*)())q->pfSeqFilter),269);
    seq->pfSeqFilter(seq);
   }
  }
  QUESTRECORD_SetQuestState(flags,q->nQuestFilter,0);
  sub_0065C3A0(flags,q->nQuestFilter,1);
  QUESTS_AddPlayerGUID(&q->tPlayerGUIDs,UNITS_GetUnitId(arg->pPlayer));
 }
 sub_00545780(arg->pGame,arg->pPlayer,arg->pTarget);
}
