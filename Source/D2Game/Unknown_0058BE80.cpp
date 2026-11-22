#include "D2Game.h"
#include "D2Structs.h"

#include "D2QuestData.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc*, D2UnitStrc*, void*);
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* game, D2UnitStrc* unit, void* data); // 0x0058BE20
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* quest, int state, D2UnitStrc* unit, QUESTUNITITERATE callback, bool iterate); // 0x00544300

// 0x0058BE80
void __fastcall ACT5Q5_Callback02_NpcDeactivate(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    if (argument->pTarget && (unsigned short)argument->pTarget->dwClassId == 515)
    {
        D2Act5Quest5Strc* data = (D2Act5Quest5Strc*)quest->pQuestDataEx;
        if (data->bQualKehkActivated == 1)
        {
            quest->nStatusFlags = 0;
            QUESTS_UnitIterate(quest, 1, 0, ACT5Q5_UnitIterate_StatusCyclerEx, true);
            data->bQualKehkActivated = 0;
        }
    }
}
