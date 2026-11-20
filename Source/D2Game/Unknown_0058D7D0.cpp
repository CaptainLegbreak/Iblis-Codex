#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"

struct Flags;
struct PlayerData;


D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

struct Game { char pad[0x6D]; unsigned char difficulty; };

struct PlayerData { char pad[0x10]; Flags* quests[3]; };

struct Quest { char pad[0x0C]; unsigned char state; };

PlayerData* __stdcall sub_006221A0(Unit*); // 0x006221A0
int __stdcall sub_0065C310(Flags*, int, int); // 0x0065C310
void __stdcall sub_0065C360(Flags*, int, int); // 0x0065C360
int __stdcall sub_0061A1B0(Room*); // 0x0061A1B0
unsigned char __stdcall sub_006427F0(int); // 0x006427F0
Quest* __fastcall sub_00543640(Game*, int); // 0x00543640

enum { QUEST_FLAGS_ID = 40, QUEST_DATA_ID = 36 };

// 0x0058D7D0
int __fastcall sub_0058D7D0_ACT5Q6_UnitIterate_SpawnObject(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == 132)
    {
        D2CoordStrc coord;
        UNITS_GetCoords(pUnit, &coord);
        coord.nX += 5;
        D2ActiveRoomStrc* pFreeRoom = UNITS_GetRoom(pUnit);
        QUESTS_GetFreePosition(pRoom, &coord, 5, 0x400, &pFreeRoom, 18, 100);
        if (pFreeRoom)
        {
            SUNIT_AllocUnitData(2, 0x235, coord.nX, coord.nY, pGame, pFreeRoom, 1, 1, 0);
        }

        return 1;
    }

    return 0;
}

// 0x0058D8B0
int __fastcall sub_0058D8B0(Game* game, Unit* unit, void* unused)
{
    Flags* flags = sub_006221A0(unit)->quests[game->difficulty];
    if (sub_0065C310(flags, QUEST_FLAGS_ID, 0) == 1 ||
        sub_0065C310(flags, QUEST_FLAGS_ID, 1) == 1) return 0;
    Room* room = sub_00620BB0(unit);
    if (!room) return 0;
    int level = sub_0061A1B0(room);
    if (!level || sub_006427F0(level) != 4) return 0;
    Quest* quest = sub_00543640(game, QUEST_DATA_ID);
    if (!quest) return 0;
    if (quest->state == 2) sub_0065C360(flags, QUEST_FLAGS_ID, 2);
    else if (quest->state == 3) sub_0065C360(flags, QUEST_FLAGS_ID, 3);
    return 0;
}
