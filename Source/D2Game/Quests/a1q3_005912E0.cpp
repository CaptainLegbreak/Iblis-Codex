#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2Structs.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_CUSTOM2 6
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define QUESTSTATEFLAG_A1Q3 3
#define QUEST_A1Q3_MALUS 3
#define OBJMODE_OPENED 2
#define LEVEL_ROGUEENCAMPMENT 1
#define STAT_LEVEL 12
#define MONSTER_CHARSI 154
#define LINE_CHANGEDLEVEL_DEBUG 0x189
#define LINE_SEQ_DEBUG 0x35A
#define LINE_SEQ_ASSERT 0x362
#define LINE_INIT_ALLOC 0x3AE
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest3Strc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



struct D2Act1Quest3Strc
{
    unsigned char unk0x00;
    unsigned char bMalusInitialized;
    unsigned char bCharsiIntroActivated;
    unsigned char bCharsiEndActivated;
    int nMalusGUID;
    unsigned char unk0x08;
    char unk0x09[0x7];
    unsigned char unk0x10;
    char pad0x11[0x1];
    unsigned short unk0x12;
    D2QuestGUIDStrc tPlayerGUIDs;
    int nMalusObjectMode;
    int nMalusItemsInGame;
    unsigned char unk0xA0;
    unsigned char bStartingPlayerHasMalus;
    unsigned char pad0xA2[0x2];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs); // 0x00545300
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005916A0
void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00591A90
bool __fastcall ACT1Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591C30
bool __fastcall ACT1Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00591D30
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT1Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT1Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00591490
void __fastcall ACT1Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT1Q3_SeqCallback(D2QuestDataStrc* pQuestData);

// 0x005912E0
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q3_MALUS);
    }

    return 0;
}

// 0x005913C0
void __fastcall ACT1Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_CHARSI)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCharsiIntroActivated == 1)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bCharsiIntroActivated = 0;
    }
    else if (pQuestDataEx->bCharsiEndActivated == 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, ITERSTATE_13, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bCharsiEndActivated = 0;
    }
}

// 0x00591430
void __fastcall ACT1Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    if (STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < MALUS_MIN_LEVEL)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING);
}

// 0x00591810
void __fastcall ACT1Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    if (!pQuestData->bNotIntro)
    {
        pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = 0;
        return;
    }

    if (nOldLevel != LEVEL_ROGUEENCAMPMENT)
    {
        return;
    }

    if (pQuestData->fState != QSTATE_2)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    if (pQuestData->fLastState != 1)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
    }

    QUESTS_StateDebug(pQuestData, QSTATE_3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_CHANGEDLEVEL_DEBUG);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = 0;
}

// 0x00591960
void __fastcall ACT1Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_CUSTOM2))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_CUSTOM2);
        SUNIT_AttachSound(pQuestArg->pPlayer, SOUND_MALUS_PICKUP, pQuestArg->pPlayer);
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, ITERSTATE_2, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
}

// 0x005919D0
void __fastcall ACT1Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS))
    {
        return;
    }

    if (!pQuestData->bNotIntro || pQuestData->fState == QSTATE_5)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    ++pQuestDataEx->nMalusItemsInGame;

    if (pQuestDataEx->nMalusItemsInGame == 1 && pQuestDataEx->bMalusInitialized && pQuestDataEx->nMalusObjectMode == OBJMODE_OPENED)
    {
        pQuestData->fLastState = QSTATE_2;
    }
}

// 0x00591A20
void __fastcall ACT1Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro || pQuestData->fState == QSTATE_5)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    --pQuestDataEx->nMalusItemsInGame;

    if (!pQuestDataEx->nMalusItemsInGame && pQuestDataEx->bMalusInitialized && pQuestDataEx->nMalusObjectMode == OBJMODE_OPENED)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, ITERSTATE_3, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x00591A60
void __fastcall ACT1Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x00591E40
bool __fastcall ACT1Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SEQ_DEBUG);
        return true;
    }

    if (pQuestData->fState != QSTATE_5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SEQ_ASSERT);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00591ED0
void __fastcall ACT1Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS))
    {
        D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        ++pQuestDataEx->nMalusItemsInGame;
        pQuestDataEx->bStartingPlayerHasMalus = 1;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = QSTATE_2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = QSTATE_3;
        pQuestData->fLastState = 1;
    }
}

// 0x00591F70
void __fastcall ACT1Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM] = ACT1Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[QUESTEVENT_PLAYERJOINEDGAME] = ACT1Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[QUESTEVENT_ITEMPICKEDUP] = ACT1Q3_Callback04_ItemPickedUp;
    pQuestData->pCallback[QUESTEVENT_MALUSREMOVED] = ACT1Q3_Callback06_MalusRemoved;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q3_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q3_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q3_SeqCallback;
    pQuestData->pNPCMessages = gpAct1Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q3;

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->fState = 0;
    pQuestData->pfStatusFilter = ACT1Q3_StatusFilterCallback;
    pQuestData->nInitNo = A1Q3_INITNO;
    pQuestData->pfActiveFilter = ACT1Q3_ActiveFilterCallback;
    pQuestData->nSeqId = A1Q3_SEQID;

    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest3Strc));
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->nMalusGUID = 0;
    pQuestDataEx->unk0x10 = 0;
    pQuestDataEx->unk0x12 = 0;
    pQuestDataEx->bMalusInitialized = 0;
    pQuestDataEx->unk0x08 = 0;
    pQuestDataEx->bCharsiIntroActivated = 0;
    pQuestDataEx->bCharsiEndActivated = 0;
    pQuestDataEx->nMalusObjectMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

#include "gen/data/Source/D2Game/Quests/a1q3_005912E0.inc"

// 0x005919C0
static __forceinline void sub_005919C0_SetLastStateTwo(D2QuestDataStrc* pQuestData)
{
    pQuestData->fLastState = 2;
}

void __stdcall sub_M113_Emit_005919C0(D2QuestDataStrc* pFirst, D2QuestDataStrc* pSecond)
{
    sub_005919C0_SetLastStateTwo(pFirst);
    sub_005919C0_SetLastStateTwo(pSecond);
}
