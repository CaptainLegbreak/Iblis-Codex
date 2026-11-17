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

#include "gen/data/Source/D2Game/00596170_ACT1Q6_UnitIterate_AttachCompletionSound.inc"
