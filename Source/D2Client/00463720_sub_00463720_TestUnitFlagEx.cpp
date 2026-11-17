struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4];
    unsigned int dwFlagEx;
};

// 0x00463720
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx & dwMask) != 0;
}
