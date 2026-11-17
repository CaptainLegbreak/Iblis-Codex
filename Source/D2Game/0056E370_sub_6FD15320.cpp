struct D2UnitStrc;
struct D2UnitFindArgStrc;

int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit);                                      // 0x00645680
int __stdcall UNITFINDS_TestUnit(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg);                               // 0x0065AA40

// 0x0056E370
int __fastcall sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg)
{
    if (sub_00645680_CanUnitCorpseBeSelected(pUnit))
    {
        return UNITFINDS_TestUnit(pUnit, pArg);
    }

    return 0;
}
