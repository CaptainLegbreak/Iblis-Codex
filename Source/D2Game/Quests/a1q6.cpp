#include "D2Game.h"

#define UNIT_MONSTER 1
#define QUEST_A1Q6_ANDARIEL 6
#define QUESTSTATEFLAG_A1Q6 6
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ITEMQUAL_NORMAL 2
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest6Strc;
struct D2SeedStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xA8];
    unsigned int dwDropItemCode;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x2];
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

extern int gpAct1Q6NpcMessages[]; // 0x007382E0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pUnit, int nQuestId, int a3); // 0x00545920
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00595B20
void __fastcall ACT1Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595B80
void __fastcall ACT1Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595C60
void __fastcall ACT1Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595E20
void __fastcall ACT1Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00596010
void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596320
int __fastcall ACT1Q6_UnitIterate_CreatePortalToTown(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596490
void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005965A0
bool __fastcall ACT1Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005967F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall sub_00544070(D2GameStrc*,const char*,const char*,int); // 0x00544070
void __fastcall sub_00545310(D2QuestDataStrc*); // 0x00545310
int __fastcall sub_00595BD0(D2GameStrc*,D2UnitStrc*,void*); // 0x00595BD0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

extern "C" const unsigned int gdwA1Q6ChippedGemCodes[7]; // 0x007361DC
extern "C" const unsigned int gdwA1Q6NormalGemCodes[7]; // 0x00736444
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall ACT1Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596170
void __fastcall ACT1Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pArgs); // 0x005961C0
int __fastcall ACT1Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005963E0
int __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596440
bool __fastcall ACT1Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x00596500

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

// 0x00596170
int __fastcall ACT1Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 33, pUnit);
    }

    return 0;
}

// 0x005961C0
void __fastcall ACT1Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pArgs)
{
    QUESTS_RemovePlayerGUID(pQuestData, pArgs);
    D2Act1Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;

    const int nUnitId = !pArgs->pPlayer ? -1 : pArgs->pPlayer->dwUnitId;

    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
}

// 0x005963E0
int __fastcall ACT1Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A1Q6_ANDARIEL, 0);
    }

    return 0;
}

// 0x00596440
int __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != (unsigned short)-1)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00596500
bool __fastcall ACT1Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuest)
{
    D2Act1Quest6Strc* pQuestDataEx = pQuest->pQuestDataEx;
    ++pQuestDataEx->nTimerInvocations;

    if (pQuestDataEx->nTimerInvocations == 10)
    {
        SUNIT_IterateUnitsOfType(pGame, 0, SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nAndarielGUID), ACT1Q6_UnitIterate_CreatePortalToTown);
        return false;
    }

    if (pQuestDataEx->nTimerInvocations != 12)
    {
        return false;
    }

    if (pQuest->fLastState != 3 && pQuest->fLastState != 13)
    {
        pQuest->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuest, 3, 0, ACT1Q6_UnitIterate_StatusCyclerEx, 1);
    }

    return true;
}

// 0x00596580
bool __fastcall ACT1Q6_Timer_StateDebug(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 605);
    }

    return true;
}

// 0x005968E0
bool __fastcall ACT1Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_CreateTimer(pQuestData, ACT1Q6_Timer_StateDebug, 20);
    }

    return true;
}

// 0x00596900
void __fastcall ACT1Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00596990
void __fastcall ACT1Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));

    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q6_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT1Q6_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q6_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q6_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q6_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q6_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q6_SeqCallback;

    pQuestData->nQuestFilter = QUESTSTATEFLAG_A1Q6;
    pQuestData->pNPCMessages = gpAct1Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 837, 0);

    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nSeqId = 37;
    pQuestData->pfActiveFilter = ACT1Q6_ActiveFilterCallback;

    pQuestDataEx->nAndarielGUID = 0;
    pQuestDataEx->unk0x190 = 0;
    pQuestDataEx->nTimerInvocations = 0;
    pQuestDataEx->bAndarielKilled = 0;
    pQuestDataEx->bCainActivated = 0;

    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID1);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID2);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID3);
}

#include "gen/data/Source/D2Game/Quests/a1q6.inc"

// 0x00596210
static void __stdcall sub_00596210_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
    CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 451), 1, pGame->nDifficulty);
}

// 0x00596260
int __fastcall ACT1Q6_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_COMPLETEDBEFORE) == 1)
    {
        return 0;
    }

    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CATACOMBSLEV4)
    {
        return 0;
    }

    D2Act1Quest6Strc* pQuestDataEx = QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    sub_00596210_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
    return 0;
}

// 0x00596320
void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_I)
    {
        return;
    }

    D2Act1Quest6Strc* pQuestDataEx = QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    sub_00596210_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
}

inline unsigned __int64 A1Q6_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2BitBufferStrc* A1Q6_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline int A1Q6_GetQuestStateInline(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nState)
{
    D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pGame, pPlayer);
    return QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, nState);
}

// 0x005965A0
void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest6Strc* pQuestDataEx = pQuestData->pQuestDataEx;

    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = 0;

    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDGRANTED)
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDPENDING))
        {
            D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer);
            sub_00596210_SetPrimaryGoalDone(pQuestData->pGame, pQuestArg->pPlayer, pQuestFlags);

            int nItemLevel;
            for (int i = 0; i < 2; ++i)
            {
                pQuestArg->pTarget->dwDropItemCode = gdwA1Q6ChippedGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
                D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
            }

            pQuestArg->pTarget->dwDropItemCode = gdwA1Q6NormalGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
            D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);

            pQuestArg->pTarget->dwDropItemCode = 0;
        }

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetCompletionFlag);
    }

    pQuestDataEx->nAndarielGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestDataEx->nTimerInvocations = 1;

    if (pQuestData->bNotIntro)
    {
        QUESTS_CreateTimer(pQuestData, ACT1Q6_Timer_StatusCycler, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q6_UnitIterate_AttachCompletionSound);
    }

    pQuestDataEx->bAndarielKilled = 1;
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 688);
    pQuestData->pfCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q6_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = 0;
}

// 0x005968C0
int __fastcall sub_005968C0_IsAndarielKilled(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->bNotIntro)
        return pQuestData->pQuestDataEx->bAndarielKilled;
    return 1;
}

// 0x00596BA0
void __fastcall sub_00596BA0_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}
