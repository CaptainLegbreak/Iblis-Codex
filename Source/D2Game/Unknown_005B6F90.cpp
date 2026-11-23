#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

struct D2Act3Quest0Strc;
struct D2Act3Quest1Strc;
struct D2ObjInitFnStrc;






D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

void __cdecl sub_005BDB10_Return()
{
}

// 0x005B7FE0
void __cdecl sub_005B7FE0_Nop()
{
}
