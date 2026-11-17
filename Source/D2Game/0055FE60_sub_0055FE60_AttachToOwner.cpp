struct D2GameStrc;
struct D2UnitStrc;

#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_STATREGEN 3

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __stdcall sub_0055C2C0(D2UnitStrc* pItem, int nArg);                                    // 0x0055C2C0
void __stdcall sub_0055A2A0(D2UnitStrc* pUnit, int nArg);                                                   // 0x0055A2A0

// 0x0055FE60
void __stdcall sub_0055FE60_AttachToOwner(D2UnitStrc* pItem)
{
    sub_0055C2C0(pItem, 0);
}

// 0x005738D0
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_STATREGEN, 0);
}

// 0x005776E0
void __stdcall sub_005776E0(D2UnitStrc* pUnit)
{
    sub_0055A2A0(pUnit, 1);
}
