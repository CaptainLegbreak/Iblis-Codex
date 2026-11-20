#include "D2Game.h"
#include "D2GameTypes.h"

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};


#define QFLAG_REWARDGRANTED 0
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_III 2
#define MONSTER_ORMUS 255
#define LEVEL_OUTERSTEPPES 104
#define OBJMODE_OPENED 2
#define EVENTTYPE_QUESTFN 7
#define QUESTSTATEFLAG_A3COMPLETED 23
struct Bits;
struct D2MapAIPathPositionStrc;
struct D2PlayerDataStrc;
struct D2Act3Quest6Strc;
struct D2QuestGUIDStrc;
struct D2ObjInitFnStrc;
struct Player;
struct QuestEx;
struct Args;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned short dwClassId;
    unsigned short unk0x06;
    int unk0x08;
    int dwUnitId;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pCallback[16];
    int eFilter;
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
    char unk0x14[0x08];
    int nSoulstonesToDrop;
    unsigned char bNatalyaSpawned;
    unsigned char pad0x21[3];
    D2MapAIStrc* pNatalyaMapAI;
    unsigned char unused0x28[4];
    int nNatalyaGUID;
    unsigned char bNatalyaMapAIChanged;
    unsigned char pad0x31[3];
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360


typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0


void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct Game { char pad0[0x6D]; unsigned char difficulty; };

struct Unit { int type,classId; void* pool; int id; };

struct Player { char pad0[0x10]; Bits* quests[3]; };

struct QuestEx { char pad0[0xC]; unsigned char flag; };

struct Quest { char pad0[9]; unsigned char notIntro; char padA[2]; unsigned char state; char padD[0xB]; QuestEx* ex; char pad1C[0xC4]; int filter; };

struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };

extern unsigned indices_00741518[]; // 0x00741518
Player* __stdcall sub_006221A0(Unit*); // 0x006221A0
int __stdcall sub_0065C310(Bits*,int,int); // 0x0065C310
int __fastcall sub_005452C0(Quest*,int); // 0x005452C0

enum { QUEST_ID = 22 };

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

// 0x005BC140
static __declspec(noinline) void __stdcall sub_005BC140_ACT3Q6_SetCompletionStates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 204), 3, pGame->nDifficulty);
}

// 0x005BC190
int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_DURANCEOFHATELEV3)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7))
    {
        return 0;
    }

    sub_005BC140_ACT3Q6_SetCompletionStates(pGame, pUnit, pQuestFlags);
    ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
    return 0;
}

// 0x005BC210
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A3Q6_MEPHISTO);
    }

    return 0;
}

// 0x005BC370
void __fastcall ACT3Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || pQuestArg->pTarget->dwClassId != MONSTER_ORMUS)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bOrmusActivated != 1)
    {
        return;
    }

    pQuestData->bStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bOrmusActivated = 0;
    pQuestData->pCallback[2] = 0;
}

// 0x005BC720
bool __fastcall ACT3Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fLastState != 4)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerStarted = 0;
    return 1;
}

// 0x005BC750
void __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != ACT_III)
    {
        return;
    }

    sub_005BC140_ACT3Q6_SetCompletionStates(pGame, pUnit, pQuestFlags);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (pQuestData)
    {
        ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
    }
}

// 0x005BC7C0
int __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005BC810
int __fastcall ACT3Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A3Q6_MEPHISTO, 0);
    }

    return 0;
}

// 0x005BC870
int __fastcall ACT3Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 66, pUnit);
    }

    return 0;
}

// 0x005BCB90
void __fastcall OBJECTS_InitFunction45_MephistoBridge(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMephistoBridgeInitialized = 1;
    pQuestDataEx->nMephistoBridgeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nMephistoBridgeObjectMode);
    if (pQuestDataEx->nMephistoBridgeObjectMode != OBJMODE_OPENED)
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 20, 0, 0);
    }
}

// 0x005BCBF0
void __fastcall OBJECTS_InitFunction44_HellGatePortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO);
    if (DUNGEON_GetLevelIdFromRoom(pOp->pRoom) == LEVEL_OUTERSTEPPES)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        return;
    }

    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bHellGatePortalInitialized = 1;
    pQuestDataEx->nHellGatePortalGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nHellGatePortalObjectMode);
}

// 0x005BCC60
bool __fastcall ACT3Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q6_Callback02_NpcDeactivate;
    }

    return true;
}

// 0x005BC270
void __fastcall sub_005BC270(Quest* quest,Args* args)
{
    Game* game=args->game;
    Bits* flags=sub_006221A0(args->player)->quests[game->difficulty];
    int reward=sub_0065C310(flags,QUEST_ID,0);
    int goal=sub_0065C310(flags,QUEST_ID,13);
    int npc=!args->target ? -1 : args->target->classId;
    if(sub_0065C310(flags,quest->filter,11)) {
        sub_00543790(quest,args->text,npc,5);
        return;
    }
    if(reward==1) {
        if(sub_005452C0(quest,!args->player ? -1 : args->player->id)==1) sub_00543790(quest,args->text,npc,6);
        return;
    }
    unsigned char state=quest->state;
    if(state>=6) {
        if(goal==1) sub_00543790(quest,args->text,npc,6);
        return;
    }
    {
        unsigned index=indices_00741518[state];
        if(index!=-1 && index<8) sub_00543790(quest,args->text,npc,index);
    }
}

#include "gen/data/Source/D2Game/Quests/a3q6.inc"

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
