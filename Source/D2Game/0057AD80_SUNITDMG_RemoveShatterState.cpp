struct D2UnitStrc;
struct D2StatListStrc;

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState);                 // 0x0063A4A0
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50

// 0x0057AD80
void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (!SUNIT_IsDead(pUnit))
    {
        STATES_ToggleState(pUnit, 107, 0);
    }

    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\SUnitDmg.cpp", 338);
}
