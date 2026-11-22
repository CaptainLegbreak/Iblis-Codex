#include "D2Game.h"

#include "D2UnitData.h"
struct D2Act1Quest4ExStrc { unsigned char padding[0x46]; unsigned char cainActive; };
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc*, D2UnitStrc*, void*);
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* game, D2UnitStrc* unit, void* data); // 0x005928C0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* game, int type, void* argument, QUESTUNITITERATE callback); // 0x005537D0

// 0x00593260
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* unused, D2QuestDataStrc* quest)
{
    SUNIT_IterateUnitsOfType(quest->pGame, 1, 0, ACT1Q4_UnitIterate_RemoveCainFromTristram);
    ((D2Act1Quest4ExStrc*)quest->pQuestDataEx)->cainActive = 0;
    return true;
}
