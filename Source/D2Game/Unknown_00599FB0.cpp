#include "D2Structs.h"
struct D2QuestGUIDStrc { unsigned int playerIds[32]; unsigned short playerCount; unsigned char padding[2]; };
struct D2Act2Quest3Strc { unsigned char padding[0x14]; D2QuestGUIDStrc playerGuids; };
struct D2QuestDataStrc { unsigned char padding[0x18]; D2Act2Quest3Strc* data; };
struct D2QuestArgStrc { unsigned char padding[12]; D2UnitStrc* player; };
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* quest, D2QuestArgStrc* argument); // 0x00545530
void __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* guids, int unitId); // 0x00545240

static __forceinline int GetUnitId(D2UnitStrc* unit) { return !unit ? -1 : unit->dwUnitId; }

// 0x00599FB0
void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    QUESTS_RemovePlayerGUID(quest, argument);
    D2UnitStrc* player = argument->player;
    D2Act2Quest3Strc* data = quest->data;
    QUESTS_FastRemovePlayerGUID(&data->playerGuids, GetUnitId(player));
}
