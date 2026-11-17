struct D2GameStrc;
struct D2UnitStrc;

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60
void __fastcall sub_6FC35570(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);         // 0x00541650

#define EVENTTYPE_MODECHANGE 0

// 0x00553F00
void __fastcall sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    sub_6FC35570(pGame, pUnit, EVENTTYPE_MODECHANGE, 0, 0);
}
