#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2NPCMessageTableStrc;



struct D2GameStrc
{
    char pad0x00[0x1C];
    void* pMemoryPool;
    char pad0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
        int nOldLevel;
    };
    union
    {
        unsigned short nMessageIndex;
        int nNewLevel;
    };
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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
    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
    };
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    D2NPCMessageTableStrc* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act5Quest4Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    unsigned char unused0x84;
    unsigned char bTimerActive;
    unsigned char bDrehyaActivated;
    unsigned char bNeedsToOpenPortal;
    unsigned char bPortalCreated;
    unsigned char bWaypointNotActivated;
    unsigned char pad0x8A[2];
    D2ActiveRoomStrc* pRoom;
};

#define QUEST_A5Q4_NIHLATHAK 34
#define QUEST_A5Q5_ANCIENTS 35
#define QUESTSTATEFLAG_A5Q4 38
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define INITNO_A5Q4 4
#define MONSTER_DREHYA 512
#define MSG_DREHYA_INTRO 20137
#define MSG_DREHYA_DONE 20148
#define LEVEL_HARROGATH 109
#define LEVEL_NIHLATHAKSTEMPLE 121
#define QUESTFX_A5Q4 17
#define TIMER_TICKS_A5Q4 8
#define LINE_SEQ_DEBUG 255
#define LINE_SEQ_ASSERT 246
#define LINE_SCROLL_STATE2 283
#define LINE_SCROLL_STATE5 298
#define LINE_KILLED_STATE4 583
#define LINE_LEVEL_STATE3 748
#define LINE_INIT_ALLOC 781
#define OBJECT_PERMANENT_TOWN_PORTAL 60
#define PORTAL_DX 10
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern D2NPCMessageTableStrc gpAct5Q4NpcMessages;                                                           // 0x00734AC8

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);  // 0x0040B430
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00543520
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);          // 0x00543F10
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                        // 0x00544720
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                           // 0x00545240
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs);                                      // 0x00545300
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);             // 0x00545920
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058AEA0
bool __fastcall ACT5Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058AF00
void __fastcall ACT5Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x0058B050
void __fastcall ACT5Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x0058B2C0
int __fastcall ACT5Q4_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x0058B4A0
void __fastcall sub_0058B5B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);  // 0x0058B5B0
int __fastcall ACT5Q4_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058B730
bool __fastcall ACT5Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058B870
void __fastcall ACT5Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058B990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

static __forceinline D2BitBufferStrc* QUESTS_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static __forceinline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x0058B0B0
int __fastcall ACT5Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == QSTATE_2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_STARTED);
    }
    else if (pQuestData->fState == QSTATE_3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x0058B140
bool __fastcall ACT5Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < QSTATE_4 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SEQ_DEBUG);
        }
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

// 0x0058B1C0
void __fastcall ACT5Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != MONSTER_DREHYA)
    {
        return;
    }

    if (nMessageIndex == MSG_DREHYA_INTRO)
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SCROLL_STATE2);
        pQuestDataEx->bDrehyaActivated = 1;
        pQuestDataEx->bNeedsToOpenPortal = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_UpdateQuestStateFlags);
    }
    else if (nMessageIndex == MSG_DREHYA_DONE)
    {
        pQuestData->nFlagsByte = 0;
        QUESTS_UnitIterate(pQuestData, pQuestData->fLastState, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);

        QUESTRECORD_SetQuestState(QUESTS_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_ENTERAREA);

        if (!QUESTRECORD_GetQuestState(QUESTS_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE)
            && (pQuestData->bNotIntro || !QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING)))
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, QSTATE_5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SCROLL_STATE5);
        ACT5Q4_SeqCallback(pQuestData);
    }
}

// 0x0058B460
void __fastcall ACT5Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const int nGUID = UNITS_GetGUIDOrNone(pQuestArg->pPlayer);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, nGUID);
}

// 0x0058B680
int __fastcall ACT5Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, sub_0058B5B0, 0);
    }

    return 0;
}

// 0x0058B6D0
int __fastcall ACT5Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A5Q4_NIHLATHAK, 0);
    }

    return 0;
}

// 0x0058B770
bool __fastcall ACT5Q4_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;

    if (pQuestData->fLastState != QSTATE_4)
    {
        pQuestData->nFlagsByte = 0;
        QUESTS_UnitIterate(pQuestData, QSTATE_4, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x0058B7A0
void __fastcall ACT5Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pRoom = pRoom;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_SetRewardPending);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_AttachCompletionSound);

    QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE);
    QUESTS_TriggerFX(pQuestData->pGame, QUESTFX_A5Q4);
    QUESTS_StateDebug(pQuestData, QSTATE_4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_KILLED_STATE4);

    if (!pQuestDataEx->bTimerActive)
    {
        pQuestDataEx->bTimerActive = 1;
        QUESTS_CreateTimer(pQuestData, ACT5Q4_Timer_StatusCycler, TIMER_TICKS_A5Q4);
    }
}

// 0x0058BAB0
void __fastcall ACT5Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const int nNewLevel = pQuestArg->nNewLevel;

    if (pQuestArg->nOldLevel == LEVEL_HARROGATH && pQuestData->fState == QSTATE_2)
    {
        QUESTS_StateDebug(pQuestData, QSTATE_3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_LEVEL_STATE3);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_UpdateQuestStateFlags);
    }

    if (nNewLevel == LEVEL_NIHLATHAKSTEMPLE && pQuestData->fLastState == 1)
    {
        pQuestData->nFlagsByte = 0;
        QUESTS_UnitIterate(pQuestData, QSTATE_2, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bDrehyaActivated = 0;
    }
}

// 0x0058BB20
void __fastcall ACT5Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT5Q4_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[QUESTEVENT_CHANGEDLEVEL] = ACT5Q4_Callback03_ChangedLevel;
    pQuestData->pfCallback[QUESTEVENT_MONSTERKILLED] = ACT5Q4_Callback08_MonsterKilled;
    pQuestData->pfCallback[QUESTEVENT_NPCACTIVATE] = ACT5Q4_Callback00_NpcActivate;
    pQuestData->pfCallback[QUESTEVENT_NPCDEACTIVATE] = ACT5Q4_Callback02_NpcDeactivate;
    pQuestData->pfCallback[QUESTEVENT_SCROLLMESSAGE] = ACT5Q4_Callback11_ScrollMessage;
    pQuestData->pfCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT5Q4_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = &gpAct5Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nQuestFilter = QUESTSTATEFLAG_A5Q4;
    pQuestData->pfStatusFilter = ACT5Q4_StatusFilterCallback;
    pQuestData->nInitNo = INITNO_A5Q4;
    pQuestData->pfActiveFilter = ACT5Q4_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q4_SeqCallback;
    pQuestData->nSeqId = QUEST_A5Q5_ANCIENTS;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest4Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x0058BE20
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q5_ANCIENTS);
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a5q4_0058B0B0.inc"
