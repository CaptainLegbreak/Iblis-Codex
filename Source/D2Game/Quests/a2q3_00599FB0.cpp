#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* quest, D2QuestArgStrc* argument); // 0x00545530
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

static inline int GetUnitId(D2UnitStrc* unit) { return !unit ? -1 : unit->dwUnitId; }

// 0x00599FB0
void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    QUESTS_RemovePlayerGUID(quest, argument);
    D2UnitStrc* player = argument->pPlayer;
    D2Act2Quest3Strc* data = (D2Act2Quest3Strc*)quest->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&data->tPlayerGUIDs, GetUnitId(player));
}
