#include "D2Game.h"

struct D2UnitStrc { unsigned int type; unsigned int classId; };
struct D2Act5Quest5Strc { unsigned char unused; unsigned char activated; };
struct D2QuestDataStrc { unsigned char padding[0x14]; unsigned char flags; unsigned char padding15[3]; D2Act5Quest5Strc* data; };
struct D2QuestArgStrc { unsigned char padding[8]; D2UnitStrc* target; };
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc*, D2UnitStrc*, void*);
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* game, D2UnitStrc* unit, void* data); // 0x0058BE20
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* quest, int state, D2UnitStrc* unit, QUESTUNITITERATE callback, bool iterate); // 0x00544300

// 0x0058BE80
void __fastcall ACT5Q5_Callback02_NpcDeactivate(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    if (argument->target && (unsigned short)argument->target->classId == 515)
    {
        D2Act5Quest5Strc* data = quest->data;
        if (data->activated == 1)
        {
            quest->flags = 0;
            QUESTS_UnitIterate(quest, 1, 0, ACT5Q5_UnitIterate_StatusCyclerEx, true);
            data->activated = 0;
        }
    }
}
