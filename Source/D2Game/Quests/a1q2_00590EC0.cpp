#include "D2Structs.h"
#include "D2GameTypes.h"
#ifdef MOVED_TEST
#define DIAG_LINE_NUMBER 451
#define STATE_LINE 452
#define QUEST_STATE 6
#define TIMER_TICKS 17
#define GLOBAL_STATE 14
#else
#define DIAG_LINE_NUMBER 447
#define STATE_LINE 448
#define QUEST_STATE 4
#define TIMER_TICKS 15
#define GLOBAL_STATE 13
#endif
struct D2GameStrc;

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
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
};


struct D2Act1Quest2Strc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char bBloodravenKilled;
    unsigned char bKashyaActivated;
    int unk0x04;
    int nBloodravenGUID;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
extern "C" const char gszA1Q2SourceFile[];                                                                  // 0x006E1B98
bool __fastcall ACT1Q2_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);  // 0x00590BF0
int __fastcall ACT1Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590DD0
int __fastcall ACT1Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590E30
int __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590E70
int __fastcall ACT1Q2_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590C40
// 0x00590EC0
void __fastcall sub_00590EC0_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", gszA1Q2SourceFile, DIAG_LINE_NUMBER);
        QUESTS_StateDebug(pQuestData, QUEST_STATE, gszA1Q2SourceFile, STATE_LINE);
        D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x01 = 1;
        pQuestDataEx->bBloodravenKilled = 1;
        pQuestDataEx->nBloodravenGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetCompletionFlag);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_AttachCompletionSound);
        QUESTS_CreateTimer(pQuestData, ACT1Q2_Timer_StatusCycler, TIMER_TICKS);
        pQuestData->pCallback[2] = 0;
        pQuestDataEx->unk0x00 = 1;
        pQuestDataEx->unk0x04 = 1;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, GLOBAL_STATE);
    }
}
