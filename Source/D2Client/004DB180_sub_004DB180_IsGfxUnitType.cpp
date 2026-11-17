struct D2UnitStrc
{
    int dwUnitType;
};

// 0x004DB180
int __fastcall sub_004DB180_IsGfxUnitType(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType >= 0 && pUnit->dwUnitType <= 2)
    {
        return 1;
    }

    return 0;
}
