struct D2GameStrc;
struct D2UnitStrc;

int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);                                       // 0x00554CA0
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);                                                       // 0x00623E00
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __fastcall sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A8520

// 0x005A8630
int __fastcall sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_6FCBC930(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        sub_6FC64CD0(pGame, pUnit);
        return 2;
    }

    return 1;
}
