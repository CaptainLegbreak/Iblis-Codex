#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2Structs.h"

#include "D2UnitData.h"
#include "D2QuestData.h"
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_III 2
#define QUESTSTATEFLAG_A1Q2 2
struct Obj00590810;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest2Strc;

struct Obj00590810 {
    unsigned char bUnknown00[9];
    unsigned char bFlag09;
    unsigned char bUnknown0A[2];
    unsigned char bValue0C;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590830

// 0x00590BF0
bool __fastcall ACT1Q2_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
    return true;
}

// 0x00590C10
void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

