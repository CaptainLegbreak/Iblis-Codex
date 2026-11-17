struct D2GameStrc;
struct D2UnitStrc;
struct D2EventTimerStrc;

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit);                                    // 0x00553980
void __fastcall SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer);                          // 0x00553970
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

// 0x00540F30
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (SUNIT_GetTimerFromUnit(pUnit))
    {
        sub_6FC349F0(pGame, pUnit);
    }

    SUNIT_SetTimerOnUnit(pUnit, 0);
}
