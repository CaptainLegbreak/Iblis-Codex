#include "D2Game.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

struct D2UnitStrc
{
    int dwUnitType;
    unsigned short dwClassId;
    char unk0x06[0x6];
    int dwUnitId;
};

struct D2QuestGUIDStrc
{
    int nGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char unk0x82[2];
};

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
    char pad0x0E[0x2];
    int nSeqId;
    unsigned char nFlags;
    unsigned char unk0x15[0x3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    union
    {
        int nOldLevel;
        struct
        {
            unsigned short nNPCNo;
            unsigned short unk0x16;
            unsigned short nMessageIndex;
            unsigned short unk0x1A;
        };
    };
};

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);               // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                             // 0x00545200
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs);                                      // 0x00545300
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);    // 0x00545780
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x005916A0
void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00591A90
bool __fastcall ACT1Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591C30
bool __fastcall ACT1Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00591D30
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT1Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);   // 0x00591430
void __fastcall ACT1Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT1Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT1Q3_SeqCallback(D2QuestDataStrc* pQuestData);

#define QUESTEVENT_NPCACTIVATE 0
#define QUESTEVENT_NPCDEACTIVATE 2
#define QUESTEVENT_CHANGEDLEVEL 3
#define QUESTEVENT_ITEMPICKEDUP 4
#define QUESTEVENT_MALUSREMOVED 6
#define QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM 9
#define QUESTEVENT_PLAYERLEAVESGAME 10
#define QUESTEVENT_SCROLLMESSAGE 11
#define QUESTEVENT_PLAYERSTARTEDGAME 13
#define QUESTEVENT_PLAYERJOINEDGAME 14

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
#define QSTATE_2 2
#define QSTATE_3 3
#define QSTATE_4 4
#define QSTATE_5 5
#define ITERSTATE_2 2
#define ITERSTATE_3 3
#define ITERSTATE_13 13
#define OBJMODE_OPENED 2
#define A1Q3_INITNO 5
#define A1Q3_SEQID 6
#define LEVEL_ROGUEENCAMPMENT 1
#define STAT_LEVEL 12
#define MALUS_MIN_LEVEL 8
#define MONSTER_CHARSI 154
#define MSG_CHARSI_INTRO 146
#define MSG_CHARSI_END 163
#define SOUND_MALUS_PICKUP 36
#define ITEMCODE_MALUS ' mdh'
#define LINE_SCROLL_DEBUG5 0xF7
#define LINE_SCROLL_ASSERT1 0xFA
#define LINE_SCROLL_ASSERT2 0x102
#define LINE_SCROLL_DEBUG2 0x10C

// 0x00591490
void __fastcall ACT1Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS);
    D2GameStrc* pGame = pQuestArg->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo != MONSTER_CHARSI)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    if (nMessageIndex == MSG_CHARSI_END)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED))
        {
            return;
        }

        pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        if (pItem)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING);
            QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
            QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS);
            --pQuestDataEx->nMalusItemsInGame;

            const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
            if (nPartyId != 0xFFFF)
            {
                PARTY_IteratePartyMembers(pQuestArg->pGame, nPartyId, (PartyCallbackFunction)ACT1Q3_UnitIterate_SetPrimaryGoalDone, 0);
            }

            if (pQuestData->bNotIntro)
            {
                if (pQuestData->fState == QSTATE_4)
                {
                    QUESTS_StateDebug(pQuestData, QSTATE_5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SCROLL_DEBUG5);
                    pQuestDataEx->bCharsiEndActivated = 1;
                    QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SCROLL_ASSERT1);
                    pQuestData->pfSeqFilter(pQuestData);
                }
                else if (pQuestDataEx->bStartingPlayerHasMalus)
                {
                    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
                    if (pQuest)
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SCROLL_ASSERT2);
                        pQuest->pfSeqFilter(pQuest);
                    }
                }
            }
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == MSG_CHARSI_INTRO)
    {
        QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SCROLL_DEBUG2);
        pQuestDataEx->bCharsiIntroActivated = 1;
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}
