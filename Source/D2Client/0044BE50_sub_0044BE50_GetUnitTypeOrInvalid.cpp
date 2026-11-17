struct D2UnitStrc
{
    int dwUnitType;
};

// 0x0044BE50
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    return nUnitType;
}
