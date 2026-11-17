struct D2UnitStrc;
void __stdcall STATES_ToggleState(D2UnitStrc* unit, int state, int enabled); // 0x00639DB0

// 0x0054CC30
void __fastcall sub_0054CC30_ClearState(D2UnitStrc* unit, int state, int unused)
{
    STATES_ToggleState(unit, state, 0);
}
